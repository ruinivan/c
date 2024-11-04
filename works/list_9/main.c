#include <stdio.h>
#include "paciente.h"

int main() {
    paciente_t paciente;
    printf("Qual o nome do paciente: ");
    fgets(paciente.nome, 100, stdin);
    for(int i=0; i<sizeof(paciente.nome); i++){
        if(paciente.nome[i] == '\n'){
            paciente.nome[i] = '\0'; 
            break;
        }
    }
    printf("E %s tem quantos anos? ", paciente.nome);
    scanf("%hd", &paciente.idade);
    printf("Paciente: %s\nIdade: %d\nLeito: %d\n", paciente.nome, paciente.idade, paciente.leito);
    return 0;
}