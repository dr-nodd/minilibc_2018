BITS 64

section .text

GLOBAL strncmp:function

strncmp:
    MOV R8, RDI
    MOV R9, RSI
    MOV R13D, EDX
    XOR R10, R10
    XOR R11, R11
    XOR R12, R12

.strncmp2:
    CMP R10D, R13D
    JE .strncmp3

    MOV R11B, BYTE[R8 + R10]
    MOV R12B, BYTE[R9 + R10]

    CMP R11B, R12B
    JNE .strncmp3

    CMP R11B, 0
    JE .ret_error

    INC R10

    JMP .strncmp2

.strncmp3:
    SUB R11B, R12B
    MOVSX EAX, R11B
    RET

.ret_error:
    MOV RAX, 0
    RET