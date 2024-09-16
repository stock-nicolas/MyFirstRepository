#include <stdio.h>

enum Mois
{
    janvier,
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
};

struct Date
{
    int Numero;
    enum Mois Mois;
    int Annee;
};

typedef struct
{
    int Numero;
    enum Mois Mois;
    int Annee;
} Date;

initialiseDate(Date *pDate)
{
    printf("entrer le jour : ");
    scanf("%d", pDate->Numero);

    printf("entrer le mois : ");
    scanf("%d", pDate->Mois);

    printf("entrer l'année : ");
    scanf("%d", pDate->Annee);
}

afficheDate()
{
}

int main(void)
{
    Date d;
    initialiseDate(&d);
    afficheDate(&d);

    return 0;
}
