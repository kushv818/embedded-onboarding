# Work for section 02

Estimated completion time: 2 days.

Do all of your work in this directory (but not in this file) so that it can be easily reviewed by a senior member later.

You should constantly be referring back to the reading or other external sources. It is not expected of you to complete all the exercises in this unaided.

## Exercise 1: DIY HAL in C

Remember blinking the LED in the last section?

Find this function in the HAL files: `void HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init)`.

Delete the generated definition within the C file. Rewrite your own definition of it in C. You should be able to test it by seeing if it compiles, and if it actually blinks the LED.

Do the exact same for `void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)` and `void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)`.

## Exercise 2: DIY HAL in Asm

Write excercise 1 in assembly. Use ARM Cortex-M (Thumb-2) assembly and the `arm-none-eabi` calling convention.

What did you learn? Write your response in another file in this directory.

## Exercise 3: Interrupts and Callbacks

Pt 1: Follow this tutorial: https://wiki.st.com/stm32mcu/wiki/Getting_started_with_EXTI

Pt 2: Follow this tutorial: https://community.st.com/t5/stm32-mcus/how-to-use-register-callbacks-in-stm32/ta-p/580499

## Exercise 4: Capture the bug

Welcome to the last exercise! This is a capture-the-flag style mini-game which will require you to hunt for hidden symbols.

You are given a black-box-esque ELF binary named `vault`. Embedded within the executable and linkable regions is a secret message.

You must extract this secret message and decode it using `gdb`, `nm`, and `objdump`.
