typedef struct Sommet{
	int origin;
	int tip;
	float weight;
	struct Sommet* next;
} Sommet;

typedef struct Head{
	Sommet* first;
} Head;

int fill_G(Head** graphe, int edges, FILE *fichier);
void display_G(Head** graphe, int order);
void freeMemory(Head** graphe, int order);
int graphe_test(char *file);


