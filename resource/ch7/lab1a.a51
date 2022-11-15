		ORG		00H
		MOV		SCON, #50H
		MOV		TMOD, #20H
		MOV		TH1, #(256-(28800/9600))
		MOV		TL1, #(256-(28800/9600))
		SETB	TR1
		SETB	P2.5
		MOV		P0, #0
		
				MOV		DPTR, #TABLE1
		
		
START:	MOV		R0, #0
				MOV		R1, #6

				JNB		P2.5, $
				CALL	DELAY
				JNB		P2.5, LOOP
		
		
LOOP:		MOV		A, R0
				MOVC	A, @A+DPTR
				MOV		SBUF, A
				JNB		TI, $
				CLR		TI
				INC		R0
				DJNZ	R1, LOOP
		
				JB		P2.5, $
				JMP		START
		
		
DELAY:	MOV		R6, #40
DLOOP:	MOV		R7, #230
				DJNZ	R7, $
				DJNZ	R6, DLOOP
				RET
		
		
TABLE1:	DB		'H', 'E', 'L', 'L', 'O', '!'
				END