#include <stdio.h>
/* rekurencyjny fibo*/
double fib_rek(int n);
{
	int n;
	printf("Wprowadz n: ");
	scanf("%d", &n);
	printf("%d wyraz fibo z to: %.0f", n, fib_rek(n));
}

double fib_rek(int n)
{
	if(n==0) 	return n;
	if(n==1)	return n;
	return fib_rek(n-1) + fib_rek(n-2);
}
