#include "affichage.h"
#include "entrainement.h"
#include "fathlete.h"
#include "menu.h"
#include "statistique.h"
#include "structure.h"
#include "verification.h"

int main() {
  int nbr_athletes = 0;
  int choix = 0;
  char reponse[4];

  printf(" ~ Bienvenue !\nVous êtes dans le programme de gestion de l'entraînement Cer-JO ~\n");

  printf("Combien de sportifs d'athlètes avez-vous ? \n");
  do {
    scanf("%d", &nbr_athletes);
    if (nbr_athletes <= 0) {
      printf("Entrée invalide ! Entrer au moins 1 sportif.\n");
      // Vidage du buffer
      while (getchar() != '\n'){}
    }
  } while (nbr_athletes <= 0);

  // déclaration des tableaux de fichiers et de sportifs
  char *nom_athletes[nbr_athletes];

  creerFichier(nbr_athletes, nom_athletes);
  AjouterEntrainement();

  while (1) {
    afficher_menu();
    scanf("%d", &choix);
    while (getchar() != '\n'); // Vidage du buffer

    switch (choix) {
      case 1:
        creerFichier(nbr_athletes, nom_athletes);
        break;

      case 2: 
        AjouterEntrainement();
        break;

      case 3:
        choix_affichage(nbr_athletes, nom_athletes);
        break;

      case 4:
        perf_athlete();
        break;

      case 5:
        meilleur_temps(nbr_athletes, nom_athletes);
        break;

      case 6:
        diff_temps();
        break;

      case 7:
        pire_temps(nbr_athletes, nom_athletes);
        break;

      case 8:
          printf("Merci d'avoir utilisé Cer-JO ! Au revoir !\n");
          for (int i = 0; i < nbr_athletes; i++) {
              free(nom_athletes[i]);
          }
          exit(0);

      default:
          printf("Option invalide, veuillez réessayer.\n");
          break;
    }
  }

    return 0;
}
