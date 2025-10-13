.syntax unified        @ Use modern ARM assembly syntax
.cpu cortex-m4         @ Target the Cortex-M4 instruction set
.thumb                 @ Use Thumb-2 instructions

.global HAL_GPIO_Init  @ Make the function name visible to the linker

HAL_GPIO_Init:
    @ R0 = GPIOx, R1 = GPIO_Init
    
    @ --- STAGE 1: Preservation (Calee-saved registers) ---
    @ If we use R4, R5, R6, etc., we must save them.
    @ Push multiple registers onto the stack. LR holds the return address.
    PUSH {R4, R5, R6, R7, R8, LR} 

    @ --- STAGE 2: Implementation (The R-M-W logic goes here) ---
    
    @ ... (Load parameters from R1 struct, calculate shifts, LDR/AND/ORR/STR) ...
    
    @ --- STAGE 3: Cleanup ---
    @ Pop the saved registers back, restoring the caller's R4-R8 state.
    @ Pop LR into PC to return to the calling function.
    POP {R4, R5, R6, R7, R8, PC}
    
    @ End of function