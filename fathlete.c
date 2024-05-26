#include "structure.h"
#include "verification.h"
#include "fathlete.h"

// Fonction pour mettre en majuscule la première lettre d'un mot
void majuscule_premiere_lettre(char *mot) {
    if (mot[0] != '\0') { 
        mot[0] = toupper(mot[0]);
    }
}

//**********************************************************************************************************************************

// Fonction pour mettre en minuscule toutes les lettres sauf la première
void minuscule_sauf_premiere_lettre(char *mot) {
    for (int i = 1; mot[i] != '\0'; i++) { //commencer à l'indice 1 pour ne pas mettre en minuscule la première lettre
        mot[i] = tolower(mot[i]);
    }
}

//**********************************************************************************************************************************

// Fonction pour mettre un nom de fichier sous la forme: Prenom_Nom
void format_nom_fichier(char *nom) {
    char prenom[50], nom_famille[50];
    int underscore_indice = -1;
    int taille = strlen(nom); //récupérer la taille de la chaîne 'nom'

    // Trouver l'indice de l'underscore
    for (int i = 0; i < taille; i++) {
        if (nom[i] == '_') {
            underscore_indice = i;
            break; //Sorti de la boucle une fois que l'underscore a été trouvé
        }
    }

    // On sépare le prénom et le nom
    strncpy(prenom, nom, underscore_indice); // Copie les caractères de la chaîne 'nom' jusqu'à l'underscore aide de chat gpt
    prenom[underscore_indice] = '\0'; // Ajoute le caractère nul à la fin du prénom pour terminer la chaîne
    strcpy(nom_famille, nom + underscore_indice + 1); // Copie les caractères de la chaîne 'nom' juste après l'underscore

    // Mettre la première lettre en majuscule et le reste en minuscule pour le prénom
    majuscule_premiere_lettre(prenom);
    minuscule_sauf_premiere_lettre(prenom);

    // Mettre la première lettre en majuscule et le reste en minuscule pour le nom de famille
    majuscule_premiere_lettre(nom_famille);
    minuscule_sauf_premiere_lettre(nom_famille);

    // Assembler le prénom et le nom de famille dans la chaine de caractere 'nom'
    sprintf(nom, "%s_%s", prenom, nom_famille);
}


//************************************************************************************************************

// procédure créant un fichier pour un athlète
void creerFichier(int nbr_athletes, char **nom_athletes) {
    char nom[50];
    FILE * fichier;

    for (int i = 0; i < nbr_athletes; i++) { // on affiche le numéro du fichier actuel à 1 et non à 0
        do {
          printf("\nEntrez le nom du sportif %d (de la forme 'Prenom_Nom'): ", i + 1);
          scanf("%s", nom);
          while (getchar() != '\n'); // Vidage du buffer
            
          if (valideNom(nom) != 1) {
            printf("Entrée invalide ! Réessayer.\n");
          }
        } while (valideNom(nom) != 1);
        
        format_nom_fichier(nom); // Fonction pour mettre un nom de fichier sous la forme: Prenom_Nom

        // vérifier si le fichier existe déjà
        

        
        fichier = fopen(nom, "w"); // permet de créer et d'ouvir un fichier avec le nom saisi par l'utilisateur, en mode écriture
        if (fichier == NULL) {
          printf("\nImpossible d'ouvrir le fichier %s. \n", nom);
          exit(1);
        }
  
        nom_athletes[i] = strdup(nom); // aide de chatgpt pour dupliquer la chaîne de caractère vers une autre chaîne de caractère qui est alloué dynamiquement 
        fclose(fichier);   
        printf("  --> Voici le nom du fichier créé: %s\n", nom); //afficher le nom du fichier créé
    }

  return;
}
