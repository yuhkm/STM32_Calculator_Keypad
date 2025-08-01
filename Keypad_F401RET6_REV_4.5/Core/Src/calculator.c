//=============================================================================
//  calculator.c
//
//  Programed by Yuhwan Kim
//=============================================================================

#include "calDef.h"
#include "calStd.h"
#include "calError.h"
#include "calStack.h"
#include "calPostfix.h"
#include "calOper.h"


void calculator_run(char caInput[])
{

	int nSt;

	TCalBuf tCalBuf;
	memset(&tCalBuf, 0, sizeof(tCalBuf));


	nSt = calPostfix_Run(caInput, &tCalBuf);
	nSt = calOper_Run(caInput, &tCalBuf);
}
