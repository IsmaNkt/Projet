#include "structure.h"
#ifndef VERIFICATION_H
#define VERIFICATION_H

// fonction qui renvoie 1 si le nom est valide et 0 sinon
int valideNom(char *nom);

// Fonction vérifiant l'existence d'un nom de fichier valide
FILE *verifier_nom(char nom[]);

// Fonction qui vérifie si le fichier est valide puis prend le nom
char *verifier_nom2(char nom[]);

// Fonction qui retourne 'oui' ou 'non' en fonction de la saisie de l'utilisateur
void oui_non(char *reponse);

int VerifierDateRelais(char sportif[], Date date);

#endif //VERIFICATION_H