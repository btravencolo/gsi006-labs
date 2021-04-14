#include <stdio.h>
#include "ex6_prod.c"

int main(){

   produto p[4];

   for (int i = 0; i < 4; i++)
   {
      printf("\nInforme o nome, o preco e a qtd. em estoque do produto 1:\n");
      scanf("%s", p[i].nome);
      scanf("%f", &p[i].preco);
      scanf("%d", &p[i].qtd_estoque);
   }

   printf("\nAumentando o preco em 10%% do produto 1 e 3");
   altera_preco(&p[0],10);
   altera_preco(&p[2],10);   
   
   printf("\nReduzindo o preco em 5%% do produto 2");
   p[1].preco = p[1].preco*-5;   

   printf("\nProdutos Cadastrados:\n");
   for (int i = 0; i < 4; i++){
     printf("\nProduto: %s\nPreco: %f\nEstoque: %d", p[i].nome,p[i].preco,p[i].qtd_estoque);
   }

   return 0;
}