#ifndef PILE_H
#define PILE_H

#include "stdio.h"
#include "stdlib.h"

typedef struct _cell {
	int		id; 
	struct _cell* suivant;
} cell;

typedef struct {
	cell* tete;
} Pile;

Pile	init_pile();
int		est_vide(Pile* pP);
void	empiler(Pile* pP, int* id_cell);
void	depiler(Pile* pP, int* id_cell);
void	detruire(Pile* pP);

#endif
