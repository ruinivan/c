#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float n1, n2, m;
    printf("Qual o valor da sua primeira nota: ");
    scanf("%f", &n1);
    printf("Qual o valor da sua segunda nota: ");
    scanf("%f", &n2);
    m = (n1+n2)/2;
    if (m>=7) printf("APROVADO! E sua média é de %.2f", m);
    else printf("NÃO APROVADO! E sua média é de %.2f", m);
    return 0;
}