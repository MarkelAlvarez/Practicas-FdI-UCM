	.global rgb2gray

	.equ COEF1, 3483
	.equ COEF2, 11718
	.equ COEF3, 1183

	.text

rgb2gray:
  		ldr r3, =COEF1
  		mul r0, r3, r0
  		ldr r3, =COEF2
  		mla r0, r3, r1, r0
  		ldr r3, =COEF3
  		mla r0, r3, r2, r0
  		mov r0, r0, lsr #14

  		mov pc, lr

/*
	.global RGB2GrayMatrix
//	.extern rgb2gray
		.equ i, -12
		.equ j, -16
		.equ orig, -20
		.equ dest, -24
		.equ N,128
		.equ M,128

RGB2GrayMatrix:
		push {r4,fp,lr}
		add fp, sp, #4*(3-1)
		sub sp, sp, #4*4
		str r0, [fp, #orig]
		str r1, [fp, #dest]

		//i=0
		mov r0, #0
		str r0, [fp, #i]
L0:		//while (i<N)
		ldr r0, [fp, #i]
		cmp r0, #N
		bge L1
		//j = 0
		mov r0, #0
		str r0, [fp, #j]
		//while (j<M)
L2:		ldr r0, [fp, #j]
		cmp r0, #M
		bge L3

		// r0 <- orig[i][j].R
		ldr r3, [fp, #orig]
		ldr r2, [fp, #i]
		ldr r4, [fp, #j]
		mov r1, #M
		mla r4, r2, r1, r4
		mov r1, #3
		mul r4, r1, r4
		ldrb r0, [r3, r4]
		// r1 <- orig[i][j].G
		add r4, r4, #1
		ldrb r1, [r3, r4]
		// r2 <- orig[i][j].B
		add r4, r4, #1
		ldrb r2, [r3, r4]

		bl rgb2gray
		// dest[i][j] <- r0
		ldr r3, [fp, #dest]
		ldr r2, [fp, #i]
		ldr r4, [fp, #j]
		mov r1, #M
		mla r4, r2, r1, r4
		strb r0, [r3, r4]

		//j++
		ldr r0, [fp, #j]
		add r0, r0, #1
		str r0, [fp, #j]
		b L2
L3:
		//i++
		ldr r0, [fp, #i]
		add r0, r0, #1
		str r0, [fp, #i]
		b L0
L1:
		sub sp, fp, #4*(3-1)
		pop {r4,fp,lr}
		bx lr
		*/

  		.end


