#include <stdio.h>
#include "pacman.h"

int main(){
    score.pontos = 0;
    moedas.valor = 100;
    pacman.poder = 0;
    fruta.poder = &pacman.poder;
    fantasma.morrer = &pacman.poder;

    while((pacman.local.y-1 != parede.local.y && pacman.local.x != parede.local.x) && pacman.andar=='w'){
        pacman.local.y--;       /* andar pra cima */
    }
    while((pacman.local.x+1 != parede.local.x && pacman.local.y != parede.local.y) && pacman.andar=='a'){
        pacman.local.x--;       /* andar pra esquerda */
    }
    while((pacman.local.y+1 != parede.local.y && pacman.local.x != parede.local.x) && pacman.andar=='s'){
        pacman.local.y++;       /* andar pra baixo */
    }
    while((pacman.local.x+1 != parede.local.x && pacman.local.y != parede.local.y) && pacman.andar=='d'){
        pacman.local.x++;       /* andar pra direita */
    }

    if(((pacman.local.x == fantasma1.local.x && pacman.local.y == fantasma1.local.y) || (pacman.local.x == fantasma2.local.x && pacman.local.y == fantasma2.local.y) || (pacman.local.x == fantasma3.local.x && pacman.local.y == fantasma3.local.y) || (pacman.local.x == fantasma4.local.x && pacman.local.y == fantasma4.local.y) || (pacman.local.x == fantasma5.local.x && pacman.local.y == fantasma5.local.y) || (pacman.local.x == fantasma6.local.x && pacman.local.y == fantasma6.local.y)) && pacman.poder == 0) /*GAME OVER*/ {
        
    }

    if((pacman.local.x == fantasma1.local.x && pacman.local.y == fantasma1.local.y) && pacman.poder == 1) /*Kill fantasma1*/ {
        score.pontos += 150;
    }
    if((pacman.local.x == fantasma2.local.x && pacman.local.y == fantasma2.local.y) && pacman.poder == 1) /*Kill fantasma2*/ {
        score.pontos += 150;
    }
    if((pacman.local.x == fantasma3.local.x && pacman.local.y == fantasma3.local.y) && pacman.poder == 1) /*Kill fantasma3*/ {
        score.pontos += 150;
    }
    if((pacman.local.x == fantasma4.local.x && pacman.local.y == fantasma4.local.y) && pacman.poder == 1) /*Kill fantasma4*/ {
        score.pontos += 150;
    }
    if((pacman.local.x == fantasma5.local.x && pacman.local.y == fantasma5.local.y) && pacman.poder == 1) /*Kill fantasma5*/ {
        score.pontos += 150;
    }
    if((pacman.local.x == fantasma6.local.x && pacman.local.y == fantasma6.local.y) && pacman.poder == 1) /*Kill fantasma6*/ {
        score.pontos += 150;
    }

    return 0;
}