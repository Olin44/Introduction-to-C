#include <stdio.h>

//napisac aplikacje, która utworzy tablice 2 wymiarowa, wyswietli ja i wyswietli liczby na przekatnej(zrealizowane na wskaźnikach)//

int main(void)
{
	int tab[3][3] = {{6,2,3}, {1,6,3}, {1,5,3}};
	int i,j;
	for(i=0; i < 3; i++)
	{
		for(j=0; j < 3; j++)
			printf("%d ", *(*(tab+i)+j));
		printf("\n");	
	}
	printf("\nPrzekatna:\n");
	for(i=0; i < 3; i++)
	{
		for(j=0; j < 3; j++)
			if(i==j)
				printf("%d ", *(*(tab+i)+j));
	}
	return 0;
}