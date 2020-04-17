BITS 64

section .text

GLOBAL strpbrk:function

strpbrk:
    MOV R8, RDI
    MOV R9, RSI
    XOR RCX, RCX

.strpbrk1:
    MOV R10B, BYTE[R8]
    MOV R11B, BYTE[R9]
    CMP R10B, 0
    JE .retnull
    CMP R10B, R11B
    JNE .increm

.strpbrk2:
    CMP R10B, R11B
    JE .return
    INC R8
    JMP .strpbrk1

.increm:
    CMP R11B, 0
    JE .reset
    CMP R10B, R11B
    JNE .increm2
    CMP R10B, R11B
    JE .return

.increm2:
    MOV R11B, BYTE[R9 + RCX]
    INC RCX
    JMP .increm

.reset:
    XOR RCX, RCX
    JMP .strpbrk2

.retnull:
    MOV RAX, 0
    RET

.return:
    MOV RAX, R8
    RET