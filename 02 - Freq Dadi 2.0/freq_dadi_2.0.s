	.file	"freq_dadi_2.0.c"
	.text
	.section	.rodata
.LC0:
	.string	"Dadi da lanciare: "
.LC1:
	.string	"%d"
.LC2:
	.string	"Facce per ogni dado: "
.LC3:
	.string	"Numero di lanci: "
.LC4:
	.string	"Faccia %d: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %rbx
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-60(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-56(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-56(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -40(%rbp)
	cltq
	leaq	0(,%rax,4), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %esi
	movl	$0, %edx
	divq	%rsi
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -32(%rbp)
	movl	$0, -52(%rbp)
	jmp	.L2
.L3:
	movq	-32(%rbp), %rax
	movl	-52(%rbp), %edx
	movslq	%edx, %rdx
	movl	$0, (%rax,%rdx,4)
	addl	$1, -52(%rbp)
.L2:
	movl	-56(%rbp), %eax
	cmpl	%eax, -52(%rbp)
	jle	.L3
	movl	$0, -52(%rbp)
	jmp	.L4
.L7:
	movl	$0, -48(%rbp)
	jmp	.L5
.L6:
	call	rand@PLT
	movl	-56(%rbp), %ecx
	cltd
	idivl	%ecx
	movl	%edx, %ecx
	movl	%ecx, %eax
	addl	$1, %eax
	movl	%eax, -44(%rbp)
	movq	-32(%rbp), %rax
	movl	-44(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	leal	1(%rax), %ecx
	movq	-32(%rbp), %rax
	movl	-44(%rbp), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -48(%rbp)
.L5:
	movl	-60(%rbp), %eax
	cmpl	%eax, -48(%rbp)
	jl	.L6
	addl	$1, -52(%rbp)
.L4:
	movl	-64(%rbp), %eax
	cmpl	%eax, -52(%rbp)
	jl	.L7
	movl	$1, -52(%rbp)
	jmp	.L8
.L9:
	movq	-32(%rbp), %rax
	movl	-52(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %edx
	movl	-52(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -52(%rbp)
.L8:
	movl	-56(%rbp), %eax
	cmpl	%eax, -52(%rbp)
	jle	.L9
	movq	%rbx, %rsp
	movl	$0, %eax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (GNU) 14.2.1 20250207"
	.section	.note.GNU-stack,"",@progbits
