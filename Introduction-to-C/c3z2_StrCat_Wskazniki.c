#include <stdio.h>
/*funkcja StrCat(char s1[], char s2[]) lancuch znakowy S1 i S2, dolaczenie s1 do s2 na wskaznikach*/
int StrCat1(char* s1, char* s2);
int main(void)
{
	char s1[20] = "ALA";
	char s2[10] = "MA KOTA";
	printf("%s %s", s1, s2);
	StrCat1(s1, s2);
	printf("\n%s", s1);
	return 0;
}

int StrCat1(char* s1, char* s2)
{
	int i = 0, j = 0;
	while(*(s1+i)!='\0') 
		i++;
	while(*(s2+j)!='\0') 
		*(s1 + i++)= *(s2 + j++ );
	*(s1+i) = '\0';
		
}