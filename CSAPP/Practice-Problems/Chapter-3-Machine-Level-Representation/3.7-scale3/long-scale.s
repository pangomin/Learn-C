	.file	"long-scale.c"
	.text
	.globl	scale
	.type	scale, @function
scale:
.LFB0:
	.cfi_startproc
	leaq	(%rdi,%rsi,4), %rax
	leaq	(%rdx,%rdx,2), %rdx
	leaq	(%rax,%rdx,4), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	scale, .-scale
	.ident	"GCC: (GNU) 16.2.1 20260810"
	.section	.note.GNU-stack,"",@progbits
