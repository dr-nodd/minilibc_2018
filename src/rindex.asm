BITS 64

section .text

GLOBAL rindex:function

rindex:
    MOV RAX, 0
    MOV R8, RDI

.rindex2:
    CMP BYTE[R8], SIL
    CMOVE RAX, R8
    CMP BYTE[R8], 0
    JE .return
    INC R8
    JMP .rindex2

.return:
    RET