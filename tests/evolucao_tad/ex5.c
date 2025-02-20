#include <stdio.h>

typedef struct produto produto;

struct produto
{
   char nome[100];
   float preco;
   int qtd_estoque;
};


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
   altera_preco(&p[1],-5);   

   printf("\nProdutos Cadastrados:\n");
   for (int i = 0; i < 4; i++){
     printf("\nProduto: %s\nPreco: %f\nEstoque: %d", p[i].nome,p[i].preco,p[i].qtd_estoque);
   }

   return 0;
}