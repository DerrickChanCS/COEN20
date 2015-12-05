#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "library.h"

#define LSW(x)	((uint32_t *) &(x))[0]	/* Least-significant 32 bits of 64-bit double word */
#define MSW(x)	((uint32_t *) &(x))[1]	/* Most-significant 32 bits of 64-bit double word  */

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

extern uint32_t UDiv64x32inASM(uint64_t dividend64, uint32_t divisor32) ;

// Shift and subtract algorithm for division
uint32_t UDiv64x32inC(uint64_t dividend64, uint32_t divisor32)
	{
	int k, cout ;

	for (k = 0; k < 32; k++)
		{
		// These two lines are a 64-bit left shift with carry out
		cout = MSW(dividend64) >> 31 ;
		dividend64 = dividend64 << 1 ;

		if (cout == 1 || MSW(dividend64) >= divisor32)
			{
			MSW(dividend64) = MSW(dividend64) - divisor32 ;
			LSW(dividend64) = LSW(dividend64) + 1 ;
			}
		}

	// LSW(dividend64) = Quotient
	// MSW(dividend64) = Rmeainder

	return LSW(dividend64) ;
	}

void PrintU64(uint64_t n)
    {
    if (n >= 10) PrintU64(n / 10) ;
    printf("%d", (int) (n % 10)) ;
    }

int main(void)
	{
	static struct { uint64_t dividend; uint32_t divisor ; } testcase[] =
 		{
		{100ULL,3UL},{200ULL,3UL},{300ULL,4UL},{0x400000000ULL,0x400UL}
		} ;
	int k ;

	InitializeHardware(HEADER, PROJECT_NAME) ;

	for (;;)
		{
		for (k = 0; k < ENTRIES(testcase); k++)
			{
			uint64_t dividend = testcase[k].dividend ;
			uint32_t divisor = testcase[k].divisor ;
			uint32_t result, answer = UDiv64x32inC(dividend, divisor) ;
			uint32_t before, after, cycles ;

            before = GetClockCycleCount() ;
            result = UDiv64x32inASM(dividend, divisor) ;
            after  = GetClockCycleCount() ;
            cycles = after - before ;

			printf("   Test Case %d: ", k+1) ;
			PrintU64(dividend) ;
			printf("/%lu\n", divisor) ;

			printf("Correct Result: %lu\n", answer) ;

			printf("   Your Result: %lu", result) ;
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
