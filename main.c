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


    info_joueur jeanMichel;

    int info_villes[19][9] ={{60,50,2,10,30,90,160,250,1},/// prix | prix maison | loyer sans maison | 1 maison | 2 maisons | 3 maisons | 4 maisons | 1 hotel | place sur le plateau
                        {60,50,4,20,60,180,320,450,3},
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

    ///si on cree une nouvelle partie -------------------------------------------------------


    nb_maison = 32;
    nb_hotel = 12;

    //initialisation des prix des cases ville et gare

    //initialisation de l'argent des joueurs
    jeanMichel.argent = 1500;
    jeanMichel.possession[0] = 3;
    jeanMichel.position[0] = 3;

    plateau[3].maison = 4;

    ///debut d'un tours

    do
    {
        printf("1. lancer des des\n");
        printf("2. acheter/vendre une maison ou un hotel\n");
        printf("3. hypothequer une case\n");

        scanf("%d", &choix);
    }
    while((choix != 1 ) && (choix != 2 ) && (choix != 3));

    switch(choix)
    {
        case 1 :
        {
            break;
        }

        case 2 :
        {
            achat_vente_maison(&jeanMichel, plateau, &nb_maison, &nb_hotel, info_villes);
            break;
        }

        case 3 :
        {
            hypotheque(&jeanMichel, plateau, &nb_maison, &nb_hotel, info_villes);
            break;
        }
    }


    printf("%d\n", plateau[3].maison );
    printf("%d\n", jeanMichel.argent);
    //lance_de(etat_de);

    return 0;
}

