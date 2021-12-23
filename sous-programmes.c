#include "menu.h"
int nb_alea()
{
    return rand()%(6)+1;
}

void lancer_de(int de[3])
{
    de[0] = nb_alea();
    de[1] = nb_alea();

    if (de[0]==de[1])
    {
        de[2]=1; // on a un double

    }
    printf("%d et %d", de[0], de[1]);
}

int menu()
{
    int choix;
    do{
        printf("MENU\n");
    printf("1- NOUVELLE PARTIE\n2-CHARGER UNE PARTIE\n3-REGLE\n4-QUITTER");
    scanf("%d",&choix);
    }while (choix<0 || choix >4);
    return choix;

}

void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void gotoligcol( int lig, int col ) {

    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

}

void setConsoleSize()
{
    keybd_event(VK_MENU,0x38,0,0); //Appuie sur ALT
    keybd_event(VK_RETURN,0x1c,0,0); //Appuie ENTREE
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0); // Relache ENTREE
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0); //Relache ALT
}
///merci AD
void plateau(int ligne)
{
    /// création des cases
    int i,j;
    gotoligcol(5+ligne,0);
        printf(" \n==============================================================================================================================================================="); /// 144
        for(j=0;j<5;j++)
        {
            printf("\n|                |                 |                 |                 |                 |                 |                 |                |                |");
        }
    printf(" \n===============================================================================================================================================================");
    for (i=0;i<6;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("\n|                |                                                                                                                            |                |");
        }
     printf("\n==================                                                                                                                             =================");
    }
    for(j=0;j<5;j++)
        {
            printf("\n|                |                                                                                                                            |                |");
        }
    printf("\n ==============================================================================================================================================================="); /// 144
        for(j=0;j<5;j++)
        {
            printf("\n|                |                 |                 |                 |                 |                 |                 |                |                |");
        }
     printf(" \n==============================================================================================================================================================="); /// 144


    ///ligne 1
    gotoligcol(9+ligne,4);
    printf("CASE DEPART");
    gotoligcol(7+ligne,18);
    Color(0,5);
    printf("                 ");
    Color(15,0);
    gotoligcol(8+ligne,22);
    printf("BUCAREST");
    gotoligcol(9+ligne,20);
    printf("PRIX:60 euros");
    gotoligcol(8+ligne,41);
    printf("CASE DE");
    gotoligcol(9+ligne,39);
    printf("COMMUNAUTE");
    gotoligcol(7+ligne,54);
    Color(0,5);
    printf("                 ");
    Color(15,0);
    gotoligcol(8+ligne,58);
    printf("SOFIA");
    gotoligcol(9+ligne,56);
    printf("PRIX:70 euros");
    gotoligcol(8+ligne,77);
    printf("IMPOT");
    gotoligcol(9+ligne,74);
    printf("PRIX:200 euros");
    gotoligcol(8+ligne,97);
    printf("GARE");
    gotoligcol(9+ligne,93);
    printf("PRIX:200 euros");
    gotoligcol(7+ligne,108);
    Color(0,3);
    printf("                 ");
    Color(15,0);
    gotoligcol(8+ligne,113);
    printf("VIENNE");
    gotoligcol(9+ligne,110);
    printf("PRIX:100 euros");
    gotoligcol(7+ligne,126);
    Color(0,3);
    printf("                ");
    Color(15,0);
    gotoligcol(8+ligne,131);
    printf("LISBONNE");
    gotoligcol(9+ligne,127);
    printf("PRIX:120 euros");
    gotoligcol(8+ligne,148);
    printf("VISITE");
    ///ligne 2
    gotoligcol(13+ligne,1);
    Color(0,2);
    printf("                ");
    Color(15,0);
    gotoligcol(14+ligne,5);
    printf("PARIS");
    gotoligcol(15+ligne,2);
    printf("PRIX:400 euros");
    gotoligcol(13+ligne,143);
    Color(0,1);
    printf("                ");
    Color(15,0);
    gotoligcol(14+ligne,148);
    printf("BERNE");
    gotoligcol(15+ligne,144);
    printf("PRIX:140 euros");
    ///ligne 3
    gotoligcol(19+ligne,1);
    Color(0,2);
    printf("                ");
    Color(15,0);
    gotoligcol(20+ligne,4);
    printf("BERLIN");
    gotoligcol(21+ligne,2);
    printf("PRIX:350 euros");
    gotoligcol(19+ligne,143);
    Color(0,1);
    printf("                ");
    Color(15,0);
    gotoligcol(20+ligne,148);
    printf("ATHENE");
    gotoligcol(21+ligne,144);
    printf("PRIX:160 euros");
    ///ligne 4
    gotoligcol(26+ligne,5);
    printf("CHANCE");
    gotoligcol(25+ligne,143);
    Color(0,1);
    printf("                ");
    Color(15,0);
    gotoligcol(26+ligne,148);
    printf("DUBLIN");
    gotoligcol(27+ligne,144);
    printf("PRIX:180 euros");
    ///ligne 5
    gotoligcol(32+ligne,5);
    printf("GARE");
    gotoligcol(33+ligne,2);
    printf("PRIX:200 euros");
    gotoligcol(32+ligne,149);
    printf("GARE");
    gotoligcol(33+ligne,144);
    printf("PRIX:200 euros");
    ///ligne 6
    gotoligcol(37+ligne,1);
    Color(0,12);
    printf("                ");
    Color(15,0);
    gotoligcol(38+ligne,5);
    printf("ROME");
    gotoligcol(39+ligne,2);
    printf("PRIX:320 euros");
    gotoligcol(37+ligne,143);
    Color(0,14);
    printf("                ");
    Color(15,0);
    gotoligcol(38+ligne,147);
    printf("STOCKHOLM");
    gotoligcol(39+ligne,144);
    printf("PRIX:200 euros");
    ///ligne 7
    gotoligcol(43+ligne,1);
    Color(0,12);
    printf("                ");
    Color(15,0);
    gotoligcol(44+ligne,4);
    printf("LONDRES");
    gotoligcol(45+ligne,2);
    printf("PRIX:300 euros");
    gotoligcol(43+ligne,143);
    Color(0,14);
    printf("                ");
    Color(15,0);
    gotoligcol(44+ligne,147);
    printf("HELSINKI");
    gotoligcol(45+ligne,144);
    printf("PRIX:200 euros");
    ///ligne 8
    gotoligcol(49+ligne,1);
    Color(0,12);
    printf("                ");
    Color(15,0);
    gotoligcol(50+ligne,4);
    printf("MADRID");
    gotoligcol(51+ligne,2);
    printf("PRIX:300 euros");
    gotoligcol(49+ligne,143);
    Color(0,14);
    printf("                ");
    Color(15,0);
    gotoligcol(50+ligne,147);
    printf("VARSOVIE");
    gotoligcol(51+ligne,144);
    printf("PRIX:200 euros");
    ///ligne 9
    gotoligcol(56+ligne,5);
    printf("ALLER EN");
    gotoligcol(57+ligne,5);
    printf("PRISON");
    gotoligcol(55+ligne,18  );
    Color(0,6);
    printf("                 ");
    Color(15,0);
    gotoligcol(56+ligne,21);
    printf("BRUXELLES");
    gotoligcol(57+ligne,20);
    printf("PRIX:280 euros");
    gotoligcol(55+ligne,36  );
    Color(0,6);
    printf("                 ");
    Color(15,0);
    gotoligcol(56+ligne,39);
    printf("AMSTERDAM");
    gotoligcol(57+ligne,38);
    printf("PRIX:260 euros");
    gotoligcol(56+ligne,59);
    printf("CASE DE");
    gotoligcol(57+ligne,57);
    printf("COMMUNAUTE");
    gotoligcol(56+ligne,78);
    printf("GARE");
    gotoligcol(57+ligne,74);
    printf("PRIX:200 euros");
    gotoligcol(56+ligne,96);
    printf("CHANCE");
    gotoligcol(55+ligne,108);
    Color(0,8);
    printf("                 ");
    Color(15,0);
    gotoligcol(56+ligne,111);
    printf("LUXEMBOURG");
    gotoligcol(57+ligne,110);
    printf("PRIX:240 euros");
    gotoligcol(55+ligne,126);
    Color(0,8);
    printf("                ");
    Color(15,0);
    gotoligcol(56+ligne,130);
    printf("COPENHAGUE");
    gotoligcol(57+ligne,128);
    printf("PRIX:220 euros");
    gotoligcol(56+ligne,149);
    printf("PARC");
    gotoligcol(57+ligne,148);
    printf("GRATUIT");
}

