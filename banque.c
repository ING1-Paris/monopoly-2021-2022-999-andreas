#include "menu.h"


int achat_ville(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9])
{
   if (jeanMichel->argent > info_case(info_villes, jeanMichel->position[0], 0))
    {
        return 1;
    }

    jeanMichel->argent -= info_case(info_villes, jeanMichel->position[0], 0);
    jeanMichel->possession[0] = jeanMichel->position[0];
    plateau[jeanMichel->position[0]].loyer = info_case(info_villes, jeanMichel->position[0], 2);

    menu_achat_vente_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes[19][9]);

    return 0;
}

void ajout_maison(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9])
{
    if ((jeanMichel->argent > info_case(info_villes, jeanMichel->position[0], 1))|| (*nb_maison=0))
    {
        menu_achat_vente_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
    }

    plateau[jeanMichel->position[0]].maison += 1;
    jeanMichel->argent -= info_case(info_villes, jeanMichel->position[0], 1); // on prend l'info 1 (le prix d'une upgrade) de la case choisi dans info_villes
    plateau[jeanMichel->position[0]].loyer = info_case(info_villes, jeanMichel->position[0], (plateau[jeanMichel->position[0]].maison+2));
    *nb_maison -=1;

    menu_achat_vente_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
}

void vendre_maison(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9])
{
    int quantite;

    if ((plateau[jeanMichel->position[0]].hotel==0) ||  (plateau[jeanMichel->position[0]].maison==0))
    {
        menu_achat_vente_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
    }

    do
    {
        printf("combien de maisons ou hotel voulais vous vendre : ");
        scanf("%d", &quantite);
        printf("\n");
    }
    while(quantite<(plateau[jeanMichel->position[0]].hotel)+(plateau[jeanMichel->position[0]].maison));

    if (plateau[jeanMichel->position[0]].hotel)
    {
        quantite -=1;
        plateau[jeanMichel->position[0]].hotel = 0;
        *nb_hotel +=1;
        jeanMichel->argent +=(info_case(info_villes, jeanMichel->position[0],1))/2;
    }

    if (plateau[jeanMichel->position[0]].maison)
    {
        plateau[jeanMichel->position[0]].maison -=quantite;
        *nb_maison +=quantite;
        jeanMichel->argent += (quantite * ((info_case(info_villes, jeanMichel->position[0],1)/2)));
        plateau[jeanMichel->position[0]].loyer = info_case(info_villes, jeanMichel->position[0], (plateau[jeanMichel->position[0]].maison+2));

    }
}

void ajout_hotel(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9])
{
    if((jeanMichel->argent > info_case(info_villes, jeanMichel->position[0], 1)) || (plateau[jeanMichel->position[0]].maison == 4) || (nb_hotel=0))
    {
        menu_achat_vente_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
    }

    plateau[jeanMichel->position[0]].hotel  += 1;
    jeanMichel->argent -= info_case(info_villes, jeanMichel->position[0], 1);
    plateau[jeanMichel->position[0]].maison = 0;
    plateau[jeanMichel->position[0]].loyer = info_case(info_villes, jeanMichel->position[0], 7);
    *nb_maison +=4;
    *nb_hotel -=1;

    menu_achat_vente_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
}

void hypotheque(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9])
{
    int la_case_choisi;

    do
    {
        printf("avec quelle case voulez vous interagir ?\n"); // le mieux serait de pouvoir cliquer
        scanf("%d", &la_case_choisi);
    }
    while(jeanMichel->possession[la_case_choisi]==0);

    if(plateau[la_case_choisi].maison || plateau[la_case_choisi].hotel)
    {
        jeanMichel->argent += (((plateau[la_case_choisi].hotel) + (plateau[la_case_choisi].maison)) * (info_case(info_villes, la_case_choisi, 1)))/2;
    }

    jeanMichel->possession[la_case_choisi] =0;
    jeanMichel->argent += ((info_case(info_villes, la_case_choisi, 0)/2));
    plateau[la_case_choisi].hypo = 1;

    *nb_maison += plateau[la_case_choisi].maison;
    *nb_hotel += (plateau[la_case_choisi].hotel);
    plateau[la_case_choisi].maison = 0;
    (plateau[la_case_choisi].hotel) = 0;
}

void menu_achat_vente_maison(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9])
{
    int choix;
    do
    {
        printf("1. ajouter une maison\n");
        printf("2. vendre une maison/hotel\n");
        printf("3. ajouter un hotel\n");
        printf("4. ne rien faire\n");

        scanf("%d", &choix);
    }
    while ((choix!= 1) && (choix!=2) && (choix!=3));

    switch(choix)
    {
        case 1 :
        {
            ajout_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);

            break;
        }

        case 2 :
        {
            vendre_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
            break;
        }

        case 3 :
        {
            ajout_hotel(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
            break;
        }

        case 4 :
        {
            break;
        }
    }
}



/*il faut trouver un moyen de stocker les infos des loyers de chaque proprieter en fonction des maisons */
/*il faut trouver un moyen de blinder les input avant d'essaye faire l'action impossib ou pas en fait*/
/*ajouter un retour vers le menu si une conditions est pas respecter dans actions  (il y en a encore genre : si le joueur à pas de maisons il peut pas en vendre)*/

/*remplacer tout les la_case_choisis par des jeanMichel.position[0] et mettre les fonctions dans le menu.h*/
