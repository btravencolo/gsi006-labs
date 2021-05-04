#include <stdlib.h>
#include <stdio.h>
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

int list_free(TLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    } else{
        list_node *aux;
        aux = list->head;
        while (aux != NULL){
            list->head = aux->next;
            free(aux);
            aux = list->head;
        }

        // // solucao 2
        // while (list->head != NULL){
        //     aux = list->head;
        //     list->head = list->head->next;
        //     free(aux);
        // }

        free(list);
    }

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
        node->next = list->head;
        list->head = node;
        return SUCCESS;
    }
  
}

int list_print(TLinkedList *list){
    if (list == NULL)
      return INVALID_NULL_POINTER;
    else {
        list_node *aux;
        aux = list->head;

        printf("\nImprimindo a lista \n");

        while (aux != NULL){
            printf("\n------------------\n");
            printf("Matricula: %d\n",aux->data.matricula);
            printf("Nome: %s\n",aux->data.nome);            
            printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);  

            aux = aux->next;          

        }

        printf("\nFim da lista \n");        
        return SUCCESS;
    }  

}