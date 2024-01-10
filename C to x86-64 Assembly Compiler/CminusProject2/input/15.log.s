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
cmovne %rdi, %rsi
andq %rdi, %rdi
leaq .string_const0(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
cmpq %r9, %r10
cmovg %r9, %r10
leaq .string_const1(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
cmpq %r9, %r10
cmovg %r9, %r10
notq %rdi
leaq .string_const2(%rip), %rdi
movl $0, %esi
movl $0, %eax
call printf@PLT
cmpq %rdi, %rsi
cmove %rdi, %rsi
cmovne %rdi, %rsi
cmpq %r10, %r9
cmovne %r10, %r9
andq %rdi, %rdi
orq %r11, %rdi
leaq .string_const3(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
leave
ret
