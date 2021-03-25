
/*
Leia um número inteiro e retorne seu antecessor e seu sucessor.

Exemplo de saída:
---------------------------------------------------
 << Numeros >>
 Digite um numero inteiro: 30
 Antecessor: 29
 Sucessor: 31
 
*/

#include <stdio.h>

int main(){
    int num;
    printf("<< Numeros >>\n");
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    printf("Antecessor: %d\n",num-1);
    printf("Sucessor: %d\n",num+1);
}