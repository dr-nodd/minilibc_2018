BITS 64

section .text

global memcpy

memcpy:
        XOR RCX, RCX

.while:
        CMP RCX, RDX
        JE .end
        MOV R10B, BYTE[RSI + RCX]
        MOV BYTE[RDI + RCX], R10B
        INC RCX
        JMP .while

.end:
        MOV RAX, RDI
        RET