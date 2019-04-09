#include <stdio.h>

//zamiana wierszy, uzytkownik podaje wiesze. ktore chce zamienić i na wskaznikach zamiana//
int wyswietlanie(int tab[3][3]);
int zamiana(int tab[3][3], int w1, int w2);
int main(void)
{
	int tab[3][3] = {{6,2,3}, {1,6,3}, {1,5,3}};
	int w1,w2;
	printf("Podaj numer(od 1 do 3) pierwszego wiesza do zamiany. ");
	scanf("%d", &w1);
	printf("Podaj numer(od 1 do 3) drugiego wiesza do zamiany. ");
	scanf("%d", &w2);
	printf("Tablica przed zamiana:\n");
	wyswietlanie(tab);
	zamiana(tab,w1-1,w2-1);
	printf("\nTablica po zamiana:\n");
	wyswietlanie(tab);
	return 0;
}

int wyswietlanie(int tab[3][3])
{
	int i,j;
	for(i=0; i < 3; i++)
	{
		for(j=0; j < 3; j++)
			printf("%d ", *(*(tab+i)+j));
		printf("\n");	
	}
}

int zamiana(int tab[3][3], int w1, int w2)
{
	int tab2[3];
	int i, j;
	for(i=0; i < 3; i++)
	{
		
		*(tab2 + i) = *(*(tab+w1)+i);
		*(*(tab+w1)+i) = *(*(tab+w2)+i);
		*(*(tab+w2)+i) = *(tab2 + i);
		
	}
		
}