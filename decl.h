//IO.C ================================================================

int readfile(char * file, int *pd, int*pn, float *** pcontrolPoints,
  int * pnb, float * pa, float *pb, float ** pxx, float *** pB_np);

int writefile(char * file, float * xx, float ** B_nx, int pts_nb, int d);

//DC.c =================================================================

void DC(float ** controlPoints, int n, int d, float x, int xnb, float ** Bnx);

float DC_point (float * P, int n, float x);

void init (float ** P, float ** cp, int d,  int n);

//subdiv.c =================================================================