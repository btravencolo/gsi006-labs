
/*
Ler uma temperatura em graus Celsius e apresentá-la convertida em graus Fahrenheit.
A fórmula de conversão é : F = C * (9.0/5.0)+ 32.0, sendo F a temperatura em Fahrenheit
e C a temperatura em Celsius.

Exemplo de saída:
---------------------------------------------------
 << Conversor Temperatura>>
 Digite a temperatura (em Celsius): 30
 30.0 graus Celsius correspondem a 86.0 Fahrenheit
 
*/

#include <stdio.h>

int main(){
    float tempc, tempf;
    printf("<< Conversor Temperatura>>\n");
    printf("Digite a temperatura (em Celsius): ");
    scanf("%f",&tempc);
    tempf = tempc * (9.0/5.0) + 32.0;
    printf("%.1f graus Celsius correspondem a %.1f Fahrenheit\n", tempc, tempf);
    return 0;
    
}
