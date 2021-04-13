#include <stdlib.h>
#include "TMat2D.h"

struct TMat2D
{
    int nrows; // númemro de linhas ;
    int ncolumns; // número de colunas;
    double *data; // dados: local onde armazena os dados da matriz
};

TMat2D *mat2D_create(int nrow, int ncol){
    TMat2D *mat;
    mat = malloc(sizeof(TMat2D));
    if (mat == NULL){
        return NULL;
    }

    mat->nrows  =  nrow;
    mat->ncolumns = ncol;
    mat->data = malloc(ncol*nrow*sizeof(double));

    int i = 3;
    int j = 2;
    int pos;
    pos = j * mat->nrows + i;
    mat->data[pos] = 9.1;



 
    if (mat->data == NULL){
        free(mat);
        return NULL;
    }
    
    return mat;
}

// retorna 0: sucesso
// retorna -1: erro
int mat2d_free(TMat2D *mat){
    if (mat == NULL){
        return -1;
    } else{
      free(mat->data);
      free(mat);
      return 0;
    }
}