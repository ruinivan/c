#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(0, "Portuguese");
    int dia, mes, ano, dia_atual, mes_atual, ano_atual, total;
    printf("Você nasceu em qual dia? ");
    scanf("%d", &dia);
    printf("E em qual mês? ");
    scanf("%d", &mes);
    printf("e em qual ano? ");
    scanf("%d", &ano);
    printf("Qual dia é hoje? ");
    scanf("%d", &dia_atual);
    printf("Qual é o mês atual? ");
    scanf("%d", &mes_atual);
    printf("Qual é o ano atual? ");
    scanf("%d", &ano_atual);
    total=(dia_atual-dia)+(mes_atual-mes)*30+(ano_atual-ano)*365;
    printf("Você tem %d dias vivos.", total);
    return 0;
}