#include <stdio.h>
#include <stdlib.h>

int *repeat(int *t1, int *t2, int tailleInit, int tailleFinale)
{

    int *resultat = malloc(sizeof(int) * tailleFinale);

    int incrementResultat = 0;

    for (int k = 0; k < tailleInit; k++)
    {
        int compteur = t1[k];
        for (int i = 0; i < compteur; i++)
        {
            resultat[incrementResultat] = t2[k];
            incrementResultat++;
        }
    }
    return (resultat);
}

void matrix_print(int *t, int tailleFinale)
{
    for (int j = 0; j < tailleFinale; j++)
    {
        printf("%ld ", t[j]);
    }
}

int main(void)
{
    int t1[3] = {1, 2, 4};
    int t2[3] = {10, 3, 8};
    int taille = 3;
    int tailleTabFinal = 0;
    for (int i = 0; i < taille; i++)
    {
        tailleTabFinal += t2[i];
    }
    int *tResultat;
    int *p1;
    p1 = repeat(t1, t2, taille, tailleTabFinal);

    matrix_print(p1, tailleTabFinal);
    free(p1);
    return 0;
}