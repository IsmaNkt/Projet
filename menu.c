#include "structure.h"
#include "menu.h"

//menu qui s'affiche après avoir créer et ajouter un entraînement
void afficher_menu() {
  printf("\n");
  printf("=======================================================\n");
  printf("                 GESTION DES ATHLÈTES         \n");
  printf("=======================================================\n");
  printf("1. Ajouter un entraînement pour un athlète\n");
  printf("-------------------------------------------------------\n");
  printf("2. Historique des entrainements : Par athlète / épreuve / date.\n");
  printf("-------------------------------------------------------\n");
  printf("3. Afficher les performances d'un athlète\n");
  printf("-------------------------------------------------------\n");
  printf("4. 3 meilleurs athlètes pour une discipline\n");
  printf("-------------------------------------------------------\n");
  printf("5. Différence de temps\n");
  printf("-------------------------------------------------------\n");
  printf("6. 3 pires athlètes pour une discipline\n");
  printf("-------------------------------------------------------\n");
  printf("7. Quitter\n");
  printf("=======================================================\n");
  printf("Choisissez une option (numéro): ");
}
