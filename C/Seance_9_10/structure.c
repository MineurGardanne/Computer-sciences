#include <string.h>
#include "structure.h"

void fill_compte(Fichier *fichier, ListesComptes *Tete){
    char name[26];
    float ammount;
    while(fscanf(fichier,"%s %f",name,ammount)!=NULL){
        Compte *actuel=(Compte*)malloc(sizeof(Compte));
        actuel->montant=ammount;
        strcpy(actuel->nom,name);
        actuel->suivant=Tete->premier;
        Tete->premier=actuel;
    }
}
void afficher(ListesComptes *tete){
    Compte *actuel=tete->premier;
    while(actuel!=NULL){
        printf("%s a %d euro sur son compte!;\n",actuel->nom,actuel->montant);
        actuel=actuel->suivant;
    }
}

void ajouter_compte(ListesComptes *tete){
    Compte *actuel=(Compte*)malloc(sizeof(Compte));
    printf("Entrez le nom et le solde du nouveau compte:\n");
    scanf("%s %f",actuel->nom,actuel->montant);
    actuel->suivant=tete->premier;
    tete->premier=actuel;
}

void trier_compte(ListesComptes *tete, int taille){
    Compte *compte_trier;
    Compte *actuel=tete->premier;
    float min=-1;
    int i=0;
    while(actuel->NULL){
        if(actuel->montant)
    }
}
