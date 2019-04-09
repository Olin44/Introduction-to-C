#include <stdio.h>
#include <stdlib.h>
/*uzytkownik ma podac rozmiar tablicy, zalokowac pamiec oraz wpisac wartosci podane przez uzytkownika*/

int main(void)
{
	int n, j;
	int *tab;
	printf("Podaj dlugosc tablicy: ");
	scanf("%d", &n);
	tab=(int *) malloc( n * sizeof(int));
	for(j=0; j < n; j++)
	{
		printf("Podaj %d element tablicy: ", j+1);
		scanf("%d", &(*(tab+j)));
	}
	printf("\nTwoja tablica: ");
	for(j=0; j < n; j++)
			printf("%d ", *(tab+j));
	free(tab);
	return 0;
}