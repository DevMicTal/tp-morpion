#include <string.h>
#include <iostream>
#include "morpion.h"

using namespace std;

bool aGagne(char lettreJoue, char morpion[TAILLE][TAILLE])
{
    int i, j, pointVerticale, pointHorizontale, pointDiagonale = 0, pointDiagonaleInverser = 0;

    for(i = 0; i < TAILLE; i++)
    {
        pointVerticale = 0;
        pointHorizontale = 0;

        for(j = 0; j < TAILLE; j++)
        {
            if(morpion[i][j] == lettreJoue)
            {
                pointVerticale++;
            }
            if(morpion[j][i] == lettreJoue)
            {
                pointHorizontale++;
            }
            if(j == i && morpion[j][i] == lettreJoue)
            {
                pointDiagonale++;
            }
            if( (i+1) + (j+1) == TAILLE + 1 && morpion[i][j] == lettreJoue )
            {
                pointDiagonaleInverser++;
            }
        }
        if(pointVerticale == TAILLE || pointHorizontale == TAILLE || pointDiagonale == TAILLE || pointDiagonaleInverser == TAILLE)
        {
            return true;
        }
    }
    return false;
}


void nomDesJoueurs (char j1[TAILLE_NOM], char j2[TAILLE_NOM])
{
 	cout << "Entrer le nom du joueur 1 :" << endl;
 	cin >> j1;
 	cout << "Entrer le nom du joueur 2 :" << endl;
 	cin >> j2;
 	cout << "Le joueur "<< j1 <<" jouera les X" << endl;
 	cout << "Le joueur "<< j2 <<" jouera les O" << endl;
}

void initGrilleJeux (char morpion[TAILLE][TAILLE])
{
 	int i,j;
 	for(i=0; i < TAILLE ;i++)
 	{
      		for( j = 0; j < TAILLE; j++)
      		{
          			morpion[i][j] = ' ';
      		}
 	}
}



void afficheGrilleJeux(char morpion[TAILLE][TAILLE])
{
     int i, j;

    for(i = 0; i < TAILLE; i++)
    {
          for(j = 0; j < TAILLE; j++)
          {
                cout << '[' << morpion[i][j] << ']';
          }
          cout << endl;
    }
}



void selectCaseJoueur (char lettreJoue, char morpion[TAILLE][TAILLE])
{
     int ligne, colonne;
     bool verifCaseJouer;

     do
     {
        cout<<"Veuillez saisir la ligne souhaite :"<<endl;
        cin>> ligne;

        cout<<"Veuillez saisir la colonne souhaite :"<<endl;
        cin>> colonne;

        ligne--; // Notre tableau commence a 0 on enlève donc 1 a chaque nombre entré
        colonne--; // pareil

        verifCaseJouer = verificationCaseJouer(ligne, colonne, morpion);

     }while(!verifCaseJouer);

    morpion[ligne][colonne] = lettreJoue;

}



//Michael dit : j’ai changé ta fonction Rom, c’est plus court et plus clair comme ça.

bool verificationCaseJouer (int ligne, int colonne, char morpion[TAILLE][TAILLE])
{
    if (ligne < 0 || ligne >= TAILLE)
    {
        cout<<"Une erreur de saisie a eu lieu : ligne: " << ligne + 1 << "  impossible à jouer:" << endl;
        return false;
    }
    if (colonne < 0 || colonne >= TAILLE)
    {
        cout<<"Une erreur de saisie a eu lieu : colonne: " << colonne + 1<< "  impossible à jouer:" << endl;
        return false;
    }
    if (morpion[ligne][colonne] != ' ')
    {
        cout << "La case est deja prise veuillez reessayer une autre case, merci " << endl;
        return false;
    }
    return true;
}

