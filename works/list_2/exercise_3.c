#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float macas;
    printf("Escreva a quantidade de mças compradas: ");
    scanf("%f", &macas);
    if(macas>12) printf("O custo total foi de R$%.2f", macas);
    else printf("O custo total foi de R$%.2f", macas * 1.3);
    return 0;
}