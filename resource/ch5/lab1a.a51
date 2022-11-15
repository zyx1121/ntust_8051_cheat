				ORG		0
START:	MOV 	A,#10000000B
LOOP: 	MOV 	P0,A
				RR 		A
				CALL 	DELAY
				JMP 	LOOP
DELAY: 	MOV 	R5,#5
DL1: 		MOV 	R6,#200
DL2: 		MOV 	R7,#230
				DJNZ 	R7,$
				DJNZ 	R6,DL2
				DJNZ 	R5,DL1
				RET
				END