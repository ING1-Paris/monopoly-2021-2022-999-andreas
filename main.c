
#include "menu.h"

int main()
{
    srand(time(NULL));
    ///déclaration des variables
///-----------------------------------------------------------------------------------------------------------------///
    t_mono plat[4][8];
    int de[3];
    char pion;
    int ligne=2;
    int colplat,ligplat,a;
    int joueur=0;
    setConsoleSize();
    int choix,nbdejoueur,i;
    t_joueur tabdejoueur[6];
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
        printf("nombre de joueur entre 2 et 6");            ///choix du nombre de joueur entre 2 et 6 joueurs
        scanf("%d",&nbdejoueur);
        for(i=0;i<nbdejoueur;i++)                                   ///remplissage du tableau de structure joueur
        {
            printf("entrez le nom du joueur n %d",i+1);
            scanf("%s",&tabdejoueur[i].nom);
            fflush(stdin);
            printf("choisissez un caractere pour votre pion");
            scanf("%c",&tabdejoueur[i].pionjoueur);
            fflush(stdin);
            tabdejoueur[i].argent=1000;
        }

        for(int j=0;j<7;j++){
        gotoligcol(31+ligne,70);
        printf("On relance les des");
        fflush(stdin);
        scanf("%d",&a);
        if (a==1){
        plateau(ligne);
        gotoligcol(29+ligne,70);
        printf("vous avez fait:");
        gotoligcol(30+ligne,75);
        lancer_de(de);
        joueur=(joueur+de[0]+de[1])%32;
        afficher_point(joueur,ligplat,colplat,pion,plat,ligne);
        system('cls');
        }
    }
    }
///------------------------------------------------------------------------------------------------------------------///
    gotoligcol(60+ligne,1);
    return 0;
}
