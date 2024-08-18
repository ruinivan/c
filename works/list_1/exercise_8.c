#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(0, "Portuguese");
    int f, c;
    printf("Escreva uma temperatura em Fahrenheit para converter em graus Celsius: ");
    scanf("%d", &f);
    c = 5*(f-32)/9;
    printf("A temperatura em graus Celsius é de %d", c);
    return 0;
}