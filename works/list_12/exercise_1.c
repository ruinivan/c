#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    char nome[100];
    int faltas;
    float nota;
} aluno_t;

int main() {
    aluno_t* aluno = (aluno_t*)malloc(sizeof(aluno_t));

    if (aluno == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Carregar dados
    printf("Digite o nome do aluno: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);
    printf("Digite o número de faltas: ");
    scanf("%d", &aluno->faltas);
    printf("Digite a nota: ");
    scanf("%f", &aluno->nota);

    // Exibir dados
    printf("\nAluno: %s", aluno->nome);
    printf("Faltas: %d\n", aluno->faltas);
    printf("Nota: %.2f\n", aluno->nota);

    // Verificar aprovação
    if (aluno->nota >= 7.0 && aluno->faltas <= 25) {
        printf("Aluno aprovado!\n");
    } else {
        printf("Aluno reprovado.\n");
    }

    free(aluno); // Libera a memória alocada
    return 0;
}
