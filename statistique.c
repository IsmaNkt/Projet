#include "entrainement.h"
#include "structure.h"
#include "verification.h"

// procédure qui affiche les performances de l'athlète (meilleur et pire temps, moyenne, temps total)
void perf_athlete() {
  char nom[50];
  int choix_epreuve;  // choix de l'épreuve avec un entier
  char ligne[256];   // pour stocker les lignes lues dans le fichier
  char epreuve_ligne[10];
  int temps, heures, minutes, secondes;
  int meilleur_temps = 0;
  int pire_temps = 0;
  int total_temps = 0;
  int compt = 0;
  FILE *fichier;

  printf("\nDe quel athlète souhaitez-vous connaître les performances ?\n");
  fichier = verifier_nom(nom); // vérifier existence du fichier et l'ouvre avec "r"

  printf("\nQuelle est l'épreuve dont souhaitez-vous connaître ses performances "
         "?\n1 : 100m \n2 : 400m \n3 : 5000m \n4 : marathon\n5 : relais\n6 : Natation\n");
  do {
    scanf("%d", &choix_epreuve);
    while (getchar() != '\n')
      ;
    if (choix_epreuve < 1 || choix_epreuve > 6) {
      printf(
          "Choisir un numéro valable: "); // message d'erreur si mauvaise valeure
    }
  } while (choix_epreuve < 1 || choix_epreuve > 6);

  char *epreuve[] = {"100m", "400m", "5000m", "marathon","relais","natation"};

  while (fgets(ligne, sizeof(ligne), fichier)) { // lit les lignes du fichier
    if (sscanf(ligne, "Entraînement fait le %*s pour l'épreuve %s avec un temps de %d:%d:%d", epreuve_ligne, &heures, &minutes, &secondes) == 4) {
      if (strcmp(epreuve_ligne, epreuve[choix_epreuve - 1]) ==
          0) { // Comparaison de l'épreuve dans le fichier avec celle du tableau
               // epreuve[] avec strcmp
        temps = heures * 3600 + minutes * 60 + secondes;
        total_temps += temps;
        compt++;
        // Initialise meilleur_temps et pire_temps avec la première valeur de
        // temps
        if (compt == 1) {
          meilleur_temps = temps;
          pire_temps = temps;
        } else {
          // Mettre à jour le meilleur temps si le temps actuel est plus petit
          if (temps < meilleur_temps) {
            meilleur_temps = temps;
          }
          // Mettre à jour le pire temps si le temps actuel est plus grand
          if (temps > pire_temps) {
            pire_temps = temps;
          }
        }
      }
    }
  }
  // fermer le fichier
  fclose(fichier);

  if (compt > 0) {
    int moyenne_temps = total_temps / compt;
    printf("\nRésumé des performances de l'athlète pour l'épreuve %s:\n",
           epreuve[choix_epreuve - 1]);
    printf("  - Meilleur temps: %.2d:%.2d:%.2d\n", meilleur_temps/3600, (meilleur_temps%3600)/60, meilleur_temps%60);
    printf("  - Pire temps: %.2d:%.2d:%.2d\n", pire_temps/3600, (pire_temps%3600)/60, pire_temps%60);
    printf("  - Temps moyen: %.2d:%.2d:%.2d\n", moyenne_temps/3600, (moyenne_temps%3600)/60, moyenne_temps%60);
  } else {
      printf("Aucun entraînement n'a été trouvé pour l'épreuve %s.\n",
             epreuve[choix_epreuve - 1]);
    }

  char reponse[4]; // Pour stocker "oui" ou "non"
  printf("Souhaitez-vous continuer à chercher d'autres données sur les performances d'un athlète ?(oui/non):\n");
  oui_non(reponse); //appel de la fonction pour vérifier si l'utilisateur veut continuer ou non
  if (strcmp(reponse, "oui") == 0){
    perf_athlete();
  }   
}

//************************************************************************************************************

