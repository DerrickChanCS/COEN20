#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "library.h"

extern uint32_t UnsignedBitFieldExtract(uint32_t word, int lsb, int width) ;

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

//This function simmulates the UBFX instruction
uint32_t UBFX(uint32_t word, int lsb, int width)
	{
	return (word >> lsb) & ((1 << width) - 1) ;
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
		{0xFFFFFFFF, 22, 5},
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
			uint32_t	result, answer = UBFX(packed, lsb, width) ;
			uint32_t    before, after, cycles ;

            before = GetClockCycleCount() ;
			result = UnsignedBitFieldExtract(packed, lsb, width) ;
            after  = GetClockCycleCount() ;
            cycles = after - before ;

			printf("   Test Case %d: %08X,%d,%d\n", k+1,
				(unsigned) packed, lsb, width) ;

			printf("Correct Result: %u\n", (unsigned) answer) ;

			printf("   Your Result: %u", (unsigned) result) ;
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
