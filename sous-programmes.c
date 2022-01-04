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
        etat_de[2]=1; // on a un double
    }

    printf("%d %d", etat_de[0], etat_de[1]);
}

int info_case(int info_villes[19][9], int la_case_choisi, int info_a_rendre)// renvoie une info preciser dans les parametre d'une ville en particulier
{
    int i;
    int j;

    for (i=0; i<19; i++)
    {
        for (j=0; j<9; j++)
        {
            if (la_case_choisi == info_villes[i][j])
            {
                return info_villes[i][info_a_rendre];
            }
        }
    }
    return 0;
}

void nom_fichier(char fichiers[2][LEN])//return deux nom de fichier (un pour les joueurs et un pour le plateau)

{
    int i;
    int j;
    time_t now;

    time(&now);// Renvoie l'heure actuelle

    strcat(fichiers[0],ctime(&now));
    strcat(fichiers[1],ctime(&now));

    strcat(fichiers[0], ".txt");
    strcat(fichiers[1], ".txt");

    for (j = 0; j<2; j++)
    {
        for(i = 0 ; fichiers[j][i] != '\0' ; i++)
        {
            if(fichiers[j][i] == ' ')
            {
                fichiers[j][i] = '_';
            }
        }
    }



}

int sauvegarde_nom(char fichiers[2][LEN])
{
    FILE* pf = fopen("./fichier_save/noms_save", "a");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }

    fprintf(pf, "%s %s\n",fichiers[0], fichiers[1]);

    fclose(pf);
    pf = NULL;
    return 0;
}


int init_sauvegarde(info_joueur tabjoueurs[] ,t_mono plateau[32], char fichiers[2][LEN])// fonction lisant le contenue du fichier
                                                                                        // et le mettant dans un tableau de structure
{
    int i = 0;
    int j = 0;
    int nb_joueur;

    FILE* pf = fopen(fichiers[0], "r");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }

    fscanf(pf, "%d", &nb_joueur);
    for (i = 0 ;i <nb_joueur ; i++)
    {
        printf("download\n");

        fscanf(pf, "%d", &tabjoueurs[i].argent);
        fscanf(pf, "%d", &tabjoueurs[i].nb_double);
        fscanf(pf, "%s", tabjoueurs[i].nom);
        fscanf(pf, "%d", &tabjoueurs[i].position[0]);
        for (j = 0 ;j<10 ;j++)
        {
            fscanf(pf, "%d", &tabjoueurs[i].possession[j]);
        }
        fscanf(pf, "%d", &tabjoueurs[i].prison);


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

        fscanf(pf, "%d", &plateau[i].hotel);
        fscanf(pf, "%d", &plateau[i].hypo);
        fscanf(pf, "%d", &plateau[i].loyer);
        fscanf(pf, "%d", &plateau[i].maison);
        fscanf(pf, "%d", &plateau[i].presence);
        fscanf(pf, "%d", &plateau[i].prix);
        fscanf(pf, "%d", &plateau[i].type);
    }

    fclose(pf);
    pf = NULL;
    return 0;

}

int sauvegarde(info_joueur tabjoueurs[] ,t_mono plateau[32], char fichiers[2][LEN], int nb_joueur)// fonction ecrivant le tableau de structure
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

    fprintf(pf, "%d\n",nb_joueur);
    for (i = 0; i<nb_joueur ; i++)
    {
        printf("sauvegarde joueurs...\n");

        fprintf(pf, "%d ",tabjoueurs[i].argent);
        fprintf(pf, "%d ",tabjoueurs[i].nb_double);
        fprintf(pf, "%s ",tabjoueurs[i].nom);
        fprintf(pf, "%d ",tabjoueurs[i].position[0]);
        for (j = 0; j<20; j++)
        {
            fprintf(pf, "%d ",tabjoueurs[i].possession[j]);
        }
        fprintf(pf, "%d\n",tabjoueurs[i].prison);

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

        fprintf(pf, "%d ",plateau[i].hotel);
        fprintf(pf, "%d ",plateau[i].hypo);
        fprintf(pf, "%d ",plateau[i].loyer);
        fprintf(pf, "%d ",plateau[i].maison);
        fprintf(pf, "%d ",plateau[i].presence);
        fprintf(pf, "%d ",plateau[i].prix);
        fprintf(pf, "%d ",plateau[i].type);
        fprintf(pf,"\n");

    }
    fclose(pf);

    pf = NULL;

    return 0;
}
