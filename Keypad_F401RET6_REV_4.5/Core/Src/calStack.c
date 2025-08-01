//=============================================================================
//  calStack.c
//
//  Programed by Yuhwan Kim
//=============================================================================

#include "calDef.h"
#include "calStd.h"
#include "calError.h"
#include "calStack.h"


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

int calStack_Create()
{

	return 0;
}


int calStack_Close()
{

	return 0;
}


//-----------------------------------------------------------------------------
//  Init stack
//-----------------------------------------------------------------------------

void calStack_Init(TStack* tStack)
{
	tStack->nPtr = -1;
}


//-----------------------------------------------------------------------------
//  Empty stack
//-----------------------------------------------------------------------------

int calStack_Empty(TStack* tStack)
{
	return((tStack->nPtr) == -1);
}


//-----------------------------------------------------------------------------
//  Full stack
//-----------------------------------------------------------------------------

int calStack_Full(TStack* tStack)
{
	return((tStack->nPtr) == (MAX_STACK_SIZE - 1));
}


//-----------------------------------------------------------------------------
//  Push stack
//-----------------------------------------------------------------------------

void calStack_Push_D(TStack* tStack, double pushVal)
{

	if (calStack_Full(tStack))
	{
		calError_Run(CAL_ST_FULL_ERR);
	}

	else
	{
		tStack->nPtr++;
		tStack->u.dData[tStack->nPtr] = pushVal;
	}
}


void calStack_Push_Ch(TStack* tStack, char pushVal)
{

	if (calStack_Full(tStack))
	{
		calError_Run(CAL_ST_FULL_ERR);
	}

	else
	{
		tStack->nPtr++;
		tStack->u.cData[tStack->nPtr] = pushVal;
	}
}


//-----------------------------------------------------------------------------
//  Pop stack
//-----------------------------------------------------------------------------

double calStack_Pop_D(TStack* tStack)
{

	int nRV = CAL_ST_OK;
	double popVal;

	if (calStack_Empty(tStack))
	{
		nRV = CAL_ST_EMPTY_ERR;
		calError_Run(nRV);

		return nRV;
	}

	else
	{
		popVal = tStack->u.dData[tStack->nPtr];

		tStack->nPtr--;

		return popVal;
	}
}


char calStack_Pop_Ch(TStack* tStack)
{

	int nRV = CAL_ST_OK;
	char popVal;

	if (calStack_Empty(tStack))
	{
		nRV = CAL_ST_EMPTY_ERR;
		calError_Run(nRV);

		return nRV;
	}

	else
	{
		popVal = tStack->u.cData[tStack->nPtr];

		tStack->nPtr--;

		return popVal;
	}
}


//-----------------------------------------------------------------------------
//  Peek stack
//-----------------------------------------------------------------------------

double calStack_Peek_D(TStack* tStack)
{

	int nRV = CAL_ST_OK;

	if (calStack_Empty(tStack))
	{
		nRV = CAL_ST_EMPTY_ERR;
		calError_Run(nRV);

		return nRV;
	}

	else
	{
		return tStack->u.dData[tStack->nPtr];
	}
}


char calStack_Peek_Ch(TStack* tStack)
{

	int nRV = CAL_ST_OK;

	if (calStack_Empty(tStack))
	{
		nRV = CAL_ST_EMPTY_ERR;
		calError_Run(nRV);

		return nRV;
	}
	else
	{
		return tStack->u.cData[tStack->nPtr];
	}
}


