#include <stdio.h>

// Função altera_preco
// Desc: modifica o preço de um *produto*
// Entrada:
//    preco: preço do produto
//    porcentagem: valor percentual a ser alterado, podendo 
//    ser negativo para diminuir valores
// Retorno:
//    0 - sucesso
//    -1 - erro
int altera_preco(float *preco, float porcentagem){
   // testando o valor passado no parâmetro procentagem
   float temp;
   if (porcentagem >= -100) {
     temp = 1+ porcentagem/100;  /// Exemplo: 1+ 10/100 = 1.1 ; 1 -5/100
     *preco = (*preco)*temp;
     return 0;
   } else {
     return -1;
   }
}

int main(){
   char nome[4][100];
   float preco[4];
   int qtd_estoque[4];

   for (int i = 0; i < 4; i++)
   {
      printf("\nInforme o nome, o preco e a qtd. em estoque do produto 1:\n");
      scanf("%s", nome[i]);
      scanf("%f", &preco[i]);
      scanf("%d", &qtd_estoque[i]);
   }

   printf("\nAumentando o preco em 10%% do produto 1 e 3");
   altera_preco(&preco[0],10);
   altera_preco(&preco[2],10);   
   
   printf("\nReduzindo o preco em 5%% do produto 2");
   altera_preco(&preco[1],-5);
   
   printf("\nProdutos Cadastrados:\n");
   for (int i = 0; i < 4; i++){
     printf("\nProduto: %s\nPreco: %f\nEstoque: %d", nome[i],preco[i],qtd_estoque[i]);
   }

   return 0;
}