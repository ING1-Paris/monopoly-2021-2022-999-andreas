#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VILLE 0
#define GARE 1
#define CHANCE 2
#define COMM 3
#define PRISON 4
#define ARRIVE 5
#define PARC 6
#define IMPOT 7

typedef struct monopoly
{
    char type[20]; // ville, gare, chance, communaute, prison, depart, parc, impot
    int prix;
    int loyer;
    int presence;
    int maison;
    int hotel;// yen a pas besoin en fait ?
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
