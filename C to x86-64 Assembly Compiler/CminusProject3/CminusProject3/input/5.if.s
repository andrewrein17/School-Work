	.section	.rodata
	.comm _gp, 8, 4
	.string_const0: .string "enter a:"
	.string_const1: .string "%d"
	.string_const2: .string "enter b:"
	.string_const3: .string "a = %d\n"
	.string_const4: .string "b = %d\n"
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	leaq .string_const0(%rip), %rdi
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	leaq .string_const1(%rip), %rdi
	movq %rbx, %rsi
	movl $0, %eax
	call scanf@PLT
	leaq .string_const2(%rip), %rdi
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	leaq .string_const1(%rip), %rdi
	movq %rbx, %rsi
	movl $0, %eax
	call scanf@PLT
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl (%rbx), %r8d
	cmpl %r8d, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovg %ebx, %ecx
	movl $-1, %ebx
	testl %ebx, %ecx
	je .L1
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl (%rbx), %r8d
	movl $0, %ebx
	cmpl %ebx, %r8d
	movl $0, %r8d
	movl $1, %ebx
	cmovg %ebx, %r8d
	movl $-1, %ebx
	testl %ebx, %r8d
	je .L1
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl (%rbx), %r9d
	leaq .string_const3(%rip), %rdi
	movl %r9d, %esi
	movl $0, %eax
	call printf@PLT
	jmp .L2
	.L1: nop
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %r9d
	leaq .string_const4(%rip), %rdi
	movl %r9d, %esi
	movl $0, %eax
	call printf@PLT
	.L2: nop
	jmp .L4
	.L3: nop
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl (%rbx), %r9d
	movl $0, %ebx
	cmpl %ebx, %r9d
	movl $0, %r9d
	movl $1, %ebx
	cmovl %ebx, %r9d
	movl $-1, %ebx
	testl %ebx, %r9d
	je .L3
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl (%rbx), %r10d
	leaq .string_const3(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	jmp .L4
	.L3: nop
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %r10d
	leaq .string_const4(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	.L4: nop
	.L6: nop
	leave
	ret
