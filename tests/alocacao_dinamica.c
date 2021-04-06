#include <stdio.h>
#include <stdlib.h>

int func(int x){

}

int main()
{
    int i = 0;
    double *p;
    for (i = 0; i < 500; i++){
          // alocando 200MB a cada passo do loop
          p = (double *)malloc(25*1024*1024*sizeof(double));

          if (p != NULL){
            printf("Passo: %d\n",  i);
            printf("Memoria alocada\n");
            system("pause");
          } else {
            printf("Passo: %d\n",  i);
            printf("Erro! Memoria insuficiente\n");
            system("pause");
          }

    }
    system("pause");
    return 0;
}
