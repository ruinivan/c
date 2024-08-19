#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    char nome[30];
    int idade;
    float peso; 
    printf("<<< EX03 - Dados >>>\n\n");
    printf("Qual é o seu nome? ");
    gets(nome);
    printf("Quantos anos você tem? ");
    scanf("%d", &idade);
    printf("Qual é o seu peso?(Kg) ");
    scanf("%f", &peso);
    printf("\n-------<<< PROCESSANDO >>>-------\n");
    printf("Muito prazer, %s. Você tem %u anos e pesa %.1fKg correto? \n", nome, idade, peso);
    printf("FIM.");
    return 0;
}