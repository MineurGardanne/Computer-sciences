void initVecteur(Vecteur *vect, int taille){
	vect->taille=taille;
	vect->first=NULL;
}
void setVecteur1(Vecteur *vect, int i, int val){
	
	int repere=0;

	Component *actuel=tete->first;
	while(actuel!=NULL){
		if(actuel->indice==i){
			actuel->valeur=val;
			repere++;
		}
	}
	if(repere==1){
		Component *nouveau=(Component*)malloc(sizeof(Component));
		nouveau->indice=i;
		nouveau->valeur=i;
		nouveau->suivant=vect->first;
		vect->first=nouveau;
	}

}
int getValeur(Vecteur *vect, int i){
	if(i<vect->taille){
		Component *actuel=vect->first;
		while(actuel!=NULL){
			if(actuel->indice==i){
				return actuel->valeur;
			}
			actuel=actuel->suivant;
		}
	}
	return 0;
}
void afficherVecteur(Vecteur *vect){
	Component *actuel=vect->first;
	while(actuel!=NULL){
		pritnf("Composante %d: %\n",actuel->indice,actuel->valeur);
		actuel=actuel->suivant;
	}
}
void resetVecteur(Vecteur *vect){
	Component *actuel=vect->first;
	while(actuel!=NULL){
		vect->first=actuel->suivant;
		free(actuel);
		actuel=vect->first;
	}
	vect->first=NULL;
}
void setVecteur2(Vecteur *vect, int i, int val){
	if(i<taille && i>=0){
		Component *nouveau=(Component*)malloc(sizeof(Component));
		if(vect->first==NULL){
			nouveau->indice=i;
			nouveau->valleur=valeur;
			nouveau->suivant=NULL;
			vect->first=nouveau;
		}
		else if(vect->first->indice>i){
			nouveau->indice=i;
			nouveau->valeur=val;
			nouveau->suivant=vect->first;
			vect->first=nouveau;
		}
		else{
			Component *actuel=vect->first;
			while(actuel!=NULL){
				if(actuel->suivant->indice>i || actuel->suivant==NULL){
					nouveau->indice=i;
					nouveau->valeur=val;
					nouveau->suivant=actuel->suivant;
					actuel->suivant=nouveau;
					break;
				}
				else if(actuel->indice==i){
					free(nouveau);
					actuel->valeur=val;
					break;
				}
				else
					actuel=actuel->suivant;
			}
		}
	}
}