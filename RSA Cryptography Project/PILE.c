#include "PILEPRIM.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
Pile PileCreer(void) {
    Pile P;
    P = (Pile) malloc(sizeof(laStruct));
    if (!P) {
        printf(" \nProblème de mémoire");
    } else {
        P->Sommet = 0;
    }
    return (P);
}

void PileDetruire(Pile P) {
    int i;
    for (i = 1; i <= P->Sommet; i++)
        elementDetruire1(P->elements[i]);
    free(P);
}

void PileAfficher(Pile P) {
    int i;
    for (i = P->Sommet; i >= 1; i--)
        elementAfficher1(P->elements[i]);
}

int EstVide(Pile P) {
    return (P->Sommet == 0);
}

int EstSaturee(Pile P) {
    return (P->Sommet == LongMax);
}

int PileTaille(Pile P) {
    return (P->Sommet);
}

int Empiler(Pile P, ELEMENT1 e) {
    int succes = 1;
    if (EstSaturee(P)) {
        printf("\n Pile saturée");
        succes = 0;
    } else {
        (P->Sommet)++;
        elementAffecter1(&P->elements[P->Sommet], e);
    }
    return (succes);
}

ELEMENT1 Depiler(Pile P) {
    ELEMENT1 elt = elementCreer1();
    if (EstVide(P)) {
        printf("\n Pile vide");
    } else {
        elementCopier1(&elt, (P->elements)[P->Sommet]);
        elementDetruire1(P->elements[P->Sommet]);
        (P->Sommet)--;
    }
    return (elt);
}

ELEMENT1 Sommet(Pile P) {
    ELEMENT1 elt = elementCreer1();
    if (EstVide(P))
        printf(" \n Pile vide");
    else
        elt = (P->elements[P->Sommet]);
    return (elt);
}

Pile PileCopier(Pile P) {
    Pile PR = PileCreer();
    int i;
    ELEMENT1 elt;
    for (i = 1; i <= P->Sommet; i++) {
        elt = elementCreer1();
        elementCopier1(&elt, P->elements[i]);
        Empiler(PR, elt);
    }
    return PR;
}

int PileComparer(Pile P1, Pile P2) {
    int test = 1;
    int i = P1->Sommet;
    if (PileTaille(P1) != PileTaille(P2))
        test = 0;
    while ((i >= 1) && (test)) {
        if (elementComparer1(P1->elements[i], P2->elements[i]) != 0)
            test = 0;
        i--;
    }
    return test;
}
