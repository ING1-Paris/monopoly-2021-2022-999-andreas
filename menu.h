#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define LEN 60

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
    char pionjoueur;
    int argent;
    int position[2]; // on garde en memoire la derniere case pour savoir si le joueur passe l'arrivÃ©
    int possession [23]; //on met juste la place des proprieters, tout le reste est stocke dans le plateau
} info_joueur;

#include "sous-programmes.c"
#include "banque.c"

//dans sous-programmes
int nb_alea();
int menu();
void Color(int couleurDuTexte,int couleurDeFond);
void gotoligcol( int lig, int col );
void setConsoleSize();
void plateau(int ligne);
void afficher_point(t_joueur joueur[6],int i,t_mono plat[32],int ligne);
void casechance(t_joueur tabdejoueur[6],int i, t_mono plat [32], int ligne);
void casedecommunaute(int ligne, int i, t_mono plat[32], t_joueur tabdejoueur[6]);
void casedouane( int de[3], int douane, t_joueur tabdejour[6], int i);
void affichage_possession(t_joueur joueur[6], int i,int ligne);

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
