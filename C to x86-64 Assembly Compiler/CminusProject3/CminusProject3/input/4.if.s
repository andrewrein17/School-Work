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
	addq $0, %rcx
	movl $0, %r8d
	movl %r8d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl (%rbx), %r9d
	movl $2, %r8d
	subl %r8d, %r9d
	movl %r9d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	movl (%rcx), %r8d
	movl $-1, %edx
	testl %edx, %r8d
	je .L1
	movl $1, %edx
	leaq .string_const0(%rip), %rdi
	movl %edx, %esi
	movl $0, %eax
	call printf@PLT
	jmp .L2
	.L1: nop
	movl $0, %edx
	leaq .string_const0(%rip), %rdi
	movl %edx, %esi
	movl $0, %eax
	call printf@PLT
	.L2: nop
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl (%rcx), %r9d
	movl $-1, %edx
	testl %edx, %r9d
	je .L3
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	movl (%rcx), %r10d
	movl $-1, %edx
	testl %edx, %r10d
	je .L3
	movl $0, %edx
	leaq .string_const0(%rip), %rdi
	movl %edx, %esi
	movl $0, %eax
	call printf@PLT
	jmp .L4
	.L3: nop
	movl $1, %edx
	leaq .string_const0(%rip), %rdi
	movl %edx, %esi
	movl $0, %eax
	call printf@PLT
	.L4: nop
	jmp .L6
	.L5: nop
	movl $0, %edx
	leaq .string_const0(%rip), %rdi
	movl %edx, %esi
	movl $0, %eax
	call printf@PLT
	.L6: nop
	leave
	ret
