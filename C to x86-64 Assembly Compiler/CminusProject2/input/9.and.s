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
andq %rdi, %rsi
leaq .string_const0(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
andq %rdi, %rdi
leaq .string_const1(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
andq %r8, %rdi
leaq .string_const2(%rip), %rdi
movl $0, %esi
movl $0, %eax
call printf@PLT
andq %r8, %rsi
leaq .string_const3(%rip), %rdi
movl $0, %esi
movl $0, %eax
call printf@PLT
leave
ret
