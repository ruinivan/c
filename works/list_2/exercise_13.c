#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    unsigned int atual, maxima, minima, media;
    printf("Qual é a quantidade atual em estoque: ");
    scanf("%u", &atual);
    printf("Qual é a quantidade máxima em estoque: ");
    scanf("%u", &maxima);
    printf("Qual é a quantidade mínima em estoque: ");
    scanf("%u", &minima);
    media=(maxima+minima)/2;
    if (atual>=media) printf("Não efetuar compra");
    else printf("Efetuar compra");
    return 0;
}