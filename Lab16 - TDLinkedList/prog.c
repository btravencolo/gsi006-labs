#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDLinkedList.h"

int main(){

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



    TDLinkedList *list;
    list = list_create();
    list_push_front(list,a);
    list_push_front(list,b);
    list_push_front(list,c);
    list_push_front(list,d);    

    list_print_forward(list);
    list_print_reverse(list);    

    return 0;
}