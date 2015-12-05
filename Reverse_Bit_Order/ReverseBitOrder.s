		.syntax	unified
		.arch	armv7-m
		.text
		.thumb_func
		.align	2

// ------------------------------------------------------------------------------------------
// uint32_t ReverseBitOrder(uint32_t word)
// ------------------------------------------------------------------------------------------

		.globl  ReverseBitOrder
ReverseBitOrder:

		// On entry: R0 = word

		// Insert your code here

		BX	LR		    // Return result in R0

		.end
