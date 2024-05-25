#include "structure.h"
#include "entrainement.h"
#include "verification.h"

// Fonction qui permet d'ajouter un seul entraînement par ligne à un fichier de sportif
void AjouterEntrainement() {
  char nomS[4][50];
  char reponse[4];
  int choix = 0;
  Sportif *s = malloc(sizeof(Sportif));
  if (s == NULL) {
    printf("Erreur allocation de la mémoire sportif.\n");
    exit(2);
  }

  // chatgpt : sans cela le programme fonctionne pas
  s->exercice = malloc(sizeof(Entrainement));
  if (s->exercice == NULL) {
    printf("Erreur allocation de la mémoire entrainement.\n");
    free(s);
    exit(3);
  }

  printf("\nVous êtes ici pour ajouter un entrainement à l'un de vos sportif\n");

  // Choisir l'épreuve d'entraînement
  printf("Quelle est l'épreuve réalisée?(choisir le bon nombre): \n 1 : "
         "100m \n 2 : 400m \n 3 : 5000m \n 4 : marathon\n 5 : relais\n 6 : natation\n 7 : boxe\n 8 : judo\n 9 : escrime\n");

  do {
    scanf("%d", &choix);
    while (getchar() != '\n'); // Vider le buffer d'entrée

    if (choix < 1 || choix > 9) {
      printf("Choisissez un numéro valable.\n"); // condition "si" l'utilisateur choisi la mauvaise valeur
    }
  } while (choix < 1 || choix > 9);

  
  //********************************************************************
  //cas boxe + judo + escrime (basé sur le sport de boxe)

  if(choix == 7 || choix == 8 || choix == 9 ){

    printf("Avez-vous 2 sportifs? (oui/non)\n");

    // chaine de caractere obligaire pour le scanf
    char r[10];
    do {
      scanf("%s", r); // Lire jusqu'à 3 caractères pour stocker "oui" ou "non"
                       // plus le caractère nul

      // strcmp pour comparer des chaînes de caractères
      if (strcmp(r, "oui") != 0 && strcmp(r, "non") != 0) {
        printf("Erreur, veuillez réessayer en répondant 'oui' ou 'non'\n");
      }
    } while (strcmp(r, "oui") != 0 && strcmp(r, "non") != 0);

    if (strcmp(r, "non") == 0) {
      printf("Il faut avoir 2 sportifs pour pouvoir faire cette épreuve de "
             "relais...L'épreuve est annulé'\n"
             "Revenez lorsque vous les aurez.\n");
      printf("Choissisez une autre épreuve.\n");
      free(s->exercice);
      free(s);
      return (AjouterEntrainement());
    }

    // On vérifie que l'utilaisateur a bien 2 sportifs
    printf("On vérifie...\n");
    printf("Choisir les 2 sportifs différents que vous avez.\n");
    for (int i = 0; i < 2; i++) {
      printf("Choisir le sportif n°%d :\n", i + 1);
      verifier_nom2(nomS[i]);
    }
    if (strcmp(nomS[0], nomS[1]) == 0) {
      printf("\nIl n'y a pas assez d'athlètes. Veuillez choisir une autre épreuve.\n");
      free(s->exercice);
      free(s);
      return (AjouterEntrainement());
    }

    printf("\n vérification terminée.\n");
    printf("Il est temps de choisir vos 2 sportifs pour l'épreuve.\n");
    printf("Choisir les athlètes qui vont participer.\n");
    do {
      for (int i = 0; i < 2; i++) {
        printf("Choisir l'althlète n°%d :\n", i + 1);
        verifier_nom2(nomS[i]);
      }
      if (strcmp(nomS[0], nomS[1]) == 0) {
        printf("\nLes sportifs ne peuvent pas être identiques.\n");
        printf("Choisir 2 athlètes différents.\n");
      }
    } while (strcmp(nomS[0], nomS[1]) == 0);

    // choisir la date d'entrainement
    printf("\nQuand va-t-il s'entraîner ? (forme: jour/mois/annee):\n");
    do {
      printf("Choisir le jour : \n");
      scanf("%d", &s->exercice->date.jour);

      if (s->exercice->date.jour < 1 || s->exercice->date.jour > 31) {
        printf("Choisissez entre 1 et 31.\n"); // messagge d'erreur si l'utilisateur saisit une valeur invalide
        while (getchar() != '\n');
      }
    } while (s->exercice->date.jour < 1 || s->exercice->date.jour > 31);

    do {
      printf("Choisir le mois : ");
      scanf("%d", &s->exercice->date.mois);
      if (s->exercice->date.mois < 1 || s->exercice->date.mois > 12) {
        printf("Choisissez entre 1 et 12.\n"); // messagge d'erreur si l'utilisateur saisit une valeur invalide
        while (getchar() != '\n');
      }
    } while (s->exercice->date.mois < 1 || s->exercice->date.mois > 12);

    do {
        printf("Choisir l'année: ");
        scanf("%d", &s->exercice->date.annee);
        if (s->exercice->date.annee < 2024 || s->exercice->date.annee > 2124) {
            printf("Nous sommes en 2024...\n"); // messagge d'erreur si l'utilisateur
            printf("Choisir une année entre 2024 et 2124.\n"); // saisit une valeur invalide
            while (getchar() != '\n');
        }
    } while (s->exercice->date.annee < 2024 || s->exercice->date.annee > 2124);

   //choisir son temps d'entrainement
    int round = 0;
    int hasard = 0;
    char res[50];
    char res1[50];
    s->exercice->temps.heure = 0;
    s->exercice->temps.seconde = 0;

    printf("Combien de round voulez-vous?\n");
    do {
      scanf("%d", &round); // saisi heure
      if (round < 1 || round > 12) {
        printf("Choisir entre 1 et 12 round\n"); // messagge d'erreur si l'utilisateur
                                      // saisit une valeur invalide
        while (getchar() != '\n'); //  eviter boucle infini
      }
    } while (round < 1 || round > 12);

    char change[50];

    if (choix == 7) {
      char change1[] = "boxe";
      strcpy(change, change1);
    } else if (choix == 8) {
      char change1[] = "judo";
      strcpy(change, change1);
    } else if (choix == 9) {
      char change1[] = "escrime";
      strcpy(change, change1);
    }
    s->exercice->temps.minute = (round * 3) + (round * 2);
    hasard = rand()%2+1; //choisit le vainqueur

    if (hasard == 1){
      strcpy(res, "vainqueur");
      strcpy(res1, "vaincu");

    } else {
      strcpy(res,"vaincu");
      strcpy(res1, "vainqueur");
      }
    // Écrire les détails de l'entraînement dans les fichiers des 4 sportifs
    printf("\nLors de cet entrainement de %s en %d round : \n", change, round);
    
    for (int i = 0; i < 2; i++) {
      FILE *fichier1 = fopen(nomS[i], "a");
      if (fichier1 == NULL) {
        printf("L'ouverture du fichier %s a échoué\n", nomS[i]);
      }
      if(i==1){
        strcpy(res, res1);
      }

      fprintf(fichier1,
              "Entraînement fait le %.2d/%.2d/%d pour l'épreuve %s avec un temps "
              "de %.2d:%.2d:%.2d\n",
              s->exercice->date.jour, s->exercice->date.mois,
              s->exercice->date.annee, change, s->exercice->temps.heure,
              s->exercice->temps.minute, s->exercice->temps.seconde);
      fclose(fichier1);

      printf("%s a été le %s de cet entrainement\n", nomS[i], res);
      
    
    }
    printf("\nVoulez-vous ajouter un autre entraînement ?(oui/non):\n");
    oui_non(reponse);
    if (strcmp(reponse, "oui") == 0){
      return AjouterEntrainement();
    }
  } 

  //**************************************************************************************
  // Cas relais
  else if (choix == 5) {

    printf("Avez-vous 4 sportifs? (oui/non):\n");

    // chaine de caractere obligaire pour le scanf
    char r[10];
    do {
      scanf("%s", r); // Lire jusqu'à 3 caractères pour stocker "oui" ou "non"
                       // plus le caractère nul

      // strcmp pour comparer des chaînes de caractères
      if (strcmp(r, "oui") != 0 && strcmp(r, "non") != 0) {
        printf("Erreur, veuillez réessayer en répondant 'oui' ou 'non'\n");
      }
    } while (strcmp(r, "oui") != 0 && strcmp(r, "non") != 0);

    if (strcmp(r, "non") == 0) {
      printf("Il faut avoir 4 sportifs pour pouvoir faire cette épreuve de "
             "relais...\n"
             "Revener lorsque vous les aurez.\n");
      printf("On vous laisse l'occasion de choisir une autre épreuve en attendant, à plus tard\n");
      free(s->exercice);
      free(s);
      return AjouterEntrainement(); // on quitte la fontion
    }

    // On vérifie que l'utilaisateur a bien 4 sportifs
    printf("On vérifie...\n");
    printf("Choisir les 4 sportifs différents que vous avez.\n");
    for (int i = 0; i < 4; i++) {
      printf("Choisir le sportif n°%d :\n", i + 1);
      verifier_nom2(nomS[i]);
    }
    if (strcmp(nomS[0], nomS[1]) == 0 || strcmp(nomS[0], nomS[2]) == 0 ||
        strcmp(nomS[0], nomS[3]) == 0 || strcmp(nomS[1], nomS[2]) == 0 ||
        strcmp(nomS[1], nomS[3]) == 0 || strcmp(nomS[2], nomS[3]) == 0) {
      printf("\nIl n'y a pas assez d'athlètes. Veuillez choisir une autre épreuve.\n");
      free(s->exercice);
      free(s);
      return AjouterEntrainement();
    }

    printf("\n vérification terminée.\n");
    printf("Il est temps de choisir vos 4 sportifs pour le relais.\n");
    printf("Les sportifs doivent être choisis dans l'ordre de positionnement "
           "dans le relais.\n");
    do {
      for (int i = 0; i < 4; i++) {
        printf("Choisir le sportif n°%d :\n", i + 1);
        verifier_nom2(nomS[i]);
      }
      if (strcmp(nomS[0], nomS[1]) == 0 || strcmp(nomS[0], nomS[2]) == 0 ||
          strcmp(nomS[0], nomS[3]) == 0 || strcmp(nomS[1], nomS[2]) == 0 ||
          strcmp(nomS[1], nomS[3]) == 0 || strcmp(nomS[2], nomS[3]) == 0) {
        printf("\nLes sportifs ne peuvent pas être identiques.\n");
        printf("Choisir 4 sportifs différents.\n");
      }
    } while (strcmp(nomS[0], nomS[1]) == 0 || strcmp(nomS[0], nomS[2]) == 0 ||
             strcmp(nomS[0], nomS[3]) == 0 || strcmp(nomS[1], nomS[2]) == 0 ||
             strcmp(nomS[1], nomS[3]) == 0 || strcmp(nomS[2], nomS[3]) == 0);

    // choisir la date d'entrainement
    printf("\nQuand va-t-il s'entraîner ? (forme: jour/mois/annee):\n");
    do {
      printf("Choisir le jour : \n");
      scanf("%d", &s->exercice->date.jour);

      if (s->exercice->date.jour < 1 || s->exercice->date.jour > 31) {
        printf("Choisissez entre 1 et 31.\n"); // messagge d'erreur si
                                               // l'utilisateur saisit une
                                               // valeur invalide
        while (getchar() != '\n')
          ;
      }
    } while (s->exercice->date.jour < 1 || s->exercice->date.jour > 31);

    do {
      printf("Choisir le mois : ");
      scanf("%d", &s->exercice->date.mois);
      if (s->exercice->date.mois < 1 || s->exercice->date.mois > 12) {
        printf("Choisissez entre 1 et 12.\n"); // messagge d'erreur si
                                               // l'utilisateur saisit une
                                               // valeur invalide
        while (getchar() != '\n')
          ;
      }
    } while (s->exercice->date.mois < 1 || s->exercice->date.mois > 12);

    do {
      printf("Choisir l'année: ");
      scanf("%d", &s->exercice->date.annee);
      if (s->exercice->date.annee < 2024 || s->exercice->date.annee > 2124) {
        printf(
            "Nous sommes en 2024...\n"); // messagge d'erreur si l'utilisateur
        printf("Choisir une date entre 2024 et 2124.\n"); // saisit une valeur
                                                         // invalide
        while (getchar() != '\n')
          ;
      }
    } while (s->exercice->date.annee < 2024 || s->exercice->date.annee > 2124);

    printf("Nous vérifions... \n"); // verification de la date du relais
    for (int i = 0; i < 4; i++) {
      FILE *fichier1 = fopen(nomS[i], "a");
      if (fichier1 == NULL) {
        printf("L'ouverture du fichier %s a échoué\n", nomS[i]);
      }
      if (VerifierDateRelais(nomS[i], s->exercice->date)) {
        free(s->exercice);
        free(s);
        printf("\nNous vous laissons l'occasion de choisir un autre entrainement\n");
        return AjouterEntrainement();
      }
    }

    // Choisir le temps d'entrainement
    printf("\nCombien de temps vont durer leurs entrainement en tout? (de la "
           "forme : h:m:s)\n");
    do {
      printf("Choisir le nombre d'heures : ");
      scanf("%d", &s->exercice->temps.heure); // saisi heure
      if (s->exercice->temps.heure < 1 || s->exercice->temps.heure > 15) {
        printf(
            "Choisissez entre 1 et 15 heures\n Même s'ils sont plusieurs ils "
            "ont besoin de repos\n"); // messagge d'erreur si l'utilisateur
                                      // saisit une valeur invalide
        while (getchar() != '\n')
          ; //  eviter boucle infini
      }
    } while (s->exercice->temps.heure < 1 || s->exercice->temps.heure > 15);

    do {
      printf("Choisir le nombre de minutes: ");
      scanf("%d", &s->exercice->temps.minute); // saisi minute
      if (s->exercice->temps.minute < 1 || s->exercice->temps.minute > 59) {
        printf("Choisissez entre 1 et 59 minutes.\n"); // messagge d'erreur si
                                                       // l'utilisateur saisit
                                                       // une valeur invalide
        while (getchar() != '\n')
          ;
      }
    } while (s->exercice->temps.minute < 1 || s->exercice->temps.minute > 59);

    do {
      printf("Choisir le nombre de secondes: ");
      scanf("%d", &s->exercice->temps.seconde); // saisi seconde
      if (s->exercice->temps.seconde < 1 || s->exercice->temps.seconde > 59) {
        printf("Choisissez entre 1 et 59 secondes.\n"); // messagge d'erreur si
                                                        // l'utilisateur saisit
                                                        // une valeur invalide
        while (getchar() != '\n');
      }
    } while (s->exercice->temps.seconde < 1 || s->exercice->temps.seconde > 59);

    // Écrire les détails de l'entraînement dans les fichiers des 4 sportifs
    for (int i = 0; i < 4; i++) {
      FILE *fichier1 = fopen(nomS[i], "a");
      if (fichier1 == NULL) {
        printf("L'ouverture du fichier %s a échoué\n", nomS[i]);
      }

      fprintf(fichier1,
              "Entrainement fait le %d/%d/%d pour l'épreuve relais avec un "
              "temps de %d:%d:%d en ayant la position %d \n",
              s->exercice->date.jour, s->exercice->date.mois,
              s->exercice->date.annee, s->exercice->temps.heure,
              s->exercice->temps.minute, s->exercice->temps.seconde, i + 1);

      fclose(fichier1);
    }
    printf("\nVoulez-vous ajouter un autre entraînement ?(oui/non):\n");
    oui_non(reponse);
    if (strcmp(reponse, "oui") == 0){
      return AjouterEntrainement();
    }
  }
  // fin du cas relais
  //********************************************************************************************
//cas piscine
  else if (choix == 6){

      printf("Avez-vous 4 sportifs? (oui/non):\n");

      // chaine de caractere obligaire pour le scanf
      char r[10];
      do {
        scanf("%s", r); // Lire jusqu'à 3 caractères pour stocker "oui" ou "non"
                         // plus le caractère nul

        // strcmp pour comparer des chaînes de caractères
        if (strcmp(r, "oui") != 0 && strcmp(r, "non") != 0) {
          printf("Erreur, veuillez réessayer en répondant 'oui' ou 'non'\n");
        }
      } while (strcmp(r, "oui") != 0 && strcmp(r, "non") != 0);

      if (strcmp(r, "non") == 0) {
        printf("Il faut avoir 4 sportifs pour pouvoir faire cette épreuve de "
               "natation...\n"
               "Revenez lorsque vous les aurez.\n");
        printf("On vous laisse l'occasion de choisir une autre épreuve en attendant, à plus tard\n");
        free(s->exercice);
        free(s);
        AjouterEntrainement(); // on quitte la fontion
      }

      // On vérifie que l'utilaisateur a bien 4 sportifs
      printf("On vérifie...\n");
      printf("Choisir les 4 sportifs différents que vous avez.\n");
      for (int i = 0; i < 4; i++) {
        printf("Choisir le sportif n°%d :\n", i + 1);
        verifier_nom2(nomS[i]);
      }
      if (strcmp(nomS[0], nomS[1]) == 0 || strcmp(nomS[0], nomS[2]) == 0 ||
          strcmp(nomS[0], nomS[3]) == 0 || strcmp(nomS[1], nomS[2]) == 0 ||
          strcmp(nomS[1], nomS[3]) == 0 || strcmp(nomS[2], nomS[3]) == 0) {
        printf("\nIl n'y a pas assez d'athlètes. Veuillez choisir une autre épreuve.\n");
        free(s->exercice);
        free(s);
        return AjouterEntrainement();
      }

      printf("\nLa vérification a été faite.\n");
      printf("Il est temps de choisir vos 4 sportifs pour faire de la natation.\n");
      do {
        for (int i = 0; i < 4; i++) {
          printf("Choisir le sportif n°%d :\n", i + 1);
          verifier_nom2(nomS[i]);
        }
        if (strcmp(nomS[0], nomS[1]) == 0 || strcmp(nomS[0], nomS[2]) == 0 ||
            strcmp(nomS[0], nomS[3]) == 0 || strcmp(nomS[1], nomS[2]) == 0 ||
            strcmp(nomS[1], nomS[3]) == 0 || strcmp(nomS[2], nomS[3]) == 0) {
          printf("\nLes sportifs ne peuvent pas être identiques.\n");
          printf("Choisir 4 sportifs différents.\n");
        }
      } while (strcmp(nomS[0], nomS[1]) == 0 || strcmp(nomS[0], nomS[2]) == 0 ||
               strcmp(nomS[0], nomS[3]) == 0 || strcmp(nomS[1], nomS[2]) == 0 ||
               strcmp(nomS[1], nomS[3]) == 0 || strcmp(nomS[2], nomS[3]) == 0);

      // choisir la date d'entrainement
      printf("\nQuand va-t-il s'entraîner ? (forme: jour/mois/annee):\n");
      do {
        printf("Choisir le jour : \n");
        scanf("%d", &s->exercice->date.jour);

        if (s->exercice->date.jour < 1 || s->exercice->date.jour > 31) {
          printf("Choisissez entre 1 et 31.\n"); // messagge d'erreur si
                                                 // l'utilisateur saisit une
                                                 // valeur invalide
          while (getchar() != '\n')
            ;
        }
      } while (s->exercice->date.jour < 1 || s->exercice->date.jour > 31);

      do {
        printf("Choisir le mois : ");
        scanf("%d", &s->exercice->date.mois);
        if (s->exercice->date.mois < 1 || s->exercice->date.mois > 12) {
          printf("Choisissez entre 1 et 12.\n"); // messagge d'erreur si
                                                 // l'utilisateur saisit une
                                                 // valeur invalide
          while (getchar() != '\n')
            ;
        }
      } while (s->exercice->date.mois < 1 || s->exercice->date.mois > 12);

      do {
        printf("Choisir l'année: ");
        scanf("%d", &s->exercice->date.annee);
        if (s->exercice->date.annee < 2024 || s->exercice->date.annee > 2124) {
          printf(
              "Nous sommes en 2024...\n"); // messagge d'erreur si l'utilisateur
          printf("Choisir une date entre 2024 et 2124.\n"); // saisit une valeur
                                                           // invalide
          while (getchar() != '\n')
            ;
        }
      } while (s->exercice->date.annee < 2024 || s->exercice->date.annee > 2124);


      // Choisir le temps d'entrainement
    int exercice;
    printf("\nQuelle série d'entrainement voulez-vous faire?\n");

    //On choisit l'exercice à faire
    printf("1 : Papillon\n 2 : Crawl\n 3 : Brasse \n 4 : Dos à un bras \n 5 : Dos à deux bras       \n");
    do {
      printf("Choisir l'exercice : ");
      scanf("%d", &exercice); // saisit choix
      if (exercice < 1 || exercice > 5 ){
        printf("Choisir l'un des exercicice proposé\n"); 
        // messagge d'erreur si l'utilisateur
        // saisit une valeur invalide
        while (getchar() != '\n')
          ; //  eviter boucle infini
      }
    } while (exercice < 1 || exercice > 5);

    ////
      printf("\nCombien de temps vont durer leurs entrainement en tout? (de la "
             "forme : h:m:s)\n");
      do {
        printf("Choisir le nombre d'heures : ");
        scanf("%d", &s->exercice->temps.heure); // saisi heure
        if (s->exercice->temps.heure < 1 || s->exercice->temps.heure > 15) {
          printf(
              "Choisissez entre 1 et 15 heures\n Même s'ils sont plusieurs ils "
              "ont besoin de repos\n"); // messagge d'erreur si l'utilisateur
                                        // saisit une valeur invalide
          while (getchar() != '\n')
            ; //  eviter boucle infini
        }
      } while (s->exercice->temps.heure < 1 || s->exercice->temps.heure > 15);

      do {
        printf("Choisir le nombre de minutes: ");
        scanf("%d", &s->exercice->temps.minute); // saisi minute
        if (s->exercice->temps.minute < 1 || s->exercice->temps.minute > 59) {
          printf("Choisissez entre 1 et 59 minutes.\n"); // messagge d'erreur si
                                                         // l'utilisateur saisit
                                                         // une valeur invalide
          while (getchar() != '\n')
            ;
        }
      } while (s->exercice->temps.minute < 1 || s->exercice->temps.minute > 59);

      do {
        printf("Choisir le nombre de secondes: ");
        scanf("%d", &s->exercice->temps.seconde); // saisi seconde
        if (s->exercice->temps.seconde < 1 || s->exercice->temps.seconde > 59) {
          printf("Choisissez entre 1 et 59 secondes.\n"); // messagge d'erreur si
                                                          // l'utilisateur saisit
                                                          // une valeur invalide
          while (getchar() != '\n');
        }
      } while (s->exercice->temps.seconde < 1 || s->exercice->temps.seconde > 59);


    char change[50];

    if (exercice == 1) {
      char change1[] = "Pappilon";
      strcpy(change, change1);
    } else if (exercice == 2) {
      char change1[] = "Crawl";
      strcpy(change, change1);
    } else if (exercice == 3) {
      char change1[] = "Brasse";
      strcpy(change, change1);
    } else if (exercice == 4) {
      char change1[] = "Dos à un bras";
      strcpy(change, change1);
    } else if (exercice == 5) {
      char change1[] = "Dos à deux bras";
      strcpy(change, change1);
    }
      // Écrire les détails de l'entraînement dans les fichiers des 4 sportifs
    printf("\nLes entrainements de %s ont été :\n",change);
      for (int i = 0; i < 4; i++) {
        FILE *fichier1 = fopen(nomS[i], "a");
        if (fichier1 == NULL) {
          printf("L'ouverture du fichier %s a échoué\n", nomS[i]);
        }

        fprintf(fichier1,
                "Entrainement fait le %d/%d/%d pour l'épreuve natation avec un "
                "temps de %d:%d:%d\n",
                s->exercice->date.jour, s->exercice->date.mois,
                s->exercice->date.annee, s->exercice->temps.heure,
                s->exercice->temps.minute, s->exercice->temps.seconde);

        fclose(fichier1);


        printf("Prévu pour %s \n" , nomS[i]);

        

        
      }

      
      printf("\nVoulez-vous ajouter un autre entraînement ?(oui/non):\n");
      oui_non(reponse);
      if (strcmp(reponse, "oui") == 0){
        return AjouterEntrainement();
      }
    }
  
    // fin du cas piscine



//********************************************************************************************
  // sport solo
  else {
    printf("Pour quel sportif voulez-vous ajouter un entraînement ?\n");
    FILE *fichier;
    fichier = verifier_nom(s->nom); // fonction qui retourne un fichier s'il existe
    fclose(fichier);
    // On ouvre en "a" pour pouvoir ajouter à la fin du fichier car la fonction
    // au-dessus ouvre en "r"
    fichier = fopen(s->nom, "a");
    if (fichier == NULL) {
      printf("Le fichier ne s'ouvre pas\n");
      free(s->exercice);
      free(s);
      exit(4);
    }

    // choisir la date d'entrainement
    printf("\nQuand va-t-il s'entraîner ? (forme: jour/mois/annee):\n");
    do {
      printf("Choisir le jour : \n");
      scanf("%d", &s->exercice->date.jour);

      if (s->exercice->date.jour < 1 || s->exercice->date.jour > 31) {
        printf("Choisissez entre 1 et 31.\n"); // messagge d'erreur si
                                               // l'utilisateur saisit une
                                               // valeur invalide
        while (getchar() != '\n');
      }
    } while (s->exercice->date.jour < 1 || s->exercice->date.jour > 31);

    do {
      printf("Choisir le mois : ");
      scanf("%d", &s->exercice->date.mois);
      if (s->exercice->date.mois < 1 || s->exercice->date.mois > 12) {
        printf("Choisissez entre 1 et 12.\n"); // messagge d'erreur si
                                               // l'utilisateur saisit une
                                               // valeur invalide
        while (getchar() != '\n');
      }
    } while (s->exercice->date.mois < 1 || s->exercice->date.mois > 12);

    do {
      printf("Choisir l'année: ");
      scanf("%d", &s->exercice->date.annee);
      if (s->exercice->date.annee < 2024 || s->exercice->date.annee > 2124) {
        printf(
            "Nous sommes en 2024...\n"); // messagge d'erreur si l'utilisateur
        printf("Choisir une année entre 2024 et 2124.\n"); // saisit une valeur
                                                         // invalide
        while (getchar() != '\n')
          ;
      }
    } while (s->exercice->date.annee < 2024 || s->exercice->date.annee > 2124);


    // Choisir le temps d'entrainement
    printf(
        "\nCombien de temps va durer son entraînement ? (de la forme : h:m:s)\n");
    do {
      printf("Choisir le nombre d'heures : ");
      scanf("%d", &s->exercice->temps.heure); // saisi heure
      if (s->exercice->temps.heure < 1 || s->exercice->temps.heure > 15) {
        printf("Choisissez entre 1 et 15 heures\n un bon athlète à besoin de "
               "temps pour dormir et manger\n"); // messagge d'erreur si
                                                 // l'utilisateur saisit une
                                                 // valeur invalide
        while (getchar() != '\n')
          ; //  eviter boucle infini
      }
    } while (s->exercice->temps.heure < 1 || s->exercice->temps.heure > 15);

    do {
      printf("Choisir le nombre de minutes: ");
      scanf("%d", &s->exercice->temps.minute); // saisi minute
      if (s->exercice->temps.minute < 1 || s->exercice->temps.minute > 59) {
        printf("Choisissez entre 1 et 59 minutes.\n"); // messagge d'erreur si
                                                       // l'utilisateur saisit
                                                       // une valeur invalide
        while (getchar() != '\n')
          ;
      }
    } while (s->exercice->temps.minute < 1 || s->exercice->temps.minute > 59);

    do {
      printf("Choisir le nombre de secondes: ");
      scanf("%d", &s->exercice->temps.seconde); // saisi seconde
      if (s->exercice->temps.seconde < 1 || s->exercice->temps.seconde > 59) {
        printf("Choisissez entre 1 et 59 secondes.\n"); // messagge d'erreur si
                                                        // l'utilisateur saisit
                                                        // une valeur invalide
        while (getchar() != '\n')
          ;
      }
    } while (s->exercice->temps.seconde < 1 || s->exercice->temps.seconde > 59);

    char change[50];

    if (choix == 1) {
      char change1[] = "100m";
      strcpy(change, change1);
    } else if (choix == 2) {
      char change1[] = "400m";
      strcpy(change, change1);
    } else if (choix == 3) {
      char change1[] = "5000m";
      strcpy(change, change1);

    } else if (choix == 4) {
      char change1[] = "marathon";
      strcpy(change, change1);
    }

    // ecrire les details de l'entrainement dans le fichier
    fprintf(fichier,
            "Entraînement fait le %.2d/%.2d/%d pour l'épreuve %s avec un temps "
            "de %.2d:%.2d:%.2d\n",
            s->exercice->date.jour, s->exercice->date.mois,
            s->exercice->date.annee, change, s->exercice->temps.heure,
            s->exercice->temps.minute, s->exercice->temps.seconde);
    fclose(fichier);

    // on libère tout
    free(s->exercice);
    free(s);
    
    printf("\nl'entrainement qui consiste au %s a été ajouté à vôtre athlète\n",change);
    // on demande si l'utilisateur veut ajouter un autre entrainement
    printf("\nVoulez-vous ajouter un autre entraînement ?(oui/non):\n");
    oui_non(reponse);
    if (strcmp(reponse, "oui") == 0){
      return AjouterEntrainement();
    }
  }

}
