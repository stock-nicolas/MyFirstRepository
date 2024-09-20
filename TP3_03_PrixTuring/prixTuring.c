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
		fgets(buffer, 2047, fInput);

		if (buffer[3] != NULL)
		{
			nombreDeLigne++;
		}
	}
	return nombreDeLigne;
}

void stockeDonneeMemoire()
{
}

int main(int argc, char **argv)
{

	//-----------variables---------------
	PrixTuring toutLesPrixTuring[5];

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

	printf("le nombre de gagnant est : %d", taille);

	//--------desalocation des variables--------
	fclose(f);
	fclose(output);

	return EXIT_SUCCESS;
}
