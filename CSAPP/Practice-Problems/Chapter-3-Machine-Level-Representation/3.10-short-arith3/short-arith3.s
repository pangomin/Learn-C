; short arith3(short x, short y, short z)
; x in %rdi, y in %rsi, z in %rdx

arith3:
	orq		%rsi, %rdx
	sarq	$9, %rdx
	notq	%rdx
	movq	%rdx, %bax
	subq	%rsi, %rbx
	ret
