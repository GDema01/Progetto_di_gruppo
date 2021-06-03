#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "globali.h"
#include "luoghi.h"
#include "personaggi.h"

void stampa_personaggi_stanza(int luog_id)
{
  int i = 0;
  while(i < NUM_PERSONAGGI)
  {
   if(luog_id == personaggi[i].luogo)
   {
     printf("- %s\n", personaggi[i].nome);
   }
   i++;
  }
}


int interagisci(int pers_id)
{
  int codice_caso;
	personaggio *pers = get_personaggio(pers_id);
  printf("TEST NOME PERS: %s\n", pers->nome);
  printf("GIOC: %d PERS: %d\n", pos_giocatore, pers->luogo);
  if (pos_giocatore == pers->luogo)
  {
    codice_caso = 2;
    if (pers->id == CUSTODE && pers->vincolo == false)
    {
      printf("%s\n",pers->interazione_base);
      printf("Immetti soluzione: ");
      char soluz[20];
      scanf("%s", soluz);
      if (strcmp(soluz, NOME_VERO_CUSTODE) == 0)
      {
        codice_caso = 0;
        aggiorna_luoghi_adiacenti(PONTE, EST, SALONE);
        pers->vincolo = true;
        pers->interazione_base = "adesso puoi procedere";
      }
      else
        codice_caso = 1;
    }
    else if (pers->id == SPETTRO && pers->vincolo == false)
    {
      printf("TEST INTERAGISCI");
      if (strcmp("", SOLUZIONE_INDOVINELLO) == 0)
      {
        codice_caso = 0;
        aggiorna_luoghi_adiacenti(CORRIDOIO, SUD, SEGRETE);
        pers->vincolo = true;
        pers->interazione_base = "adesso puoi procedere";
      }
      else
        codice_caso = 1;
    }
  }
  else
  {
    printf("TEST NON VEDI PERSONA\n");
    codice_caso = 3;
  }
  return codice_caso;
}



void esegui_interagisci(int pers_id)
{
	personaggio *pers = get_personaggio(pers_id);
	int codice_caso;
	codice_caso = interagisci(pers_id);
	if(codice_caso == 0)
	{
		printf("%s\n", pers->interazione_base);
		printf("%s\n", pers->interazione_giusta);
	}
	else if(codice_caso == 1)
	{
		printf("%s\n", pers->interazione_sbagliata);
		printf("%s\n", pers->interazione_base);
	}
	else if(codice_caso == 2)
	{	
		printf("%s\n", pers->interazione_base);	
	}
	else
	{	
		printf("non vedi questa persona\n");	
	}
}
