#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED
#define LongMax 1000
#include "ELTCOUPLEPRIM.h"

typedef struct {
    ELEMENT1 elements[LongMax];
    int Sommet;
} laStruct,*Pile;
#endif // PILE_H_INCLUDED
