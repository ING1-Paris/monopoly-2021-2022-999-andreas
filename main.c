
#include "menu.h"

int main()
{
    srand(time(NULL));
    int i;
    t_mono plateau[32];
    int etat_de[3] = {0,0,0};
    int nb_maison;
    int nb_hotel;
    int choix;
    int nb_joueur;
    char fichiers[2][LEN] = {"./fichier_saves/joueurs.txt","./fichier_saves/plateau.txt"};

    info_joueur tabJoueurs[6];

    int info_villes[19][9] ={{60,50,2,10,30,90,160,250,1},/// prix | prix maison | loyer sans maison | 1 maison | 2 maisons | 3 maisons | 4 maisons | 1 hotel | place sur le plateau
                        {60,50,4,20,60,180,320,450,3},    ///   0         1                 2              3          4           5           6          7                8
                        {100,50,6,30,90,270,400,550,6},   // il faut rajouter une case groupe de couleur ou pas
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
                        //il manque les gares :(

    plateau[0].type =ARRIVE;
    plateau[1].type =VILLE;
    plateau[2].type =COMM;
    plateau[3].type =VILLE;
    plateau[4].type =IMPOT;
    plateau[5].type =GARE;
    plateau[6].type =VILLE;
    plateau[7].type =VILLE;
    plateau[8].type =PARC;
    plateau[9].type =VILLE;
    plateau[10].type =VILLE;
    plateau[11].type =VILLE;
    plateau[12].type =GARE;
    plateau[13].type =VILLE;
    plateau[14].type =VILLE;
    plateau[15].type =VILLE;
    plateau[16].type =PARC;
    plateau[17].type =VILLE;
    plateau[18].type =VILLE;
    plateau[19].type =CHANCE;
    plateau[20].type =GARE;
    plateau[21].type =COMM;
    plateau[22].type =VILLE;
    plateau[23].type =VILLE;
    plateau[24].type =PRISON;
    plateau[25].type =VILLE;
    plateau[26].type =VILLE;
    plateau[27].type =VILLE;
    plateau[28].type =GARE;
    plateau[29].type =CHANCE;
    plateau[30].type =VILLE;
    plateau[31].type =VILLE;

    /*
    -afficher le menu avec le nom des sauvegardes
    -on travaille sur le fichier choisi
    -initialisation des cases et joueur en fonction du fichier (si le nom du fichier sur lequel on travaille est en dernier dans le tableau alors tout à 0)
    -demander le nombre de joueur si besoin
    -demander les noms des joueurs si besoin
    -lancer la partie
    */

    //--------------------------------------------------------- on lis et on affiche se que contient le fichier nom
    /*                                                            //le joueur choisi la save qu'il veut charger
    char nom_tempo[15][2][LEN];

    FILE* pf = fopen("./fichier_save/noms_save", "r");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
    }

    for (i = 0 ;i <15 ; i++)
    {
        printf("download\n");

        fscanf(pf, "%s", nom_tempo[i][0]);
        fscanf(pf, "%s", nom_tempo[i][1]);
        printf("%d. %s %s\n", i+1, nom_tempo[i][0], nom_tempo[i][1]);
    }

    fclose(pf);
    pf = NULL;

    do
    {
        printf("entrer le numero de la sauvegarde que vous voulez charger");
        scanf("%d", &choix);
    }
    while((choix<16) && (choix>0));

    for(i = 0; i<60; i++)
    {
        fichiers[0][i] = nom_tempo[choix][0][i];
        fichiers[1][i] = nom_tempo[choix][1][i];
    }*/





    //initialisation à partir des noms de fichiers selectionner

    ///si on cree une nouvelle partie -------------------------------------------------------

    nb_maison = 32;
    nb_hotel = 12;
    nb_joueur = 6;


    //initialisation des prix des cases ville et gare

    //initialisation des infos des joueurs

    for (int i = 0; i<32; i++)
    {
        plateau[i].hotel = 0;
        plateau[i].hypo = 0;
        plateau[i].loyer = 0;
        plateau[i].maison = 0;
        plateau[i].presence = 0;
        plateau[i].prix = 0;
        plateau[i].type = 0;
    }

    for ( i=0; i<6; i++)
    {
        tabJoueurs[i].argent = 200;
        tabJoueurs[i].nb_double = 0;
        tabJoueurs[i].nom[0] = "y";
        tabJoueurs[i].position[0] = 2; // il faudra bien initialiser à 0 /!\ tabJoueurs[i].prison = 0;
    }

    sauvegarde(tabJoueurs ,plateau ,fichiers, nb_joueur);


    ///debut d'un tours

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
            tabdejoueur[i].position[2]=0;
            for (j=0;j<23;j++)
            {
                tabdejoueur[i].possession[j]=0;
            }
        }
        do
        {
            for (i=0;i<nbdejoueur;i++)
            {
                tabdejoueur[i].position[1]=tabdejoueur[i].position[2];
                plateau(ligne);
                affichage_possession(tabdejoueur,i,ligne);
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

        switch(choix)
            {
                case 1 :
                {
                    break;
                }

                case 2 :
                {
                    achat_vente_maison(&tabdejoueur[i], plateau, &nb_maison, &nb_hotel, t_villes[19][9]);
                    break;
                }

                case 3 :
                {
                    hypotheque(&tabdejoueur[i], plateau, &nb_maison, &nb_hotel, t_villes[19][9]);
                    break;
                }
            }
                plateau(ligne);

                gotoligcol(29+ligne,70);
                printf("vous avez fait:");
                gotoligcol(30+ligne,75);
                lancer_de(de);
                tabdejoueur[i].position[2]=(tabdejoueur[i].position[1]+de[0]+de[1])%32;
                afficher_point(tabdejoueur,i,plat,ligne);
                passage_arrivee(tabdejoueur,i);
                ///action apres le tour
                nddejoueurenjeu=0;
                system('cls');
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
