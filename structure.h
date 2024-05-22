#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


// Structures des épreuves (on pourra ajouter des épreuves par la suite)
//+1 lors des choix
typedef enum {
  e_100m,     // 0
  e_400m,     // 1
  e_5000m,    // 2
  e_marathon, // 3
  e_relais,// 4
  e_natation, //5
  e_boxe, //6
  e_judo,  //7
  e_escrime //8
} Epreuve;

typedef struct {
  int jour;
  int mois;
  int annee;
} Date;

typedef struct {
  int heure;
  int minute;
  int seconde;
} Temps;

// Structure des entrainements(on pourra en ajouter par la suite)
typedef struct {
  Date date;
  Epreuve evenement;
  Temps temps;
} Entrainement;

// Structure des sportifs
typedef struct {
  char nom[50];
  int age;
  Entrainement *exercice;
} Sportif;

#endif //STRUCTURE_H