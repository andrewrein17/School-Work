.section .rodata

.string_const0: .string "10+30 = %d\n"
.string_const1: .string "result is %d\n"
.text
.global main
.type main,@function
main: nop
pushq %rbp
movq %rsp, %rbp
addq %rax, %rbx
leaq .string_const0(%rip), %rdi
movl $40, %esi
movl $0, %eax
call printf@PLT
addq %rsi, %r8
addq %r9, %r9
leaq .string_const1(%rip), %rdi
movl $10, %esi
movl $0, %eax
call printf@PLT
leave
ret
