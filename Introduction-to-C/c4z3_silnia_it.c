#include <stdio.h>
/* iteracyjny fibo*/
double fib_it(int n);
int main(void)
{
	int n;
	printf("Wprowadz n: ");
	scanf("%d", &n);
	printf("%d wyraz fibo z to: %.0f", n, fib_it(n));
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