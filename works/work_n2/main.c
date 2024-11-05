#include <stdio.h>
#include "pacman.h"

int main(){
    score.pontos = 0;
    moedas.valor = 100;
    pacman.poder = 0;
    fruta.poder = &pacman.poder;
    fantasma.morrer = &pacman.poder;

    do{
        if(pacman.local.y-1 != parede.local.x) pacman.local.y--;           /* andar pra cima */
    }while(pacman.andar=='w');
    do{
        if(pacman.local.x-1 != parede.local.x) pacman.local.x--;           /* andar pra esquerda */
    }while(pacman.andar=='a');
    do{
        if(pacman.local.y+1 != parede.local.x) pacman.local.y++;           /* andar pra baixo */
    }while(pacman.andar=='s');
    do{
        if(pacman.local.x+1 != parede.local.x) pacman.local.x++;           /* andar pra direita */
    }while(pacman.andar=='d');

    if(((pacman.local.x == fantasma1.local.x && pacman.local.y == fantasma1.local.y) || (pacman.local.x == fantasma2.local.x && pacman.local.y == fantasma2.local.y) || (pacman.local.x == fantasma3.local.x && pacman.local.y == fantasma3.local.y) || (pacman.local.x == fantasma4.local.x && pacman.local.y == fantasma4.local.y) || (pacman.local.x == fantasma5.local.x && pacman.local.y == fantasma5.local.y) || (pacman.local.x == fantasma6.local.x && pacman.local.y == fantasma6.local.y)) && pacman.poder == 0) /*GAME OVER*/ {
        
    }

    if((pacman.local.x == fantasma1.local.x && pacman.local.y == fantasma1.local.y) && pacman.poder == 1) /*Kill fantasma1*/ {

    }
    if((pacman.local.x == fantasma2.local.x && pacman.local.y == fantasma2.local.y) && pacman.poder == 1) /*Kill fantasma2*/ {

    }
    if((pacman.local.x == fantasma3.local.x && pacman.local.y == fantasma3.local.y) && pacman.poder == 1) /*Kill fantasma3*/ {

    }
    if((pacman.local.x == fantasma4.local.x && pacman.local.y == fantasma4.local.y) && pacman.poder == 1) /*Kill fantasma4*/ {

    }
    if((pacman.local.x == fantasma5.local.x && pacman.local.y == fantasma5.local.y) && pacman.poder == 1) /*Kill fantasma5*/ {

    }
    if((pacman.local.x == fantasma6.local.x && pacman.local.y == fantasma6.local.y) && pacman.poder == 1) /*Kill fantasma6*/ {

    }

    return 0;
}