	.file	"def.c"
	.text
	.p2align 4
	.globl	smart_method
	.def	smart_method;	.scl	2;	.type	32;	.endef
	.seh_proc	smart_method
smart_method:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, %rsi
	movq	%rdx, %rbx
	call	clock
	movl	%eax, %edi
	xorl	%eax, %eax
	movw	%ax, (%rsi)
	cmpq	$3, %rbx
	jbe	.L2
	movl	$2, %edx
	movl	$4, %eax
	pxor	%xmm0, %xmm0
	.p2align 5
	.p2align 4
	.p2align 3
.L15:
	cmpb	$0, (%rsi,%rdx)
	jne	.L41
.L3:
	addq	$1, %rdx
	movq	%rdx, %rax
	imulq	%rdx, %rax
	cmpq	%rax, %rbx
	jnb	.L15
.L2:
	call	clock
	pxor	%xmm0, %xmm0
	subl	%edi, %eax
	cvtsi2sdl	%eax, %xmm0
	mulsd	.LC0(%rip), %xmm0
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.p2align 4,,10
	.p2align 3
.L41:
	cmpq	%rax, %rbx
	jb	.L3
	cmpq	$1, %rdx
	jne	.L5
	movq	%rbx, %r8
	subq	%rax, %r8
	cmpq	$6, %r8
	jbe	.L31
	cmpq	$-1, %rbx
	je	.L31
	leaq	1(%r8), %r9
	cmpq	$14, %r8
	jbe	.L16
	movq	%r9, %rcx
	leaq	(%rsi,%rax), %rdx
	andq	$-16, %rcx
	leaq	(%rcx,%rdx), %r10
	testb	$16, %cl
	je	.L8
	movups	%xmm0, (%rdx)
	addq	$16, %rdx
	cmpq	%r10, %rdx
	je	.L38
	.p2align 4
	.p2align 4
	.p2align 3
.L8:
	movups	%xmm0, (%rdx)
	addq	$32, %rdx
	movups	%xmm0, -16(%rdx)
	cmpq	%r10, %rdx
	jne	.L8
.L38:
	leaq	(%rcx,%rax), %rdx
	cmpq	%rcx, %r9
	je	.L13
	subq	%rcx, %r8
	leaq	1(%r8), %r9
	cmpq	$6, %r8
	jbe	.L10
.L7:
	addq	%rsi, %rcx
	movq	$0, (%rcx,%rax)
	movq	%r9, %rax
	andq	$-8, %rax
	addq	%rax, %rdx
	andl	$7, %r9d
	je	.L13
.L10:
	leaq	1(%rdx), %rax
	movb	$0, (%rsi,%rdx)
	cmpq	%rax, %rbx
	jb	.L13
	leaq	2(%rdx), %rax
	movb	$0, 1(%rsi,%rdx)
	cmpq	%rax, %rbx
	jb	.L13
	leaq	3(%rdx), %rax
	movb	$0, 2(%rsi,%rdx)
	cmpq	%rax, %rbx
	jb	.L13
	leaq	4(%rdx), %rax
	movb	$0, 3(%rsi,%rdx)
	cmpq	%rax, %rbx
	jb	.L13
	leaq	5(%rdx), %rax
	movb	$0, 4(%rsi,%rdx)
	cmpq	%rax, %rbx
	jb	.L13
	leaq	6(%rdx), %rax
	movb	$0, 5(%rsi,%rdx)
	cmpq	%rax, %rbx
	jb	.L13
	movb	$0, 6(%rsi,%rdx)
.L13:
	movl	$4, %eax
	movl	$2, %edx
	jmp	.L15
	.p2align 5
	.p2align 4,,10
	.p2align 3
