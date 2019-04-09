/*lista jednokierunkowa, dodawanie i usuwanie  z listy jednokierunkowej*/
#include <stdio.h>
struct Elist* dodaj_elem2(struct Elist *q, int x);
struct Elist
	{
    int klucz;
    struct Elist * nast;
	};
 
struct Elist* dodaj_elem(struct Elist *q, int x);
struct Elist* usun_elem(struct Elist *q, int x);
void drukuj_liste(struct Elist *q);
 
struct Elist* dodaj_elem(struct Elist *q, int x)
	{
    struct Elist *pom;
    pom=(struct Elist*)malloc(sizeof(struct Elist));
    pom->klucz=x;
    pom->nast=q;
    q=pom;
    return q;
	}
 
struct Elist* usun_elem(struct Elist *q, int x)
	{
    struct Elist *pom, *tmp;
    pom=q;
    while (pom !=NULL && pom->klucz!= x)
	{
        tmp=pom;
    pom=pom->nast;
    }
    if(pom!=NULL)
	{
        if (pom == q)
            q=pom->nast;
        else
            tmp->nast=pom->nast;
        free(pom);
    }
    else
    	printf("Elementu %d nie ma w liscie", x);
    return q;
	}
void drukuj_liste(struct Elist* q)
	{
    struct Elist *pom;
    int i=0;
    pom=q;
    while(pom != NULL){
        printf("\nnr %d: %d",++i,pom->klucz);
        pom = pom->nast;
    }
}
struct Elist* dodaj_elem2(struct Elist *q, int x)
	{
    struct Elist *pom;
    pom=(struct Elist*)malloc(sizeof(struct Elist));
    pom->klucz=x;
    pom->nast=q;
    q=pom;
    return q;
	} 
int main(void)
	{
    int i, x, wyb;
    struct Elist* glowa=NULL;
    for(i=0;i<5; i++)
        glowa=dodaj_elem(glowa, i);
    printf("Chcesz dodac czy odjac?\n1.Dodaj\n2.Odejmij\n");
    scanf("%d", &wyb);
    if(wyb==1)
    	{
    	printf("\nPodaj wartosc:");
    	scanf("%d", &i);
    	glowa=dodaj_elem(glowa, i);
    	}
    if(wyb==2)
		{
    	if(glowa!=NULL)
			{
	        printf("\nElementy listy:");
	        drukuj_liste(glowa);
	        printf("\nPodaj element (wartosc) do usuniecia: ");
	        scanf("%d", &x);
	        glowa=usun_elem(glowa, x);
			}
	    else
        	printf("Lista pusta");
		}	
    drukuj_liste(glowa);
    return 0;
	}