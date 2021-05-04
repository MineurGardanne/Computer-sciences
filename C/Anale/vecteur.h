typedef struct Component{
	int indice;
	int valeur;
	struct Component *suivant;
}Component;

typedef struct Vecteur{
	int taille;
	Component *first;
}Vecteur;

void initVecteur(Vecteur *vect, int taille);
void setVecteur1(Vecteur *vect, int i, int val);
int getValeur(Vecteur *vect, int i);
void afficherVecteur(Vecteur *vect);
void resetVecteur(Vecteur *vect);
void setVecteur2(Vecteur *vect, int i, int val);
void sumVecteur(Vecteur *vect1, Vecteur *vect2, Vecteur *vect3);