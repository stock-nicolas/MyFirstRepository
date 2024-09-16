#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    janvier = 1,
    fevrier,
    mars,
    avril,
    mais,
    juin,
    juillet,
    aout,
    septembre,
    novembre,
    decembre
} Mois;

typedef struct
{
    int Numero;
    Mois Mois;
    int Annee;
} Date;

void initialiseDate(Date *pDate)
{
    printf("entrer le jour : ");
    scanf("%d", &pDate->Numero);

    printf("entrer le mois : ");
    scanf("%d", &pDate->Mois);

    printf("entrer l'année : ");
    scanf("%d", &pDate->Annee);
}

void afficheDate(Date *pDate)
{
    printf("la date est %d / %d / %d", pDate->Numero, pDate->Mois, pDate->Annee);
}

Date creerDateParCopie(void)
{
    Date d;
    initialiseDate(&d);
    return d;
}

Date *newDate()
{
    Date *IdDate = malloc(sizeof(Date));
    initialiseDate(IdDate);
    return IdDate;
}

int main(void)
{
    Date d;
    // --------- exo 1---------

    // initialiseDate(&d);
    // afficheDate(&d);

    // -------- exo 2---------
    // d = creerDateParCopie();
    // afficheDate(&d);

    // --------- exo 3--------
    Date *date;
    date = newDate();
    afficheDate(date);

    free(date);
    date = NULL;

    return 0;
}
