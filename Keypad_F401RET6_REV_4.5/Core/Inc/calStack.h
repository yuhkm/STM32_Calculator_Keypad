//=============================================================================
//  calStack.h
//
//  Programed by Yuhwan Kim
//=============================================================================

#ifndef CAL_STACK_H
#define CAL_STACK_H


//-----------------------------------------------------------------------------

typedef struct
{

	int nType; //0:, 1:Operator,   2:Trigonometry,   3:Trigonometry value,   10:Value

	union
	{
		int nMethod; //Bracket = 0:(,   1:)
		//Operator = 0:+,   1:-,   2:*,   3:/
		//Trigonometry =0:,   1:Sin,   2:Cos,   3:Tan

		double dVal; //Double Value

	} u;

} TCalData;

typedef struct
{

	int nPtr;

	TCalData taData[MAX_CAL_DATA];

} TCalBuf;



typedef struct
{

	int nPtr;

	union
	{
		double dData[MAX_STACK_SIZE];

		char cData[MAX_STACK_SIZE];

	} u;

} TStack;


//-----------------------------------------------------------------------------

//
extern int calStack_Create();

extern int calStack_Close();


//Init stack
extern void calStack_Init(TStack* tStack);

//Empty stack
extern int calStack_Empty(TStack* tStack);

//Full stack
extern int calStack_Full(TStack* tStack);


//Push stack
extern void calStack_Push_D(TStack* tStack, double pushVal);
extern void calStack_Push_Ch(TStack* tStack, char pushVal);

//Pop stack
extern double calStack_Pop_D(TStack* tStack);
extern char calStack_Pop_Ch(TStack* tStack);

//Peek stack
extern double calStack_Peek_D(TStack* tStack);
extern char calStack_Peek_Ch(TStack* tStack);




#endif
