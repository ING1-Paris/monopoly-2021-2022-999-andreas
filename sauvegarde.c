#include "menu.h"



// initialise le nom du fichier sur lequel on vas travailler /// ça marche hallelujah
void init_nom_sauvegarde(t_fichier* fichiers)
    {
        int i = 0;
        int choix = 0;
        int nb_sauvegarde = 0;
        char entrer[LEN];
        t_fichier nom_tempo[15];

        FILE* pf = fopen("./fichier_saves/noms_save", "r");
        if (pf == NULL)
        {
            printf("Erreur d'ouverture de fichier.");
        }

        for (i = 0; i<15; i++)
        {
            printf("download\n");

            fscanf(pf, "%s\n", entrer);

            if((entrer[2] != 'f') && (entrer[3] != 'i')) {continue;} // on verifie que c'est un fichier valide afin de ne pas prendre inutilement les case vides

            strcpy(nom_tempo[i].joueur, entrer);

            fscanf(pf, "%s\n", entrer);
            strcpy(nom_tempo[i].plateau, entrer);

            printf("%d\t%s %s\n", nb_sauvegarde+1, nom_tempo[i].joueur, nom_tempo[i].plateau);

            nb_sauvegarde += 1;
        }

        fclose(pf);
        pf = NULL;

        do
        {
            printf("entrer le numero de la sauvegarde que vous voulez charger");
            scanf("%d", &choix);
        }
        while((choix>nb_sauvegarde) && (choix<1));

        strcpy(fichiers->joueur, nom_tempo[choix-1].joueur);
        strcpy(fichiers->plateau, nom_tempo[choix-1].plateau);

    }

//cree deux noms de fichier (un pour les joueurs et un pour le plateau)
void nom_fichier(t_fichier* fichiers)
{
    int i;
    time_t now;

    time(&now);// Renvoie l'heure actuelle,
    strcat(fichiers->joueur,ctime(&now));
    strcat(fichiers->plateau,ctime(&now));

    for(i = 0 ; fichiers->joueur[i] != '\0' ; i++)
    {
        if(fichiers->joueur[i] == ' ' || fichiers->joueur[i] == ':')
        {
            fichiers->joueur[i] = '_';
            fichiers->plateau[i] = '_';
        }

        if(fichiers->joueur[i] == '\n') //les chiens ya un retour à la ligne apres l'heure
        {
            fichiers->joueur[i] = fichiers->joueur[i+1];
            fichiers->plateau[i] = fichiers->plateau[i+1];

            strcat(fichiers->joueur, ".txt");
            strcat(fichiers->plateau, ".txt");
        }
    }

}

//sauvegarde les noms des fichiers sur lesquels on travaille dans un fichier dédié
int sauvegarde_nom(t_fichier* fichiers)
{
    FILE* pf = fopen("./fichier_saves/noms_save", "a");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }
    fprintf(pf, "%s %s\n",fichiers->joueur, fichiers->plateau);

    fclose(pf);
    pf = NULL;
    return 0;
}

//initialise les données d'une partie a partir d'une sauvegarde donner en parametre
int init_sauvegarde(t_joueur tabjoueurs[] ,t_mono plateau[32], t_fichier* fichiers)
{
    int i = 0;
    int j = 0;
    int nb_joueur;

    FILE* pf = fopen(fichiers->joueur, "r");
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
        fscanf(pf, "%d", &tabjoueurs[i].position[1]);
        for (j = 0 ;j<10 ;j++)
        {
            fscanf(pf, "%d", &tabjoueurs[i].possession[j]);
        }
        fscanf(pf, "%d", &tabjoueurs[i].prison);
    }
    fclose(pf);

    pf = fopen(fichiers->plateau, "r");
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
        fscanf(pf, "%d", &plateau[i].prix);
        fscanf(pf, "%d", &plateau[i].type);
    }

    fclose(pf);
    pf = NULL;
    return nb_joueur;

}

//sauvegarde les données de la partie actuelle dans deux fichiers, la fonction vas cree le fichier (s'il n'existe pas)
int sauvegarde(t_joueur tabjoueurs[] ,t_mono plateau[32], t_fichier* fichiers, int nb_joueur)
{
    int i = 0;
    int j = 0;


    FILE* pf = fopen(fichiers->joueur, "w");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }

    fprintf(pf, "%d\n",nb_joueur);
    for (i = 0; i<nb_joueur ; i++)
    {

        fprintf(pf, "%d ",tabjoueurs[i].argent);
        fprintf(pf, "%d ",tabjoueurs[i].nb_double);
        fprintf(pf, "%s ",tabjoueurs[i].nom);
        fprintf(pf, "%d ",tabjoueurs[i].position[1]);
        for (j = 0; j<20; j++)
        {
            fprintf(pf, "%d ",tabjoueurs[i].possession[j]);
        }
        fprintf(pf, "%d\n",tabjoueurs[i].prison);

    }
    fclose(pf);

    pf = fopen(fichiers->plateau, "w");
    if (pf == NULL)
    {
        printf("Erreur d'ouverture de fichier.");
        return 1;
    }

    for (i = 0; i<32; i++)
    {

        fprintf(pf, "%d ",plateau[i].hotel);
        fprintf(pf, "%d ",plateau[i].hypo);
        fprintf(pf, "%d ",plateau[i].loyer);
        fprintf(pf, "%d ",plateau[i].maison);
        fprintf(pf, "%d ",plateau[i].prix);
        fprintf(pf, "%d ",plateau[i].type);
        fprintf(pf,"\n");

    }
    fclose(pf);

    pf = NULL;

    return 0;
}
