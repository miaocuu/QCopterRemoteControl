/**
  *      __            ____
  *     / /__ _  __   / __/                      __  
  *    / //_/(_)/ /_ / /  ___   ____ ___  __ __ / /_ 
  *   / ,<  / // __/_\ \ / _ \ / __// _ \/ // // __/ 
  *  /_/|_|/_/ \__//___// .__//_/   \___/\_,_/ \__/  
  *                    /_/   github.com/KitSprout    
  * 
  * @file    stm32f4xx_bsp.c
  * @author  KitSprout
  * @date    16-Mar-2017
  * @brief   
  * 
  */

/* Includes --------------------------------------------------------------------------------*/
#include "drivers\stm32f4_system.h"
#include "drivers\stm32f4_exti.h"
#include "stm32f4xx_bsp.h"

/** @addtogroup STM32_Program
  * @{
  */

/* Private typedef -------------------------------------------------------------------------*/
/* Private define --------------------------------------------------------------------------*/
/* Private macro ---------------------------------------------------------------------------*/
/* Private variables -----------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------*/
/* Private functions -----------------------------------------------------------------------*/

void BSP_GPIO_Config( void )
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* Enable all GPIO Clk *******************************************************/
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /* GPIO all analog input *****************************************************/
  GPIO_InitStruct.Mode  = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
  GPIO_InitStruct.Pin   = GPIO_PIN_All & (~(GPIO_PIN_13 | GPIO_PIN_14));
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* GPIO Pin ******************************************************************/
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

  GPIO_InitStruct.Pin   = LED_R_PIN;
  HAL_GPIO_Init(LED_R_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin   = LED_G_PIN;
  HAL_GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin   = LED_B_PIN;
  HAL_GPIO_Init(LED_B_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

  GPIO_InitStruct.Pin   = KEY_S1_PIN;
  HAL_GPIO_Init(KEY_S1_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin   = KEY_S2_PIN;
  HAL_GPIO_Init(KEY_S2_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin   = KEY_PL_PIN;
  HAL_GPIO_Init(KEY_PL_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin   = KEY_PP_PIN;
  HAL_GPIO_Init(KEY_PP_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin   = KEY_PR_PIN;
  HAL_GPIO_Init(KEY_PR_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin   = KEY_JR_PIN;
  HAL_GPIO_Init(KEY_JR_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin   = KEY_JL_PIN;
  HAL_GPIO_Init(KEY_JL_GPIO_PORT, &GPIO_InitStruct);

  LED_R_Set();
  LED_G_Set();
  LED_B_Set();
}

void BSP_EXTI_KEY_Config( pFunc event )
{
  EXTIx_KEY_JR_Config(event);
}

/*************************************** END OF FILE ****************************************/
