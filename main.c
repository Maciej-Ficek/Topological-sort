#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 1000

void Error ()
{
    printf("Nie udalo sie.");

}
//implementacja kolejki
int tabqu [ MAXQUEUE+1 ];
int fr, en;
void InitQueue ( void )
{
fr = en = 0;
} /*InitQueue*/
void Enqueue ( int el )
{
tabqu[en++] = el;
if ( en > MAXQUEUE ) en = 0;
if ( en == fr ) Error ();
} /*Enqueue*/
void Dequeue ( int *el )
{
if ( fr != en ) {
*el = tabqu[fr++];
if ( fr > MAXQUEUE ) fr = 0;
}
else Error ();
} /*Dequeue*/
char QueueEmpty ( void )
{
return fr == en;
} /*QueueEmpty*/


typedef struct kraw {
int koniec;
struct kraw *pocz;
struct kraw *nast;
}kraw, *pkraw;




void InicjalizujListe (kraw l, pkraw p)
{p=&l;
p->pocz=NULL;
p->nast=NULL;
} /*InicjalizujListe*/

void WstawNaPoczatek ( int j, kraw l, pkraw p)
{
p=&l;
p->koniec = j;
p->nast = p->pocz;
p->pocz=p;
} /*WstawNaPoczatek*/

int MalyGraf (int n)
{
    if(n==0||n==1)
        {printf("Twoj graf ma %d wierzcholkow i jest posortowany.\n",n);
return 1;}
else return 0;
}
int UjemnaLiczba ( int n)
{
    if(n<0.0)
     {printf("Plik wskazuje na ujemna liczbê wierzcholkow.\n Popraw go i uruchom"
               "program ponownie.");
    return 1;}
    else return 0;
}

int ZredukujLiczniki(kraw l, pkraw p,int tab[])
{
    p=&l;
    if(p->pocz==NULL){printf("lista pusta.");return 0;}
    if(p->nast==NULL){tab[p->koniec]--;return 0;}

   // while(p->nast!=NULL)
    //   {
     //   tab[p->koniec]--;
     //   p=p->nast;}
return 0;
}

int main()

{


int i;

int j;

int LW;

int odp;

int wybor;

int krawedz;


FILE *Graf;
printf("1. Wczytaj z pliku. 2. Wczytaj z klawiatury.");
do
{       scanf("%d",&wybor);


if(wybor!=1&&wybor!=2)
    printf("Zly wybor. zdecyduj jeszcze raz.");}

while (wybor!=1&&wybor!=2);


switch(wybor)
{


case 1:
{


Graf = fopen("Graf.txt", "r+");
fscanf(Graf,"%d",&LW);

if(MalyGraf(LW)) return 0;
if(UjemnaLiczba(LW)) return 0;

printf("Twoj graf wczytany z pliku ma %d wierzcholkow.\n",LW);


int licznik[LW];
kraw Lista[LW];
    pkraw p;
for(i=0;i<LW;i++)
{licznik[i]=0;
    InicjalizujListe(Lista[i], p);
    printf("%d\n",licznik[i]);
}



for(i=0;i<LW;i++)
  {
      for(j=0;j<LW;j++)
    {fscanf(Graf,"%d",&krawedz);
    if(krawedz>0){;WstawNaPoczatek(j, Lista[i], p);licznik[j]++;}
  }
  }
  fclose(Graf);
  for(i=0;i<LW;i++)
{

    if(licznik[i]==0)break;
    if(i==LW-1){printf("Nie istnieje wierzcholek, do ktorego \n"
                      "nie wchodzi zadna krawedz. Nie da sie \n"
                      "posortowac topologicznie.\n"); return 0;}
}


  printf("Liczniki maja teraz wartosc:\n");
for(i=0;i<LW;i++)
{
    printf("%d: %d\n",i,licznik[i]);
}

//sortowanie

for(i=0;i<LW;i++)
{
       if(licznik[i]==0)
       {Enqueue(i);
       licznik[i]=-5;}

}

int k=0;
while(!QueueEmpty())
  {Dequeue(&tabqu[k]);
  p=&Lista[tabqu[k]];
  printf("%d%d",tabqu[k],p->koniec);

  k++;

  if(p->nast==NULL)licznik[p->koniec]--;
  else {
   while(p->nast!=NULL)
  {
      licznik[p->koniec]--;
       p=p->nast;
}

  for(i=0;i<LW;i++)
{
       if(licznik[i]==0){Enqueue(i); licznik[i]=-5;}


}
  }
  }



  printf("Jestem tu.");


break;
}//koniec case1
case 2:
{

    printf("Podaj prosze nieujemna liczbe wierzcholkow\n");
    do{ scanf("%d",&LW);
    if(LW<0.0)
        printf("Wprowadz liczbe wierzcholkow jeszcze raz.");
            }while(LW<0.0);

int licznik[LW];
kraw Lista[LW];
pkraw p;
for(i=0;i<LW;i++)
{
    licznik[i]=0;
    InicjalizujListe(Lista[i], p);
    printf("%d\n",licznik[i]);
}

    if(MalyGraf(LW))return 0;
    for(i=0;i<LW;i++)
    for(j=0;j<LW;j++)
        {
        printf("Czy z %d wychodzi krawedz do %d?\n",i,j);
        do{
            scanf("%d",&odp);

            if(odp!=0&&odp!=1)
            printf("Podaj prosze odpowiedz jeszcze raz.\n"
                   "Czy z %d wychodzi krawedz zakonczona w %d?\n",i,j);
        }
        while(odp!=0&&odp!=1);
        if(odp==1){WstawNaPoczatek(j, Lista[i], p);licznik[j]++;}

        }

for(i=0;i<LW;i++)
{
    if(licznik[i]==0)break;
    if(i==LW-1){printf("Nie istnieje wierzcholek, do ktorego \n"
                      "nie wchodzi zadna krawedz. Nie da sie \n"
                      "posortowac topologicznie."); return 0;}
}

printf("Liczniki maja teraz wartosc:\n");
for(i=0;i<LW;i++)
{printf("%d:%d\n",i,licznik[i]);

}

//sortowanie

for(i=0;i<LW;i++)
{
       if(licznik[i]==0)
       {Enqueue(i);
       licznik[i]=-5;}

}

int k=0;
while(!QueueEmpty())
  {Dequeue(&tabqu[k]);
  p=&Lista[tabqu[k]];
  printf("%d%d",tabqu[k],p->koniec);

  k++;

  if(p->nast==NULL)licznik[p->koniec]--;
  else {
   while(p->nast!=NULL)
  {
      licznik[p->koniec]--;
       p=p->nast;
}

  for(i=0;i<LW;i++)
{
       if(licznik[i]==0){Enqueue(i); licznik[i]=-5;}


}
  }
  }
 // ZredukujLiczniki(Lista[Tablica[k]],p,licznik);

break;}//koniec case2
}//Koniec switcha

    return 0;
}
