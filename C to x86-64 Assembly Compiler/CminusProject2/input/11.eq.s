.section .rodata

.string_const0: .string "%d\n"
.string_const1: .string "%d\n"
.string_const2: .string "%d\n"
.string_const3: .string "%d\n"
.text
.global main
.type main,@function
main: nop
pushq %rbp
movq %rsp, %rbp
cmpq %rdi, %rsi
cmove %rdi, %rsi
leaq .string_const0(%rip), %rdi
movl $0, %esi
movl $0, %eax
call printf@PLT
cmpq %rdi, %rdi
cmovne %rdi, %rdi
leaq .string_const1(%rip), %rdi
movl $0, %esi
movl $0, %eax
call printf@PLT
cmpq %r8, %r8
cmove %r8, %r8
leaq .string_const2(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
cmpq %r8, %r9
cmovne %r8, %r9
leaq .string_const3(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
leave
ret
