%include "io.inc"

section .data
    a dq 2.0
    b dq 1.0

section .text

global CMAIN

; f2(x) = (x-2)^3 - 1

CMAIN:
    push ebp
    mov esp, ebp
    
    finit
    fld qword[ebp + 8]
    fld qword[a]
    fsubp
    fld st0
    fld st0
    fmulp
    fmulp
    fld qword[b]
    fsubp
    
    leave
    ret