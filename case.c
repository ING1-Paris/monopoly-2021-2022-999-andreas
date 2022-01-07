#include "menu.h"


void casechance(t_joueur tabdejoueur[6],int i, t_mono plat [32], int ligne)
{
    int carte;
    char tab[15][200] = { {"vous prenez 3 jours de conge, vous allez manger des tapas a mardrid.Si vous passer par la case depart prenez 200 euros"},{"sortie de douane.Vous pouvez la conserver(utilisable une seul fois)"},{"avancez jusqu a la case depart"},{"votre passeport à expirer, vous ne jouez pas pendant 2 tours"},{"vous avez ete expule de la ou vous etes, vous revenez a Paris"},{"vous avez gagne une soiree poker à Bucarest vous gagnez 100 euros"},{"On vous a vole votre argent a Sofia vous perdez 100 euros"},{"sortie de douane.Vous pouvez la conserver(utilisable une seul fois)"},{"vous vous faites arnaquer par un portugais vous perdez 150 euros"},{"vous gagnez un prix de beaute et vous remportez 200 euros"},{"Pour votre anniverssaire vos enfants vous offre un voyage a Londres.Si vous passer par la case depart prenez 200 euros"},{"vous payez votre tourne a Dublin et vous perdez 100 euros"},{"direction la case depart"},{"changement de proramme pendant votre voyage,vous allez a Rome.Si vous passer par la case depart prenez 200 euros"},{"vous etes bloquer par la neige à Stockholm,vous y restez 2 jours de plus"},{"vous gagnez un jeu televise,vous partez imediatement pour Berlin.Si vous passer par la case depart prenez 200 euros"}};
    carte=rand()%(15);
    printf(tab[carte]);
    switch(carte)
    {
        case 0 :
        {
            gotoligcol(54+ligne,4);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[25].presence++;
            break;
        }
        case 1:
        {
            tabdejoueur[i].possession[23]++;
            break;
        }

        case 2 :
        {
            gotoligcol(3+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[1].presence++;
            break;
        }

        case 3 :
        {
            //pas jouer pendant 2 tours;
            break;
        }
        case 4 :
        {
            gotoligcol(17+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[32].presence++;
            break;
        }
        case 5:
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent+100;
            break;
        }
        case 6:
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent-100;
            break;
        }
        case 7:
        {
            tabdejoueur[i].possession[23]++;
            break;
        }
        case 8:
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent-150;
            break;
        }
        case 9:
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent+200;
            break;
        }
        case 10:
        {
            gotoligcol(47+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[26].presence++;
            break;
        }
        case 11:
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent-100;
            break;
        }
        case 12:
        {
            gotoligcol(3+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[1].presence++;
            break;
        }
        case 13:
        {
            gotoligcol(35+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[27].presence++;
            break;
        }
        case 14:
        {
            //bouge pas pendant 2 jours
            break;
        }
        case 15:
        {
            gotoligcol(23+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[31].presence++;
            break;
        }
    }
}

void casedecommunaute(int ligne, int i, t_mono plat[32], t_joueur tabdejoueur[6])
{
    int carte,choix;
    char tab[15][200] = { {"Placez-vous sur la case départ"},{"Erreur de la banque en votre faveur. Recevez 200 euros"},{"Payez la note du médecin 100 euros"},{"Vous pouvez partir de la douane. Cette carte peut être conservée jusqu’à ce qu’elle soit utilisée ou vendue."},{"Aller a la douane. Rendez-vous directement à la prison. Ne franchissez pas par la case depart, ne touchez pas 200 euros"},{"Recevez votre revenu annuel 500 euros"},{"C est votre anniversaire, recevez 150 euros"},{"sortie de douane.Vous pouvez la conserver(utilisable une seul fois)"},{"Les contributions vous remboursent la somme de 100 euros"},{"Vous héritez 100 euros"},{"Payez une amende de 200 euros ou bien tirez une carte « CHANCE »"},{"vous payez votre tourne a Dublin et vous perdez 100 euros"},{"direction la case depart"},{"Amende pour ivresse, vous perdez 200 euros"},{"La banque vous verse un dividende de 200 euros"},{"Retournez à Sofia"}};
    carte=rand()%(15);
    printf(tab[carte]);
    switch(carte)
    {
        case 0 :
        {
            gotoligcol(3+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[1].presence++;
            break;
        }
        case 1:
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent+200;
            break;
        }

        case 2 :
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent-100;
            break;
        }

        case 3 :
        {
             tabdejoueur[i].possession[23]++;
            break;
        }
        case 4 :
        {
            gotoligcol(11+ligne,148);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[9].presence++;
            break;
        }
        case 5:
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent+500;
            break;
        }
        case 6:
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent+150;
            break;
        }
        case 7:
        {
            tabdejoueur[i].possession[23]++;
            break;
        }
        case 8:
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent+100;
            break;
        }
        case 9:
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent+100;
            break;
        }
        case 10:
        {
            do
            {
                printf("que voulez-vous faire. tapez 1 pour payer 100 euros ou 2 pour tirer une carte chance");
                scanf("%d",&choix);
            }while(choix!=1 || choix!=2);
                if (choix==1)
                {
                    tabdejoueur[i].argent=tabdejoueur[i].argent-100;
                }
                else
                {
                    casechance(tabdejoueur,i,plat,ligne);
                }
            break;
        }
        case 11:
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent-100;
            break;
        }
        case 12:
        {
            gotoligcol(3+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[1].presence++;
            break;
        }
        case 13:
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent-200;
            break;
        }
        case 14:
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent+200;
            break;
        }
        case 15:
        {
            gotoligcol(11+ligne,54);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[4].presence++;
            break;
        }
    }
}
/*
void casedouane( int de[3], int douane, t_joueur tabdejour[6], int i)
{
    int choix;
    do
    {
        printf("1. Payer 50 euros\n2. utiliser une carte sotir de douane\n3.acheter une carte sortir de douane à un joueur et la jouer\n4. lancer les des");
        scanf("%d",&choix);
    }while(choix<1 || choix>4);
    switch(choix)
    {
        case 1:
            {
                tabdejoueur[i].argent=tabdejoueur[i].argent-50;
                break;
            }
        case 2:
            {

                tabdejour[i].possession[0].joueur=
                break;
            }
    }
}

*/
