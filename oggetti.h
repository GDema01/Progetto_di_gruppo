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

typedef struct
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

static oggetto oggetti[NUM_OGGETTI] = {
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

oggetto *get_oggetto(int ogg_id);

void stampa_oggetti_stanza(int luog_id);

void esegui_prendi(int ogg_id);
int prendi(int ogg_id);

void esegui_colpisci(int ogg_id);
int colpisci(int ogg_id);

void esegui_usa(int ogg_id);
int usa(int ogg_id);

void esegui_lascia(int ogg_id);
int lascia(int ogg_id);

void esegui_dai(int ogg_id, int pers_id);
int dai(int ogg_id, int pers_id);