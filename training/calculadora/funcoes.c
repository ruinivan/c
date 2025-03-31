#include <stdio.h>
#include "funcoes.h"

char menu(){
    char opr;
    printf("Digite o simbolo operacional desejado:(+ - * /) ");
    getchar();
    scanf("%c", &opr);
    return opr;
}

float soma(float m, float n){
    return m+n;
}

float sub(float m, float n){
    return m-n;
}

float mult(float m, float n){
    return m*n;
}

float div(float m, float n){
    return m/n;
}