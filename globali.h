// ID_OGGETTI
#define SPADA 100
#define SCUDO 101
#define FIACCOLA 102
#define FEDERA_CUSCINO 103
#define CHIAVE_VERA 104
#define GRIMALDELLO 105
#define VASO_DA_NOTTE 106
#define ALCOOL 107
#define TESORO 108
#define PORTA 109
#define CAMINO 110
#define PASSAGGIO_SEGRETO 111
#define STATUA 112
#define LETTERA 113
#define TAVOLO 114
#define BARILE 115

#define NUM_OGGETTI 16

// ID PERSONAGGI
#define VECCHIO 200
#define CUSTODE 201
#define SPETTRO 202

#define NUM_PERSONAGGI 3

#define NOME_VERO_CUSTODE "blarne"
#define SOLUZIONE_INDOVINELLO "semaforo"

// ID_STANZE
#define PONTE 0
#define SALONE 1
#define SALA_DA_PRANZO 2
#define CORRIDOIO 3
#define SEGRETE 4
#define SALA_TROFEI 5
#define CAMERA_REALE 6
#define STANZA_DEL_TESORO 7
#define CELLE 8

#define NUM_LUOGHI 9

// ID_DIREZIONI
#define NORD 0
#define EST 1
#define SUD 2
#define OVEST 3

#define DIMENSIONE_INVENTARIO 5

typedef struct personaggio
{
  int id;
  char *nome;
  char *descrizione;
  char *interazione_base;
  char *interazione_giusta;
  char *interazione_sbagliata;
  char *interazione_colpito;
  bool vincolo; // false = non risolto, true = risolto
  int luogo;
} personaggio;

typedef struct oggetto
{ 
  int id;
  char *descrizione;
  char *nome;
  int luogo;
  bool utilizzabile;
  char *funzione_utile;
  char *funzione_inutile;
  int luogo_utile;
  bool colpibile;
  char *frase_colpito;
} oggetto;

typedef struct luogo
{
  int id;
  char *descrizione;
  char *nome;
  int adiacenti[4];
} luogo;

extern int pos_giocatore;
extern int vita;
extern int inventario[DIMENSIONE_INVENTARIO];

extern oggetto oggetti[NUM_OGGETTI];
extern luogo luoghi[NUM_LUOGHI];
extern personaggio personaggi[NUM_PERSONAGGI];

luogo *get_luogo(int luog_id);
personaggio *get_personaggio(int pers_id);
oggetto *get_oggetto(int ogg_id);