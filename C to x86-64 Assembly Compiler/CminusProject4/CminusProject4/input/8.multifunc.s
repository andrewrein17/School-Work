	.section	.rodata
	.comm _gp, 12, 4
	.string_const0: .string "a1\n"
	.string_const1: .string "a2\n"
	.string_const2: .string "return sum: %d\n"
	.text
	.globl a1
	.type a1,@function
a1:	nop
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
	movl $1, %ebx
	movl %ebx, %eax
	addq $8, %rsp
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	leave
	ret
	.globl a2
	.type a2,@function
a2:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $400, %rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $8, %rsp
	leaq .string_const1(%rip), %rdi
	call printf@PLT
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	call a1
	movl %eax, %ecx
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
	leaq _gp(%rip), %r8
	addq $4, %r8
	call a1
	movl %eax, %r8d
	leaq _gp(%rip), %r9
	addq $8, %r9
	call a2
	movl %eax, %r9d
	addl %r9d, %r8d
	leaq .string_const2(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
