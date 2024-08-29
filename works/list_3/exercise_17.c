#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int merca=1;
    float total_valor, media, valor;
    char mais;
    do{
        printf("Digite o valor da %dª mercadoria: ", merca);
        scanf("%f", &valor);
        total_valor+=valor;
        merca++;
        printf("MAIS MERCADORIAS (S/N)? ");
        scanf(" %c", &mais);
    }while(mais=='S');
    media=total_valor/(--merca);
    printf("\nO valor total em estoque é de: R$%.2f \nE a média dos valores da mercadoria é de: R$%.2f", total_valor, media);
    return 0;
}