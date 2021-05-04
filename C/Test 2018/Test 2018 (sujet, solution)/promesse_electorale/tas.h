#ifndef TAS_H
#define TAS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAILLE_MAX  100

typedef struct 
{
  int	id;
  float val;
} element;

typedef struct
{
  element tab[TAILLE_MAX];
  int taille;
} Tas;

void creerTasVide(Tas *tas);
int indiceFilsGauche(int inoeud);
int indiceFilsDroit(int inoeud);
int indicePere(int inoeud);
int nbFils(Tas *tas, int inoeud);

element filsGauche(Tas *tas, int inoeud);
element filsDroit(Tas *tas, int inoeud);
element pere(Tas *tas, int inoeud);
element noeud(Tas *tas, int inoeud);
element extractMin(Tas *tas);

void heapify_down(Tas *tas, int ival); 
void heapify_up(Tas *tas, int ival); 
void afficherTas(Tas *tas);
void echangerAvecFilsDroit(Tas *tas, int inoeud);
void echangerAvecFilsGauche(Tas *tas, int inoeud);
int  getIndex(Tas *tas, element ent);
void insererTas(Tas *tas, element ent);
void updatePriorityTas(Tas *tas, element ent); 
void echangerAvecPere(Tas *tas, int inoeud);
void creerTas(Tas *tas, element *tab, int taille);

#endif 
