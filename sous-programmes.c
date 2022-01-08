#include "menu.h"
// fonction pour afficher les regles (je crois que ça se voit)
void regles()
{
    printf(" 888b     d888  .d88888b.  888b    888  .d88888b.  8888888b.   .d88888b.  888      Y88b   d88P\n");
    printf(" 8888b   d8888 d88P' 'Y88b 8888b   888 d88P' 'Y88b 888   Y88b d88P' 'Y88b 888       Y88b d88P\n");
    printf(" 88888b.d88888 888     888 88888b  888 888     888 888    888 888     888 888        Y88o88P\n");
    printf(" 888Y88888P888 888     888 888Y88b 888 888     888 888   d88P 888     888 888         Y888P\n");
    printf(" 888 Y888P 888 888     888 888 Y88b888 888     888 8888888P'  888     888 888          888\n");
    printf(" 888  Y8P  888 888     888 888  Y88888 888     888 888        888     888 888          888\n");
    printf(" 888   '   888 Y88b. .d88P 888   Y8888 Y88b. .d88P 888        Y88b. .d88P 888          888\n");
    printf(" 888       888  'Y88888P'  888    Y888  'Y88888P'  888         'Y88888P'  88888888     888\n");
    printf("\n\n");

    printf("Deroulement du jeu :\n");
    printf("\nUne partie de Monopoly se deroule au tour par tour ou les joueurs jouent les uns apres les autres. Les joueurs utilisent les 2 des ordinaires a 6 faces. Chaque joueur lance les des, avance\n");
    printf("son pion sur le parcours en fonction de la valeur qu'il a obtenu, puis effectue une action en fonction de la case sur laquelle il est arrete :\n");
    printf("\n");
    printf("Cases Proprietes :\n");
    printf("\n");
    printf("-Le joueur tombe sur un terrain ou une gare qui n'appartient a personne : il peut s'il le souhaite, en devenir proprietaire.\n");
    printf("-Le joueur tombe sur un terrain une gare qui lui appartient : il peut s'il le souhaite ajouter une maison ou un hotel, s'il en a les capacites fianciere.\n");
    printf("-Le joueur tombe sur un terrain ou une gare qui appartient a un adversaire : il doit alors lui payer un loyer. Le montant est fixee sur la carte de propriete detenu par le proprietaire. Si la case correspond a un terrain ou une gare\n");
    printf("hypotheque, le joueur ne doit rien payer au proprietaire.\n");
    printf("\n");
    printf("Autres cases :\n");
    printf("\n");
    printf("-Le joueur tombe sur la Case Chance : il tire une carte Chance. Comme son nom ne l'indique pas, les cartes Chances ne sont pas forcement synonyme de bonnes chances : La carte Chance  peut en effet generer une amende pour le joueur.\n");
    printf(" fun fact :Le terme Chance dans les editions françaises est un faux-ami puisqu'il s'agit d'une adaptation de l'anglais Chance qui signifie hasard et donc pas necessaire un bon hasard.\n");
    printf("-Le joueur tombe sur une Case Caisse de Communaute : il doit alors tirer une carte Caisse de Communaute.\n");
    printf("-Le joueur tombe sur la Case Taxe de luxe : Pas de chance, il doit payer le montant correspondant a la banque.\n");
    printf("-Le joueur passe sur la Case Depart : S'il s'arrete exactement sur cette case, il gagne 400 euros. S'il ne fait que passer par cette case, il ne gagne que 200 euros.\n");
    printf("-Le joueur s'arrete sur la Case Impôts sur le revenu : il doit alors payer 200 euros.\n");
    printf("-Le joueur tombe sur la Case Allez en Prison : Il doit directement se rendre en prison sans passer par la case depart et donc sans toucher les 200 ou 400 euros prevus normalement.\n");
    printf("-Le joueur arrive sur la Case Simple visite : Il s'agit d'une case neutre sans action particuliere. Il s'agit d'une simple visite de courtoisie aux prisonniers.\n");
    printf("-Le joueur tombe sur la Case Prison : il applique les regles pour en sortir, et dans l'edition Monopoly, regles maison, il ne perçoit plus ses loyers.\n");
    printf("-Le joueur s'arrete sur la Case Parc gratuit : il s'agissait d'une case neutre sans action.\n");
    printf("Les terrains sont groupes par couleur. Des qu'un joueur est en possession d'un terrain, il pourra y construire des maisons et des hôtels s'il tombe sur celui-ci. Un hôtel correspond a 5 maisons.\n");
    printf("\n");
    printf("Case Prison :\n");
    printf("\n");
    printf("S'il tombe sur la case correspondante, ou s'il tire une mauvaise carte Chance, le joueur pourra se retrouver en prison avec l'impossibilite d'avancer dans le jeu. Il existe exactement 3 scenarios qui peuvent pousser le joueur a\n");
    printf("devenir detenu en prison :\n");
    printf("-Le joueur s'arrete sur la case : Allez en prison ;\n");
    printf("-Le joueur fait 3 fois de suite, un double de des (1+1, 2+2; 3+3 …) ;\n");
    printf("-Le joueur pioche une carte “Chance” qui l'invite a se rendre en prison\n");
    printf("\n");
    printf("Lorsqu'un joueur est detenu en prison, il pose son pion sur la case Prison et ne peut plus avancer sur le plateau. Il attend son tour jusqu'a ce que sa peine soit terminee et qu'il soit libere de prison. Ainsi, lorsqu'il est en prison,\n");
    printf("le joueur perçoit les loyers de ses terrains.\n");
    printf("\n");
    printf("Il existe plusieurs methodes qui permettent de sortir de prison au Monopoly :\n");
    printf("-Le joueur prisonnier detient la carte : Vous etes libere de prison qu'il peut acheter a un adversaire ou qu'il peut avoir dans son patrimoine) ;\n");
    printf("-Lors de son tour de jeu, le joueur fait double des (1+1, 2+2…) ;\n");
    printf("-Le joueur s'acquitte d'une caution de 50 euros.\n");
    printf("\n");
    printf("La duree de detention maximale est de 3 tours. S'il n'a pas reussi a sortir de prison a ce moment la (via un double des par exemple), le joueur sera alors dans l'obligation de payer le montant de la caution fixee a 50 euros\n");
    printf("\n");
    printf("Fin de la partie de Monopoly :\n");
    printf("\n");
    printf("Une partie de Monopoly s'arrete lorsqu'un joueur (le vainqueur) est le dernier joueur a ne pas avoir fait faillite. A ce moment la, le joueur se retrouve en situation de monopole puisqu'il detient l'ensemble des proprietes du jeu.\n");
    printf("\n");
}

