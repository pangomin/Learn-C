	.file	"short-test.c"
	.text
	.globl	test
	.type	test, @function
test:
.LFB0:
	.cfi_startproc
	leal	(%rdx,%rsi), %eax
	subl	%edi, %eax
	cmpw	$5, %dx
	jle	.L2
	cmpw	$2, %si
	jle	.L3
	movswl	%di, %eax
	movswl	%dx, %ecx
	cltd
	idivl	%ecx
	ret
.L3:
	movswl	%di, %eax
	movswl	%si, %esi
	cltd
	idivl	%esi
	ret
.L2:
	cmpw	$2, %dx
	jg	.L1
	movswl	%dx, %eax
	movswl	%si, %esi
	cltd
	idivl	%esi
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	test, .-test
	.ident	"GCC: (GNU) 16.2.1 20260810"
	.section	.note.GNU-stack,"",@progbits
