//=============================================================================
//  readKeypad.c
//
//  Programed by Yuhwan Kim
//=============================================================================


#include "readKeypad.h"


#include "stm32f4xx_hal.h"



//-----------------------------------------------------------------------------
//  Keypad GPIO (5x5)
//-----------------------------------------------------------------------------

//COL (out)
#define COL0_PORT GPIOA
#define COL0_PIN GPIO_PIN_7

#define COL1_PORT GPIOA
#define COL1_PIN GPIO_PIN_6

#define COL2_PORT GPIOA
#define COL2_PIN GPIO_PIN_5

#define COL3_PORT GPIOA
#define COL3_PIN GPIO_PIN_4

#define COL4_PORT GPIOA
#define COL4_PIN GPIO_PIN_3


//ROW(in)
#define ROW0_PORT GPIOB
#define ROW0_PIN GPIO_PIN_14

#define ROW1_PORT GPIOB
#define ROW1_PIN GPIO_PIN_15

#define ROW2_PORT GPIOC
#define ROW2_PIN GPIO_PIN_6

#define ROW3_PORT GPIOC
#define ROW3_PIN GPIO_PIN_7

#define ROW4_PORT GPIOC
#define ROW4_PIN GPIO_PIN_8


//-----------------------------------------------------------------------------
//  Read keypad value
//-----------------------------------------------------------------------------

char readKeypad_run (void)
{
	/* Make COL 0 LOW and all other COL HIGH */
	HAL_GPIO_WritePin (COL0_PORT, COL0_PIN, GPIO_PIN_RESET);  //Pull the COL0 low
	HAL_GPIO_WritePin (COL1_PORT, COL1_PIN, GPIO_PIN_SET);  // Pull the COL1 High
	HAL_GPIO_WritePin (COL2_PORT, COL2_PIN, GPIO_PIN_SET);  // Pull the COL2 High
	HAL_GPIO_WritePin (COL3_PORT, COL3_PIN, GPIO_PIN_SET);  // Pull the COL3 High
	HAL_GPIO_WritePin (COL4_PORT, COL4_PIN, GPIO_PIN_SET);  // Pull the COL4 High

	if (!(HAL_GPIO_ReadPin (ROW0_PORT, ROW0_PIN)))   // if the ROW 0 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW0_PORT, ROW0_PIN)));   // wait till the button is pressed
		return 'E';		//ESC
	}

	if (!(HAL_GPIO_ReadPin (ROW1_PORT, ROW1_PIN)))   // if the ROW 1 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW1_PORT, ROW1_PIN)));   // wait till the button is pressed
		return 'F';		//Fn
	}

	if (!(HAL_GPIO_ReadPin (ROW2_PORT, ROW2_PIN)))   // if the ROW 2 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW2_PORT, ROW2_PIN)));   // wait till the button is pressed
		return 'R';		//Reserved
	}

	if (!(HAL_GPIO_ReadPin (ROW3_PORT, ROW3_PIN)))   // if the ROW 3 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW3_PORT, ROW3_PIN)));   // wait till the button is pressed
		return 'B';		//Backspace
	}
