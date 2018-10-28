#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include "Integral.h"

#define k (4) 
#define MAX(A,B) ((A > B) ? A : B)
#define MIN(A,B) ((A < B) ? A : B)

int main()
{
	const int m = 14;
	typedef double(*funcp)(double);
	
	int i;
	double a[5], b[5], delta[5];
	funcp funcArray[3] = { SinPlusCos, SinDivideId, SecMultiplyId }; 
	char * funcName[3] = { "sin(x)+cos(x)","sin(x)/x","sec(x)*x" };
	
	for (i = 0; i <= k; i++)
	{
		printf("please, enter the limits of integration:\t");
		scanf_s("%lf %lf", &a[i], &b[i]);
		getchar();

		printf("please, enter the integration accuracy: \t");
		scanf_s("%lf", &delta[i]);
		getchar();
	}

	printf("computing, please, be patient :))\n");

	printf("Your results: \n");

	for (i = 0; i <= m; i++)
	{
		printf("f(x)= %s on [%lf;%lf] equal % +12lf\n", funcName[i/5], MIN(a[i % 5], b[i % 5]), MAX(a[i % 5], b[i % 5]), dIntegral(funcArray[i/5], a[i%5], b[i%5], delta[i%5]));
		fflush(stdout);
	}

	system("pause");
	return 0;
}