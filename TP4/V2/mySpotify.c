// gcc -W -Wall -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main
// gcc -W -Wall -Wno-unused-parameter -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main

#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>


//------def fonction externe------



void afficheElement(Element e){
    printf("%s ",e);
}

void detruireElement(Element e){
    free(e);
}


bool equalsElement(Element e1, Element e2){
    return strcmp(e1,e2)==0;
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

Music* readOneMusic(FILE* f,char*buffer[2048],int i){
    fgets(buffer,2047,f);
    Music* musique = malloc(sizeof(Music));
    // alloc name
    char* token = strtok(buffer,";");
    musique->name =malloc(sizeof(char)*(strlen(token)+1));
    strncpy(musique->name,token);

    //alloc artist
    token = strtok(NULL,";");
    musique->artist = malloc(sizeof(char)*(strlen(token)+1));
    strncpy(musique->artist,token);
    // alloc album
    token = strtok(NULL,";");
    musique->album = malloc(sizeof(char)*(strlen(token)+1));
    strncpy(musique->album,token);
    //alloc genre
    token=strtok(NULL,";");
    musique->genre=malloc(sizeof(char)*(strlen(token)+1));
    strncpy(musique->genre,token);
    //nbDisque
    token=strtok(NULL,";");
    musique->discNumber=atoi(token);
    //trackNumber
    token=strtok(NULL,";");
    musique->trackNumber=atoi(token);
    // annee
    token= strtok(NULL,";");
    musique->year=atoi(token);

    return musique;


}

Liste readMusics(FILE* f,int taille){
    char* buffer[2048];
    Liste spotify=NULL;
    for(int i=0;i<taille;i++){
        spotify=ajoutFin_i(readOneMusic(f,buffer,i),spotify);
    }
    return spotify;
}

typedef struct {
    char* name;
    char* artist;
    char* album;
    char* genre;
    int discNumber;
    int trackNumber;
    int year;
} Music ;


int main(void){
	//test a faire, je ferais le main a la maison

    char* filename = "music.csv";
    char* outputname = "out.csv";

    FILE* readFile = fopen(filename,'r');
    FILE* outFile = fopen(outputname,'w');

    
    int taille = numberOfWinners(readFile);
    rewind(readFile);

    Liste spotify = readMusics(readFile,taille);



    return 0;
}