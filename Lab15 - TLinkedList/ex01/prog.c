#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TLinkedList.h"

int main(){
    TLinkedList *list;
    struct aluno a,b,c,d;
    strcpy(a.nome,"Joao");
    a.matricula = 1;
    a.n1 = 0;    a.n2 = 2;    a.n3 = 0;

    strcpy(b.nome,"Maria");
    b.matricula = 2;
    b.n1 = 2;    b.n2 = 0;    b.n3 = 0;

    strcpy(c.nome,"Jose");
    c.matricula = 3;
    c.n1 = 0;    c.n2 = 0;    c.n3 = 4;

    strcpy(d.nome,"Ana");
    d.matricula = 4;
    d.n1 = 0;    d.n2 = 0;    d.n3 = 2;


    list = list_create();
    if (list == NULL){
       printf("ERRO!");
       exit(1);
    } 

    int ret;
    ret = list_push_back(list, a);
    if (ret == INVALID_NULL_POINTER)
      printf("Erro de ponteiro");
    else if (ret == OUT_OF_MEMORY)
      printf("Memoria insuficiente");
    else if (ret == SUCCESS)
      printf("Aluno inserido");

    list_push_back(list, b);
    list_push_back(list, c);
    list_push_back(list, d);        
 
 /// joao / maria / jose / ana

// maria -> joao ->jose ->ana

    list_print(list);
    int tam = list_size(list);
    printf("Tamanho da lista: %d", tam);
    list_free(list);
    list = NULL;

}