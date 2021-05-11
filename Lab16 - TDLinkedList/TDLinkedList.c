#include <stdlib.h>
#include <stdio.h>
#include "TDLinkedList.h"

typedef struct DLNode DLNode;

struct DLNode
{
    struct aluno data;
    DLNode *prev;
    DLNode *next;
};

// estrutura do descritor da lista
struct TDLinkedList
{
    DLNode *begin;
    DLNode *end;
    int size;
};

TDLinkedList *list_create()
{
    TDLinkedList *list;
    list = malloc(sizeof(TDLinkedList));
    if (list != NULL)
    {
        list->begin = NULL;
        list->end = NULL;
        list->size = 0;
    }
    return list;
}

int list_push_front(TDLinkedList *list, struct aluno al)
{
    if (list == NULL)
        return INVALID_NULL_POINTER;

    DLNode *node;
    node = malloc(sizeof(DLNode));
    if (node == NULL)
        return OUT_OF_MEMORY;

    node->data = al;
    node->prev = NULL;
    node->next = list->begin;

    if (list->begin == NULL)
    { // a lista está vazia
        list->begin = node;
        list->end = node;
        list->size = 1;
    }
    else
    { // a lista possui um nó
        list->begin->prev = node;
        list->begin = node;
        list->size++;
    }
    return SUCCESS;
}

int list_print_forward(TDLinkedList *list)
{
    if (list == NULL)
        return INVALID_NULL_POINTER;
    DLNode *aux;
    aux = list->begin;
    printf("\nImprimindo a lista\n");

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


int list_print_reverse(TDLinkedList *list)
{
    if (list == NULL)
        return INVALID_NULL_POINTER;
    DLNode *aux;
    aux = list->end;
    printf("\nImprimindo a lista - reverso\n");

    while (aux != NULL)
    {
        printf("\n------------------\n");
        printf("Matricula: %d\n", aux->data.matricula);
        printf("Nome: %s\n", aux->data.nome);
        printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

        aux = aux->prev;
    }
    printf("\nFim da lista \n");
}
