BITS 64

section .text

GLOBAL memset:function

memset:
    MOV RAX, RDI
    XOR RCX, RCX

.memset2:
    CMP RCX, RDX
    JNE .memset3
    RET

.memset3:
    MOV BYTE[RAX + RCX], SIL
    INC RCX
    JMP .memset2