#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include "ELTPHRASEPRIM.h"
ELEMENT elementCreer(){
    ELEMENT ptr;
    ptr=(ELEMENT) malloc (sizeof (PHRASE));
    strcpy(ptr->phrase,"");
    return ptr;
}
void elementLire(ELEMENT*ptr){
    printf("Donnez une phrase  \n");
    gets((*ptr)->phrase);
}
void elementDetruire (ELEMENT elt){
    free (elt);
}
void elementAfficher(ELEMENT elt){
    printf("%s \n",elt->phrase);
}
void elementAffecter(ELEMENT*elt1, ELEMENT elt2){
    *elt1=elt2;
}
void elementCopier(ELEMENT *elt1, ELEMENT elt2){
    strcpy((*elt1)->phrase,elt2->phrase);

}
int elementComparer(ELEMENT elt1, ELEMENT elt2){
    if (strcmp(elt1->phrase,elt2->phrase)==0){
        return 1;
    }
    else return 0;

}
