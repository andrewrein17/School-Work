.section .rodata

.string_const0: .string "i=1; j=2; k=3; l=4\n"
.string_const1: .string "i+j+k*l = %d\n"
.string_const2: .string "i+(l-i)/k+j = %d\n"
.text
.global main
.type main,@function
main: nop
pushq %rbp
movq %rsp, %rbp
leaq .string_const0(%rip), %rdi
movl $0, %eax
call printf@PLT
addq %rdi, %rsi
imulq %r8, %r9
addq %r8, %r10
leaq .string_const1(%rip), %rdi
movl $15, %esi
movl $0, %eax
call printf@PLT
subq %rdi, %r9
addq %rdi, %rdi
addq %rsi, %rsi
leaq .string_const2(%rip), %rdi
movl $4, %esi
movl $0, %eax
call printf@PLT
leave
ret
