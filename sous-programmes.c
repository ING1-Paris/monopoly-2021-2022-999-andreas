#include "menu.h"


int nb_alea()
{
    return rand()%(6)+1;
}

void lance_de(int etat_de[3])
{

    etat_de[0] = nb_alea();
    etat_de[1] = nb_alea();

    if (etat_de[0]==etat_de[1])
    {
        printf("c'est un double ! vous relancerai les des\n");
        etat_de[2]+=1; // on a un double
    }

    printf("%d %d", etat_de[0], etat_de[1]);
}

///il faudra integrer ça pour initialiser les loyer des cases avec le fichier infos_villes /// il faudra aussi faire ca pour les infos à sauvegarder

void lecture(t_film tab[MAX], char fichier[20])// fonction lisant le contenue du fichier
                                               // et le mettant dans un tableau de structure
{
    int i = 0;

    FILE* pf = fopen(fichier, "r");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }

    for (i = 0 ;i < MAX ; i++)
    {
        printf("download\n");

        fscanf(pf, "%d", &tab[i].prix);
        fscanf(pf, "%s", tab[i].titre);
        fscanf(pf, "%s", tab[i].rea);
        fscanf(pf, "%d", &tab[i].annee);
        fscanf(pf, "%s", tab[i].genre);


    }
    fclose(pf);
    pf = NULL;

}

void ecriture(t_film tab[MAX], char ficher[20])// fonction ecrivant le tableau de structure
                                               // dans le fichier texte
{
    int i = 0;

    FILE* pf = fopen(ficher, "w");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }

    for (i = 0; i<MAX ; i++)
    {
        printf("upload\n");

        fprintf(pf, "%d ",tab[i].id);
        fprintf(pf, "%s ",tab[i].titre);
        fprintf(pf, "%s ",tab[i].rea);
        fprintf(pf, "%d ",tab[i].annee);
        fprintf(pf, "%s\n",tab[i].genre);


    }
    fclose(pf);
    pf = NULL;

}
///note : je ne sais pas encore comment on vas faire pour lire correctement le fichier, mettre les bonnes infos au bon endroit
