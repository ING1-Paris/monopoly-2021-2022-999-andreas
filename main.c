
#include "menu.h"

int main()
{
    srand(time(NULL));
    ///déclaration des variables
///-----------------------------------------------------------------------------------------------------------------///
    t_mono plat[4][8];
    int de[3];
    int ligne=2;
    setConsoleSize();
    int choix,nddejoueurenjeu,nbdejoueur,i,j;
    t_joueur tabdejoueur[6];
    nddejoueurenjeu=0;
///-----------------------------------------------------------------------------------------------------------------///
///menu
    choix=menu();
    fflush(stdin);

/// nouvelle partie
///----------------------------------------------------------------------------------------------------------------///
///début de la partie
    if (choix==1)
    {
        ///début de la partie
        do
        {
            printf("nombre de joueur entre 2 et 6");            ///choix du nombre de joueur entre 2 et 6 joueurs
            scanf("%d",&nbdejoueur);
        }while(nbdejoueur<2 || nbdejoueur>6);
        for(i=0;i<nbdejoueur;i++)                                   ///remplissage du tableau de structure joueur
        {
            printf("entrez le nom du joueur n %d",i+1);
            scanf("%s",&tabdejoueur[i].nom);
            fflush(stdin);
            printf("choisissez un caractere pour votre pion");
            scanf("%c",&tabdejoueur[i].pionjoueur);
            fflush(stdin);
            tabdejoueur[i].argent=1000;
            tabdejoueur[i].position[2]=0;
        }
        do
        {
            for (i=0;i<nbdejoueur;i++)
            {
                tabdejoueur[i].position[1]=tabdejoueur[i].position[2];
                plateau(ligne);
                gotoligcol(30+ligne,70);
                menu_taches1();
                plateau(ligne);
                gotoligcol(29+ligne,70);
                printf("vous avez fait:");
                gotoligcol(30+ligne,75);
                lancer_de(de);
                tabdejoueur[i].position[2]=(tabdejoueur[i].position[1]+de[0]+de[1])%32;
                afficher_point(tabdejoueur,i,plat,ligne);
                passage_arrivee(tabdejoueur[i]);
                menu_taches2(); ///plus action différentes en fonction de la case
                for (j=0;j<nbdejoueur;j++)
                {
                    if (tabdejoueur[i].argent!=0)
                    {
                        nddejoueurenjeu=nddejoueurenjeu+1;
                    }
                }
            }

        }while (nddejoueurenjeu=1);
    }
///------------------------------------------------------------------------------------------------------------------///
    gotoligcol(60+ligne,1);
    return 0;
}
