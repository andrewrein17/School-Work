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
addq %rdi, %rsi
cmpq %r8, %r9
cmove %r8, %r9
cmovne %r8, %r9
leaq .string_const0(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
imulq %r11, %rsi
imulq %rdi, %r8
cmpq %rsi, %r9
cmovg %rsi, %r9
leaq .string_const1(%rip), %rdi
movl $0, %esi
movl $0, %eax
call printf@PLT
imulq %r8, %rsi
addq %rdi, %r8
addq %r12, %rsi
cmpq %r13, %r14
cmovg %r13, %r14
leaq .string_const2(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
cmpq %rsi, %rdi
cmovg %rsi, %rdi
imulq %r8, %r11
addq %r8, %r8
addq %r9, %rsi
leaq .string_const3(%rip), %rdi
movl $10, %esi
movl $0, %eax
call printf@PLT
leave
ret
