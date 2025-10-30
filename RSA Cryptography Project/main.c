#include "LSTPHRASE.h"
#include "PILE.h"
#include "ELTCOUPLEPRIM.h"
#include "LSTPHRASECONVERTIT.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#define MAGENTA "\x1b[35m"
#define RED     "\x1b[31m"




char conv_int_to_char(long long int x){
    return x;
}


int modulo(long long int base, long long int exponent, long long int modulus) {
    long long int result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent%2!=0)
            result = (result * base) % modulus;
        exponent = exponent/2;
        base = (base * base) % modulus;
    }
    return result;
}


long long int dechiffrement(int c,ELEMENT1 e1){
    long long int n=e1->a,d=e1->b;
    return modulo(c,d,n);
}

ELEMENT remp_phrase_dechiffrer(ELEMENT2 e,ELEMENT1 e1){
    ELEMENT e2=elementCreer();
    for (int i=0;i<e->taille;i++){
        e2->phrase[i]=conv_int_to_char(dechiffrement(e->phrase_convertit[i],e1));
    }

    return e2;
}


void dechiffrement_final(LISTE2 L_chiffrer,Pile pilePrivee,int N){
    ELEMENT phrase_dechiffrer;
    for (int i=1;i<=N;i++){
        phrase_dechiffrer=elementCreer();
        elementCopier(&phrase_dechiffrer,remp_phrase_dechiffrer(recuperer2(L_chiffrer,i),Depiler(pilePrivee)));
        elementAfficher(phrase_dechiffrer);
    }

}

long long int chiffrement(int m,ELEMENT1 e1){
    long long int n=e1->a,e=e1->b;
    return modulo(m,e,n);
}


int conv_char_to_int(char c){
    return c;
}


ELEMENT2 remp_phrase(ELEMENT e,ELEMENT1 e1){
    ELEMENT2 e2=elementCreer2();
    int t[strlen(e->phrase)];
    for (int i=0;i<strlen(e->phrase);i++){
        t[i]=conv_char_to_int(e->phrase[i]);
    }
    for (int i=0;i<strlen(e->phrase);i++){
        e2->phrase_convertit[i]=chiffrement(t[i],e1);
    }
    e2->taille=strlen(e->phrase);
    return e2;
}


void chiffrement_final(LISTE2 L_chiffrer,LISTE L, Pile pilePublique,int N){
    ELEMENT2 phrase_chiffrer;
    for (int i=1;i<=N;i++){
        phrase_chiffrer=elementCreer2();
        elementCopier2(&phrase_chiffrer,remp_phrase(recuperer(L,i),Depiler(pilePublique)));
        inserer2(L_chiffrer,phrase_chiffrer,i);
    }

}


int verif_premier(int p){
    int i;
    for (i=2; i<p/2;i++)    if (p%i==0) return 0;
    return 1;
}


int PGCD(int exposant, int fonction){
    int temp;
    while (fonction != 0){
        temp = exposant % fonction;
        exposant = fonction;
        fonction = temp;
    }
    return exposant;
}


void calcul_rsa(int *tabpremier,ELEMENT1 e1,ELEMENT1 e2){
    int p,q,n,fonction,exposant=2,stop=0,d=1;

    do{
        srand(time(NULL));
        p = tabpremier[rand() %169];
        q = tabpremier[rand() %169];
    }while(!verif_premier(p)&& !verif_premier(q));
    n=p*q;
    fonction=(p-1)*(q-1);
    while(exposant<fonction && !stop){
        if (verif_premier(exposant) && PGCD(exposant,fonction)==1) stop=1;
        else exposant++;
    }
    stop=0;
    do{
        if((d*exposant)%fonction==1) stop=1;
        else d++;
    }while(!stop);
    (e1)->a=n;
    (e1)->b=exposant;
    (e2)->a=n;
    (e2)->b=d;

}

int verifier_existe(Pile p,ELEMENT1 e){
    int i=1,stop=0;
    while (i<=p->Sommet && !stop){
        if(elementComparer1(e,p->elements[i]))  stop=1;
        i++;
    }
    return stop;

}


void remplir(int N,Pile pilePrivee,Pile pilePublique,int *tabpremier){
    int i=1,test1=0,test2=0;
    ELEMENT1 e1,e2;
    do{
        e1=elementCreer1();
        e2=elementCreer1();
        calcul_rsa(tabpremier,e1,e2);
        if (!verifier_existe(pilePublique,e1) &&
            !verifier_existe(pilePublique,e2) &&
            !verifier_existe(pilePrivee,e1) &&
            !verifier_existe(pilePrivee,e2)
            ){
            test1=Empiler(pilePublique,e1);
            test2=Empiler(pilePrivee,e2);
            i++;
        } else{


        }
    }while(i<=N);
}



LISTE file (int N,LISTE L){
    int i=0;
    ELEMENT e;
    FILE*f= fopen("projet.txt", "r");
    while(i<N&&f!= NULL){
        e=elementCreer();
        fgets(e->phrase,sizeof(e->phrase),f);
        e->phrase[strcspn(e->phrase, "\n")] = '\0';

        inserer(L,e,1);
        i++;
    }
    fclose(f);
    return L;
}

int main(){
    //121
    system("cls");
    system("color B0");
    getch() ;
    setlocale(LC_ALL,"");
    Pile pilePrivee=PileCreer(),pilePublique=PileCreer();
    LISTE2 L_chiffrer=listeCreer2();
    //168
    int tabpremier[200]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
    int N;

    printf(MAGENTA);
    printf("\t \t \t \t \t Chiffrement RSA : \n");
    printf("\n \n");
    printf("Donnez Le Nombre De Phrases A Lire Du Fichier:\n");
    scanf("%i",&N);
    LISTE L=listeCreer();
    file(N,L);
    printf("\t \t \t \t \ --------------La liste:---------------\n");
    listeAfficher(L);
    remplir(N,pilePrivee,pilePublique,tabpremier);
    printf("\t \t \t \t  -------------Les deux piles:---------------\n");
    printf("La Pile Public: \n \n");
    PileAfficher(pilePublique);
    printf("\n \n");
    printf("La Pile Prive:\n \n");
    PileAfficher(pilePrivee);
    printf("\n \n");
    chiffrement_final(L_chiffrer,L,pilePublique,N);
    printf("\t \t \t   ------------------LES PHRASES CHIFFRER---------------- \n");
    listeAfficher2(L_chiffrer);
    printf("\t \t \t ------------------LES PHRASES DECHIFFRER---------------- \n");
    dechiffrement_final(L_chiffrer,pilePrivee,N);





    return 0;
}
