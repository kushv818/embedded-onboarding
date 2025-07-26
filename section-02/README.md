> Tags: Assembly, Armv8 Assembly, embedded systems, registers, HAL

# Computer Architecture

This section teaches you how to build a [Minecraft redstone computer.](https://www.youtube.com/watch?v=CW9N6kGbu2I)

You will also learn how a computer is structured, how memory works, how to program in assembly and how to take advantage of these characteristics.

## You should already know...

- C language fundamentals
  - data types
  - functions, arguments and return values
  - control structures (`if`, `else`, `for`, `while`)
  - how to use pointers
  - the different regions of memory and their purposes
    - how each region works
  - bitwise operations (`&`, `|`, `^`,` ~`, `<<`, `>>`)
- Compiling process
  - preprocessing, compiling, assembling, linking
  - purpose of `.c`, `.h`, `.o`, `.elf`, and linking object files
  - basic use of Makefile or build systems like cmake

If any of the items above are unfamiliar or unclear, go back and review the C Language section before proceeding.

## 0. Motivation of understanding a computer's architecture

You might have guessed by now that you will be writing assembly in this section. But that's not all that this section has to offer. So why do we care about computer architecture?

1. Your C code is **not** the whole story:

   - Despite the majority of your development being that you will be writing, compiling, debugging and executing C code, that is not where you can stop caring.
   - What's actually getting executed and how it's being executed is entirely up to the registers, instructions, stack frames and memory layout — many of which you may not understand how to use without knowing many of the computer architecture concepts that are taught here.

2. Embedded systems = talking **directly** to hardware:

   - Microcontrollers don't have (general purpose) operating systems to abstract things and manage resources for you.
   - You will be toggling bits inside registers, you will be managing timing down to the clock cycle.
   - You have to understand how memory is laid out, what registers do and what the compiler is doing behind the scenes.

3. Debugging
   - Why does this variable change randomly?
   - Why did the system crash after a function call?
   - Why is my ISR returning to the wrong place?
   - All of these are questions you will be answering when you are debugging (notice how I said when, not if. You will run into bugs at one point during your career.) Without knowledge of computer architecture, you will not know how to use the GDB or get use out of it.
   - Other debugging tools like `objdump` or `nm` are only incredibly useful if you know computer architecture.

Without computer architecture, you're programming blindly.

## 1. The Assembly Language

### Armv8 ISA

### QEMU

### Application Binary Interface

### Word

### Calling Conventions

### Inline Assembly

### Endianness

## 2. Register File

### Registers

### Special Registers

#### Program Counter

#### Stack Pointer

#### Link Register

#### Other reserved registers

### Hardware Registers with Memory Mapped I/O

### GPIO Example

### Hardware Abstraction Layer

## 3. Memory

### Cache

### Memory Map

### Stack Frames

## 4. Interrupts and Execution

### Systick

### Interrupt Service Routine

### Vector table

### Nested Vectored Interrupt Controller (NVIC)

### Exception handling and context switching

### The clock

### Interplay with operating systems

### Callback functions

## 5. Debuggers, Toolchains and Linkers

### Startup file

### Linkerscript

### GDB and Disassembly

### Watchpoints and Breakpoints

### Data Watchpoint & Trace (DWT) and Cycle Counting
