//=============================================================================
//  readBattery.c
//
//  Programed by Yuhwan Kim
//=============================================================================


#include "readBattery.h"
#include "stm32f4xx_hal.h"
#include "st7789.h"

extern ADC_HandleTypeDef hadc1;




int readBatteryPercentage(void)
{
    uint16_t readValue;
    float voltage;
    int battery_percentage;

    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 1000);
    readValue = HAL_ADC_GetValue(&hadc1);

    voltage = ((float)readValue / 4095) * 3.3 * 5;

    if (voltage >= 4.2) {
        battery_percentage = 100;
    } else if (voltage <= 3.0) {
        battery_percentage = 0;
    } else {
        battery_percentage = (int)(((voltage - 3.0) / (4.2 - 3.0)) * 100);
    }

    return battery_percentage;
}



void printBattery(void)
{
    int batteryPercentage = readBatteryPercentage();
    char percentage_str[6];

    uint16_t color;
    if (batteryPercentage >= 80) {
        color = GREEN;
    } else if (batteryPercentage >= 20) {
        color = WHITE;
    } else {
        color = RED;
    }


    if (batteryPercentage == 100) {
        percentage_str[0] = '1';
        percentage_str[1] = '0';
        percentage_str[2] = '0';
        percentage_str[3] = '%';
        percentage_str[4] = ' ';
        percentage_str[5] = '\0';
    } else {
        percentage_str[0] = ' ';
        percentage_str[1] = (batteryPercentage / 10) + '0';
        percentage_str[2] = (batteryPercentage % 10) + '0';
        percentage_str[3] = '%';
        percentage_str[4] = ' ';
        percentage_str[5] = '\0';
    }

    ST7789_WriteString(278, 5, percentage_str, Font_7x10, color, BLACK);
}