//fonction qui affiche le top3 meilleurs athlète dans une épreuve
void meilleur_temps(int nbr_athletes, char *nom_athletes[]) {
  int choix_epreuve;  // choix de l'épreuve avec un entier
  char ligne[256];   // pour stocker les lignes lues dans le fichier
  char epreuve_ligne[10];
  int heures, minutes, secondes;
  //chatgpt : permet de stocker dessus pour chaque athletes
  int temps[nbr_athletes], moyenne_temps[nbr_athletes];
  int total_temps = 0;
  int compt = 0;
  char nom_premier[255];
  char nom_deuxieme[255];
  char nom_troisieme[255];
  FILE *fichier;


  printf("\nQuelle est l'épreuve dont souhaitez-vous connaître ses 3 meilleurs athlètes?");
  printf("\n1 : 100m \n2 : 400m \n3 : 5000m \n4 : marathon\n5 : relais\n 6 : natation \n");

  do {
    scanf("%d", &choix_epreuve);
    while (getchar() != '\n');
    if (choix_epreuve < 1 || choix_epreuve > 6) {
      printf("Choisir un numéro valable: "); // message d'erreur si mauvaise valeure
    }
  } while (choix_epreuve < 1 || choix_epreuve > 6);

  char *epreuve[] = {"100m", "400m", "5000m", "marathon", "relais", "natation"};

  for (int i = 0; i < nbr_athletes; i++) {
    //On remet tout à 0 pour la boucle pour chaque athlète
    compt = 0;
    total_temps = 0;
    moyenne_temps[i] = 0;
      // même chose que dans la fonction précédente
    fichier = fopen(nom_athletes[i], "r");
    if(fichier == NULL){
      printf("impossible d'ouvrir le fichier %s", nom_athletes[i]);
      exit(1);
    }

    while (fgets(ligne, sizeof(ligne), fichier)) { // lit les lignes du fichier
      if (sscanf(ligne, "Entraînement fait le %*s pour l'épreuve %s avec un temps de %d:%d:%d", epreuve_ligne, &heures, &minutes, &secondes) == 4) {
        if (strcmp(epreuve_ligne, epreuve[choix_epreuve - 1]) ==0) { 
          // Comparaison de l'épreuve dans le fichier avec celle du tableau
          // epreuve[] avec strcmp
          temps[i] = heures * 3600 + minutes * 60 + secondes;
          total_temps += temps[i];
          compt++;
          }
        }
      }
    if(compt>0){
      moyenne_temps[i] = total_temps / compt;
    }
    // fermer le fichier
    fclose(fichier);
  }//fin boucle for

  //par défaut le premier est le premier du tableau
  strcpy(nom_premier, nom_athletes[0]);
  int temps1 = moyenne_temps[0];

  int temps2 = 86400; //24h en secondes pour pouvoir faire les comparaison
  int temps3 = 86400;

  for (int i = 1; i < nbr_athletes; i++) {
    if(moyenne_temps[i] != 0){
      if (moyenne_temps[i]<temps1) {
        temps3 = temps2; //on met à jour le top3
        strcpy(nom_troisieme,nom_deuxieme); 
        temps2 = temps1; // on met à jour le top2
        strcpy(nom_deuxieme,nom_premier);
        temps1 = moyenne_temps[i]; //on met à jour le top1
        strcpy(nom_premier,nom_athletes[i]);
      } else if (moyenne_temps[i]<temps2) { //2 cas
        temps3 = temps2; //à jour top3
        strcpy(nom_troisieme,nom_deuxieme);
        temps2 = moyenne_temps[i]; //jour top2
        strcpy(nom_deuxieme,nom_athletes[i]);
      } else if (moyenne_temps[i]<temps3) {
        temps3 = moyenne_temps[i]; //à jour top3
        strcpy(nom_troisieme,nom_athletes[i]);
      }
    }  
  }

  if(temps1 == 0){
    printf("\nAucun entraînement n'a été trouvé pour l'épreuve par conséquent personne n'est dans le classement\n");
  }

  else if(temps2 == 86400){
     printf("\nEn 1re place nous avons %s avec son temps moyen de : %.2d:%.2d:%.2d\n", nom_premier, temps1/3600, (temps1%3600)/60, temps1%60);
    printf("\nNous avons que 1 athlète dans le top 3\n");
    printf("Il n'y a ni deuxième ni troisième meilleur athlète pour cette épreuve car c'est le seul à s'être entrainer.\n");
  }

  else if(temps3 == 86400){
    printf("\nEn 1re place nous avons %s avec son temps moyen de : %.2d:%.2d:%.2d\n", nom_premier, temps1/3600, (temps1%3600)/60, temps1%60);
    printf("En 2e place nous avons %s avec son temps moyen de : %.2d:%.2d:%.2d\n", nom_deuxieme, temps2/3600, (temps2%3600)/60, temps2%60);
    printf("\nNous avons que 2 athlètes dans le top 3\n");
    printf("Il n'y a pas de troisième meilleur athlète pour cette épreuve car ce sont les 2 seules à s'être entrainer.\n");
  }

  else{
    printf("\nEn 1re place nous avons %s avec son temps moyen de : %.2d:%.2d:%.2d\n", nom_premier, temps1/3600, (temps1%3600)/60, temps1%60);
    printf("En 2e place nous avons %s avec son temps moyen de : %.2d:%.2d:%.2d\n", nom_deuxieme, temps2/3600, (temps2%3600)/60, temps2%60);
    printf("Et pour finir, en 3e place nous avons %s avec son temps moyen de : %.2d:%.2d:%.2d\n", nom_troisieme, temps3/3600, (temps3%3600)/60, temps3%60);
    }


  char reponse[4]; // Pour stocker "oui" ou "non"
  printf("\nSouhaitez-vous continuer à savoir qui sont les meilleurs athlètes dans une autre épreuve? (oui/non):\n");
  oui_non(reponse); //appel de la fonction pour vérifier si l'utilisateur veut continuer ou non
  if (strcmp(reponse, "oui") == 0){
    meilleur_temps(nbr_athletes,nom_athletes);
  }   
  }

