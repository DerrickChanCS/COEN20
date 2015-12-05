#include <stdio.h>
#include <stdint.h>
#include "library.h"

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

extern uint32_t ReverseBitOrder(uint32_t) ;

// This function simulates the RBIT instruction ...
uint32_t RBIT(uint32_t word)
	{
	uint32_t result ;
	int bit ;

	result = 0 ;
	for (bit = 0; bit <= 31; bit++)
		{
		result |= (word & 1) << (31 - bit) ;
		word >>= 1 ;
		}

	return result ;
	}

int main(void)
    {
	static uint32_t testcase[] =
		{
		0x80000000, 0x00000001, 0x12345678,	0x0000FFFF,	0x0F0F0F0F,	0x08080808
		} ;

	InitializeHardware(HEADER, PROJECT_NAME) ;

	for (;;)
		{
		int k ;

		for (k = 0; k < ENTRIES(testcase); k++)
			{
			uint32_t word = testcase[k] ;
			uint32_t result, answer = RBIT(word) ;
			uint32_t before, after, cycles ;

            before = GetClockCycleCount() ;
			result = ReverseBitOrder(word) ;
            after  = GetClockCycleCount() ;
            cycles = after - before ;

			printf("   Test Case %d: %08X (hex)\n", k+1, (unsigned) word) ;

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