/*
	if (!(HAL_GPIO_ReadPin (ROW4_PORT, ROW4_PIN)))   // if the ROW 4 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW4_PORT, ROW4_PIN)));   // wait till the button is pressed
		return ' ';		//NU
	}
*/

	/* Make COL 1 LOW and all other COL HIGH */
	HAL_GPIO_WritePin (COL0_PORT, COL0_PIN, GPIO_PIN_SET);  //Pull the COL0 High
	HAL_GPIO_WritePin (COL1_PORT, COL1_PIN, GPIO_PIN_RESET);  // Pull the COL1 low
	HAL_GPIO_WritePin (COL2_PORT, COL2_PIN, GPIO_PIN_SET);  // Pull the COL2 High
	HAL_GPIO_WritePin (COL3_PORT, COL3_PIN, GPIO_PIN_SET);  // Pull the COL3 High
	HAL_GPIO_WritePin (COL4_PORT, COL4_PIN, GPIO_PIN_SET);  // Pull the COL4 High

	if (!(HAL_GPIO_ReadPin (ROW0_PORT, ROW0_PIN)))   // if the ROW 0 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW0_PORT, ROW0_PIN)));   // wait till the button is pressed
		return '7';
	}

	if (!(HAL_GPIO_ReadPin (ROW1_PORT, ROW1_PIN)))   // if the ROW 1 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW1_PORT, ROW1_PIN)));   // wait till the button is pressed
		return '8';
	}

	if (!(HAL_GPIO_ReadPin (ROW2_PORT, ROW2_PIN)))   // if the ROW 2 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW2_PORT, ROW2_PIN)));   // wait till the button is pressed
		return '9';
	}

	if (!(HAL_GPIO_ReadPin (ROW3_PORT, ROW3_PIN)))   // if the ROW 3 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW3_PORT, ROW3_PIN)));   // wait till the button is pressed
		return '/';
	}

	if (!(HAL_GPIO_ReadPin (ROW4_PORT, ROW4_PIN)))   // if the ROW 4 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW4_PORT, ROW4_PIN)));   // wait till the button is pressed
		return '(';
	}


	/* Make COL 2 LOW and all other COL HIGH */
	HAL_GPIO_WritePin (COL0_PORT, COL0_PIN, GPIO_PIN_SET);  //Pull the COL0 High
	HAL_GPIO_WritePin (COL1_PORT, COL1_PIN, GPIO_PIN_SET);  // Pull the COL1 High
	HAL_GPIO_WritePin (COL2_PORT, COL2_PIN, GPIO_PIN_RESET);  // Pull the COL2 low
	HAL_GPIO_WritePin (COL3_PORT, COL3_PIN, GPIO_PIN_SET);  // Pull the COL3 High
	HAL_GPIO_WritePin (COL4_PORT, COL4_PIN, GPIO_PIN_SET);  // Pull the COL4 High

	if (!(HAL_GPIO_ReadPin (ROW0_PORT, ROW0_PIN)))   // if the ROW 0 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW0_PORT, ROW0_PIN)));   // wait till the button is pressed
		return '4';
	}

	if (!(HAL_GPIO_ReadPin (ROW1_PORT, ROW1_PIN)))   // if the ROW 1 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW1_PORT, ROW1_PIN)));   // wait till the button is pressed
		return '5';
	}

	if (!(HAL_GPIO_ReadPin (ROW2_PORT, ROW2_PIN)))   // if the ROW 2 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW2_PORT, ROW2_PIN)));   // wait till the button is pressed
		return '6';
	}

	if (!(HAL_GPIO_ReadPin (ROW3_PORT, ROW3_PIN)))   // if the ROW 3 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW3_PORT, ROW3_PIN)));   // wait till the button is pressed
		return '*';
	}

	if (!(HAL_GPIO_ReadPin (ROW4_PORT, ROW4_PIN)))   // if the ROW 4 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW4_PORT, ROW4_PIN)));   // wait till the button is pressed
		return ')';
	}


	/* Make COL 3 LOW and all other COL HIGH */
	HAL_GPIO_WritePin (COL0_PORT, COL0_PIN, GPIO_PIN_SET);  //Pull the COL0 High
	HAL_GPIO_WritePin (COL1_PORT, COL1_PIN, GPIO_PIN_SET);  // Pull the COL1 High
	HAL_GPIO_WritePin (COL2_PORT, COL2_PIN, GPIO_PIN_SET);  // Pull the COL2 High
	HAL_GPIO_WritePin (COL3_PORT, COL3_PIN, GPIO_PIN_RESET);  // Pull the COL3 low
	HAL_GPIO_WritePin (COL4_PORT, COL4_PIN, GPIO_PIN_SET);  // Pull the COL4 High

	if (!(HAL_GPIO_ReadPin (ROW0_PORT, ROW0_PIN)))   // if the ROW 0 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW0_PORT, ROW0_PIN)));   // wait till the button is pressed
		return '1';
	}

	if (!(HAL_GPIO_ReadPin (ROW1_PORT, ROW1_PIN)))   // if the ROW 1 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW1_PORT, ROW1_PIN)));   // wait till the button is pressed
		return '2';
	}

	if (!(HAL_GPIO_ReadPin (ROW2_PORT, ROW2_PIN)))   // if the ROW 2 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW2_PORT, ROW2_PIN)));   // wait till the button is pressed
		return '3';
	}

	if (!(HAL_GPIO_ReadPin (ROW3_PORT, ROW3_PIN)))   // if the ROW 3 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW3_PORT, ROW3_PIN)));   // wait till the button is pressed
		return '-';
	}

	if (!(HAL_GPIO_ReadPin (ROW4_PORT, ROW4_PIN)))   // if the ROW 4 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW4_PORT, ROW4_PIN)));   // wait till the button is pressed
		return '=';
	}


	/* Make COL 4 LOW and all other COL HIGH */
	HAL_GPIO_WritePin (COL0_PORT, COL0_PIN, GPIO_PIN_SET);  //Pull the COL0 High
	HAL_GPIO_WritePin (COL1_PORT, COL1_PIN, GPIO_PIN_SET);  // Pull the COL1 High
	HAL_GPIO_WritePin (COL2_PORT, COL2_PIN, GPIO_PIN_SET);  // Pull the COL2 High
	HAL_GPIO_WritePin (COL3_PORT, COL3_PIN, GPIO_PIN_SET);  // Pull the COL3 High
	HAL_GPIO_WritePin (COL4_PORT, COL4_PIN, GPIO_PIN_RESET);  // Pull the COL4 low
/*
	if (!(HAL_GPIO_ReadPin (ROW0_PORT, ROW0_PIN)))   // if the ROW 0 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW0_PORT, ROW0_PIN)));   // wait till the button is pressed
		return ' ';		//NU
	}
*/
	if (!(HAL_GPIO_ReadPin (ROW1_PORT, ROW1_PIN)))   // if the ROW 1 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW1_PORT, ROW1_PIN)));   // wait till the button is pressed
		return '0';
	}

	if (!(HAL_GPIO_ReadPin (ROW2_PORT, ROW2_PIN)))   // if the ROW 2 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW2_PORT, ROW2_PIN)));   // wait till the button is pressed
		return '.';
	}

	if (!(HAL_GPIO_ReadPin (ROW3_PORT, ROW3_PIN)))   // if the ROW 3 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW3_PORT, ROW3_PIN)));   // wait till the button is pressed
		return '+';
	}
/*
	if (!(HAL_GPIO_ReadPin (ROW4_PORT, ROW4_PIN)))   // if the ROW 4 is low
	{
		while (!(HAL_GPIO_ReadPin (ROW4_PORT, ROW4_PIN)));   // wait till the button is pressed
		return ' ';		//NU
	}
*/

	return 0xFF;
}


