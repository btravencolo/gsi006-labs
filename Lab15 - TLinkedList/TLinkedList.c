#include <stdlib.h>
#include "TLinkedList.h"

typedef struct list_node list_node;

struct list_node {
    struct aluno data;
    list_node *next;  
};

struct TLinkedList {
    list_node *head;
};

TLinkedList *list_create(){
    TLinkedList *list;
    list = malloc(sizeof(TLinkedList));
    if (list != NULL){
        list->head = NULL;
    }
    return list;
}


int list_push_front(TLinkedList *list, struct aluno al){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    } else {
        list_node *node;
        node = malloc(sizeof(list_node));
        if (node == NULL){
            return OUT_OF_MEMORY;
        }
        node->data = al;

        if (list->head == NULL){ // testando se a lista está vazia
          node->next = NULL;
        } else { // a lista contem elementos
          node->next = list->head;
        }
        list->head = node;
    }
  
}