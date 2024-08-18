#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(0, "Portuguese");
    float n1, n2, n3, mf;
    printf("Qual é a sua primeira nota: ");
    scanf("%f", &n1);
    printf("Qual é a sua segunda nota: ");
    scanf("%f", &n2);
    printf("Qual é a sua terceira nota ");
    scanf("%f", &n3);
    mf= (2*n1 + 3*n2 + 5*n3)/10;
    printf("Sua média final é de: %.1f", mf);
    return 0;
}