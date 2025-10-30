#ifndef ELTPHRASEPRIM_H_INCLUDED
#define ELTPHRASEPRIM_H_INCLUDED
#include "ELTPHRASESDD.h"
ELEMENT elementCreer(void) ;
void elementLire(ELEMENT*);
void elementDetruire (ELEMENT);
void elementAfficher(ELEMENT);
void elementAffecter(ELEMENT*, ELEMENT);
void elementCopier(ELEMENT *, ELEMENT) ;
int elementComparer(ELEMENT, ELEMENT);
#endif // ELTPHRASEPRIM_H_INCLUDED
