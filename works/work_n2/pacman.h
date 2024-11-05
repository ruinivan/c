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
    posicao local_inicial;
    posicao local_final;
    int *reviver;
}spawn;
struct{
    posicao local;
    int vida;
}fantasma1;

struct{
    posicao local;
    int vida;
}fantasma2;

struct{
    posicao local;
    int vida;
}fantasma3;

struct{
    posicao local;
    int vida;
}fantasma4;

struct{
    posicao local;
    int vida;
}fantasma5;

struct{
    posicao local;
    int vida;
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