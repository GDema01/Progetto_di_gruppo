#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "luoghi.h"
#include "oggetti.h"
#include "personaggi.h"
#include "varie.h"
#include "globali.h"

//FUNZIONE CONFRONTA OGGETTO
int confronta_oggetto(char *nome)
{
	int ogg_id = -1;
	int i = 0;
  while (i < NUM_OGGETTI)
  {
    if (strcmp(nome, oggetti[i].nome) == 0)
    {
      ogg_id = oggetti[i].id;
    }
    i++;
  }
  return ogg_id;  
}

bool analizza_ed_esegui(char *input)
{
  char *verbo = strtok(input, " \n");
  char *nome = strtok(NULL, " \n");
  
  if (verbo != NULL)
  {
    lower_string(verbo);
    if (strcmp(verbo, "esci") == 0)
    {
      return false;
    }
		else if (strcmp(verbo, "mappa") == 0)
    {
      //aprire_mappa();
    }
		else if (strcmp(verbo, "guida") == 0)
    {
      //aprire_guida();
    }
    else if (strcmp(verbo, "guarda") == 0)
    {
      guarda(nome);
    }
    else if (strcmp(verbo, "interagisci") == 0)
    {
      //funzione per interagire
    }
    else if (strcmp(verbo, "inventario") == 0)
    {
      get_inventario();
    }
    else if (strcmp(verbo, "guida") == 0)
    {
      // apri guida
    }
		else if (strcmp(verbo, "mappa") == 0)
		{
			//aprire_file();
		}
    else if (strcmp(verbo, "pos") == 0)
    {
      printf("TEST POS_GIOCATORE: %d\n", pos_giocatore);
    }
    else if (strcmp(verbo, "ouch") == 0)
    {
      perdi_vita();
      printf("TEST VITA: %d\n", vita);
    }
    else if (nome != NULL)
    {
      int ogg_id = confronta_oggetto(nome);
      lower_string(nome);
      if (strcmp(verbo, "vai") == 0)
      {
        if (strcmp(nome, "nord") == 0)
          esegui_spostati(NORD);
        else if (strcmp(nome, "est") == 0)
          esegui_spostati(EST);
        else if (strcmp(nome, "sud") == 0)
          esegui_spostati(SUD);
        else if (strcmp(nome, "ovest") == 0)
          esegui_spostati(OVEST);
        else
          printf("Non capisco dove vuoi andare\n");
      }
      else if (ogg_id != -1)
      {
        if (strcmp(verbo, "prendi") == 0)
        {
          esegui_prendi(ogg_id);
        }
        else if (strcmp(verbo, "lascia") == 0)
        {
          esegui_lascia(ogg_id);
        }
        else if (strcmp(verbo, "ispeziona") == 0)
        {	
          esegui_ispeziona(ogg_id);
        }
        else if (strcmp(verbo, "usa") == 0)
        {
          esegui_usa(ogg_id);
        }
        else if (strcmp(verbo, "colpisci") == 0)
        {
          esegui_colpisci(ogg_id);
        }
        else if (strcmp(verbo, "dai") == 0)
        {
          esegui_dai(ogg_id, CUSTODE); // CAMBIARE
        }
        else
        {
          printf("Non capisco: %s\n", verbo);
        }
      }
      else
      {
        printf("Non capisco: %s %s\n", verbo, nome);
      }
    }
    else
    {
      printf("Non capisco: %s\n", verbo);
    }
  }
  return true;
}