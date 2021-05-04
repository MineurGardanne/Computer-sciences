//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif

#include <stdlib.h>
#include <stdio.h>
#include "vent.h"
#include "Releve.h"
int main()
{
    //On demande à l'utilisateur la durée de l'étude
    int duree, mois, annee;
    // printf("Entrez le nombre de mois que durera l'étude.\n");
     //scanf_s("%d", &mois);
    mois = 12;
    duree = mois * 30;
    annee = duree / 365;
    if (duree % 365 != 0)
        annee += 1;

    //On crée le fichier où on mettra les résultats statistiques qui serviront à construire les graphiques avec dislin
    FILE* fichier = fopen("windfarmstats.csv", "w+");
    fprintf(fichier, "Mois,Total,Médiane,Moyenne,Ecart-type\n");

    //On initialise les listes chainées
    Head* head = (Head*)malloc(sizeof(Head));
    Tete* tete = (Tete*)malloc(sizeof(Tete));
    initReports(head, duree);
    initWindmill(tete);
    DailyReport* dailyReport = head->primo;
    //On lance la simulation
    double *monthlyProd= (double*)malloc(sizeof(double) * (mois-1));
    double dailyProd = 0.0;
    for (int j = 0; j < mois; j++) {
        double monthlySummary[20] = { 0.0 };
        monthlyProd[j] = 0.0;
        for (int k = 1; k < 6; k++) {//k inférieur à 6 car il n'y a pas plus de 5 semaines dans un mois
            for (int i = 0; i < 7; i++) {
                dailyReport->day = i;
                dailyReport->week = k;
                dailyReport->month = j%11;
                dailyReport->year = 2020+j/11;
                fillDailyReport(dailyReport, tete);//on remplit le relevé journalier avec la production des eoliennes
                additionTableau(dailyReport->farm, monthlySummary);//on incrémente le tableau de la production mensuelle des éoliennes
                monthlyProd[j] += dailyProd;//on incrémente la production mensuelle totale
                if (k * 7 + i > 30)
                    break;
                changeWind(tete);//changement de vent de  minuit
                dailyProd = dailyprod(tete);//calcul de la production journalière des éoliennes selon le nouvel état du vent
                dailyReport = dailyReport->next;
            }
        }
        fprintf(fichier, "%d,%.2f MW,", j+1, monthlyProd[j]);
        stat(monthlySummary, 20, fichier);//On écrit dans un fichier la médiane,moyenne et ecart-type des productions journalières du mois
    }
    tri(monthlyProd,mois-1);
    fprintf(fichier,"Meilleurs mois,%2.f MW\n", monthlyProd[mois - 1]);
    fprintf(fichier,"Pire mois,%2.f MW\n", monthlyProd[0]);
    fclose(fichier);
    delete(tete);
    deleteReports(head);
    return 0;
}