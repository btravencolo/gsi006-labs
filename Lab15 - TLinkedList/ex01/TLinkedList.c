#include <stdlib.h>
#include <stdio.h>
#include "TLinkedList.h"

typedef struct list_node list_node;

struct list_node
{
    struct aluno data;
    list_node *next;
};

struct TLinkedList
{
    list_node *head;
};

TLinkedList *list_create()
{
    TLinkedList *list;
    list = malloc(sizeof(TLinkedList));
    if (list != NULL)
    {
        list->head = NULL;
    }
    return list;
}

int list_push_front(TLinkedList *list, struct aluno al)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *node;
        node = malloc(sizeof(list_node));
        if (node == NULL)
        {
            return OUT_OF_MEMORY;
        }
        node->data = al;
        node->next = list->head;
        list->head = node;

        return SUCCESS;
    }
}

int list_push_back(TLinkedList *list, struct aluno al)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *node;
        node = malloc(sizeof(list_node));
        if (node == NULL)
            return OUT_OF_MEMORY;
        node->data = al;
        node->next = NULL;
        if (list->head == NULL)
        { // a lista está vazia
            list->head = node;
        }
        else
        { // a lista tem pelo menos um nó
            list_node *aux;
            aux = list->head;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = node;
        }
        return SUCCESS;
    }
}

int list_print(TLinkedList *list)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *aux;
        aux = list->head;
        printf("\nImprimindo a lista (tamanho %d)\n", list_size(list));

        while (aux != NULL)
        {
            printf("\n------------------\n");
            printf("Matricula: %d\n", aux->data.matricula);
            printf("Nome: %s\n", aux->data.nome);
            printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

            aux = aux->next;
        }
        printf("\nFim da lista \n");
    }
}

int list_free(TLinkedList *list)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *aux;

        aux = list->head;
        while (aux != NULL)
        {
            list->head = aux->next;
            free(aux);
            aux = list->head;
        }

        // segunda forma
        // while (list->head != NULL)
        // {
        //     aux = list->head;
        //     list->head = list->head->next;
        //     free(aux);
        // }
        free(list);
        return SUCCESS;
    }
}


int list_size(TLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    } else {
        int contador = 0;
        list_node *aux;
        aux = list->head;
        while (aux != NULL)
        {
            aux = aux->next;
            contador = contador + 1;
        }
        return contador;
    }
}


int list_insert_sorted(TLinkedList *list, struct aluno al){
    if (list == NULL)
        return INVALID_NULL_POINTER;
    list_node *node;
    node = malloc(sizeof(list_node));
    if (node == NULL)
        return OUT_OF_MEMORY;
    node->data = al;

    list_node *aux, *prev;

    prev = NULL;
    aux = list->head;
    while ( (aux != NULL) && (node->data.matricula > aux->data.matricula)){
        prev = aux;
        aux = aux->next;
    }
    if (prev == NULL) { // inserção na cabeça (lista vazia ou matricula de menor de valor da lista)
        node->next = aux;
        list->head = node;
    } else {
       prev->next = node;
       node->next = aux;
    }
    return SUCCESS;   
}