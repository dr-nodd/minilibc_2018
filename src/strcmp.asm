BITS 64

section .text

GLOBAL strcmp:function

strcmp:
    MOV R8, RDI
    MOV R9, RSI
    XOR R10, R10

.strcmp2:
    MOV R11B, BYTE[R8 + R10]
    MOV R12B, BYTE[R9 + R10]

    CMP R11B, R12B
    JNE .strcmp3

    CMP R11B, 0
    JE .ret_error

    INC R10
    JMP .strcmp2

.strcmp3:
    SUB R11B, R12B
    MOVSX EAX, R11B
    RET

.ret_error:
    MOV RAX, 0
    RET