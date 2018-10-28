
#ifndef _INTEGRAL_H_


#ifndef DBL_MIN
#define DBL_MIN          2.2250738585072014e-308

#endif 

#ifndef NAN
#define _HUGE_ENUF  1e+300
#define INFINITY   ((float)(_HUGE_ENUF * _HUGE_ENUF))
#define NAN        ((float)(INFINITY * 0.0F))
#endif


double dIntegral(double(*func)(double x), double from, double to, double step);

double SinPlusCos(double x);

double SinDivideId(double x);

double SecMultiplyId(double x);

double SqareId(double x);


#define _INTEGRAL_H_
#endif