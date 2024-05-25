#include "structure.h"
#include "fathlete.h"
#include "verification.h"

//affiche les résultats d'un athlètes dont le nom est donné
void affiche_nom() {
  FILE *fichier;
  char ligne[100];
  char nom[50];
  char reponse[4];

  verifier_nom2(nom);

  fichier = fopen(nom, "r");
  if (fichier == NULL) {
      printf("Erreur d'ouverture du fichier %s\n", nom);
      return;
  }

  while (fgets(ligne, 100, fichier) != NULL) {
      printf("%s : %s", nom, ligne);
  }

  fclose(fichier);

  printf("Voulez-vous afficher les résultats d'un autre athlète ?(oui/non):\n");
  oui_non(reponse);
  if (strcmp(reponse, "oui") == 0){
    affiche_nom();
  }

}

//**************************************************************************************************

void affiche_nom_date(){

char date[25], date_comp[25];
FILE *fichier;
char ligne[100];
char nom[50];
char reponse[4];

printf("Saisissez la date (jj/mm/aaaa) : \n");
scanf("%s", date);      

verifier_nom2(nom);

fichier = fopen(nom, "r");
if (fichier == NULL) {
    printf("Erreur d'ouverture du fichier %s\n", nom);
    return;
}

//boucle qui lit chaque ligne du fichier jusqu'à la fin du fichier, (sizeof(ligne) permet d'éviter de lire une chaine de caractère dépassant la taille de 'ligne' )
 while (fgets(ligne, sizeof(ligne), fichier) != NULL) {

      sscanf(ligne, "%*s %*s %*s %s", date_comp); //récupérer les premiers caractères de la ligne (les premiers carcatères sont censés être la date)

      //comparer les deux chaînes de caractères et afficher la ligne si elles sont identiques
      if (strcmp(date, date_comp) == 0) {
          printf("%s", ligne);
      }
  }  

fclose(fichier); //fermer le fichier

  printf("Voulez-vous afficher les résultats d'un autre athlète ?(oui/non):\n");
  oui_non(reponse);
  if (strcmp(reponse, "oui") == 0){
    affiche_nom_date();
  }

}

//**************************************************************************************************

//afficher tous les résultats de TOUS les athlètes en fonction d'une date donnée
void affiche_date(int nbr_athletes, char *nom_athletes[]){
char date[11], date_comp[11];
char ligne[100];
char reponse[4];
FILE *fichier;
Date j, comp;
int epreuve_realisee;

  do{
    epreuve_realisee = 0;
    printf("\nSaisissez la date  (jj/mm/aaaa) :\n");

    do {
      printf("Choisir l'année : \n");
      scanf("%d", &j.annee);

      if (j.annee < 2024 || j.annee > 2124) {
        printf(
            "Nous sommes en 2024...\n"); // messagge d'erreur si l'utilisateur
                                         // saisit une valeur invalide
        while (getchar() != '\n')
          ;
      }
    } while (j.annee < 2024 ||
             j.annee > 2124);

    do {
      printf("Choisir le mois : ");
      scanf("%d", &j.mois);
      if (j.mois < 0 || j.mois > 12) {
        printf("Choisissez entre 1 et 12.\n"); // messagge d'erreur si
                                               // l'utilisateur saisit une
                                               // valeur invalide
        while (getchar() != '\n')
          ;
      }
    } while (j.mois < 1 || j.mois > 12);

    do {
      printf("Choisir le jour: ");
      scanf("%d", &j.jour);
      if (j.jour< 1 || j.jour > 31) {
        printf("Choisissez entre 1 et 31.\n"); // messagge d'erreur si
                                               // l'utilisateur saisit une
                                               // valeur invalide
        while (getchar() != '\n')
          ;
      }
    } while (j.jour < 1 || j.jour > 31);


 for (int i = 0; i < nbr_athletes; i++) {
      // même chose que dans la fonction précédente
        fichier = fopen(nom_athletes[i], "r");

        if(fichier == NULL){
            printf("impossible d'ouvrir le fichier %s", nom_athletes[i]);
            exit(1);
        }

      while (fgets(ligne, sizeof(ligne), fichier) != NULL) {

        sscanf(ligne, "Entraînement fait le %d/%d/%d pour l'épreuve %*s avec un temps de %*s", &comp.jour, &comp.mois, &comp.annee); // récupérer la date de la ligne 

            if (j.jour == comp.jour && j.mois == comp.mois && j.annee == comp.annee) {
              printf("%s : %s", nom_athletes[i], ligne);  //affichage avec le nom du sportif en plus
              epreuve_realisee = 1;
            }
      }

      fclose(fichier);

  }

  if(epreuve_realisee == 0){
    printf("Il n'y a eu aucun entraînement à cette date, Réessayez :\n");
  }

  } while(epreuve_realisee == 0);

  printf("Voulez-vous afficher les résultats d'un autre athlète ?(oui/non):\n");
  oui_non(reponse);
  if (strcmp(reponse, "oui") == 0){
    affiche_date(nbr_athletes, nom_athletes);
  }
}

