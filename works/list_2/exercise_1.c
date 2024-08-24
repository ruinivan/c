#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int nun;
    printf("Escreva um número: ");
    scanf("%d", &nun);
    if(nun>10) printf("É MAIOR QUE 10!");
    else printf("NÃO É MAIOR QUE 10!");
    return 0;
}