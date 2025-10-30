#ifndef LSTPHRASECONVERTIT_H_INCLUDED
#define LSTPHRASECONVERTIT_H_INCLUDED



#include"ELTPHRASECONVERTITPRIM.h"
typedef struct structNoeud2{
    ELEMENT2 info;
    struct structNoeud2 * suivant;
}structNoeud2,*NOEUD2;

typedef struct {
    NOEUD2 tete;
    int lg;
}lastruct2,*LISTE2;





#endif // LSTPHRASECONVERTIT_H_INCLUDED
