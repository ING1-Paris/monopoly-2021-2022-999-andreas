#include "menu.h"


void passage_arrivee(info_joueur jeanMichel)
{
    printf("ici c'est le passage de tours");

    if ((jeanMichel.position[0]-jeanMichel.position[1])<0)
    {
        jeanMichel.argent+=200;
    }


}

void achat_vente_maison(info_joueur jeanMichel, t_mono plateau[32], int nb_maison, int nb_hotel)
{
    int la_case_choisi;
    int choix;

    printf("avec quelle case voulez vous interagir ?\n"); // le mieux serait de pouvoir cliquer
    scanf("%d", &la_case_choisi);                         // sur la case mais jps si c'est possible


    if (jeanMichel.possession[la_case_choisi])
    {
        printf("1. ajouter une maison\n");
        printf("2. ne rien faire\n");
        if (plateau[la_case_choisi].maison == 4)
        {
            printf("3. ajouter un hotel\n");
        }

        scanf("%d", &choix);
        switch (choix)
        {
            case 1 :
            {
                plateau.maison[la_case_choisi] += 1;
                jeanMichel.argent -= /*prix de l'upgrade*/
                nb_maison -=1;
            }

            case 2 :
            {
                menu_taches(jeanMichel, plateau);
            }

            case 3 :
            {
                plateau.hotel[la_case_choisi]  += 1;
                plateau.maison[la_case_choisi] = 0;
                jeanMichel.argent -= /*prix de l'upgrade*/
                nb_maison +=4;
                nb_hotel -=1;
            }

            default :
            {
                achat_vente_maison(jeanMichel,plateau, nb_maison, nb_hotel)
            }
        }
    }

    else:
    {
        printf("cette rue appartient à un autre joueur, quel dommage...\n");
        menu_taches(jeanMichel,plateau, nb_maison, nb_hotel);
    }
}

void hypotheque(info_joueur jeanMichel, t_mono plateau[32], int nb_maison, int nb_hotel)
{
    int la_case_choisi;

    printf("avec quelle case voulez vous interagir ?\n"); // le mieux serait de pouvoir cliquer
    scanf("%d", &la_case_choisi);

    if(jeanMichel.possession[la_case_choisi])
    {
        jeanMichel.possession[la_case_choisi] =0;
        jeanMichel.argent += /*prix de la case -10%*/
        plateau.hypo[la_case_choisi] = 1;
    }
}

void menu_taches(info_joueur jeanMichel, t_mono plateau[32], int nb_maison, int nb_hotel)
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
            achat_vente_maison(jeanMichel, plateau, nb_maison, nb_hotel);
            break;
        }

        case 3 :
        {
            hypotheque(jeanMichel, plateau, nb_maison, nb_hotel);
            break;
        }

        default :
        {
            menu_taches(jeanMichel, plateau, nb_maison, nb_hotel);

        }
    }
}


/*il faut trouver un moyen de stocker les infos des loyers de chaque proprieter en fonction des maisons */
