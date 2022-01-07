
#include "menu.h"

int main()
{
    srand(time(NULL));
    ///déclaration des variables
///-----------------------------------------------------------------------------------------------------------------///
    t_mono plat[32];
    int de[3];
    int ligne=2;
    setConsoleSize();
    int choix,/*nddejoueurenjeu*/nbdejoueur,i,j;
    t_joueur tabdejoueur[6];
    //nddejoueurenjeu=0;
    int*nb_maison=32;
    int*nb_hotel=16;
    int a=0;
    int carte=rand()%(15);


    int t_villes[19][9] ={{60,50,2,10,30,90,160,250,1},/// prix | prix maison | loyer sans maison | 1 maison | 2 maisons | 3 maisons | 4 maisons | 1 hotel | place sur le plateau
                        {70,50,4,20,60,180,320,450,3},
                        {100,50,6,30,90,270,400,550,6},
                        {120,50,8,40,100,300,450,600,7},
                        {120,100,10,50,150,450,625,750,9},
                        {140,100,10,50,150,450,625,750,10},
                        {160,100,12,60,180,500,700,900,11},
                        {180,100,14,70,200,550,750,950,13},
                        {180,100,14,70,200,550,750,950,14},
                        {180,100,16,80,220,600,800,1000,15},
                        {220,150,18,90,250,70,875,1050,17},
                        {240,150,20,100,300,750,925,1100,18},
                        {260,150,22,110,330,800,975,1150,22},
                        {280,150,24,120,360,850,1025,1200,23},
                        {300,200,26,130,390,900,1100,1275,25},
                        {300,200,26,130,390,900,1100,1275,26},
                        {320,200,28,150,450,1000,1200,1400,27},
                        {350,200,35,175,500,1100,1300,1500,30},
                        {400,200,50,200,600,1400,1700,2000,31}};

    plat[0].type =ARRIVE;
    plat[1].type =VILLE;
    plat[2].type =COMM;
    plat[3].type =VILLE;
    plat[4].type =IMPOT;
    plat[5].type =GARE;
    plat[6].type =VILLE;
    plat[7].type =VILLE;
    plat[8].type =PARC;
    plat[9].type =VILLE;
    plat[10].type =VILLE;
    plat[11].type =VILLE;
    plat[12].type =GARE;
    plat[13].type =VILLE;
    plat[14].type =VILLE;
    plat[15].type =VILLE;
    plat[16].type =PARC;
    plat[17].type =VILLE;
    plat[18].type =VILLE;
    plat[19].type =CHANCE;
    plat[20].type =GARE;
    plat[21].type =COMM;
    plat[22].type =VILLE;
    plat[23].type =VILLE;
    plat[24].type =PRISON;
    plat[25].type =VILLE;
    plat[26].type =VILLE;
    plat[27].type =VILLE;
    plat[28].type =GARE;
    plat[29].type =CHANCE;
    plat[30].type =VILLE;
    plat[31].type =VILLE;

    /*
    -afficher le menu avec le nom des sauvegardes
    -on travaille sur le fichier choisi
    -initialisation des cases et joueur en fonction du fichier (si le nom du fichier sur lequel on travaille est en dernier dans le tableau alors tout à 0)
    -demander le nombre de joueur si besoin
    -demander les noms des joueurs si besoin
    -lancer la partie
    */

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
            tabdejoueur[i].argent=1500;
            tabdejoueur[i].position[1]=1;
            for (j=0;j<23;j++)
            {
                tabdejoueur[i].possession[j]=0;
            }
        }
    }
        do
        {
            for (i=0;i<nbdejoueur;i++)
            {
                tabdejoueur[i].position[0]=tabdejoueur[i].position[1];
                plateau(ligne);
                affichage_possession(tabdejoueur,i,ligne);
                for (j=0;j<nbdejoueur;j++)
                {
                    afficher_point(tabdejoueur,j,plat,ligne);
                }
                gotoligcol(30+ligne,70);
                do
                    {
                        printf("1. lancer des des\n");
                        gotoligcol(31+ligne,70);
                        printf("2. acheter/vendre une maison ou un hotel\n");
                        gotoligcol(32+ligne,70);
                        printf("3. hypothequer une case\n");
                        scanf("%d", &choix);
                    }while((choix<1 || choix> 3));
        gotoligcol(29+ligne,70);
        printf("vous avez fait:");
        gotoligcol(30+ligne,75);
        lancer_de(de);

        switch(choix)
            {
                case 1 :
                {
                    break;
                }

                case 2 :
                {
                    achat_vente_maison(&tabdejoueur[i], plat, nb_maison, nb_hotel, t_villes);
                    break;
                }

                case 3 :
                {
                    hypotheque(&tabdejoueur[i], plat, nb_maison, nb_hotel,t_villes);
                    break;
                }
            }
                plateau(ligne);

                gotoligcol(29+ligne,70);
                printf("vous avez fait:");
                gotoligcol(30+ligne,75);
                lancer_de(de);
                tabdejoueur[i].position[1]=(tabdejoueur[i].position[1]+de[0]+de[1])%32;
                afficher_point(tabdejoueur,i,plat,ligne);
                passage_arrivee(tabdejoueur,i);
                actioncase(t_villes,plat,tabdejoueur,i,ligne,carte);
            }

        }while (a==0);//(nddejoueurenjeu==1);
///------------------------------------------------------------------------------------------------------------------///
    gotoligcol(60+ligne,1);
    return 0;
}
