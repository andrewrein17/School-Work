.section .rodata

.string_const0: .string "%d\n"
.string_const1: .string "%d\n"
.string_const2: .string "%d\n"
.string_const3: .string "%d\n"
.string_const4: .string "%d\n"
.string_const5: .string "%d\n"
.string_const6: .string "%d\n"
.string_const7: .string "%d\n"
.string_const8: .string "%d\n"
.string_const9: .string "%d\n"
.string_const10: .string "%d\n"
.text
.global main
.type main,@function
main: nop
pushq %rbp
movq %rsp, %rbp
notq %rsi
leaq .string_const0(%rip), %rdi
movl $0, %esi
movl $0, %eax
call printf@PLT
leaq .string_const1(%rip), %rdi
movl $0, %esi
movl $0, %eax
call printf@PLT
leaq .string_const2(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
leaq .string_const3(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
leaq .string_const4(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
leaq .string_const5(%rip), %rdi
movl $0, %esi
movl $0, %eax
call printf@PLT
leaq .string_const6(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
notq %rsi
leaq .string_const7(%rip), %rdi
movl $0, %esi
movl $0, %eax
call printf@PLT
orq %r8, %rsi
leaq .string_const8(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
andq %rsi, %rsi
leaq .string_const9(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
orq %r8, %rsi
andq %rsi, %rsi
leaq .string_const1(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
leave
ret
