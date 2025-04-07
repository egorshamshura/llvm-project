	.file	"test32.ll"
	.text
	.globl	main                            ; -- Begin function main
	.type	main,@function
main:                                   ; @main
; %bb.0:
	MOVli32 rh2 -2
	MOVli32 rh4 10
	PUTPIXEL rh4 rh4 rh2
	FLUSH
	MOVli32 rh9 12
	BR32 rh0
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
                                        ; -- End function
	.section	".note.GNU-stack","",@progbits
