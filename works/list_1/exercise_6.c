#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(0, "Portuguese");
    float carro_novo, custo_fabrica;
    printf("Qual é o custo de fabrica do carro? ");
    scanf("%f", &custo_fabrica);
    carro_novo = custo_fabrica + 0.28*custo_fabrica + 0.45*custo_fabrica;
    printf("O valor final ao consumidor do carro novo será de R$%.2f", carro_novo);
    return 0;
}