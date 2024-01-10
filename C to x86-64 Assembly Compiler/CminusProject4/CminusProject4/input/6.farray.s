	.section	.rodata
	.comm _gp, 100, 4
	.string_const0: .string "the return value is %d\n"
	.string_const1: .string "result is %d\n"
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
	addq $48, %rbx
	movl $0, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $52, %rbx
	movl $1000, %ecx
	movl %ecx, (%rbx)
.L0:	nop
	leaq _gp(%rip), %rbx
	addq $48, %rbx
	movl (%rbx), %ecx
	movl $10, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovl %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L1
	leaq _gp(%rip), %rbx
	addq $48, %rbx
	movl (%rbx), %ecx
	leaq _gp(%rip), %rbx
	addq $56, %rbx
	movslq %ecx, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	leaq _gp(%rip), %rcx
	addq $48, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movslq %r8d, %r8
	imulq $4, %r8
	addq %r8, %rcx
	movl (%rcx), %r8d
	movl %r8d, (%rbx)
	leaq _gp(%rip), %rbx
	addq $52, %rbx
	leaq _gp(%rip), %rcx
	addq $52, %rcx
	movl (%rcx), %r8d
	leaq _gp(%rip), %rcx
	addq $48, %rcx
	movl (%rcx), %r9d
	leaq _gp(%rip), %rcx
	addq $56, %rcx
	movslq %r9d, %r9
	imulq $4, %r9
	addq %r9, %rcx
	movl (%rcx), %r9d
	subl %r9d, %r8d
	movl %r8d, (%rbx)
	leaq _gp(%rip), %rbx
	addq $48, %rbx
	leaq _gp(%rip), %rcx
	addq $48, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp .L0
.L1:	 nop
	movl $3, %ebx
	leaq _gp(%rip), %rcx
	addq $56, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl (%rcx), %ebx
	leaq _gp(%rip), %rcx
	addq $52, %rcx
	movl (%rcx), %r8d
	addl %r8d, %ebx
	leaq .string_const0(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	movl $3, %ebx
	leaq _gp(%rip), %rcx
	addq $56, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl (%rcx), %ebx
	leaq _gp(%rip), %rcx
	addq $52, %rcx
	movl (%rcx), %r8d
	addl %r8d, %ebx
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
	addq $96, %r8
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
