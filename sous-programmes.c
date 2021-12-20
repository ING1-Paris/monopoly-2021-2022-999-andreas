#include "menu.h"
int nb_alea()
{
    return rand()%(6)+1;
}

<<<<<<< Updated upstream
int lancer_de()
{
    int de[3] = {0};

    de[0] = nb_alea();
    de[1] = nb_alea();

    if (de[0]==de[1])
    {
        printf("c'est un double ! vous relancerai les des\n");
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

<<<<<<< Updated upstream
    printf("%d %d", de[0], de[1]);
    return de;
=======
>>>>>>> Stashed changes
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
    /// cr�ation des cases
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
    gotoligcol(9+ligne,23);
    printf("PRIX:");
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
    gotoligcol(9+ligne,59);
    printf("PRIX:");
    gotoligcol(8+ligne,77);
    printf("IMPOT");
    gotoligcol(9+ligne,77);
    printf("PRIX:");
    gotoligcol(8+ligne,97);
    printf("GARE");
    gotoligcol(9+ligne,97);
    printf("PRIX:");
    gotoligcol(7+ligne,108);
    Color(0,3);
    printf("                 ");
    Color(15,0);
    gotoligcol(8+ligne,113);
    printf("VIENNE");
    gotoligcol(9+ligne,114);
    printf("PRIX:");
    gotoligcol(7+ligne,126);
    Color(0,3);
    printf("                ");
    Color(15,0);
    gotoligcol(8+ligne,131);
    printf("LISBONNE");
    gotoligcol(9+ligne,132);
    printf("PRIX:");
    gotoligcol(8+ligne,148);
    printf("VISITE");
    ///ligne 2
    gotoligcol(13+ligne,1);
    Color(0,2);
    printf("                ");
    Color(15,0);
    gotoligcol(14+ligne,5);
    printf("PARIS");
    gotoligcol(15+ligne,5);
    printf("PRIX:");
    gotoligcol(13+ligne,143);
    Color(0,1);
    printf("                ");
    Color(15,0);
    gotoligcol(14+ligne,148);
    printf("BERNE");
    gotoligcol(15+ligne,149);
    printf("PRIX:");
    ///ligne 3
    gotoligcol(19+ligne,1);
    Color(0,2);
    printf("                ");
    Color(15,0);
    gotoligcol(20+ligne,4);
    printf("BERLIN");
    gotoligcol(21+ligne,5);
    printf("PRIX:");
    gotoligcol(19+ligne,143);
    Color(0,1);
    printf("                ");
    Color(15,0);
    gotoligcol(20+ligne,148);
    printf("ATHENE");
    gotoligcol(21+ligne,149);
    printf("PRIX:");
    ///ligne 4
    gotoligcol(26+ligne,5);
    printf("CHANCE");
    gotoligcol(25+ligne,143);
    Color(0,1);
    printf("                ");
    Color(15,0);
    gotoligcol(26+ligne,148);
    printf("DUBLIN");
    gotoligcol(27+ligne,149);
    printf("PRIX:");
    ///ligne 5
    gotoligcol(32+ligne,5);
    printf("GARE");
    gotoligcol(33+ligne,5);
    printf("PRIX:");
    gotoligcol(32+ligne,149);
    printf("GARE");
    gotoligcol(33+ligne,149);
    printf("PRIX:");
    ///ligne 6
    gotoligcol(37+ligne,1);
    Color(0,12);
    printf("                ");
    Color(15,0);
    gotoligcol(38+ligne,5);
    printf("ROME");
    gotoligcol(39+ligne,5);
    printf("PRIX:");
    gotoligcol(37+ligne,143);
    Color(0,14);
    printf("                ");
    Color(15,0);
    gotoligcol(38+ligne,147);
    printf("STOCKHOLM");
    gotoligcol(39+ligne,149);
    printf("PRIX:");
    ///ligne 7
    gotoligcol(43+ligne,1);
    Color(0,12);
    printf("                ");
    Color(15,0);
    gotoligcol(44+ligne,4);
    printf("LONDRES");
    gotoligcol(45+ligne,5);
    printf("PRIX:");
    gotoligcol(43+ligne,143);
    Color(0,14);
    printf("                ");
    Color(15,0);
    gotoligcol(44+ligne,147);
    printf("HELSINKI");
    gotoligcol(45+ligne,149);
    printf("PRIX:");
    ///ligne 8
    gotoligcol(49+ligne,1);
    Color(0,12);
    printf("                ");
    Color(15,0);
    gotoligcol(50+ligne,4);
    printf("MADRID");
    gotoligcol(51+ligne,5);
    printf("PRIX:");
    gotoligcol(49+ligne,143);
    Color(0,14);
    printf("                ");
    Color(15,0);
    gotoligcol(50+ligne,147);
    printf("VARSOVIE");
    gotoligcol(51+ligne,149);
    printf("PRIX:");
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
    gotoligcol(57+ligne,23);
    printf("PRIX:");
    gotoligcol(55+ligne,36  );
    Color(0,6);
    printf("                 ");
    Color(15,0);
    gotoligcol(56+ligne,39);
    printf("AMSTERDAM");
    gotoligcol(57+ligne,41);
    printf("PRIX:");
    gotoligcol(56+ligne,59);
    printf("CASE DE");
    gotoligcol(57+ligne,57);
    printf("COMMUNAUTE");
    gotoligcol(56+ligne,78);
    printf("GARE");
    gotoligcol(57+ligne,78);
    printf("PRIX:");
    gotoligcol(56+ligne,96);
    printf("CHANCE");
    gotoligcol(55+ligne,108);
    Color(0,8);
    printf("                 ");
    Color(15,0);
    gotoligcol(56+ligne,111);
    printf("LUXEMBOURG");
    gotoligcol(57+ligne,114);
    printf("PRIX:");
    gotoligcol(55+ligne,126);
    Color(0,8);
    printf("                ");
    Color(15,0);
    gotoligcol(56+ligne,130);
    printf("COPENHAGUE");
    gotoligcol(57+ligne,132);
    printf("PRIX:");
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

void banque()
{
    printf("ici c'est la banque");
}
