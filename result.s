
.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $32, %rsp 
    movl $3, -16(%rbp)
    addq $32, %rsp 
    popq    %rbp
    ret
