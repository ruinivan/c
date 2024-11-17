#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pediatra.h"

/* Cria o primeiro paciente da lista */
paciente_t * primeiro_paciente(char *nome, int idade, float peso, float altura, char genero) {
    paciente_t *novo = (paciente_t *)malloc(sizeof(paciente_t));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para o paciente.\n");
        exit(1);
    }
    strncpy(novo->nome, nome, 100);
    novo->idade = idade;
    novo->peso = peso;
    novo->altura = altura;
    novo->genero = genero;
    novo->prox = NULL;
    return novo;
}

/* Adiciona uma nova criança no final da lista */
void novo_paciente(paciente_t *primeiro, char *nome, int idade, float peso, float altura, char genero) {
    paciente_t *atual = primeiro;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    paciente_t *novo = (paciente_t *)malloc(sizeof(paciente_t));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para o paciente.\n");
        exit(1);
    }

    strncpy(novo->nome, nome, 100);
    novo->idade = idade;
    novo->peso = peso;
    novo->altura = altura;
    novo->genero = genero;
    novo->prox = NULL;

    atual->prox = novo;
}

/* Calcula o IMC da criança e retorna a classificação */
IMCInfantil calcula_imc(paciente_t *crianca) {
    if (crianca == NULL) {
        printf("Paciente invalido.\n");
        exit(1);
    }

    float imc = crianca->peso / (crianca->altura * crianca->altura);
    IMCInfantil classificacao;

    // Classificação baseada em faixa etária e gênero
    if (crianca->idade >= 6 && crianca->idade <= 15) {
        if (crianca->genero == 'M') { // Masculino
            if (imc < 14.0) {
                classificacao = ABAIXO;
            } else if (imc < 18.0) {
                classificacao = NORMAL;
            } else if (imc < 22.0) {
                classificacao = SOBREPESO;
            } else {
                classificacao = OBESIDADE;
            }
        } else if (crianca->genero == 'F') { // Feminino
            if (imc < 14.5) {
                classificacao = ABAIXO;
            } else if (imc < 18.5) {
                classificacao = NORMAL;
            } else if (imc < 22.5) {
                classificacao = SOBREPESO;
            } else {
                classificacao = OBESIDADE;
            }
        } else {
            printf("Genero invalido.\n");
            exit(1);
        }
    } else {
        printf("Idade fora da faixa permitida.\n");
        exit(1);
    }

    return classificacao;
}
