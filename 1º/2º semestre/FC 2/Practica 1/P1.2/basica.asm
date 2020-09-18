/*
 * source.asm
 *
 *  Created on: 17/02/2020
 *  Author: Markel Alvarez
 */

/*	C = 0
	while( A >= B )
	{
		A = A - B
		C = C + 1
	}
*/
.global start

.data
A:		.word 0x18
B: 		.word 0x04
C: 		.word 0x00

.text
start:
		LDR R1, =A
		LDR R1, [R1]
		LDR R2, =B
		LDR R2, [R2]
		LDR R3, =C
		LDR R3, [R3]

		while: CMP R1, R2
			   BLT fin_w
			   SUB R1, R1, R2
			   ADD R3, R3, #1
			   B while
	    fin_w:
	    	   LDR R4, =C
		       STR R3, [R4]
	    	   B FIN
FIN: 	B .
    	.end
