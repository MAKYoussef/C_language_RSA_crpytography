#include "LSTPHRASEPRIM.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
NOEUD noeudCreer(ELEMENT e){
    NOEUD n;
    n =(NOEUD)malloc(sizeof(structNoeud));
    if(!n)  printf ("\nPlus d'espace");
    else{
       elementAffecter(&n->info, e);
       n->suivant = NULL;
    }
    return n;
}
void noeudDetruire(NOEUD n){
    elementDetruire(n->info);
    free(n);
}
int estVide(LISTE L) {
    return (L->lg == 0);
}

int estSaturee(LISTE L) {
    NOEUD temp;
    int saturee = 1;
    temp = (NOEUD) malloc(sizeof(structNoeud));
    if (temp != NULL) {
        saturee = 0;
        free(temp);
    }
    return saturee;
}

int listeTaille(LISTE L) {
    return (L->lg);
}

int inserer(LISTE L, ELEMENT e, int pos) {
    int succee = 1;
    int i;
    NOEUD n, p, q;
    if (estSaturee(L)) {
        printf("\nListe saturée");
        succee = 0;
    } else {
        if ((pos < 1) || (pos > L->lg + 1)) {
            printf("\nPosition invalide");
            succee = 0;
        } else {
            n = noeudCreer(e);
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

int supprimer(LISTE L, int pos) {
    int i;
    int succee = 1;
    NOEUD p, q;
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

ELEMENT recuperer(LISTE L, int pos) {
    ELEMENT elt = elementCreer();
    int i;
    NOEUD p;
    if (estVide(L))
        printf("\nListe vide");
    else {
        if ((pos < 1) || (pos > L->lg))
            printf("\nPosition invalide");
        else {
            p = L->tete;
            for (i = 1; i < pos; i++)
                p = p->suivant;
            elementAffecter(&elt, p->info);
        }
    }
    return (elt);
}

LISTE listeCreer(void) {
    LISTE L;
    L = (LISTE) malloc(sizeof(lastruct));
    if (!L)
        printf("\nProblème de mémoire");
    else {
        L->lg = 0;
        L->tete = NULL;
    }
    return (L);
}

void listeDetruire(LISTE L) {
    int i;
    NOEUD p, q;
    q = L->tete;
    for (i = 1; i <= L->lg; i++) {
        p = q;
        q = q->suivant;
        noeudDetruire(p);
    }
    free(L);
}

void listeAfficher(LISTE L) {
    int i = 1;
    NOEUD p;
    p = L->tete;
    for (i = 1; i <= L->lg; i++) {
        elementAfficher(p->info);
        p = p->suivant;
    }
}

LISTE listeCopier(LISTE L) {
    LISTE LR = listeCreer();
    int i;
    ELEMENT elt;
    for (i = 1; i <= L->lg; i++) {
        elt = elementCreer();
        elementCopier(&elt, recuperer(L, i));
        inserer(LR, elt, i);
    }
    return LR;
}

int listeComparer(LISTE L1, LISTE L2) {
    int test = 1;
    int i = 1;
    if (listeTaille(L1) != listeTaille(L2))
        test = 0;
    while ((i <= listeTaille(L1)) && (test)) {
        if (elementComparer(recuperer(L1, i), recuperer(L2, i)) != 0)
            test = 0;
        i++;
    }
    return test;
}




