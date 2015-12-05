		.syntax	unified
		.arch	armv7-m
		.text
		.thumb_func
		.align	2

// ------------------------------------------------------------------------------------------
// int64_t SMul64x64inASM(int64_t a, int64_t b)
// ------------------------------------------------------------------------------------------

		.globl  SMul64x64inASM
SMul64x64inASM:

	// The two parameters are passed to this function as follows:
	//
	// a<63..32> is in register R1; a<31..0> is in register R0
	// b<63..32> is in register R3; b<31..0> is in register R2
	//
	// Bits 63..32 of the product must be returned in register R1
	// Bits 31..0 of the product must be returned in register R0
	//
	// The value of all other registers must be preserved!

	// Insert your code here ...
		PUSH {R4}

		UMULL R1,R4,R1,R2 //ahi * blo
		UMULL R4,R3,R0,R3 //alo * bhi
		UMULL R2,R0,R0,R2 //alo * blo  LOXLO

		ADD R0, R0, R1
		ADD R0, R0, R4

		MOV R1, R2

		POP {R4}

		BX	    LR		    	// Return to calling program.

        	.end
