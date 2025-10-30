#ifndef LSTPHRASECONVERTITPRIM_H_INCLUDED
#define LSTPHRASECONVERTITPRIM_H_INCLUDED

#include "LSTPHRASECONVERTITSDD.h"
NOEUD2 noeudCreer2(ELEMENT2 e);
void noeudDetruire2(NOEUD2 n);
LISTE2 listeCreer2(void);
void listeDetruire2(LISTE2);
int estVide2(LISTE2);
int estSaturee2(LISTE2);
int listeTaille2(LISTE2);
ELEMENT2 recuperer2(LISTE2, int);
int inserer2(LISTE2, ELEMENT2,int);
int supprimer2(LISTE2, int);
void listeAfficher2(LISTE2);
LISTE2 listeCopier2(LISTE2);
int listeComparer2(LISTE2, LISTE2);




#endif // LSTPHRASECONVERTITPRIM_H_INCLUDED
