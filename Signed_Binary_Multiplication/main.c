#include <stdio.h>
#include <stdint.h>
#include "library.h"

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

int16_t SBinaryMultiply(int8_t mpier, int8_t mcand) ;

int main(void)
	{
	static struct { int8_t multiplier, multiplicand ; } testcase[] =
 		{
		{0,1},{-1,-1},{2,-2},{-3,3},{127, 127},{-128,-128},{127,-128}
 		} ;
	int k ;

	InitializeHardware(HEADER, PROJECT_NAME) ;

	for (;;)
		{
		for (k = 0; k < ENTRIES(testcase); k++)
			{
			int8_t mpier = testcase[k].multiplier ;
			int8_t mcand = testcase[k].multiplicand ;
			uint32_t before, after, cycles ;
			int16_t product ;

            before = GetClockCycleCount() ;
 			product = SBinaryMultiply(mpier, mcand) ;
            after  = GetClockCycleCount() ;
            cycles = after - before ;

			printf("   Test Case %d: %d x %d\n", k+1, mpier, mcand) ;

			printf("Correct Result: %d\n", mpier * mcand) ;

			printf("   Your Result: %d", product) ;
			if (product != mpier * mcand) printf(" %s", ERROR_FLAG) ;
			printf("\n") ;

			printf("  Clock Cycles: %lu\n\n", cycles) ;

			WaitForPushButton() ;
			}

		printf("Press button to start over.\n") ;
		WaitForPushButton() ;
		ClearDisplay() ;
		}
	}
