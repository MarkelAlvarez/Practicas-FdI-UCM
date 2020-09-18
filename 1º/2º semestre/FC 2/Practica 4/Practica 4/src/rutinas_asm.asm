// Markel Alvarez
.global RGB2GrayMatrix

.EQU N, 128*128

.text

RGB2GrayMatrix:
	PUSH {R4 - R12, LR}

	MOV R4, #0
	MOV R5, #N
	MOV R6, R0
	MOV R7, R1
	MOV R11, R4

for:
	CMP R4, R5
	BGE for_fin

	LDRB R8, [R6, R11]
	ADD R11, R11, #1
	LDRB R9, [R6, R11]
	ADD R11, R11, #1
	LDRB R10, [R6, R11]

	MOV R0, R8
	MOV R1, R9
	MOV R2, R10

	BL rgb2gray
	STRB R0, [R7, R4]
	ADD R4, R4, #1
	ADD R11, R11, #1
	B for

for_fin:
	POP {R4 - R12, LR}
	MOV PC, LR
