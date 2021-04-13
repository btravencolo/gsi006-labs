#include <stdio.h>
#include "TMat2D.h"

int main(){
    
    
    TMat2D *p = NULL;
    printf("\nCriando a matriz\n");
    p = mat2D_create(1000,1000);
    if (p==NULL){
        printf("Erro na alocacao da matriz");
    } else{  
        
        // preencher a matrix
        // .....
        // soma matriz;
        // ...
        printf("Apagando a matriz\n");
        mat2d_free(p);
    }

    return 0;
}