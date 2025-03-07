	.file	"terne_pitagoriche.c"
	.text
	.section	.rodata
.LC0:
	.string	"Terna pitagorica: %d, %d, %d\n"
	.text
	.globl	trovaTernePitagoriche
	.type	trovaTernePitagoriche, @function
trovaTernePitagoriche:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	$1, -12(%rbp)
	jmp	.L2
.L8:
	movl	-12(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L3
.L7:
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	.L4
.L6:
	movl	-12(%rbp), %eax
	imull	%eax, %eax
	movl	%eax, %edx
	movl	-8(%rbp), %eax
	imull	%eax, %eax
	addl	%eax, %edx
	movl	-4(%rbp), %eax
	imull	%eax, %eax
	cmpl	%eax, %edx
	jne	.L5
	movl	-4(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L5:
	addl	$1, -4(%rbp)
.L4:
	movl	-4(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jle	.L6
	addl	$1, -8(%rbp)
.L3:
	movl	-8(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jle	.L7
	addl	$1, -12(%rbp)
.L2:
	movl	-12(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jle	.L8
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	trovaTernePitagoriche, .-trovaTernePitagoriche
	.section	.rodata
.LC1:
	.string	"Inserisci un numero N: "
.LC2:
	.string	"%d"
	.align 8
.LC3:
	.string	"Non ci sono terne pitagoriche per N < 5."
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-12(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-12(%rbp), %eax
	cmpl	$4, %eax
	jg	.L10
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L11
.L10:
	movl	-12(%rbp), %eax
	movl	%eax, %edi
	call	trovaTernePitagoriche
.L11:
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L13
	call	__stack_chk_fail@PLT
.L13:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 14.2.1 20250207"
	.section	.note.GNU-stack,"",@progbits
