#ifndef LSTPHRASE_H_INCLUDED
#define LSTPHRASE_H_INCLUDED
#include"ELTPHRASEPRIM.h"


typedef struct structNoeud{
    ELEMENT info;
    struct structNoeud * suivant;
}structNoeud,*NOEUD;

typedef struct {
    NOEUD tete;
    int lg;
}lastruct,*LISTE;




#endif // LSTPHRASE_H_INCLUDED
