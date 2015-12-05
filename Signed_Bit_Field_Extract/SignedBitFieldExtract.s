		.syntax	unified
		.arch	armv7-m
		.text
		.thumb_func
		.align	2

// ------------------------------------------------------------------------------------------
// int32_t SignedBitFieldExtract(uint32_t word, int lsb, int width)
// ------------------------------------------------------------------------------------------

		.globl  SignedBitFieldExtract
SignedBitFieldExtract:

		// On entry: R0 = word, R1 = lsb, R2 = width

		// Insert your code here ...

		BX	LR		// return

		.end
