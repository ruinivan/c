#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "pacman.h"

void carregar_fase(int fase, int parede[10][50]) {
    if (fase == 0) {
        // Fase 1: Paredes externas e um obstáculo no meio
        for (int i = 8; i < 16; i++) {
            parede[12][i] = 1;
        }
    } else if (fase == 1) {
        // Fase 2: Labirinto com caminhos estreitos
        for (int i = 5; i < 20; i++) {
            parede[i][10] = 1;
            parede[i][15] = 1;
        }
    } else if (fase == 2) {
        // Fase 3: Paredes em padrão circular
        for (int i = 5; i < 20; i++) {
            parede[5][i] = parede[20][i] = 1;
        }
        for (int i = 10; i < 15; i++) {
            parede[i][5] = parede[i][20] = 1;
        }
    }
}

void inicializar_moedas(moedas *moeda[], int quant_moeda, int parede[10][50]) {
    for (int i = 0; i < quant_moeda; i++) {
        moeda[i] = (moedas *)malloc(sizeof(moedas));
        do {
            moeda[i]->local.x = rand() % 25;
            moeda[i]->local.y = rand() % 25;
        } while (parede[moeda[i]->local.x][moeda[i]->local.y] == 1);
    }
}

void inicializar_frutas(frutas *fruta[], int quant_frutas, int parede[10][50]) {
    for (int i = 0; i < quant_frutas; i++) {
        fruta[i] = (frutas *)malloc(sizeof(frutas));
        do {
            fruta[i]->local.x = rand() % 25;
            fruta[i]->local.y = rand() % 25;
        } while (parede[fruta[i]->local.x][fruta[i]->local.y] == 1);
    }
}

void desenhar_mapa(int parede[10][50], fantasmas fantasma[], moedas *moeda[], frutas *fruta[], int quant_moeda, int quant_frutas) {
    system("cls"); // Limpa o console no Windows
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
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
                for (int m = 0; m < quant_moeda; m++) {
                    if (!desenhado && moeda[m] && moeda[m]->local.x == i && moeda[m]->local.y == j) {
                        printf("o");
                        desenhado = 1;
                    }
                }
                // Verifica frutas
                for (int fr = 0; fr < quant_frutas; fr++) {
                    if (!desenhado && fruta[fr] && fruta[fr]->local.x == i && fruta[fr]->local.y == j) {
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
void mover_pacman(int parede[10][50]) {
    if (_kbhit()) {
        char tecla = _getch();  // Usa _getch() ao invés de getch()
        switch (tecla) {
            case 'w': // Cima
                if (pacman.local.x > 0 && parede[pacman.local.x - 1][pacman.local.y] == 0)
                    pacman.local.x--;
                break;
            case 'a': // Esquerda
                if (pacman.local.y > 0 && parede[pacman.local.x][pacman.local.y - 1] == 0)
                    pacman.local.y--;
                break;
            case 's': // Baixo
                if (pacman.local.x < 9 && parede[pacman.local.x + 1][pacman.local.y] == 0)
                    pacman.local.x++;
                break;
            case 'd': // Direita
                if (pacman.local.y < 49 && parede[pacman.local.x][pacman.local.y + 1] == 0)
                    pacman.local.y++;
                break;
        }
    }
}
void mover_fantasmas(fantasmas *fantasmas, int num_fantasmas, int parede[10][50]) {
    for (int i = 0; i < num_fantasmas; i++) {
        int direcao = rand() % 4;
        switch (direcao) {
            case 0: // Cima
                if (fantasmas[i].local.x > 0 && parede[fantasmas[i].local.x - 1][fantasmas[i].local.y] == 0)
                    fantasmas[i].local.x--;
                break;
            case 1: // Esquerda
                if (fantasmas[i].local.y > 0 && parede[fantasmas[i].local.x][fantasmas[i].local.y - 1] == 0)
                    fantasmas[i].local.y--;
                break;
            case 2: // Baixo
                if (fantasmas[i].local.x < 9 && parede[fantasmas[i].local.x + 1][fantasmas[i].local.y] == 0)
                    fantasmas[i].local.x++;
                break;
            case 3: // Direita
                if (fantasmas[i].local.y < 49 && parede[fantasmas[i].local.x][fantasmas[i].local.y + 1] == 0)
                    fantasmas[i].local.y++;
                break;
        }
    }
}
int main() {
    int moedas_coletadas = 0, quant_moeda = 50;
    int quant_frutas = 5, tempo_poder = 10;
    int andar_cooldown = 500;
    int score = 0;
    int fase = 0;
    int parede[10][50];

    // Inicializa o mapa vazio
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            parede[i][j] = 0;
        }
    }

    // Criação das bordas
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            parede[0][j] = 1;
            parede[i][0] = 1;
            parede[9][j] = 1;
            parede[i][49] = 1;
        }
    }

    fantasmas fantasma[4];
    for (int i = 0; i < 4; i++) {
        fantasma[i].local.x = rand() % 10;
        fantasma[i].local.y = rand() % 50;
        fantasma[i].vida = 1;
    }

    frutas *fruta[quant_frutas];
    moedas *moeda[quant_moeda];
    pacman.local.x = 1;
    pacman.local.y = 1;

    srand(time(NULL));

    // Inicializa moedas e frutas
    inicializar_moedas(moeda, quant_moeda, parede);
    inicializar_frutas(fruta, quant_frutas, parede);
    carregar_fase(fase, parede);

    // Loop principal do jogo
    while (fase < 5) {
        desenhar_mapa(parede, fantasma, moeda, fruta, quant_moeda, quant_frutas);
        mover_pacman(parede); // Movimento do Pacman
        mover_fantasmas(fantasma, 4, parede); // Movimento dos fantasmas

        // Coleta moedas
        for (int i = 0; i < quant_moeda; i++) {
            if (moeda[i] && moeda[i]->local.x == pacman.local.x && moeda[i]->local.y == pacman.local.y) {
                score += 10;
                free(moeda[i]);
                moeda[i] = NULL;
                moedas_coletadas++;
            }
        }

        // Coleta frutas
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

        // Verifica progressão de fase
        if (moedas_coletadas >= quant_moeda) {
            printf("Você completou a fase %d!\n", fase + 1);
            fase++;
            moedas_coletadas = 0;
            inicializar_moedas(moeda, quant_moeda, parede);
            inicializar_frutas(fruta, quant_frutas, parede);
        }

        Sleep(100); // Tempo entre as atualizações (suave para o console)
    }

    printf("Parabéns! Você completou o jogo com %d pontos!\n", score);
    return 0;
}