#include <stdio.h>
int main(){
    int valor;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    return (valor>0) ? 1 : (valor==0) ? 0 : -1;
}