.L5:
	movb	$0, (%rsi,%rax)
	addq	%rdx, %rax
	cmpq	%rax, %rbx
	jb	.L3
	movb	$0, (%rsi,%rax)
	addq	%rdx, %rax
	cmpq	%rax, %rbx
	jnb	.L5
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L31:
	movq	%rbx, %rdx
	movb	$0, (%rsi,%rax)
	subq	%rax, %rdx
	addq	$1, %rax
	andl	$1, %edx
	cmpq	%rax, %rbx
	jb	.L13
	testq	%rdx, %rdx
	je	.L12
	movb	$0, (%rsi,%rax)
	addq	$1, %rax
	cmpq	%rax, %rbx
	jb	.L13
	.p2align 5
	.p2align 4
	.p2align 3
.L12:
	movb	$0, (%rsi,%rax)
	movb	$0, 1(%rsi,%rax)
	addq	$2, %rax
	cmpq	%rax, %rbx
	jnb	.L12
	jmp	.L13
.L16:
	movq	%rax, %rdx
	xorl	%ecx, %ecx
	jmp	.L7
	.seh_endproc
	.p2align 4
	.globl	classic_method
	.def	classic_method;	.scl	2;	.type	32;	.endef
	.seh_proc	classic_method
classic_method:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rdx, %rsi
	movq	%rcx, %rbx
	call	clock
	movl	%eax, %edi
	leaq	-7(%rsi), %rax
	cmpq	$-9, %rax
	ja	.L60
	leaq	1(%rsi), %rcx
	cmpq	$14, %rsi
	jbe	.L61
	movq	%rcx, %rdx
	movq	%rbx, %rax
	pxor	%xmm0, %xmm0
	andq	$-16, %rdx
	leaq	(%rdx,%rbx), %r8
	testb	$16, %dl
	je	.L45
	leaq	16(%rbx), %rax
	movups	%xmm0, (%rbx)
	cmpq	%rax, %r8
	je	.L84
	.p2align 4
	.p2align 4
	.p2align 3
.L45:
	movups	%xmm0, (%rax)
	addq	$32, %rax
	movups	%xmm0, -16(%rax)
	cmpq	%rax, %r8
	jne	.L45
.L84:
	cmpq	%rcx, %rdx
	je	.L50
	movq	%rsi, %rax
	subq	%rdx, %rax
	leaq	1(%rax), %rcx
	cmpq	$6, %rax
	jbe	.L47
.L44:
	movq	%rcx, %rax
	movq	$0, (%rbx,%rdx)
	andq	$-8, %rax
	addq	%rax, %rdx
	andl	$7, %ecx
	je	.L50
.L47:
	leaq	1(%rdx), %rax
	movb	$0, (%rbx,%rdx)
	cmpq	%rax, %rsi
	jb	.L50
	leaq	2(%rdx), %rax
	movb	$0, 1(%rbx,%rdx)
	cmpq	%rax, %rsi
	jb	.L50
	leaq	3(%rdx), %rax
	movb	$0, 2(%rbx,%rdx)
	cmpq	%rax, %rsi
	jb	.L50
	leaq	4(%rdx), %rax
	movb	$0, 3(%rbx,%rdx)
	cmpq	%rax, %rsi
	jb	.L50
	leaq	5(%rdx), %rax
	movb	$0, 4(%rbx,%rdx)
	cmpq	%rax, %rsi
	jb	.L50
	leaq	6(%rdx), %rax
	movb	$0, 5(%rbx,%rdx)
	cmpq	%rax, %rsi
	jb	.L50
	movb	$0, 6(%rbx,%rdx)
.L50:
	movsd	.LC3(%rip), %xmm1
	movl	$2, %ecx
	jmp	.L58
	.p2align 5
	.p2align 4,,10
	.p2align 3
.L51:
	movb	%al, (%rbx,%rcx)
	addq	$1, %rcx
	cmpq	%rcx, %rsi
	jb	.L59
