#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(0, "Portuguese");
    int percentual_reajuste;
    float salario_mensal, salario_final;
    printf("Quanto é o seu salário mensal, antes do reajuste? ");
    scanf("%f", &salario_mensal);
    printf("Qual é o perceltual de reajuste?(sem a porcentagem) ");
    scanf("%d", &percentual_reajuste);
    salario_final = salario_mensal*(1 + percentual_reajuste*0.01);
    printf("O novo salario é de R$%.2f", salario_final);
    return 0;
}