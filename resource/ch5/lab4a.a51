			ORG 	0
			MOV 	R0,#0
			MOV 	P0,#0
			SETB 	P2.5
			MOV		A,#00000001B
			MOV		P0,A
			
START: 		JNB 	P2.5,$
					CALL 	DELAY
					JNB 	P2.5, START
			
LEDGO: 		RL		A
					MOV		P0,A
			
DEBOUN2: 	JB 		P2.5,$
					CALL 	DELAY
					JB 		P2.5,DEBOUN2
					JMP 	START
			
DELAY: 		MOV 	R6,#100
DLOOP: 		MOV 	R7,#230
					DJNZ 	R7,$
					DJNZ 	R6,DLOOP
					RET
					END