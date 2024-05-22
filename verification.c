#include "structure.h"
#include "verification.h"


// fonction qui renvoie 1 si le nom est valide et 0 sinon
int valideNom(char *nom) {
  int taille = strlen(nom);
  int nb_underscore = 0;

  // Le nom ne doit pas commencer ou se terminer par un underscore
  if (nom[0] == '_' || nom[taille - 1] == '_') {
    return 0;
  }

  // Vérifier chaque caractère du nom
  for (int i = 0; i < taille; i++) {
    if (nom[i] == '_') {
        nb_underscore++;
    } else if (!isalpha(nom[i])) { // Vérifie si le caractère est alphabétique (les accents ne sont pas pris en compte)
      return 0;
    }
  }

  // Le nom est valide s'il contient exactement un seul underscore
  return (nb_underscore == 1);
}

//******************************************************************************************

// Fonction vérifiant l'existence d'un nom de fichier valide
FILE *verifier_nom(char nom[]) {
  FILE *fichier;

  // Boucle pour vérifier que le nom du fichier existe
  do { 
    printf("Entrez le nom du sportif: ");
    scanf("%s", nom); // récupère le nom du sportif
    while (getchar() != '\n'); // vide le buffer d'entrée

    fichier = fopen(nom, "r"); // ouvre le fichier en lecture
    if (fichier == NULL) {
      printf("Ce nom n'existe pas. Veuillez réessayer.\n");
    }

  } while (fichier == NULL);

  return fichier; // Retourne le fichier ouvert
}

//************************************************************************************

// Fonction qui vérifie si le fichier est valide puis prend le nom
char *verifier_nom2(char nom[]) {
  FILE *fichier = verifier_nom(nom);

  fclose(fichier);
  return nom; // Retourne le le sportif (nom du fichier)
}

//************************************************************************************

// Fonction qui retourne 'oui' ou 'non' en fonction de la saisie de l'utilisateur
void oui_non(char *reponse) {
  do {
    scanf("%3s", reponse); // Lire jusqu'à 3 caractères pour stocker "oui" ou "non" plus le caractère nul
    while (getchar() != '\n'); // Vidage du buffer

    if (strcmp(reponse, "oui") != 0 && strcmp(reponse, "non") != 0) {
      printf("Veuillez répondre par 'oui' ou 'non'.\n");
    }
  } while (strcmp(reponse, "oui") != 0 && strcmp(reponse, "non") != 0);
}

//************************************************************************************

int VerifierDateRelais(char sportif[], Date date) {
  FILE *fichier = fopen(sportif, "r");
  if (fichier == NULL) {
    return 0;
  }

  char ligne[255];
  int jour, mois, annee, evenement, heure, minute, seconde;

  while (fgets(ligne, 255, fichier) != NULL) {

    // Trouver avec chatgpt elle utilise sscanf pour extraire les informations
    sscanf(ligne,
           "Entrainement fait le %d/%d/%d pour l'épreuve %d avec un temps de "
           "%d:%d:%d",
           &jour, &mois, &annee, &evenement, &heure, &minute, &seconde);

    //par défaut 
    evenement = e_relais;
    // On compare entre le fichier et les données du paramètre
    if (jour == date.jour && mois == date.mois && annee == date.annee &&
        evenement == e_relais) {
      fclose(fichier);
      printf("%s a déjà fait un relais à cette date... \n L'entrainement est "
             "annulé'\n",
             sportif);
      return 1;
    }
  }
  printf("%s peut participer au relai à cette date\n", sportif);
  fclose(fichier);
  return 0;
}