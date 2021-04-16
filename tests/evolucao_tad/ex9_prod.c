#include <stdlib.h>
#include <string.h>
#include "ex9_prod.h"

struct produto
{
   char nome[100];
   float preco;
   int qtd_estoque;
};

produto *cria_produto(char *nome, float preco, int qtd){
  produto *p;

  p = malloc(sizeof(produto));
  if (p == NULL)
    return NULL;
  strcpy(p->nome,nome);
  p->preco = preco;
  p->qtd_estoque = qtd;
  return p;
}
// retorno
// -1 - erro
// 0 - sucesso
int get_prod_info(produto *prod, char *nome, float *preco, int *qtd){
  if (prod == NULL)
    return -1;
  strcpy(nome,prod->nome);
  *preco = prod->preco;
  *qtd = prod->qtd_estoque;
  return 0; //success
}
// Função altera_preco
// Desc: modifica o preço de um *produto*
// Entrada:
//    produto: informações do produto
//    porcentagem: valor percentual a ser alterado, podendo 
//    ser negativo para diminuir valores
// Retorno:
//    0 - sucesso
//    1 - erro
int altera_preco(produto *prod, float porcentagem){
   // testando o valor passado no parâmetro procentagem
   float temp;
   if (porcentagem >= -100) {
     temp = 1+ porcentagem/100;  /// Exemplo: 1+ 10/100 = 1.1 ; 1 -5/100
     prod->preco = prod->preco*temp;
     return 0;
   } else {
     return -1;
   }
}

int destroi_produto(produto *prod){
  if (prod == NULL)
    return -1;
  free(prod);
  return 0;
}