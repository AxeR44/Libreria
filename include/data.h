#ifndef DATA_H
#define DATA_H
#endif
#define LUN 100

struct data{
  int giorno;
  int mese;
  int anno;
};

typedef struct data data;

struct libro {
  char titolo[LUN];
  char genere[LUN];
  float prezzo;
  data edizione;
  data ristampa;
  int pieno;
};

typedef struct libro libro;

typedef libro * archivio;



