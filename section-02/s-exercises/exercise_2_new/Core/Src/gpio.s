// DO NOT edit below
.syntax unified
.thumb
// DO NOT edit above

// FIND IN DATASHEET REGISTER MAP
.equ RCC_BASE,       0x40021000                // RCC base address
.equ RCC_AHBENR,     RCC_BASE + 0x14     // AHB Peripheral enable register
.equ GPIO_MODER,     0x00                // GPIO mode register offset from location of its respective GPIO_typedef struct
.equ GPIO_ODR,       0x14                // GPIO output data register offset from location of its respective GPIO_typedef struct

.global my_gpio_init
.global my_gpio_toggle
.global my_hal_delay

// !!! dont be afraid to look at the C implementation for help !!!
// dont over think it!! nothing is here to trick you !!

.thumb_func
my_gpio_init:
    ldr r3, = RCC_AHBENR                        // We have to enable some clock thing to init GPIOs
    ldr r4, [r3]						// Load the contents of the register
    orr r4, r4, #(1 << 17)             // Find the correct bit position to enable the RCC
    str r4, [r3]					// Update the register to the new value

    // r0: port base, r1: pin, r2: mode
    lsl r3, r1, #1 //multiply pin by 2, shift r1 left by 1
    mov r4, #3 // store 3
    lsl r4, r4, r3 // shift number 3 left by pin num *2 to get a mask at the correct position

    ldr r5, [r0, #GPIO_MODER]                  // what register are we modifying to set the mode?
    bics r5, r5, r4                      // clear the 2 bits first
    lsl r6, r2, r3						//
    orr r5, r5, r6
    str r5, [r0, #GPIO_MODER]                  // write back to the what register

    bx lr                                 // branch link register

.thumb_func
my_gpio_toggle:
    // r0 = port base
    // r1 = pin number

    ldr r2, [r0, #GPIO_ODR]                  // read output data register
    movs r3, #1
    lsl r3, r3, r1                      // create bitmask for pin using bit shift
    eor r2, r2, r3                      // what logic element toggles something?
    str r2, [r0, #GPIO_ODR]                  // write back to what register?

    bx lr                               // branch link register = return to caller

.thumb_func
my_hal_delay:
    // r0 = delay in ms

ms:
    movs r1, #1                       // adjust based on system clock frq  [CONSTANT]

cnt:
    subs r1, r1, #1                      // count down or count up? which instruction mnemonic supports that?
    bne cnt                             // loop until done, what branch condition do we want?

    subs r0, r0, #1
    bne ms

    bx lr
