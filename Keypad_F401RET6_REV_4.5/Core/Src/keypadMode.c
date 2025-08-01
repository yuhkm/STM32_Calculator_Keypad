//=============================================================================
//  keypadMode.c
//
//  Programed by Yuhwan Kim
//=============================================================================


#include "keypadMode.h"


//-----------------------------------------------------------------------------
//  Mode GPIO
//-----------------------------------------------------------------------------


// Mode_1 (Keypad)
#define mode1_PORT GPIOA
#define mode1_PIN GPIO_PIN_9

// Mode_2 (Calculator)
#define mode2_PORT GPIOA
#define mode2_PIN GPIO_PIN_8

//-----------------------------------------------------------------------------
//  Keypad Mode Read
//-----------------------------------------------------------------------------

int keypadMode_read(void)
{
    int nMode = 0;

    GPIO_PinState mode1_state = HAL_GPIO_ReadPin(mode1_PORT, mode1_PIN);
    GPIO_PinState mode2_state = HAL_GPIO_ReadPin(mode2_PORT, mode2_PIN);


    if (mode1_state == GPIO_PIN_SET && mode2_state == GPIO_PIN_RESET)
    {
        nMode = 1;  // Mode 1: Keypad
    }
    else if (mode1_state == GPIO_PIN_RESET && mode2_state == GPIO_PIN_SET)
    {
        nMode = 2;  // Mode 2: Calculator
    }
    else
    {
        nMode = -1;  // Mode error
    }

    return nMode;
}
