# STM32_Calculator_Keypad
STM32 Based USB Keypad and Calculator Project  
<br>
<img src="https://github.com/user-attachments/assets/596d8d49-576b-4b3f-bf7d-17416ccdfcdd" width="400"/>

## Overview
Development Period : 2024.08 ~ 2024.11
<br>
### HW
- MCU : STM32F401RET6  
- Displsy : ST7789 1.9" TFT LCD  
- Battery : Li-Po 500mAh 3.7V  
- Interface: USB (for keypad mode and charging)
- Switches: Cherry MX compatible mechanical switches  
  ( Kailh hot-swap sockets )
-  
-  
 
### SW
- Maximum expression length: 70 characters
- Calculator supported Operations  
  Basic arithmetic : +, -, ×, ÷  
  Parentheses : (), {}, []  
  Trigonometric functions : sin, cos, tan  
  Planned support for : asin, acos, atan, log, ln   
-  
-  


## Key Features
- Mode 0 : Calculator
- Mode 1 : USB Keypad  
<br>

| USB C | Power S/W | Mode S/W | Function            | Power source             |
|:-----:|:----------:|:--------:|--------------------|--------------------------|
|   0   |     0      |    X     | Power off          | -                        |
|   0   |     1      |    0     | Calculator mode    | Battery                  |
|   0   |     1      |    1     | -                  | -                        |
|   1   |     0      |    X     | Power off          | Battery charge           |
|   1   |     1      |    0     | Calculator mode    | USB + Battery charge     |
|   1   |     1      |    1     | USB Keypad mode    | USB + Battery charge     |








<img src="https://github.com/user-attachments/assets/025b817e-7f0f-425e-8290-4d6647f31785" width="400"/>
<img src="https://github.com/user-attachments/assets/760db888-4328-4ba1-9905-d4fd6b443620" width="450"/>

