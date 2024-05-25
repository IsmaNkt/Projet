#include "structure.h"
#ifndef FATHLETE_H
#define FATHLETE_H

// Fonction pour mettre en majuscule la première lettre d'un mot
void majuscule_premiere_lettre(char *mot);

// Fonction pour mettre en minuscule toutes les lettres sauf la première
void minuscule_sauf_premiere_lettre(char *mot);

// Fonction pour mettre un nom de fichier sous la forme: Prenom_Nom
void format_nom_fichier(char *nom);

// procédure créant un fichier pour un athlète
void creerFichier(int nbr_athletes, char **nom_athletes);

#endif