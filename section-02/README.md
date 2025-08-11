> Tags: Assembly, Armv8 Assembly, embedded systems, registers, HAL

# Computer Architecture

This section teaches you how to build a [Minecraft redstone computer.](https://www.youtube.com/watch?v=CW9N6kGbu2I)

You will also learn how a computer is structured, how memory works, how to program in assembly and how to take advantage of these characteristics.

In these tutorials, we will be studying the ARM architecture, which is a Reduced Instruction Set Computer (RISC) architecture. More specifically, we will be developing using ARMv6-M and similar families of assembly to supplement your learning of hardware and software.

In contrast, the x86 architecture, which you may be more familiar with due to it being a product of [Intel](https://en.wikipedia.org/wiki/Intel_8086) and [AMD](https://en.wikipedia.org/wiki/Opteron), is a Complex Instruction Set Computer (CISC).

The primary goal of CISC architecture is to complete a task in as few lines of assembly as possible. This is achieved by building processor hardware that is capable of understanding and executing a series of operations. Thus, as the name suggests, it has a more complex instruction set.

On the other hand, the RISC school of thought strives to only use simple instructions that can be executed within one clock cycle. More accurately, it aimrs to use a small, regular set of simple instructions that are easy to **pipeline** and optimize in hardware. This simplicity enables more predictable performance and efficient instruction execution, often within a single clock cycle. This means that developers will be writing more lines of assembly per task, but it also means that we as developers have more control over the software we execute.

Unfortunately, despite the advantages of RISC based processing, RISC chips took over a decade to gain a foothold in the commercial world. This was largely due to a lack of software support that companies in the early 1990's were not willing to invest in...

There are many caveats to each design theory, and in practice, modern architectures often incorporate elements of both. However, understanding these core philosophies gives you the insight needed to reason about performance, efficiency, and system design.

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

## 0.1 Some prerequisite topics

### Clock

The clock is the heartbeat of any computer and produces a steady, square wave output from either an internal crystal oscillator or an external one.

Intuitively, we know that computers are clock controlled because if we were to run an empty loop like so:

```C
for (int i = 0; i < 1000000; ++i); // one million times
```

Though this _appears_ to execute almost instantly, we know that it doesn't. For me, it takes 0.000681 seconds. If I ran

```C
for (int i = 0; i < 50000000; ++i); // fifty million times
```

I can see it takes 0.022914 seconds, which is longer. While it's not exactly 50 times slower, (it's about 33 times slower), we can see that even though these loops “do nothing,” the CPU still executes multiple instructions per iteration:

- incrementing the counter,
- comparing it to the limit,
- branching

and each of those operations consumes clock cycles. The work is invisible to the user, but it's still happening step-by-step in hardware.

---

The clock signal is a digital signal (meaning it has only 2 logic levels: 0 and 1) and looks like this: especially registers and memory.

```
Time   →      0   1   2   3   4   5   6   7   8   9   10
Level  →     ───┐   ┌───┐   ┌───┐   ┌───┐   ┌───┐   ┌───
                └───┘   └───┘   └───┘   └───┘   └───┘
Binary →      1   0   1   0   1   0   1   0   1   0   1

```

Let's talk about the picture. Between time 0 and time 1 (similarly between time 3 and 4 or time 7 and 8) the clock goes from logic level 0 to logic level 1. We call this a rising edge. Conversely, between time 1 and time 2, the logic level goes from 1 to 0. We call this the falling edge of the clock.

**Many components of the computer are controlled by the rising edge of the clock, such as registers and memory.**

Without diving too much into digital circuits, the clock is one of the core components of any computer.

Question for you: if the clock is purely in control of how quickly my CPU can execute something, why can't we just crank up the clock speed for more performance?

Answer: Let's say signals propagated instantly, we have unlimited money for the electricity bill and you had a cooling system capable of swapping heat at 100% efficiency. Then yes, we can do this.

But unfortunately, these conditions do not hold in the real world.

### How we measure a computer's performance

A computer's performace is measured by the following ratio:

$$
\frac{\text{time}}{\text{program}}
$$

"How much time does it take to execute this program?"

But this is a very broad question and can't do much with it, so we can expand the original equation as such:

$$
\frac{\text{time}}{\text{program}} = \frac{\text{time}}{\text{cycle}} \times\frac{\text{cycles}}{\text{instruction}} \times \frac{\text{instructions}}{\text{program}}
$$

And now this is a much more solvable equation.

### Endianness

Endianness basically describes the placement of the most signficant bit and the least signficant bit (obviously they must be on the opposite side of each other).

In little-endian systems, the least significant byte is stored first (at the lowest memory address).

In big-endian systems, the most significant byte comes first.

## 1. The Assembly Language

### What is an instruction

Because assembly language is often 1:1 correlated with actual machine language (as in 1s and 0s), an assembly instruction usually corresponds to one machine instruction.

Because all\* computers are some combination of digital electronics, the machine instruction must be comprised of only two logic levels: voltage high and voltage low, or as we use: 1s and 0s.

### Instruction types and formats

### QEMU

### Application Binary Interface

### Word

### Calling Conventions

### Inline Assembly

## 2. Register File

The concept of computer registers are essential to computer architecture as a whole. The register file is the collection of registers organized within the central processing unit (CPU).

### Registers

Registers are areas in the CPU where data can be processed. CPUs don’t operate on memory directly, but instead data is loaded into registers, processed, and written back to memory. In assembly language, generally, you cannot directly copy data from one memory location to another without first passing that data through a register.

Registers are normally measured by the number of bits they can hold, and denote that computers bit width; for example, a 32 bit computer has 32 bit registers.

Registers are often the smallest structure of memory any computer can use. Registers are not cache, and cache memory is something else entirely.

### General Purpose Registers

The first type of register is what is known as a General Purpose Register (GPR). GPRs are referred to as general purpose because they can contain either data, in this case up to a 64-bit value, or a memory address (a pointer). A value in a GPR can be processed through operations like addition, multiplication, shifting, etc.

General purpose registers can be thought of as your scratch paper. It largely does not matter what a general purpose register holds as long as the concept of execution remains untouched; they are flexible, and as the name suggests, multi-purpose.

### Special Registers

The second type of registers are special registers. These generally do not hold data but exist to maintain the state of execution for a program. Most computer systems have these registers.

#### Program Counter (PC)

The program counter register points (i.e. holds the address) to the current instruction being executed. It is the CPU’s built-in tracker for where it is in your program. It always holds the memory address of the next instruction the CPU will run.

Every time the CPU completes an instruction, the PC moves forward to the next one. If you run a branch or jump, the PC is updated with a new address so the CPU can continue somewhere else.

#### Stack Pointer (SP)

The stack pointer points to the top of the stack. The stack holds your saved general purpose registers and the return address. Like in section 1, when the Stack Pointer exceeds your allocated RAM region for the stack, you get stack overflow and the memory it reads is no longer valid, which will either trigger a segfault (only on computers with memory protection) or silently fail (more likely with embedded cores).

#### Link Register (LR)

The link register holds the return address of a function. Returning from a function often involves moving the contents of LR into PC. When a function is called, the CPU needs to remember where to come back to after the function finishes. Instead of always pushing that address onto the stack, many architectures have a dedicated link register for this purpose.

### Other reserved registers

Sometimes certain architectures have more reserved registers. Some are operating system reserved, sometimes not.

ARM has a few more special registers that are largely architecture-dependent that should be mentioned here. These are known as program status registers (PSR). Physically speaking, the PSR is actually three registers combined into one to save space.

#### Arithmetic flag PSR (APSR)

holds condition flags from arithmetic/logical ops, which can be one of `N` for negative, `Z` for zero, `C` for carry, and `V` for overflow.

#### Interrupt PSR (IPSR)

holds the exception number of the currently running handler. 0 means the CPU is running in Thread mode (normal program execution). Nonzero values indicate Handler mode — the CPU is servicing an exception or interrupt.

For example, `IPSR` = `16` means that the SysTick handler is running. `IPSR` = `3` means that the HardFault handler is running. This is useful for debugging which interrupt you’re in or writing code that behaves differently depending on whether you’re in normal execution or interrupt context.

#### Exectution PSR (EPSR)

holds the execution state. It's main jobs are to keep the T-bit set to indicate Thumb execution and track if-then blocks' progress and condition. As a developer, you do not have to worry about this too much, as it is mostly handled by the computer for you.

### Hardware Registers with Memory Mapped I/O

### GPIO Example

### Hardware Abstraction Layer

## 3. Memory

### Cache

### Memory Map

### Memory Alignment

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

### GDB: GNU Debugger

### Dissassembly: `nm`, `readelf` and `objdump`

### Watchpoints and Breakpoints

### Data Watchpoint & Trace (DWT) and Cycle Counting
