#include <iostream>
#include "morpion.h"

using namespace std;

int main(int argc, char *argv[])
{
    char j1[TAILLE_NOM], j2[TAILLE_NOM];
    char morpion[TAILLE][TAILLE];
    int compteur = 0; // il faut initialiser le compteur a 0.

    nomDesJoueurs(j1,j2);

    initGrilleJeux(morpion);
    cout << endl;

    do
    {
         cout << "C'est a " << j1 << " de jouer:" << endl;
        selectCaseJoueur('X', morpion);
        afficheGrilleJeux(morpion);
        compteur++;
        cout << endl;

        if ( !aGagne('X', morpion) && compteur != TAILLE*TAILLE )
        {
cout << "C'est a " << j2 << " de jouer:" << endl;
            selectCaseJoueur('O', morpion);
            afficheGrilleJeux(morpion);
            compteur++;
            cout << endl;
        }

    }  while ( !aGagne('X', morpion) && !aGagne('O', morpion) && compteur != TAILLE*TAILLE );

    cout << "Grille finale : " << endl;
    afficheGrilleJeux(morpion);

    if ( aGagne('X', morpion) )
    {
        cout << j1 << " a gagne la partie." << endl;
    }
    else if ( aGagne('O', morpion) )
    {
        cout << j2 << " a gagne la partie." << endl;
    }
    else if (compteur == TAILLE*TAILLE)
    {
        cout << "Match nul" << endl;
    }

    return 0;
}
