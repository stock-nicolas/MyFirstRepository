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
	char prenomNom;
	char titre
} PrixTuring;

int main(int argc, char **argv)
{
	PrixTuring toutLesPrixTuring[5];

	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

	FILE *f;
	FILE *output;
	f = fopen(filename, "r");
	output = fopen(outputFilename, "r");
	if (f == NULL)
	{
		printf("fichier pas chargé");
	}
	else
	{
		while (feof(f) != "EOF")
		{
			char chara = fgetc(f);
			fprintf(output, chara);
		}
	}

	fclose(f);
	fclose(output);
	// TODO

	return EXIT_SUCCESS;
}
