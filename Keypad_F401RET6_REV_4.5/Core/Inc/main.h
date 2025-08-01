/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Fn_LED_Pin GPIO_PIN_0
#define Fn_LED_GPIO_Port GPIOC
#define BAT_ADC_Pin GPIO_PIN_2
#define BAT_ADC_GPIO_Port GPIOA
#define COL4_Pin GPIO_PIN_3
#define COL4_GPIO_Port GPIOA
#define COL3_Pin GPIO_PIN_4
#define COL3_GPIO_Port GPIOA
#define COL2_Pin GPIO_PIN_5
#define COL2_GPIO_Port GPIOA
#define COL1_Pin GPIO_PIN_6
#define COL1_GPIO_Port GPIOA
#define COL0_Pin GPIO_PIN_7
#define COL0_GPIO_Port GPIOA
#define ROW0_Pin GPIO_PIN_14
#define ROW0_GPIO_Port GPIOB
#define ROW1_Pin GPIO_PIN_15
#define ROW1_GPIO_Port GPIOB
#define ROW2_Pin GPIO_PIN_6
#define ROW2_GPIO_Port GPIOC
#define ROW3_Pin GPIO_PIN_7
#define ROW3_GPIO_Port GPIOC
#define ROW4_Pin GPIO_PIN_8
#define ROW4_GPIO_Port GPIOC
#define NMODE_2_Pin GPIO_PIN_8
#define NMODE_2_GPIO_Port GPIOA
#define NMODE_1_Pin GPIO_PIN_9
#define NMODE_1_GPIO_Port GPIOA
#define RES_Pin GPIO_PIN_6
#define RES_GPIO_Port GPIOB
#define DC_Pin GPIO_PIN_7
#define DC_GPIO_Port GPIOB
#define CS_Pin GPIO_PIN_8
#define CS_GPIO_Port GPIOB
#define BLK_Pin GPIO_PIN_9
#define BLK_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define ST7789_RST_GPIO_Port 	GPIOB
#define ST7789_RST_Pin       	GPIO_PIN_6
#define ST7789_DC_GPIO_Port  	GPIOB
#define ST7789_DC_Pin        	GPIO_PIN_7
#define ST7789_CS_GPIO_Port  	GPIOB
#define ST7789_CS_Pin        	GPIO_PIN_8
#define ST7789_BLK_GPIO_Port	GPIOB
#define ST7789_BLK_Pin        	GPIO_PIN_9

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
