%include "io.inc"

section .data
    k dq 0.6

section .text

global CMAIN

; f1'(x) = 0.6

CMAIN:
    push ebp
    mov esp, ebp
    
    finit
    fld qword[k]
    
    leave
    ret