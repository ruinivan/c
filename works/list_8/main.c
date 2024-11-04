#include <stdio.h>
#include "nascimento.h"

int main(){
    data_t nasc;
    printf("Digite sua data de nascimento (dd /mes /ano): ");
    scanf("%d /%d /%d", &nasc.dia, &nasc.mes, &nasc.ano);
    printf("Voce esta a %d dias vivos", dias_de_vida(nasc));
    return 0;
}