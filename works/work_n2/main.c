#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "pacman.h"

void carregar_fase(int fase, int parede[25][25]) {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            parede[i][j] = 0; // Limpa o mapa
        }
    }
    if (fase == 0) {
        // Fase 1: Paredes externas e um obstáculo no meio
        for (int i = 0; i < 25; i++) {
            parede[0][i] = parede[24][i] = 1;
            parede[i][0] = parede[i][24] = 1;
        }
        for (int i = 8; i < 16; i++) {
            parede[12][i] = 1;
        }
    } else if (fase == 1) {
        // Fase 2: Labirinto com caminhos estreitos
        for (int i = 0; i < 25; i++) {
            parede[0][i] = parede[24][i] = 1;
            parede[i][0] = parede[i][24] = 1;
        }
        for (int i = 5; i < 20; i++) {
            parede[i][10] = 1;
            parede[i][15] = 1;
        }
    } else if (fase == 2) {
        // Fase 3: Paredes em padrão circular
        for (int i = 0; i < 25; i++) {
            parede[0][i] = parede[24][i] = 1;
            parede[i][0] = parede[i][24] = 1;
        }
        for (int i = 5; i < 20; i++) {
            parede[5][i] = parede[20][i] = 1;
        }
        for (int i = 10; i < 15; i++) {
            parede[i][5] = parede[i][20] = 1;
        }
    }
}

void inicializar_moedas(moedas *moeda[], int quant_moeda, int parede[25][25]) {
    for (int i = 0; i < quant_moeda; i++) {
        moeda[i] = (moedas *)malloc(sizeof(moedas));
        do {
            moeda[i]->local.x = rand() % 25;
            moeda[i]->local.y = rand() % 25;
        } while (parede[moeda[i]->local.x][moeda[i]->local.y] == 1);
    }
}

void inicializar_frutas(frutas *fruta[], int quant_frutas, int parede[25][25]) {
    for (int i = 0; i < quant_frutas; i++) {
        fruta[i] = (frutas *)malloc(sizeof(frutas));
        do {
            fruta[i]->local.x = rand() % 25;
            fruta[i]->local.y = rand() % 25;
        } while (parede[fruta[i]->local.x][fruta[i]->local.y] == 1);
    }
}

void desenhar_mapa(int parede[25][25], fantasmas fantasma[], moedas *moeda[], frutas *fruta[], int quant_moeda, int quant_frutas) {
    system("cls"); // Limpa o console no Windows
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            if (parede[i][j] == 1) {
                printf("#"); // Parede
            } else {
                int desenhado = 0;
                // Verifica fantasmas
                for (int f = 0; f < 4; f++) {
                    if (fantasma[f].local.x == i && fantasma[f].local.y == j && fantasma[f].vida) {
                        printf("F");
                        desenhado = 1;
                        break;
                    }
                }
                // Verifica moedas
                for (int m = 0; m < quant_moeda && !desenhado; m++) {
                    if (moeda[m] && moeda[m]->local.x == i && moeda[m]->local.y == j) {
                        printf("o");
                        desenhado = 1;
                    }
                }
                // Verifica frutas
                for (int fr = 0; fr < quant_frutas && !desenhado; fr++) {
                    if (fruta[fr] && fruta[fr]->local.x == i && fruta[fr]->local.y == j) {
                        printf("0");
                        desenhado = 1;
                    }
                }
                // Verifica Pacman
                if (!desenhado && pacman.local.x == i && pacman.local.y == j) {
                    printf("@");
                    desenhado = 1;
                }
                // Espaço vazio
                if (!desenhado)
                    printf(" ");
            }
        }
        printf("\n");
    }
}

void mover_pacman(int parede[25][25], int andar_cooldown) {
    if (_kbhit()) {
        char tecla = _getch();
        switch (tecla) {
            case 'w':
                if (parede[pacman.local.x - 1][pacman.local.y] == 0)
                    pacman.local.x--;
                break;
            case 'a':
                if (parede[pacman.local.x][pacman.local.y - 1] == 0)
                    pacman.local.y--;
                break;
            case 's':
                if (parede[pacman.local.x + 1][pacman.local.y] == 0)
                    pacman.local.x++;
                break;
            case 'd':
                if (parede[pacman.local.x][pacman.local.y + 1] == 0)
                    pacman.local.y++;
                break;
        }
        Sleep(andar_cooldown * 1000);
    }
}
int main(){
    int moedas_coletadas = 0, quant_moeda = 50;             /*config quantia das moedas*/
    int quant_frutas = 5, tempo_poder = 10;                 /*config das frutas*/
    int andar_cooldown = 0.5;                               /*tempo pra andar*/
    int score = 0;
    pacman.poder = 0;
    int fase=0;
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
    pacman.local.x = 1;
    pacman.local.y = 1;
    carregar_fase(fase, parede);
    srand(time(NULL));
   while (moedas_coletadas < quant_moeda) {
        mover_pacman(parede, andar_cooldown);
        desenhar_mapa(parede, fantasma, moeda, fruta, quant_moeda, quant_frutas);
        for (int i = 0; i < quant_moeda; i++) {
            if (moeda[i] && moeda[i]->local.x == pacman.local.x && moeda[i]->local.y == pacman.local.y) {
                score += 10;
                free(moeda[i]);
                moeda[i] = NULL;
                moedas_coletadas++;
            }
        }
        for (int i = 0; i < quant_frutas; i++) {
            if (fruta[i] && fruta[i]->local.x == pacman.local.x && fruta[i]->local.y == pacman.local.y) {
                score += 25;
                free(fruta[i]);
                fruta[i] = NULL;
                pacman.poder = 1;
                Sleep(tempo_poder * 1000);
                pacman.poder = 0;
            }
        }
    }
    printf("Parabéns! Você completou o jogo com %d pontos!\n", score);
    return 0;
}