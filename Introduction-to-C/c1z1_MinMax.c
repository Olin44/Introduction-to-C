#include <stdio.h>

int main(void){
	int n;
	int i;
	int tab[10];
	for(i=0; i < 10; i++){
		printf("Podaj liczbe:");
		scanf("%d", &n);
		tab[i] = n;
	}
	int min = tab[0];
	int max = tab[0];
	for(i = 0; i < 10; i++){
	if(tab[i] < min)
		min = tab[i];
	if(tab[i] > max)	
		max = tab[i];
}
	printf("Najmniejsza to: %d\n", min);
	printf("Najwieksza to: %d", max);
	
	return 0;
}