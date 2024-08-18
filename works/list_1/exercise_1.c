#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(0, "Portuguese");
    int a, b;
    printf("Escreva um número: ");
    scanf("%d", &a);
    b=--a;
    printf("O antecessor do seu número digitado é %d", b);
    return 0;
}