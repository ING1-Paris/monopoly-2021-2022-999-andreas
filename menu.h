#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct info_joueur // regroupe les infos d'un joueur
{
    char nom[30];
    int argent;
    int position[2]; // on garde en memoire la derniere case pour savoir si le joueur passe l'arrivé
    int possession [20]; //je pense qu'on fera une liste pour chaque case
                         //avec le loyer de la case, le nb de maison
                         //et le nb de l'hotel

} info_joueur;

#include "sous-programmes.c"
#include "banque.c"


int nb_alea();
void lance_de(int etat_de[]);


#endif // MENU_H_INCLUDED
