#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int i, inferior=0;
    float temp[365], menor, maior, media, total=0;
    srand(time(NULL));
    for(i=0;i<365;i++){
        temp[i] = (rand()%32)+10;
        total+=temp[i];
    }
    menor = temp[0];
    for(i=0;i<365;i++) menor = (temp[i]<menor) ? temp[i] : menor; 
    for(i=0;i<365;i++) maior = (temp[i]>maior) ? temp[i] : maior;
    media = total/365;
    for(i=0;i<365;i++) (temp[i]<media) ? inferior++ : inferior;
    printf("Menor Temperatura: %.1f \nMaior Temperatura: %.1f \nTemperatura Média: %.1f \nDias inferiores que a média: %d", menor, maior, media, inferior);
    return 0;
}