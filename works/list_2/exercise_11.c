#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float fixo, vendas;
    printf("Qual é o seu salário fixo? ");
    scanf("%f", &fixo);
    printf("Qual o valor das vendas efetuadas por você? ");
    scanf("%f", &vendas);
    if (vendas<=1500) printf("O salário total é de R$%.2f", fixo+(0.03*vendas));
    else printf("O salário total é de R$%.2f", fixo+(0.03*1500)+(0.05*(vendas-1500)));
    return 0;
}