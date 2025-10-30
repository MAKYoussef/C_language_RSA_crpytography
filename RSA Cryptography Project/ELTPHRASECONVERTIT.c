#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include "ELTPHRASECONVERTITPRIM.h"


ELEMENT2 elementCreer2(){
    ELEMENT2 ptr;
    ptr=(ELEMENT2) malloc (sizeof (PHRASE_CONVETIT));
    for (int i=0;i<taillemax;i++) ptr->phrase_convertit[i]=0;
    ptr->taille=0;
    return ptr;
}
void elementDetruire2 (ELEMENT2 elt){
    free (elt);
}
void elementAfficher2(ELEMENT2 elt){
    for (int i=0;i<elt->taille;i++ ) printf("%i |",elt->phrase_convertit[i]);
    printf("\n");
}
void elementAffecter2(ELEMENT2*elt1, ELEMENT2 elt2){
    *elt1=elt2;
}
void elementCopier2(ELEMENT2 *elt1, ELEMENT2 elt2){
    for (int i=0;i<elt2->taille;i++) (*elt1)->phrase_convertit[i]=elt2->phrase_convertit[i];
    (*elt1)->taille=elt2->taille;
}
int elementComparer2(ELEMENT2 elt1, ELEMENT2 elt2){
    int i=0,test=1;
    if (elt1->taille!=elt2->taille) test=0;
    while (i<elt1->taille && test) if (elt1->phrase_convertit[i]!=elt2->phrase_convertit[i]) test=0;
    return test;
}
