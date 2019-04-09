#include <stdio.h>
#include <stdlib.h>
int funkcja(FILE *plik2, float a, float b, float c, float x1, float x2, float k);
int funkcja2(FILE *plik2);
int tekstowo(FILE *plik2, float a, float b, float c, float x1, float x2, float k);
int main(int argc, char *argv[] )
{
	float a, b, c, x1, x2, k;
	FILE *plik2; 
	
	if(argc == 1)
		{
			int wybor;
			printf("Chcesz zapisaæ wynik binarnie czy tekstowo? \n1.Binarnie\n2.Tekstowo"); scanf("%d", &wybor);
			printf("Podaj a:\n"); scanf("%f", &a);
			printf("\nPodaj b:\n"); scanf("%f", &b);
			printf("\nPodaj c:\n"); scanf("%f", &c);
			printf("\nPodaj poczatek zakresu x:\n"); scanf("%f", &x1);
			printf("\nPodaj koniec zakresu x:\n"); scanf("%f", &x2);
			printf("\nPodaj ilosc krokow:\n"); scanf("%f", &k);
			if(wybor == 1)
				{				
				plik2 = fopen("wyniki.bin", "wb");
				funkcja(plik2, a, b, c, x1, x2, k);
				funkcja2(plik2);
				}
			if(wybor ==2)
				{
				plik2 = fopen("wyniki.txt", "w"); 	
				tekstowo(plik2, a, b, c, x1, x2, k);
				}	
		}
	if(argc == 8)
		{
		if(strcmp(argv[7], "bin") == 0)
			{
			int i;
			plik2 = fopen("wyniki.bin", "wb");
			float arg[6];
			for (i=1; i < argc; i++)
				{		
				arg[i]= (float)atoi(argv[i]);
				printf ("Argument %d to: %f\n", i, arg[i]);
				}
			funkcja(plik2, arg[1], arg[2], arg[3], arg[4], arg[5], arg[6]);
			funkcja2(plik2);
			printf("kliknij enter, zeby zakonczyc");
			getch();
			}
		
		if(strcmp(argv[7], "txt") == 0)
			{
			int i;
			plik2 = fopen("wyniki.txt", "w");
			float arg[6];
			for (i=1; i < argc-1; i++)
				{		
				arg[i]= (float)atoi(argv[i]);
				printf ("Argument %d to: %f\n", i, arg[i]);
				}
			tekstowo(plik2, arg[1], arg[2], arg[3], arg[4], arg[5], arg[6]);
			}
		}
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
	krok = (x2 - x1)/(k-1);
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
int tekstowo(FILE *plik2, float a, float b, float c, float x1, float x2, float k)
{
	int i;
	float wynik, krok, temp;
	if(x2 < x1)
		{
			temp = x2;
			x2 = x1;
			x1 = temp;
		}
	fprintf(plik2, "Dla a = %.0f, b = %.0f, c = %.0f\nW zakresie %.0f do %.0f\nIlosc krokow %.0f\nn x y\n", a, b, c, x1, x2, k);
	krok = (x2 - x1)/(k-1);
	for(i=0; i < k; i++)
		{
				{
				wynik = a*(x1*x1) + b*x1 + c;
				fprintf(plik2, "%d %.2f %f\n", i+1, x1, wynik);
				x1 += krok;
				}
		}
	fclose(plik2);
	return 0;
}