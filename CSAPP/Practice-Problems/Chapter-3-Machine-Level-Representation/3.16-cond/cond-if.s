	.file	"cond-if.c"
	.text
	.globl	cond
	.type	cond, @function
cond:
.LFB0:
	.cfi_startproc
	testw	%di, %di
	je	.L1
	cmpw	%di, (%rsi)
	jge	.L1
	movw	%di, (%rsi)
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	cond, .-cond
	.ident	"GCC: (GNU) 16.2.1 20260810"
	.section	.note.GNU-stack,"",@progbits
