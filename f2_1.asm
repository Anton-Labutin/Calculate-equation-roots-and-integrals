%include "io.inc"

section .data
    a dq 2.0
    k dq 3.0

section .text

global CMAIN

; f2'(x) = 3*(x-2)^2

CMAIN:
    push ebp
    mov esp, ebp
    
    finit
    fld qword[k]
    fld qword[ebp + 8]
    fld qword[a]
    fsubp
    fld st0
    fmulp
    fmulp
    
    leave
    ret