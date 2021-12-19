
#include "menu.h"

int main()
{
    srand(time(NULL));
    t_mono plat[4][8];
    int de[3];
    char pion;
    int ligne=2;
    int colplat,ligplat,a;
    int joueur=0;
    setConsoleSize();
    int choix;
    choix=menu();
    fflush(stdin);
    printf("entrez un caractère");
    scanf("%c",&pion);
    if (choix==1)
    {
        for(int j=0;j<7;j++){
        gotoligcol(31+ligne,70);
        printf("On relance les des");
        scanf("%d",&a);
        if (a==1){
        system('cls');
        plateau(ligne);
        gotoligcol(29+ligne,70);
        printf("vous avez fait:");
        gotoligcol(30+ligne,75);
        lancer_de(de);
        joueur=(joueur+de[0]+de[1])%32;
        afficher_point(joueur,ligplat,colplat,pion,plat,ligne);
        }
    }
    }
    gotoligcol(60+ligne,1);
    return 0;
}
