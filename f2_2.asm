%include "io.inc"

section .data
    a dq 2.0
    k dq 6.0

section .text

global CMAIN

; f2''(x) = 6*(x-2)

CMAIN:
    push ebp
    mov esp, ebp
    
    finit
    fld qword[k]
    fld qword[ebp + 8]
    fld qword[a]
    fsubp
    fmulp
    
    leave
    ret