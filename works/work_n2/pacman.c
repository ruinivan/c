#include <stdio.h>

typedef struct{
    int x;
    int y;
}posicao;

typedef struct{
    posicao pacman_posicao;
    int *pacman_direcao;
}pacman;

typedef struct{
    posicao fantasma1_posicao;
    int *fantasma1_direcao;
}fantasma1;

typedef struct{
    posicao fantasma2_posicao;
    int *fantasma2_direcao;
}fantasma2;

typedef struct{
    posicao fantasma3_posicao;
    int *fantasma3_direcao;
}fantasma3;

typedef struct{
    posicao fantasma4_posicao;
    int *fantasma4_direcao;
}fantasma4;

typedef struct{
    posicao fantasma5_posicao;
    int *fantasma5_direcao;
}fantasma5;

typedef struct{
    posicao fantasma6_posicao;
    int *fantasma6_direcao;
}fantasma6;

struct{
    int pontos;
}score;

struct{
    int valor;
    int *atribuicao;
}moedas;


int main(){
    score.pontos = 0;
    moedas.valor = 100;
    moedas.atribuicao = &score.pontos;
}