		.syntax	unified
		.arch	armv7-m
		.text
		.thumb_func
		.align	2

// ------------------------------------------------------------------------------------------
// uint32_t ReverseByteOrder(uint32_t word)
// ------------------------------------------------------------------------------------------

		.globl  ReverseByteOrder
ReverseByteOrder:

		// On entry: R0 = word

		LDR R1,=0
		AND R2,R0,0x000000ff
		LSL R2,R2,#24
		ORR R1,R1,R2

		AND R2,R0,0x0000ff00
		LSL R2,R2,#8
		ORR R1,R1,R2

		AND R2,R0,0x00ff0000
		LSR R2,R2,#8
		ORR R1,R1,R2

		AND R2,R0,0xff000000
		LSR R2,R2,#24
		ORR R1,R1,R2
		// Insert your code here
		
		MOV R0,R1

		BX	LR		    // Return result in R0

		.end
