#include <stdio.h>
#include <stdint.h>
#include "library.h"

extern int32_t DiscrInASM(int32_t, int32_t, int32_t) ;

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

//This function computes and returns the discriminant.
int32_t DiscrInC(int32_t a, int32_t b, int32_t c)
	{
	return b*b - 4*a*c ;
	}

int main(void)
	{
	static struct { int32_t a, b, c ; } testcase[] =
		{
		{1,1,1},{-1,2,3},{1,3,-2}
		} ;
	int k ;

	InitializeHardware(HEADER, PROJECT_NAME) ;

	for (;;)
		{
		for (k = 0; k < ENTRIES(testcase); k++)
			{
			int32_t a = testcase[k].a ;
			int32_t b = testcase[k].b ;
			int32_t c = testcase[k].c ;
			int32_t result, answer = DiscrInC(a, b, c) ;
			uint32_t before, after, cycles ;

            before = GetClockCycleCount() ;
			result = DiscrInASM(a, b, c) ;
            after  = GetClockCycleCount() ;
            cycles = after - before ;

			printf("   Test Case %d: disc(%ld,%ld,%ld)\n", k+1, a, b, c) ;

			printf("Correct Result: %ld\n", answer) ;

			printf("   Your Result: %ld", result) ;
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
