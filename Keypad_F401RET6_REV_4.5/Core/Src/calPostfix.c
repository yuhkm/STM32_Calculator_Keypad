//=============================================================================
//  calPostfix.c
//
//  Programed by Yuhwan Kim
//=============================================================================

#include "calDef.h"
#include "calStd.h"
#include "calError.h"
#include "calStack.h"
#include "calPostfix.h"


//-----------------------------------------------------------------------------
//  Calculate sequence
//-----------------------------------------------------------------------------

static int calPostfix_GetOperPri(char cVal)
{

	int nRV;

	switch (cVal)
	{
	case '(':  case ')':  nRV = CAL_PRI_0;  break;
	case '+':  case '-':  nRV = CAL_PRI_1;  break;
	case '*': case '/':   nRV = CAL_PRI_2;  break;
	default:              nRV = CAL_PRI_ERR;  break;
	}

	calError_Run(nRV);
	return nRV;
}


//-----------------------------------------------------------------------------
//  Put Calculate Buf
//-----------------------------------------------------------------------------

static int calPostfix_PutBuf_Oper(TCalBuf* tpBuf, char cVal, int nPtr)
{

	int nRV = CAL_RV_OK;
	TCalData* tpData;

	tpData = tpBuf->taData;


	switch (cVal)
	{
	case '+':

		tpData[nPtr].nType = 1;
		tpData[nPtr].u.nMethod = 0;

		break;

	case '-':

		tpData[nPtr].nType = 1;
		tpData[nPtr].u.nMethod = 1;

		break;

	case '*':

		tpData[nPtr].nType = 1;
		tpData[nPtr].u.nMethod = 2;

		break;

	case '/':

		tpData[nPtr].nType = 1;
		tpData[nPtr].u.nMethod = 3;

		break;

	case 's':

		tpData[nPtr].nType = 2;
		tpData[nPtr].u.nMethod = 1;

		break;

	case 'c':

		tpData[nPtr].nType = 2;
		tpData[nPtr].u.nMethod = 2;

		break;

	case 't':

		tpData[nPtr].nType = 2;
		tpData[nPtr].u.nMethod = 3;

		break;

	default:

		nRV = CAL_RV_BUF_OPER_ERR;

		break;
	}

	return nRV;
}


static int calPostfix_PutBuf_Val(TCalBuf* tpBuf, int nOperMode, double dVal, int nPtr)
{

	int nType;
	int nRV = CAL_RV_OK;
	TCalData* tpData;

	tpData = tpBuf->taData;


	switch (nOperMode)
	{
	case 0:  nType = 10;  break;
	case 1:  case 2:  nType = 3;  break;
	default:  nRV = CAL_RV_BUF_VAL_ERR;  break;
	}

	tpBuf->taData[nPtr].nType = nType;
	tpData[nPtr].u.dVal = dVal;

	return nRV;
}


//-----------------------------------------------------------------------------
//  Postfix
//-----------------------------------------------------------------------------

