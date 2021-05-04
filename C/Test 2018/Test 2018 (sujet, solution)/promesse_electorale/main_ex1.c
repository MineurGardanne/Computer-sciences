

/***********************************************************************************/
/*          Examen "Algorithmique et Programmtion II" 2018                         */
/*		       Exercice 1  (Promesse électorale)                                   */
/***********************************************************************************/
/* Construction du graphe G associé à la commune X : 
/* Sommets :
/*	1) Associer un sommet à chaque habitation.
/*	2) Considérer tous les points déjà reliés par une route en bon état comme 
/*		étant un seul et même sommet du graphe.
/*	Arêtes : Chemins pondérés par les distances données. 
/*
/* 1 : Centre Bourg // le réseau routier du Centre-Bourg forme un seul sommet
/* 2 : Fays
/* 3 : Bergerie
/* 4 : Aqueduc
/* 5 : Dauberie
/* 6 : Grignon
/* 7 : Haies
/* 8 : Croisée - Iris // Croisée et Iris représente un seul sommet
/*
/* Pour déterminer le budget minimum nécessaire pour relier les habitations de la 
/* commune au centre-bourg par des routes respectant les normes du transport routier, 
/* il est suffisant de trouver l'arbre de recouvrement minimal du graphe G.
/***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

int main()
{
	const char* graphFileName = "graphe_commune_X.txt"; 

	/* Représentater un graphe par liste d'adjacence */

	Graphe G_liste;
	graphe_liste_adjacence(&G_liste, graphFileName);

	printf("Graphe G (liste d'adjacence): \n\n" );
	affichage_graphe_liste_adjacence(&G_liste);

	int start_node = 0;
	float min_cost_spanning_tree;
	int* predecessor = (int*) malloc(G_liste.nb_sommets*sizeof(int));

	min_cost_spanning_tree = algorithm_prim (&G_liste, start_node, predecessor);

	//printf("L'arbre couvrant de poids minimum est constitué des aretes suivantes : " );
	printf("\nL'ensemble de chemins a reparer est : " );
	for(int i = 0; i < G_liste.nb_sommets; i++)
		 if (i != start_node) printf("%d -> %d, ",  predecessor[i]+1, i+1);

	printf("\n\nLe budget minimum necessaire pour relier les habitations au centre-bourg est : %.2f\n", min_cost_spanning_tree);

	free(G_liste.sommets_tete);

	return 0;
}




