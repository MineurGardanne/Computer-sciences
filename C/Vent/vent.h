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
void changeWind(Tete *tete);//Simule le changement de vent de 0h00 selon les probabilit�s
void initWindmill(Tete *tete);//Initie les pointeurs de 20 �oliennes et de la t�te
double dailyprod(Tete* tete);//Calcul le production totale journali�re et la retourne sous la forme d'un double
void display(Tete* tete);// affiche la vitesse actuelle et la production journali�re des �oliennes
void delete(Tete* tete);//Supprime les pointeurs des �oliennes et de la t�te