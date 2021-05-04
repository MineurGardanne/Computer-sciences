#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
int main()
{
    Fichier *fichier=fopen("liste_compte.txt","r");
    ListesComptes *tete=(ListesComptes*)malloc(sizeof(ListesComptes));
    tete->premier=NULL;
    fill_compte(fichier,tete);
    afficher(tete);
    return 0;
}
