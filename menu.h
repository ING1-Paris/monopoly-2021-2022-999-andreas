#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct monopoly
{
    int maison;
    int hotel;
    int presence;
    int prix;

}t_mono;

typedef struct info_joueur // regroupe les infos d'un joueur
{
    char nom[30];
    int argent;
    int position[2]; // on garde en memoire la derniere case pour savoir si le joueur passe l'arrivé
    int possession [15]; //je pense qu'on fera une liste pour chaque case [0]
                         //avec le loyer de la case [1], le nb de maison [2]
                         //et le nb de l'hotel [3]

} info_joueur;

#include "sous-programmes.c"
#include "banque.c"

//dans sous-programmes
int nb_alea();
void lance_de(int etat_de[]);

//dans banque
void achat_vente_maison(info_joueur jeanMichel);
void hypotheque(info_joueur jeanMichel);

#endif // MENU_H_INCLUDED
