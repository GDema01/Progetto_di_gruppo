#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "globali.h"
#include "oggetti.h"
#include "varie.h"
#include "parser.h"

int vita = 3;

void get_inventario()
{
  int i = 0;
  int liberi = 0;
  
  printf("Nel tuo inventario hai:\n");

  while(i < DIMENSIONE_INVENTARIO)
  {
    if(inventario[i] != -1)
    {
      printf("- %s\n", get_oggetto(inventario[i])->nome);
    }
    else
      liberi++;
    i++;
  }
  printf("Puoi prendere ancora %d oggetti.\n ", liberi);
}


void guida()
{
  printf("Apertura file Guida:\n ");
  //apertura del file
}


void perdi_vita()
{
  printf("Perdi una vita!\n");
  vita--;
	if(vita<=0)  
	{
		printf("l avventura e terminata");
    analizza_ed_esegui("esci");
	}
}


void guadagna_vita()
{
  printf("Hai guadagnato una vita!\n");
  vita++;
}


int scegliere_difficolta()
{
	int identificatore;
	printf("scegliere la difficolta,inserendo il numero \n");
	printf("1:");
	printf("difficolta normale\n");
	printf("2:");
	printf("difficolta difficile \n");
	scanf("%d",&identificatore);	
	return identificatore;
}


int verifica_scelta(int identificatore)
{
	if(identificatore == 1)
	{
		vita = 2;
	}
	else if(identificatore == 2)
	{
		vita = 1;
	}
	else
	{
    while(identificatore < 1 || identificatore > 2)
    {
      printf("inserire una difficolta valida \n");
      scanf("%d",&identificatore);
    }
	}
  return vita;
}

void lower_string(char s[]) {
   int c = 0;
   while (s[c] != '\0') {
      if (s[c] >= 'A' && s[c] <= 'Z') {
         s[c] = s[c] + 32;
      }
      c++;
   }
}
/*void apri_mappa()
{
	FILE *fp;
	char mappa[100];
	fp=fopen("mappa.txt","r");
	fscanf(fp,%s,mappa);
}
void apri_mappa()
{
	FILE *fp;
	char guida[100];
	fp=fopen("guida.txt","r");
	fscanf(fp,%s,guida);
}*/


