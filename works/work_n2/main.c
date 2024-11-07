#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pacman.h"

int main(){
    int fim = 0;
    int total_moedas = 0;
    score.pontos = 0;
    pacman.poder = 0;
    fantasma fantasma[4];       /*4 fantasmas*/
    frutas *fruta[5];           /*5 frutas*/
    moedas *moeda[50];          /*50 moedas*/

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

        if(((pacman.local.x == fantasma[0].local.x && pacman.local.y == fantasma[0].local.y) || (pacman.local.x == fantasma[1].local.x && pacman.local.y == fantasma[1].local.y) || (pacman.local.x == fantasma[2].local.x && pacman.local.y == fantasma[2].local.y) || (pacman.local.x == fantasma[3].local.x && pacman.local.y == fantasma[3].local.y)) && pacman.poder == 0) /*GAME OVER*/ {
        
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