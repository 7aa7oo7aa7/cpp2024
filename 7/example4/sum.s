	.file	"sum.cpp"
	.text
	.section	.text._Z3SumIiET_S0_S0_,"axG",@progbits,_Z3SumIiET_S0_S0_,comdat
	.weak	_Z3SumIiET_S0_S0_
	.type	_Z3SumIiET_S0_S0_, @function
_Z3SumIiET_S0_S0_:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_Z3SumIiET_S0_S0_, .-_Z3SumIiET_S0_S0_
	.section	.text._Z3SumIdET_S0_S0_,"axG",@progbits,_Z3SumIdET_S0_S0_,comdat
	.weak	_Z3SumIdET_S0_S0_
	.type	_Z3SumIdET_S0_S0_, @function
_Z3SumIdET_S0_S0_:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	%xmm0, -8(%rbp)
	movsd	%xmm1, -16(%rbp)
	movsd	-8(%rbp), %xmm0
	addsd	-16(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	_Z3SumIdET_S0_S0_, .-_Z3SumIdET_S0_S0_
	.ident	"GCC: (GNU) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
