#ifndef PACMAN_H
#define PACMAN_H

typedef struct{
    int x;
    int y;
}posicao;

typedef struct{
    posicao local;
    int vida;
}fantasmas;

typedef struct{
    posicao local;
}frutas;

typedef struct{
    posicao local;
}moedas;

struct{
    posicao local;
    char andar;
    int poder;
}pacman;

struct{
    posicao local_inicial;
    posicao local_final;
}spawn;

#endif