//**************************************************************************************************


//fonction qui va afficher les resultats de TOUS les athlètes en fonction d'une épreuve donnée 
void affiche_epreuve(int nbr_athletes, char *nom_athletes[]){
char epreuve[25], epreuve_comp[25];
FILE *fichier;
char ligne[100];
char *tab_epreuve[9] = {"100m", "400m", "5000m", "marathon", "relais", "natation", "boxe", "judo", "escrime"};
char reponse[4];
int compte = 0;
int epreuve_realisee = 0;

do{
    epreuve_realisee = 0;
        do{
            printf("\nSaisissez l'épreuve ('100m', '400m', '5000m', 'marathon', 'relais' , 'natation' , 'boxe' , 'judo' ou 'escrime'): \n");

                scanf("%s", epreuve);
                while (getchar() != '\n'){}

                compte = 0;
                    for(int j=0; j<9; j++){
                            if(strcmp(epreuve, tab_epreuve[j]) != 0){
                                compte++;
                            }
                    }

                    if(compte == 9){
                    printf("Erreur, veuillez saisir une épreuve valide.\n");
                    }


        }while (compte == 9);


  //la boucle parcours chaque fichier d'  athlète
  for (int i = 0; i < nbr_athletes; i++) {

    fichier = fopen(nom_athletes[i], "r");

    if(fichier == NULL){
        printf("Impossible d'ouvrir le fichier %s", nom_athletes[i]);
        exit(1);
    }
      //même chose, récupérer chaque ligne... jusqu'à fin du fichier ou erreur
      while (fgets(ligne, sizeof(ligne), fichier) != NULL) {

          sscanf(ligne, "%*s %*s %*s %*s %*s %*s %s", epreuve_comp); //aide de chatgpt avec '%*s' qui permet d'ignoré la première chaîne qui est la date

          if (strcmp(epreuve, epreuve_comp) == 0) {
              printf("%s : %s", nom_athletes[i], ligne);
              epreuve_realisee = 1;
          }

      }

      fclose(fichier);
  }

  if(epreuve_realisee == 0){
    printf("Erreur, l'épreuve saisie n'a été réalisée par aucun athlète.\n");
  }

} while(epreuve_realisee == 0);

  printf("Voulez-vous afficher les résultats d'un autre athlète ?(oui/non):\n");
  oui_non(reponse);
  if (strcmp(reponse, "oui") == 0){
    affiche_epreuve(nbr_athletes, nom_athletes);
  }
}

//**************************************************************************************************

