		.syntax unified
		.arch	armv7-m
		.text
		.thumb_func
		.align	2

// ------------------------------------------------------------------------------------------
// uint32_t SqrtInASM(uint32_t x)
// ------------------------------------------------------------------------------------------

		.globl  SqrtInASM
SqrtInASM:

		LDR R1,=0 //y
		LDR R2,=1073741824 //2^30 m

	startloop:
		ORR R3,R1,R2 //b
		LSR R1,R1,#1
		CMP R3,R0
		BGT L1
		SUB R0,R0,R3
		ORR R1,R1,R2
	L1:
		LSR R2,R2,#2
		CMP R2,#0
		BNE startloop:

		MOV R0,R1	

		BX      LR

	        .end