.L58:
	leaq	-2(%rcx), %rdx
	movl	$1, %eax
	cmpq	$1, %rdx
	jbe	.L51
	movq	%rcx, %rdx
	xorl	%eax, %eax
	andl	$1, %edx
	je	.L51
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rcx, %xmm0
	testq	%rcx, %rcx
	jns	.L53
	movq	%rcx, %rax
	pxor	%xmm0, %xmm0
	shrq	%rax
	orq	%rdx, %rax
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm0, %xmm0
.L53:
	sqrtsd	%xmm0, %xmm0
	comisd	%xmm1, %xmm0
	cvttsd2siq	%xmm0, %r9
	jb	.L55
	subsd	%xmm1, %xmm0
	cvttsd2siq	%xmm0, %r9
	btcq	$63, %r9
.L55:
	movl	$3, %r8d
	jmp	.L56
	.p2align 5
	.p2align 4,,10
	.p2align 3
.L57:
	movq	%rcx, %rax
	xorl	%edx, %edx
	divq	%r8
	testq	%rdx, %rdx
	je	.L64
	addq	$2, %r8
.L56:
	cmpq	%r8, %r9
	jnb	.L57
	movl	$1, %eax
	movb	%al, (%rbx,%rcx)
	addq	$1, %rcx
	cmpq	%rcx, %rsi
	jnb	.L58
.L59:
	call	clock
	pxor	%xmm0, %xmm0
	subl	%edi, %eax
	cvtsi2sdl	%eax, %xmm0
	mulsd	.LC0(%rip), %xmm0
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.p2align 4,,10
	.p2align 3
.L64:
	xorl	%eax, %eax
	jmp	.L51
.L60:
	movq	%rsi, %rdx
	movb	$0, (%rbx)
	movl	$1, %eax
	andl	$1, %edx
	cmpq	$1, %rsi
	jb	.L59
	testq	%rdx, %rdx
	je	.L43
	movb	$0, 1(%rbx)
	movl	$2, %eax
	cmpq	$2, %rsi
	jb	.L85
	.p2align 5
	.p2align 4
	.p2align 3
.L43:
	movb	$0, (%rbx,%rax)
	movb	$0, 1(%rbx,%rax)
	addq	$2, %rax
	cmpq	%rax, %rsi
	jnb	.L43
.L85:
	cmpq	$1, %rsi
	jbe	.L59
	jmp	.L50
.L61:
	xorl	%edx, %edx
	jmp	.L44
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC4:
	.ascii "Quanti numeri primi vuoi calcolare: \0"
.LC5:
	.ascii "%llu\0"
.LC6:
	.ascii "Errore allocazione di memoria\0"
.LC9:
	.ascii "------- ERASTOTENE -------\0"
	.align 8
.LC10:
	.ascii "Tempo impiegato da erastotene: %f\12\0"
	.align 8
.LC11:
	.ascii "Numeri primi trovati da eratostene: %llu\12\12\0"
	.align 8
.LC12:
	.ascii "------- METODO CLASSICO -------\0"
	.align 8
.LC13:
	.ascii "Tempo impiegato nel metodo classico %f\12\0"
	.align 8
.LC14:
	.ascii "Numeri primi trovati con il metodo classico: %d\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	call	__main
	leaq	.LC4(%rip), %rcx
	call	printf
	leaq	40(%rsp), %rdx
	leaq	.LC5(%rip), %rcx
	call	scanf
	movl	$10, %ecx
	call	putchar
	movq	40(%rsp), %rsi
	leaq	1(%rsi), %rbp
	movq	%rbp, %rcx
	call	malloc
	movq	%rbp, %rcx
	movq	%rax, %rbx
	call	malloc
	movq	%rax, %rdi
	testq	%rbx, %rbx
	je	.L107
	leaq	-7(%rsi), %rax
	cmpq	$-9, %rax
	ja	.L98
	cmpq	$14, %rsi
	jbe	.L99
	movq	%rbp, %rdx
	movl	$16843009, %ecx
	xorl	%eax, %eax
	movd	%ecx, %xmm0
	andq	$-16, %rdx
	pshufd	$0, %xmm0, %xmm0
	.p2align 5
	.p2align 4
	.p2align 3
