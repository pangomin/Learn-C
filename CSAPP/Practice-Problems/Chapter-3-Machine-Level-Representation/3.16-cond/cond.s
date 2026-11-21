	.file	"cond.c"
	.text
	.globl	cond
	.type	cond, @function
cond:
.LFB0:
	.cfi_startproc
	testw	%di, %di
	je	.L1
	cmpw	%di, (%rsi)
	jl	.L3
.L1:
	ret
.L3:
	movw	%di, (%rsi)
	ret
	.cfi_endproc
.LFE0:
	.size	cond, .-cond
	.ident	"GCC: (GNU) 16.2.1 20260810"
	.section	.note.GNU-stack,"",@progbits
