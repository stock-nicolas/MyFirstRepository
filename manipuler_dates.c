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

int main(void)
{

    return 0;
}
