#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "globali.h"
#include "varie.h"
#include "luoghi.h"
#include "oggetti.h"
#include "parser.h"
#include "personaggi.h"
#include "varie.h"

char input[100] = "guarda";

bool get_input()
{
  // Cursore che fa capire all'utente dove inserire i comandi
  printf("\n--> ");
  // leggo input da tastiera
  return fgets(input, sizeof input, stdin) != NULL;
}

int main(void)
{
  printf("Ciao, benvenuto alla mia avventura testuale!\n");
  // Loop principale chiama le due funzioni alternativamente
  while (analizza_ed_esegui(input) && get_input());
  printf("\nCiao\n\n");
  return 0;
}