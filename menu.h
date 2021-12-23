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
    int type; // ville, gare, chance, communaute, prison, depart, parc, impot
    int prix;
    int loyer;
    int presence;
    int maison;
    int hotel;
    int hypo; // si c'est hypotheque ou pas

}t_mono;

typedef struct info_joueur // regroupe les infos d'un joueur
{
    int prison;
    int nb_double;
    char nom[30];
    int argent;
    int position[2]; // on garde en memoire la derniere case pour savoir si le joueur passe l'arrivé
    int possession [15]; //on met juste la place des proprieters, tout le reste est stocke dans le plateau

} info_joueur;

#include "sous-programmes.c"
#include "banque.c"

//dans sous-programmes
int nb_alea();
void lance_de(int etat_de[3]);

//dans banque
void menu_taches(info_joueur jeanMichel, t_mono plateau[32], int nb_maison, int nb_hotel);
void achat_vente_maison(info_joueur jeanMichel, t_mono plateau[32], int nb_maison, int nb_hotel);
void hypotheque(info_joueur jeanMichel, t_mono plateau[32], int nb_maison, int nb_hotel);

#endif // MENU_H_INCLUDED
