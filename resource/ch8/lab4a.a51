			ORG		0
			JMP		START
			ORG		23H
			JMP		UART_INT
			
START:		MOV		TMOD,#20H
			MOV		TH1,#253
			MOV		SCON,#50H
			SETB	TR1
			SETB	ES
			SETB	EA
			
			MOV		DPTR,#TEXT
			
			MOV		R5,#0
			MOV		R6,#0
			MOV		R7,#1
			SETB	TI
			
			JMP		$
			
UART_INT:	JB		TI,TI_OK

RI_OK:		CLR		RI
			MOV		R0,SBUF
			MOV		R7,#1
			MOV		R6,#1
			SETB	TI
			JMP		UART_EXIT

TI_OK:		CLR		TI
			CJNE	R7,#1,UART_EXIT
			CJNE	R6,#1,SDTX
			MOV		SBUF,R0
			MOV		R6,#0
			JMP		UART_EXIT
			
SDTX:		MOV		A,R5
			MOVC	A,@A+DPTR
			MOV		SBUF,A
			INC		R5
			CJNE	R5,#29,UART_EXIT
			MOV		R5,#0
			MOV		R7,#0
			JMP		UART_EXIT

UART_EXIT:	RETI

TEXT:		DB		" The keyboard you pressed is "

			END