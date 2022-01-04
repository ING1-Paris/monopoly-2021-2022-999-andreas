#include "menu.h"


void passage_arrivee(info_joueur jeanMichel)
{
    printf("ici c'est le passage de tours");

    if ((jeanMichel.position[0]-jeanMichel.position[1])<0)
    {
        jeanMichel.argent+=200;
    }


}

void faillite(info_joueur* jeanMichel, int paymant, t_mono plateau[32]) // test si le joueur est en faillite
{
    ///en travaux
}

void achat_vente_maison(info_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9])
{
    int quantite;
    int la_case_choisi;
    int choix;

    do
    {
        printf("avec quelle case voulez vous interagir ?\n"); // le mieux serait de pouvoir cliquer
        scanf("%d", &la_case_choisi);
    }
    while(!jeanMichel->possession[la_case_choisi]);


    do
    {

        printf("2. vendre une maison/hotel\n");
        if (jeanMichel->argent < info_case(info_villes, la_case_choisi, 1))
        {
            printf("1. ajouter une maison\n");
            if (plateau[la_case_choisi].maison == 4)
            {
                printf("3. ajouter un hotel\n");
            }
        }


        scanf("%d", &choix);
    }
    while ((choix!= 1) && (choix!=2) && (choix!=3));

    switch (choix)
    {
        case 1 :
        {
            plateau[la_case_choisi].maison += 1;
            //tester si le joueur à l'argent
            jeanMichel->argent -= info_case(info_villes, la_case_choisi, 1); // on prend l'info 1 (le prix d'une upgrade) de la case choisi dans info_villes
            plateau[la_case_choisi].loyer = info_case(info_villes, la_case_choisi, (plateau[la_case_choisi].maison+2));
            nb_maison -=1;
            break;
        }

        case 2 :
        {
            printf("combien de maisons ou hotel voulais vous vendre : ");
            scanf("%d", &quantite);
            printf("\n");
            if (plateau[la_case_choisi].hotel)
            {
                quantite -=1;
                plateau[la_case_choisi].hotel = 0;
                nb_hotel +=1;
                jeanMichel->argent +=(info_case(info_villes, la_case_choisi,1))/2;
            }

            else if (plateau[la_case_choisi].maison)
            {
                plateau[la_case_choisi].maison -=quantite;
                nb_maison +=quantite;
                jeanMichel->argent += (quantite * ((info_case(info_villes, la_case_choisi,1)/2)));
                plateau[la_case_choisi].loyer = info_case(info_villes, la_case_choisi, (plateau[la_case_choisi].maison+2));

            }
            break;
        }

        case 3 :
        {
            plateau[la_case_choisi].hotel  += 1;
            //tester si le joueur à l'argent
            jeanMichel->argent -= info_case(info_villes, la_case_choisi, 1);
            plateau[la_case_choisi].maison = 0;
            plateau[la_case_choisi].loyer = info_case(info_villes, la_case_choisi, 7);
            nb_maison +=4;
            nb_hotel -=1;
            break;
        }
    }
}

void hypotheque(info_joueur* jeanMichel, t_mono plateau[32], int* nb_maison, int* nb_hotel, int info_villes[19][9])
{
    int la_case_choisi;

    do
    {
        printf("avec quelle case voulez vous interagir ?\n"); // le mieux serait de pouvoir cliquer
        scanf("%d", &la_case_choisi);
    }
    while(!jeanMichel->possession[la_case_choisi]);

    if(plateau[la_case_choisi].maison || plateau[la_case_choisi].hotel)
    {
        jeanMichel->argent += (((plateau[la_case_choisi].hotel) + (plateau[la_case_choisi].maison)) * (info_case(info_villes, la_case_choisi, 1)))/2;
    }

    jeanMichel->possession[la_case_choisi] =0;
    jeanMichel->argent += ((info_case(info_villes, la_case_choisi, 0)/2));
    plateau[la_case_choisi].hypo = 1;

}


/*il faut trouver un moyen de stocker les infos des loyers de chaque proprieter en fonction des maisons */
/*il faut trouver un moyen de blinder les input avant d'essaye faire l'action impossib*/
