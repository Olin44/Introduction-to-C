#include <stdio.h>
#include <string.h>
/*napisz funkcj StrEdn(s1, s2) przyjmuj±ca wartosci s1 i s2 jesli tekst w s2 wystepuje na koncu teksty s1 zwraca 1 w przeciwnym wypadku zwraca 0 */
int StrEnd(char s1[], char s2[]);
int main(void)
{
	char s1[20] = "Ala ma kota";
	char s2[10] = "kota";
	char s3[10] = "psa";
	printf("Lancuch 1: %s \nLancuch 2: %s\nLancuch 3: %s", s1, s2, s3);
	printf("\nWynik dla lancucha 1 i 2: %d", StrEnd(s1, s2));
	printf("\nWynik dla lancucha 1 i 3: %d", StrEnd(s1, s3));
    return 0;
	
}

int StrEnd(char s1[], char s2[])
{
	int i = 0, j = 0;
	while(s2[i]!='\0') i++;
	while(s1[j]!='\0') j++;
	while(i >= 0)
	{
	   if(s1[j]!=s2[i])
	        return 0;
	    i--;
	    j--;
	}
	return 1;
}