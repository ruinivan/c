#include <stdio.h>
#include "pediatra.h"

void exibe_classificacao(IMCInfantil classificacao) {
    switch (classificacao) {
        case ABAIXO:
            printf("Classificacao: Abaixo do peso\n");
            break;
        case NORMAL:
            printf("Classificacao: Peso normal\n");
            break;
        case SOBREPESO:
            printf("Classificacao: Sobrepeso\n");
            break;
        case OBESIDADE:
            printf("Classificacao: Obesidade\n");
            break;
        default:
            printf("Classificacao invalida.\n");
    }
}

int main() {
    // Criar o primeiro paciente
    paciente_t *lista_pacientes = primeiro_paciente("Ana", 10, 30.0, 1.40, 'F');

    // Adicionar mais pacientes
    novo_paciente(lista_pacientes, "Joao", 12, 50.0, 1.50, 'M');
    novo_paciente(lista_pacientes, "Maria", 8, 25.0, 1.20, 'F');
    novo_paciente(lista_pacientes, "Pedro", 15, 70.0, 1.70, 'M');

    // Iterar sobre a lista de pacientes e calcular o IMC
    paciente_t *atual = lista_pacientes;
    while (atual != NULL) {
        printf("\nPaciente: %s\n", atual->nome);
        printf("Idade: %d anos\n", atual->idade);
        printf("Peso: %.2f kg\n", atual->peso);
        printf("Altura: %.2f m\n", atual->altura);
        printf("Genero: %c\n", atual->genero);

        // Calcular o IMC e exibir a classificacao
        IMCInfantil classificacao = calcula_imc(atual);
        exibe_classificacao(classificacao);

        // Ir para o próximo paciente
        atual = atual->prox;
    }

    return 0;
}