void afficher_point(int joueur,int ligplat, int colplat,char pion,t_mono plat[4][8],int ligne)
{
    if (joueur<9)
        {
            ligplat=1;
            colplat=joueur%8;
            if (colplat!=0)
            {
                plat[ligplat][colplat].presence++;
                gotoligcol(10+ligne,colplat*19);
                printf("%c",pion);
            }
            else
            {
                gotoligcol(10+ligne,144);
                printf("%c",pion);
            }
        }
        else if (joueur>=9 && joueur<17)
        {
            ligplat=2;
            colplat=joueur%8;
            if (colplat!=0)
            {
                plat[ligplat][colplat].presence++;
                gotoligcol(10+colplat*6+ligne,144);
                printf("%c",pion);
            }
            else
            {
                gotoligcol(59+ligne,144);
                printf("%c",pion);
            }
        }
        else if (joueur>=17 && joueur<=25)
        {
            ligplat=3;
            colplat=joueur%8;
            if (colplat!=0)
            {
                plat[ligplat][colplat].presence++;
                gotoligcol(59+ligne,154-colplat*19);
                printf("%c",pion);
            }
            else
            {
                gotoligcol(59+ligne,5);
                printf("%c",pion);
            }
        }
        else
        {
            ligplat=4;
            colplat=joueur%8;
            if (colplat!=0)
            {
                plat[ligplat][colplat].presence++;
                gotoligcol(60-colplat*6,3);
                printf("%c",pion);
            }
            else
            {
                gotoligcol(ligne,5);
                printf("%c",pion);
            }
        }
}


