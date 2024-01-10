.section .rodata

.string_const0: .string "51/17 = %d\n"
.string_const1: .string "100/2/5 is %d\n"
.text
.global main
.type main,@function
main: nop
pushq %rbp
movq %rsp, %rbp
leaq .string_const0(%rip), %rdi
movl $3, %esi
movl $0, %eax
call printf@PLT
leaq .string_const1(%rip), %rdi
movl $10, %esi
movl $0, %eax
call printf@PLT
leave
ret
