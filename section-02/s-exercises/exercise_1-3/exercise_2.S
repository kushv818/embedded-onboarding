.syntax unified                @ Use modern ARM assembly syntax
.cpu cortex-m4                 @ If building for STM32F0: use .cpu cortex-m0
.thumb                         @ Thumb / Thumb-2

.global HAL_GPIO_Init          @ exported symbol

/* --- constant addresses & offsets (STM32 GPIO) --- */
.equ GPIOA_BASE,     0x48000000    @ STM32F0 GPIOA base
.equ GPIO_MODER,     0x00          @ mode register
.equ GPIO_OTYPER,    0x04          @ output type
.equ GPIO_OSPEEDR,   0x08          @ speed
.equ GPIO_PUPDR,     0x0C          @ pull-up/down

/* --- pin constants for PA5 --- */
.equ PIN_INDEX,      5             @ PA5
.equ PIN_BIT,        (1 << PIN_INDEX)       @ 0x20
.equ FIELD_SHIFT,    (PIN_INDEX * 2)        @ 10
.equ FIELD_MASK,     (3 << FIELD_SHIFT)     @ 0x0C00
.equ MODE_OUTPUT,    (1 << FIELD_SHIFT)     @ 0x0400 (MODER=01)

HAL_GPIO_Init:
    @ R0 = GPIOx, R1 = GPIO_Init

    /* --- STAGE 1: save caller-saved we plan to use --- */
    PUSH    {R4, R5, R6, R7, LR}

    /* load GPIO_Init->Pin (offset 0 in HAL struct) */
    LDR     R2, [R1, #0]                  @ R2 = pin mask

    /* check pin == GPIO_PIN_5 (0x20) */
    MOVS    R3, #1
    LSLS    R3, R3, #PIN_INDEX            @ R3 = 1<<5
    CMP     R2, R3
    BNE     .Ldone                        @ not pin 5 -> no-op

    /* check GPIOx == GPIOA */
    LDR     R4, =GPIOA_BASE
    CMP     R0, R4
    BNE     .Ldone                        @ not GPIOA -> no-op

    /* --- STAGE 2: perform masked writes in glitch-safe order --- */
    /* OTYPER &= ~(1<<5)  (push-pull) */
    LDR     R5, [R0, #GPIO_OTYPER]
    BIC     R5, R5, R3                    @ clear bit 5
    STR     R5, [R0, #GPIO_OTYPER]

    /* prep masks/values for 2-bit fields */
    MOVS    R5, #3
    LSLS    R5, R5, #FIELD_SHIFT          @ R5 = FIELD_MASK (0x0C00)
    MOVS    R6, #1
    LSLS    R6, R6, #FIELD_SHIFT          @ R6 = MODE_OUTPUT (0x0400)

    /* OSPEEDR &= ~(3<<(5*2))  (low speed) */
    LDR     R7, [R0, #GPIO_OSPEEDR]
    BIC     R7, R7, R5
    STR     R7, [R0, #GPIO_OSPEEDR]

    /* PUPDR &= ~(3<<(5*2))  (no pull) */
    LDR     R7, [R0, #GPIO_PUPDR]
    BIC     R7, R7, R5
    STR     R7, [R0, #GPIO_PUPDR]

    /* MODER = (MODER & ~FIELD_MASK) | MODE_OUTPUT  (01: output) */
    LDR     R7, [R0, #GPIO_MODER]
    BIC     R7, R7, R5
    ORR     R7, R7, R6
    STR     R7, [R0, #GPIO_MODER]

.Ldone:
    /* --- STAGE 3: restore & return --- */
    POP     {R4, R5, R6, R7, PC}
