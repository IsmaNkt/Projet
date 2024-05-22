#ifndef STATISTIQUE_H
#define STATISTIQUE_H

// procédure qui affiche les performances de l'athlète (meilleur et pire temps, moyenne, temps total)
void perf_athlete();

//fonction qui affiche le top3 meilleurs athlète dans une épreuve
void meilleur_temps(int nbr_athletes, char *nom_athletes[]);

//fonction qui affiche le top3 pire athlète dans une épreuve
void pire_temps(int nbr_athletes, char *nom_athletes[]);

// fonction indiquant la différence de temps pour une même épreuve entre deux dates
void diff_temps();

#endif
