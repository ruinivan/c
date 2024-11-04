#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "paciente.h"

void alocacao_paciente(paciente_t *paciente, char *nome, short idade){
    srand(time(NULL));
    for(int i=0; i<sizeof(paciente->nome); i++){
        if(paciente->nome[i] == '\n'){
            paciente->nome[i] = '\0'; 
            break;
        }
    }
    strncpy(paciente->nome, nome, sizeof(paciente->nome));
    paciente->idade = idade;
    int andar = (rand() % 5) + 1;
    int leito_andar = rand() % 10;
    paciente->leito = andar*100 + leito_andar;
}