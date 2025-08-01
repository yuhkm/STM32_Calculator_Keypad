//=============================================================================
//  hidKeypad.c
//
//  Programed by Yuhwan Kim
//=============================================================================

//[Keyboard Hex code]
//https://www.youtube.com/watch?v=tj1_hsQ5PR0
//https://controllerstech.com/wp-content/uploads/2020/09/KEYBOARD_HELPER.pdf


#include "hidKeypad.h"


//-----------------------------------------------------------------------------

extern USBD_HandleTypeDef hUsbDeviceFS;


//-----------------------------------------------------------------------------
//  HID struct
//-----------------------------------------------------------------------------

typedef struct
{
	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYCODE1;
	uint8_t KEYCODE2;
	uint8_t KEYCODE3;
	uint8_t KEYCODE4;
	uint8_t KEYCODE5;
	uint8_t KEYCODE6;
} keyboardHID;


keyboardHID keyboardhid = {0, 0, 0, 0, 0, 0, 0, 0};


//-----------------------------------------------------------------------------
// Send HID keypad value
//-----------------------------------------------------------------------------

void hidKeypad_sandKey(uint8_t key)
{
	if (key == '1')  keyboardhid.KEYCODE1 = 0x1E;
	if (key == '2')  keyboardhid.KEYCODE1 = 0x1F;
	if (key == '3')  keyboardhid.KEYCODE1 = 0x20;
	if (key == '4')  keyboardhid.KEYCODE1 = 0x21;
	if (key == '5')  keyboardhid.KEYCODE1 = 0x22;
	if (key == '6')  keyboardhid.KEYCODE1 = 0x23;
	if (key == '7')  keyboardhid.KEYCODE1 = 0x24;
	if (key == '8')  keyboardhid.KEYCODE1 = 0x25;
	if (key == '9')  keyboardhid.KEYCODE1 = 0x26;
	if (key == '0')  keyboardhid.KEYCODE1 = 0x27;

	if (key == 'E')
	{
		keyboardhid.KEYCODE1 = 0x29;  // press 'ESC'
	}

	//Fn
	//Reserved


	if (key == 'B')
	{
		keyboardhid.KEYCODE1 = 0x2A;  // press 'Backspace'
	}

	if (key == '+')
	{
		keyboardhid.MODIFIER = 0x02;  // left shift pressed
		keyboardhid.KEYCODE1 = 0x2E;  // press '+'
	}
	if (key == '-')
	{
		keyboardhid.KEYCODE1 = 0x2D;  // press '-'
	}
	if (key == '*')
	{
		keyboardhid.MODIFIER = 0x02;  // left shift pressed
		keyboardhid.KEYCODE1 = 0x25;  // press '*'
	}
	if (key == '/')
	{
		keyboardhid.KEYCODE1 = 0x38;  // press '/'
	}

	if (key == '(')
	{
		keyboardhid.MODIFIER = 0x02;  // left shift pressed
		keyboardhid.KEYCODE1 = 0x26;  // press '('
	}
	if (key == ')')
	{
		keyboardhid.MODIFIER = 0x02;  // left shift pressed
		keyboardhid.KEYCODE1 = 0x27;  // press ')'
	}
	if (key == '.')
	{
		keyboardhid.KEYCODE1 = 0x63;  // press '.'
	}
	if (key == '=')
	{
		keyboardhid.KEYCODE1 = 0x2E;  // press '='
	}

	USBD_HID_SendReport(&hUsbDeviceFS, &keyboardhid, sizeof (keyboardhid));
	HAL_Delay (50);
	keyboardhid.MODIFIER = 0x00;  // shift release
	keyboardhid.KEYCODE1 = 0x00;  // release key
	USBD_HID_SendReport(&hUsbDeviceFS, &keyboardhid, sizeof (keyboardhid));
}


//-----------------------------------------------------------------------------
// Key mecro test
//-----------------------------------------------------------------------------
/*
void hidKeypad_mecroTest ()
{
	keyboardhid.MODIFIER = 0x02;	//left shift
	keyboardhid.KEYCODE1 = 0x04;	//press 'a'
	USBD_HID_SendReport(&hUsbDeviceFS, &keyboardhid, sizeof(keyboardhid));
	HAL_Delay(50);
	keyboardhid.MODIFIER = 0x00;	//release shift
	keyboardhid.KEYCODE1 = 0x00;	//release key
	USBD_HID_SendReport(&hUsbDeviceFS, &keyboardhid, sizeof(keyboardhid));
	HAL_Delay(1000);
}
*/

