#include "menu.h"


void banque(info_joueur jeanMichel)
{
    printf("ici c'est le passage de tours");

    if ((jeanMichel.position[0]-jeanMichel.position[1])>=0)
    {
        jeanMichel.argent+=200;
    }


}

void fonction_pour_acheter_une_rue(info_joueur jeanMichel)
{
    int la_case_choisi;
    int choix;

    printf("avec quelle case voulez vous interagir ?");
    scanf("%d", &la_case_choisi);

    printf("que voulez vous faire ?");


    if (/*la case choisi dans aucune des possession des joueur*/);
    {
        printf("1. acheter");
        printf("2. ne rien faire");

        scanf("%d", &choix);
        switch(choix)
        {

        }

    }

    else if (la_case_choisi in jeanMichel.possession):
    {
        printf("1. hypothequer");
        printf("2. ajouter une maison");
        printf("3. ne rien faire"):
        if (/*le nombre de maison sur la case egale à 4*/)
        {
            printf("4. ajouter un hotel");
        }
        /*switch ici*/
    }

    else:
    {
        printf("cette rue appartient à un autre joueur quel dommage...");
        /*revenir au menu des actions*/
    }

    /*on appelle d'autre fonction pour acheter, vendre, ajouter une maison/en enlever une et pareil pour les hotels */


}