// renvoie si la position du joueur est possessedé par quelqu'un
int possession(t_joueur jeanMichel)
{
    int i;

    for(i = 0; i<23; i++)
    {
        if (jeanMichel.possession[i]==jeanMichel.position[0])
        {
            return 1;
        }

    }
    return 0;
}

//renvoie le resultat d'un lancé de des
void lancer_de(int de[3])
{
    de[0] = rand()%(6)+1;
    de[1] = rand()%(6)+1;


    if (de[0]==de[1])
    {

        de[2]=1; // on a un double
    }

    printf("%d %d",de[0], de[1]);
}

// renvoie une info preciser dans les parametre d'une ville en particulier
int info_case(int info_villes[19][9], int la_case_choisi, int info_a_rendre)
{
    int i;
    int j;

    for (i=0; i<19; i++)
    {
        for (j=0; j<9; j++)
        {
            if (la_case_choisi == info_villes[i][j])
            {
                return info_villes[i][info_a_rendre];
            }
        }
    }
    return 0;
}

// test si il y a encore des joueur en jeux
int fin_partie(t_joueur tabJoueur[], int nb_joueur)
{
    int i;
    int nb = 0;

    for(i = 0; i<nb_joueur; i++)
    {
        if (tabJoueur[i].argent == 1)
        {
            nb+=1;
        }
    }

    if (nb>=2)
    {
        return 1;
    }
    return 0;
}