//fonction qui va afficher les résultats de TOUS les athlètes en fonctions d'une epreuve donnée et d'une date donnée
void affiche_epreuve_date(int nbr_athletes, char *nom_athletes[]){
  char date[11], date_comp[11];
  char epreuve[25], epreuve_comp[25];
  char ligne[100];
  FILE *fichier;
  Date j, comp;
  char *tab_epreuve[9] = {"100m", "400m", "5000m", "marathon", "relais", "natation", "boxe", "judo", "escrime"};
  char reponse[4];
  int compte = 0;
  int epreuve_realisee = 0;

  do{
  printf("\nSaisissez la date (jj/mm/aaaa) :\n");

    do {
      printf("Choisir l'année : \n");
      scanf("%d", &j.annee);

      if (j.annee < 2024 || j.annee > 2124) {
        printf(
            "Nous sommes en 2024...\n"); // messagge d'erreur si l'utilisateur
                                         // saisit une valeur invalide
        while (getchar() != '\n')
          ;
      }
    } while (j.annee < 2024 ||
             j.annee > 2124);

    do {
      printf("\nChoisir le mois : ");
      scanf("%d", &j.mois);
      if (j.mois < 0 || j.mois > 12) {
        printf("Choisissez entre 1 et 12.\n"); // messagge d'erreur si
                                               // l'utilisateur saisit une
                                               // valeur invalide
        while (getchar() != '\n')
          ;
      }
    } while (j.mois < 1 || j.mois > 12);

    do {
      printf("\nChoisir le jour: ");
      scanf("%d", &j.jour);
      if (j.jour< 1 || j.jour > 31) {
        printf("Choisissez entre 1 et 31.\n"); // messagge d'erreur si
                                               // l'utilisateur saisit une
                                               // valeur invalide
        while (getchar() != '\n');

      }
    } while (j.jour < 1 || j.jour > 31);


    epreuve_realisee = 0;
        do{
            printf("\nSaisissez l'épreuve ('100m', '400m', '5000m', 'marathon', 'relais', 'natation', 'boxe', 'judo' ou 'escrime'): \n");

                scanf("%s", epreuve);
                while (getchar() != '\n'){}

                compte = 0;
                    for(int j=0; j<9; j++){
                            if(strcmp(epreuve, tab_epreuve[j]) != 0){
                                compte++;
                            }
                    }

                    if(compte == 9){
                    printf("Erreur, veuillez saisir une épreuve valide.\n");
                    }


        }while (compte == 9);

  for(int i=0; i<nbr_athletes; i++){
    fichier = fopen(nom_athletes[i], "r");
            if (fichier == NULL) {
                printf("Erreur d'ouverture du fichier %s\n", nom_athletes[i]);
                exit(1);
            }

   while (fgets(ligne, sizeof(ligne), fichier) != NULL) {

            sscanf(ligne, "Entraînement fait le %d/%d/%d pour l'épreuve %*s avec un temps de %*s", &comp.jour, &comp.mois, &comp.annee);
            sscanf(ligne, "%*s %*s %*s %*s %*s %*s %s", epreuve_comp);
          //comparer les deux dates et les deux épreuves et afficher si elles sont identiques avec le nom de l'athlete
          if (j.jour == comp.jour && j.mois == comp.mois && j.annee == comp.annee && strcmp(epreuve, epreuve_comp) == 0) {
              printf("%s : %s", nom_athletes[i], ligne);
              epreuve_realisee = 1;
          }
      }

      fclose(fichier);
  }

  if(epreuve_realisee == 0){
    printf("Erreur, l'épreuve saisie n'a été réalisée par aucun athlète à cette date.\n");
  }

  } while(epreuve_realisee == 0);

  printf("Voulez-vous afficher les résultats d'un autre athlète ?(oui/non):\n");
  oui_non(reponse);
  if (strcmp(reponse, "oui") == 0){
    affiche_epreuve_date(nbr_athletes, nom_athletes);
  }

}

//**************************************************************************************************


//fonction qui va afficher le temps moyen d'un sportif spécifique pour une épreuve donné 
void affiche_epreuve_nom(){
    FILE *fichier;
    char ligne[100];
    char epreuve[25], epreuve_comp[25];
    char *tab_epreuve[9] = {"100m", "400m", "5000m", "marathon", "relais", "natation", "boxe", "judo", "escrime"};
    char nom[50];
    char reponse[4];
    int compte = 0;
    int epreuve_realisee = 0;      


    verifier_nom2(nom);

    fichier = fopen(nom, "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier %s\n", nom);
        exit(1);
    }

  do{
    epreuve_realisee = 0;
        do{
            printf("\nSaisissez l'épreuve ('100m', '400m', '5000m', 'marathon' ,'relais', 'natation', 'boxe', 'judo' ou 'escrime'): \n");

                scanf("%s", epreuve);
                while (getchar() != '\n'){}

                compte = 0;
                    for(int j=0; j<9; j++){
                            if(strcmp(epreuve, tab_epreuve[j]) != 0){
                                compte++;
                            }
                    }

                    if(compte == 9){
                    printf("Erreur, veuillez saisir une épreuve valide.\n");
                    }


        }while (compte == 9);


      for(int j=0; j<9; j++){
        if(strcmp(epreuve, tab_epreuve[0]) != 0 || strcmp(epreuve, tab_epreuve[0]) != 0 || strcmp(epreuve, tab_epreuve[0]) != 0 || strcmp(epreuve, tab_epreuve[0]) != 0 || strcmp(epreuve, tab_epreuve[0]) != 0){
          printf("Erreur, veuillez saisir une épreuve valide.\n");
          affiche_epreuve_nom(nom);
        }
      }


       while (fgets(ligne, sizeof(ligne), fichier) != NULL) {

      sscanf(ligne, "%*s %*s %*s %*s %*s %*s %s", epreuve_comp); //récupérer seulement l'épreuve comme dans 'affiche_épreuve'

      if (strcmp(epreuve, epreuve_comp) == 0) {
          printf("%s : %s", nom, ligne);
          epreuve_realisee = 1;
      }
  }
    //dire qu'il n'y a pas eu d'entraînement
    fclose(fichier);

    //si aucune épreuve n'a été réalisée on recommence 
    if(epreuve_realisee == 0){
    printf("Erreur, l'épreuve saisie n'a pas été réalisée par cet athlète.\n");
    }
} while(epreuve_realisee == 0);

  printf("Voulez-vous afficher les résultats d'un autre athlète ?(oui/non):\n");
  oui_non(reponse);
  if (strcmp(reponse, "oui") == 0){
    affiche_epreuve_nom();
  }
}

