	.section	.rodata
	.comm _gp, 44, 4
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
	leaq _gp(%rip), %rcx
	addq $40, %rcx
	movl $3, %r8d
	movl %r8d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $40, %rcx
	movl (%rcx), %r8d
	movl %r8d, %edx
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movslq %edx, %rdx
	imulq $4, %rdx
	addq %rdx, %rcx
	movl $7, %edx
	movl %edx, (%rcx)
	leaq _gp(%rip), %rcx
	addq $40, %rcx
	movl (%rcx), %r8d
	movl %r8d, %edx
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movslq %edx, %rdx
	imulq $4, %rdx
	addq %rdx, %rcx
	movl (%rcx), %edx
	leaq .string_const0(%rip), %rdi
	movl %edx, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %rcx
	addq $40, %rcx
	leaq _gp(%rip), %rbx
	addq $40, %rbx
	movl (%rbx), %r9d
	movl $2, %r8d
	addl %r8d, %r9d
	movl %r9d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $40, %rcx
	movl (%rcx), %r8d
	movl %r8d, %edx
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movslq %edx, %rdx
	imulq $4, %rdx
	addq %rdx, %rcx
	movl $22, %edx
	movl %edx, (%rcx)
	movl $5, %edx
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
