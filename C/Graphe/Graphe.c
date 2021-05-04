#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <Graphe.h>

int fill_G(Head** graphe, int edges, FILE* fichier){
	int succed=edges;
	int origin; //extrémité initiale
	int tip;//extrémité terminale
	float weight;//poids du chemin
	while(fscanf(fichier,"%d %d %f",&origin,&tip,&weight)==3){
		//thread_peak(graphe[origin],graphe[tip],origin,tip,weight);
		//Affectation de l'arrête au sommet origin
		Sommet*newO=(Sommet*)malloc(sizeof(Sommet));
		newO->origin=origin;
		newO->tip=tip;
		newO->weight=weight;
		if(graphe[origin]->first==NULL){
			graphe[origin]->first=newO;
			newO->next=NULL;
		}
		else{
			newO->next=graphe[origin]->first;
			graphe[origin]->first=newO;
		}
		//Affectation de l'arrête au sommet tip si car considéré qu'il n'y a pas d'arc
		Sommet*newT=(Sommet*)malloc(sizeof(Sommet));
		newT->origin=tip;
		newT->tip=origin;
		newT->weight=weight;
		if(graphe[tip]->first==NULL){
			graphe[tip]->first=newT;
			newT->next=NULL;
		}
		else{
			newT->next=graphe[tip]->first;
			graphe[tip]->first=newT;
		}
		succed--;
	}
	if(succed==0)
		return 1;
	else
		return 0;
}

void display_G(Head** graphe, int order){
	for(int i=0;i<order;i++){
		Sommet* V=graphe[i]->first;
		printf("Sommets voisins à %d:",i);
		while(V!=NULL){
			if(V->next==NULL)
				printf(" %d.\n",V->tip);
			else
				printf(" %d,",V->tip);
			V=V->next;
		}}}

void freeMemory(Head** graphe, int order){
	Sommet* new;
	for(int i=0;i<order;i++){
		while(new!=NULL){
			new=graphe[i]->first;
			graphe[i]->first=new->next;
			free(new);	
		}
	}
	free(graphe);
}

int graphe_test(char *file){
	//int arc; //indique la présence d'arc
	//char* file //chemin du fichier txt contenant le graphe
	//printf("Le graphe a des arcs ?\nOui:Tapez 0\nNon:Tapez:1\n");
	//scanf("&d",&arc);
	//printf("Quel est le nom du fichier txt qui contient le graphe ?\n");
	//scanf("&s",file);

	int order,edges;
	FILE* fichier=fopen(file,"r");
	if(fichier==NULL)
		return -1;
	fscanf(fichier,"%d %d",&order,&edges);
	Head** graphe=(Head**)malloc(sizeof(Head)*(order+1);
	//init_G(graphe,order);
	for(int i=0;i<order;i++){
		graphe[i]->first=NULL;
		printf("%d\n")
	}
	//fill_G(graphe,edges,fichier);
	//fclose(fichier);
	//display_G(graphe,order);
	freeMemory(graphe,order);
}