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

    //list_print_forward(list);
    //list_print_reverse(list);    

    TDLinkedList *list_teste;
    list_teste = list_create();
    int ret;
    ret = list_insert(list_teste,10,a);
    if (ret == OUT_OF_RANGE) 
        printf("Out of range!");
    ret = list_insert(list_teste,0,a);
    if (ret == OUT_OF_RANGE) 
        printf("Out of range!");
    
    list_insert(list_teste,1,a); // teste com a lista vazia;  L: a
    list_insert(list_teste,1,b); // teste com a lista com um elemento (insere antes);   L: b <> a 
    list_insert(list_teste,2,c); // insere no meio;   L: b <> c <> a     
    list_insert(list_teste,4,d); // insere na última posição; L: b <> c <> a <> d
    list_print_forward(list_teste);
    list_push_front(list_teste,d);
    list_print_forward(list_teste);// insere na primeira posição; L: d <> b <> c <> a <> d
    

    
        

    return 0;
}