.section .rodata

.string_const0: .string "10-20 = %d\n"
.string_const1: .string "result is %d\n"
.text
.global main
.type main,@function
main: nop
pushq %rbp
movq %rsp, %rbp
subq %rbx, %rax
leaq .string_const0(%rip), %rdi
movl $-10, %esi
movl $0, %eax
call printf@PLT
subq %r8, %rsi
subq %r10, %r9
leaq .string_const1(%rip), %rdi
movl $70, %esi
movl $0, %eax
call printf@PLT
leave
ret
