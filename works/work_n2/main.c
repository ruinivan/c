#include <stdio.h>
#include "pacman.h"

int main(){
    score.pontos = 0;
    pacman.poder = 0;
    fantasma fantasma[6];

    frutas fruta[5];                                /*5 frutas*/
    for(int i=0; i<5; i++) fruta[i].poder = &pacman.poder;

    moedas moeda[50];                               /*50 moedas*/
    for(int i=0; i<50; i++) moeda[i].valor = 100;

    while((pacman.local.y-1 != parede.local.y && pacman.local.x != parede.local.x) && pacman.andar=='w'){
        pacman.local.y--;                           /*andar pra cima*/
    }
    while((pacman.local.x+1 != parede.local.x && pacman.local.y != parede.local.y) && pacman.andar=='a'){
        pacman.local.x--;                           /*andar pra esquerda*/
    }
    while((pacman.local.y+1 != parede.local.y && pacman.local.x != parede.local.x) && pacman.andar=='s'){
        pacman.local.y++;                           /*andar pra baixo*/
    }
    while((pacman.local.x+1 != parede.local.x && pacman.local.y != parede.local.y) && pacman.andar=='d'){
        pacman.local.x++;                           /*andar pra direita*/
    }

    if(((pacman.local.x == fantasma[0].local.x && pacman.local.y == fantasma[0].local.y) || (pacman.local.x == fantasma[1].local.x && pacman.local.y == fantasma[1].local.y) || (pacman.local.x == fantasma[2].local.x && pacman.local.y == fantasma[2].local.y) || (pacman.local.x == fantasma[3].local.x && pacman.local.y == fantasma[3].local.y) || (pacman.local.x == fantasma[4].local.x && pacman.local.y == fantasma[4].local.y) || (pacman.local.x == fantasma[5].local.x && pacman.local.y == fantasma[5].local.y)) && pacman.poder == 0) /*GAME OVER*/ {
        
    }

    if((pacman.local.x == fantasma[0].local.x && pacman.local.y == fantasma[0].local.y) && pacman.poder == 1) /*Kill fantasma[0]*/ {

        score.pontos += 150;
    }
    if((pacman.local.x == fantasma[1].local.x && pacman.local.y == fantasma[1].local.y) && pacman.poder == 1) /*Kill fantasma[1]*/ {

        score.pontos += 150;
    }
    if((pacman.local.x == fantasma[2].local.x && pacman.local.y == fantasma[2].local.y) && pacman.poder == 1) /*Kill fantasma[3]*/ {

        score.pontos += 150;
    }
    if((pacman.local.x == fantasma[3].local.x && pacman.local.y == fantasma[3].local.y) && pacman.poder == 1) /*Kill fantasma[4]*/ {

        score.pontos += 150;
    }
    if((pacman.local.x == fantasma[4].local.x && pacman.local.y == fantasma[4].local.y) && pacman.poder == 1) /*Kill fantasma[4]*/ {

        score.pontos += 150;
    }
    if((pacman.local.x == fantasma[5].local.x && pacman.local.y == fantasma[5].local.y) && pacman.poder == 1) /*Kill fantasma[5]*/ {

        score.pontos += 150;
    }
    
    return 0;
}