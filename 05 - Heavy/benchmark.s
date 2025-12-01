	.file	"main.c"
	.text
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB22:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	xorl	%edi, %edi
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	leaq	b_matrix(%rip), %r13
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%r13, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	leaq	a_matrix(%rip), %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	leaq	4000000(%rbp), %r14
	movq	%rbp, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
.L2:
	xorl	%r15d, %r15d
.L3:
	call	rand@PLT
	movslq	%eax, %rdx
	movl	%eax, %ecx
	imulq	$1759218605, %rdx, %rdx
	sarl	$31, %ecx
	sarq	$43, %rdx
	subl	%ecx, %edx
	imull	$5000, %edx, %edx
	subl	%edx, %eax
	addl	$1, %eax
	movl	%eax, (%rbx,%r15)
	call	rand@PLT
	movslq	%eax, %rdx
	movl	%eax, %ecx
	imulq	$1759218605, %rdx, %rdx
	sarl	$31, %ecx
	sarq	$43, %rdx
	subl	%ecx, %edx
	imull	$5000, %edx, %edx
	subl	%edx, %eax
	addl	$1, %eax
	movl	%eax, (%r12,%r15)
	addq	$4, %r15
	cmpq	$4000, %r15
	jne	.L3
	addq	$4000, %rbx
	addq	$4000, %r12
	cmpq	%r14, %rbx
	jne	.L2
	leaq	res(%rip), %r10
	xorl	%r9d, %r9d
	leaq	4004000(%r13), %r8
	leaq	4000000+b_matrix(%rip), %r11
.L4:
	imulq	$4000, %r9, %rdi
	movq	%r11, %rcx
	movq	%r10, %rsi
	addq	%rbp, %rdi
.L6:
	leaq	-4000000(%rcx), %rax
	movq	%rdi, %rdx
	pxor	%xmm3, %xmm3
	.p2align 4
	.p2align 3
.L5:
	movd	(%rdx), %xmm4
	movdqa	(%rax), %xmm2
	addq	$4000, %rax
	addq	$4, %rdx
	pshufd	$0, %xmm4, %xmm0
	psrlq	$32, %xmm2
	movdqa	%xmm0, %xmm1
	pmuludq	-4000(%rax), %xmm1
	psrlq	$32, %xmm0
	pshufd	$8, %xmm1, %xmm1
	pmuludq	%xmm2, %xmm0
	pshufd	$8, %xmm0, %xmm0
	punpckldq	%xmm0, %xmm1
	paddd	%xmm1, %xmm3
	cmpq	%rcx, %rax
	jne	.L5
	leaq	16(%rax), %rcx
	movaps	%xmm3, (%rsi)
	addq	$16, %rsi
	cmpq	%r8, %rcx
	jne	.L6
	addq	$1, %r9
	addq	$4000, %r10
	cmpq	$1000, %r9
	jne	.L4
	addq	$8, %rsp
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE22:
	.size	main, .-main
	.globl	res
	.bss
	.align 32
	.type	res, @object
	.size	res, 4000000
res:
	.zero	4000000
	.globl	b_matrix
	.align 32
	.type	b_matrix, @object
	.size	b_matrix, 4000000
b_matrix:
	.zero	4000000
	.globl	a_matrix
	.align 32
	.type	a_matrix, @object
	.size	a_matrix, 4000000
a_matrix:
	.zero	4000000
	.ident	"GCC: (GNU) 14.2.1 20250207"
	.section	.note.GNU-stack,"",@progbits
