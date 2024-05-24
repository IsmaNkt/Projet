# Gestion des Athlètes

Ce programme permet de gérer les athlètes et leurs entraînements dans différentes épreuves sportives. 
Il offre plusieurs fonctionnalités telles que:
  - Création de fichiers pour les athlètes
  - Ajout d'entraînements
  - Consultation de l'historique des entraînements
  - Affichage des performances des athlètes
  - Recherche des meilleurs et des pires athlètes dans une discipline
  - Comparaison des temps entre deux dates pour une même épreuve



# Structure du Projet
Le projet est composé des fichiers suivants :

1. main.c : Contient la fonction principale pour démarrer le programme


2. structure.h : Fichier d'en-tête contenant les structures utilisées dans le programme


3. affichage.c : Contient les fonctions pour afficher diverses informations et rapports liés aux athlètes et aux entraînements

   affichage.h : Fichier d'en-tête contenant la déclaration des fonctions pour afficher les informations et rapports


5. entrainement.c : Contient la fonction pour ajouter des entraînements
   
   entrainement.h : Fichier d'en-tête contenant la déclaration de la fonction du fichier entrainement.c


7. fathlete.c : Contient les fonctions pour manipuler les données des athlètes: formater les noms de fichiers et créer des fichiers pour chaque athlète
   
   fathlete.h : Fichier d'en-tête contenant les déclarations des fonctions de manipulation des données des athlètes


9. menu.c : Contient la fonction pour afficher le menu de toutes les fonctionnalités du programme
    
   menu.h : Fichier d'en-tête contenant la déclaration de la fonction du fichier menu.c


11. statistique.c : Contient les fonctions pour afficher les performances et la différence de temps entre deux dates pour une épreuve d'un athlète ainsi que les meilleurs et pires athlètes dans une épreuve
    
    statistique.h : Fichier d'en-tête contenant les déclarations des fonctions du fichier statistique.c


13. verification.c : Contient les fonctions pour valider un nom, vérifier l'existence d'un nom de fichier, récupérer un nom de fichier et vérifier si un sportif peut participer à un relais à une certaine date
    
    verification.h : Fichier d'en-tête contenant les déclarations des fonctions de vérification.c



# Utilisation
Assurez-vous que tous les fichiers .c et .h sont présents dans le répertoire de compilation

Pour utiliser le programme, compilez tous les fichiers source en utilisant votre compilateur C (gcc) à l'aide de la commande: make

Ensuite, exécutez le fichier exécutable à l'aide de la commande: ./main

Lors de l'exécution, suivez les instructions du menu pour accéder aux différentes fonctionnalités du programme



# Développeurs
Ce programme a été développé par Ismail NIAKATE, Alexis MURUGAN et Hugo TRAN-PHAT