//************************************************************************************************************

//fonction qui affiche le top3 meilleur athlète dans une épreuve
void pire_temps(int nbr_athletes, char *nom_athletes[]) {
  int choix_epreuve;  // choix de l'épreuve avec un entier
  char ligne[256];   // pour stocker les lignes lues dans le fichier
  char epreuve_ligne[10];
  int heures, minutes, secondes;
  //chatgpt : permet de stocker dessus pour chaque athletes
  int temps[nbr_athletes], moyenne_temps[nbr_athletes];
  int total_temps = 0;
  int compt = 0;
  char nom_premier[255];
  char nom_deuxieme[255];
  char nom_troisieme[255];
  FILE *fichier;


  printf("\nQuelle est l'épreuve dont souhaitez-vous connaître ses 3 pires athlètes?");
  printf("\n1 : 100m \n2 : 400m \n3 : 5000m \n4 : marathon\n5 : relais\n 6 : natation \n");

  do {
    scanf("%d", &choix_epreuve);
    while (getchar() != '\n')
      ;
    if (choix_epreuve < 1 || choix_epreuve > 6) {
      printf("Choisir un numéro valable: "); // message d'erreur si mauvaise valeure
    }
  } while (choix_epreuve < 1 || choix_epreuve > 6);

  char *epreuve[] = {"100m", "400m", "5000m", "marathon", "relais", "natation"};

  for (int i = 0; i < nbr_athletes; i++) {
    //On remet tout à 0 pour la boucle pour chaque athlète
    compt = 0;
    total_temps = 0;
    moyenne_temps[i] = 0;
      // même chose que dans la fonction précédente
    fichier = fopen(nom_athletes[i], "r");
    if(fichier == NULL){
      printf("impossible d'ouvrir le fichier %s", nom_athletes[i]);
      exit(1);
    }

    while (fgets(ligne, sizeof(ligne), fichier)) { // lit les lignes du fichier
      if (sscanf(ligne, "Entraînement fait le %*s pour l'épreuve %s avec un temps de %d:%d:%d", epreuve_ligne, &heures, &minutes, &secondes) == 4) {
        if (strcmp(epreuve_ligne, epreuve[choix_epreuve - 1]) ==0) { 
          // Comparaison de l'épreuve dans le fichier avec celle du tableau
          // epreuve[] avec strcmp
          temps[i] = heures * 3600 + minutes * 60 + secondes;
          total_temps += temps[i];
          compt++;
          }
        }
      }
    if(compt>0){
      moyenne_temps[i] = total_temps / compt;
    }
    // fermer le fichier
    fclose(fichier);
  }//fin boucle for

  //par défaut le premier est le premier du tableau
  strcpy(nom_premier, nom_athletes[0]);
  int temps1 = moyenne_temps[0];

  int temps2 = 0;
  int temps3 = 0;

  for (int i = 1; i < nbr_athletes; i++) {
    if (moyenne_temps[i] > temps1) {
      temps3 = temps2; //on met à jour le top3
      strcpy(nom_troisieme,nom_deuxieme); 
      temps2 = temps1; // on met à jour le top2
      strcpy(nom_deuxieme,nom_premier);
      temps1 = moyenne_temps[i]; //on met à jour le top1
      strcpy(nom_premier,nom_athletes[i]);
    } else if (moyenne_temps[i]>temps2) { //2 cas
      temps3 = temps2; //à jour top3
      strcpy(nom_troisieme,nom_deuxieme);
      temps2 = moyenne_temps[i]; //jour top2
      strcpy(nom_deuxieme,nom_athletes[i]);
    } else if (moyenne_temps[i]>temps3) {
      temps3 = moyenne_temps[i]; //à jour top3
      strcpy(nom_troisieme,nom_athletes[i]);
    }
  }

  
  if(temps1 == 0){
    printf("\nAucun entraînement n'a été trouvé pour l'épreuve par conséquent personne n'est dans le classement\n");
  }

  else if(temps2 == 0){
     printf("\nEn 1re place nous avons %s avec son temps moyen de : %.2d:%.2d:%.2d\n", nom_premier, temps1/3600, (temps1%3600)/60, temps1%60);
    printf("\nNous avons que 1 athlète dans le top 3\n");
    printf("Il n'y a ni deuxième ni troisième pire athlète pour cette épreuve car c'est le seul à s'être entrainer.\n");
  }

  else if(temps3 == 0){
    printf("\nVos sportifs les moins performant sont :\n");
    printf("En 1re place nous avons %s avec son temps moyen de : %.2d:%.2d:%.2d\n", nom_premier, temps1/3600, (temps1%3600)/60, temps1%60);
    printf("En 2e place nous avons %s avec son temps moyen de : %.2d:%.2d:%.2d\n", nom_deuxieme, temps2/3600, (temps2%3600)/60, temps2%60);
    printf("\nNous avons que 2 athlètes dans le top 3\n");
    printf("Il n'y a pas de troisième pire athlète pour cette épreuve car ce sont les 2 seules à s'être entrainer.\n");
  }

  else{
    printf("\nVos sportifs les moins performant sont :\n");
    printf("En 1re place nous avons %s avec son temps moyen de : %.2d:%.2d:%.2d\n", nom_premier, temps1/3600, (temps1%3600)/60, temps1%60);
    printf("En 2e place nous avons %s avec son temps moyen de : %.2d:%.2d:%.2d\n", nom_deuxieme, temps2/3600, (temps2%3600)/60, temps2%60);
    printf("Et pour finir, en 3e place nous avons %s avec son temps moyen de : %.2d:%.2d:%.2d\n", nom_troisieme, temps3/3600, (temps3%3600)/60, temps3%60);
    }



  char reponse[4]; // Pour stocker "oui" ou "non"
  printf("Souhaitez-vous continuer à savoir qui sont les pires athlètes dans une autre épreuve? (oui/non):\n");
  oui_non(reponse); //appel de la fonction pour vérifier si l'utilisateur veut continuer ou non
  if (strcmp(reponse, "oui") == 0){
    pire_temps(nbr_athletes,nom_athletes);
  }   
  }


