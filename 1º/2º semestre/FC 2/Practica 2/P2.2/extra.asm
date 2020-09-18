// Markel Alvarez
/*.global start
	.EQU N, 8

.data
	A: .word 7,3,25,4,75,2,1,1

.bss
	B: .space N*4
	max: .space 4
	ind: .space 4

.text
	start:
		LDR R0, = A

		LDR R1, = B

		LDR R2, = max
		LDR R2, [R2]
		LDR R3, = ind
		LDR R3, [R3]
		MOV R5, #0		//j
	for1:
		CMP R5, #N
		BGE finfor1
		MOV R4, #0		//max
		MOV R7, #0		//i
	for2:
		CMP R7, #N
		BGE finfor2

		LDR R8, [R0, R7, LSL#2]	// R8 = A[i]
		CMP R8, R4
		BLE finif
		MOV R4, R8		// max = A[i]
		STR R4, [R2]
		MOV R9, R7		// ind = i
		STR R9, [R3]
	finif:
		ADD R7, R7, #1
		B for2
	finfor2:
		LDR R10, [R0, R9, LSL#2]		//B[j]=A[ind];
		STR R10, [R1, R5, LSL#2]
		MOV R11, #0
		STR R11, [R0, R9, LSL#2]		//A[ind]=0;
		ADD R5, R5, #1
		B for1
	finfor1:
		B .
		.end
*/
