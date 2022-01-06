#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define LEN 60

#define VILLE 0
#define GARE 1
#define CHANCE 2
#define COMM 3
#define PRISON 4
#define ARRIVE 5
#define PARC 6
#define IMPOT 7

typedef struct fichier
{
    char joueur[LEN];
    char plateau[LEN];
}t_fichier;

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
} t_joueur;

#include "sous-programmes.c"
#include "banque.c"
#include "sauvegarde.c"
#include "case.c"


//dans save
int init_sauvegarde(t_joueur tabjoueurs[] ,t_mono plateau[32], t_fichier* fichiers);
int sauvegarde(t_joueur tabjoueurs[] ,t_mono plateau[32], t_fichier* fichiers, int nb_joueur);
int sauvegarde_nom(t_fichier* fichiers);
void nom_fichier(t_fichier* fichiers);
void init_nom_sauvegarde(t_fichier* fichiers);

//dans sous-programmes
int nb_alea();
int menu();
void Color(int couleurDuTexte,int couleurDeFond);
void gotoligcol( int lig, int col );
void setConsoleSize();
void affichage_plateau(int ligne);
void afficher_point(t_joueur joueur[6],int i,t_mono plateau[32],int ligne);
void casechance(t_joueur tabdejoueur[6],int i, t_mono plateau [32], int ligne);
void casedecommunaute(int ligne, int i, t_mono plateau[32], t_joueur tabdejoueur[6]);
void casedouane( int de[3], int douane, t_joueur tabdejour[6], int i);
void affichage_possession(t_joueur joueur[6], int i,int ligne);
void lance_de(int etat_de[3]);
int info_case(int info_villes[19][9], int la_case_choisi, int info_a_rendre);
int fin_partie(t_joueur tabJoueur[], int nb_joueur);



//dans banque
void menu_achat_vente_maison(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9]);
void ajout_maison(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9]);
void vendre_maison(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9]);
void ajout_hotel(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9]);
void hypotheque(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9]);
int achat_ville(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9]);

#endif // MENU_H_INCLUDED
