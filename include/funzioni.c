#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funzioni.h"

archivio inizializzaArchivio(int size){
	archivio tmp, arc;
	arc = (archivio)malloc(size * sizeof(libro));
	tmp = arc;
	while(tmp < arc + size){
		svuota(tmp);
		++tmp;
	}
	return arc;
}
void visualizza(int size, archivio arc){
	archivio tmp = arc;
	int vuoto = 0;
	printf("\n\nTitolo\t\t\tGenere\t\t\tPrezzo\t\t\tAnno Edizione\n");
	while(tmp < arc+size){
		if(tmp->pieno == 1) {
			printf("%s\t\t\t%s\t\t\t%.2f\t\t\t%d\n\n\n", tmp->titolo, tmp->genere, tmp->prezzo, tmp->edizione.anno);
		}
		else {
			++vuoto;
		}
		//printf("%s\t%.2f\t%d\n\n\n", tmp->titolo, tmp->prezzo, tmp->edizione.anno);
		++tmp;
	}
	if (vuoto == size) {
		printf("\n\nArchivio libri vuoto\n\n");
	}
	//printf("%d\n", vuoto);
}
void inserisci(int *size, archivio *arc, libro lb){
	/*archivio tmp = *arc;
	archivio *tmp1 = arc;*/
	int afull = 0, offset = 0;
	lb.pieno = 1;
	while (offset < *size && (*arc + offset)->pieno == 1 && afull == 0) {
		if ((*arc + offset)->pieno == 1 && offset == *size - 1) {
			afull = 1;
		}
		else {
			++offset;
		}
	}
	if(afull == 1){
		*size = *size + 10;
		*arc = (archivio)realloc(*arc, *size * sizeof(libro));
		++offset;
	}
	*(*arc+offset) = lb;
	inizializzaSliceArchivio(offset + 1, *size, arc);
}

void modifica(libro *lb) {
	int scelta;
	do {
		printf("\n******* Modifica del libro %s *******", lb->titolo);
		printf("Scegliere una voce da modificare inserendo una scelta compresa tra 1 e 4 (un altro numero per tornare al menu principale):");
		printf("\n1 - Modifica del Titolo\n");
		printf("2 - Modifica del genere\n");
		printf("3 - Modifica del prezzo\n");
		printf("4 - Modifica dell'anno di pubblicazione\n");
		printf("Inserire la propria scelta: ");

		scanf("%d", &scelta);
		switch (scelta) {
		case 1:
			printf("Inserire il nuovo titolo: ");
			scanf("\n%[^\n]", lb->titolo);
			break;
		case 2:
			printf("Inserire il nuovo genere: ");
			scanf("\n%[^\n]", lb->genere);
			break;
		case 3:
			printf("Inserire il nuovo prezzo: ");
			scanf("%f", &(lb->prezzo));
			break;
		case 4:
			printf("Inserire il nuovo anno di pubblicazione: ");
			scanf("%d", &(lb->edizione.anno));
			break;
		default:
			scelta = 0;
		}

	} while (scelta != 0);
}

void cancellaModifica(int tag, int size, archivio arc, char *title) {
	libro *trovato = ricerca(size, arc, title);
	if (trovato != NULL) {
		switch (tag) {
		case 0:
			//cancella
			svuota(trovato);
			break;
		case 1:
			//modifica
			modifica(trovato);
			break;
		}
	}
	else {
		printf("\n\nNessuna occorrenza trovata: archivio inalterato\n\n");
	}
}

libro *ricerca(int size, archivio arc, char *title){
	archivio tmp = arc;
	while(tmp < arc + size){
		if(!strcmp(tmp -> titolo, title))
			return tmp;
		++tmp;
	}
	return NULL;
}

void svuota(libro *lb){
	strcpy(lb->titolo, "Lorem ipsum dolor sit amet");
	strcpy(lb->genere, "Lorem ipsum dolor sit amet");
	lb->prezzo = 0.0;
	lb->edizione.giorno = 1;
	lb->edizione.mese = 1;
	lb->edizione.anno = 1970;
	lb->ristampa.giorno = 1;
	lb->ristampa.mese = 1;
	lb->ristampa.anno = 1970;
	lb->pieno = 0;
}

void inizializzaSliceArchivio(int start, int size, archivio *arc) {
	while (start < size) {
		svuota((*arc + start++));
	}
}

void debug(archivio *arc) {	//Qualcosa che nessuno deve vedere
	libro *lb = &(**arc);
	printf("%.2f\n", lb->prezzo);
	lb->prezzo = 150;
	printf("%.2f\n", (*lb).prezzo);
}

