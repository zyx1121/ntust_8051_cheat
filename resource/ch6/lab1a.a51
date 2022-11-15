					ORG		0
					SETB	P2.5
					MOV		DPTR, #TABLE
					MOV		TMOD, #11H
					MOV		P0, #00H
			
START:		JNB		P2.5, $
					MOV		R0, #0
DISPLAY:	MOV		A, R0
					MOVC	A, @A+DPTR
					MOV		P0, A
					INC		R0
					CALL	DELAY
					CJNE	R0, #6,DISPLAY
					JMP		START
			
DELAY:		MOV		R1, #20
LOOP:			MOV		TH0, #(65536-46080) / 256
					MOV		TL0, #(65536-46080) MOD 256
					SETB	TR0
					JNB		TF0, $
					CLR		TR0
					CLR		TF0
					DJNZ	R1, LOOP
					RET
			
TABLE:		DB		6DH,66H,4FH,5BH,06H,3FH
					END