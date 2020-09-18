/*
 * source.asm
 *
 *  Created on: 17/02/2020
 *      Author: Markel Alvarez
 */

.global start
.data
X:		.word 0x03
Y:		.word 0x0A

.bss
Mayor:	.space 4

.text
start:
		LDR R4, =X
		LDR R3, =Y
		LDR R5, =Mayor
		LDR R1, [R4]
		LDR R2, [R3]
		CMP R1, R2
		BLE else
		STR R1, [R5]
		B FIN
else: 	STR R2, [R5]
FIN: 	B .
		.end
