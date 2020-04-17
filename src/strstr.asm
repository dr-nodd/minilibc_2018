BITS 64

section .text

GLOBAL strstr:function

strstr:
    MOV R8, RDI
    MOV R9, RSI
    MOV RAX, RDI
    XOR RCX, RCX

.strstr2:
    MOV R10B, BYTE[R8]
    MOV R11B, BYTE[R9]
    CMP R11B, 0
    JE .return
    CMP R10B, 0
    JE .retnull
    CMP R10B, R11B
    JE .increm0
    INC R8
    JMP .strstr2

.increm0:
    MOV RAX, R8

.increm1:
    MOV R10B, BYTE[R8 + RCX]
    MOV R11B, BYTE[R9 + RCX]
    CMP R11B, 0
    JE .return
    CMP R10B, R11B
    JE .increm2
    XOR RCX, RCX
    INC R8
    JMP .strstr2

.increm2:
    INC RCX
    JMP .increm1

.return:
    RET

.retnull:
    MOV RAX, 0
    RET