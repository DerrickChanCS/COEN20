		.syntax	unified
		.arch	armv7-m
		.text
		.thumb_func
		.align	2

// ------------------------------------------------------------------------------------------
// int CountLeadingZeroes(uint32_t word)
// ------------------------------------------------------------------------------------------

		.globl  CountLeadingZeroes
CountLeadingZeroes:

		// On entry: R0 = word

	        // Insert your code here

		BX      LR		    // Return result in R0

		.end
