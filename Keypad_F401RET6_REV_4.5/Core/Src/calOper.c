//=============================================================================
//  calOper.c
//
//  Programed by Yuhwan Kim
//=============================================================================

#include "calDef.h"
#include "calStd.h"
#include "calError.h"
#include "calStack.h"
#include "calOper.h"


//-----------------------------------------------------------------------------
//  Return value convert
//-----------------------------------------------------------------------------

static void calOper_convert(double value, char *str, int decimalPlaces)
{

    int intPart = (int)value;


    double fractionalPart = value - intPart;
    for (int i = 0; i < decimalPlaces; i++) {
        fractionalPart *= 10;
    }
    int fracPart = (int)(fractionalPart + 0.5);


    sprintf(str, "%d.%0*d", intPart, decimalPlaces, fracPart);
}


//-----------------------------------------------------------------------------
//  Operator Calculate
//-----------------------------------------------------------------------------

static double calOper_Calculate_Oper(double dNum0, int nMethod, double dNum1)
{
	double dNum2 = 0.0;

	switch (nMethod)
	{
	case 0:  dNum2 = dNum0 + dNum1;  break;
	case 1:  dNum2 = dNum0 - dNum1;  break;
	case 2:  dNum2 = dNum0 * dNum1;  break;
	case 3:  dNum2 = dNum0 / dNum1;  break;
	default: calError_Run(CAL_RV_CAL_OPER_ERR);  break;
	}

	return dNum2;
}


static double calOper_Calculate_Tri(int nMethod, double dNum2)
{
	double dNum3 = 0.0;

	switch (nMethod)
	{
	case 1:  dNum3 = sin(dNum2 * (PI / 180));  break;
	case 2:  dNum3 = cos(dNum2 * (PI / 180));  break;
	case 3:  dNum3 = tan(dNum2 * (PI / 180));  break;
	default: calError_Run(CAL_RV_CAL_TRI_ERR);  break;
	}

	return dNum3;
}


//-----------------------------------------------------------------------------
//  Operation
//-----------------------------------------------------------------------------

int calOper_Run(char caInput[], TCalBuf* tpBuf)
{

	int i;
	int nLen;
	int nType;
	int nCount = 0;
	int nMethod;
	int nOperMode = OPER_MODE_DET;
	int nRV = CAL_RV_OK;
	double dVal;
	double dNum0 = 0.0;
	double dNum1 = 0.0;
	double dNum2 = 0.0;
	double dNum3 = 0.0;
	double dCalVal = 0.0;
	TStack tStack;
	TCalData* tpData;

	//
	tpData = tpBuf->taData;
	nLen = tpBuf->nPtr;

	//
	calStack_Init(&tStack);


	for (i = 0; i < nLen; i++)
	{
		nType = tpData[i].nType;
		nMethod = tpData[i].u.nMethod;
		dVal = tpData[i].u.dVal;

		switch (nType)
		{
		case 1:

			if (nOperMode >= 1)
			{
				nCount--;
			}

			dNum1 = calStack_Pop_D(&tStack);
			dNum0 = calStack_Pop_D(&tStack);
			dNum2 = calOper_Calculate_Oper(dNum0, nMethod, dNum1);
			calStack_Push_D(&tStack, dNum2);

			break;

		case 2:		//Trigonometry

			switch (nMethod)
			{
			case 1:  nOperMode = OPER_MODE_SIN;  break;
			case 2:  nOperMode = OPER_MODE_COS;  break;
			case 3:  nOperMode = OPER_MODE_TAN;  break;
			default: nRV = CAL_RV_TRI_TYPE_ERR;  break;
			}

			break;

		case 3:

			if (nOperMode >= 1)
			{
				nCount++;
				calStack_Push_D(&tStack, dVal);
			}

			else
			{
				nRV = CAL_RV_OPER_MODE_ERR;
				calError_Run(nRV);
			}

			if (nCount == 1 && tpData[i + 1].nType != 3)
			{
				nCount = -1;
			}

			break;

		case 10:

			if (nOperMode == OPER_MODE_DET)
			{
				calStack_Push_D(&tStack, dVal);
			}

			else
			{
				nRV = CAL_RV_OPER_MODE_ERR;
				calError_Run(nRV);
			}

			break;

		default:

			nRV = CAL_RV_OPER_TYPE_ERR;

			break;
		}

		if (nType != 2)
		{
			if (nCount == -1 || (nOperMode >= 1 && nCount < 2 && tpData[i + 1].nType != 3))
			{
				dNum2 = calStack_Pop_D(&tStack);
				dNum3 = calOper_Calculate_Tri(nOperMode, dNum2);
				calStack_Push_D(&tStack, dNum3);

				nOperMode = OPER_MODE_DET;
				nCount = 0;
			}
		}
	}

	dCalVal = calStack_Pop_D(&tStack);


	calOper_convert(dCalVal, caInput, 4);

//	printf("Result : %f\n", dCalVal);

	return nRV;
}
