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

void readWinners(FILE *f, PrixTuring *toutLesPrix, int taille)
{

	char buffer[2048];
	for (int i = 0; i < taille; i++)
	{
		completerUnWinner(f, toutLesPrix, buffer, i);
	}
}

int main(int argc, char **argv)
{

	//-----------variables---------------

	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

	FILE *f;
	FILE *output;
	f = fopen(filename, "r");
	output = fopen(outputFilename, "w");

	// --------fonction utilisée ------------

	// recopieFichier(f, output);

	int taille;
	taille = numberOfWinners(f);
	printf("le nombre de gagnant est : %d\n", taille);
	rewind(f);

	PrixTuring toutLesPrixTuring[taille]; // uniquement en C99

	readWinners(f, toutLesPrixTuring, taille);

	printf("la premiere année ou l'on a gagner un prix est :%d\n", toutLesPrixTuring[0].annee);
	printf("le premier gagnant est :%s\n", toutLesPrixTuring[0].prenomNom);

	//--------desalocation des variables--------
	fclose(f);
	fclose(output);

	return EXIT_SUCCESS;
}
