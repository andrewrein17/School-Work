	.section	.rodata
	.comm _gp, 4, 4
	.string_const0: .string "enter a:"
	.string_const1: .string "%d"
	.string_const2: .string "%d is not 0\n"
	.string_const3: .string "%d is 0\n"
	.string_const4: .string "complete\n"
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	leaq .string_const0(%rip), %rdi
	call printf@PLT
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	leaq .string_const1(%rip), %rdi
	movq %rcx, %rsi
	movl $0, %eax
	call scanf@PLT
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	movl (%rcx), %r8d
	movl $-1, %edx
	testl %edx, %r8d
	je .L1
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	movl (%rcx), %r9d
	leaq .string_const2(%rip), %rdi
	movl %r9d, %esi
	movl $0, %eax
	call printf@PLT
	jmp .L2
	.L1: nop
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	movl (%rcx), %r9d
	leaq .string_const3(%rip), %rdi
	movl %r9d, %esi
	movl $0, %eax
	call printf@PLT
	.L2: nop
	leaq .string_const4(%rip), %rdi
	call printf@PLT
	leave
	ret
