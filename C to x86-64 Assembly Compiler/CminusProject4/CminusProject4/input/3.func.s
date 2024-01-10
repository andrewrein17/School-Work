	.section	.rodata
	.comm _gp, 16, 4
	.string_const0: .string "local a = %d\n"
	.string_const1: .string "global a+b = %d\n"
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
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	movl $2, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	movl (%rbx), %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	movl (%rbx), %ecx
	movl $1, %ebx
	addl %ebx, %ecx
	movl %ecx, %eax
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
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl $1, %r8d
	movl %r8d, (%rbx)
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	leaq _gp(%rip), %r8
	addq $12, %r8
	call t
	movl %eax, %r8d
	movl %r8d, (%rbx)
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl (%rbx), %r8d
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %r9d
	addl %r9d, %r8d
	leaq .string_const1(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
