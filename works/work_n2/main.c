#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define ALTURA 10
#define LARGURA 21
#define FASES 5

typedef struct {
    int x, y;
} coordenadas;

typedef struct {
    coordenadas posicao;
    int vivo;
} fantasma_t;

typedef struct {
    coordenadas posicao;
    int poderoso;
    int vidas;
} pacman_t;

// Mapas das fases
char mapas[FASES][ALTURA][LARGURA] = {
    {
        "###################",
        "#........#........#",
        "#.####.#.#.####.#.#",
        "#o#  #.#.#.#  #.#o#",
        "#.####.###.####.#.#",
        "#.................#",
        "###.###.#.#.###.###",
        "  #.# o.#.#.o.#.#  ",
        "  #.# #########.#  ",
        "###################"
    },
    {
        "###################",
        "#........#........#",
        "#.##o..#.#.#....#.#",
        "#.#  #.#.#.#.o..#.#",
        "#.####.###.####.#.#",
        "#o...............o#",
        "#.#.###.#.#.###.#.#",
        "#.#.o...#.#.o...#.#",
        "#.#.###########.#.#",
        "###################"
    },
    {
        "###################",
        "#.................#",
        "#.#.###.#####.#.#.#",
        "#.#...........#...#",
        "#.###.#.#######.#.#",
        "#..o..#...o.....#.#",
        "#.##########.##..#a#",
        "#.#..........#....#",
        "#...#######o.#.o..#",
        "###################"
    },
    {
        "###################",
        "#........#........#",
        "#o####.###.######.#",
        "#.#..#.....#...o..#",
        "#.#.####.####.###.#",
        "#.#...........#...#",
        "#.#.###########.#.#",
        "#.#...........o.#o#",
        "#...###########.#.#",
        "###################"
    },
    {
        "###################",
        "#.......#.........#",
        "#.#.#.#.#.#.###.#.#",
        "#.#.#.#o#.#.#o..#.#",
        "#.#.#.###.#.#####.#",
        "#.#...........#...#",
        "#.#####.#.#####.#.#",
        "#.#o....#.......#.#",
        "#.#.###########.#o#",
        "###################"
    }
};

fantasma_t fantasmas[4];
pacman_t pacman;

int fase_atual = 0;
int pontos = 0;
int moedas_restantes = 0;
int frutas_tempo = 0;

void inicializar_jogo() {
    // Inicializa Pac-Man
    pacman.posicao.x = 1;
    pacman.posicao.y = 1;
    pacman.poderoso = 0;
    pacman.vidas = 3;

    // Inicializa fantasmas
    fantasmas[0].posicao.x = 5;
    fantasmas[0].posicao.y = 10;
    fantasmas[1].posicao.x = 5;
    fantasmas[1].posicao.y = 9;
    fantasmas[2].posicao.x = 5;
    fantasmas[2].posicao.y = 11;
    fantasmas[3].posicao.x = 5;
    fantasmas[3].posicao.y = 8;
    for (int i = 0; i < 4; i++) {
        fantasmas[i].vivo = 1;
    }

    // Conta moedas no mapa da fase atual
    moedas_restantes = 0;
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            if (mapas[fase_atual][i][j] == '.') {
                moedas_restantes++;
            }
        }
    }
}

void desenhar_mapa() {
    system("cls");

    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            int desenhado = 0;

            // Verifica se há fantasmas
            for (int f = 0; f < 4; f++) {
                if (fantasmas[f].vivo && fantasmas[f].posicao.x == i && fantasmas[f].posicao.y == j) {
                    printf("F");
                    desenhado = 1;
                    break;
                }
            }

            // Verifica posição do Pac-Man
            if (!desenhado && pacman.posicao.x == i && pacman.posicao.y == j) {
                printf(pacman.poderoso ? "P" : "C");
                desenhado = 1;
            }

            // Desenha o mapa
            if (!desenhado) {
                printf("%c", mapas[fase_atual][i][j]);
            }
        }
        printf("\n");
    }

    printf("Pontos: %d  Vidas: %d  Fase: %d\n", pontos, pacman.vidas, fase_atual + 1);
}

