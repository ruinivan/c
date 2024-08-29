#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float total_valor, media, valor;
    int i, total_merca;
    printf("Qual o número total de mercadorias? ");
    scanf("%d", &total_merca);
    for (i=1; i<=total_merca; i++){
        printf("Digite o valor da %dª mercadoria: ", i);
        scanf("%f", &valor);
        total_valor+=valor;
    }
    media=total_valor/total_merca;
    printf("\nO valor total em estoque é de: R$%.2f \nE a média dos valores da mercadoria é de: R$%.2f", total_valor, media);
    return 0;
}