typedef struct Liste{
	char villes[100][26];
	int habs[100];
	int taille;
}
Liste* chargerFichier(char **listeVille,int *litseHab);
void afficherVille();