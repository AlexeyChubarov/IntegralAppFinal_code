#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include "Integral.h"
 
#define eps (DBL_MIN)

double dIntegral(double(*func)(double x), double from, double to, double step)
{
	int n, id_sign;
	double integral_summ, change;

	integral_summ = 0.;
	change = 0.;

	if (abs(step) < eps)
	{
		fprintf(stderr, "sorry, you divide on zero (number nearby zero).\n");
		return NAN;
	}

	if (step < 0)
	{
		fprintf(stderr, "sorry, you have written down step<0. It has no physical sense.\n");
		return NAN;
	}
	
 
	if ((abs(to - from) / step) > INT_MAX)
	{
		fprintf(stderr, "sorry, you have faced integer overflow.\n");
		return NAN;
	}

	id_sign = 1;

	if ((from - to)>=eps)
	{ 
		id_sign = -1;

		change = to;
		to = from;
		from = change;
	}

	n = (int)((to - from) / step);

	for (int i = 1; i < n; i++)
	{
		integral_summ += (*func)(from + i * step);
	}
	integral_summ = id_sign * (integral_summ + ((*func)(from) + (*func)(to)) / 2.)*step;
	return integral_summ;
}

