	.section	.rodata
	.comm _gp, 8, 4
	.string_const0: .string "enter a:"
	.string_const1: .string "%d"
	.string_const2: .string "absoulute valute is %d\n"
	.string_const3: .string "absoulute value is %d\n"
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
	movl $0, %edx
	cmpl %edx, %r8d
	movl $0, %r8d
	movl $1, %edx
	cmovge %edx, %r8d
	movl $-1, %edx
	testl %edx, %r8d
	je .L1
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	leaq _gp(%rip), %rdx
	addq $0, %rdx
	movl (%rdx), %r10d
	movl %r10d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl (%rcx), %r9d
	leaq .string_const2(%rip), %rdi
	movl %r9d, %esi
	movl $0, %eax
	call printf@PLT
	jmp .L2
	.L1: nop
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl $0, %r9d
	leaq _gp(%rip), %r8
	addq $0, %r8
	movl (%r8), %r11d
	subl %r11d, %r9d
	movl %r9d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl (%rcx), %r9d
	leaq .string_const3(%rip), %rdi
	movl %r9d, %esi
	movl $0, %eax
	call printf@PLT
	.L2: nop
	leave
	ret
