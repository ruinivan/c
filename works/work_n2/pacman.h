#ifndef PACMAN_H
#define PACMAN_H

typedef struct{
    int x;
    int y;
}posicao;

struct{
    posicao local;
    char andar;
    int poder;
}pacman;

struct{
    int *morrer;
}fantasma;

struct{
    posicao local;
}fantasma1;

struct{
    posicao local;
}fantasma2;

struct{
    posicao local;
}fantasma3;

struct{
    posicao local;
}fantasma4;

struct{
    posicao local;
}fantasma5;

struct{
    posicao local;
}fantasma6;

struct{
    posicao local;
}parede;

struct{
    int pontos;
}score;

struct{
    posicao local;
    int valor;
}moedas;

struct{
    posicao local;
    int *poder;
}fruta;

#endif