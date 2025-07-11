> Tags: embedded systems, C language, embedded C

# Reading for section 01: Introduction to the C language, general C syntax, embedded C, and compilers.

> ### Important! Read Below:

If at this point you have _never, ever_ written software (in any shape or form), I highly recommend you stop here and pick up a programming language tutorial **outside of this one**. Here are some suggestions for your first programming language:

- Python (easiest)
- C++ (the best first language)
- Java (NOT Javascript)

Languages that should not be your first:

- Rust
- Any Assembly language
- C \(1)

> (1) this is debatable, as C is normally a very good first, but for the sake of this tutorial, i think its better to take on a more high level language for a first language.

Once you feel like you have a good grasp on syntax, program structure, and program control, come back to this tutorial.

# C language

**Goal:** Teach the core features of C relevant to embedded development without assuming prior C experience.

---

## 1. Why C?

### History & purpose of C

- C was created in 1972 by Dennis Ritchie at Bell Labs, orignally designed for a complete rewrite of the UNIX operating system; namely, the utility binaries and the Unix kernel.

- At the time, assembly was the most popular language used to program computers, but assembly was too verbose and unreadable. C was created as a _high-level_ alternative to assembly development.

- Despite its age, C still sees usage in device drivers, operating systems, and in our case, embedded systems.

- C does not support object oriented paradigms, like classes, inheritance or encapsulation. C does, however, provide composite data structures via `structs` and `unions`.

### Why C dominates embedded systems

- As stated earler, C is used heavily in embedded systems, with its only real competition being Rust or C++.

- C compiles to fast and predictable machine code with very minimal overhead.

  - Let's take a look at this sentence:
  - C is compiled:
    - A compiled language is different from an interpreted language, like Java or Python.
    - Compiled means that C code is translated directly into native machine code (1s and 0s).
  - Fast and predictable machine code:
    - Predictability is good; this means that optimizations like branch prediction and cache algorithms can do more.
    - C++ has a feature called `templates`, which basically allows for boilerplate code. While this is convenient and more readable, sometimes this will blow up the binary size.
    - Fast is also good, since embedded systems always need to meet real-time requirements.
  - Minimal overhead:
    - Languages like Java use what's called **garbage collectors**. These are background, under-the-hood programs that automatically manages memory for us. Despite the convenience, it makes an impact on performance.
    - C nor C++ do not have garbage collectors; memory management must be coded in alongside the actual program.

- As a direct descendant of assembly language, C allows for direct hardware access. This means we can do:

  - Pointer math
  - Bitwise manipulation
  - Memory mapped I/O

- All of this matters because

  - Microcontrollers have very limited memory (usually hundreds of kilobytes)
  - CPU clock speeds in the millions (commercial cpus are in the billions)
  - No operating system, and if any, a very barebones RTOS (explained later in this tutorial)

- As for other reasons why C is so widely used in embedded software development, C...
  - is very portable (as a result of its age and popularity)
  - has long term support
  - has extensive documentation
  - if you tell someone your main/fav language is C their opinion of you will improve

---

## 2. Basic Syntax and Program Structure

### `main()` function

- All programs begin execution at main.
- All programs need a main function.
- You can write all the drivers in the world but if they are not called in main they will not run.

It normally looks like: `int main(void)` or sometimes `int main(int argc, char** argv)`.

### Headers and `#include`

- You can make your code modular by including another file with relevant functions.
  - Let's say you made a file called `animals.c` and in it, you wrote

### `printf()`, return values, and compilation

_Mini-exercise:_

---

## 3. Control Structures

### `if`, `else`, `switch`

### `for`, `while`, `do-while` loops

### `break` and `continue`

_Mini-exercise:_

---

## 4. Variables and Data Types

### `int`, `float`, `char`, `double`

### Type specifiers: `unsigned`, `long`, `short`

### Type sizes and portability (`stdint.h`)

_Mini-exercise:_

---

## 5. Functions

### Syntax: return types, arguments

### Scope: local vs global

### Declaration vs definition

_Mini-exercise:_

---

## 6. Pointers and Memory

### What is a pointer? (Memory address model)

### `*`, `&`, pointer arithmetic

### Arrays vs pointers

### Pointer pitfalls

_Mini-exercise:_ Swap two integers using pointers

---

## 7. Structs and `typedef`

### Declaring and using structs

### Nested structs

### `typedef` for clean code

_Mini-exercise:_ Define a `struct` for sensor data

---

## 8. Embedded-Specific Concepts

### `volatile`: why it matters in hardware

### `const`, `static`, and `extern`

### `__attribute__((weak))` for override-able definitions

### Memory-mapped I/O example

_Mini-exercise:_ Simulate an LED toggle register

---

## 9. Style and Best Practices

### Naming conventions

### Header files and code organization

### Commenting and documentation style

### `#define` vs `const`

---

## 10. Compilers and Build Systems

### Other gcc specific attributes.
