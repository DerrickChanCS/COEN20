		.syntax	unified
		.arch	armv7-m
		.text
		.thumb_func
		.align	2

// ------------------------------------------------------------------------------------------
// uint32_t UDiv64x32inASM(uint64_t dividend64, uint32_t divisor32)
// ------------------------------------------------------------------------------------------

		.globl  UDiv64x32inASM
UDiv64x32inASM:

	// The two parameters are passed to this function as follows:
	//
	// dividend64 is in register pair R1.R0
	// divisor32 is in register R2
	//
	// The quotient must be returned in register R0

	// Insert your code here ...

		BX      LR		    // Return to calling program.

		.end
