#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "pacman.h"

void assombrar(fantasmas *fantasma, int parede[25][25], int andar_cooldown){    /*Fantasma vivo andar aleatoriamente*/ 
    int andar = rand() % 4;
    switch (andar){
    case 0:
        while(parede[fantasma->local.x][fantasma->local.y-1]==0 && parede[fantasma->local.x-1][fantasma->local.y]==1 && parede[fantasma->local.x-1][fantasma->local.y]==1){
            fantasma->local.y--;                            /*fantasma pra cima*/
            sleep(andar_cooldown);
        }
        break;
    case 1:
        while(parede[fantasma->local.x-1][fantasma->local.y]==0 && parede[fantasma->local.x][fantasma->local.y-1]==1 && parede[fantasma->local.x][fantasma->local.y+1]==1){
            fantasma->local.x--;                            /*fantasma pra esquerda*/
            sleep(andar_cooldown);
        }
        break;
    case 2:
        while(parede[fantasma->local.x][fantasma->local.y+1]==0 && parede[fantasma->local.x-1][fantasma->local.y]==1 && parede[fantasma->local.x+1][fantasma->local.y]==1){
            fantasma->local.y++;                            /*fantasma pra baixo*/
            sleep(andar_cooldown);
        }
        break;
    case 3:
        while(parede[fantasma->local.x+1][fantasma->local.y]==0 && parede[fantasma->local.x][fantasma->local.y-1]==1 && parede[fantasma->local.x][fantasma->local.y+1]==1){
            fantasma->local.x++;                            /*fantasma pra direita*/
            sleep(andar_cooldown);
        }
        break;
    default:
        break;
    }
}

int main(){
    int moedas_coletadas = 0, quant_moeda = 50;             /*config quantia das moedas*/
    int quant_frutas = 5, tempo_poder = 10;                 /*config das frutas*/
    int andar_cooldown = 0.5;                               /*tempo pra andar*/
    int score = 0;
    pacman.poder = 0;

    int parede[25][25];                                     /*criação das paredes*/

    for(int i=0; i<25; i++){
        for(int j=0; j<25; j++){
            parede[i][j]=0;                                 /*esvaziando o lugar*/
        }
    }

    for(int i=0; i<25; i++){
        for(int j=0; i<25;j++){                             /*declarando as bordas*/
            parede[0][j]=1;
            parede[i][0]=1;
            parede[24][j]=1;
            parede[i][24]=1;
        }
    }

    fantasmas fantasma[4];                                  /*4 fantasmas*/
    for(int i=0; i<4; i++) fantasma[i].vida = 1;

    frutas *fruta[quant_frutas];                            /*frutas*/
    moedas *moeda[quant_moeda];                             /*moedas*/

    srand(time(NULL));

    if(moedas_coletadas < quant_moeda){

        while(parede[pacman.local.x][pacman.local.y-1]==0 && pacman.andar=='w'){
            pacman.local.y--;                               /*andar pra cima*/
            sleep(andar_cooldown);                          /*Cooldown para andar*/
        }
        while(parede[pacman.local.x-1][pacman.local.y]==0 && pacman.andar=='a'){
            pacman.local.x--;                               /*andar pra esquerda*/
            sleep(andar_cooldown);                          /*Cooldown para andar*/
        }
        while(parede[pacman.local.x][pacman.local.y+1]==0 && pacman.andar=='s'){
            pacman.local.y++;                               /*andar pra baixo*/
            sleep(andar_cooldown);                          /*Cooldown para andar*/
        }
        while(parede[pacman.local.x+1][pacman.local.y]==0 && pacman.andar=='d'){
            pacman.local.x++;                               /*andar pra direita*/
            sleep(andar_cooldown);                          /*Cooldown para andar*/
        }

        for(int i=0; i<4; i++){
            if(fantasma[i].vida == 1){
                assombrar(&fantasma[i], parede, andar_cooldown);        /*funcao para o fantasma andar(no meio do jogo)*/
            }
        }

        for(int i=0; i<4; i++){
            if((pacman.local.x == fantasma[i].local.x && pacman.local.y == fantasma[i].local.y) && pacman.poder == 0){  /*GAME OVER*/

            }
        }

        for(int i=0; i<4; i++){
            if((pacman.local.x == fantasma[i].local.x && pacman.local.y == fantasma[i].local.y) && pacman.poder == 1){ /*kill fantasma*/
            score += 50;
            fantasma[i].vida = 0;
            }
        }
        
        for(int i=0; i<quant_moeda; i++){
            if(moeda[i]->local.x == pacman.local.x && moeda[i]->local.y == pacman.local.y){         /*Coletar Moeda*/
                score += 10;
                free(moeda[i]);
                moedas_coletadas+=1;
            }
        }

        for(int i=0; i<5;){
            if(fruta[i]->local.x == pacman.local.x && fruta[i]->local.y == pacman.local.y){         /*Coletar Fruta*/
                score += 25;
                pacman.poder = 1;
                sleep(tempo_poder);                          /*Tempo de poder*/
                pacman.poder = 0;
            }
        }
    }
    return 0;
}