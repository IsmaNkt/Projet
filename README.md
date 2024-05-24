# Gestion des Athlètes

Ce programme permet de gérer les athlètes et leurs entraînements dans différentes épreuves sportives. 
Il offre plusieurs fonctionnalités telles que:
  - la création de fichiers pour les athlètes
  - l'ajout d'entraînements
  - la consultation de l'historique des entraînements
  - l'affichage des performances des athlètes
  - la recherche des meilleurs et des pires athlètes dans une discipline
  - la comparaison des temps entre deux dates pour une même épreuve


# Structure du Projet
Le projet est composé des fichiers suivants :

1. main.c : Contient la fonction principale pour démarrer le programme.
2. affichage.c : Contient les fonctions pour afficher diverses informations et rapports liés aux athlètes et aux entraînements.
3. affichage.h : Fichier d'en-tête contenant la déclaration des fonctions pour afficher les informations et rapports.
4. entrainement.c : Contient la fonction pour ajouter des entraînements.
5. entrainement.h : Fichier d'en-tête contenant la déclaration de la fonction du fichier entrainement.c.
6. fathlete.c : Contient les fonctions pour manipuler les données des athlètes.
7. fathlete.h : Fichier d'en-tête contenant les déclarations des fonctions de manipulation des données des athlètes.
8. menu.c : Contient les fonctions pour afficher le menu principal du programme.
9. menu.h : Fichier d'en-tête contenant les déclarations des fonctions du fichier menu.c.
10. statistique.c : Contient les fonctions pour afficher les performances des athlètes, les meilleurs athlètes dans une épreuve, les pires athlètes dans une épreuve et la différence de temps entre deux dates pour une épreuve.
11. statistique.h : Fichier d'en-tête contenant les déclarations des fonctions du fichier statistique.c
12. structure.h : Fichier d'en-tête contenant les définitions des structures utilisées dans le programme.
13. verification.c : Contient les fonctions pour valider un nom, vérifier l'existence d'un nom de fichier, récupérer un nom de fichier et vérifier si un sportif peut participer à un relais à une certaine date.
14. verification.h : Fichier d'en-tête contenant les déclarations des fonctions de vérification.


# Utilisation
Assurez-vous que tous les fichiers .c et .h sont présents dans le répertoire de compilation.
Pour utiliser le programme, compilez tous les fichiers source en utilisant votre compilateur C (gcc) à l'aide de la commande: make
Ensuite, exécutez le fichier exécutable à l'aide de la commande: ./main
Lors de l'exécution, suivez les instructions du menu pour accéder aux différentes fonctionnalités du programme.


# Développeurs
Ce programme a été développé par Ismail NIAKATE, Alexis MURUGAN et Hugo TRAN-PHAT.
