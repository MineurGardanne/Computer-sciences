typedef enum {
    INEFFECTUAL,AVERAGE,STRONG
}Speed;
typedef struct Windmill{
    int id;
    Speed etat;
    double prod;
    struct Windmill *suivant;
} Windmill;
typedef struct Tete{
    Windmill *first;
}Tete;
void changeWind(Tete *tete);//Simule le changement de vent de 0h00 selon les probabilités
void initWindmill(Tete *tete);//Initie les pointeurs de 20 éoliennes et de la tête
double dailyprod(Tete* tete);//Calcul le production totale journalière et la retourne sous la forme d'un double
void display(Tete* tete);// affiche la vitesse actuelle et la production journalière des éoliennes
void delete(Tete* tete);//Supprime les pointeurs des éoliennes et de la tête