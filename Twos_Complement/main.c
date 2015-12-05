#include <stdio.h>
#include <stdint.h>
#include "library.h"

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

void TwosComp(int input[8], int output[8]) ;

int main(void)
	{
	static struct {int bin[8]; int8_t old; int8_t new;} testcase[] =
		{
		{{0,0,0,0,0,0,0,0},0,0},
		{{1,0,0,0,0,0,0,0},1,-1},
		{{1,1,1,1,1,1,1,1},-1,1},
		{{0,0,0,0,0,0,0,1},-128,-128},
		{{1,1,1,1,1,1,1,0},127,-127}
		} ;
	int k ;

	InitializeHardware(HEADER, PROJECT_NAME) ;

	for (;;)
		{
		for (k = 0; k < ENTRIES(testcase); k++)
			{
			int *input = testcase[k].bin ;
			int old = testcase[k].old ;
			int new = testcase[k].new ;
			uint32_t before, after, cycles ;
			int output[8] ;

            before = GetClockCycleCount() ;
			TwosComp(input, output) ;
            after  = GetClockCycleCount() ;
            cycles = after - before ;

			printf("   Test Case %d: ", k+1) ;
			PrintBits(input) ;
			printf(" (%d)\n", old) ;

			printf("Correct Result: ") ;
			PrintByte(new) ;
			printf(" (%d)\n", new) ;

			printf("   Your Result: ") ;
			if (PrintBits(output) != (uint8_t) new) printf(" %s", ERROR_FLAG) ;
			printf("\n") ;

			printf("  Clock Cycles: %lu\n\n", cycles) ;

			WaitForPushButton() ;
			}

		printf("Press button to start over.\n") ;
		WaitForPushButton() ;
		ClearDisplay() ;
		}
	}
