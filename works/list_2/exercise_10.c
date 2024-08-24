#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    char nome[]="", sexo;
    float altura;
    printf("Qual é o seu nome: ");
    gets(nome);
    printf("%s, qual é a sua altura em metros? ", nome);
    scanf(" %f", &altura);
    printf("%s, qual é o seu sexo?(M ou F) ", nome);
    scanf(" %c", &sexo);
    if (sexo=='M'){
        printf("Seu peso ideal é %.2f", (72.7*altura)-58);
    }
    else if(sexo=='F'){
        printf("Seu peso ideal é %.2f", (62.1*altura)-44,7);
    }
    return 0;
}