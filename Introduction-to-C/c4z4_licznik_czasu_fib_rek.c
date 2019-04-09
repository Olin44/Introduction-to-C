#include <stdio.h>
#include <time.h>
/* rekurencyjny fibo*/
double fib_rek(int n);
int main(void)
{
	unsigned i=30;
	for(i; i <= 46; i++)
		printf("%d wyraz fibo z to: %.0f Od startu zegara uplynelo %lf sekund\n", i, fib_rek(i), (clock ()/(float)CLOCKS_PER_SEC));
		
}

double fib_rek(int n)
{
	if(n==0 || n==1) return n; 
	return fib_rek(n-1) + fib_rek(n-2);
}