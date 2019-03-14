/*
 *Questo programma consente di archiviare i dati relativi ad una libreria personale. 
 *
 * Il programma, al termine della stesura del codice,  sarà dotato di un menu che consenta di richiamare alcune funzionalità: 
 * 
 * - elencare tutti i libri presenti in archivio;
 * - aggiungere un libro;
 * - cancellare un libro;
 * - modificare i dati relativi ad un libro;
 * - ricercare un libro;
 * - ordinare l'archivio. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "funzioni.h"

void riempiLibreria(int, archivio*);

int main() {

	int input;
	int size = 10;
	archivio libri;
	libro *elemento, *p = NULL;
	char titolo[LUN];

	elemento = (libro *) malloc (sizeof(libro));
	libri = inizializzaArchivio(size);	//Vengono inizializzati i primi 10 elementi dell'archivio
  
	do {

		printf("******* Menu *******");
		printf("\nInserire un numero compreso tra 1 e 6 (un altro numero per uscire):\n");
		printf("1 - Mostra il contenuto dell'archivio\n");
		printf("2 - Inserisci un libro in archivio\n");
		printf("3 - Cancella un libro dell'archivio\n");
		printf("4 - Modifica un libro in archivio\n");
		printf("5 - Ricerca un libro in archivio\n");
		printf("6 - Ordina l'archivio\n");
		printf("Inserire la propria scelta: ");
  
		scanf("%d", &input);     

		switch(input) {
			case 1: 
				visualizza(size, libri);
			break;
			case 2: 
				printf("Inserisci il titolo del libro: \n");
				scanf("\n%[^\n]", elemento->titolo);
				printf("Inserisci il genere del libro: \n");
				scanf("\n%[^\n]", elemento->genere);
				printf("Inserisci il prezzo del libro: \n");
				scanf("%f", &(elemento->prezzo));
				printf("Inserisci l'anno di pubblicazione del libro: \n");
				scanf("%d", &(elemento->edizione.anno));
				inserisci(&size, &libri,*elemento);
			break;
			case 3: 
				printf("Inserisci il titolo del libro da cancellare: \n");
				scanf("\n%[^\n]", titolo);
				//cancella(size, libri,titolo);
				cancellaModifica(0, size, libri, titolo);
			break;
			case 4:
				printf("Inserire il titolo del libro da modificare: \n");
				scanf("\n%[^\n]", titolo);
				cancellaModifica(1, size, libri, titolo);
				/*printf("Inserisci il titolo del libro: \n");
				scanf("\n%[^\n]", elemento->titolo);
				printf("Inserisci il genere del libro: \n");
				scanf("\n%[^\n]", elemento->genere);
				printf("Inserisci il prezzo del libro: \n");
				scanf("%f", &(elemento->prezzo));
				printf("Inserisci l'anno di pubblicazione del libro: \n");
				scanf("%d", &(elemento->edizione.anno));*/
				// modifica(libri,elemento);
			break;
			case 5: 
				printf("Inserisci il titolo del libro da cercare: \n");
				scanf("\n%[^\n]", titolo);
				p = ricerca(size, libri, titolo);
				if(p != NULL) {
					printf("\nTitolo del libro: %s\n", p->titolo);
					printf("Genere del libro: %s\n", p->genere);
					printf("Prezzo del libro: %f\n", p->prezzo);
					printf("Anno di pubblicazione del libro: %d\n\n", p->edizione.anno);
					p=NULL;
				} else {
					printf("Libro non trovato!\n");
				}
			break;
			case 6: 
				//TODO: da implementare!!!
				//ordina(libri);
				printf("Non ancora implementato\n\n");
			break;
			case 7:	//Caso Fantasma
				debug(&libri);
				break;
			case 8:	//Caso ancora più fantasma
				riempiLibreria(size, &libri);
				break;
			default: input = 0;
		}

	} while(input!=0);

	free(libri);
	free(elemento);

	return EXIT_SUCCESS;
}

void riempiLibreria(int size, archivio *arc) {
	*arc = (archivio)realloc(*arc, size * sizeof(libro));
	for (int offset = 0; offset < size; offset++) {
		(*arc + offset)->pieno = 1;
		strcpy((*arc + offset)->titolo, "Lorem ipsum dolor sit amet");
	}
}
