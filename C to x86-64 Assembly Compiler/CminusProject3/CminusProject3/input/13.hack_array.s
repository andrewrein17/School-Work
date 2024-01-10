	.section	.rodata
	.comm _gp, 64, 4
	.string_const0: .string "a[-3]=%d\n"
	.string_const1: .string "a[11]=%d\n"
	.string_const2: .string "n=%d\n"
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	movl $3, %r8d
	movl %r8d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl $4, %r8d
	movl %r8d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $8, %rcx
	movl $5, %r8d
	movl %r8d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $52, %rcx
	movl $13, %r8d
	movl %r8d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $56, %rcx
	movl $14, %r8d
	movl %r8d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $60, %rcx
	movl $15, %r8d
	movl %r8d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl $0, %r8d
	leaq _gp(%rip), %rdx
	addq $0, %rdx
	movl (%rdx), %r10d
	subl %r10d, %r8d
	movl %r8d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl (%rcx), %r8d
	movl %r8d, %edx
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movslq %edx, %rdx
	imulq $4, %rdx
	addq %rdx, %rcx
	movl (%rcx), %r8d
	leaq .string_const0(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	movl $11, %edx
	movl %edx, %edx
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movslq %edx, %rdx
	imulq $4, %rdx
	addq %rdx, %rbx
	movl (%rbx), %edx
	leaq .string_const1(%rip), %rdi
	movl %edx, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %rcx
	addq $60, %rcx
	movl (%rcx), %r8d
	leaq .string_const2(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	movl $12, %edx
	movl %edx, %edx
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movslq %edx, %rdx
	imulq $4, %rdx
	addq %rdx, %rbx
	movl $100, %edx
	movl %edx, (%rbx)
	leaq _gp(%rip), %rcx
	addq $60, %rcx
	movl (%rcx), %r8d
	leaq .string_const2(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
