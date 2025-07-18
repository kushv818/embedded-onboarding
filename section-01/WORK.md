# Work for section 01

Estimated completion time: 2 days.

Do all of your work in this directory (but not in this file) so that it can be easily reviewed by a senior member later.

You should constantly be referring back to the reading or other external sources. It is not expected of you to complete all the exercises in this unaided.

This section is probably the longest section as it covers the fundamentals.

> This tutorial assumes you are at least familiar with general programming concepts and syntax.

## Exercise 1: Hello World and compiling with `gcc`

1. Make a c file. Title it appropriately.
2. Inside your main function, write a function that prints `Hello, World!` to `stdout`.
3. Compile and run.
4. Take this easy exercise as an opprtunity to fix your toolchain, compiler settings, IDE settings and more.

## Exercise 2: FizzBuzz

1. Inside the file you used for exercise 1, make a function with signature ` FizzBuzz`
2. The function takes one `int n` as an argument, and returns nothing

   - If `n` is divisible by 3, print `Fizz`.
   - If `n` is divisible by 5, print `Buzz`.
   - If `n` is divisible by both 3 and 5, print `FizzBuzz`
   - If `n` is not divisible by either, print nothing.

3. Dynamically allocate an `int` array using pointer notation of size 20.
4. Populate the array with numbers from 1 to 20.
5. In `main`, run the function `FizzBuzz` on the array.
6. Also in main, write a `for-loop` on `FuzzBuzz` from 1 to 30.
7. Distinguish each output using print statements.

## Exercise 3: Function pointer practice

1. Do this in the same C file as (1) and (2).
2. `qsort` is a C standard library function that implements a sorting algorithm for arrays of arbitrary objects according to a user-provided comparison function.
   - Write the user-provided three-way comparison function for `int` data type.
3. Call `qsort` on the dynamiclaly alloacted buffer from exercise 2.

## Exercise 4: Blinky

> First embedded code!

#### In this exercise, you’ll blink the user LED using STM32 HAL functions:

1. Navigate to the `blinky` subdirectory. Some definitions:

   - Hardware Abstraction Layer (HAL): A software layer that allows your application to directly interact with the hardware of the microcontroller.

   - General Purpose Input/Output (GPIO): Pins on a microcontroller that can be configured as either inputs or outputs. They can be set to high (on) or low (off).

   - Think of GPIOs like a neighborhood:

     - A GPIO port (e.g., GPIOA, GPIOB, etc.) is like a street.

     - Each pin (e.g., PIN_5, PIN_13) is like a house on that street.

2. Go to `Core -> Src -> main.c`. Scroll down to line 100, inside the infinite while loop. You will write all of your code in there. Do not write code outside the while loop. Do not write code outside the `main.c` file.

3. Now go to `Drivers -> STM32F0xx_HAL_Driver -> Src -> stm32f0xx_hal_gpio.c`.

4. Scroll down to around line 415. Find the function

```C
void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
```

5. Now go to `Drivers -> STM32F0xx_HAL_Driver -> Src -> stm32f0xx_hal.c`

6. Scroll down to around line 359. Find the function

```C
__weak void HAL_Delay(uint32_t Delay)
```

7. Go to `Drivers -> STM32F0xx_HAL_Driver -> Inc -> stm32f0xx_hal_gpio.h`. At line 67, you will see the defined `enum` for the different `GPIO_PinState`s.

   - `GPIO_PIN_RESET` means setting the pin to low.
   - `GPIO_PIN_SET` means setting the pin to high.

8. Go back to the while loop in `main.c`. Consider the 2 functions you looked at earlier: `HAL_GPIO_WritePin(...)` and `HAL_Delay(...)`.

9. Go to `blinky.ioc` and search for `LD2` (line 65). This is your user LED. Remember the pin. Go to `Core -> Inc -> main.h` and remember which GPIO port and pin is mapped for `LD2`. Confirm that it looks like:

```C
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
```

10. Program the microcontroller such that the user LED blinks on 500 ms, then turns off for 500ms, then turns back on for 500ms and repeats this infinitely.

11. The NUCLEO-F030R8 is the hardware that this exercise targets. DFR has 3 in the shop; come see/talk to me to borrow it. You may also buy your own from this [DIGIKEY link](https://www.digikey.com/en/products/detail/stmicroelectronics/NUCLEO-F030R8/4695526?gad_campaignid=20243136172). They are about $12.

> Footnote: You are encouraged to seek out more C programming tutorials before you move on to the final project.

## Final project for this section

### Choose a project idea from any of the following:

1.
2.
3.

### Instructions that apply to all projects:

- You must link your project as a submodule within your forked copy of the repository

- Your code must be modular. You must write header files for each source file you write. You must also keep source files in a subdirectory called `src` and header files in a subdirectory called `inc`.

- You must use the _Make_ build system and you must write your own `makefile`. Requirements for build system:

  - It must place build output files in a subdirectory called `build`.
  - It should support `make clean`, which cleans the `build` folder.
  - It should support `make run`, which runs the built executable.

- You must write your own GitHub workflows config file. At minimum, it should:
  - Support
