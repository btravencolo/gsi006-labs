#include <stdio.h>
#include "ex9_prod.h"

int main(){

   //produto *p1, *p2, *p3;

   produto *p[4];

   char nome[100];
   float preco; 
   int qtd_estoque;

   for (int i = 0; i < 4; i++){ 
     printf("\nInforme o nome, o preco e a qtd. em estoque do produto 1:\n");
     scanf("%s", nome);
     scanf("%f", &preco);
     scanf("%d", &qtd_estoque);
     p[i] = cria_produto(nome,preco,qtd_estoque);
   }


   printf("\nAumentando o preco em 10%% do produto 1 e 3");
   altera_preco(p[0],10);
   altera_preco(p[2],10);   
   
   printf("\nReduzindo o preco em 5%% do produto 2");
   if (altera_preco(p[1],-5) == -1)
    printf("\n Erro! - preco nao alterado ");   
   //  p->preco = p->preco*-5;   <<< não compila se descomentar

   printf("\nProdutos Cadastrados:\n");
   
   for (int i = 0; i < 4; i++){ 
     get_prod_info(p[i],nome,&preco,&qtd_estoque);
     printf("\nProduto: %s\nPreco: %f\nEstoque: %d", nome,preco,qtd_estoque);
   }

   for (int i = 0; i < 4; i++)
     destroi_produto(p[i]);

   return 0;
}