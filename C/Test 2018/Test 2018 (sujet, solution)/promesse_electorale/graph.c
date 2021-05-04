#include "graph.h"

void graphe_liste_adjacence(Graphe* G, const char* grapheFicNom)
{
	FILE* fp;
	fp = fopen(grapheFicNom, "r");
	
	if (fp != NULL) 
	{
		int		nb_sommets, nb_edges, u, v;
		float	w;

		fscanf(fp, "%d%d", &nb_sommets, &nb_edges);
		
		G->nb_sommets	= nb_sommets;
		G->sommets_tete	= (sommet*) malloc(nb_sommets*sizeof(sommet)); 

		for (int i = 0; i < nb_sommets; i++) 
		{
			G->sommets_tete[i].suivant		= NULL;
			G->sommets_tete[i].weight_edge	= 0;
		}		
		for (int i = 0; i < nb_edges; i++) 
		{
			fscanf(fp, "%d %d %f", &u, &v, &w);

			sommet* s		= (sommet*) malloc(sizeof(sommet));  
			s->suivant		= G->sommets_tete[u-1].suivant;
			s->succeseurID	= G->sommets_tete[u-1].succeseurID;
			s->weight_edge  = G->sommets_tete[u-1].weight_edge;

			G->sommets_tete[u-1].succeseurID	= v-1;
			G->sommets_tete[u-1].suivant		= s;
			G->sommets_tete[u-1].weight_edge	= w;

			sommet* t		= (sommet*) malloc(sizeof(sommet));  
			t->suivant		= G->sommets_tete[v-1].suivant;
			t->succeseurID	= G->sommets_tete[v-1].succeseurID;
			t->weight_edge  = G->sommets_tete[v-1].weight_edge;

			G->sommets_tete[v-1].succeseurID	= u-1;
			G->sommets_tete[v-1].suivant		= t;
			G->sommets_tete[v-1].weight_edge	= w;
		}
	}
	else printf("Le fichier n'a pas été trouvé.");
	fclose(fp);
}


void affichage_graphe_liste_adjacence(Graphe* G) 
{	
	for(int i = 0; i < G->nb_sommets; i++) 
	{
		printf("Sommet %d : ", i + 1);

		sommet* courant = &(G->sommets_tete[i]);

		while(courant->suivant != NULL)
		{
			printf("%d (%.2f), ", courant->succeseurID + 1, courant->weight_edge);
			courant = courant->suivant;
		} 
		printf("\n");
	}
}

float algorithm_prim (Graphe* G, int start_node,  int* predecessor) 
{
	element	*cost = (element*) malloc(G->nb_sommets*sizeof(element));
	bool	*inQueue = (bool*)  malloc(G->nb_sommets*sizeof(element));

	for (int i = 0; i < G->nb_sommets; i++) 
	{
		cost[i].id		= i;
		cost[i].val		= INFINITY;
		predecessor[i]	= -1;
		inQueue[i]		= true;
	}
	cost[start_node].id	= start_node;
	cost[start_node].val = 0;

	Tas priority_queue;
	creerTas(&priority_queue, cost, G->nb_sommets);

	while (priority_queue.taille != 0)
	{
		element min_elem = extractMin(&priority_queue);
		inQueue[min_elem.id]	= false;
		
		sommet* courant = &(G->sommets_tete[min_elem.id]);

		while(courant->suivant != NULL)
		{
			int u = courant->succeseurID;
			if (cost[u].val > courant->weight_edge && inQueue[u])
			{
				predecessor[u]	= min_elem.id;
				cost[u].val		= courant->weight_edge;
				
				element elem = {u, courant->weight_edge};
				updatePriorityTas(&priority_queue, elem);
			}
			courant = courant->suivant;
		} 
	}
	
	float min_cost_spanning_tree = 0;
	for (int i = 0;  i <  G->nb_sommets; i++)
		min_cost_spanning_tree += cost[i].val;

	return min_cost_spanning_tree;
}
