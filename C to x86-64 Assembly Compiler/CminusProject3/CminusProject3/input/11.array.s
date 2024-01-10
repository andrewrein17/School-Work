	.section	.rodata
	.comm _gp, 40, 4
	.string_const0: .string "%d\n"
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	movl $3, %edx
	movl %edx, %edx
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movslq %edx, %rdx
	imulq $4, %rdx
	addq %rdx, %rbx
	movl $4, %edx
	movl %edx, (%rbx)
	movl $3, %edx
	movl %edx, %edx
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movslq %edx, %rdx
	imulq $4, %rdx
	addq %rdx, %rbx
	movl (%rbx), %edx
	leaq .string_const0(%rip), %rdi
	movl %edx, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
