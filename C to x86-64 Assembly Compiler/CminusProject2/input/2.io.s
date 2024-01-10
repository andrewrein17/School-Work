.section .rodata

.string_const0: .string "input an integer: "
.string_const1: .string "%d"
.string_const2: .string "you entered: %d\n"
.string_const3: .string "%d\n"
.string_const4: .string "%d\n"
.text
.global main
.type main,@function
main: nop
pushq %rbp
movq %rsp, %rbp
leaq .string_const0(%rip), %rdi
movl $0, %eax
call printf@PLT
leaq .string_const1(%rip), %rdi
movq %rax, %rsi
movl $0, %eax
call scanf@PLT
leaq .string_const2(%rip), %rdi
movl $0, %esi
movl $0, %eax
call printf@PLT
leaq .string_const3(%rip), %rdi
movl $1, %esi
movl $0, %eax
call printf@PLT
addq %rbx, %rcx
leaq .string_const4(%rip), %rdi
movl $3, %esi
movl $0, %eax
call printf@PLT
leave
ret
