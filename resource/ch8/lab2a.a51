		ORG		0
		JMP		S
		ORG		0BH
		JMP		TIMER0

S:
		MOV		TMOD,#01H
		MOV		TH0,#HIGH(65536-46080)
		MOV		TL0,#LOW(65536-46080)
		SETB	ET0
		SETB	EA
		
		MOV		DPTR,#TABLE
		MOV		R0,#0
		MOV		R1,#0
		MOV		P0,#3FH
		SETB	P2.5
		
START:	
		JNB		P2.5,$
		MOV		P0,#6DH
		SETB	TR0
		JMP		START
		
TIMER0:
		MOV		TH0,#HIGH(65536-46080)
		MOV		TL0,#LOW(65536-46080)
		INC		R1
		CJNE	R1,#20,EXIT
		MOV		R1,#0
		
		MOV		A,R0
		MOVC	A,@A+DPTR
		MOV		P0,A
		INC		R0
		CJNE	R0,#5,EXIT
		
		MOV		R0,#0
		CLR		TR0
		
EXIT:
		RETI
		
TABLE:
		DB		66H,4FH,5BH,06H,3FH
		END