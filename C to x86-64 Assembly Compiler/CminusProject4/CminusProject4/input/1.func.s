	.section	.rodata
	.comm _gp, 8, 4
	.string_const0: .string "inside function t\n"
	.string_const1: .string "%d\n"
	.text
	.globl t
	.type t,@function
t:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $400, %rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $8, %rsp
	leaq .string_const0(%rip), %rdi
	call printf@PLT
	movl $10, %ebx
	movl %ebx, %eax
	addq $8, %rsp
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	leave
	ret
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	leaq _gp(%rip), %r8
	addq $4, %r8
	call t
	movl %eax, %r8d
	movl %r8d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	movl (%rcx), %r8d
	leaq .string_const1(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
