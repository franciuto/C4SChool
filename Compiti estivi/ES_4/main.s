	.file	"main.c"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
.L2:
	call	menu
	jmp	.L2
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "1. Add a question\12"
	.ascii "2. Delete question\12"
	.ascii "3. Answer the questionnaire\12"
	.ascii "4. Exit\0"
.LC1:
	.ascii "Choose an option: \0"
.LC2:
	.ascii " %c\0"
.LC3:
	.ascii "\12\12Your final score is %d\12\12\0"
	.align 8
.LC4:
	.ascii "\12Invalid choice, please try again\0"
	.text
	.globl	menu
	.def	menu;	.scl	2;	.type	32;	.endef
	.seh_proc	menu
menu:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-1(%rbp), %rax
	leaq	.LC2(%rip), %rcx
	movq	%rax, %rdx
	call	scanf
	nop
.L4:
	call	getchar
	cmpl	$10, %eax
	jne	.L4
	movzbl	-1(%rbp), %eax
	movsbl	%al, %eax
	cmpl	$52, %eax
	je	.L5
	cmpl	$52, %eax
	jg	.L6
	cmpl	$51, %eax
	je	.L7
	cmpl	$51, %eax
	jg	.L6
	cmpl	$49, %eax
	je	.L8
	cmpl	$50, %eax
	je	.L9
	jmp	.L6
.L8:
	call	add_question
	jmp	.L10
.L9:
	call	delete_question
	jmp	.L10
.L7:
	call	give_questionnaire
	movl	%eax, %edx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L10
.L5:
	movl	$0, %ecx
	call	exit
.L6:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	puts
	nop
.L10:
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC5:
	.ascii "a\0"
.LC6:
	.ascii "questionario.txt\0"
	.align 8
.LC7:
	.ascii "\12Insert the question (%d letters max): \0"
	.align 8
.LC8:
	.ascii "Insert answer %c (%d letters max): \0"
.LC9:
	.ascii "%c. %s\0"
	.align 8
.LC10:
	.ascii "\12Insert correct answer for this question: \0"
.LC11:
	.ascii "%c\12\12\0"
	.text
	.globl	add_question
	.def	add_question;	.scl	2;	.type	32;	.endef
	.seh_proc	add_question
