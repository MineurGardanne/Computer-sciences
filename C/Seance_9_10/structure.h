typedef struct Compte Compte;
struct Compte{
    char nom[26];
    float montant;
    Compte *suivant;
};

typedef struct ListesComptes ListesComptes;
struct ListesComptes{
    Compte *premier;
};

void fill_compte(Fichier *fichier, ListesComptes *Tete);
void afficher(ListesComptes *tete);
void ajouter_compte(ListesComptes *tete);
