#include "ex7_prod.h"

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