void mover_pacman() {
    if (_kbhit()) {
        char tecla = _getch();
        int novo_x = pacman.posicao.x;
        int novo_y = pacman.posicao.y;

        // Processa entrada do jogador
        switch (tecla) {
            case 'w': novo_x--; break; // Cima
            case 's': novo_x++; break; // Baixo
            case 'a': novo_y--; break; // Esquerda
            case 'd': novo_y++; break; // Direita
        }

        // Verifica colisão com parede
        if (mapas[fase_atual][novo_x][novo_y] != '#') {
            pacman.posicao.x = novo_x;
            pacman.posicao.y = novo_y;

            // Verifica se Pac-Man comeu moeda
            if (mapas[fase_atual][novo_x][novo_y] == '.') {
                pontos += 10;
                moedas_restantes--;
                mapas[fase_atual][novo_x][novo_y] = ' ';
            }

            // Verifica se Pac-Man comeu fruta
            if (mapas[fase_atual][novo_x][novo_y] == 'o') {
                pontos += 50;
                pacman.poderoso = 1;
                frutas_tempo = 30; // Dura 30 ciclos
                mapas[fase_atual][novo_x][novo_y] = ' ';
            }
        }
    }
}

void mover_fantasmas() {
    for (int i = 0; i < 4; i++) {
        if (!fantasmas[i].vivo) continue;

        int direcao = rand() % 4;
        int novo_x = fantasmas[i].posicao.x;
        int novo_y = fantasmas[i].posicao.y;

        switch (direcao) {
            case 0: novo_x--; break; // Cima
            case 1: novo_x++; break; // Baixo
            case 2: novo_y--; break; // Esquerda
            case 3: novo_y++; break; // Direita
        }

        if (mapas[fase_atual][novo_x][novo_y] != '#' ) {
            fantasmas[i].posicao.x = novo_x;
            fantasmas[i].posicao.y = novo_y;
        }
    }
}

void verificar_colisoes() {
    for (int i = 0; i < 4; i++) {
        if (!fantasmas[i].vivo) continue;

        if (fantasmas[i].posicao.x == pacman.posicao.x &&
            fantasmas[i].posicao.y == pacman.posicao.y) {
            if (pacman.poderoso) {
                fantasmas[i].vivo = 0;
                pontos += 200;
                
                //revivendo os fantasmas que o pacman matou by:Vitor
                fantasmas[i].posicao.x = 1; 
                fantasmas[i].posicao.y = 16; 
                fantasmas[i].vivo = 1;
            } else {
                pacman.vidas--;
                pacman.posicao.x = 1;
                pacman.posicao.y = 1;

                if (pacman.vidas <= 0) {
                	Sleep(3000);
                    printf("Game Over! Pontuação final: %d\n", pontos);
                    exit(0);
                }
            }
        }
    }
}

void proxima_fase() {
    fase_atual++;
    if (fase_atual >= FASES) {
        printf("Parabéns! Você completou o jogo com %d pontos!\n", pontos);
        Sleep(2000);
        exit(0);
    }
    inicializar_jogo();
}

void atualizar_jogo() {
	verificar_colisoes();
    if (pacman.poderoso) {
        frutas_tempo--;
        if (frutas_tempo <= 0) {
            pacman.poderoso = 0;
        }
    }
    mover_pacman();
    verificar_colisoes();
    mover_fantasmas();
    verificar_colisoes();

    if (moedas_restantes == 0) {
        proxima_fase();
    }
}
int main() {
    srand(time(NULL));
    inicializar_jogo();

    while (1) {
        desenhar_mapa();
        atualizar_jogo();
        Sleep(100); // Controle da velocidade
    }

    return 0;
}