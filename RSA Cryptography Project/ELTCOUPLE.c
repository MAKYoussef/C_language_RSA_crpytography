#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include "ELTCOUPLEPRIM.h"

ELEMENT1 elementCreer1(){
    ELEMENT1 ptr;
    ptr=(ELEMENT1) malloc (sizeof (COUPLE));
    ptr->a=0;
    ptr->b=0;
    return ptr;

}

void elementLire1(ELEMENT1*ptr){
    printf("Donnez le premier entier:  \n");
    scanf("%i",&(*ptr)->a);
    printf("Donnez le deuxieme entier:  \n");
    scanf("%i",&(*ptr)->b);

}
void elementDetruire1 (ELEMENT1 elt){
    free (elt);
}
void elementAfficher1(ELEMENT1 elt){
    printf("(%i,%i)\n",elt->a,elt->b);
}
void elementAffecter1(ELEMENT1*elt1, ELEMENT1 elt2){
    *elt1=elt2;
}
void elementCopier1(ELEMENT1 *elt1, ELEMENT1 elt2){
   (*elt1)->a=elt2->a;
   (*elt1)->b=elt2->b;

}
int elementComparer1(ELEMENT1 elt1, ELEMENT1 elt2){

    int test1=0,test2=0;
    if (elt1->a==elt2->a) test1=1;
    if (elt1->b==elt2->b) test2=1;
    return (test1==test2 && test1==1);
}
