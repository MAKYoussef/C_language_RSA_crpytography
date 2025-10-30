#ifndef PILEPRIM_H_INCLUDED
#define PILEPRIM_H_INCLUDED
#include"PILESDD.h"
Pile PileCreer(void);
void PileDetruire(Pile);
int EstVide(Pile);
int EstSaturee(Pile);
int PileTaille(Pile);
ELEMENT1 Sommet(Pile);
int Empiler(Pile, ELEMENT1);
ELEMENT1 Depiler(Pile);
void PileAfficher(Pile);
Pile PileCopier(Pile);
int PileComparer(Pile, Pile);
#endif // PILEPRIM_H_INCLUDED
