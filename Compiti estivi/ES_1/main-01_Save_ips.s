	.file	"01_Save_ips.c"
	.text
	.globl	ip_conunt
	.data
	.align 4
ip_conunt:
	.long	1
	.section .rdata,"dr"
.LC0:
	.ascii "%d > \0"
.LC1:
	.ascii "%16s\0"
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
	movl	ip_conunt(%rip), %eax
	leaq	.LC0(%rip), %rcx
	movl	%eax, %edx
	call	printf
	movq	16(%rbp), %rax
	leaq	.LC1(%rip), %rcx
	movq	%rax, %rdx
	call	scanf
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC2:
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
	jne	.L4
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$1, %ecx
	call	exit
.L4:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC3:
	.ascii "r\0"
.LC4:
	.ascii "ip_list.txt\0"
.LC5:
	.ascii "Content of \"ip_list.txt\"\0"
.LC6:
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
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	leaq	.LC3(%rip), %rdx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	check_file
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	puts
	jmp	.L6
.L7:
	leaq	-32(%rbp), %rax
	leaq	.LC6(%rip), %rcx
	movq	%rax, %rdx
	call	printf
.L6:
	movq	-8(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %r8
	movl	$16, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	jne	.L7
	nop
	nop
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC7:
	.ascii "w\0"
	.align 8
.LC8:
	.ascii "- IPs saver by Francesco Fontanesi -\0"
	.align 8
.LC9:
	.ascii "\12All IPs are saved in \"ip_list.txt\"\0"
	.align 8
.LC10:
	.ascii "\12\12Insert IPs (type: \"fine\" to save and exit):\0"
.LC11:
	.ascii "fine\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	leaq	.LC7(%rip), %rdx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	check_file
	leaq	.LC8(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	.LC9(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	.LC10(%rip), %rax
	movq	%rax, %rcx
	call	puts
.L11:
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	prompt
	leaq	.LC11(%rip), %rdx
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	jne	.L9
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	call	file_print
	jmp	.L13
.L9:
	movq	-8(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	fputs
	movl	ip_conunt(%rip), %eax
	addl	$1, %eax
	movl	%eax, ip_conunt(%rip)
	jmp	.L11
.L13:
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (GNU) 15.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	exit;	.scl	2;	.type	32;	.endef
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	fgets;	.scl	2;	.type	32;	.endef
	.def	strcmp;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
	.def	fputs;	.scl	2;	.type	32;	.endef
