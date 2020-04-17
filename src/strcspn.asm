BITS 64

section .text

GLOBAL my_strlen:function

my_strlen:
    XOR RCX, RCX
    CMP RDI, 0
    JE .strlen3

.strlen2:
    MOV AL, BYTE[RDI + RCX]
    CMP AL, 0
    JE .strlen3
    INC RCX
    JMP .strlen2

.strlen3:
    MOV RAX, RCX
    RET

GLOBAL my_strpbrk:function

my_strpbrk:
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

GLOBAL strcspn:function

strcspn:
    CALL my_strpbrk
    MOV R8, RAX
    CALL my_strlen
    MOV R9, RAX
    MOV RDI, R8
    CALL my_strlen
    MOV R8, RAX
    SUB R9, R8
    MOV RAX, R9
    RET