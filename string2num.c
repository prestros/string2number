// Programm zur Konvertierung von Zeichenketten/Strings in Zahlen
// Autor: Fabian Prestros
// Datum: 28.11.2020

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char eingabe[20];
	long long zahl;
	double dezimalzahl;
	int fehlerzaehler = 0;
	int punkte = 0;
	int i = 0;
	
	// String einlesen
	printf("Bitte die umzuwandelnde Zahl eingeben: ");
	fgets(eingabe, 20, stdin);

	// Prüfen, ob wirklich Zahlen eingegeben wurden
	while (eingabe[i] != '\0')
	{
		if (eingabe[i] < '0' || eingabe[i] > '9')
			fehlerzaehler++;
		if (eingabe[i] == '.')
			punkte++;
		i++;
	}

	if (eingabe[0] == '-') // Fehlerzähler korrigieren, wenn ein Minus an 1. Stelle steht
		fehlerzaehler--;
	
	if (fehlerzaehler == 1) // Ganze Zahl umwandeln
	{
		zahl = atol(eingabe);

		printf("Eingabe = %s\n", eingabe);
		printf("Ausgabe = %lld\n", zahl);
		printf("Doppelte der eingegebenen Zahl = %lld\n", zahl * 2);
	}

	else if (fehlerzaehler == 2 && punkte == 1) // Fließkommazahl umwandeln
	{
		dezimalzahl = atof(eingabe);

		printf("Eingabe = %s\n", eingabe);
		printf("Ausgabe = %lf\n", dezimalzahl);
		printf("Doppelte der eingegebenen Zahl = %lf\n", dezimalzahl * 2);
	}

	else //Anderenfall => Fehlermeldung
	{
		printf("Es darf nur eine Zahl mit weniger als 20 Stellen sein.\n");
	}
	
}