/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef struct
{
	int annee;
	char *prenomNom; // \0 at the end
	char *titre;	 // \0 at the end
} PrixTuring;

void recopieFichier(FILE *fInput, FILE *fOutput)
{
	if (fInput == NULL || fOutput == NULL)
	{
		printf("fichier pas chargé");
	}
	else
	{
		while (feof(fInput) == 0)
		{
			char chara = fgetc(fInput);
			putc(chara, fOutput);
		}
	}
}

int numberOfWinners(FILE *fInput)
{
	int nombreDeLigne = 0;
	char buffer[2048];

	while (feof(fInput) == 0)
	{
		char *ligne;
		ligne = fgets(buffer, 2047, fInput);

		if (ligne != NULL)
		{
			nombreDeLigne++;
		}
	}
	return nombreDeLigne;
}

void completerUnWinner(FILE *f, PrixTuring *toutLesPrix, char buffer[2048], int i)
{
	int indiceBuffer = 0;
	int tailleInfo = 0;

	fgets(buffer, 2047, f);

	char *p = buffer;
	// comupte year
	while (buffer[indiceBuffer] != ';')
	{
		indiceBuffer++;
		tailleInfo++;
	}
	char *destination = malloc(sizeof(char) * (tailleInfo));
	strncpy(destination, p, tailleInfo);
	toutLesPrix[i].annee = atoi(destination);
	free(destination);
	p = p + tailleInfo + 1;
	tailleInfo = 0;
	indiceBuffer++;
	// compute names
	while (buffer[indiceBuffer] != ';')
	{
		indiceBuffer++;
		tailleInfo++;
	}
	char *destNom = calloc(tailleInfo + 1, sizeof(char));
	buffer[indiceBuffer] = '\0';
	strncpy(destNom, p, tailleInfo);
	toutLesPrix[i].prenomNom = destNom;
	p = p + tailleInfo + 1;
	tailleInfo = 0;
	indiceBuffer++;
	// compute topic

	while (buffer[indiceBuffer] != '\n')
	{
		indiceBuffer++;
		tailleInfo++;
	}
	char *destTopic = calloc(tailleInfo + 1, sizeof(char));
	buffer[indiceBuffer] = '\0';
	strncpy(destTopic, p, tailleInfo);
	toutLesPrix[i].titre = destTopic;
}

void concatenneInfoWinner(char buffer[2048], PrixTuring *toutLesPrix, FILE *out, int i)
{
	sprintf(buffer, "%d;%s;%s\n", toutLesPrix[i].annee, toutLesPrix[i].prenomNom, toutLesPrix[i].titre);
	fputs(buffer, out);
}

void readWinners(FILE *f, PrixTuring *toutLesPrix, int taille)
{

	char buffer[2048];
	for (int i = 0; i < taille; i++)
	{
		completerUnWinner(f, toutLesPrix, buffer, i);
	}
}

void printWinners(PrixTuring *toutLesPrix, FILE *output, int taille)
{
	char buffer[2048];
	for (int i = 0; i < taille; i++)
	{
		concatenneInfoWinner(buffer, toutLesPrix, output, i);
	}
}

void freeMemory(PrixTuring *toutLesPrix, int tailleToutLesPrix)
{
	for (int i = 0; i < tailleToutLesPrix; i++)
	{
		free(toutLesPrix[i].prenomNom);
		free(toutLesPrix[i].titre);
	}
}

void infoAnnee(int annee, PrixTuring *tab, int taille)
{
	for (int i = 0; i < taille; i++)
	{
		if ((tab[i]).annee = annee)
		{
			printf("l'annee %d, le(s) gagnants(s) ont été : %s\nNature des travaux : %s\n", annee, tab[i].prenomNom, tab[i].titre);
		}
	}
}

int main(int argc, char **argv)
{

	//-----------variables---------------

	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
	int veutOnLesInfosDunGagant = 0;
	int anneeVoulu;

	FILE *f;
	FILE *output;
	//----------gestion des paramètres d'appel-----------

	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-o") == 0)
		{
			if (i + 1 < argc)
			{
				output = fopen(argv[i + 1], "w");
				i++;
			}
		}
		if (strcmp(argv[i], "--info"))
		{
			if (i + 1 < argc)
			{
				anneeVoulu = atoi(argv[i + 1]);
				printf("annee voulue en string : %s\n", argv[i + 1]);
				printf("annee voulue en decimal : %d\n", anneeVoulu);
				veutOnLesInfosDunGagant = 1;
				i++;
			}
		}
		else
		{
			output = fopen(outputFilename, "w");
		}
	}

	f = fopen(filename, "r");

	// --------fonction utilisée ------------

	// recopieFichier(f, output);

	int taille;
	taille = numberOfWinners(f);
	printf("le nombre de gagnant est : %d\n", taille);
	rewind(f);

	PrixTuring toutLesPrixTuring[taille]; // uniquement en C99

	readWinners(f, toutLesPrixTuring, taille);

	printf("la premiere année ou l'on a gagner un prix est :%d\n", toutLesPrixTuring[56].annee);
	printf("le premier gagnant est :%s\n", toutLesPrixTuring[56].prenomNom);

	if (veutOnLesInfosDunGagant == 1)
	{
		infoAnnee(anneeVoulu, toutLesPrixTuring, taille);
	}

	printWinners(toutLesPrixTuring, output, taille);

	//--------desalocation des variables--------
	freeMemory(toutLesPrixTuring, taille);
	fclose(f);
	fclose(output);

	return EXIT_SUCCESS;
}
