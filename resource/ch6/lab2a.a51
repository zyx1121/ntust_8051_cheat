				ORG		0
				SETB	P3.4
				MOV		DPTR, #TABLE
				MOV		TMOD, #55H
				SETB	TR0

LOOP:		MOV		TH0, #0
				CALL	DELAY
				MOV		A, TL0
				MOV		B, #10
				DIV		AB
				MOVC	A, @A+DPTR
				MOV		P0, A
				JMP		LOOP

DELAY:	MOV		R6, #2
DLOOP:	MOV		R7, #230
				DJNZ	R7, $
				DJNZ	R6, DLOOP

TABLE:	DB		3FH, 06H, 5BH, 4FH, 66H, 6DH, 7CH, 07H, 7FH, 67H
				END