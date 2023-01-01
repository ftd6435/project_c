#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

int main()
{
    int taille = 0;
    Ges ges[100], elem;

    taille = createEmployer(ges);

    printf("\n\nLES EMPLOYER DE L'ENTREPRISE\n");
    printEmployer(ges, taille);

    // printf("\n\nLES EMPLOYER AYANT AU MOINS 1 ENFANT \n");
    // printFatherEmployer(ges, taille);

    // printf("\n\nLES EMPLOYER QUI ONT FAIT AU MOINS 5 ANS DANS L'ENTREPRISE\n");
    // printOldEmployer(ges, taille);

    // printf("\n\nRECHERCHE D'UN EMPLOYER \n");
    // searchEmployer(ges, "mdp", taille);

    // printf("\n\nLES EMPLOYER DE L'ENTREPRISE APRES LE TRIYAGE\n");
    // sortEmployer(ges, taille);

    // printf("\n\nENTREZ LES DONNER DE L'EMPLOYER A INSERER\n");
    // scanSingleEmployer(&elem);
    // taille = insertEmployer(ges, elem, taille);

    // printf("\n\nLES EMPLOYER DE L'ENTREPRISE APRES INSERTION\n");
    // printEmployer(ges, taille);

    printf("\n\nLA LISTE DES EMPLOYER APRES SUPPRESSION\n");
    // suppression
    taille = deleteEmployer(ges, "mdp", taille);
    // affichage
    printEmployer(ges, taille);

    printf("FIN DU PROGRAMME !");
    return 0;
}