int calPostfix_Run(char* cpInput, TCalBuf* tpBuf)
{

	int i;
	int j = 0;
	int k;
	int nLen = strlen(cpInput);
	int nVal = 0;
	int nCount = 0;
	int nDist = 0;
	int nPtr;
	int nStk;
	int nOperMode = POST_MODE_DET;
	int nRV = CAL_RV_OK;
	double dVal = 0.0;
	char cVal;
	char cVal_Pop;
	//	char *vPtr;
	char csVal[100] = { '\0' };
	TStack tStack;
	TCalData* tpData;

	//
	tpData = tpBuf->taData;
	nPtr = tpBuf->nPtr;

	//
	calStack_Init(&tStack);


	for (i = 0; i < nLen; i++)
	{
		cVal = cpInput[i];
		nDist = isdigit(cVal);

		if (nDist != 0 || cVal == '.')
		{
			nCount = i;

			for (k = i; k < nLen; k++)
			{
				if ((cVal == '(') || (cVal == ')') || (cVal == '+') || (cVal == '-')
					|| (cVal == '*') || (cVal == '/') || (cVal == '\0'))
				{
					break;
				}

				else if (cVal == ' ')
				{
					if (isdigit(cpInput[nCount + 1]) != 0 || cpInput[nCount + 1] == '.')
					{
						nRV = CAL_RV_BLANK_ERR;
						calError_Run(nRV);
					}

					break;
				}

				csVal[j] = cVal;

				j++;
				nCount++;

				cVal = cpInput[nCount];
			}

			j--;
			i = i + j;

			for (k = j; k > -1; k--)
			{
				dVal = atof(&csVal[k]);
			}

			if ((nRV = calPostfix_PutBuf_Val(tpBuf, nOperMode, dVal, nPtr)) < 0)
			{
				calError_Run(nRV);
			}

			nPtr++;
			dVal = 0.0;

			/*			vPtr = strchr( csVal, '.' );

						if( vPtr == NULL )
						{

						}

						else
						{

						}
			*/
			for (k = nCount; k > -1; k--)
			{
				csVal[k] = '\0';
			}

			j = 0;

			if (nOperMode == POST_MODE_TRI_SHORT)
			{
				nOperMode = POST_MODE_DET;
			}
		}

		else
		{
			switch (cVal)
			{
			case '+':   case '-':   case '*':   case '/':

				for (k = i; k < nLen; k++)
				{
					if (!(!calStack_Empty(&tStack) && (calPostfix_GetOperPri(cVal) <= calPostfix_GetOperPri(calStack_Peek_Ch(&tStack)))))
					{
						break;
					}

					cVal_Pop = calStack_Pop_Ch(&tStack);


					if ((nRV = calPostfix_PutBuf_Oper(tpBuf, cVal_Pop, nPtr)) < 0)
					{
						calError_Run(nRV);
					}

					nPtr++;
				}

				calStack_Push_Ch(&tStack, cVal);

				break;

			case '(':

				calStack_Push_Ch(&tStack, cVal);

				break;

			case ')':

				cVal_Pop = calStack_Pop_Ch(&tStack);

				for (k = i; k < nLen; k++)
				{
					if (cVal_Pop == '(')
					{
						break;
					}

					if ((nRV = calPostfix_PutBuf_Oper(tpBuf, cVal_Pop, nPtr)) < 0)
					{
						calError_Run(nRV);
					}

					nPtr++;

					cVal_Pop = calStack_Pop_Ch(&tStack);
				}

				if (nOperMode == POST_MODE_TRI_LONG)
				{
					nOperMode = POST_MODE_DET;
				}

				break;

			case 's':   case 'c':   case 't':

				if ((cpInput[i + 1] == 'i') && (cpInput[i + 2] == 'n'))  nRV = CAL_RV_OK;
				else if ((cpInput[i + 1] == 'o') && (cpInput[i + 2] == 's'))  nRV = CAL_RV_OK;
				else if ((cpInput[i + 1] == 'a') && (cpInput[i + 2] == 'n'))  nRV = CAL_RV_OK;
				else  calError_Run(CAL_RV_POST_TRI_ERR);

				if (cpInput[i + 3] != '(')
				{
					if (cpInput[i + 4] != '(')
					{
						nOperMode = POST_MODE_TRI_SHORT;
					}
				}

				else
				{
					nOperMode = POST_MODE_TRI_LONG;
				}


				if ((nRV = calPostfix_PutBuf_Oper(tpBuf, cVal, nPtr)) < 0)
				{
					calError_Run(nRV);
				}

				nPtr++;
				i = i + 2;

				break;

			case ' ':

				break;

			default:

				nRV = CAL_RV_POST_OPER_ERR;

				break;
			}
		}

		cVal = cpInput[i];
	}

	nStk = tStack.nPtr;

	for (k = nStk; k >= -1; k--)
	{
		if (calStack_Empty(&tStack))
		{
			break;
		}

		cVal_Pop = calStack_Pop_Ch(&tStack);

		if ((nRV = calPostfix_PutBuf_Oper(tpBuf, cVal_Pop, nPtr)) < 0)
		{
			calError_Run(nRV);
		}

		nPtr++;
	}

	tpBuf->nPtr = nPtr;

	return nRV;
}
