#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int i, dia=1, inferior=0, mais;
    float temp[dia], menor, maior, media, total=0;
    for(i=0;i<dia;i++){
        printf("Registrar temperatura: ");
        scanf("%f", &temp[i]);
        total+=temp[i];
        printf("Registrar mais?(1 ou 0) ");
        scanf("%d", &mais);
        dia+=mais;
    }
    menor = temp[0];
    for(i=0;i<dia;i++){
        menor = (temp[i]<menor) ? temp[i] : menor; 
    }
    for(i=0;i<dia;i++){
        maior = (temp[i]>maior) ? temp[i] : maior;
    }
    media = total/dia;
    for(i=0;i<dia;i++){
        
        (temp[i]<media) ? inferior++ : inferior;
    }
    printf("Menor Temperatura: %.1f \nMaior Temperatura: %.1f \nTemperatura Média: %.1f \nDias inferiores que a média: %d", menor, maior, media, inferior);
    return 0;
}