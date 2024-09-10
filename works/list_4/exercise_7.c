#include <stdio.h>
int main(){
    int valor;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    return (valor%2==0) ? 1: 0;
}