typedef enum {
	JAN, FEB, MAR, AVR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
}Month;
typedef enum {
	MON, TUE, WED, THU, FRI, SAT, SUN
}Day;
typedef struct DailyReport {
	Day day;
	Month month;
	int week;
	int year;
	double farm[20];
	struct DailyReport* next;
}DailyReport;
typedef struct Head{
	DailyReport* primo;
}Head;
void initReports(Head *head, int duration);//Creer un pointeur dailyReport vide pour chaque jour de l'étude
void fillDailyReport(DailyReport* dailyReport, Tete* tete);//Remplis la production journalière d'un dailyReport
void deleteReports(Head *head);//Supprime les pointeurs Head et DailyReport
void tri(double tab[], int taille);//Tri un tableau de flottant par ordre croissant
void additionTableau(double tab1[], double tab2[]);//Additionne deux tableaux, la somme est stocké dans tab2
void stat(double tab[], int taille, FILE* fichier);//Calcule le 1er quartile, la médiane, le 3ème quartile,
//la moyenne et l'écart-type d'un tableau de double trié et les enregistrent dans un fichier