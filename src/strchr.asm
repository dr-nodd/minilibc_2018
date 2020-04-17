BITS 64

section .text

GLOBAL strchr:function

strchr:
    MOV RAX, RDI

.strchr2:
    CMP BYTE[RAX], SIL
    JE .return
    CMP BYTE[RAX], 0
    JE .return_error
    INC RAX
    JMP .strchr2

.return:
    RET

.return_error:
    MOV RAX, 0
    RET