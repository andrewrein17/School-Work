.section .rodata

.string_const0: .string "10*20 = %d\n"
.string_const1: .string "result is %d\n"
.text
.global main
.type main,@function
main: nop
pushq %rbp
movq %rsp, %rbp
imulq %rax, %rbx
leaq .string_const0(%rip), %rdi
movl $200, %esi
movl $0, %eax
call printf@PLT
imulq %rsi, %r8
imulq %r9, %r10
leaq .string_const1(%rip), %rdi
movl $84, %esi
movl $0, %eax
call printf@PLT
leave
ret
