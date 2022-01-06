
#include "menu.h"

int main()
{
    srand(time(NULL));
    int i, j, choix, nb_joueur, nb_joueur_actu, nb_maison, nb_hotel;
    int ligne = 2;
    setConsoleSize();

    int de[3] = {0,0,0};
    t_fichier fichiers;

    strcpy(fichiers.joueur, "./fichier_saves/joueurs");
    strcpy(fichiers.plateau, "./fichier_saves/plateau");

    t_joueur tabJoueur[6];
    t_mono plateau[32];

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

    /*
    printf("depart\n");
    printf("%s\n", fichiers.joueur);
    printf("%s\n", fichiers.plateau);


    init_nom_sauvegarde(&fichiers);

    printf("%s\n", fichiers.joueur);
    printf("%s\n",fichiers.plateau);
    printf("arriver\n");
    */










///------------------------------------------menu demarrage

    choix = menu();



    if (choix==1) /// 1- NOUVELLE PARTIE
    {
        // definition des stock de maisons et hotels
        nb_maison = 32;
        nb_hotel = 12;

        //choix du nombre de joueur entre 2 et 6 joueurs
        do
        {
            printf("nombre de joueur entre 2 et 6");
            scanf("%d",&nb_joueur);
        }
        while(nb_joueur<2 || nb_joueur>6);

        //remplissage du tableau de structure joueur
        for(i=0;i<nb_joueur;i++)
        {
            printf("entrez le nom du joueur n %d",i+1);
            scanf("%s",&tabJoueur[i].nom);
            fflush(stdin);

            printf("choisissez un caractere pour votre pion");
            scanf("%c",&tabJoueur[i].pionjoueur);
            fflush(stdin);

            tabJoueur[i].argent=1500;
            tabJoueur[i].position[2]=0;

            for (j=0;j<23;j++)
            {
                tabJoueur[i].possession[j]=0;
            }
        }

        nom_fichier(&fichiers);
        sauvegarde_nom(&fichiers);
        sauvegarde(tabjoueurs ,plateau, &fichiers, nb_joueur);

    }

    else if(choix == 2) ///2-CHARGER UNE PARTIE
    {
        init_nom_sauvegarde(&fichiers); //c'est turbo cassé, ya rien qui vas
        init_sauvegarde(tabjoueurs, plateau, &fichiers);

    }

    else if(choix == 3) ///3-REGLE
    {
        //fonction qui affiche les regles
    }

    else if(choix == 4)
    {
        //fonction qui fait quitter le jeu ?
    }




    ///----------------------------------------------------------------LE JEU
    i = 0;
    do
    {

        tabJoueur[i].position[1]=tabJoueur[i].position[0];
        affichage_plateau(ligne);
        affichage_possession(tabJoueur,i,ligne);
        gotoligcol(30+ligne,70);

        affichage_plateau(ligne);

        gotoligcol(29+ligne,70);
        printf("vous avez fait:");
        gotoligcol(30+ligne,75);
        lancer_de(de);
        tabJoueur[i].position[2]=(tabJoueur[i].position[1]+de[0]+de[1])%32;
        afficher_point(tabJoueur,i,plateau,ligne);
        if ((jeanMichel[i].position[0]-jeanMichel[i].position[1])<0)
        {
            jeanMichel[i].argent+=200;
        }

        //action sur la case tombé

        ///action apres le tour
        sauvegarde(tabjoueurs, plateau, fichiers);
        i+=1;
        if (i = nb_joueur_actu)
        {
            i = 0;
        }

    }while (fin_partie(tabJoueur));


///------------------------------------------------------------------------------------------------------------------///
    return 0;
}

// on peut faire de l'alocation dynamique pour le tab tab_joueur
// il faut modifie les fichier sauvegarde parce que ya un element en plus dans la stucture joueur

