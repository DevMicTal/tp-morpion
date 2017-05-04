#ifndef MORPION_H_INCLUDED
#define MORPION_H_INCLUDED
#define TAILLE 3
#define TAILLE_NOM 100

void initGrilleJeux(char [TAILLE][TAILLE]);
void nomDesJoueurs(char [TAILLE_NOM], char [TAILLE_NOM]);
bool verificationCaseJouer(int, int, char [TAILLE][TAILLE]);
void selectCaseJoueur(char, char [TAILLE][TAILLE]);
void afficheGrilleJeux(char [TAILLE][TAILLE]);
bool aGagne(char, char [TAILLE][TAILLE]);

#endif // MORPION_H_INCLUDED
