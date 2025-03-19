	.file	"main.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB22:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	leaq	a_matrix(%rip), %rbx
	leaq	b_matrix(%rip), %rbp
	leaq	4000000(%rbx), %r15
	movq	%rbp, %r14
	movq	%rbx, %r13
.L2:
	movl	$0, %r12d
.L3:
	call	rand@PLT
	movslq	%eax, %rdx
	imulq	$1759218605, %rdx, %rdx
	sarq	$43, %rdx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$5000, %edx, %edx
	subl	%edx, %eax
	addl	$1, %eax
	movl	%eax, 0(%r13,%r12)
	call	rand@PLT
	movslq	%eax, %rdx
	imulq	$1759218605, %rdx, %rdx
	sarq	$43, %rdx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$5000, %edx, %edx
	subl	%edx, %eax
	addl	$1, %eax
	movl	%eax, (%r14,%r12)
	addq	$4, %r12
	cmpq	$4000, %r12
	jne	.L3
	addq	$4000, %r13
	addq	$4000, %r14
	cmpq	%r15, %r13
	jne	.L2
	movl	$0, %r10d
	leaq	res(%rip), %r12
	leaq	4004000(%rbp), %r11
.L4:
	leaq	(%r10,%r12), %r8
	leaq	4000000(%rbp), %rdi
.L6:
	movq	%r8, %r9
	leaq	(%r10,%rbx), %rcx
	leaq	-4000000(%rdi), %rax
	movl	$0, %esi
	.p2align 5
.L5:
	movl	(%rcx), %edx
	imull	(%rax), %edx
	addl	%edx, %esi
	addq	$4, %rcx
	addq	$4000, %rax
	cmpq	%rdi, %rax
	jne	.L5
	movl	%esi, (%r9)
	addq	$4, %r8
	addq	$4, %rdi
	cmpq	%r11, %rdi
	jne	.L6
	addq	$4000, %r10
	cmpq	$4000000, %r10
	jne	.L4
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 56
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
