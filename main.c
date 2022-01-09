
#include "menu.h"

int main()
{
    srand(time(NULL));
    int i, j, choix, nb_joueur, nb_joueur_actu, nb_maison, nb_hotel;
    int ligne = 2;
    int prix_case,valid;
    setConsoleSize();

    int de[3] = {0,0,0};
    t_fichier fichiers;

    strcpy(fichiers.joueur, "./fichier_saves/joueurs");
    strcpy(fichiers.plateau, "./fichier_saves/plateau");

    t_joueur tabJoueur[6];
    t_mono plateau[32];

    int info_villes[32][9] ={{60,50,2,10,30,90,160,250,1},/// prix | prix maison | loyer sans maison | 1 maison | 2 maisons | 3 maisons | 4 maisons | 1 hotel | place sur le plateau
                        {0,0,0,0,0,0,0,0,2},              ///   0         1                 2              3          4           5           6          7                8
                        {60,50,4,20,60,180,320,450,3},
                        {0,0,0,0,0,0,0,0,4},
                        {200,0,25,50,100,200,0,0,5},
                        {100,50,6,30,90,270,400,550,6},
                        {120,50,8,40,100,300,450,600,7},
                        {0,0,0,0,0,0,0,0,8},
                        {120,100,10,50,150,450,625,750,9},
                        {140,100,10,50,150,450,625,750,10},
                        {160,100,12,60,180,500,700,900,11},
                        {200,0,25,50,100,200,0,0,12},
                        {180,100,14,70,200,550,750,950,13},
                        {180,100,14,70,200,550,750,950,14},
                        {180,100,16,80,220,600,800,1000,15},
                        {0,0,0,0,0,0,0,0,16},
                        {220,150,18,90,250,70,875,1050,17},
                        {240,150,20,100,300,750,925,1100,18},
                        {0,0,0,0,0,0,0,0,19},
                        {200,0,25,50,100,200,0,0,21},
                        {0,0,0,0,0,0,0,0,20},
                        {260,150,22,110,330,800,975,1150,22},
                        {280,150,24,120,360,850,1025,1200,23},
                        {0,0,0,0,0,0,0,0,24},
                        {300,200,26,130,390,900,1100,1275,25},
                        {300,200,26,130,390,900,1100,1275,26},
                        {320,200,28,150,450,1000,1200,1400,27},
                        {200,0,25,50,100,200,0,0,28},
                        {0,0,0,0,0,0,0,0,29},
                        {350,200,35,175,500,1100,1300,1500,30},
                        {400,200,50,200,600,1400,1700,2000,31},
                        {0,0,0,0,0,0,0,0,32}};


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



///------------------------------------------menu demarrage

demarrage(&nb_maison, &nb_hotel, &nb_joueur, &nb_joueur_actu, &i, plateau, tabJoueur, &fichiers);

///----------------------------------------------------------------LE JEU
///initialisation des trucs à initialiser systematiquement

int carte=rand()%(15);

    do
    {
        if (plateau[tabJoueur[i].position[1]].type == PRISON)
        {
            casedouane(de, tabJoueur, i);
        }


        tabJoueur[i].position[0]=tabJoueur[i].position[1];
        affichage_plateau(ligne);
        affichage_possession(tabJoueur,i,ligne,plateau);
        gotoligcol(29+ligne,70);
        printf("vous avez fait:");
        gotoligcol(30+ligne,75);
        lancer_de(de);
        tabJoueur[i].position[1]=(tabJoueur[i].position[1]+de[0]+de[1])%32;
        affichage_infocase(tabJoueur,i,ligne,plateau,info_villes);
        for (j=0;j<nb_joueur;j++)
                {
                    afficher_point(tabJoueur,j,plateau,ligne);
                }
        if ((tabJoueur[i].position[1]-tabJoueur[i].position[0])<0)
        {
            gotoligcol(20,70);
            printf("vous avez ressu 200 euros pour avoir passe l'arrive");
            tabJoueur[i].argent+=200;
        }


        switch(plateau[tabJoueur[i].position[1]].type)
        {
            case VILLE:
            {

                if (plateau[tabJoueur[i].position[1]].possesseder == 1)
                {
                    gotoligcol(34,75);
                    printf("vous etes tomber sur une ville qui appartient a un joueur tu as paye %d euros",plateau[tabJoueur->position[1]].loyer);
                    scanf("%d",&valid);
                    tabJoueur[i].argent -= plateau[tabJoueur->position[1]].loyer;
                }

                else
                {
                    prix_case=info_case(info_villes,tabJoueur[i].position[1],0);
                    do
                    {
                        gotoligcol(34,57);
                        printf("vous etes sur une ville qui appartient a personne.");
                        gotoligcol(35,53);
                        printf("Elle coute %d euros voulez vous l acheter. Entrez 1 pour oui ou 2 pour non",prix_case);
                        scanf("%d",&valid);
                    }while (valid<1 || valid >2);
                    achat_ville(&tabJoueur[i], plateau, &nb_maison, &nb_hotel, info_villes);
                }

                break;
            }

            case GARE:
            {

                if (plateau[tabJoueur->position[1]].possesseder == 0)
                {
                    prix_case=info_case(info_villes,tabJoueur[i].position[1],0);
                    do
                    {
                        gotoligcol(34,57);
                        printf("vous etes sur un gare qui appartient a personne.");
                        gotoligcol(35,53);
                        printf("Elle coute %d euros voulez vous l acheter? Entrez 1 pour oui ou 2 pour non",prix_case);
                        scanf("%d",&valid);
                    }while (valid<1 || valid >2);
                    achat_ville(&tabJoueur[i], plateau, &nb_maison, &nb_hotel, info_villes);
                }

                else
                {
                     tabJoueur[i].argent -= plateau[tabJoueur->position[1]].loyer;
                }

                break;
            }

            case CHANCE:
            {
                carte=casechance(tabJoueur, i, plateau, ligne,carte);
                break;
            }

            case COMM:
            {
                carte=casedecommunaute(ligne, i, plateau, tabJoueur,carte);
                break;
            }

            case PRISON:
            {
                gotoligcol(11+ligne,148+i);
                printf("%c",tabJoueur[i].pionjoueur);
                tabJoueur[i].position[1]=8;
                tabJoueur[i].position[0]=7;

                afficher_point(tabJoueur,i,plateau,ligne);
                break;
            }

            case ARRIVE:
            case PARC:
            {
                gotoligcol(34,75);
                printf("reposez vous");
                break;
            }

            case IMPOT:
            {
                gotoligcol(34,75);
                printf("vous etes tomber sur la case impot vous avez paye 200 euros");
                tabJoueur[i].argent -= 200;
                break;
            }
        }

        if(tabJoueur[i].argent<0)
        {
            pas_argent(tabJoueur, plateau, &nb_maison, &nb_hotel, info_villes);
        }

        affichage_possession(tabJoueur,i,ligne,plateau);



        ///action apres le tour
        plusieurs_gares(tabJoueur[i], plateau, info_villes);

        sauvegarde(tabJoueur, plateau, &fichiers,nb_joueur, nb_joueur_actu, nb_maison, nb_hotel);
        i+=1;
        if (i == nb_joueur_actu)
        {
            i = 0;
        }

        printf("voulez vous aller au menu principale ? oui:1 non:0");
        scanf("%d", &choix);

        if (choix)
        {
            demarrage(&nb_maison, &nb_hotel, &nb_joueur, &nb_joueur_actu, &i, plateau, tabJoueur, &fichiers);
        }

    }while (fin_partie(tabJoueur, nb_joueur));


//il faudrait supprimer le fichier quand la partie est fini

///------------------------------------------------------------------------------------------------------------------///
    return 0;
}

// on peut faire de l'alocation dynamique pour le tab tab_joueur
// il faut modifie les fichier sauvegarde parce que ya un element en plus dans la stucture joueur

