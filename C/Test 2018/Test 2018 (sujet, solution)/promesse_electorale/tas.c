#include "tas.h"

void creerTasVide(Tas *tas)
{
  tas->taille = 0;
}

int indiceFilsGauche(int inoeud)
{
  return 2 * inoeud + 1;
}

int indiceFilsDroit(int inoeud)
{
  return 2 * inoeud + 2;
}

int indicePere(int inoeud)
{
  return (inoeud - 1) / 2;
}

int nbFils(Tas *tas, int inoeud)
{
  int nfils;
  if (indiceFilsGauche(inoeud) > tas->taille - 1)
    nfils = 0;
  else if (indiceFilsDroit(inoeud) > tas->taille - 1)
    nfils = 1;
  else
    nfils = 2;
  return nfils;
}

element filsGauche(Tas *tas, int inoeud)
{
	return tas->tab[indiceFilsGauche(inoeud)];
}

element filsDroit(Tas *tas, int inoeud)
{
  return tas->tab[indiceFilsDroit(inoeud)];
}

element pere(Tas *tas, int inoeud)
{
  return tas->tab[indicePere(inoeud)];
}

element noeud(Tas *tas, int inoeud)
{
  return tas->tab[inoeud];
}

void afficherTas(Tas *tas)
{
  int i, niv = 0, nfils;

  for (i = 0; i < tas->taille; i++)
  {
	  printf("%d", noeud(tas, i).id);

    nfils = nbFils(tas, i);
    if (nfils == 2)
		printf("(%d %d)", filsGauche(tas, i).id, filsDroit(tas, i).id);
    else if (nfils == 1)
      printf("(%d)", filsGauche(tas, i).id);

    if (i == niv * (niv + 1)) // fin du niveau
    {
      printf("\n");
      niv++;
    }
    else
      printf(" ");
  }
  printf("\n");
}

void insererTas(Tas *tas, element ent)
{

  int ival;

  tas->tab[tas->taille++] = ent;  // ajout a la fin
  ival = tas->taille - 1;
  heapify_up(tas, ival);
  
}

void heapify_up (Tas *tas, int ival) 
{
	bool bienPlace = false;

	if (tas->taille == 1) // cas de l'insertion du tout premier element
    bienPlace = true;

	while (!bienPlace)
	{
		if (pere(tas, ival).val <= tas->tab[ival].val)
			bienPlace = true;
		else
		{
			echangerAvecPere(tas, ival);
			ival = indicePere(ival);
		}
	}
}

element extractMin(Tas *tas)
{
	element min_ent = tas->tab[0]; 

	tas->tab[0] = tas->tab[tas->taille-1];
	tas->taille --;
	
	heapify_down(tas, 0);
	
	return min_ent;
}


void heapify_down(Tas *tas, int ival) 
{
	int index_smallest = ival;

	if (indiceFilsGauche(ival) < tas->taille && filsGauche(tas, ival).val < tas->tab[ival].val )
			index_smallest = indiceFilsGauche(ival);

	if (indiceFilsDroit(ival) < tas->taille && filsDroit(tas, ival).val < tas->tab[index_smallest].val )
			index_smallest = indiceFilsDroit(ival);

	if (index_smallest != ival) 
	{
		echangerAvecPere(tas, index_smallest);
		heapify_down(tas, index_smallest);
	}	
}

void updatePriorityTas(Tas *tas, element ent)
{
	int ival = getIndex(tas, ent);
	tas->tab[ival].val = ent.val;

	heapify_down(tas, ival); 
	heapify_up(tas, ival);
}

void echangerAvecPere(Tas *tas, int inoeud)
{
	element valNoeud = noeud(tas, inoeud);

	tas->tab[inoeud] = pere(tas, inoeud);
	tas->tab[indicePere(inoeud)] = valNoeud;
}

int getIndex(Tas *tas, element ent)
{
	bool find_element = false;
	int i = 0;
	while (find_element == false && i < tas->taille)
	{
		if (tas->tab[i].id == ent.id) 
			find_element = true;
		else 
			i++;
	}
	return i;
}

void creerTas(Tas *tas, element *tab, int taille)
{
	creerTasVide(tas);
	for (int i = 0; i < taille; i++)
		insererTas(tas, tab[i]);
}



