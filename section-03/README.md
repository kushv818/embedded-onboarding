> Tags: I2C, SPI, UART, CAN, GPIO, DMA, ADC

# Reading for section 03: Peripherals and Protocols

**Goal:** Teach how to use the STM32 peripherals like the GPIO, ADC, Timers, and DMA, and communication protocols such as I2C and CAN. 

In section 01, you were able to write firmware for an STM32 microcontroller to blink an onboard LED. In this section, you will learn more ways to blink that same LED and also learn to interface and communicate with external devices and peripherals.

---

## 1. General-Purpose Input/Output (GPIO)

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

>You can also use GPIO inputs and outputs to emulate digital communication protocols using a technique known as [bit-banging](<https://en.wikipedia.org/wiki/Bit_banging>).

### Exercise 1: Using a Button to Turn On an LED
Navigate to ```WORK.md``` in this section and begin the first exercise.

### Using GPIO with Analog Signals

Although GPIOs are fundamentally digital pins, they can also be used to simulate analog inputs/outputs, being able to read or output voltages between LOW (0V) and HIGH (+3.3V). Microcontrollers use a technique known as **PWM**, or **Pulse-Width Modulation** in order to simulate an analog output.

PWM works by rapidly switching a GPIO pin HIGH and LOW at an extremely high frequency, creating a signal what looks like a square wave. By varying the **Duty Cycle**, or the percentage of the time the square wave is HIGH compared to when it is LOW, you can control the level of voltage as seen in the image below.

![alt text](../assets/3/PWMExample.png)

For example, if you wanted to output a GPIO pin at 1.65V, you would need a duty cycle of 50%. If you wanted an output of 0.825V, you would need a duty cycle of 25%. You can control these duty cycles using hardware timers, which we will demonstrate later in section 03.

A real world example of using PWM is for LED dimming, as LEDs require a minimum voltage applied to turn on. With PWM, you are able to keep the LED at that voltage level without having it turn off. The LED dims because it turns on and off at a fast rate that your eyes cannot percieve, creating the illusion of dimming. You can also use PWM in the same context for controlling motor speeds. 

### How to use PWM
Below are a couple of formulas you can use to calculate your desired voltage using PWM.

**Total Period (s)**

$$
\text{Total Period} = T_{\text{HIGH}} + T_{\text{LOW}}
$$

- $\text{Total Period}$ is the sum of how long the output is HIGH and how long it is LOW for one iteration
- $\text{T}_\text{HIGH}$ is the amount of time in seconds during the period when the output is HIGH
- $\text{T}_\text{LOW}$ is the amount of time in seconds during the period when the output is LOW

**<br>Duty Cycle (%):**

$$
\text{Duty Cycle} = \frac{T_{\text{HIGH}}}{\text{Total Period}} \times 100
$$

Where:
- $\text{Duty Cycle}$ is the percentage of time the signal is HIGH
- $\text{T}_\text{HIGH}$ is the amount of time in seconds during the period when the output is HIGH
- $\text{Total Period}$ is the sum of how long the output is HIGH and how long it is LOW for one iteration

**<br>Average Output Voltage:**

$$
V_{\text{out}} = V_{\text{HIGH}} \times \frac{\text{Duty Cycle}}{100}
$$

Where:
- $V_{\text{out}}$ is the average voltage output
- $V_{\text{HIGH}}$ is the logic HIGH voltage (3.3V)
- Duty Cycle is the percentage of time the signal is HIGH

## 2. Interrupts

An **Interrupt** is a signal that pauses the code that is currently running in order to execute another piece of code before resuming its previous task. Interrupts are extremely important in embedded systems as they offer an immediate response to time-critical events such as button presses, sensor and communication data, or indications of data buffers being full. 

### Types of Interrupts

There are two types of interrupts we will be looking at:
- **External**
- **Internal**

**External** interrupts are triggered by hardware outside of the microcontroller such as buttons, sensors, keyboards, or mice.

**Internal** interrupts are triggered by events inside of the microcontroller through peripherals such as timers, ADC completion, data buffers being full, or software events such as system calls. 

### How do Interrupts Work?

While the main program is running, an **IRQ** or **Interrupt Request** signal will be sent either internally or externally to alert the CPU. The processor will then pause the main program and save its current state before **handling** the interrupt by jumping to and executing an **ISR** or **Interrupt Service Routine**, which is a function designed to run upon an IRQ. After the ISR has completed, the program will resume the main program from its previous saved state.

### Polling Vs Interrupts

In [1. GPIO](#1-gpio) you were able to learn about how GPIOs can read digital signals from external peripherals such as buttons. Using this knowledge, if you wanted to read the input of a button to turn on an LED by constantly checking the state of the button in the main loop in a method known as **Polling**, which is what you did in [Exercise 1](#exercise-1-using-a-button-to-turn-on-an-led).

Polling can be very easy to implement and is easily understandable and able to be debugged, but it consumes CPU usage and power because it would constantly run in the background. Another disadvantage to polling is that it cannot handle time-critical tasks, and it may miss events if it is polling too slowly. 

>Another example: If you had an accelerometer sensor that outputs at a certain rate and you wanted to implement a [Kalman Filter](https://en.wikipedia.org/wiki/Kalman_filter), which requires the state of the system to be updated at a certain time rate, polling may update it too fast which could also it mess up. 

Interrupts can solve a lot of the issues mentioned above, but the disadvantages to using interrupts are that it can be harder to understand and debug, and introduce bugs if the ISR is written improperly. Using too many interrupts in a program can lead to even less efficiency because it can overwhelm the CPU, as it requires a lot of overhead to pause the main program, save its state and execute the ISR.

>You may have experienced your computer slowing down and opened up the Task Manager. You may have also come across a high usage of system interrupts leading to high CPU usage. This is an example of what can go wrong with interrupts.

This section went over a basic introduction to interrupts. You will learn more about interrupts in section-04.

### Exercise 2: Using Button Interrupts to Turn On an LED
Navigate to ```WORK.md``` in this section and begin the second exercise.

## 3. Timers
**Timers** are a hardware peripheral that count the number of clock ticks in order to generate precise timing intervals, which could be used to control pin timing, generate delays, and synchronize event timing.

> Circling back, PWM is a great example of how precise delays generated by timers can be used

Timers work by counting the number of clock pulses and resetting when hitting the max value based on the timer's bit resolution. For example, a 16-bit timer will count up (or down) starting from 0 and increment on every clock pulse until hitting 65535 and resetting. Upon reset, an interrupt signal is generated and will run whatever you put in its ISR.

You can measure how long a timer period is using the formula below.

$$
    \text{Timer Period} = \frac{{\text{Max Value}}}{\text{Bus Frequency}}
$$

For example, a 48MHz clock on the AHB Bus with a max value of 65535 will reset about every $1635 \mu s.$ 

### How to Control Timers

Timers can be programmed to run as fast or slow as the user wants. All timers are tied to a clock bus for peripherals that by default run at a very high rate. The bus clock can be slowed down specifically for a timer peripheral using a **Prescaler**, which divides the clock source in order to slow it down to whatever rate you need the timer to run at. The formula below shows how you will use it.

$$
    \text{Timer Frequency} = \frac{{\text{Bus Frequency}}}{\text{Prescaler Value - 1}}
$$

>Note: For the STM32, it is important to subtract 1 from the desired value of the prescaler as it is how they are designed to work.

For example, if I wanted a timer that operates at 48kHz, I would enter a prescalar value of 1000. 

If you wanted to manually set the max value, you could also use the **ARR** or **Auto-Reload Register**, which allows you to set up the max counter value. If you wanted the clock to stop at 32768, the ARR will allow you do do that.

Putting it all together, the formula for setting your desired timer frequency will look like this.

$$
    \text{Timer Frequency} = \frac{{\text{Bus Frequency}}}{\text{(Prescaler Value - 1)} * \text{(ARR Value - 1)}}
$$

## 4. Analog-to-Digital Converters (ADC)

An **Analog-to-Digital Converter** or **ADC** is a peripheral that converts an analog signal, such as a voltage into a digital format that the microcontroller can use. Every ADC works by sampling a signal discretely at certain time points and converting it to a digital format in a process known as **Quantization**. 

On the STM32, the ADC works using a **Successive Approximation Register** or **SAR**. The ADC will sample and hold the input voltage signal, and compare the sampled voltage to set internal voltage references using a binary search. 

### Nyquist-Shannon Sampling Theorem

When using an ADC, it is important to know the **Nyquist-Shannon Sampling Theorem**, which states that for any continuous-time signal, you would need to sample at a rate at least 2-times higher than its highest frequency component. This would mean if the highest frequency signal you are expecting to sample is 6kHz, you will need the ADC to sample at 12kHz at the minimum.  

If an ADC is sampling at 12kHz, the ADC will only be able to read up to 6kHz, which will be your **Nyquist Frequency**. Any signals above the Nyquist Frequency will be read poorly and get mixed into your main signal in what is known as **Aliasing**.

>You will learn more about analog and digital signal processing and how to prevent aliasing in section-05. 

### Converting ADC Values to a Voltage

When using the ADC, you will get a value from $0$ to $2^N-1$, with $N$ being the resolution in the number of bits of the ADC. To convert this number into a voltage of type float or double, you would need to use the formula below.

$$
\text{V} = \frac{\text{Val}_\text{ADC}}{2^N - 1} * \text{V}_{\text{REF}}
$$



Where:
- $V$ is the measured voltage
- $\text{Val}_\text{ADC}$ is the digital value read from the ADC
- $N$ is the ADC resolution in bits
- $V_{\text{REF}}$ is the reference voltage for the ADC (3.3V on STM32)

For example, if you have a 12-bit ADC ($N = 12$), a reference voltage of $3.3V$, and the ADC reads a value of $2048$:

$$
V = \frac{2048}{4095} * 3.3V \approx 1.65V
$$


## 5. Direct Memory Access (DMA)
TODO

## 6. Serial Communication
TODO

## 7. Universal Asynchronous Receiver/Transmitter (UART)
TODO

## 8. Serial Peripheral Interface (SPI)
TODO

## 9. Inter-Integrated Circuit (I2C)
TODO

## 10. Controller Area Network (CAN)
TODO

