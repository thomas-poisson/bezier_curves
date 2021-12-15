#include <stdio.h>
#include <stdlib.h>

#include"util.h"
#include"decl.h"

int main (){
  //lecture du fichier d'entrée
  char * infile="PtsControle.csv";
  int d; int n;
  float ** controlPoints;
  //borne sur l'intervalle à représenter
  int pts_nb; float a; float b;
  //coordonnées calculées des polynômes
  float * xx; float ** B_np;
  readfile (infile, &d, &n, &controlPoints, &pts_nb, &a, &b, &xx, &B_np);

  //creation du fichier de sortie
  char * outfile="output.csv";

  //boucle sur les x dans [a,b]
  float * Bnx = malloc(d*sizeof(float));
  for (int i=0; i<pts_nb; i++){
    xx[i]=a+i*(b-a)/pts_nb;
    //calcul des B_n(x) par algorithme de DC
    for (int j=0; j<d; j++){
      Bnx[j]=0;
      //écriture dans B_np (étape inutile en allouant plus intelligemment la mémoire)
      B_np[j][i]=Bnx[j];
    }
    
  }
  free(Bnx);
  freetab(controlPoints);

  //ecriture ds fichier sortie des x, B_n(x)
  writefile(outfile, xx, B_np, pts_nb);
}
