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

    return 0;
}