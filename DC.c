#include <stdlib.h>

#include"util.h"
#include"decl.h"

void DC(float ** controlPoints, int n, int d, float x, int xnb, float ** Bnx){
    //initialisation de l'algorithme
    float ** cp = alloctab(d, n);
    init(controlPoints, cp, d, n);

    //boucle sur la dimension du probleme
    for (int i=0; i<d; i++){
        //appel à la méthode DC en dimension 1
        Bnx[i][xnb] = DC_point(cp[i], n, x);
    }
    //libération de la mémoire de la copie
    freetab(cp);
}

float DC_point (float * c, int n, float x){
    for (int k=0; k < n-1; k++){
        for (int i=0; i < n-1-k ; i++){
            c[i] = (1-x) * c[i] + x * c[i+1] ;
        }
    }
    return c[0];
}

void init (float ** P, float ** cp, int d,  int n){
    //réalise une copie de P dans cp (alloc de cp à réaliser au préalable)
    for (int j=0; j<d; j++){
         for (int i=0; i<n; i++){
            cp[j][i] = P[j][i];
        }
    }
}