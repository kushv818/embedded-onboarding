> Tags: I2C, SPI, UART, CAN, GPIO, DMA, ADC

# Reading for section 03: Peripherals and Protocols

**Goal:** Teach how to use the STM32 peripherals like the GPIO, ADC, Timers, and DMA, and communication protocols such as I2C and CAN. 

In section 01, you were able to write firmware for an STM32 microcontroller to blink an onboard LED. In this section, you will learn more ways to blink that same LED and also learn to interface and communicate with external devices and peripherals.

---

## 0. GPIO

**GPIO** stands for **General-Purpose Input/Output**. It is a digital pin on a microcontroller that you can control through firmware programming. GPIOs are important because they allow your microcontroller to interact with the physical world. With GPIO pins, you can do plenty of things such as reading sensors, communicating with other devices, and controlling LEDs, motors, and other high voltage devices.

With GPIO being a digital pin, it can be in one of two states:
- **HIGH** (3.3V)
- **LOW** (0V)
> Sometimes, development boards such as the Arduino will have HIGH as 5V, but the STM32 that you will be working with will use 3.3V as HIGH.

GPIOs can be programmed for various tasks. You can configure a GPIO to be either an:
- **Input**
    - Reading digital signals such as button presses
- **Output**
    - Sending digital signals out such as turning and LED on, or PWM signals

>You can also use GPIO inputs and outputs to emulate digital communication protocols that otherwise would not have been supported by the microcontroller using a technique known as [bit-banging](<https://en.wikipedia.org/wiki/Bit_banging>).

Although GPIOs are fundamentally digital pins, they can also be used as analog inputs/outputs, being able to read or output voltages between LOW (0V) and HIGH (+3.3V). Microcontrollers use a technique known as **PWM**, or **Pulse-Width Modulation** in order to simulate an analog output.

PWM works by rapidly switching a GPIO pin HIGH and LOW at an extremely high frequency, creating a signal what looks like a square wave. By varying the **Duty Cycle**, or the percentage of the time the square wave is HIGH compared to when it is LOW, you can control the level of voltage.

![alt text](image.png)

For example, if you wanted to output a GPIO pin at 1.65V, you would need a duty cycle of 50%. If you wanted an output of 0.825V, you would need a duty cycle of 25%.

PWM is especially important for LED dimming, as LEDs require a minimum voltage applied to turn on. With PWM, you are able to keep the LED at that voltage level without having it turn off. The LED dims because it turns on and off at a fast rate that your eyes cannot percieve, creating the illusion of dimming. You can also use PWM in the same context for controlling motor speeds.  

### GPIO STM32 Example
TODO: Write tutorial on how to blink and dim the LED and how to poll button inputs

