	.section	.rodata
	.comm _gp, 12, 4
	.string_const0: .string "%d\n"
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl $0, %ecx
	movl %ecx, (%rbx)
	.L2:
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl (%rbx), %ecx
	movl $50, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovl %ebx, %ecx
	movl $-1, %ebx
	testl %ebx, %ecx
	je .L3
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl $0, %r8d
	movl %r8d, (%rbx)
	.L4:
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %r8d
	movl $10, %ebx
	cmpl %ebx, %r8d
	movl $0, %r8d
	movl $1, %ebx
	cmovl %ebx, %r8d
	movl $-1, %ebx
	testl %ebx, %r8d
	je .L5
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl (%rbx), %r9d
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %r10d
	addl %r10d, %r9d
	leaq .string_const0(%rip), %rdi
	movl %r9d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	leaq _gp(%rip), %r9
	addq $4, %r9
	movl (%r9), %r10d
	movl $2, %r9d
	addl %r9d, %r10d
	movl %r10d, (%rbx)
	jmp .L4
	.L5: nop
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	movl $0, %r9d
	leaq _gp(%rip), %r10
	addq $4, %r10
	movl (%r10), %r11d
	subl %r11d, %r9d
	movl %r9d, (%rbx)
	.L4:
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	movl (%rbx), %r9d
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %r10d
	cmpl %r10d, %r9d
	movl $0, %r9d
	movl $1, %ebx
	cmovne %ebx, %r9d
	movl $-1, %ebx
	testl %ebx, %r9d
	je .L5
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	movl (%rbx), %r10d
	leaq .string_const0(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	leaq _gp(%rip), %r10
	addq $8, %r10
	movl (%r10), %r11d
	movl $1, %r10d
	addl %r10d, %r11d
	movl %r11d, (%rbx)
	jmp .L4
	.L5: nop
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	leaq _gp(%rip), %r10
	addq $0, %r10
	movl (%r10), %r11d
	movl $10, %r10d
	addl %r10d, %r11d
	movl %r11d, (%rbx)
	jmp .L2
	.L3: nop
	leave
	ret
