#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(0, "Portuguese");
    int carros;
    float salario_fixo, comissao, valor_vendas, salario_total;
    printf("Qual é o seu salario fixo? ");
    scanf("%f", &salario_fixo);
    printf("Quanto de comissão você ganha por carro vendido? ");
    scanf("%f", &comissao);
    printf("Quantos carros você vendeu? ");
    scanf("%d", &carros);
    printf("Qual é o valor dos carros que você vendeu? ");
    scanf("%f", &valor_vendas);
    salario_total = salario_fixo + comissao*carros + 0.05*(valor_vendas*carros);
    printf("O seu salário total será de: R$%.2f", salario_total);
    return 0;
}