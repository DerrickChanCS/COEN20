#include <stdio.h>
#include <stdint.h>
#include "library.h"

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

unsigned int Bin2Unsigned(int binary[8]) ;
  signed int Bin2Signed(int binary[8]) ;

int main(void)
	{
	static struct {int bin[8]; unsigned u; signed s;} testcase[] =
		{
		{{0,0,0,0,0,0,0,0},0,0},
		{{1,0,0,0,0,0,0,0},1,1},
		{{0,1,1,1,1,1,1,1},254,-2},
		{{0,0,0,0,0,0,0,1},128,-128},
		{{1,1,1,1,1,1,1,0},127,127},
		{{1,1,1,1,1,1,1,1},255,-1}
		} ;
	int k ;

	InitializeHardware(HEADER, PROJECT_NAME) ;

	for (;;)
		{
		for (k = 0; k < ENTRIES(testcase); k++)
			{
			int *binary = testcase[k].bin ;
			uint32_t before, after, cycles ;
			int8_t s ;
			uint8_t u ;

            before = GetClockCycleCount() ;
			s = Bin2Signed(binary) ;
			u = Bin2Unsigned(binary) ;
            after  = GetClockCycleCount() ;
            cycles = after - before ;

			printf("   Test Case %d: ", k+1) ;
			PrintBits(binary) ;
			printf("\n") ;

			printf("Correct Result: %d (%uu)\n", testcase[k].s, testcase[k].u) ;

			printf("   Your Result: %d (%uu)", s, u) ;
			if (s != testcase[k].s || u != testcase[k].u) printf(" %s", ERROR_FLAG) ;
			printf("\n") ;

			printf("  Clock Cycles: %lu\n\n", cycles) ;

			WaitForPushButton() ;
			}

		printf("Press button to start over.\n") ;
		WaitForPushButton() ;
		ClearDisplay() ;
		}
	}
