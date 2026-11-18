shift_left4_rightn:

	movq	%rdi, %rax
	salq	$4, %rax
	movl	%esi, %ecx
	shrq	%cl, %rax
	ret
