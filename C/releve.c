#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "vent.h"
#include "Releve.h"

void initReports(Head *head, int duration)
{
	head->primo = NULL;
	for (int i = 0; i < duration; i++) {
		DailyReport* newDay = (DailyReport*)malloc(sizeof(DailyReport));
		newDay->next = head->primo;
		head->primo = newDay;
	}
}

void fillDailyReport(DailyReport* dailyReport, Tete* tete)
{
	Windmill* actuel = tete->first;
	for (int i = 0; i < 20; i++) {
		dailyReport->farm[i] = actuel->prod;
		actuel = actuel->suivant;
	}
}

void deleteReports(Head* head) {
	DailyReport* actuel = head->primo;
	while (actuel != NULL) {
		head->primo = actuel->next;
		free(actuel);
		actuel = head->primo;
	}
	free(head);
}

void tri(double tab[], int taille) {
	int i, j;
	double c;
	for (i = 0; i < taille - 1; i++)
		for (j = i + 1; j < taille; j++)
			if (tab[i] > tab[j]) {
				c = tab[i];
				tab[i] = tab[j];
				tab[j] = c;
			}
}

void additionTableau(double tab1[], double tab2[]) {
	for (int i = 0; i < 20; i++) {
		tab2[i] += tab1[i];
	}
}

void stat(double tab[],int taille,FILE *fichier) {
	double mediane, moyenne, ecart;
	moyenne = 0.0;
	for (int i=0; i < taille; i++) {
		moyenne += tab[i];
	}
	moyenne /= taille;
	ecart = 0.0;
	for (int i = 0; i < taille; i++) {
		ecart += (tab[i] - moyenne) * (tab[i] - moyenne);
	}
	ecart = sqrt(ecart / 20.0);
	tri(tab,taille);
	mediane = (tab[(taille+1)%2] + tab[(taille+1)%2 + 1] )/ 2.0;
	fprintf(fichier, "%.2f MW,%.2f MW,%.2f MW\n", mediane, moyenne, ecart);
}