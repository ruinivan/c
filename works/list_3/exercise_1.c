#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float nun1, nun2=0;
    printf("Digite o numerador: ");
    scanf("%f", &nun1);
    while (nun2==0){
        printf("Digite o denominador: ");
        scanf("%f", &nun2);
    }
    printf("%.2f/%.2f = %.2f", nun1, nun2, nun1/nun2);
    return 0;
}