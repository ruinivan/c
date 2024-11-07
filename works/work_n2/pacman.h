#ifndef PACMAN_H
#define PACMAN_H

typedef struct{
    int x;
    int y;
}posicao;

typedef struct{
    posicao local;
    int vida;
}fantasma;

typedef struct{
    posicao local;
    int valor;
}moedas;
struct{
    posicao local;
    char andar;
    int poder;
}pacman;

struct{
    posicao local_inicial;
    posicao local_final;
    int *reviver;
}spawn;

struct{
    posicao local;
}parede;

struct{
    int pontos;
}score;

typedef struct{
    posicao local;
    int *poder;
}frutas;

#endif