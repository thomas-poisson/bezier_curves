#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"util.h"
#include"decl.h"

int main (int argc, char *argv[]){

  if (argc==0){
    fprintf(stderr, "Veuillez entrer le nom du fichier des points de controle");
  }

  //lecture du fichier d'entrée
  char infile[50] = {'\0'};
  strcat(infile, "./controlpoints/");
  strcat(infile, argv[1]);
  printf("input file : %s\n", infile);
  int d; int n;
  float ** controlPoints;

  //borne sur l'intervalle à représenter
  int pts_nb; float a; float b;

  //coordonnées calculées des polynômes
  float * xx; float ** B_np;
  readfile (infile, &d, &n, &controlPoints, &pts_nb, &a, &b, &xx, &B_np);

  //creation du fichier de sortie
  char outfile[50] = {'\0'};
  strcat(outfile, "./curves/out_");
  strcat(outfile, argv[1]);
  printf("output file : %s\n", outfile);

  //boucle sur les x dans [a,b]
  for (int i=0; i<pts_nb; i++){
    xx[i]=a+i*(b-a)/(pts_nb-1);
    //calcul des B_n(x) par algorithme de DC
    DC(controlPoints, n, d, xx[i], i, B_np);
  }
  freetab(controlPoints);

  //ecriture ds fichier sortie des x, B_n(x)
  writefile(outfile, xx, B_np, pts_nb, d);
}
