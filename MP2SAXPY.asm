section .text
global saxpy_asm

; void saxpy_asm(float A, float *X, float *Y, float *Z, int n)

saxpy_asm:
    ; A -> xmm0
    ; X -> rdi
    ; Y -> rsi
    ; Z -> rdx
    ; n -> rcx(array size)

    xor r8, r8 ; initialize loop, r8 = 0

saxpy_loop:
    cmp r8, rcx ; check if r8 >= n
    jge end

    movss xmm1, dword [rdi + r8*4] ; load X[i] into xmm1
    mulss xmm1, xmm0 ; xmm1 = A * X[i]
    movss xmm2, dword [rsi + r8*4] ; load Y[i] into xmm2
    addss xmm1, xmm2 ; xmm1 = A * X[i] + Y[i]
    movss dword [rdx + r8*4], xmm1 ; store result in Z[i]

    inc r8
    jmp saxpy_loop

end:
    ret
