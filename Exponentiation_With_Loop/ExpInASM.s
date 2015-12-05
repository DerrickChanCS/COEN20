		.syntax unified
		.arch	armv7-m
		.text
		.thumb_func
		.align	2

// ------------------------------------------------------------------------------------------
// int32_t ExpInASM(int32_t x, uint32_t n)
// ------------------------------------------------------------------------------------------

		.globl  ExpInASM
ExpInASM:
		LDR R2,=1 //Y
	// RO is p or x	
	start:
		AND R3,R1,#1
		CMP	R3,#0
		BEQ L1
		MUL R2,R2,R0
	L1:
		LSR R1,R1,#1
		CMP R1,#0
		BEQ endLoop
		MUL R0,R0,R0
		B start
	endLoop:
		MOV R0,R2

		BX      LR

     		.end
