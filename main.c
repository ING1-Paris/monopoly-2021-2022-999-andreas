#include "menu.h"


int main()
{
    srand(time(NULL));
    int i;
    t_mono plateau[32];
    int etat_de[3] = {0,0,0};
    /*
    -afficher le menu avec le nom des sauvegardes
    -on travaille sur le fichier choisi
    -initialisation des cases et joueur en fonction du fichier (si le nom du fichier sur lequel on travaille est en dernier dans le tableau alors tout à 0)
    -demander le nombre de joueur si besoin
    -demander les noms des joueurs si besoin
    -lancer la partie
    */
    plateau[0].type =ARRIVE;
    plateau[1].type =VILLE;
    plateau[2].type =COMMU;
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
    plateau[21].type =COMMU;
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


    ///si on cree une nouvelle partie -------------------------------------------------------
    for (i = 0; i<32;i++)
    {
        if (plateau[i].type == VILLE)
        {
            //et la c'est le drame
        }

        else if (plateau[i].type == GARE)
        {
            plateau[i].prix = 200;
        }
    }


    lance_de(etat_de);

    return 0;
}

