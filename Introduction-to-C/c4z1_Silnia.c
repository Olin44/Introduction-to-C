#include <stdio.h>
/* rekurencyjna silnia */
double silnia(int n);
int main(void)
{
	int n;
	printf("Wprowadz n: ");
	scanf("%d", &n);
	printf("Silnia z %d to: %.0f", n, silnia(n));
}

double silnia(int n)
{
	if (n == 0) return 1;
	return n * silnia (n-1);
}