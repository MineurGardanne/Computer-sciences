/********************************************************/
/*    Examen "Algorithmique et Programmtion II" 2018    */
/*			        Exercice 2							*/
/********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

typedef struct 
{
	Pile p_in;
	Pile p_out;
} File;

File	init_file();
void	enfiler(File* pF, int* id_cell);
void	defiler(File* pF, int* id_cell);

int main()
{
	File file_test = init_file();

	printf("Creation d'une file de 10 entiers, dont le contenu est : ");
	for (int i = 0; i < 10; i++)
	{
		enfiler(&file_test, &i);
		printf("%d ", file_test.p_in.tete->id);
	}
	
	printf("\n\nDefilement de la file : ");
	for (int k = 0; k < 10; k++)
	{
		int i = 3;
		defiler(&file_test, &i);
		printf("%d ", i);
	} 
	
	printf("\n");

	return 0;
}

File init_file() 
{
	File file_vide;
	file_vide.p_in	= init_pile();
	file_vide.p_out = init_pile();
	
	return file_vide;
}

void enfiler(File* pF, int* id_cell) 
{
	empiler (&pF->p_in, id_cell);
}

void defiler(File* pF, int* id_cell) 
{	
	if(est_vide(&pF->p_in) && est_vide(&pF->p_out))
    {
        printf("\n The queue is empty!");
		id_cell = NULL;
		return;
	}
 
	
	if(est_vide(&pF->p_out))
	{
		int icell; 
		while(!est_vide(&pF->p_in))
		{
			depiler(&pF->p_in, &icell);
			empiler(&pF->p_out, &icell);
		}
	}
	 
	depiler(&pF->p_out, id_cell);
}
