#ifndef ELTCOUPLEPRIM_H_INCLUDED
#define ELTCOUPLEPRIM_H_INCLUDED
#include"ELTCOUPLESDD.h"
ELEMENT1 elementCreer1(void) ;
void elementLire1(ELEMENT1*);
void elementDetruire1 (ELEMENT1);
void elementAfficher1(ELEMENT1);
void elementAffecter1(ELEMENT1*, ELEMENT1);
void elementCopier1(ELEMENT1 *, ELEMENT1) ;
int elementComparer1(ELEMENT1, ELEMENT1);



#endif // ELTCOUPLEPRIM_H_INCLUDED
