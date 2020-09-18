// Markel Alvarez

.global start
	.EQU N, 8 // conts N = 8
.data
	A:		.word 7,3,25,4,75,2,1,1 // A[] = [7,3,25,4,75,2,1,1]
.bss
	max: 	.space 4 // Reserva espacio para el máximo
.text
	start:
		MOV R0, #0
		LDR R1, =max // Leo la dir. de max
		STR R0, [R1] // Escribo 0 en max
		LDR R2, =A   // Se almacena en R2 la dirección de comienzo de A
		MOV R3, #0   // Se inicializa el índice del array

	for:
		CMP R3, #N // if i >= N -> END
		BGE end
		LDR R4, [R2, R3, LSL#2]
		LDR R0, [R1]
		CMP R0, R4
		BGE continue_for
		MOV R0, R4
		STR R0, [R1] // Almacena el nuevo maximo en max
		B continue_for

	continue_for:
		ADD R3, R3, #1 // i++
		B for

	end:
		B .
		.end
