#include "menu.h"

int casechance(t_joueur tabdejoueur[6],int i, t_mono plat [32], int ligne, int carte)
{
    char tab[16][200] = { {"vous prenez 3 jours de conge, vous allez manger des tapas a mardrid.Si vous passer par la case depart prenez 200 euros"},{"sortie de douane.Vous pouvez la conserver(utilisable une seul fois)"},{"avancez jusqu a la case depart"},{"votre passeport à expirer, vous payez 50 euros pour en faire un neuf"},{"vous avez ete expule de la ou vous etes, vous revenez a Paris"},{"vous avez gagne une soiree poker à Bucarest vous gagnez 100 euros"},{"On vous a vole votre argent a Sofia vous perdez 100 euros"},{"sortie de douane.Vous pouvez la conserver(utilisable une seul fois)"},{"vous vous faites arnaquer par un portugais vous perdez 150 euros"},{"vous gagnez un prix de beaute et vous remportez 200 euros"},{"Pour votre anniverssaire vos enfants vous offre un voyage a Londres.Si vous passer par la case depart prenez 200 euros"},{"vous payez votre tourne a Dublin et vous perdez 100 euros"},{"direction la case depart"},{"changement de proramme pendant votre voyage,vous allez a Rome.Si vous passer par la case depart prenez 200 euros"},{"vous trouvez 50 euros par terre dans les rue de Paris"},{"vous gagnez un jeu televise,vous partez imediatement pour Berlin.Si vous passer par la case depart prenez 200 euros"}};
    gotoligcol(52+ligne,19);
    printf(tab[carte]);  // on prend un élément du tableau puis on exécute l'odre de la carte
    switch(carte)
    {
        case 0 :
        {
            gotoligcol(54+ligne,4);
            printf("%c",tabdejoueur[i].pionjoueur);
            tabdejoueur[i].position[1]=24;
            break;
        }
        case 1:
        {
            tabdejoueur[i].possession[33]++;
            break;
        }

        case 2 :
        {
            gotoligcol(3+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            tabdejoueur[i].position[1]=32;
            break;
        }

        case 3 :
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent-50;
            break;
        }
        case 4 :
        {
            gotoligcol(17+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            tabdejoueur[i].position[1]=31;
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
            tabdejoueur[i].possession[33]++;
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
            tabdejoueur[i].position[1]=25;
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
            tabdejoueur[i].position[1]=32;
            break;
        }
        case 13:
        {
            gotoligcol(35+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            tabdejoueur[i].position[1]=26;
            break;
        }
        case 14:
        {
            tabdejoueur[i].argent=tabdejoueur[i].argent+50;
            break;
        }
        case 15:
        {
            gotoligcol(23+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            tabdejoueur[i].position[1]=30;
            break;
        }
    }
    return carte++;
}

int casedecommunaute(int ligne, int i, t_mono plat[32], t_joueur tabdejoueur[6],int carte)
{
    int choix;
    char tab[16][200] = { {"Placez-vous sur la case départ"},{"Erreur de la banque en votre faveur. Recevez 200 euros"},{"Payez la note du médecin 100 euros"},{"Vous pouvez partir de la douane. Cette carte peut être conservée jusqu’à ce qu’elle soit utilisée ou vendue."},{"Aller a la douane. Rendez-vous directement à la dozuane. Ne franchissez pas par la case depart, ne touchez pas 200 euros"},{"Recevez votre revenu annuel 500 euros"},{"C est votre anniversaire, recevez 150 euros"},{"sortie de douane.Vous pouvez la conserver(utilisable une seul fois)"},{"Les contributions vous remboursent la somme de 100 euros"},{"Vous héritez 100 euros"},{"Payez une amende de 200 euros ou bien tirez une carte « CHANCE »"},{"vous payez votre tourne a Dublin et vous perdez 100 euros"},{"direction la case depart"},{"Amende pour ivresse, vous perdez 200 euros"},{"La banque vous verse un dividende de 200 euros"},{"Retournez à Sofia"}};
    gotoligcol(52+ligne,19);
    printf(tab[carte]);  // on prend un élément du tableau puis on exécute l'odre de la carte
    switch(carte)
    {
        case 0 :
        {
            gotoligcol(3+ligne,3+i);
            printf("%c",tabdejoueur[i].pionjoueur);
            tabdejoueur[i].position[1]=32;
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
             tabdejoueur[i].possession[33]++;
            break;
        }
        case 4 :
        {
            gotoligcol(11+ligne,148+i);
            printf("%c",tabdejoueur[i].pionjoueur);
            tabdejoueur[i].position[1]=8;
            tabdejoueur[i].position[0]=7;
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
            tabdejoueur[i].possession[33]++;
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
                gotoligcol(53+ligne,19);
                printf("que voulez-vous faire. tapez 1 pour payer 100 euros ou 2 pour tirer une carte chance");
                scanf("%d",&choix);
            }while(choix<1 || choix>2);
                if (choix==1)
                {
                    tabdejoueur[i].argent=tabdejoueur[i].argent-100;
                }
                else
                {
                    casechance(tabdejoueur,i,plat,ligne,carte);
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
            gotoligcol(3+ligne,3+i);
            printf("%c",tabdejoueur[i].pionjoueur);
            tabdejoueur[i].position[1]=32;
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
            tabdejoueur[i].position[1]=3;
            break;
        }
    }
    return carte++;
}

void casedouane( int de[3], t_joueur tabdejoueur[6], int i, int nb_joueur)
{
    int choix;
    int verif=1; // variable qui permet de sortir du our du joueur
    do
    {
    do
    {
        printf("1. Payer 50 euros\n2. utiliser une carte sotir de douane\n3.acheter une carte sortir de douane à un joueur et la jouer\n4. lancer les des");
        scanf("%d",&choix);
    }while(choix<1 || choix>4);
    switch(choix)
    {
        case 1:
            {
                tabdejoueur[i].argent=tabdejoueur[i].argent-50;         // le joueur paye pour sotir
                verif=0;
                break;
            }
        case 2:
            {
                if (tabdejoueur[i].possession[33]!=0)           // le joueur utilise une carte sortir de prison
                {
                    tabdejoueur[i].possession[33]=tabdejoueur[i].possession[33]-1;
                    verif=0;
                    break;
                }
                else
                {
                    break;
                }
            }
        case 3:         // le joueur achete une carte sortir de prison à un autre joueur
            {
                int j, choix1;
                    for(j=0;j<nb_joueur;j++)
                    {
                        if(tabdejoueur[j].possession[24]!=0)
                        {
                            do
                            {
                                gotoligcol(37,75);
                                printf("vous avez une carte sortie de douane. Est ce que vous la vender pour 150 euros(1 pour oui ou 2 pour non");
                                scanf("%d",&choix1);
                            }while (choix1<1 || choix1>2);
                            if (choix1==1)
                            {
                                tabdejoueur[j].argent=tabdejoueur[j].argent+150;
                                tabdejoueur[j].possession[33]=tabdejoueur[j].possession[33]-1;
                                tabdejoueur[i].argent=tabdejoueur[i].argent-150;
                                verif=0;
                                break;
                            }
                        }
                break;
            }
            }
        case 4:     // le joueur lance les dés pour sortir
            {
                verif=0;
                break;
            }

    }
    }while (verif==1);
    lancer_de(de, &tabdejoueur[i]);
}

int carteimpot(int i, t_joueur tabdejoueur[6])
{
    printf("vous devez payer 200");
    tabdejoueur[i].argent=tabdejoueur[i].argent-200; // on retire 200 euros au joueur
    return tabdejoueur[i].argent;
}
