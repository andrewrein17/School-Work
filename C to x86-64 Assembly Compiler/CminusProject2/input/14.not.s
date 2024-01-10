.section .rodata

.string_const0: .string "%d\n"
.string_const1: .string "%d\n"
.string_const2: .string "%d\n"
.string_const3: .string "%d\n"
.string_const4: .string "%d\n"
.text
.global main
.type main,@function
main: nop
pushq %rbp
movq %rsp, %rbp
leaq .string_const0(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
notq %rdx
leaq .string_const1(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
leaq .string_const2(%rip), %rdi
movl $0, %esi
movl $0, %eax
call printf@PLT
notq %rdx
leaq .string_const3(%rip), %rdi
movl $0, %esi
movl $0, %eax
call printf@PLT
notq %rdi
leaq .string_const4(%rip), %rdi
movl $0, %esi
movl $0, %eax
call printf@PLT
leave
ret
