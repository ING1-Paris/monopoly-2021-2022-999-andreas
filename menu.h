#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct monopoly
{
    char type[20]; // ville, gare, chance, communaute, prison, depart, parc
    int prix;
    int presence;
    int maison;
    int hotel;
    int hypo;

}t_mono;

typedef struct info_joueur // regroupe les infos d'un joueur
{

    int prison;
    int nb_double;
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
void lance_de(int etat_de[3]);

//dans banque
void achat_vente_maison(info_joueur jeanMichel);
void hypotheque(info_joueur jeanMichel);

#endif // MENU_H_INCLUDED
