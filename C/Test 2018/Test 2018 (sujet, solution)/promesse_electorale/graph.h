#ifndef GRAPH_H
#define GRAPH_H

#include "tas.h"

#define INFINITY 999    

typedef struct _sommet {
	int		 succeseurID;
	float	 weight_edge;
	struct	_sommet* suivant;
} sommet;

typedef struct {
	int	nb_sommets;
	sommet* sommets_tete;
} Graphe;

void	graphe_liste_adjacence(Graphe* G, const char* grapheFicNom);
void	affichage_graphe_liste_adjacence(Graphe* G); 
float	algorithm_prim (Graphe* G, int start_node,  int* predecessor);


#endif 
