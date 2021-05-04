%include "io.inc"

section .data
    k dq 6.0


section .text

global CMAIN

; f3''(x) = -3/(x^3)

CMAIN:
    push ebp
    mov esp, ebp
    
    finit
    fld qword[k]
    fld qword[ebp + 8]
    fld st0
    fld st0
    fmulp
    fmulp
    fdivp
    
    leave
    ret