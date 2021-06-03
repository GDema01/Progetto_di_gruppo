#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "globali.h"
#include "oggetti.h"
#include "personaggi.h"
#include "varie.h"
#include "luoghi.h"

int pos_giocatore = 0;

luogo *get_luogo(int luog_id)
{
  luogo *luog = NULL;
  int i = 0;
  bool trovato = false;
  while (i < NUM_LUOGHI && trovato == false)
  {
    if (luog_id == luoghi[i].id)
    {
      luog = &luoghi[i];
      trovato = true;
    }
    i++;
  }
  return luog;
}


void esegui_ispeziona(int ogg_id)
{
	oggetto *ogg = get_oggetto(ogg_id);
	if(ogg->luogo == -1 || ogg->luogo == pos_giocatore)
	{	
		printf("%s\n", ogg->descrizione);
	}
	else
	{
		printf("non vedi nulla del genere\n");
	}
}

void guarda()
{
  printf("ti trovi in:\n");
  printf("%s\n", get_luogo(pos_giocatore)->descrizione);
  printf("vedi:\n");
  stampa_oggetti_stanza(pos_giocatore);
  stampa_personaggi_stanza(pos_giocatore);
}

void esegui_spostati(int direzione)
{
  int codice_caso = spostati(direzione);
  if(codice_caso == 0)
  {
    printf("La tua posizione attuale è: %s\n", get_luogo(pos_giocatore)->nome);
  }
  else if(codice_caso == 1)
  {
    printf("Non conosco quella direzione\n");
  }
  else if(codice_caso == 2)
  {
    esegui_interagisci(CUSTODE);
  }
  else if(codice_caso == 3)
  {
    printf("Vedi una porta chiusa a chiave con una nota attaccata sopra\n");
  }
  else if(codice_caso == 4)
  {
    esegui_interagisci(SPETTRO);
  }
  else if(codice_caso == 5)
  {
    printf("I pipistrelli ti attaccano!\n");
  }
  else if(codice_caso == 6)
  {
    printf("Vedi un passaggio segreto, ma e' chiuso...\n");
  }
  else if(codice_caso == 7)
  {
    printf("Hai tentato di attraversare le fiamme, ma sei diventato cenere!\n");
  }
  else
  {
    printf("Non puoi andare in quella direzione!\n");
  }

}

int spostati(int direzione)
{
  //printf("TEST SPOSTATI, POS GIOCATORE: %d\n", pos_giocatore);
  int codice_caso;
  codice_caso = -1;
  if(direzione > 3 || direzione < 0)
  {
    codice_caso = 1;
  }
  luogo *luogo_corrente;
	luogo_corrente = get_luogo(pos_giocatore);

  if(codice_caso == -1)
  {
    if(luogo_corrente->adiacenti[direzione] != -1)
    {
      pos_giocatore = luogo_corrente->adiacenti[direzione];
      printf("TEST SPOSTATI, POS GIOCATORE: %d\n", pos_giocatore);
      codice_caso = 0;
    }
    else if(pos_giocatore == PONTE  && direzione == EST)
    {
      codice_caso = 2;
    }
    else if(pos_giocatore == SALONE  && direzione == NORD)
    {
      codice_caso = 3;
    }
    else if(pos_giocatore == CORRIDOIO  && direzione == SUD)
    {
      codice_caso = 4;
    }
    else if(pos_giocatore == SEGRETE  && direzione != NORD)
    {
      perdi_vita();
      codice_caso = 5;
    }
    else if(pos_giocatore == SALA_TROFEI &&  direzione == EST)
    {
      codice_caso = 6;
    }
    else if(pos_giocatore == CAMERA_REALE  && direzione == SUD)
    {
      perdi_vita();
      codice_caso = 7;
    }
  }

  return codice_caso;
}

void aggiorna_luoghi_adiacenti(int id_partenza, int direzione, int id_arrivo)
{
  get_luogo(id_partenza)->adiacenti[direzione] = id_arrivo;
}