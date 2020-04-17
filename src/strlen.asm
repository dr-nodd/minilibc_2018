BITS 64

section .text

GLOBAL strlen:function

strlen:
    MOV RCX, 0

.strlen2:
    MOV AL, BYTE[RDI + RCX]
    CMP AL, 0
    JE .strlen3
    INC RCX
    JMP .strlen2

.strlen3:
    MOV RAX, RCX
    RET