void casechance(t_joueur tabdejoueur[6],int i, t_mono plat [4][8], int ligne)
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
            plat[4][2].presence++;
            break;
        }
        case 1:
        {
            //carte sortie de douane
            break;
        }

        case 2 :
        {
            gotoligcol(3+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[1][1].presence++;
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
            plat[4][8].presence++;
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
            // carte sortie de douane
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
            plat[4][3].presence++;
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
            plat[1][1].presence++;
            break;
        }
        case 13:
        {
            gotoligcol(35+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[4][4].presence++;
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
            plat[4][7].presence++;
            break;
        }
    }
}
#include "menu.h"
void casechance(t_joueur tabdejoueur[6],int i, t_mono plat [4][8], int ligne)
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
            plat[4][1].presence++;
            break;
        }
        case 1:
        {
            //carte sortie de douane
            break;
        }

        case 2 :
        {
            gotoligcol(3+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[1][0].presence++;
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
            plat[4][7].presence++;
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
            // carte sortie de douane
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
            plat[4][2].presence++;
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
            plat[1][0].presence++;
            break;
        }
        case 13:
        {
            gotoligcol(35+ligne,3);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[4][3].presence++;
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
            plat[4][6].presence++;
            break;
        }
    }
}

void casedecommunaute(int ligne, int i, t_mono plat[4][8], t_joueur tabdejoueur[6])
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
            plat[1][0].presence++;
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
             // carte sortie de douane
            break;
        }
        case 4 :
        {
            gotoligcol(11+ligne,148);
            printf("%c",tabdejoueur[i].pionjoueur);
            plat[2][1].presence++;
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
            // carte sortie de douane
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
            plat[1][1].presence++;
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
            plat[1][3].presence++;
            break;
        }
    }
}

void casedouane( int de[3], int douane, t_joueur tabdejour[6], int i)
{
    int choix;
    do
    {
        printf("1. Payer 50 euros\n2. utiliser une carte sotir de douane\n3.acheter une carte sortir de douane à un joueur et la jouer\n4. lancer les des");
        scanf("%d",&choix);
    }while(choix<1 || choix>4)
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

void passage_arrivee(t_joueur jeanMichel)
{
    if ((jeanMichel.position[0]-jeanMichel.position[1])<0)
    {
        jeanMichel.argent+=200;
    }
}

void menu_taches1()
{
    int choix;
    printf("1. lancer des des\n2. acheter/vendre une maison ou un hotel\n3. hypothequer une case\n");
    scanf("%d", &choix);
    switch(choix)
    {
        case 1 :
        {
            break;
        }

        case 2 :
        {
            //achat_vente_maison();
            break;
        }

        case 3 :
        {
           // hypotheque();
            break;
        }

        default :
        {
            menu_taches1();

        }
    }
}
void menu_taches2()
{
    int choix;
    printf("1. acheter la case ou payer le loyer\n2. acheter/vendre une maison ou un hotel\n3. hypothequer une case\n");
    scanf("%d", &choix);
    switch(choix)
    {
        case 1 :
        {
            break;
        }

        case 2 :
        {
            //achat_vente_maison();
            break;
        }

        case 3 :
        {
           // hypotheque();
            break;
        }

        default :
        {
            menu_taches2();

        }
    }
}
/*
void achat_vente_maison(t_joueur jeanMichel)
{
    int la_case_choisi;

    printf("avec quelle case voulez vous interagir ?\n"); // le mieux serait de pouvoir cliquer
    scanf("%d", &la_case_choisi);                         // sur la case mais jps si c'est possible


    if (la_case_choisi est dans jeanMichel.possession)
    {
        printf("1. ajouter une maison\n");
        printf("2. ne rien faire\n"):
        if (jeanMichel.possession[la_case_choisi][2]==4)
        {
            printf("3. ajouter un hotel\n");
        }

        scanf("%d", &choix);
        switch (choix);
        {
            case 1 :
            {
                jeanMichel.possession[la_case_choisi][2] += 1;
                jeanMichel.argent -= prix de la maison
            }

            case 2 :
            {
                menu_taches();
            }

            case 3 :
            {
                jeanMichel.possession[la_case_choisi][3] += 1;
                jeanMichel.argent -= prix de l'hotel
            }

            default :
            {

            }
        }
    }

    else:
    {
        printf("cette rue appartient � un autre joueur, quel dommage...\n");
        menu_taches();
    }
}

void hypotheque(t_joueur jeanMichel)
{
    int la_case_choisi;

    printf("avec quelle case voulez vous interagir ?\n"); // le mieux serait de pouvoir cliquer
    scanf("%d", &la_case_choisi);

    if(la_case_choisi est dans jeanMichel.possession)
    {
        jeanMichel.possession[la_case_choisi] =0;
        jeanMichel.argent -= prix de la case -10%

    }
}*/


