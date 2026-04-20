#include<stdio.h>

double sumaValoare(float a, float b)
{
	double s = 0;
	s = a + b;
	return s;
}

int main()
{
	int i = 4568;
	double (*pSumVal)(float, float);
	pSumVal = sumaValoare;
	printf("\nAdresa(pSumaVal) = %p, Continut(pSumaVal) = %p\n", &pSumVal, pSumVal);
	double c = pSumVal((float)i + 1, (float)i + 2);
	printf("c = %lf\n", c);
	pSumVal = &sumaValoare;
	c = pSumVal(i + 1, i + 2);
	printf("c = %lf\n", c);
	return 0;
}