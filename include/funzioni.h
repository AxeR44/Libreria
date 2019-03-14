#ifndef FUNZIONI_H
#define FUNZIONI_H
#endif
#include "data.h"
archivio inizializzaArchivio(int);
void visualizza(int, archivio);
void inserisci(int*, archivio*, libro);
void modifica(libro*);
void cancellaModifica(int, int, archivio, char*);
libro *ricerca(int, archivio, char*);
void svuota(libro*);
void inizializzaSliceArchivio(int, int, archivio*);
void debug(archivio*);