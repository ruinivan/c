#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float n1, n2;
    printf("Digite o numerador: ");
    scanf("%f", &n1);
    do{
        printf("Digite o denominador: ");
        scanf("%f", &n2);
        if (n2==0) printf("VALOR INVÁLIDO\n");
    } while(n2==0);
    printf("%.2f/%.2f = %.2f", n1, n2, n1/n2);
    return 0;
}