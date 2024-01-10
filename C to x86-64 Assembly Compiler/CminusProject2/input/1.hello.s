.section .rodata

.string_const0: .string "Hello world!\n"
.text
.global main
.type main,@function
main: nop
pushq %rbp
movq %rsp, %rbp
leaq .string_const0(%rip), %rdi
movl $0, %eax
call printf@PLT
leave
ret