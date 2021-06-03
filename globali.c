#include <stdbool.h>
#include <stdio.h>

#include "globali.h"
#include "oggetti.h"

oggetto oggetti[] = {
  {
    100, // id
    "questo oggetto ti permette di attaccare un nemico", // descrizione
    "spada", // nome
    -1, // luogo 
    true, // utilizzabile 
    "bel colpo!", // funzione_utile
    "è meglio non usare la spada qui", // funzione_inutile
    5, // luogo_utile
    false, //colpibile
    "cosa volevi colpire?" // frase_colpibile
  },
  {
    101, // id
    "ti permette di proteggerti da qualcosa", // descrizione
    "scudo", // nome
    -1, // luogo
    true, // utilizzabile
    "lo scudo ti ha protetto", // funzione_utile
    "da cosa volevi proteggerti?", // funzione_inutile
    6, // luogo_utile
    false, // colpibile
    "non puoi colpire lo scudo" // frase_colpito
  }, 
  {
    102, // id
    "ti permette di illuminare luoghi buii", // descrizione
    "fiaccola", // nome 
    1, // luogo
    true, // utilizzabile
    "hai illuminato questo luogo", // funzione_utile
    "questo luogo è già illuminato", // funzione_inutile
    4, // luogo_utile
    false, // colpibile
    "volevi colpire il fuoco?" // frase_colpito
  },
  {
    103, // id
    "questa federa potrebbe essere usata per portare un oggetto in più", // descrizione
    "federa", // nome 
    8, // luogo
    false, // utilizzabile
    "ora hai uno slot in più nell'inventario", // funzione_utile
    "ora non ti serve usare questo oggetto", // funzione_inutile
    8, // luogo_utile
    false, // colpibile
    "non puoi colpire una federa!" // frase_colpito
  },
  {
    104, // id
    "chiave che ti è stata data dal vecchio prigioniero", // descrizione
    "chiave", // nome 
    8, // luogo
    true, // utilizzabile
    "hai aperto questa porta", // funzione_utile
    "non so dove inserire la chiave", // funzione_inutile
    1, // luogo_utile
    false, // colpibile
    "non puoi colpire una chiave!" // frase_colpito
  },
  {
    105, // id
    "un grimaldello usato per scassinare le porte", // descrizione
    "grimaldello",  // nome 
    4, // luogo
    true, // utilizzabile
    "non sei un grande scassinatore...", // funzione_utile
    "non vedi niente da scassinare.", // funzione_inutile
    1, // luogo_utile
    false, // colpibile
    "non puoi colpire una chiave!" // frase_colpito
  },
  {
    106, // id
    "Un vaso da notte pieno di un qualcosa", // descrizione
    "vaso da notte", // nome 
    6, // luogo
    true, // utilizzabile
    "Hai usato il vaso da notte!", // funzione_utile
    "Non penso sia utile qui usare il vaso da notte", // funzione_inutile
    7, // luogo_utile
    false, // colpibile
    "Rompere il vaso non ti porterà a niente" // frase_colpito
  },
  {
    107, // id
    "Bottiglia con dell'alcool dentro", // descrizione
    "alcool",  // nome 
    4, // luogo
    false, // utilizzabile
    "", // funzione_utile
    "Vuoi davvero bere in questo posto macabro?", // funzione_inutile
    8, // luogo_utile
    false, // colpibile
    "che senso ha colpire una bottiglia di alcool?" // frase_colpito
  },
  {
    108, // id
    "un grande baule che sembra contenere il tesoro nascosrto del re", // descrizione
    "tesoro",  // nome 
    7, // luogo
    false, // utilizzabile
    "", // funzione_utile
    "", // funzione_inutile
    -1, // luogo_utile
    false, // colpibile
    "non puoi colpire un tesoro!" // frase_colpibile
  },
	{
    109, // id
    "è una porta chiusa a chiave con  una nota attaccata sopra", // descrizione
    "porta",  // nome 
    1, // luogo
    false, // utilizzabile
    "", //funzione_utile
		"", // funzione_inutile
		 1, // luogo_utile
    false, // colpibile
		"non puoi colpire una porta", //frase_colpibile
  },
	{
    110, // id
    "un vecchio camino rimasto accesso", // descrizione
    "camino",  // nome 
    6, // luogo
    false, // utilizzabile
    "", // funzione_utile
    "", // funzione_inutile
    7, // luogo_utile
    false, // colpibile
    "Stai cercando di farti una spada infuocata?" // frase_colpito
  },
	{
    111, // id
    "è un passaggio che ti permette di arrivare da qualche parte", // descrizione
    "passaggio",  // nome 
    6, // luogo
    false, // utilizzabile
    "", // funzione_utile
    "", // funzione_inutile
    7, // luogo_utile
    false, //colpibile
    "stai cercando di attraversare una porta chiusa a chiave?" // frase_colpito
  },
  {
    112, // id
    "una statua in posizione d'attacco", // descrizione
    "statua",  // nome 
    7, // luogo
    false, // utilizzabile
    "", // funzione_utile
    "", // funzione_inutile
    5, // luogo_utile
    false, //colpibile
    "tranquillo, non è una persona vera" // frase_colpito
  },
	{
    113, // id
    "\"Non riesco a trovare la chiave di questa porta accidenti!\n- il guardiano\"", // descrizione
    "lettera",  // nome 
    1, // luogo
    false, // utilizzabile
    "", // funzione_utile
    "", // funzione_inutile
    1, // luogo_utile
    false, //colpibile
    "Secondo te tagliare una lettera con la spada ha senso?" // frase_colpito
    
  },
	{
    114, // id
    "è un tavolo con dei piatti sporchi da chissà quanto tempo", // descrizione
    "tavolo",  // nome 
    1, // luogo
    false, // utilizzabile
    "", // funzione_utile
    "", // funzione_inutile
    1,// luogo_utile
    false, //colpibile
    "bravo hai rotto il tavolo" // frase_colpito
  },
	{
    115, // id
    "e' un barile contenente qualcosa al suo interno", // descrizione
    "barile",  // nome 
    2, // luogo
    false, // utilizzabile
    "", // funzione_utile
    "", // funzione_inutile
    2, // luogo_utile
    true, //colpibile
    "colpendo il barile hai trovato una pozione all'interno" // frase_colpito
  }
};


