BITS 64

section .text

global memmove

memmove:
    CMP RDI, RSI
    JG .membackcpy
    JMP .memfrontcpy

.membackcpy:
        MOV RCX, RDX
        SUB RCX, 1

.whileback:
        CMP RCX, -1
        JE .end
        MOV R10B, BYTE[RSI + RCX]
        MOV BYTE[RDI + RCX], R10B
        SUB RCX, 1
        JMP .whileback

.memfrontcpy:
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