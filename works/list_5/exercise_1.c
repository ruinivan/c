#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int cont, p=0;
    float notas[20], media, soma;
    for(cont=0;cont<20;cont++){
        printf("Qual é a nota do %dº Aluno: ", cont+1);
        scanf("%f", &notas[cont]);
        soma+=notas[cont];
    }
    media=soma/cont;
    for(cont=0;cont<20;cont++){
        (notas[cont]>media) ? p++ : p;
    }
    printf("A média foi de %.2f \nE os alunos que passaram da média foram de %d", media, p);
    return 0;
}