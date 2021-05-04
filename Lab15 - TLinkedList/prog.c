#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TLinkedList.h"

int main(){
    TLinkedList *list;
    struct aluno a;
    strcpy(a.nome,"Joao");
    a.matricula = 1123;
    a.n1 = 0;    a.n2 = 0;    a.n3 = 0;
    
    list = list_create();
    if (list == NULL){
       printf("ERRO!");
       exit(1);
    } 

    list_push_front(list, a);
    list_push_front(list, a);
    list_push_front(list, a);

}