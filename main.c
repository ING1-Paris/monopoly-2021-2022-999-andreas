#include "menu.h"


int main()
{
    srand(time(NULL));

    int etat_de[3] = {0,0,0};
    int i;
    info_joueur Dennis;

    for (i=0;i<2;i++)
    {
        printf("%d ",etat_de[i]);
    }
    printf("\n");

    lance_de(etat_de);

    for (i=0;i<2;i++)
    {
        printf("%d ",etat_de[i]);
    }



    banque(Dennis);


    return 0;
}