//affiche le menu demarrage
void demarrage(int* nb_maison, int* nb_hotel, int* nb_joueur, int* nb_joueur_actu, int* k, t_mono plateau[32],t_joueur tabJoueur[6], t_fichier* fichiers)
{
    int choix;
    int i;
    int j;

    printf(" 888b     d888  .d88888b.  888b    888  .d88888b.  8888888b.   .d88888b.  888      Y88b   d88P\n");
    printf(" 8888b   d8888 d88P' 'Y88b 8888b   888 d88P' 'Y88b 888   Y88b d88P' 'Y88b 888       Y88b d88P\n");
    printf(" 88888b.d88888 888     888 88888b  888 888     888 888    888 888     888 888        Y88o88P\n");
    printf(" 888Y88888P888 888     888 888Y88b 888 888     888 888   d88P 888     888 888         Y888P\n");
    printf(" 888 Y888P 888 888     888 888 Y88b888 888     888 8888888P'  888     888 888          888\n");
    printf(" 888  Y8P  888 888     888 888  Y88888 888     888 888        888     888 888          888\n");
    printf(" 888   '   888 Y88b. .d88P 888   Y8888 Y88b. .d88P 888        Y88b. .d88P 888          888\n");
    printf(" 888       888  'Y88888P'  888    Y888  'Y88888P'  888         'Y88888P'  88888888     888\n");
    printf("\n\n");
    printf("1- NOUVELLE PARTIE\n2-CHARGER UNE PARTIE\n3-REGLE\n4-QUITTER");
    printf("entrer le numero de l'action a suivre : ");
    do
    {
        scanf("%d",&choix);
    }
     while (choix<0 || choix >4);


    if (choix==1) /// 1- NOUVELLE PARTIE
    {
        // definition des stock de maisons et hotels
        *nb_maison = 32;
        *nb_hotel = 12;

        //choix du nombre de joueur entre 2 et 6 joueurs
        do
        {
            printf("nombre de joueur entre 2 et 6");
            scanf("%d", nb_joueur);
        }
        while(*nb_joueur<2 || *nb_joueur>6);

        //remplissage du tableau de structure joueur
        for(i=0;i<*nb_joueur;i++)
        {
            printf("entrez le nom du joueur n %d",i+1);
            scanf("%s",tabJoueur[i].nom);
            fflush(stdin);

            printf("choisissez un caractere pour votre pion");
            scanf("%c",&tabJoueur[i].pionjoueur);
            fflush(stdin);

            tabJoueur[i].argent=1500;
            tabJoueur[i].position[1]=0;

            for (j=0;j<23;j++)
            {
                tabJoueur[i].possession[j]=0;
            }
        }

        nom_fichier(fichiers);
        sauvegarde_nom(fichiers);
        sauvegarde(tabJoueur ,plateau, fichiers, *nb_joueur, *nb_joueur_actu, *nb_maison, *nb_hotel);

        *k = rand()% *nb_joueur-1;
        printf("c'est %s qui commence", tabJoueur[*k].nom);

    }

    else if(choix == 2) ///2-CHARGER UNE PARTIE
    {
        i = 0;
        init_nom_sauvegarde(fichiers);
        init_sauvegarde(tabJoueur, plateau, fichiers, nb_joueur_actu, nb_joueur, nb_maison, nb_hotel);

    }

    else if(choix == 3) ///3-REGLE
    {
        regles();
    }

    else if(choix == 4)
    {
        //fonction qui fait quitter le jeu ?
    }
}


//jsp
void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

//jsp
void gotoligcol( int lig, int col ) {
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

//jsp
void setConsoleSize()
{
    keybd_event(VK_MENU,0x38,0,0); //Appuie sur ALT
    keybd_event(VK_RETURN,0x1c,0,0); //Appuie ENTREE
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0); // Relache ENTREE
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0); //Relache ALT
}

//affiche le plateau
void affichage_plateau(int ligne)
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

//affiche le pion ?
void afficher_point(t_joueur joueur[6],int i,t_mono plat[32],int ligne)
{
    int colplat;
    colplat=joueur[i].position[2];
    colplat=colplat%8;
    if (joueur[i].position[2]<9)
        {
            if (colplat!=0)
            {
                plat[joueur[i].position[2]].presence++;
                gotoligcol(10+ligne,colplat*19+i);
                printf("%c",joueur[i].pionjoueur);
            }
            else
            {
                gotoligcol(10+ligne,144+i);
                printf("%c",joueur[i].pionjoueur);
                plat[joueur[i].position[2]].presence++;
            }
        }
        else if (joueur[i].position[2]>=9 && joueur[i].position[2]<17)
        {
            if (colplat!=0)
            {
                plat[joueur[i].position[2]].presence++;
                gotoligcol(10+colplat*6+ligne,144+i);
                printf("%c",joueur[i].pionjoueur);
            }
            else
            {
                gotoligcol(59+ligne,144+i);
                printf("%c",joueur[i].pionjoueur);
                plat[joueur[i].position[2]].presence++;
            }
        }
        else if (joueur[i].position[2]>=17 && joueur[i].position[2]<=25)
        {
            if (colplat!=0)
            {
                plat[joueur[i].position[2]].presence++;
                gotoligcol(59+ligne,154-colplat*19+i);
                printf("%c",joueur[i].pionjoueur);
            }
            else
            {
                gotoligcol(59+ligne,5+i);
                printf("%c",joueur[i].pionjoueur);
                plat[joueur[i].position[2]].presence++;
            }
        }
        else
        {
            if (colplat!=0)
            {
                plat[joueur[i].position[2]].presence++;
                gotoligcol(60-colplat*6,3+i);
                printf("%c",joueur[i].pionjoueur);
            }
            else
            {
                gotoligcol(ligne,5+i);
                printf("%c",joueur[i].pionjoueur);
                plat[joueur[i].position[2]].presence++;
            }
        }
}

//affiche les possession du joueur en train de jouer
void affichage_possession(t_joueur joueur[6], int i,int ligne)
{
    int j;
    gotoligcol(15+ligne,22);
    printf("joueur numero %d",i+1);
    gotoligcol(16+ligne,22);
    printf("argent: %d",joueur[i].argent);
    for(j=0;j<23;j++)
    {
        gotoligcol(17+ligne+i,22);
        printf("%d",joueur[i].possession[j]);
    }
}