//************************************************************************************************************


// fonction indiquant la différence de temps pour une même épreuve entre deux dates
void diff_temps() {
  char nom[50];
  int choix_epreuve; // choix de l'épreuve avec un entier
  char ligne[256]; // pour stocker les lignes lues dans le fichier
  char epreuve_ligne[10], date[20]; // pour stocker le nom de l'épreuve et la de chaque ligne du fichier
  int temps, heures, minutes, secondes;
  int tab_temps[100];      // Tableau pour stocker les temps de chaque ligne du fichier
  char tab_dates[100][15]; // Tableau pour stocker les dates de chaque ligne du fichier
  int compt = 0;
  FILE *fichier;

  printf("\nDe quel athlète souhaitez-vous connaître la différence de temps pour une même épreuve ?\n");

  fichier = verifier_nom(nom); // vérifier existence du fichier et l'ouvre avec "r"

  printf("\nQuelle est l'épreuve dont souhaitez-vous connaître la différence de temps ?\n1 : 100m \n2 : 400m \n3 : 5000m \n4 : marathon\n5 : relais\n 6 : natation \n");

  do {
    scanf("%d", &choix_epreuve); //récupère la valeur de l'épreuve saisie par l'entraîneur 
    while (getchar() != '\n'); // vidage du buffer

    if (choix_epreuve < 1 || choix_epreuve > 6) {
      printf("Choisir un numéro valable"); // message d'erreur si mauvaise valeure
    }
  } while (choix_epreuve < 1 || choix_epreuve > 6);

  char *epreuves[6] = {"100m", "400m", "5000m", "marathon", "relais", "natation"}; // tableau qui contient les noms des épreuves

  while (fgets(ligne, sizeof(ligne), fichier)) { // lit les lignes du fichier
    // Vérifier si la ligne contient l'épreuve choisie
    if (sscanf(ligne, "Entraînement fait le %15s pour l'épreuve %s avec un temps de %d:%d:%d", date, epreuve_ligne, &heures, &minutes, &secondes) == 5) { // récupérer la date, l'épreuve et le temps du fichier
      if (strcmp(epreuve_ligne, epreuves[choix_epreuve - 1]) == 0) { // comparaison de l'épreuve dans le fichier avec celle du tableau epreuves[] 
        temps = heures * 3600 + minutes * 60 + secondes; // calcul du temps en secondes
        strcpy(tab_dates[compt], date); // copie la date dans le tableau tab_dates[]
        tab_temps[compt] = temps; // copie le temps en secondes dans le tableau tab_temps[] 
        compt++; // incrémentation du compteur afin de savoir s'il y a au moins 2 même épreuves 
      }
    }
  }

  if (compt >= 2) { // si au moins 2 même épreuves ont été trouvées
    printf("\nChoisissez deux dates parmi les suivantes pour comparer les temps:\n"); // demande à l'entraîneur de choisir deux dates

    // Afficher les dates trouvées ainsi que les temps correspondants
    for (int i = 0; i < compt; i++) {
      printf("  - Date %d: %s Temps %d: %.2d:%.2d:%.2d\n", i + 1, tab_dates[i], i + 1, tab_temps[i] / 3600, (tab_temps[i] % 3600) / 60, tab_temps[i] % 60);
    }

    int date1, date2;
    // Demander à l'entraîneur de choisir les deux dates à comparer
    do {
      printf("Première date (numéro): ");
      scanf("%d", &date1);
      printf("Deuxième date (numéro): ");
      scanf("%d", &date2);
      while (getchar() != '\n');

      if (date1 < 1 || date1 > compt || date2 < 1 || date2 > compt || date1 == date2) {
        printf("Choisissez deux dates valides.\n"); // message d'erreur si mauvaise valeure
      }
    } while (date1 < 1 || date1 > compt || date2 < 1 || date2 > compt || date1 == date2);

    // différence absolue entre les deux temps
    int diff_temps = abs(tab_temps[date1 - 1] - tab_temps[date2 - 1]); 
    // conversion de la différence de temps en heures, minutes et secondes
    int diff_heures = diff_temps / 3600;
    int diff_minutes = (diff_temps % 3600) / 60;
    int diff_secondes = diff_temps % 60;

    // Affichage des deux dates choisis
    printf("Comparaison entre le %s et le %s:\n", tab_dates[date1 - 1], tab_dates[date2 - 1]);
    // Affichage de la différence entre les deux temps
    printf("  - La différence de temps est %d heures, %d minutes, %d secondes\n", diff_heures, diff_minutes, diff_secondes);

  } else {
      printf("\nPas assez de données pour comparer deux dates.\n"); // message d'erreur si moins de deux dates

      char reponse[4]; // Chaîne pour stocker "oui" ou "non"
      printf("Souhaitez-vous continuer à chercher d'autres données sur la différence de temps pour un athlète ?(oui/non):\n");
      oui_non(reponse); //appel de la fonction pour vérifier si l'utilisateur veut continuer ou non
      if (strcmp(reponse, "oui") == 0) {
        diff_temps(); // récursivité : rappel de la fonction pour continuer une autre recherche
      }
    }

  fclose(fichier); //fermer le fichier correspondant 
}
