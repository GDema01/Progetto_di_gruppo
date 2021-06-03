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

// ID_DIREZIONI
#define NORD 0
#define EST 1
#define SUD 2
#define OVEST 3

#define NUM_LUOGHI 9

typedef struct luogo
{
  int id;
  char *descrizione;
  char *nome;
  int adiacenti[4];
} luogo;

static struct luogo luoghi[NUM_LUOGHI] = {
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

luogo *get_luogo(int luog_id);

void guarda();

void esegui_ispeziona(int ogg_id);

void esegui_spostati(int direzione);
int spostati(int direzione);

void aggiorna_luoghi_adiacenti(int id_partenza, int direzione, int id_arrivo);