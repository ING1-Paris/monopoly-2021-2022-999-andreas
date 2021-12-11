#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sous-programmes.c"

struct info_joueur // regroupe les infos d'un joueur
{
    int argent;
    int position[2]; // on garde en memoire la derniere case pour savoir si le joueur passe l'arrivé
    int possession [20]; //je pense qu'on fera une liste pour chaque case
                         //avec le loyer de la case, le nb de maison
                         //et le nb de l'hotel

} ;

int nb_alea();
int lancer_de();
void banque();

#endif // MENU_H_INCLUDED
