#include "structure.h"
#ifndef AFFICHAGE_H
#define AFFICHAGE_H

//affiche les résultats d'un athlètes dont le nom est donné
void affiche_nom();

//?? : afficher les résultats d'un athlète en fonction de la date
void affiche_nom_date();

//afficher tous les résultats de TOUS les athlètes en fonction d'une date donnée
void affiche_date(int nbr_athletes, char *nom_athletes[]);

//fonction qui va afficher les resultats de TOUS les athlètes en fonction d'une épreuve donnée 
void affiche_epreuve(int nbr_athletes, char *nom_athletes[]);

//fonction qui va afficher les résultats de TOUS les athlètes en fonctions d'une epreuve donnée et d'une date donnée
void affiche_epreuve_date(int nbr_athletes, char *nom_athletes[]);

//fonction qui va afficher le temps moyen d'un sportif spécifique pour une épreuve donné 
void affiche_epreuve_nom();

//fonction qui va afficher le résultat d'un sportif spécifique pour une date donnée et une épreuve donnée
void affiche_epreuve_nom_date();

// fonction qui va demander à l'utilisateur de quelle manière il veut afficher les résultats, puis appeller une fonction en fonction de ce choix
void choix_affichage(int nbr_athletes, char *nom_athletes[]);

#endif