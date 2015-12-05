		.syntax	unified
		.arch	armv7-m
		.text
		.thumb_func
		.align	2

// ------------------------------------------------------------------------------------------
// uint32_t UnsignedBitFieldExtract(uint32_t word, int lsb, int width)
// ------------------------------------------------------------------------------------------

		.globl  UnsignedBitFieldExtract
UnsignedBitFieldExtract:

		// On entry: R0 = word, R1 = lsb, R2 = width

		// Insert your code here ...

		BX	LR		// return

		.end
