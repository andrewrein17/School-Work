.section .rodata

.string_const0: .string "Your grader\n"
.string_const1: .string "will put "
.string_const2: .string "a random "
.string_const3: .string "string here\n"
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
movl $0, %eax
call printf@PLT
leaq .string_const2(%rip), %rdi
movl $0, %eax
call printf@PLT
leaq .string_const3(%rip), %rdi
movl $0, %eax
call printf@PLT
leave
ret
