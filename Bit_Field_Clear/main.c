#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "library.h"

extern uint32_t BitFieldClear(uint32_t word, int lsb, int width) ;

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

//This function simulates the ARM BFC instruction
uint32_t BFC(uint32_t word, int lsb, int width)
	{
	uint32_t mask = (1 << (lsb+width)) - (1 << lsb) ;
	return word & ~mask ;
	}

int main(void)
	{
	static struct
		{
		uint32_t	before ;
		int			lsb ;
		int			width ;
		} testcase[] =
		{
		{0xFFFFFFFF,  5, 7},
		{0xFFFFFFFF, 22, 5}
		} ;
	int k ;

	InitializeHardware(HEADER, PROJECT_NAME) ;

	for (;;)
		{
		for (k = 0; k < ENTRIES(testcase); k++)
			{
			uint32_t	word	= testcase[k].before ;
			int			lsb		= testcase[k].lsb ;
			int			width	= testcase[k].width ;
			uint32_t	result, answer	= BFC(word, lsb, width) ;
			uint32_t    before, after, cycles ;

            before = GetClockCycleCount() ;
			result = BitFieldClear(word, lsb, width) ;
            after  = GetClockCycleCount() ;
            cycles = after - before ;

			printf("   Test Case %d: %08X,%d,%d\n", k+1,
				(unsigned) word, lsb, width) ;

			printf("Correct Result: %08X\n", (unsigned) answer) ;

			printf("   Your Result: %08X", (unsigned) result) ;
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
