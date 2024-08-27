#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    unsigned int conta;
    float saldo, debito, credito, saldo_atual;
    printf("Qual é o número da sua conta: ");
    scanf("%u", &conta);
    printf("Qual é o seu saldo? ");
    scanf("%f", &saldo);
    printf("Quanto de débito você têm? ");
    scanf("%f", &debito);
    printf("Quanto de crédito você têm? ");
    scanf("%f", &credito);
    saldo_atual = saldo - debito + credito;
    if (saldo_atual>=0) printf("Saldo Positivo de R$%.2f", saldo_atual);
    else printf("Saldo Negativo de R$%.2f", saldo_atual);
    return 0;
}