luogo luoghi[] = {
  {0, "un ponte da attraversare", "ponte", {-1, -1, -1, -1} },
  {1, "un salone brutto", "salone", {-1, 2, -1, 0} },
  {2, "una sala da pranzo", "sala da pranzo", {-1,-1,3,1} },
  {3, "un corridoio vecchio e spoglio", "corridoio", {2, -1, -1, -1} },
  {4, "delle segrete da esplorare", "segrete", {3, -1, 8, -1} },
  {5, "una sala con molti trofei", "sala trofei", {-1, 6, 1, -1} },
  {6, "una camera dove il signore riposa", "camera reale", {-1, -1, -1, 6 } },
  {7, "una stanza piena di ricchezze", "stanza del tesoro", {6, -1, -1, -1} },
  {8, "delle celle contenenti cose utili", "celle", {4, -1, -1, -1} }
};

personaggio personaggi[] = {
  {
    200, // id
    "vecchio", // nome
    "vecchio prigioniero alcolizzato", // descrizione
    "Cosa ti porta qui straniero?", // interazione_base
    "Grazie ne avevo proprio bisogno!", // interazione_giusta
    "Non è una cosa che posso bere", // interazione_sbagliata
    "Ma sei pazzo?", // interazione_colpito
    false, // vincolo
    8 // luogo
  },
  {
    201, // id
    "custode", // nome
    "un vecchio custode a guardia del castello", // descrizione
    "Vuoi passare? La mia prova dovrei superare", // interazione_base
    "Bravo il mio nome sei riuscito ad indovinare", // interazione_giusta
    "Ehh mi dispace nel castello non potrai entrare", // interazione_sbagliata
    "Non è con la violenza che passerai", // interazione_colpito
    false,
    0
  },
  {
    202, // id
    "spettro", // nome
    "uno spettro un po' spaesato", // descrizione
    "Hey Tu, alle segrete vuoi andare? il mio indovinello dovrai indovinare!!", // interazione_base
    "Bravo hai indovinato, la strada adesso hai liberato", // interazione_giusta
    "Mi dispiace, ma questa risposta non mi piace!", // interazione_sbagliata
    "Stai davvero cercando di colpirmi? Ma hai capito che sono uno spettro vero?", // interazione_colpito
    false, // vincolo
    3 // luogo
  },
};

personaggio *get_personaggio(int pers_id)
{
  int i = 0;
  personaggio *pers = NULL;
  int trovato = false;
  while(i < NUM_PERSONAGGI && trovato == false)
  {
    if(pers_id == personaggi[i].id)
    {
      pers = &personaggi[i];
      trovato = true;
    }
    i++;
  }

  return pers;
}


oggetto *get_oggetto(int ogg_id)
{
  oggetto *ogg = NULL;
  int i = 0;
  bool trovato = false;
  while (i < NUM_OGGETTI && trovato == false)
  {
    if (ogg_id == oggetti[i].id)
    {
      ogg = &oggetti[i];
      trovato = true;
    }
    i++;
  }
  return ogg;
}


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