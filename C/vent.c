#include "vent.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void changeWind(Tete *tete){
    int proba=0;
    Windmill *actuel=tete->first;
    while(actuel!=NULL){
        proba=rand()%101;
        if ((actuel->etat == INEFFECTUAL && proba <= 20) || (actuel->etat == AVERAGE && proba <= 11) || (actuel->etat == STRONG && proba <= 4))
            actuel->etat = INEFFECTUAL;
        else if ((actuel->etat == INEFFECTUAL && proba > 20 && proba <= 73) || (actuel->etat == AVERAGE && proba > 11 && proba <= 74) || (actuel->etat == STRONG && proba > 4 && proba <= 61))
            actuel->etat = AVERAGE;
        else if ((actuel->etat==INEFFECTUAL && proba>73)||(actuel->etat==AVERAGE && proba>74)||(actuel->etat==STRONG && proba>61))
            actuel->etat=STRONG;
        actuel->prod=0;
        actuel=actuel->suivant;
    }
}

double dailyprod(Tete *tete){
    double ammount=0;
    Windmill *actuel=tete->first;
    while(actuel!=NULL){
        if(actuel->etat==AVERAGE)
            actuel->prod=0.4;
        else if(actuel->etat==STRONG)
            actuel->prod=0.65;
        ammount+=actuel->prod;
        actuel=actuel->suivant;
    }
    return ammount;
}

void initWindmill(Tete *tete){
    tete->first=NULL;
    for(int i=1;i<21;i++){
        Windmill *actuel=(Windmill*)malloc(sizeof(Windmill));
        actuel->id=21-i;
        actuel->etat=INEFFECTUAL;
        actuel->prod=0.0;
        actuel->suivant=tete->first;
        tete->first=actuel;
    }
}

void display(Tete *tete){
    Windmill *actuel=tete->first;
    while(actuel!=NULL){
    printf("Windmill number %d speed %d prod %.2f MW\n",actuel->id,actuel->etat,actuel->prod);
    actuel=actuel->suivant;
    }
}

void delete(Tete *tete){
    Windmill *actuel=tete->first;
    while(actuel!=NULL){
        tete->first=actuel->suivant;
        free(actuel);
        actuel = tete->first;
    }
    free(tete);
}