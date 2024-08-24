#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float horas, salario, total; 
    printf("Quantas horas você trabalhou neste mês: ");
    scanf("%f", &horas);
    printf("Quanto você recebe por hora? ");
    scanf("%f", &salario);
    if(horas>160){
        total = salario*160 + ((horas-160)*salario*1.5);
        printf("O salario total será de: R$%.2f", total);
    }
    else printf("O salarario total será de: R$%.2f", horas*salario);
    return 0;
}