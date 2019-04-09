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
	int i, j;
	FILE *plik2; 
	printf("Podaj a:\n"); scanf("%f", &a);
	printf("\nPodaj b:\n"); scanf("%f", &b);
	printf("\nPodaj c:\n"); scanf("%f", &c);
	printf("\nPodaj poczatek zakresu x:\n"); scanf("%f", &x1);
	printf("\nPodaj koniec zakresu x:\n"); scanf("%f", &x2);
	printf("\nPodaj ilosc krokow:\n"); scanf("%f", &k);
	plik2 = fopen("wyniki.bin", "wb");
	if(x2 < x1)
		{
			temp = x2;
			x2 = x1;
			x1 = temp;
		}
	krok = (x2 - x1)/k;
	fwrite(&k, sizeof(float), 1, plik2);
	for(i=0; i <= k; i++)
		{
				{
				j = i+1;	
				wynik = a*(x1*x1) + b*x1 + c;
				fwrite (&x1, sizeof (float), 1, plik2);
				fwrite (&wynik, sizeof (float), 1, plik2);
				x1 += krok;
				}
		}
	
	fclose(plik2);
	return 0;
}