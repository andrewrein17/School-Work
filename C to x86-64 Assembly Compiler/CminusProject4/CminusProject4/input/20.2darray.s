	.section	.rodata
	.comm _gp, 1604, 4
	.string_const0: .string "input a[3][5] = "
	.string_const1: .string "%d"
	.string_const2: .string "you input %d\n"
	.string_const3: .string "a[3][5]+return=%d\n"
	.text
	.globl local
	.type local,@function
local:	nop
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
	movl $3, %ebx
	movl $5, %ecx
	leaq _gp(%rip), %r8
	addq $800, %r8
	movslq %ebx, %rbx
	movq $20, %r9
	imulq %r9, %rbx
	movslq %ecx, %rcx
	addq %rcx, %rbx
	imulq $4, %rbx
	addq %rbx, %r8
	leaq .string_const1(%rip), %rdi
	movq %r8, %rsi
	movl $0, %eax
	call scanf@PLT
	movl $3, %ebx
	movl $5, %ecx
	leaq _gp(%rip), %r8
	addq $800, %r8
	movslq %ebx, %rbx
	movq $20, %r9
	imulq %r9, %rbx
	movslq %ecx, %rcx
	addq %rcx, %rbx
	imulq $4, %rbx
	addq %rbx, %r8
	movl (%r8), %ebx
	leaq .string_const2(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	movl $3, %ebx
	movl $5, %ecx
	leaq _gp(%rip), %r8
	addq $800, %r8
	movslq %ebx, %rbx
	movq $20, %r9
	imulq %r9, %rbx
	movslq %ecx, %rcx
	addq %rcx, %rbx
	imulq $4, %rbx
	addq %rbx, %r8
	movl (%r8), %ebx
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
	movl $3, %ecx
	movl $5, %r8d
	leaq _gp(%rip), %r9
	addq $0, %r9
	movslq %ecx, %rcx
	movq $20, %r10
	imulq %r10, %rcx
	movslq %r8d, %r8
	addq %r8, %rcx
	imulq $4, %rcx
	addq %rcx, %r9
	movl $10, %ecx
	movl %ecx, (%r9)
	movl $3, %ecx
	movl $5, %r8d
	leaq _gp(%rip), %r9
	addq $0, %r9
	movslq %ecx, %rcx
	movq $20, %r10
	imulq %r10, %rcx
	movslq %r8d, %r8
	addq %r8, %rcx
	imulq $4, %rcx
	addq %rcx, %r9
	movl (%r9), %ecx
	leaq _gp(%rip), %r8
	addq $1600, %r8
	call local
	movl %eax, %r8d
	addl %r8d, %ecx
	leaq .string_const3(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
