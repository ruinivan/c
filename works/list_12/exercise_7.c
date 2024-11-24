#include <stdio.h>

int main() {
    float nota;
    int faltas;

    printf("Digite a nota do estudante: ");
    scanf("%f", &nota);
    printf("Digite o número de faltas do estudante: ");
    scanf("%d", &faltas);

    if (nota >= 7 && faltas <= 25) {
        printf("Estudante aprovado.\n");
    } else {
        printf("Estudante reprovado.\n");
    }

    return 0;
}