//**************************************************************************************************

//fonction qui va afficher le résultat d'un sportif spécifique pour une date donnée et une épreuve donnée
void affiche_epreuve_nom_date(){
FILE *fichier;
char ligne[100];
char epreuve[25], epreuve_comp[25];
char nom[50];
char reponse[4];
char *tab_epreuve[9] = {"100m", "400m", "5000m", "marathon", "relais", "natation", "boxe", "judo", "escrime"};
int compte = 0;
int epreuve_realisee = 0;
Date j, comp;

verifier_nom2(nom);

fichier = fopen(nom, "r");
if (fichier == NULL) {
    printf("Erreur d'ouverture du fichier %s\n", nom);
    return;
}

do{
printf("\nSaisissez la date (jj/mm/aaaa) :\n");

do {
      printf("Choisir l'année : \n");
      scanf("%d", &j.annee);

      if (j.annee < 2024 || j.annee > 2124) {
        printf(
            "Nous sommes en 2024...\n"); // messagge d'erreur si l'utilisateur
                                         // saisit une valeur invalide
        while (getchar() != '\n')
          ;
      }
    } while (j.annee < 2024 ||
             j.annee > 2124);

    do {
      printf("Choisir le mois : ");
      scanf("%d", &j.mois);
      if (j.mois < 0 || j.mois > 12) {
        printf("Choisissez entre 1 et 12.\n"); // messagge d'erreur si
                                               // l'utilisateur saisit une
                                               // valeur invalide
        while (getchar() != '\n')
          ;
      }
    } while (j.mois < 1 || j.mois > 12);

    do {
      printf("Choisir le jour: ");
      scanf("%d", &j.jour);
      if (j.jour< 1 || j.jour > 31) {
        printf("Choisissez entre 1 et 31.\n"); // messagge d'erreur si
                                               // l'utilisateur saisit une
                                               // valeur invalide
        while (getchar() != '\n')
          ;
      }
    } while (j.jour < 1 || j.jour > 31);

    epreuve_realisee = 0;
        do{
            printf("\nSaisissez l'épreuve ('100m', '400m', '5000m', 'marathon', 'relais', 'natation', 'boxe', 'judo' ou 'escrime'): \n");

                scanf("%s", epreuve);
                while (getchar() != '\n'){}

                compte = 0;
                    for(int j=0; j<9; j++){
                            if(strcmp(epreuve, tab_epreuve[j]) != 0){
                                compte++;
                            }
                    }

                    if(compte == 9){
                    printf("Erreur, veuillez saisir une épreuve valide.\n");
                    }


        }while (compte == 9);

 while (fgets(ligne, sizeof(ligne), fichier) != NULL) {

        sscanf(ligne, "Entraînement fait le %d/%d/%d pour l'épreuve %*s avec un temps de %*s", &comp.jour, &comp.mois, &comp.annee);
        sscanf(ligne, "%*s %*s %*s %*s %*s %*s %s", epreuve_comp);
                                 //récupérer la date et l'épreuve
      if (j.jour == comp.jour && j.mois == comp.mois && j.annee == comp.annee && strcmp(epreuve, epreuve_comp) == 0) {
          printf("%s : %s", nom, ligne); //afficher la ligne avec le nom
          epreuve_realisee = 1;
      }

  }

  fclose(fichier);
  if(epreuve_realisee == 0){
    printf("Erreur, l'épreuve saisie n'a pas été réalisée par cet athlète à cette date. (Erreur de date ou d'épreuve)\n");
  }
  } while(epreuve_realisee == 0);

    printf("Voulez-vous afficher les résultats d'un autre athlète ?(oui/non):\n");
    oui_non(reponse);
    if (strcmp(reponse, "oui") == 0){
      affiche_epreuve_nom_date();
    }

}

