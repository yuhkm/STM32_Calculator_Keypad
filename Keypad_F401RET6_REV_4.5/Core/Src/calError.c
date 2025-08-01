//=============================================================================
//  calError.c
//
//  Programed by Yuhwan Kim
//=============================================================================

#include "calDef.h"
#include "calStd.h"
#include "calError.h"



//-----------------------------------------------------------------------------
//  Print Error Code
//-----------------------------------------------------------------------------

int calError_Run(int errCode)
{

	if (errCode >= 0)  return CAL_ERR_RUN_OK;

	else
	{
		switch (errCode)
		{
			//Operator Priority
		case CAL_PRI_ERR:  printf("Operation priority set error.\n");  break;

			//Return Value
		case CAL_RV_BLANK_ERR:  printf("Syntax blank error.\n");  break;
		case CAL_RV_POST_OPER_ERR:  printf("Operator postfix error.\n");  break;
		case CAL_RV_POST_TRI_ERR:  printf("Trigonometry postfix error.\n");  break;
		case CAL_RV_BUF_OPER_ERR:  printf("Put buffer operator error.\n");  break;
		case CAL_RV_BUF_VAL_ERR:  printf("Put buffer value error.\n");  break;
		case CAL_RV_OPER_TYPE_ERR:  printf("Operation type error.\n");  break;
		case CAL_RV_TRI_TYPE_ERR:  printf("Trigonometry type error.\n");  break;
		case CAL_RV_OPER_MODE_ERR:  printf("Operation mode error.\n");  break;
		case CAL_RV_CAL_OPER_ERR:  printf("Calculate operator error.\n");  break;
		case CAL_RV_CAL_TRI_ERR:  printf("Trigonometry operator error.\n");  break;

			//Stack
		case CAL_ST_FULL_ERR:  printf("Stack full error.\n");  break;
		case CAL_ST_EMPTY_ERR:  printf("Stack empty error.\n");  break;

		default:  return CAL_ERR_RUN_ERR;
		}

		printf("[Break the calculator]\n");
		system("PAUSE");
		exit(1);
	}

	return CAL_ERR_RUN_OK;
}
