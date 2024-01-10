	.section	.rodata
	.comm _gp, 404, 4
	.string_const0: .string "enter i = "
	.string_const1: .string "%d"
	.string_const2: .string "out of bound!\n"
	.string_const3: .string "%d\n"
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	leaq .string_const0(%rip), %rdi
	call printf@PLT
	leaq _gp(%rip), %rcx
	addq $400, %rcx
	leaq .string_const1(%rip), %rdi
	movq %rcx, %rsi
	movl $0, %eax
	call scanf@PLT
	leaq _gp(%rip), %rcx
	addq $400, %rcx
	movl (%rcx), %r9d
	movl $0, %r8d
	cmpl %r8d, %r9d
	movl $0, %r9d
	movl $1, %r8d
	cmovl %r8d, %r9d
	leaq _gp(%rip), %rcx
	addq $400, %rcx
	movl (%rcx), %r10d
	movl $100, %r8d
	cmpl %r8d, %r10d
	movl $0, %r10d
	movl $1, %r8d
	cmovge %r8d, %r10d
	orl %r10d, %r9d
	movl $1, %r8d
	cmovne %r8d, %r9d
	movl $-1, %r8d
	testl %r8d, %r9d
	je .L1
	leaq .string_const2(%rip), %rdi
	call printf@PLT
	jmp .L2
	.L1: nop
	leaq _gp(%rip), %rcx
	addq $400, %rcx
	movl (%rcx), %r10d
	movq %r10d, %rdx
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	imulq $4, %rdx
	addq %rdx, %rcx
	leaq _gp(%rip), %rcx
	addq $400, %rcx
	movl (%rcx), %r10d
	movl $2, %r8d
	imull %r8d, %r10d
	movl %r10d, (%rcx)
	movl $5, %r8d
	movq %r8d, %rdx
	leaq _gp(%rip), %rdx
	addq $4, %rdx
	imulq $4, %rdx
	addq %rdx, %rdx
	movl $5, %r8d
	movl %r8d, (%rdx)
	leaq _gp(%rip), %rcx
	addq $400, %rcx
	movl (%rcx), %r10d
	movq %r10d, %rdx
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	imulq $4, %rdx
	addq %rdx, %rcx
	movl (%rcx), %r8d
	leaq .string_const3(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	.L2: nop
	leave
	ret
