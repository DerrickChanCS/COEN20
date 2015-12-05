#include <stdio.h>
#include <stdint.h>

#define ENTRIES(a) (sizeof(a)/sizeof(a[0]))

extern void SubBinary(int a[8], int b[8], int c[8]) ;

void PrintBits(int binary[8]){
	int i = 0;
	for(;i<8; i++){
		printf("%d", binary[7-i]);
	}
}

void PrintByte(int num){
	int i = 0;
	for(;i<8; i++){
		printf("%d", num & (1<<(7-i))?1:0);
	}
}

int main(void)
	{
	static struct {int a[8], b[8], diff ; } testcase[] =
		{
		{{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,1},0},
		{{1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0},-2},
		{{1,0,1,0,1,0,1,0},{1,0,1,0,1,0,1,0},0},
		{{1,1,0,1,0,0,0,0},{0,1,1,0,1,1,1,1},21},
		{{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},-85}
		} ;
	int k ;


		for (k = 0; k < ENTRIES(testcase); k++)
			{
			int *a = testcase[k].a ;
			int *b = testcase[k].b ;
			int sum[8] ;
			uint32_t before, after, cycles ;

			printf(" Test Case %d: \n", k+1) ;
			PrintBits(a) ;
			printf("\n") ;
			PrintBits(b) ;
			printf("\n") ;

			printf("   Correct Sum: \n") ;
			PrintByte(testcase[k].diff);
			printf("\n") ;

			SubBinary(a, b, sum) ;

			printf("      Your Sum: \n") ;
			PrintBits(sum);
			printf("\n") ;

			printf("\n") ;

			}

		}