add_question:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$160, %rsp
	.seh_stackalloc	160
	.seh_endprologue
	leaq	.LC5(%rip), %rdx
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	check_file
	movl	$1, %edx
	movl	$500, %ecx
	call	calloc
	movq	%rax, -24(%rbp)
	leaq	.LC7(%rip), %rax
	movl	$500, %edx
	movq	%rax, %rcx
	call	printf
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %r8
	movl	$500, %edx
	movq	%rax, %rcx
	call	fgets
	movq	-16(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	fputs
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movb	$65, -1(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L12
.L13:
	movq	$0, -128(%rbp)
	movq	$0, -120(%rbp)
	movq	$0, -112(%rbp)
	movq	$0, -104(%rbp)
	movq	$0, -96(%rbp)
	movq	$0, -88(%rbp)
	movq	$0, -80(%rbp)
	movq	$0, -72(%rbp)
	movq	$0, -64(%rbp)
	movq	$0, -56(%rbp)
	movq	$0, -48(%rbp)
	movq	$0, -40(%rbp)
	movl	$0, -32(%rbp)
	movsbl	-1(%rbp), %eax
	leaq	.LC8(%rip), %rcx
	movl	$100, %r8d
	movl	%eax, %edx
	call	printf
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rdx
	leaq	-128(%rbp), %rax
	movq	%rdx, %r8
	movl	$100, %edx
	movq	%rax, %rcx
	call	fgets
	movsbl	-1(%rbp), %ecx
	leaq	-128(%rbp), %r8
	leaq	.LC9(%rip), %rdx
	movq	-16(%rbp), %rax
	movq	%r8, %r9
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	fprintf
	movzbl	-1(%rbp), %eax
	addl	$1, %eax
	movb	%al, -1(%rbp)
	addl	$1, -8(%rbp)
.L12:
	cmpl	$3, -8(%rbp)
	jle	.L13
	leaq	.LC10(%rip), %rax
	movq	%rax, %rcx
	call	printf
	call	getchar
	andl	$95, %eax
	movb	%al, -25(%rbp)
	nop
.L14:
	call	getchar
	cmpl	$10, %eax
	jne	.L14
	movsbl	-25(%rbp), %ecx
	leaq	.LC11(%rip), %rdx
	movq	-16(%rbp), %rax
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	fprintf
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	nop
	addq	$160, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC12:
	.ascii "r\0"
.LC13:
	.ascii "%d. %s...\12\0"
.LC14:
	.ascii "%d. %s\12\0"
	.align 8
.LC15:
	.ascii "Enter the number of question to delete (1-%d): \0"
.LC16:
	.ascii "Question does not exist!\0"
.LC17:
	.ascii "w\0"
.LC18:
	.ascii "temp.txt\0"
	.text
	.globl	delete_question
	.def	delete_question;	.scl	2;	.type	32;	.endef
	.seh_proc	delete_question
delete_question:
	pushq	%rbp
	.seh_pushreg	%rbp
	subq	$1200, %rsp
	.seh_stackalloc	1200
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	leaq	.LC12(%rip), %rdx
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, 1040(%rbp)
	movq	1040(%rbp), %rax
	movq	%rax, %rcx
	call	check_file
	movl	$1, 1068(%rbp)
	jmp	.L17
.L24:
	leaq	512(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	cmpq	$50, %rax
	jbe	.L18
	leaq	512(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movl	$50, %r8d
	movq	%rax, %rcx
	call	strncpy
	movb	$0, -46(%rbp)
	leaq	-96(%rbp), %rdx
	movl	1068(%rbp), %eax
	leaq	.LC13(%rip), %rcx
	movq	%rdx, %r8
	movl	%eax, %edx
	call	printf
	jmp	.L19
.L18:
	leaq	512(%rbp), %rdx
	movl	1068(%rbp), %eax
	leaq	.LC14(%rip), %rcx
	movq	%rdx, %r8
	movl	%eax, %edx
	call	printf
.L19:
	movl	$0, 1064(%rbp)
	jmp	.L20
.L23:
	movq	1040(%rbp), %rdx
	leaq	512(%rbp), %rax
	movq	%rdx, %r8
	movl	$500, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	je	.L42
	addl	$1, 1064(%rbp)
.L20:
	cmpl	$4, 1064(%rbp)
	jle	.L23
	jmp	.L22
.L42:
	nop
.L22:
	addl	$1, 1068(%rbp)
.L17:
	movq	1040(%rbp), %rdx
	leaq	512(%rbp), %rax
	movq	%rdx, %r8
	movl	$500, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	jne	.L24
	movl	$0, 1036(%rbp)
	movl	1068(%rbp), %eax
	leal	-1(%rax), %edx
	leaq	.LC15(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rdx
	leaq	480(%rbp), %rax
	movq	%rdx, %r8
	movl	$32, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	jne	.L25
	leaq	.LC16(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movq	1040(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	jmp	.L16
.L25:
	leaq	480(%rbp), %rax
	movl	$10, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	call	strtol
	movl	%eax, 1036(%rbp)
	cmpl	$0, 1036(%rbp)
	jle	.L27
	movl	1068(%rbp), %eax
	cmpl	1036(%rbp), %eax
	jg	.L28
.L27:
	leaq	.LC16(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movq	1040(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	jmp	.L16
.L28:
	leaq	.LC17(%rip), %rdx
	leaq	.LC18(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, 1024(%rbp)
	movq	1024(%rbp), %rax
	movq	%rax, %rcx
	call	check_file
	movq	1040(%rbp), %rax
	movq	%rax, %rcx
	call	rewind
	movl	$1, 1060(%rbp)
	jmp	.L29
.L40:
	movl	1060(%rbp), %eax
	cmpl	1036(%rbp), %eax
	jne	.L30
	movl	$0, 1056(%rbp)
	jmp	.L31
.L34:
	movq	1040(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %r8
	movl	$500, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	je	.L43
	addl	$1, 1056(%rbp)
.L31:
	cmpl	$4, 1056(%rbp)
	jle	.L34
	jmp	.L35
.L30:
	movq	1024(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	fputs
	movl	$0, 1052(%rbp)
	jmp	.L36
.L39:
	movq	1040(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %r8
	movl	$500, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	je	.L44
	movq	1024(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	fputs
	addl	$1, 1052(%rbp)
.L36:
	cmpl	$4, 1052(%rbp)
	jle	.L39
	jmp	.L35
.L43:
	nop
	jmp	.L35
.L44:
	nop
.L35:
	addl	$1, 1060(%rbp)
.L29:
	movq	1040(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %r8
	movl	$500, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	jne	.L40
	movq	1040(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movq	1024(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	remove
	leaq	.LC6(%rip), %rdx
	leaq	.LC18(%rip), %rax
	movq	%rax, %rcx
	call	rename
	nop
.L16:
	addq	$1200, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC19:
	.ascii "Question n.%d: %s\0"
.LC20:
	.ascii "%s\0"
.LC21:
	.ascii "Your answer (A,B,C,D): \0"
.LC22:
	.ascii "Correct! Your score is %d\12\12\0"
.LC23:
	.ascii "Wrong!\12\0"
	.text
	.globl	give_questionnaire
	.def	give_questionnaire;	.scl	2;	.type	32;	.endef
	.seh_proc	give_questionnaire
give_questionnaire:
	pushq	%rbp
	.seh_pushreg	%rbp
	subq	$576, %rsp
	.seh_stackalloc	576
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	leaq	.LC12(%rip), %rdx
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, 424(%rbp)
	movq	424(%rbp), %rax
	movq	%rax, %rcx
	call	check_file
	movl	$1, 444(%rbp)
	movl	$0, 440(%rbp)
	jmp	.L46
.L51:
	leaq	-80(%rbp), %rdx
	movl	444(%rbp), %eax
	leaq	.LC19(%rip), %rcx
	movq	%rdx, %r8
	movl	%eax, %edx
	call	printf
	movl	$0, 436(%rbp)
	jmp	.L47
.L48:
	movq	424(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %r8
	movl	$100, %edx
	movq	%rax, %rcx
	call	fgets
	leaq	-80(%rbp), %rax
	leaq	.LC20(%rip), %rcx
	movq	%rax, %rdx
	call	printf
	addl	$1, 436(%rbp)
.L47:
	cmpl	$3, 436(%rbp)
	jle	.L48
	leaq	.LC21(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-81(%rbp), %rax
	leaq	.LC2(%rip), %rcx
	movq	%rax, %rdx
	call	scanf
	movzbl	-81(%rbp), %eax
	andl	$95, %eax
	movb	%al, -81(%rbp)
	movq	424(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %r8
	movl	$100, %edx
	movq	%rax, %rcx
	call	fgets
	movzbl	-80(%rbp), %edx
	movzbl	-81(%rbp), %eax
	cmpb	%al, %dl
	jne	.L49
	addl	$1, 440(%rbp)
	movl	440(%rbp), %eax
	leaq	.LC22(%rip), %rcx
	movl	%eax, %edx
	call	printf
	jmp	.L50
.L49:
	leaq	.LC23(%rip), %rax
	movq	%rax, %rcx
	call	puts
.L50:
	movq	424(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %r8
	movl	$100, %edx
	movq	%rax, %rcx
	call	fgets
	addl	$1, 444(%rbp)
.L46:
	movq	424(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %r8
	movl	$500, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	jne	.L51
	movq	424(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movl	440(%rbp), %eax
	addq	$576, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC24:
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
	jne	.L55
	leaq	.LC24(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$1, %ecx
	call	exit
.L55:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (GNU) 15.1.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	getchar;	.scl	2;	.type	32;	.endef
	.def	exit;	.scl	2;	.type	32;	.endef
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	calloc;	.scl	2;	.type	32;	.endef
	.def	fgets;	.scl	2;	.type	32;	.endef
	.def	fputs;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.def	fprintf;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	strncpy;	.scl	2;	.type	32;	.endef
	.def	strtol;	.scl	2;	.type	32;	.endef
	.def	rewind;	.scl	2;	.type	32;	.endef
	.def	fputs;	.scl	2;	.type	32;	.endef
	.def	remove;	.scl	2;	.type	32;	.endef
	.def	rename;	.scl	2;	.type	32;	.endef
