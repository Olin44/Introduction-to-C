//*wpisz abc, wpisz zakres, ile wartosci funkcji, ilosc krokow, wartosc xy do pliku tekstowego*/
#include <stdio.h>
int funkcja(void);
int main(void)
{
	funkcja();
}

int funkcja(void)
{
	float a, b, c, x1, x2, k, wynik, temp, krok;
	int i;
	FILE *plik; 
	printf("Podaj a:\n"); scanf("%f", &a);
	printf("\nPodaj b:\n"); scanf("%f", &b);
	printf("\nPodaj c:\n"); scanf("%f", &c);
	printf("\nPodaj poczatek zakresu x:\n"); scanf("%f", &x1);
	printf("\nPodaj koniec zakresu x:\n"); scanf("%f", &x2);
	printf("\nPodaj ilosc krokow:\n"); scanf("%f", &k);
	plik = fopen("wyniki.txt", "w"); 
	if(x2 < x1)
		{
			temp = x2;
			x2 = x1;
			x1 = temp;
		}
	fprintf(plik, "Dla a = %.0f, b = %.0f, c = %.0f\nW zakresie %.0f do %.0f\nIlosc krokow %.0f\nn x y\n", a, b, c, x1, x2, k);
	krok = (x2 - x1)/k;
	for(i=0; i <= k-1; i++)
		{
				{
				wynik = a*(x1*x1) + b*x1 + c;
				fprintf(plik, "%d %.2f %f\n", i+1, x1, wynik);
				x1 += krok;
				}
		}
	fclose(plik);
	return 0;
}