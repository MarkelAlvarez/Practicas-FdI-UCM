// Markel Alvarez
.extern _stack
.global start
.equ 	N, 8

.data
A: 		.word 7,3,25,4,75,2,1,1

.bss
B:		.space N*4
max: 	.space 4
ind:	.space 4

.text
start:
		LDR SP, =_stack
		MOV FP, #0
		MOV R1, #N
		MOV R4, #0

for1:
		LDR R0, =A
		CMP R4, #N
		BGE for1_fin
		BL max2
		MOV R5, R0
		LDR R6, =A
		LDR R7, [R6, R5, LSL#2]
		LDR R8, =B
		STR R7, [R8, R4, LSL#2]
		MOV R9, #0
		STR R9, [R6, R5, LSL#2]
		ADD R4, R4, #1
		B for1

for1_fin:
		B .

max2:
		PUSH {R4-R9, FP}
		ADD FP, SP, #24
		MOV R4, R0
		LDR R6, =max
		MOV R7, #0
		STR R7, [R6]
		LDR R8, =ind
		STR R7, [R8]
		MOV R5, #0

for:
		CMP R5, R1
		BGE for_fin
		LDR R7, [R4, R5, LSL#2]
		LDR R9, [R6]
		CMP R7, R9
		BLE if_fin
		STR R7, [R6]
		STR R5, [R8]

if_fin:
		ADD R5, R5, #1
		B for

for_fin:
		LDR R4, [R8]
		MOV R0, R4
		B max_dev

max_dev:
		POP {R4-R9, FP}
		MOV PC, LR

.end
