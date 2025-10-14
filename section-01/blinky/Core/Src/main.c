/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
void HAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init); // <----------------------------- Section 2, exercise 1
void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState); // <----------- Section 2, exercise 1
void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin); // <---------------------------------- Section 2, exercise 1
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick.
   */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1) {
    /* USER CODE END WHILE */
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
    HAL_Delay(500);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
    HAL_Delay(500);

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**s
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType =
      RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK) {
    Error_Handler();
  }
}

/**
 * @brief USART2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART2_UART_Init(void) {

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 38400;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK) {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */
}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */
  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING; // binary number with different slices representing different things
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /* unused */
  /*Configure GPIO pin : LD2_Pin 
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);
 */

  /* USER CODE BEGIN MX_GPIO_Init_2 */
  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

// rewritten GPIO functions for exercise 1, a mix of generality and specificity
void HAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init){
  // The GPIO_InitTypeDef fed in the mx_GPIO_Init function only contains Pin, Mode, Pull, Speed parameters
  // one pin at a time as well so while loop is not necessary here
  uint32_t temp;
  uint32_t pin = GPIO_Init->Pin;
  uint32_t pin_index = ctz(pin); // count trailing zeros to get the index of the pin

  //general variables from GPIO_InitTypeDef
  uint32_t mode = GPIO_Init->Mode;
  uint32_t pull = GPIO_Init->Pull;
  uint32_t speed = GPIO_Init->Speed;

  //decoding mode
  pin_mode = (mode & GPIO_MODE) >> GPIO_MODE_Pos; // only keep gpio mode bits and shift to lsb
  exti_mode = (mode & EXTI_MODE) >> EXTI_MODE_Pos; // only keep exti mode bits and shift to lsb
  trigger_mode = (mode & TRIGGER_MODE) >> TRIGGER_MODE_Pos; // only keep trigger mode bits and shift to lsb
  output_type = (mode & OUTPUT_TYPE) >> OUTPUT_TYPE_Pos; // only keep output type bits and shift to lsb

  // configuring general registers
  // MODER register
  temp = GPIOx ->MODER;
  temp &= ~(0x3u << (2 * pin_index)); // clear the 2 bits corresponding to the pin
  temp |= (pin_mode << (2 * pin_index)); // set the 2 bits corresponding to the pin
  GPIOx ->MODER = temp;

  //PUPDR register
  temp = GPIOx ->PUPDR;
  temp &= ~(0x3u << (2 * pin_index));
  temp |= (pull << (2 * pin_index));
  GPIOx ->PUPDR = temp;

  //mode specific configurations
  if(pin_mode == MODE_OUTPUT){
    //configure Output Type
    temp = GPIOx ->OTYPER;
    temp &= ~(0x1u << pin_index); // clear the bit corresponding to the pin
    temp |= (output_type << pin_index); // set the bit corresponding to the pin
    GPIOx ->OTYPER = temp;

    //and configure Output Speed
    temp = GPIOx ->OSPEEDR;
    temp &= ~(0x3u << (2 * pin_index));
    temp |= (speed << (2 * pin_index));
    GPIOx ->OSPEEDR = temp;
  }

  if(pin_mode == MODE_INPUT){
    //configure EXTI and trigger mode
    if(exti_mode != 0){ // if exti mode is selected
      //enable syscfg clock
      __HAL_RCC_SYSCFG_CLK_ENABLE();

      //find the correct EXTICR register and configure it to the right port
      uint32_t position = pin_index / 4; // choosing the correct EXTICR register, since there are 4 registers for 16 pins
      uint32_t shift = (pin_index % 4) * 4; // each exti register has 4 fields/slices of 4 bits each, choosing the correct slice
      uint32_t port = GPIO_GET_INDEX(GPIOx); // getting the port index for the pin

      //writing the port index to the correct slice after clearing it
      SYSCFG->EXTICR[position] = (SYSCFG->EXTICR[position] & ~(0xFu << shift)) | (port << shift);

      //configure EXTI IMR register and edge trigger registers
      uint32_t bit = 1u << pin_index; // bit corresponding to the pin in the EXTI registers

      // Falling-only:
      EXTI->RTSR &= ~bit; // disable rising
      EXTI->FTSR |=  bit; // enable falling

      // Unmask interrupt:
      EXTI->IMR |=  bit;

      // Clear pending:
      EXTI->PR =  bit;

    }
  }
}

// more specific init function rewritten to make converting to assembly easier
void HAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init){
  uint32_t pin = GPIO_Init->Pin;
  uint32_t pin_index = ctz(pin); // count trailing zeros to get the index of the pin

  /* LED: PA5 → output, push-pull, low speed, no pull */
  if (GPIOx == GPIOA && pin == GPIO_PIN_5) {
    // program type/speed/pull first, then mode (glitch-safe)
    GPIOA->OTYPER  &= ~(1u << pin_index);                    // push-pull
    GPIOA->OSPEEDR &= ~(3u << (pin_index*2u));              // low speed
    GPIOA->PUPDR   &= ~(3u << (pin_index*2u));              // no pull
    GPIOA->MODER    = (GPIOA->MODER & ~(3u << (pin_index*2u))) | (1u << (pin_index*2u)); // 01 = output
    return;
  }
}

// Rewritten GPIO function for exercise 1
void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState){
  if (PinState != GPIO_PIN_RESET) {
        GPIOx->ODR |=  (uint32_t)GPIO_Pin;
  } else {
        GPIOx->ODR &= ~(uint32_t)GPIO_Pin;
  }
}

// Rewritten GPIO function for exercise 1
void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    GPIOx->ODR ^= (uint32_t)GPIO_Pin;
}

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1) {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line) {
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line
     number, ex: printf("Wrong parameters value: file %s on line %d\r\n", file,
     line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
