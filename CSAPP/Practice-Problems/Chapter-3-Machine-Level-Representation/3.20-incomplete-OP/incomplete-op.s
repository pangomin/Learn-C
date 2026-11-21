	.file	"incomplete-op.c"
	.text
	.globl	arith
	.type	arith, @function
arith:
.LFB0:
	.cfi_startproc
	leal	15(%rdi), %eax
	testw	%di, %di
	cmovns	%edi, %eax
	sarw	$4, %ax
	ret
	.cfi_endproc
.LFE0:
	.size	arith, .-arith
	.ident	"GCC: (GNU) 16.2.1 20260810"
	.section	.note.GNU-stack,"",@progbits
