#include "pile.h"

Pile init_pile() 
{
	Pile pileVide;
	pileVide.tete = NULL; 
	return pileVide;
}

int est_vide(Pile* pP) 
{
	return (pP->tete == NULL);
}

void empiler(Pile* pP, int* id_cell) 
{
	cell* pelem = (cell*) malloc(sizeof(cell)); 

	pelem->id = *id_cell;
	pelem->suivant = NULL; 
	 
	if (pP->tete == NULL) 
		pP->tete = pelem; 
	else 
	{
		pelem->suivant = pP->tete;
		pP->tete = pelem; 
	}
}

void depiler(Pile* pP, int* id_cell) 
{	
	if (pP->tete != NULL) 
	{
		cell* pelem	= pP->tete; 
		*id_cell	= pelem->id; 
		pP->tete	= pelem->suivant;
		free(pelem);
	}
	else 
	{
		printf("\n The stack is empty!");
		id_cell = NULL;
	}
}

void detruire (Pile* pP)
{
	cell* pelem = pP->tete;

	while (pP->tete != NULL) 
	{
		pelem		= pP->tete;
		pP->tete	= pelem->suivant;
		free(pelem);
	}
}