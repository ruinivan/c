#include <stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    printf("<<< EX01 - Listagem >>>\n\n");
    printf("Listagem de Alunos\n");
    printf("Nome\t\tNota\n");
    printf("---------------------\n");
    printf("Ana beatriz\t 8.5\n");
    printf("Bianca Martins   9.0\n");
    printf("Cláudio Sá\t 5.5\n");
    printf("Giovana Silva    7.5");
    return 0;
}