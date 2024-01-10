	.section	.rodata
	.comm _gp, 12, 4
	.string_const0: .string "Enter an integer between 1 and 11:"
	.string_const1: .string "%d"
	.string_const2: .string "s=%d\n"
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	leaq .string_const0(%rip), %rdi
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	leaq .string_const1(%rip), %rdi
	movq %rbx, %rsi
	movl $0, %eax
	call scanf@PLT
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	movl (%rbx), %ecx
	movl $2, %ebx
	movl %ecx, %eax
	cdq
	idivl %ebx
	movl %eax, %ecx
	movl $2, %ebx
	imull %ebx, %ecx
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	movl (%rbx), %edx
	cmpl %edx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmove %ebx, %ecx
	movl $-1, %ebx
	testl %ebx, %ecx
	je .L1
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl $1, %edx
	movl %edx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl $0, %edx
	movl %edx, (%rbx)
	.L2:
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %edx
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	movl (%rbx), %r8d
	cmpl %r8d, %edx
	movl $0, %edx
	movl $1, %ebx
	cmovle %ebx, %edx
	movl $-1, %ebx
	testl %ebx, %edx
	je .L3
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	leaq _gp(%rip), %r8
	addq $0, %r8
	movl (%r8), %r9d
	leaq _gp(%rip), %r8
	addq $4, %r8
	movl (%r8), %r10d
	addl %r10d, %r9d
	movl %r9d, (%rbx)
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	leaq _gp(%rip), %r8
	addq $4, %r8
	movl (%r8), %r9d
	movl $1, %r8d
	addl %r8d, %r9d
	movl %r9d, (%rbx)
	jmp .L2
	.L3: nop
	jmp .L2
	.L1: nop
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl $1, %r8d
	movl %r8d, (%rbx)
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl $1, %r8d
	movl %r8d, (%rbx)
	.L2:
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %r8d
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	movl (%rbx), %r9d
	cmpl %r9d, %r8d
	movl $0, %r8d
	movl $1, %ebx
	cmovle %ebx, %r8d
	movl $-1, %ebx
	testl %ebx, %r8d
	je .L3
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	leaq _gp(%rip), %r9
	addq $0, %r9
	movl (%r9), %r10d
	leaq _gp(%rip), %r9
	addq $4, %r9
	movl (%r9), %r11d
	imull %r11d, %r10d
	movl %r10d, (%rbx)
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	leaq _gp(%rip), %r9
	addq $4, %r9
	movl (%r9), %r10d
	movl $1, %r9d
	addl %r9d, %r10d
	movl %r10d, (%rbx)
	jmp .L2
	.L3: nop
	.L2: nop
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl (%rbx), %r9d
	leaq .string_const2(%rip), %rdi
	movl %r9d, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
