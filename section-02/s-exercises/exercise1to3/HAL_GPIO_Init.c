/*
The following two functions are rewritten versions of the HAL GPIO functions
do not compile this file, it is only for reference
Both functions exist within main.c, after the MX_GPIO_Init function
Uncomment only one of the two versions of the init function at a time in main.c to test
*/

// Init function version 1 - general purpose, but mainly for the two provided
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

// Init function version 2 - more specific, only for the LED pin,
// more specific init function rewritten to make converting to assembly easier
void HAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init){
  uint32_t pin = GPIO_Init->Pin;
  uint32_t pin_index = ctz(pin); // count trailing zeros to get the index of the pin

  /* LED: PA5 -> output, push-pull, low speed, no pull */
  if (GPIOx == GPIOA && pin == GPIO_PIN_5) {
    // program type/speed/pull first, then mode (glitch-safe)
    GPIOA->OTYPER  &= ~(1u << pin_index);                    // push-pull
    GPIOA->OSPEEDR &= ~(3u << (pin_index*2u));              // low speed
    GPIOA->PUPDR   &= ~(3u << (pin_index*2u));              // no pull
    GPIOA->MODER    = (GPIOA->MODER & ~(3u << (pin_index*2u))) | (1u << (pin_index*2u)); // 01 = output
    return;
  }
}