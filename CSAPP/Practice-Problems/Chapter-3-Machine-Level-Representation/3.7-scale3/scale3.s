	.file	"scale3.c"
	.text
	.globl	scale3
	.type	scale3, @function
scale3:
.LFB0:
	.cfi_startproc
	addl	$10, %edi
	imull	%esi, %edi
	leal	(%rdi,%rdx), %eax
	ret
	.cfi_endproc
.LFE0:
	.size	scale3, .-scale3
	.ident	"GCC: (GNU) 16.2.1 20260810"
	.section	.note.GNU-stack,"",@progbits
