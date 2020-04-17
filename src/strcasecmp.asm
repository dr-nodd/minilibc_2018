BITS 64

section .text

GLOBAL strcasecmp:function

strcasecmp:
    MOV R8, RDI
    MOV R9, RSI
    XOR RCX, RCX

.strcmp2:
    MOV R11B, BYTE[R8 + RCX]
    MOV BL, BYTE[R9 + RCX]

    MOV R10B, R11B
    MOV R12B, BL
    CMP R11B, BL
    JNE .toupper1

    CMP R11B, 0
    JE .ret_error

    INC RCX
    JMP .strcmp2

.casecmp:
    CMP R11B, BL
    JE .incremcmp
    SUB R10B, R12B
    MOVSX EAX, R10B
    RET

.toupper1:
    CMP R11B, 0x61
    JGE .iflower
    JMP .toupper2

.iflower:
    CMP R11B, 0x7A
    JLE .capitalletter
    JMP .toupper2

.capitalletter:
    SUB R11B, 0x20
    JMP .toupper2

.toupper2:
    CMP BL, 0x61
    JGE .iflower2
    JMP .casecmp

.iflower2:
    CMP BL, 0x7A
    JLE .capitalletter2
    JMP .casecmp

.capitalletter2:
    SUB BL, 0x20
    JMP .casecmp

.incremcmp:
    INC RCX
    JMP .strcmp2

.ret_error:
    MOV RAX, 0
    RET