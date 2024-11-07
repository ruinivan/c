#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "pacman.h"

void assombrar(fantasmas *fantasma){    /*Fantasma vivo andar aleatoriamente*/
    int andar = rand() % 4;
    switch (andar){
    case 0:
        fantasma->local.y--;            /*fantasma pra cima*/
        sleep(1);
        break;
    case 1:
        fantasma->local.x--;            /*fantasma pra esquerda*/
        sleep(1);
        break;
    case 2:
        fantasma->local.y++;            /*fantasma pra baixo*/
        sleep(1);
        break;
    case 3:
        fantasma->local.x++;            /*fantasma pra direita*/
        sleep(1);
        break;
    default:
        break;
    }
}

int main(){
    int fim = 0;
    int total_moedas = 0;
    score.pontos = 0;
    pacman.poder = 0;

    fantasmas fantasma[4];       /*4 fantasmas*/
    for(int i=0; i<4; i++) fantasma[i].vida = 1;

    frutas *fruta[5];           /*5 frutas*/
    moedas *moeda[50];          /*50 moedas*/

    srand(time(NULL));

    for(int i=0; i<2; i+=fim){

        while((pacman.local.y-1 != parede.local.y && pacman.local.x != parede.local.x) && pacman.andar=='w'){
            pacman.local.y--;                           /*andar pra cima*/
            sleep(1);                                   /*Cooldown para andar*/
        }
        while((pacman.local.x+1 != parede.local.x && pacman.local.y != parede.local.y) && pacman.andar=='a'){
            pacman.local.x--;                           /*andar pra esquerda*/
            sleep(1);                                   /*Cooldown para andar*/
        }
        while((pacman.local.y+1 != parede.local.y && pacman.local.x != parede.local.x) && pacman.andar=='s'){
            pacman.local.y++;                           /*andar pra baixo*/
            sleep(1);                                   /*Cooldown para andar*/
        }
        while((pacman.local.x+1 != parede.local.x && pacman.local.y != parede.local.y) && pacman.andar=='d'){
            pacman.local.x++;                           /*andar pra direita*/
            sleep(1);                                   /*Cooldown para andar*/
        }

        for(int i=0; i<4; i++){
            if(fantasma[i].vida == 1){
                assombrar(&fantasma[i]);                /*funcao para o fantasma andar(no meio do jogo)*/
            }
        }

        for(int i=0; i<4; i++){
            if((pacman.local.x == fantasma[i].local.x && pacman.local.y == fantasma[i].local.y) && pacman.poder == 0){  /*GAME OVER*/

            }
        }

        for(int i=0; i<4; i++){
            if((pacman.local.x == fantasma[i].local.x && pacman.local.y == fantasma[i].local.y) && pacman.poder == 1){ /*kill fantasma*/
            score.pontos += 50;
            fantasma[i].vida = 0;
            }
        }
        
        for(int i=0; i<50; i++){
            if(moeda[i]->local.x == pacman.local.x && moeda[i]->local.y == pacman.local.y){         /*Coletar Moeda*/
                score.pontos += 10;
                free(moeda[i]);
                total_moedas+=1;
            }
        }

        for(int i=0; i<5;){
            if(fruta[i]->local.x == pacman.local.x && fruta[i]->local.y == pacman.local.y){         /*Coletar Fruta*/
                score.pontos += 25;
                pacman.poder = 1;
                sleep(10);                          /*Tempo de poder*/
                pacman.poder = 0;
            }
        }

        if(total_moedas == 50) break;               /*Fim da Fase*/
    }
    return 0;
}