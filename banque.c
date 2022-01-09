#include "menu.h"

/** change le loyer des gares en fonction du nombre possédé
 * paramètres:
 * les infos d'un joueur
 * les infos de chaque case du plateau
 * les infos financière de chaque terrains
 */
void plusieurs_gares(t_joueur jeanMichel, t_mono plateau[32], int info_villes[19][9])
{
    int i;
    int nb_gares = 0;

    for(i = 0; i<23; i++)
    {
        if (plateau[jeanMichel.possession[i]].type== GARE)
        {
            nb_gares+=1;
        }

    }

    for(i = 0; i<23; i++)
    {
        if (plateau[jeanMichel.possession[i]].type== GARE)
        {
            plateau[jeanMichel.possession[i]].loyer = info_case(info_villes, jeanMichel.possession[i], nb_gares+1);
        }
    }
}

/** permet d'acheter une ville
 * paramètres:
 * les infos d'un joueurs
 * les infos de chaque case du plateau
 * le nombre de maison restante
 * le nombre d'hotel restant
 * les infos financière de chaque terrains
 */
int achat_ville(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9])

{

    jeanMichel->argent -= info_case(info_villes, jeanMichel->position[1], 0);
    jeanMichel->possession[0] = jeanMichel->position[1];
    plateau[jeanMichel->position[1]].loyer = info_case(info_villes, jeanMichel->position[1], 2);
    plateau[jeanMichel->position[1]].possesseder++;

    return 0;
}

/** permet d'ajouter une ville
 * paramètres:
 * les infos d'un joueur
 * les infos de chaque case du plateau
 * le nombre de maison resante
 * le nombe de hotel restant
 * les infos financière de chaque terrains
 */
void ajout_maison(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9])
{
    plateau[jeanMichel->position[1]].maison += 1;
    jeanMichel->argent -= info_case(info_villes, jeanMichel->position[1], 1); // on prend l'info 1 (le prix d'une upgrade) de la case choisi dans info_villes
    plateau[jeanMichel->position[1]].loyer = info_case(info_villes, jeanMichel->position[1], (plateau[jeanMichel->position[1]].maison+2));
    *nb_maison -=1;

}


/** permet de vendre une maison
 * paramètres:
 * les infos d'un joueur
 * les infos de chaque case du plateau
 * le nombre de maison resante
 * le nombe de hotel restant
 * les infos financière de chaque terrains
 */
int vendre_maison(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9])
{
    int quantite;
    int case_choisi;

    printf("avec quelle case voulez vous interagir ? taper 404 si vous n'avez pas de maison\n");
    do
    {
        scanf("%d", &case_choisi);

        if(case_choisi == 404)
        {
            return 0;
        }
    }
    while((plateau[jeanMichel->position[0]].hotel)+(plateau[jeanMichel->position[0]].maison)==0 || possession(*jeanMichel));

    do
    {
        printf("combien de maisons ou hotel voulais vous vendre : ");
        scanf("%d", &quantite);
        printf("\n");
    }
    while(quantite<(plateau[case_choisi].hotel)+(plateau[case_choisi].maison));

    if (plateau[case_choisi].hotel)
    {
        quantite -=1;
        plateau[case_choisi].hotel = 0;
        *nb_hotel +=1;
        jeanMichel->argent +=(info_case(info_villes, case_choisi,1))/2;
    }

    if (plateau[case_choisi].maison)
    {
        plateau[case_choisi].maison -=quantite;
        *nb_maison +=quantite;
        jeanMichel->argent += (quantite * ((info_case(info_villes, case_choisi,1)/2)));
        plateau[case_choisi].loyer = info_case(info_villes, case_choisi, (plateau[case_choisi].maison+2));

    }
    return 0;
}
/** permet d'ajouter un hotel
 * paramètres:
 * les infos d'un joueur
 * les infos de chaque case du plateau
 * le nombre de maison resante
 * le nombe de hotel restant
 * les infos financière de chaque terrains
 */
void ajout_hotel(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9])
{

    plateau[jeanMichel->position[1]].hotel  += 1;
    jeanMichel->argent -= info_case(info_villes, jeanMichel->position[1], 1);
    plateau[jeanMichel->position[1]].maison = 0;
    plateau[jeanMichel->position[1]].loyer = info_case(info_villes, jeanMichel->position[1], 7);
    *nb_maison +=4;
    *nb_hotel -=1;

}

/** permet d'hypotheque un terrain
 * paramètres:
 * les infos d'un joueur
 * les infos de chaque case du plateau
 * le nombre de maison resante
 * le nombe de hotel restant
 * les infos financière de chaque terrains
 */
int hypotheque(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9])
{
    int la_case_choisi;
    printf("avec quelle case voulez vous interagir ? taper 404 si vous n'avez de proprieter\n");
    do
    {
        scanf("%d", &la_case_choisi);

        if(la_case_choisi == 404)
        {
            return 0;
        }
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
    plateau[la_case_choisi].possesseder=plateau[la_case_choisi].possesseder-1;

    return 0;
}

void pas_argent(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9])
{
    int i;

    printf("1. vendre une maison\n");
    printf("2. hypotheque une case\n");
    printf("3. abondonner");
    do
    {
        scanf("%d",&i);
    }
    while(i!=1 && i!=2);

    switch(i)
    {
    case 1:
        {
            vendre_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
            pas_argent(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
            break;
        }

    case 2:
        {
            hypotheque(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
            pas_argent(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
            break;
        }

    case 3:
        {
            jeanMichel->faillite = 1;
            break;
        }
    }
}

/** menu permettant les actions sur une ville possedé
 * paramètres:
 * les infos d'un joueur
 * les infos de chaque case du plateau
 * le nombre de maison resante
 * le nombe de hotel restant
 * les infos financière de chaque terrains
 */
void menu_achat_vente_maison(t_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9])
{
    int choix;
    do
    {
        gotoligcol(40,75);
        printf("1. ajouter une maison\n");
        gotoligcol(41,75);
        printf("2. vendre une maison/hotel\n");
        gotoligcol(42,75);
        printf("3. ajouter un hotel\n");
        gotoligcol(43,75);
        printf("4. finir le tour\n");
        gotoligcol(44,70);
        scanf("%d", &choix);
    }
    while ((choix!= 1) && (choix!=2) && (choix!=3) && (choix!=4));

    switch(choix)
    {
        case 1 :
        {
            if ((jeanMichel->argent > info_case(info_villes, jeanMichel->position[1], 1))|| (*nb_maison=0))
            {
                menu_achat_vente_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
            }

            ajout_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);

            menu_achat_vente_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
            break;
        }

        case 2 :
        {
            if ((plateau[jeanMichel->position[1]].hotel==0) ||  (plateau[jeanMichel->position[1]].maison==0))
            {
                menu_achat_vente_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
            }

            vendre_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
            break;
        }

        case 3 :
        {
            if((jeanMichel->argent > info_case(info_villes, jeanMichel->position[1], 1)) || (plateau[jeanMichel->position[1]].maison == 4) || (nb_hotel=0))
            {
                menu_achat_vente_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
            }

            ajout_hotel(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);

            menu_achat_vente_maison(jeanMichel, plateau, nb_maison, nb_hotel, info_villes);
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

/*remplacer tout les la_case_choisis par des jeanMichel.position[1] et mettre les fonctions dans le menu.h*/
