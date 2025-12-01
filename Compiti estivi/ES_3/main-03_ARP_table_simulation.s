	.file	"03_ARP_table_simulation.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "a\0"
.LC1:
	.ascii "arp_table.txt\0"
	.align 8
.LC2:
	.ascii "- ARP Table simulator by Francesco Fontanesi -\0"
	.align 8
.LC3:
	.ascii "All IPs and MAC couples are saved in \"%s\"\12\0"
	.align 8
.LC4:
	.ascii "\12Insert IPs-MAC Couples (type: \"fine\" to save and exit):\0"
.LC5:
	.ascii "fine\0"
.LC6:
	.ascii "%s\12\0"
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
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	check_file
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC1(%rip), %rdx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	puts
.L4:
	leaq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	prompt
	leaq	.LC5(%rip), %rdx
	leaq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	jne	.L2
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	call	file_print
	jmp	.L6
.L2:
	leaq	-48(%rbp), %rcx
	leaq	.LC6(%rip), %rdx
	movq	-8(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	fprintf
	jmp	.L4
.L6:
	movl	$0, %eax
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC7:
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
	jne	.L9
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$1, %ecx
	call	exit
.L9:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC8:
	.ascii "\12> \0"
.LC9:
	.ascii "\12\0"
	.text
	.globl	prompt
	.def	prompt;	.scl	2;	.type	32;	.endef
	.seh_proc	prompt
prompt:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	.LC8(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	movq	%rdx, %r8
	movl	$34, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	je	.L12
	leaq	.LC9(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	strcspn
	movq	16(%rbp), %rdx
	addq	%rdx, %rax
	movb	$0, (%rax)
.L12:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC10:
	.ascii "r\0"
.LC11:
	.ascii "\12Content of \"%s\":\12\0"
.LC12:
	.ascii "%s\0"
	.text
	.globl	file_print
	.def	file_print;	.scl	2;	.type	32;	.endef
	.seh_proc	file_print
file_print:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$80, %rsp
	.seh_stackalloc	80
	.seh_endprologue
	leaq	.LC10(%rip), %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	check_file
	leaq	.LC1(%rip), %rdx
	leaq	.LC11(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L14
.L15:
	leaq	-48(%rbp), %rax
	leaq	.LC12(%rip), %rcx
	movq	%rax, %rdx
	call	printf
.L14:
	movq	-8(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %r8
	movl	$34, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	jne	.L15
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	nop
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (GNU) 15.1.0"
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	strcmp;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
	.def	fprintf;	.scl	2;	.type	32;	.endef
	.def	exit;	.scl	2;	.type	32;	.endef
	.def	fgets;	.scl	2;	.type	32;	.endef
	.def	strcspn;	.scl	2;	.type	32;	.endef
