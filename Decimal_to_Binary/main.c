#include <stdio.h>
#include <stdint.h>
#include "library.h"

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

void Dec2Bin(int decimal, int binary[8]) ;

int main(void)
	{
	static struct { int decimal ;} testcase[] =
		{
		{0},{+1},{-1},{+2},{-2},{-128},{+127},{-127}
		} ;
	int binary[8] ;
	int k ;

	InitializeHardware(HEADER, PROJECT_NAME) ;

	for (;;)
		{
		for (k = 0; k < ENTRIES(testcase); k++)
			{
			int decimal = testcase[k].decimal ;
			uint32_t before, after, cycles ;

			// convert to a binary array
            before = GetClockCycleCount() ;
			Dec2Bin(decimal, binary) ;
            after  = GetClockCycleCount() ;
            cycles = after - before ;

			printf("   Test Case %d: %d\n", k+1, decimal) ;

			printf("Correct Result: ") ;
			PrintByte(decimal) ;
			printf("\n") ;

			printf("   Your Result: ") ;
			if (PrintBits(binary) != (uint8_t) decimal) printf(" %s", ERROR_FLAG) ;
			printf("\n") ;

			printf("  Clock Cycles: %lu\n\n", cycles) ;

			WaitForPushButton() ;
			}

		printf("Press button to start over.\n") ;
		WaitForPushButton() ;
		ClearDisplay() ;
		}
	}
