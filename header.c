#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CURRENT_YEAR 2023
#define PRIME 80000
#define PERCENT 0.25

#include "header.h"

// Prototype of creating function
int createEmployer(Ges *g)
{
    char stop = 'c';
    char vider;
    int i = 0;

    while (stop != '*')
    {
        printf("Matricule: ");
        readString(g[i].mat, 4);

        printf("Nom: ");
        readString(g[i].name, 20);

        printf("Annee d'engagement: ");
        scanf("%d", &g[i].yearEngage);

        printf("Salaire de base: ");
        scanf("%d", &g[i].sBase);

        printf("Nombre d'enfant: ");
        scanf("%d", &g[i].children);

        g[i].lasted = CURRENT_YEAR - g[i].yearEngage;

        if (g[i].lasted > 5)
        {
            g[i].sExact = g[i].sBase + (PRIME * g[i].children) + (g[i].sBase * PERCENT);
        }
        else
        {
            g[i].sExact = g[i].sBase + (PRIME * g[i].children);
        }

        i++;
        printf("\nTAPEZ N'IMPORTE QUELLE TOUCE POUR CONTINUER OU * POUR ARRETER : ");
        cleanBuffer();
        scanf("%c", &stop);
        scanf("%c", &vider);
    }

    return i;
}

// Prototype of printing function
void printEmployer(Ges *g, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("%d : %s %s %d %d %d %d GNF %d GNF\n", i + 1, g[i].mat, g[i].name, g[i].children, g[i].lasted, g[i].yearEngage, g[i].sBase, g[i].sExact);
    }
}

// Prototype of printing employer who have any children
void printFatherEmployer(Ges *g, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        if (g[i].children > 0)
        {
            printf("%d : %s %s %d %d %d %d GNF %d GNF\n", i + 1, g[i].mat, g[i].name, g[i].children, g[i].lasted, g[i].yearEngage, g[i].sBase, g[i].sExact);
        }
    }
}

// Prototype of printing old employer
void printOldEmployer(Ges *g, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        if (g[i].lasted > 5)
        {
            printf("%d : %s %s %d %d %d %d GNF %d GNF\n", i + 1, g[i].mat, g[i].name, g[i].children, g[i].lasted, g[i].yearEngage, g[i].sBase, g[i].sExact);
        }
    }
}

// Prototype of searching employer
void searchEmployer(Ges *g, char *mat, int taille)
{
    int search = 0;
    int c, j;

    for (int i = 0; i < taille; i++)
    {
        c = strcmp(g[i].mat, mat);

        if (c == 0)
        {
            search = 1;
            j = i;
            break;
        }
    }

    if (search)
    {
        printf("%s %s %d %d %d %d GNF %d GNF\n", g[j].mat, g[j].name, g[j].children, g[j].lasted, g[j].yearEngage, g[j].sBase, g[j].sExact);
    }
    else
    {
        printf("Le matricule ne correspond a aucun employer !");
    }
}

// Prototype of sort ascending
void sortEmployer(Ges *g, int taille)
{
    int min, j, c;

    for (int i = 0; i < taille; i++)
    {
        min = i;
        for (int j = i + 1; j < taille; j++)
        {
            c = strcmp(g[j].name, g[min].name);
            if (c < 0)
            {
                min = j;
            }
        }

        if (min != i)
        {
            exchange(&g[min], &g[i]);
        }
    }

    printEmployer(g, taille);
}

// Prototype of exchange two values
void exchange(Ges *a, Ges *b)
{
    Ges tmp;

    strcpy(tmp.mat, a->mat);
    strcpy(tmp.name, a->name);
    tmp.lasted = a->lasted;
    tmp.yearEngage = a->yearEngage;
    tmp.children = a->children;
    tmp.sBase = a->sBase;
    tmp.sExact = a->sExact;

    strcpy(a->mat, b->mat);
    strcpy(a->name, b->name);
    a->lasted = b->lasted;
    a->yearEngage = b->yearEngage;
    a->children = b->children;
    a->sBase = b->sBase;
    a->sExact = b->sExact;

    strcpy(b->mat, tmp.mat);
    strcpy(b->name, tmp.name);
    b->lasted = tmp.lasted;
    b->yearEngage = tmp.yearEngage;
    b->children = tmp.children;
    b->sBase = tmp.sBase;
    b->sExact = tmp.sExact;
}

// Prototype of scanSingleEmployer
void scanSingleEmployer(Ges *elem)
{
    printf("Matricule: ");
    readString(elem->mat, 4);

    printf("Nom: ");
    readString(elem->name, 20);

    printf("Annee d'engagement: ");
    scanf("%d", &elem->yearEngage);

    printf("Salaire de base: ");
    scanf("%d", &elem->sBase);

    printf("Nombre d'enfant: ");
    scanf("%d", &elem->children);

    elem->lasted = CURRENT_YEAR - elem->yearEngage;

    if (elem->lasted > 5)
    {
        elem->sExact = elem->sBase + (PRIME * elem->children) + (elem->sBase * PERCENT);
    }
    else
    {
        elem->sExact = elem->sBase + (PRIME * elem->children);
    }
}

// Prototype of inserting function
int insertEmployer(Ges *g, Ges elem, int taille)
{
    int i = taille;
    int pos, c;

    if (i == 0)
    {
        strcpy(g[i].mat, elem.mat);
        strcpy(g[i].name, elem.name);
        g[i].lasted = elem.lasted;
        g[i].yearEngage = elem.yearEngage;
        g[i].children = elem.children;
        g[i].sBase = elem.sBase;
        g[i].sExact = elem.sExact;
        taille++;
    }
    else
    {
        pos = 0;
        for (int j = 0; j < taille; j++)
        {
            c = strcmp(g[j].name, elem.name);
            if (c >= 0)
            {
                pos = j;
            }
        }

        taille++;
        for (int k = taille; k > pos; k--)
        {
            exchange(&g[k], &g[k - 1]);
        }

        strcpy(g[pos].mat, elem.mat);
        strcpy(g[pos].name, elem.name);
        g[pos].lasted = elem.lasted;
        g[pos].yearEngage = elem.yearEngage;
        g[pos].children = elem.children;
        g[pos].sBase = elem.sBase;
        g[pos].sExact = elem.sExact;
    }

    return taille;
}

// Prototype of deleting an employer
int deleteEmployer(Ges *g, char *mat, int taille)
{
    int c, pos, test = 0;

    for (int i = 0; i < taille; i++)
    {
        c = strcmp(g[i].mat, mat);
        if (c == 0)
        {
            pos = i--;
            test = 1;
            for (int k = taille - 1; k > pos; k--)
            {
                exchange(&g[k], &g[k - 1]);
            }
            taille--;
        }
    }

    if (test)
    {
        printf("\nSUPPRESSION EFFECTUER AVEC SUCCES \n");
    }
    else
    {
        printf("\nSUPPRESSION ECHOUER SVP VERIFIER LE MATRICULE\n");
    }

    return taille;
}

// Prototype of cleaner of buffer
int readString(char *chaine, int taille)
{
    char *pos = NULL;

    if (fgets(chaine, taille, stdin) != NULL)
    {
        pos = strchr(chaine, '\n');
        if (pos != NULL)
            *pos = '\0';
        else
            cleanBuffer();

        return 1;
    }
    else
    {
        cleanBuffer();
        return 0;
    }
}

void cleanBuffer()
{
    int c;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}