# Work for section 01

Estimated completion time: 2 days.

Do all of your work in this directory (but not necessarily in this file) so that it can be easily reviewed by a senior member later.

> This tutorial assumes you are at least familiar with general programming concepts and syntax.

## Exercise 1: Hello World and compiling with `gcc`

1. Make a c file. Title it appropriately.
2. Inside your main function, write a function that prints `Hello, World!` to `stdout`.
3. Compile and run.

## Exercise 2: FizzBuzz

1. Inside the file you used for exercise 1, make a function with signature `void FizzBuzz(int n)`
2. The function returns nothing.

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

## Exercise 4: Multifile C project

## Exercise 5: Blinky
