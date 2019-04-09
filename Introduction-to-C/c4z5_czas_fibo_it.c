#include <stdio.h>
#include <time.h>
/* iteracyjny fibo*/
double fib_it(int n);
int main(void)
{
	unsigned i=30;
	for(i; i <= 46; i++)
		printf("%d wyraz fibo z to: %.0f Od startu zegara uplynelo %lf sekund\n", i, fib_it(i), (clock ()/(float)CLOCKS_PER_SEC));
}


double fib_it(int n)
{
	int i;
	double a = 0;
	double b = 1;
	double wynik = 0;
	if(n == 0) 	return 0;
	if(n == 1)	return 1;
	for(i=0; i < n-1; i++)
		{
			wynik = a + b;
			a = b;
			b = wynik;
		}
	return wynik;		
}