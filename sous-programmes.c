#include "menu.h"

int nb_alea()
{
    return rand()%(6)+1;
}

void lance_de(int etat_de[])
{

    etat_de[0] = nb_alea();
    etat_de[1] = nb_alea();

    if (etat_de[0]==etat_de[1])
    {
        printf("c'est un double ! vous relancerai les des\n");
        etat_de[2]=1; // on a un double

    }

    printf("%d %d", etat_de[0], etat_de[1]);
}



