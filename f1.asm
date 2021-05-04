%include "io.inc"

section .data
    k dq 0.6
    b dq 3.0

section .text

global CMAIN

; f1(x) = 0.6 * x + 3

CMAIN:
    push ebp
    mov esp, ebp
    
    finit
    fld qword[b]
    fld qword[ebp + 8]
    fld qword[k]
    fmulp
    faddp
    
    leave
    ret