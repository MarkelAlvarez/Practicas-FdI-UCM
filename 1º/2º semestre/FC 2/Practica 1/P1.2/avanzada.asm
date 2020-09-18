/*
 * avanzada.asm
 *
 *  Created on: 18/02/2020
 *      Author: Markel Alvarez
 */

/*
	for(i=0; i<4; i++)
	{
		A = A+B;
	}
	C = A;
*/
.global start

/*.data
A:		.word 18
B: 		.word 4
C: 		.word 0*/

.text
start:
		MOV R0, #0
		MOV R1, #18
		MOV R2, #4
		MOV R3, #0
		/*LDR R1, =A
		LDR R1, [R1]
		LDR R2, =B
		LDR R2, [R2]
		LDR R3, =C
		LDR R3, [R3]*/

		for: CMP R0, #4
			 BGE fin_f
			 ADD R1, R1, R2
			 ADD R0, R0, #1
			 B for
	    fin_f:
		     STR R3, [R1]
	    	 B FIN
FIN: 	B .
    	.end
