%include "io.inc"

section .data
    k dq 3.0


section .text

global CMAIN

; f3(x) = 3/x

CMAIN:
    push ebp
    mov esp, ebp
    
    finit
    fld qword[k]
    fld qword[ebp + 8]
    fdivp
    
    leave
    ret