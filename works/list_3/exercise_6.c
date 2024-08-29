#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float n1, n2;
    char dnv;
    do{
        do{
            printf("Qual a sua nota da 1ª avaliação? ");
            scanf("%f", &n1);
        }while (n1<=0 || n1>10);
        do{
            printf("Qual a sua nota da 2ª avaliação? ");
            scanf("%f", &n2);
        }while (n2<=0 || n2>10);
        printf("A média é de %.2f", (n1+n2)/2);
        printf("\nNOVO CÁLCULO (S/N)? ");
        scanf(" %c", &dnv);
    }while (dnv=='S');
    return 0;
}