# About

A collection of tutorials to help with the onboarding process for the embedded systems teams.

This onboarding tutorial serves to familiarize new members to the tools and skills the embedded teams use on a daily basis.

Nearly all of the concepts in here are something a member should be able to understand to be a successful member on the team.

## Notice

This tutorial set assumes a \*NIX environment (operating system). This includes:

- macOS (this tutorial was developed on macOS)
- all Linux distributions which includes but is not limited to

  - Arch
  - Ubuntu
  - Debian

- freeBSD and openBSD

All further instructions are written under the assumption that your environment is [POSIX compliant](https://stackoverflow.com/questions/1780599/what-is-the-meaning-of-posix).

If you're using Windows, you'll need a compatible environment to follow along effectively. I recommend one of the following:

1. Windows Subsystem for Linux (WSL) – Provides a native Linux environment on Windows. Suitable for most development workflows.

2. Virtual Machine (VM) – Run a Linux distribution using software such as VirtualBox or VMware.

3. Dual Boot Setup – Install Linux alongside Windows and choose your operating system at startup.

You can read more [here](https://github.com/DallasFormulaRacing/embedded-onboarding/wiki/DEnvironment).

## Table of Contents

| Section | Title                          | Difficulty | Learning Outcomes                                                                                                                                                                                                                      |
| ------- | ------------------------------ | ---------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 00      | Introduction & Version Control | -          | Basic grasp of embedded programming and an full understanding of git.                                                                                                                                                                  |
| 01      | The C Language                 | +          | Fundamental C programming concepts: control structures, pointers, structs, memory, basic data structures, volatile and weak.                                                                                                           |
| 02      | Computer Architecture          | +++        | Understanding of registers, compiler process, linking, RAM, stack and heap memory, working knowledge of ARMv8 assembly.                                                                                                                |
| 03      | Operating Systems              | +++        | Understanding of inner workings of operating systems, RTOS. Know how and what a scheduler does and works. Know how processes and threads work with each other. Understand parallelism and concurrency. Understand interrupts           |
| 04      | Peripherals and Protocols      | ++         | Interfacing with external modules. Know and understand CAN, I2C, SPI, GPIO. Know how to utilize DMA. Using the STM32 HAL to interface with peripherals.                                                                                |
| 05      | Hardware and Signal Processing | ++++       | Analog and digital signals and converting between the two. Basics of EMI mitigation. Signal processing and filtering basics. Introduction to filtering. CMSIS libraries. Debugging with JTAG and OpenOCD. Creating the IOC and pinout. |
| 06      | Final Project                  | +++        | Create a rudimentary data acquisition system; no hardware design required. Send information with print over UART.                                                                                                                      |

## References
