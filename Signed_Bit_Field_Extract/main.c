#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "library.h"

extern int32_t SignedBitFieldExtract(uint32_t word, int lsb, int width) ;

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

// This function simulates the SBFX instruction ...
int32_t SBFX(uint32_t word, int lsb, int width)
	{
	// There is a MUCH easier way to do this in assembly!
	uint32_t bits = (word >> lsb) & ((1 << width) - 1) ;
	if ((bits >> (width - 1)) != 0) bits |= ~((1 << width) - 1) ;
	return (int32_t) bits ;
	}

int main(void)
	{
	static struct
		{
		uint32_t	packed ;
		int			lsb ;
		int			width ;
		} testcase[] =
		{
		{0xFFFFFFFF,  5, 7},
		{0xF0FFFFFF, 22, 5},
		{0x12345678, 13, 8}
		} ;
	int k ;

	InitializeHardware(HEADER, PROJECT_NAME) ;

	for (;;)
		{
		for (k = 0; k < ENTRIES(testcase); k++)
			{
			uint32_t	packed	= testcase[k].packed ;
			int			lsb		= testcase[k].lsb ;
			int			width	= testcase[k].width ;
			int32_t     result, answer = SBFX(packed, lsb, width) ;
			uint32_t    before, after, cycles ;

            before = GetClockCycleCount() ;
			result = SignedBitFieldExtract(packed, lsb, width) ;
            after  = GetClockCycleCount() ;
            cycles = after - before ;

			printf("   Test Case %d: %08X,%d,%d\n", k+1,
				(unsigned) packed, lsb, width) ;

			printf("Correct Result: %d\n", (signed) answer) ;

			printf("   Your Result: %d", (signed) result) ;
			if (result != answer) printf(" %s", ERROR_FLAG) ;
			printf("\n") ;

			printf("  Clock Cycles: %lu\n\n", cycles) ;

			WaitForPushButton() ;
			}

		printf("Press button to start over.\n") ;
		WaitForPushButton() ;
		ClearDisplay() ;
		}
	}