//**************************************************************************************************

// fonction qui va demander à l'utilisateur de quelle manière il veut afficher les résultats, puis appeller une fonction en fonction de ce choix
void choix_affichage(int nbr_athletes, char *nom_athletes[]) {

char nom[50];
int maniere;
int choix1, choix2, choix3, choixdate;

printf("\nVoulez-vous afficher l'historique SEULEMENT en fonction de la date ?\n 1 : Oui\n 2 : Non\n");

    do{
    scanf("%d", &choixdate);
    while (getchar() != '\n'){}
    if (choixdate < 1 || choixdate > 2) {
        printf("Erreur, veuillez saisir 1 ou 2\n");
    } 
    } while(choixdate < 1 || choixdate >2);



    if (choixdate == 2) {
        printf("\nDe quelle manière voulez-vous afficher les résultats ?\n 1 : par nom\n 2 : par épreuve\n");

        do{
        scanf("%d", &maniere);
        while (getchar() != '\n'){}
        if (maniere < 1 || maniere > 2) {
            printf("Erreur, veuillez réessayer, saisissez 1 ou 2 \n");
        }
        }while(maniere < 1 || maniere > 2);

        if (maniere == 1){

            printf("\nVoulez-vous consulter les performances de cet athlète en fonction d'une épreuve particulière ?\n 1 : oui\n 2 : non\n");

            do{
            scanf("%d", &choix1);
            while (getchar() != '\n'){}
            if (choix1 < 1 || choix1 > 2) {
                printf("Erreur, veuillez réessayer, saisissez 1 ou 2 \n");
            }
            } while (choix1 < 1 || choix1 > 2);

            if (choix1 == 1) {
                printf("\nVoulez-vous consulter les performances de cet athlète en fonction d'une date particulière ?\n 1 : oui\n 2 : non\n");

                do{
                scanf("%d", &choix3);
                while (getchar() != '\n'){}
                if (choix3 < 1 || choix3 > 2) {
                    printf("Erreur, veuillez réessayer, saisissez 1 ou 2 \n");
                }
                } while(choix3 < 1 || choix3 > 2);

                if (choix3 == 1) {
                    affiche_epreuve_nom_date();
                } else {
                    affiche_epreuve_nom();
                }
            } else {
                printf("\nVoulez-vous consulter les performances de cet athlète en fonction d'une date ?\n1 : oui\n2 : non\n");

                do{
                scanf("%d", &choix2);
                while (getchar() != '\n'){}
                if (choix2 < 1 || choix2 > 2) {
                    printf("Erreur, veuillez réessayer, saisissez 1 ou 2 \n");
                }
                } while(choix2 < 1 || choix2 > 2);

                if (choix2 == 1) {
                    affiche_nom_date();
                } else {
                    affiche_nom();
                }
            }
        } 
        else {
            printf("\nVoulez-vous consulter les performances de tous les athlètes en fonction d'une date ?\n1 : oui\n2 : non\n");

            do{
            scanf("%d", &choix1);
            while (getchar() != '\n'){}
            if (choix1 < 1 || choix1 > 2) {
                printf("Erreur, veuillez réessayer, saisissez 1 ou 2 \n");
            }
            } while(choix1 < 1 || choix1 >2);

            if (choix1 == 1) {
                affiche_epreuve_date(nbr_athletes, nom_athletes);
            } else {
                affiche_epreuve(nbr_athletes, nom_athletes);
            }
        }
    } 

    else {
        affiche_date(nbr_athletes, nom_athletes);
    }
}

//**************************************************************************************************
