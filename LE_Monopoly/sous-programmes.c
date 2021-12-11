#include "menu.h"

int nb_alea()
{
    return rand()%(6)+1;
}

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

    printf("%d %d", de[0], de[1]);
    return de;
}



void banque()
{
    printf("ici c'est la banque");
}
