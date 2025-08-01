//=============================================================================
//  calDef.h
//
//  Programed by Yuhwan Kim
//=============================================================================

#ifndef CAL_DEF_H
#define CAL_DEF_H



//String Size
#define MAX_CAL_DATA 100
#define MAX_STACK_SIZE 100


//Trigonometry
#define PI  3.14159265358979323846264338327950


//-----------------------------------------------------------------------------

//calPostfix_OPER_MODE define
#define POST_MODE_DET					0
#define POST_MODE_TRI_SHORT				1	//Trigonometry
#define POST_MODE_TRI_LONG				2	//Trigonometry()

//calOper_OPER_MODE define
#define OPER_MODE_DET					0
#define OPER_MODE_SIN					1
#define OPER_MODE_COS					2
#define OPER_MODE_TAN					3

//Operator Priority
#define CAL_PRI_0                       0
#define CAL_PRI_1                       1
#define CAL_PRI_2                       2
#define CAL_PRI_ERR					   -1


//Return Value
#define CAL_RV_OK                       1
#define CAL_RV_BUSY                     0
#define CAL_RV_ERR                     -1

#define CAL_RV_BLANK_ERR               -10
#define CAL_RV_POST_OPER_ERR           -20
#define CAL_RV_POST_TRI_ERR            -21
#define CAL_RV_BUF_OPER_ERR            -30
#define CAL_RV_BUF_VAL_ERR             -31
#define CAL_RV_OPER_TYPE_ERR           -40
#define CAL_RV_TRI_TYPE_ERR            -41
#define CAL_RV_OPER_MODE_ERR           -50
#define CAL_RV_CAL_OPER_ERR            -60
#define CAL_RV_CAL_TRI_ERR             -61

//Stack
#define CAL_ST_OK                       1
#define CAL_ST_BUSY                     0
#define CAL_ST_FULL_ERR                -100
#define CAL_ST_EMPTY_ERR               -101

//calError_Run()
#define CAL_ERR_RUN_OK                  1
#define CAL_ERR_RUN_BUSY                0
#define CAL_ERR_RUN_ERR                -1

#endif
