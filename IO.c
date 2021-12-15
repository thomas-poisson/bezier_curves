#include <stdio.h>
#include <stdlib.h>

#include"util.h"

int readfile(char * file, int *pd, int*pn, float *** pcontrolPoints,
  int * pnb, float * pa, float *pb, float ** pxx, float *** pB_np){
  //format fichier :
  //d n
  //coord point1 (x1 ... xd)
  //...
  //coord pointn (x1 ... xd)
  //pts_nb a b

  FILE *fp = fopen(file, "r");
  if (fp==NULL) {fprintf(stderr, "erreur de lecture de fichier\n"); return(1);}
  fscanf(fp, "%d %d", pd, pn);
  int d = *pd; int n = *pn;
  *pcontrolPoints = alloctab(d,n);
  float ** controlPoints = *pcontrolPoints;
  for (int j=0; j<n; j++){
    for (int i=0; i<d; i++){
      fscanf(fp, "%f", & (controlPoints[i][j]) );
    }
  }
  fscanf(fp, "%d %f %f", pnb, pa, pb);
  (* pxx) = malloc((*pnb) * sizeof(float));
  (* pB_np) = alloctab(d, (*pnb));
  fclose(fp);
  return 0;
}

int writefile(char * file, float * xx, float ** B_nx, int pts_nb, int d){
  //format fichier :
  //d n
  //...
  //x B_n(x)_1 B_n(x)_2 ... B_n(x)_d
  //...

  FILE *fp = fopen(file, "w");
  if (fp==NULL) {fprintf(stderr, "erreur d'ecriture de fichier\n"); return(1);}
  //header
  fprintf(fp,"%d %d ", d, pts_nb);
  for (int i=1; i<d; i++){
    fprintf(fp, "0 ");
  }
  fprintf(fp, "\n");
  //data
  for (int i=0; i<pts_nb; i++){
    fprintf(fp,"%f ", xx[i]);
    for (int j=0; j<d; j++){
      fprintf(fp,"%f ", B_nx[j][i]);
    }
    fprintf(fp,"\n");
  }
  free(xx); freetab(B_nx);
  return 0;
}
