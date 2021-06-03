#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "globali.h"
#include "varie.h"
#include "luoghi.h"
#include "personaggi.h"
#include "oggetti.h"

int inventario[DIMENSIONE_INVENTARIO] = {100, 101, -1, -1, -1};

int prendi(int ogg_id)
{
	int i;
	bool aggiunto;
	int codice_caso;
	oggetto *ogg;
	ogg = get_oggetto(ogg_id);
	if(ogg->luogo != pos_giocatore)
	{
		codice_caso=1;
	}
	else if(ogg->utilizzabile==false)
	{	
		codice_caso = 2;
	}
	else
	{
		i = 0;
		aggiunto = false;
		codice_caso = 3;
		while(i < DIMENSIONE_INVENTARIO &&aggiunto == false)
		{
			if(inventario[i] == -1)
			{
					inventario[i] = ogg_id;
					aggiunto = true;
					codice_caso = 0;
			}
			i++;
		}
	}
	return codice_caso;
}


void esegui_prendi(int ogg_id)
{
	int codice_caso = prendi(ogg_id);
	if(codice_caso == 0)
	{
		printf("oggetto aggiunto all'inventario\n");
	}
	else if(codice_caso == 1)
	{
		printf("non vedi niente del genere\n");
	}
	else if(codice_caso == 2)
	{
		printf("non puoi prendere quel oggetto\n");
	}
	else
	{
		printf("non hai spazio nell inventario\n");
	}
}


int lascia(int ogg_id)
{
	int i = 0;
	int lasciato = 1;
	while(i < DIMENSIONE_INVENTARIO && lasciato == 1)
	{
		if(inventario[i] == ogg_id)
		{
			inventario[i] = -1;
			get_oggetto(ogg_id)->luogo = pos_giocatore;
			lasciato = 0;
		}
		i++;
	}
	return lasciato;
}


void esegui_lascia(int ogg_id)
{
	int lasciato;
	lasciato = lascia(ogg_id);
	if(lasciato == 0)
	{
		printf("oggetto rimosso dall inventario\n");
	}
	else
	{
		printf("non hai quell oggetto\n");
	}
}


void esegui_colpisci(int ogg_id)
{
  oggetto *ogg = get_oggetto(ogg_id);
  int codice_caso = colpisci(ogg_id);

  if (codice_caso == 0)
    printf("%s", ogg->frase_colpito);
  else
    printf("Non vedi niente del genere da colpire\n");
}


int colpisci(int ogg_id)
{
	int codice_caso = 1;
  oggetto *ogg = get_oggetto(ogg_id);
  if (pos_giocatore == ogg->luogo_utile)
  {
    if (ogg->id == /*PIPISTRELLI*/100)
      perdi_vita();
    else if (ogg->id == BARILE)
      guadagna_vita();
  }
	else
	{
		codice_caso = 0;
	}
	return codice_caso;	
}


void esegui_usa(int ogg_id)
{
  oggetto *ogg = get_oggetto(ogg_id);
  int codice_caso = usa(ogg_id);
  
  if (codice_caso == 0)
    printf("%s\n", ogg->funzione_utile);
  else if (codice_caso == 1)
    printf("%s\n", ogg->funzione_inutile);
  else
    printf("Non hai quest'oggetto\n");
}


int usa(int ogg_id)
{
  int i = 0;
  int codice_caso = 2;

  while (i < DIMENSIONE_INVENTARIO && codice_caso == 2)
  {
    if (ogg_id == inventario[i])
    {
      oggetto *ogg = get_oggetto(ogg_id);
      if (pos_giocatore != ogg->luogo_utile)
        codice_caso = 1;
      else
      {
        codice_caso = 0;
        if (inventario[i] == CHIAVE_VERA)
        {
          aggiorna_luoghi_adiacenti(SALONE, NORD, SALA_TROFEI);
          esegui_lascia(inventario[i]);
        }
        else if (inventario[i] == SPADA)
        {
          esegui_dai(inventario[i], STATUA);
          esegui_lascia(ogg_id);
        }
        else if (inventario[i] == FIACCOLA)
        {
          aggiorna_luoghi_adiacenti(SEGRETE, SUD, CELLE);
          ogg->utilizzabile = false;
          esegui_lascia(inventario[i]);
        }
        else if (inventario[i] == VASO_DA_NOTTE)
        {
          aggiorna_luoghi_adiacenti(CAMERA_REALE, SUD, STANZA_DEL_TESORO);
        }
      }
      
    }
    i++;    
  }
  
  return codice_caso;
}


int dai(int ogg_id, int pers_id)
{
  int i;
  int codice_caso;
  personaggio *pers = get_personaggio(pers_id);
  if(pos_giocatore == pers->luogo)
  {
    i=0;
    while(i < DIMENSIONE_INVENTARIO && codice_caso == 3)
    {
      if(inventario[i] == ogg_id)
      {
        if(ogg_id == ALCOOL && pers->id == VECCHIO)
        {
          get_oggetto(ogg_id)->luogo=-2;
          codice_caso=0;
          get_oggetto(CHIAVE_VERA)->luogo = SEGRETE;
          esegui_prendi(CHIAVE_VERA);
        }
        else
        {
          if(ogg_id == SPADA && pers->id == STATUA)
          {
            esegui_lascia(ogg_id);
            codice_caso=0;
            aggiorna_luoghi_adiacenti(SALA_TROFEI, EST,  CAMERA_REALE);
          }
          else
          {
            codice_caso=1;
          }
          
        }
        
      }
      i++;
    } 
    codice_caso=2;
  }
  return codice_caso;
}


void esegui_dai(int ogg_id, int pers_id)
{
  int codice_caso;
  personaggio *pers = get_personaggio(pers_id);
  codice_caso = dai(ogg_id,pers_id);
  if(codice_caso == 0)
    printf("%s",pers->interazione_giusta);
  else
  {
    if(codice_caso == 1)
      printf("%s",pers->interazione_sbagliata);
    else
    {
      if(codice_caso == 2)
        printf("non hai questo oggetto");
      else
        printf("non vedi questa persona qui");
    }
  }
} 


void stampa_oggetti_stanza(int luog_id)
{
  int i = 0;
  int oggetti_presenti = 0;
  
  while(i < NUM_OGGETTI)
  {
    if(luog_id == oggetti[i].luogo)
    {
      printf("- %s\n", oggetti[i].nome);
      oggetti_presenti++;
    }
    i++;
  }
  if(oggetti_presenti == 0)
  {
    printf("Nessun oggetto\n");
  }
}