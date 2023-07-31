	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 3
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	.cfi_def_cfa_offset 16
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w0, #24910
	movk	w0, #188, lsl #16
	bl	_printd
	mov	w0, #0
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_printd                         ; -- Begin function printd
	.p2align	2
_printd:                                ; @printd
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	w0, [x29, #-4]
	ldur	w8, [x29, #-4]
	subs	w8, w8, #0
	cset	w8, ge
	tbnz	w8, #0, LBB1_2
	b	LBB1_1
LBB1_1:
	mov	w0, #45
	bl	_putchar
	ldur	w9, [x29, #-4]
	mov	w8, #0
	subs	w8, w8, w9
	stur	w8, [x29, #-4]
	b	LBB1_2
LBB1_2:
	ldur	w8, [x29, #-4]
	mov	w9, #10
	sdiv	w8, w8, w9
	str	w8, [sp, #8]
	subs	w8, w8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB1_4
	b	LBB1_3
LBB1_3:
	ldr	w0, [sp, #8]
	bl	_printd
	b	LBB1_4
LBB1_4:
	ldur	w8, [x29, #-4]
	mov	w10, #10
	sdiv	w9, w8, w10
	mul	w9, w9, w10
	subs	w8, w8, w9
	add	w0, w8, #48
	bl	_putchar
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
