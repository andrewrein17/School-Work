	.section	.rodata
	.comm _gp, 12, 4
	.string_const0: .string "enter a:"
	.string_const1: .string "%d"
	.string_const2: .string "1+2+...+min(100, a)=%d\n"
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
	addq $8, %rcx
	movl $0, %r8d
	movl %r8d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl $0, %r8d
	movl %r8d, (%rcx)
	.L2:
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl (%rcx), %r8d
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	movl (%rcx), %r9d
	cmpl %r9d, %r8d
	movl $0, %r8d
	movl $1, %edx
	cmovle %edx, %r8d
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl (%rcx), %r9d
	movl $100, %edx
	cmpl %edx, %r9d
	movl $0, %r9d
	movl $1, %edx
	cmovle %edx, %r9d
	testl %r8d, %r8d
	movl $1, %r8d
	movl $0, %edx
	cmove %edx, %r8d
	testl %r9d, %r9d
	movl $1, %r9d
	movl $0, %edx
	cmove %edx, %r9d
	andl %r9d, %r8d
	movl $-1, %edx
	testl %edx, %r8d
	je .L3
	leaq _gp(%rip), %rcx
	addq $8, %rcx
	leaq _gp(%rip), %rdx
	addq $8, %rdx
	movl (%rdx), %r10d
	leaq _gp(%rip), %rdx
	addq $4, %rdx
	movl (%rdx), %r11d
	addl %r11d, %r10d
	movl %r10d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	leaq _gp(%rip), %rdx
	addq $4, %rdx
	movl (%rdx), %r10d
	movl $1, %r9d
	addl %r9d, %r10d
	movl %r10d, (%rcx)
	jmp .L2
	.L3: nop
	leaq _gp(%rip), %rcx
	addq $8, %rcx
	movl (%rcx), %r9d
	leaq .string_const2(%rip), %rdi
	movl %r9d, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
