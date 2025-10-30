#include "LSTPHRASECONVERTITPRIM.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>


NOEUD2 noeudCreer2(ELEMENT2 e){
    NOEUD2 n;
    n =(NOEUD2)malloc(sizeof(structNoeud2));
    if(!n)  printf ("\nPlus d'espace");
    else{
       elementAffecter2(&n->info, e);
       n->suivant = NULL;
    }
    return n;
}
void noeudDetruire2(NOEUD2 n){
    elementDetruire2(n->info);
    free(n);
}
int estVide2(LISTE2 L) {
    return (L->lg == 0);
}

int estSaturee2(LISTE2 L) {
    NOEUD2 temp;
    int saturee = 1;
    temp = (NOEUD2) malloc(sizeof(structNoeud2));
    if (temp != NULL) {
        saturee = 0;
        free(temp);
    }
    return saturee;
}

int listeTaille2(LISTE2 L) {
    return (L->lg);
}

int inserer2(LISTE2 L, ELEMENT2 e, int pos) {
    int succee = 1;
    int i;
    NOEUD2 n, p, q;
    if (estSaturee2(L)) {
        printf("\nListe saturée");
        succee = 0;
    } else {
        if ((pos < 1) || (pos > L->lg + 1)) {
            printf("\nPosition invalide");
            succee = 0;
        } else {
            n = noeudCreer2(e);
            if (pos == 1) {
                n->suivant = L->tete;
                L->tete = n;
            } else {
                q = L->tete;
                for (i = 1; i < pos; i++) {
                    p = q;
                    q = q->suivant;
                }
                p->suivant = n;
                n->suivant = q;
            }
            (L->lg)++;
        }
    }
    return succee;
}

int supprimer2(LISTE2 L, int pos) {
    int i;
    int succee = 1;
    NOEUD2 p, q;
    if (estVide(L)) {
        printf("\nListe vide");
        succee = 0;
    } else {
        if ((pos < 1) || (pos > L->lg)) {
            printf("\nPosition invalide");
            succee = 0;
        } else {
            q = L->tete;
            if (pos == 1)
                L->tete = L->tete->suivant;
            else {
                for (i = 1; i < pos; i++) {
                    p = q;
                    q = q->suivant;
                }
                p->suivant = q->suivant;
            }
            noeudDetruire(q);
            (L->lg)--;
        }
    }
    return succee;
}

ELEMENT2 recuperer2(LISTE2 L, int pos) {
    ELEMENT2 elt = elementCreer2();
    int i;
    NOEUD2 p;
    if (estVide2(L))
        printf("\nListe vide");
    else {
        if ((pos < 1) || (pos > L->lg))
            printf("\nPosition invalide");
        else {
            p = L->tete;
            for (i = 1; i < pos; i++)
                p = p->suivant;
            elementAffecter2(&elt, p->info);
        }
    }
    return (elt);
}

LISTE2 listeCreer2(void) {
    LISTE2 L;
    L = (LISTE2) malloc(sizeof(lastruct2));
    if (!L)
        printf("\nProblème de mémoire");
    else {
        L->lg = 0;
        L->tete = NULL;
    }
    return (L);
}

void listeDetruire2(LISTE2 L) {
    int i;
    NOEUD2 p, q;
    q = L->tete;
    for (i = 1; i <= L->lg; i++) {
        p = q;
        q = q->suivant;
        noeudDetruire2(p);
    }
    free(L);
}

void listeAfficher2(LISTE2 L) {
    int i = 1;
    NOEUD2 p;
    p = L->tete;
    for (i = 1; i <= L->lg; i++) {
        elementAfficher2(p->info);
        printf("\n");
        p = p->suivant;
    }
}

LISTE2 listeCopier2(LISTE2 L) {
    LISTE2 LR = listeCreer2();
    int i;
    ELEMENT2 elt;
    for (i = 1; i <= L->lg; i++) {
        elt = elementCreer2();
        elementCopier2(&elt, recuperer2(L, i));
        inserer2(LR, elt, i);
    }
    return LR;
}

int listeComparer2(LISTE2 L1, LISTE2 L2) {
    int test = 1;
    int i = 1;
    if (listeTaille2(L1) != listeTaille2(L2))
        test = 0;
    while ((i <= listeTaille2(L1)) && (test)) {
        if (elementComparer2(recuperer2(L1, i), recuperer2(L2, i)) != 0)
            test = 0;
        i++;
    }
    return test;
}


