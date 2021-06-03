// ID PERSONAGGI
#define VECCHIO 200
#define CUSTODE 201
#define SPETTRO 202

#define NUM_PERSONAGGI 3

#define NOME_VERO_CUSTODE "blarne"
#define SOLUZIONE_INDOVINELLO "semaforo"

typedef struct
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

static personaggio personaggi[NUM_PERSONAGGI] = {
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

personaggio *get_personaggio(int pers_id);
void stampa_personaggi_stanza(int luog_id);

int interagisci(int pers_id);
void esegui_interagisci(int pers_id);