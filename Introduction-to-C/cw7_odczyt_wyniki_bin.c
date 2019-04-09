#include <stdio.h>
int main(void)
{
	float k;
	int i, j;
	float x1, wynik;
	FILE *plik2;
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