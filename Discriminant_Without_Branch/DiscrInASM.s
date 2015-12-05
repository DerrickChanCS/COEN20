		.syntax	unified
		.arch	armv7-m
		.text
		.thumb_func
		.align	2

// ------------------------------------------------------------------------------------------
// int32_t DiscrInASM(int32_t a, int32_t b, int32_t c)
// ------------------------------------------------------------------------------------------

		.globl  DiscrInASM
DiscrInASM:

	// The first parameter (a) is passed to this function in R0.
	// The second parameter (b) is passed to this function in R1.
	// The second parameter (c) is passed to this function in R2.
	// The function should return the result in R0.

	// Registers R0 through R3 may be modified without
	// preserving their original content. However, the
	// value of all other registers must be preserved!

	// Insert your code here ...

		BX	LR		            // return

		.end
