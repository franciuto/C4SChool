	.file	"mem_layout.c"
	.text
	.globl	msg1
	.data
	.align 8
	.type	msg1, @object
	.size	msg1, 12
msg1:
	.string	"Ciao Mondo!"
	.globl	msg2
	.bss
	.align 8
	.type	msg2, @object
	.size	msg2, 10
msg2:
	.zero	10
	.globl	g_init
	.data
	.align 4
	.type	g_init, @object
	.size	g_init, 4
g_init:
	.long	10
	.globl	g_uninit
	.bss
	.align 4
	.type	g_uninit, @object
	.size	g_uninit, 4
g_uninit:
	.zero	4
	.globl	g_const
	.section	.rodata
	.align 4
	.type	g_const, @object
	.size	g_const, 4
g_const:
	.long	42
	.text
	.globl	foo
	.type	foo, @function
foo:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, %eax
	movb	%al, -8(%rbp)
	movsbl	-8(%rbp), %eax
	imull	-4(%rbp), %eax
	movl	%eax, %edx
	movl	sta.0(%rip), %eax
	addl	%edx, %eax
	movl	%eax, sta.0(%rip)
	leaq	sta.0(%rip), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	foo, .-foo
	.section	.rodata
.LC0:
	.string	"Ciao Mondo!"
	.align 8
.LC1:
	.string	"Indirizzo di msg1         (string)            : %p\n"
	.align 8
.LC2:
	.string	"Indirizzo di msg2         (string)            : %p\n"
	.align 8
.LC3:
	.string	"Indirizzo di msg3         (string)            : %p\n"
	.align 8
.LC4:
	.string	"Indirizzo puntato da pstr (pString      )     : %p\n"
	.align 8
.LC5:
	.string	"Indirizzo di msg1         (      )            : %p\n"
	.align 8
.LC6:
	.string	"Indirizzo di msg2         (      )            : %p\n"
	.align 8
.LC7:
	.string	"Indirizzo di msg3         (      )            : %p\n"
	.align 8
.LC8:
	.string	"Indirizzo di pstr         (pString      )     : %p\n"
	.align 8
.LC9:
	.string	"Indirizzo di foo()        (code/text)         : %p\n"
	.align 8
.LC10:
	.string	"Indirizzo di sta          (static)            : %p\n"
	.align 8
.LC11:
	.string	"Indirizzo di g_init       (global init)       : %p\n"
	.align 8
.LC12:
	.string	"Indirizzo di g_uninit     (global uninit/BSS) : %p\n"
	.align 8
.LC13:
	.string	"Indirizzo di g_const      (global const)      : %p\n"
	.align 8
.LC14:
	.string	"Indirizzo di local        (stack)             : %p\n"
	.align 8
.LC15:
	.string	"Indirizzo di local_const  (stack const)       : %p\n"
	.align 8
.LC16:
	.string	"Indirizzo di dynamic      (heap)              : %p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$5, -48(%rbp)
	movl	$7, -44(%rbp)
	movl	$4, %edi
	call	malloc@PLT
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movl	$20, (%rax)
	leaq	.LC0(%rip), %rax
	movq	%rax, -40(%rbp)
	movabsq	$7957663868289902915, %rax
	movq	%rax, -20(%rbp)
	movl	$2191204, -12(%rbp)
	leaq	msg1(%rip), %rdx
	leaq	.LC1(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	msg2(%rip), %rdx
	leaq	.LC2(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-20(%rbp), %rax
	leaq	.LC3(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-40(%rbp), %rax
	leaq	.LC4(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	msg1(%rip), %rdx
	leaq	.LC5(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	msg2(%rip), %rdx
	leaq	.LC6(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-20(%rbp), %rax
	leaq	.LC7(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-40(%rbp), %rax
	leaq	.LC8(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	foo(%rip), %rdx
	leaq	.LC9(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$97, %esi
	movl	$10, %edi
	call	foo
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	g_init(%rip), %rdx
	leaq	.LC11(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	g_uninit(%rip), %rdx
	leaq	.LC12(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	g_const(%rip), %rdx
	leaq	.LC13(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-48(%rbp), %rax
	leaq	.LC14(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-44(%rbp), %rax
	leaq	.LC15(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-32(%rbp), %rax
	leaq	.LC16(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.local	sta.0
	.comm	sta.0,4,4
	.ident	"GCC: (GNU) 15.1.1 20250425"
	.section	.note.GNU-stack,"",@progbits