.L91:
	movups	%xmm0, (%rbx,%rax)
	movups	%xmm0, (%rdi,%rax)
	addq	$16, %rax
	cmpq	%rdx, %rax
	jne	.L91
	cmpq	%rdx, %rbp
	je	.L95
	movq	%rsi, %rax
	subq	%rdx, %rax
	leaq	1(%rax), %rbp
	cmpq	$6, %rax
	jbe	.L93
.L90:
	movq	.LC8(%rip), %rax
	movq	%rax, (%rbx,%rdx)
	movq	%rax, (%rdi,%rdx)
	movq	%rbp, %rax
	andq	$-8, %rax
	addq	%rax, %rdx
	andl	$7, %ebp
	je	.L95
.L93:
	leaq	1(%rdx), %rax
	movb	$1, (%rbx,%rdx)
	movb	$1, (%rdi,%rdx)
	cmpq	%rax, %rsi
	jb	.L95
	leaq	2(%rdx), %rax
	movb	$1, 1(%rbx,%rdx)
	movb	$1, 1(%rdi,%rdx)
	cmpq	%rax, %rsi
	jb	.L95
	leaq	3(%rdx), %rax
	movb	$1, 2(%rbx,%rdx)
	movb	$1, 2(%rdi,%rdx)
	cmpq	%rax, %rsi
	jb	.L95
	leaq	4(%rdx), %rax
	movb	$1, 3(%rbx,%rdx)
	movb	$1, 3(%rdi,%rdx)
	cmpq	%rax, %rsi
	jb	.L95
	leaq	5(%rdx), %rax
	movb	$1, 4(%rbx,%rdx)
	movb	$1, 4(%rdi,%rdx)
	cmpq	%rax, %rsi
	jb	.L95
	leaq	6(%rdx), %rax
	movb	$1, 5(%rbx,%rdx)
	cmpq	%rax, %rsi
	jb	.L95
	movb	$1, 6(%rbx,%rdx)
.L95:
	leaq	.LC9(%rip), %rcx
	xorl	%esi, %esi
	call	puts
	movq	40(%rsp), %rdx
	movq	%rbx, %rcx
	call	smart_method
	leaq	.LC10(%rip), %rcx
	movq	%xmm0, %rdx
	movapd	%xmm0, %xmm1
	call	printf
	movq	40(%rsp), %rcx
	cmpq	$1, %rcx
	jbe	.L96
	movl	$2, %eax
	.p2align 4
	.p2align 4
	.p2align 3
.L97:
	movzbl	(%rbx,%rax), %edx
	addq	$1, %rax
	addq	%rdx, %rsi
	cmpq	%rax, %rcx
	jnb	.L97
.L96:
	movq	%rsi, %rdx
	leaq	.LC11(%rip), %rcx
	call	printf
	leaq	.LC12(%rip), %rcx
	call	puts
	movq	40(%rsp), %rdx
	movq	%rdi, %rcx
	call	classic_method
	leaq	.LC13(%rip), %rcx
	movq	%xmm0, %rdx
	movapd	%xmm0, %xmm1
	call	printf
	movq	%rsi, %rdx
	leaq	.LC14(%rip), %rcx
	call	printf
	movq	%rbx, %rcx
	call	free
	movq	%rdi, %rcx
	call	free
	xorl	%eax, %eax
.L86:
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
.L98:
	xorl	%eax, %eax
	.p2align 5
	.p2align 4
	.p2align 3
.L89:
	movb	$1, (%rbx,%rax)
	movb	$1, (%rdi,%rax)
	addq	$1, %rax
	cmpq	%rax, %rsi
	jnb	.L89
	jmp	.L95
.L99:
	xorl	%edx, %edx
	jmp	.L90
.L107:
	leaq	.LC6(%rip), %rcx
	call	printf
	movl	$1, %eax
	jmp	.L86
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC0:
	.long	-755914244
	.long	1062232653
	.align 8
.LC3:
	.long	0
	.long	1138753536
	.align 8
.LC8:
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.byte	1
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (GNU) 14.2.0"
	.def	clock;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
