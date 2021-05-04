Liste* chargerFichier(){
	FILE *fichier=fopen("villes.txt","r");
	Liste* liste=(Liste*)malloc(sizeof(Liste));
	liste->taille=0;
	while(fscanf(fichier,"%s %d",liste->listeVille[liste->taille],liste->listeHab[liste->taille])!=NULL && liste->taille<100){
		liste->taille++;
	}
	fclose(fichier);
	return liste;

}
void afficherVille(Liste *liste){
	int i=0;
	while(i<=taille){
		printf("%s: %d\n",liste->villes[i],liste->habs[i] );
		i++;
	}
}

void changeCity(Liste *liste, int newNb, char *ville){
	int i=0;
	while(i<=taille){
		if(strcmp(ville,liste->villes[i])==0){
			liste->habs[i]=newNb;
		}
		i++;
	}
}

void addCity(Liste *liste){
	if(taille<100){
		printf("Quel est le nom de la ville à ajouter ?\n");
		scanf("%s",liste->villes[liste->taille+i]);
		printf("Quel est son nombre d'habitants ?\n");
		scanf("%d",liste->habs[liste->taille+i]);
	}
}