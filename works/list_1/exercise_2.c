#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(0, "Portuguese");
    float base, altura, area;
    printf("Quanto que é a base do retângulo? ");
    scanf("%f", &base);
    printf("Quantpo que é a altura do retângulo? ");
    scanf("%f", &altura);
    area=base*altura;
    printf("A área do retângulo vale %.2fm².", area);
    return 0;
}