#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LEN 60 //taille d'un nom de fichier

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
    int position[2]; // on garde en memoire la derniere case pour savoir si le joueur passe l'arriv�
    int possession [20]; //on met juste la place des proprieters, tout le reste est stocke dans le plateau

} info_joueur;

#include "sous-programmes.c"
#include "banque.c"

//dans sous-programmes
int nb_alea();
void lance_de(int etat_de[3]);
int info_case(int info_villes[19][9], int la_case_choisi, int info_a_rendre);
int init_sauvegarde(info_joueur tabjoueurs[] ,t_mono plateau[32], char fichiers[2][LEN]);
int sauvegarde(info_joueur tabjoueurs[] ,t_mono plateau[32], char fichers[2][LEN], int nb_joueur);
int sauvegarde_nom(char fichiers[2][LEN]);
void nom_fichier(char fichiers[2][LEN]);

//dans banque

void ajout_maison(info_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9]);
void vendre_maison(info_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9]);
void ajout_hotel(info_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9]);
void hypotheque(info_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9]);
void faillite(info_joueur* jeanMichel, int paymant, t_mono plateau[32]);
void menu_achat_vente_maison(info_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9]);
#endif // MENU_H_INCLUDED
