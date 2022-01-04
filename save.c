#include "menu.h"
void nom_fichier(char fichiers[2][LEN])//return deux nom de fichier (un pour les joueurs et un pour le plateau)

{
    time_t now;

    time(&now);// Renvoie l'heure actuelle

    strcat(fichiers[0],ctime(&now));
    strcat(fichiers[1],ctime(&now));

    strcat(fichiers[0], ".txt");
    strcat(fichiers[1], ".txt");

}


int init_sauvegarde(t_joueur* tabjoueurs[] ,t_mono* plateau[32], char fichiers[2][LEN])// fonction lisant le contenue du fichier
                                                                                        // et le mettant dans un tableau de structure
{
    int i = 0;
    int j = 0;

    FILE* pf = fopen(fichiers[0], "r");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }

    for (i = 0 ;i < 6/*il faudra mettre la taille logique du tabjoueurs*/ ; i++)
    {
        printf("download\n");

        fscanf(pf, "%d", &tabjoueurs[i]->argent);
        fscanf(pf, "%d", &tabjoueurs[i]->nb_double);
        fscanf(pf, "%s", tabjoueurs[i]->nom);
        fscanf(pf, "%d", &tabjoueurs[i]->position[0]);
        for (j = 0 ;j<10 ;j++)
        {
            fscanf(pf, "%d", &tabjoueurs[i]->possession[j]);
        }
        fscanf(pf, "%d", &tabjoueurs[i]->prison);


    }
    fclose(pf);

    pf = fopen(fichiers[0], "r");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }

    for (i = 0 ;i < 32 ; i++)
    {
        printf("download\n");

        fscanf(pf, "%d", &plateau[i]->hotel);
        fscanf(pf, "%d", &plateau[i]->hypo);
        fscanf(pf, "%d", &plateau[i]->loyer);
        fscanf(pf, "%d", &plateau[i]->maison);
        fscanf(pf, "%d", &plateau[i]->presence);
        fscanf(pf, "%d", &plateau[i]->prix);
        fscanf(pf, "%d", &plateau[i]->type);
    }

    fclose(pf);
    pf = NULL;
    return 0;

}

int sauvegarde(t_joueur* tabjoueurs[] ,t_mono* plateau[32], char fichiers[2][LEN])// fonction ecrivant le tableau de structure
                                                                                                             // dans le fichier texte
                                                                                                             // la fonction vas cree le fichier (vue qu'il n'existe pas)
{
    int i = 0;
    int j = 0;

    FILE* pf = fopen(fichiers[0], "w");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }

    for (i = 0; i<6/*il faudra mettre la taille logique du tabjoueurs*/ ; i++)
    {
        printf("sauvegarde joueurs...\n");

        fprintf(pf, "%d ",tabjoueurs[i]->argent);
        fprintf(pf, "%d ",tabjoueurs[i]->nb_double);
        fprintf(pf, "%s ",tabjoueurs[i]->nom);
        fprintf(pf, "%d ",tabjoueurs[i]->position[0]);
        for (j = 0; j<20; j++)
        {
            fprintf(pf, "%d ",tabjoueurs[i]->possession[j]);
        }
        fprintf(pf, "%d\n",tabjoueurs[i]->prison);


    }
    fclose(pf);

    pf = fopen(fichiers[1], "w");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }

    for (i = 0; i<32; i++)
    {
        printf("sauvegarde plateau...\n");

        fprintf(pf, "%d ",plateau[i]->hotel);
        fprintf(pf, "%d ",plateau[i]->hypo);
        fprintf(pf, "%d ",plateau[i]->loyer);
        fprintf(pf, "%d ",plateau[i]->maison);
        fprintf(pf, "%d ",plateau[i]->presence);
        fprintf(pf, "%d ",plateau[i]->prix);
        fprintf(pf, "%d ",plateau[i]->type);
        fprintf(pf,"\n");

    }
    fclose(pf);

    pf = NULL;

    return 0;
}
