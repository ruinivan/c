#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(0, "Portuguese");
    float base, altura, area;
    printf("Qual é a base do retângulo? ");
    scanf("%f", &base);
    printf("Qual é a altura do retângulo? ");
    scanf("%f", &altura);
    area=base*altura;
    printf("A área do retângulo é de %.2fm².", area);
    return 0;
}