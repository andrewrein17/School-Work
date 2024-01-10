	.section	.rodata
	.comm _gp, 8, 4
	.string_const0: .string "%d\n"
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl $1, %r8d
	movl %r8d, (%rcx)
	.L2:
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl (%rcx), %r8d
	movl $10, %edx
	cmpl %edx, %r8d
	movl $0, %r8d
	movl $1, %edx
	cmovle %edx, %r8d
	movl $-1, %edx
	testl %edx, %r8d
	je .L3
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	movl $1, %r9d
	movl %r9d, (%rcx)
	.L4:
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	movl (%rcx), %r9d
	movl $10, %edx
	cmpl %edx, %r9d
	movl $0, %r9d
	movl $1, %edx
	cmovle %edx, %r9d
	movl $-1, %edx
	testl %edx, %r9d
	je .L5
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	movl (%rcx), %r10d
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl (%rcx), %r11d
	imull %r11d, %r10d
	leaq .string_const0(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	leaq _gp(%rip), %r8
	addq $0, %r8
	movl (%r8), %r11d
	movl $1, %r10d
	addl %r10d, %r11d
	movl %r11d, (%rcx)
	jmp .L4
	.L5: nop
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	leaq _gp(%rip), %r8
	addq $4, %r8
	movl (%r8), %r11d
	movl $1, %r10d
	addl %r10d, %r11d
	movl %r11d, (%rcx)
	jmp .L2
	.L3: nop
	leave
	ret
