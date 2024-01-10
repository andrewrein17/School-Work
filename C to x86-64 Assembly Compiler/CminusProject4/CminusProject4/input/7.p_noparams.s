	.section	.rodata
	.comm _gp, 56, 4
	.string_const0: .string "a1()\n"
	.string_const1: .string "a2()\n"
	.string_const2: .string "a3()\n"
	.string_const3: .string "a4()\n"
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
	movl $0, %ebx
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
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	leaq _gp(%rip), %r8
	addq $16, %r8
	call a1
	movl %eax, %r8d
	movl %r8d, (%rcx)
	leaq .string_const1(%rip), %rdi
	call printf@PLT
	movl $0, %ecx
	movl %ecx, %eax
	addq $8, %rsp
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	leave
	ret
	.globl a3
	.type a3,@function
a3:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $400, %rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $8, %rsp
	leaq _gp(%rip), %r8
	addq $0, %r8
	leaq _gp(%rip), %r9
	addq $20, %r9
	call a1
	movl %eax, %r9d
	movl %r9d, (%r8)
	leaq _gp(%rip), %r8
	addq $4, %r8
	leaq _gp(%rip), %r9
	addq $24, %r9
	call a2
	movl %eax, %r9d
	movl %r9d, (%r8)
	leaq .string_const2(%rip), %rdi
	call printf@PLT
	movl $0, %r8d
	movl %r8d, %eax
	addq $8, %rsp
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	leave
	ret
	.globl a4
	.type a4,@function
a4:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $400, %rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $8, %rsp
	leaq _gp(%rip), %r9
	addq $0, %r9
	leaq _gp(%rip), %r10
	addq $28, %r10
	call a1
	movl %eax, %r10d
	movl %r10d, (%r9)
	leaq _gp(%rip), %r9
	addq $4, %r9
	leaq _gp(%rip), %r10
	addq $32, %r10
	call a2
	movl %eax, %r10d
	movl %r10d, (%r9)
	leaq _gp(%rip), %r9
	addq $8, %r9
	leaq _gp(%rip), %r10
	addq $36, %r10
	call a3
	movl %eax, %r10d
	movl %r10d, (%r9)
	leaq .string_const3(%rip), %rdi
	call printf@PLT
	movl $0, %r9d
	movl %r9d, %eax
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
	leaq _gp(%rip), %r10
	addq $0, %r10
	leaq _gp(%rip), %r11
	addq $40, %r11
	call a1
	movl %eax, %r11d
	movl %r11d, (%r10)
	leaq _gp(%rip), %r10
	addq $4, %r10
	leaq _gp(%rip), %r11
	addq $44, %r11
	call a2
	movl %eax, %r11d
	movl %r11d, (%r10)
	leaq _gp(%rip), %r10
	addq $8, %r10
	leaq _gp(%rip), %r11
	addq $48, %r11
	call a3
	movl %eax, %r11d
	movl %r11d, (%r10)
	leaq _gp(%rip), %r10
	addq $12, %r10
	leaq _gp(%rip), %r11
	addq $52, %r11
	call a4
	movl %eax, %r11d
	movl %r11d, (%r10)
	leave
	ret
