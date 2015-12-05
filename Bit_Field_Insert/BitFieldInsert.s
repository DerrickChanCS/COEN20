		.syntax	unified
		.arch	armv7-m
		.text
		.thumb_func
		.align	2

// ------------------------------------------------------------------------------------------
// uint32_t BitFieldInsert(uint32_t word, int lsb, int width, uint32_t value)
// ------------------------------------------------------------------------------------------

		.globl  BitFieldInsert
BitFieldInsert:

		// On entry: R0 = word, R1 = lsb, R2 = width, R3 = value

		PUSH {R4,R5,R6}
		LDR R4,=1 //mask
		LDR R5,=1
		//mask = (1 << (lsb+width)) - (1 << lsb);
		ADD R6,R1,R2  //lsb+width
		LSL R4,R4,R6  //1<<(lsb+width) --> R4
		LSL R5,R5,R1  //1<<lsb --> R5
		SUB R4,R4,R5  //1<<(lsb+width) - (1<<lsb);
		MVN R4,R4     //word &= ~mask 
		AND R0,R0,R4

		LDR R5,=1     //mask
		LSL R5,R5,R2  //1<<width
		SUB R4,R5,#-1 //1<<width - 1 --> R4 = mask
		AND R3,R3,R4  //value&=mask

		LSL R3,R3,R1  //value<<lsb
		ORR R0,R0,R3  //R0 == word


		POP {R4,R5,R6}

		BX      LR		            // return result in R0

		.end
