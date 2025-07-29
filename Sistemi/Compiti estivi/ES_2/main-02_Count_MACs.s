	.file	"02_Count_MACs.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "Error opening file\0"
	.text
	.globl	check_file
	.def	check_file;	.scl	2;	.type	32;	.endef
	.seh_proc	check_file
check_file:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	cmpq	$0, 16(%rbp)
	jne	.L3
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$1, %ecx
	call	exit
.L3:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "r\0"
.LC2:
	.ascii "mac_list.txt\0"
.LC3:
	.ascii "%s\0"
.LC4:
	.ascii "\12%d MAC Addresses found\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$80, %rsp
	.seh_stackalloc	80
	.seh_endprologue
	call	__main
	leaq	.LC1(%rip), %rdx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	check_file
	movl	$0, -4(%rbp)
	jmp	.L5
.L6:
	leaq	-48(%rbp), %rax
	leaq	.LC3(%rip), %rcx
	movq	%rax, %rdx
	call	printf
	addl	$1, -4(%rbp)
.L5:
	movq	-16(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %r8
	movl	$19, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	jne	.L6
	movl	-4(%rbp), %eax
	leaq	.LC4(%rip), %rcx
	movl	%eax, %edx
	call	printf
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movl	$0, %eax
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (GNU) 15.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	exit;	.scl	2;	.type	32;	.endef
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	fgets;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
