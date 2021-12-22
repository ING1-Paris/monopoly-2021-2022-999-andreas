#include "menu.h"


void passage_arrivee(info_joueur jeanMichel)
{
    printf("ici c'est le passage de tours");

    if ((jeanMichel.position[0]-jeanMichel.position[1])<0)
    {
        jeanMichel.argent+=200;
    }


}

void menu_taches()
{
    int choix;

    printf("1. lancer des dés\n");
    printf("2. acheter/vendre une maison ou un hotel\n");
    printf("3. hypothéquer une case\n");

    scanf("%d", &choix);

    switch(choix)
    {
        case 2 :
        {
            achat_vente_maison();
            break;
        }

        case 3 :
        {
            hypotheque();
            break;
        }

        default :
        {
            menu_taches();

        }
    }
}

void achat_vente_maison(info_joueur jeanMichel)
{
    int la_case_choisi;

    printf("avec quelle case voulez vous interagir ?\n"); // le mieux serait de pouvoir cliquer
    scanf("%d", &la_case_choisi);                         // sur la case mais jps si c'est possible


    if (/*la_case_choisi est dans jeanMichel.possession*/)
    {
        printf("1. ajouter une maison\n");
        printf("2. ne rien faire\n"):
        if (jeanMichel.possession[la_case_choisi][2]==4)
        {
            printf("3. ajouter un hotel\n");
        }

        scanf("%d", &choix);
        switch (choix);
        {
            case 1 : //ajouter une maison ou un hotel c'est la meme sauf qu'il faut decrementer une maison ou un hotel au compte totale
            {
                jeanMichel.possession[la_case_choisi][2] += 1;
                jeanMichel.argent -= /*prix de l'upgrade*/
            }

            case 2 :
            {
                menu_taches();
            }

            case 3 :
            {
                jeanMichel.possession[la_case_choisi][3]   += 1;
                jeanMichel.argent -= /*prix de l'upgrade*/
            }

            default :
            {

            }
        }
    }

    else:
    {
        printf("cette rue appartient à un autre joueur, quel dommage...\n");
        menu_taches();
    }
}

void hypotheque(info_joueur jeanMichel)
{
    int la_case_choisi;

    printf("avec quelle case voulez vous interagir ?\n"); // le mieux serait de pouvoir cliquer
    scanf("%d", &la_case_choisi);

    if(/*la_case_choisi est dans jeanMichel.possession*/)
    {
        jeanMichel.possession[la_case_choisi] =0;
        jeanMichel.argent -= /*prix de la case -10%*/

    }
}


/*il faut trouver un moyen de stocker les infos des loyers de chaque proprieter en fonction des maisons */
