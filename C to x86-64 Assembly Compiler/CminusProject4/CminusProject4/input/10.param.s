	.section	.rodata
	.comm _gp, 16, 4
	.string_const0: .string "%d\n"
	.text
	.globl b4
	.type b4,@function
b4:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $8, %rsp
	movl $4, %ebx
	leaq .string_const0(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $-1, %rbx
	movl (%rbx), %ecx
	movl $1, %ebx
	addl %ebx, %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $-1, %rbx
	movl (%rbx), %ecx
	movl $1, %ebx
	addl %ebx, %ecx
	movl %ecx, %eax
	addq $8, %rsp
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	leave
	ret
	.globl d2
	.type d2,@function
d2:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $8, %rsp
	leaq _gp(%rip), %rbx
	addq $-1, %rbx
	movl (%rbx), %r8d
	leaq .string_const-(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $-1, %rbx
	movl (%rbx), %r8d
	leaq .string_const-(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl (%r8), %r9d
	movl %r9d, (%rbx)
	leaq _gp(%rip), %rbx
	addq $-1, %rbx
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl (%r8), %r9d
	movl %r9d, (%rbx)
	leaq _gp(%rip), %rbx
	addq $-1, %rbx
	leaq _gp(%rip), %r8
	addq $0, %r8
	movl (%r8), %r9d
	movl %r9d, (%rbx)
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
	.globl d3
	.type d3,@function
d3:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $8, %rsp
	leaq _gp(%rip), %r8
	addq $-1, %r8
	leaq _gp(%rip), %r9
	addq $-1, %r9
	movl (%r9), %r10d
	movl $1, %r9d
	addl %r9d, %r10d
	movl %r10d, (%r8)
	leaq _gp(%rip), %r8
	addq $-1, %r8
	leaq _gp(%rip), %r9
	addq $-1, %r9
	movl (%r9), %r10d
	movl $2, %r9d
	addl %r9d, %r10d
	movl %r10d, (%r8)
	leaq _gp(%rip), %r8
	addq $-1, %r8
	leaq _gp(%rip), %r9
	addq $-1, %r9
	movl (%r9), %r10d
	movl $3, %r9d
	addl %r9d, %r10d
	movl %r10d, (%r8)
	leaq _gp(%rip), %r8
	addq $-1, %r8
	leaq _gp(%rip), %r9
	addq $-1, %r9
	movl (%r9), %r10d
	movl $4, %r9d
	addl %r9d, %r10d
	movl %r10d, (%r8)
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl (%r8), %r9d
	movl %r9d, %eax
	addq $8, %rsp
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	leave
	ret
	.globl d1
	.type d1,@function
d1:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $8, %rsp
	leaq _gp(%rip), %r8
	addq $-4, %r8
	leaq _gp(%rip), %r10
	addq $-1, %r10
	movl (%r10), %r11d
	movl $200, %r10d
	imull %r10d, %r11d
	movl %r11d, (%r8)
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl (%r8), %r10d
	leaq .string_const-(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-4, %r8
	movl (%r8), %r10d
	leaq .string_const-(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl (%r8), %r10d
	leaq .string_const-(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl (%r8), %r10d
	leaq .string_const-(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-8, %r8
	call d2
	movl %eax, %r8d
	leaq .string_const-(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl (%r8), %r10d
	leaq .string_const-(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-4, %r8
	movl (%r8), %r10d
	leaq .string_const-(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl (%r8), %r10d
	leaq .string_const-(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl (%r8), %r10d
	leaq .string_const-(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-12, %r8
	call d3
	movl %eax, %r8d
	leaq .string_const-(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl (%r8), %r10d
	leaq .string_const-(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-4, %r8
	movl (%r8), %r10d
	leaq .string_const-(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl (%r8), %r10d
	leaq .string_const-(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl (%r8), %r10d
	leaq .string_const-(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-4, %r8
	movl (%r8), %r10d
	movl %r10d, %eax
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
	addq $-1, %r8
	movl $1, %r11d
	movl %r11d, (%r8)
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl $2, %r11d
	movl %r11d, (%r8)
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl $3, %r11d
	movl %r11d, (%r8)
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl $4, %r11d
	movl %r11d, (%r8)
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl $2, %r11d
	movl %r11d, (%r8)
	leaq _gp(%rip), %r8
	addq $-16, %r8
	call b4
	movl %eax, %r8d
	leaq .string_const-(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-20, %r8
	call d1
	movl %eax, %r8d
	leaq .string_const-(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %r8
	addq $-1, %r8
	movl $1, %r11d
	movl %r11d, (%r8)
	leaq _gp(%rip), %r8
	addq $-24, %r8
	call b4
	movl %eax, %r8d
	leaq .string_const-(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
