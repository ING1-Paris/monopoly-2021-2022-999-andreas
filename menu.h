#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct monopoly
{
    int maison;
    int hotel;
    int presence;
    int prix;

}t_mono;

typedef struct casemonopoly
{
    int joueur;
    int loyer;
    int maison;
    int hotel;
}t_case;


typedef struct info_joueur // regroupe les infos d'un joueur
{
    char nom[30];
    char pionjoueur;
    int argent;
    int position[2]; // on garde en memoire la derniere case pour savoir si le joueur passe l'arrivé
    t_case possession [20]; //je pense qu'on fera une liste pour chaque case [0]
                         //avec le loyer de la case [1], le nb de maison [2]
                         //et le nb de l'hotel [3]

} t_joueur;

int nb_alea();
void lancer_de(int de[3]);
int menu();
void Color(int couleurDuTexte,int couleurDeFond);
void gotoligcol( int lig, int col );
void setConsoleSize();
void plateau(int ligne);
void afficher_point(t_joueur joueur[6],int i,t_mono plat[4][8],int ligne);
void casechance(t_joueur tabdejoueur[6],int i, t_mono plat [4][8], int ligne);
void passage_arrivee(t_joueur jeanMichel);
void menu_taches1();
void menu_taches2();
void casedecommunaute(int ligne, int i, t_mono plat[4][8], t_joueur tabdejoueur[6]);

#endif // MENU_H_INCLUDED
