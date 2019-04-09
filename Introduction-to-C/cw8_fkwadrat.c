#include <stdio.h>
funkcja(FILE *plik2, float a, float b, float c, float x1, float x2, float k);
int funkcja2(FILE *plik2);

int main(int argc, char *argv[] )
{
	float a, b, c, x1, x2, k;
	
	FILE *plik2; 
	printf("Podaj a:\n"); scanf("%f", &a);
	printf("\nPodaj b:\n"); scanf("%f", &b);
	printf("\nPodaj c:\n"); scanf("%f", &c);
	printf("\nPodaj poczatek zakresu x:\n"); scanf("%f", &x1);
	printf("\nPodaj koniec zakresu x:\n"); scanf("%f", &x2);
	printf("\nPodaj ilosc krokow:\n"); scanf("%f", &k);
	plik2 = fopen("wyniki.bin", "wb");
	
	funkcja(plik2, a, b, c, x1, x2, k);
	funkcja2(plik2);
}

int funkcja(FILE *plik2, float a, float b, float c, float x1, float x2, float k)
{
	float wynik, temp, krok;
	int i, j;
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

int funkcja2(FILE *plik2)
{
	float k;
	int i, j;
	float x1, wynik;
	plik2=fopen("wyniki.bin", "rb");	
	fread(&k, sizeof(float), 1, plik2);
	printf("n   x      y\n");
	for(i = 1; i <= k; i++)
		{
			fread(&x1, sizeof(float), 1, plik2);
			fread(&wynik, sizeof(float), 1, plik2);
			printf("%d %.2f %f\n", i, x1, wynik);
		}
	
	fclose(plik2);
}