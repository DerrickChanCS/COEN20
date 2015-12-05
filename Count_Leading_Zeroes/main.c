#include <stdio.h>
#include <stdint.h>
#include "library.h"

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

extern int CountLeadingZeroes(uint32_t) ;

// This function simulates the CLZ instruction ...
int CLZ(uint32_t word)
	{
	int bit, count = 0 ;

	for (bit = 31; bit >= 0; bit--)
		{
		if ((word & (1 << bit)) != 0) break ;
		count++ ;
		}

	return count ;
	}

int main(void)
    {
	static uint32_t testcase[] =
		{
		0x00000000,	0xFFFFFFFF,	0x00008000,	0x08080808
		} ;

	InitializeHardware(HEADER, PROJECT_NAME) ;

	for (;;)
		{
		int k ;

		for (k = 0; k < ENTRIES(testcase); k++)
			{
			uint32_t word = testcase[k] ;
			int result, answer = CLZ(word) ;
			uint32_t before, after, cycles ;

            before = GetClockCycleCount() ;
			result = CountLeadingZeroes(word) ;
            after  = GetClockCycleCount() ;
            cycles = after - before ;

			printf("   Test Case %d: %08X (hex)\n", k+1, (unsigned) word) ;

			printf("Correct Result: %d\n", answer) ;

			printf("   Your Result: %d", result) ;
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
