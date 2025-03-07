#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
}player;

int main(){
    player player1, player2;
    int tabela[3][3], a, b, ganhou_x = 0, ganhou_o = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabela[i][j] = 0;
        }
    }
    printf("BEM-VINDO AO JOGO DA VELHA!!! \n");
    printf("Nome do primeiro jogador: ");
    fgets(player1.nome, 20, stdin);
    for(int i = 0; i < strlen(player1.nome); i++) if(player1.nome[i]=='\n') player1.nome[i] = '\0';
    printf("Nome do segundo jogador: ");
    fgets(player2.nome, 20, stdin);
    for(int i = 0; i < strlen(player2.nome); i++) if(player2.nome[i]=='\n') player1.nome[i] = '\0';
    for(int i = 0; i < 9; i++){
        printf("\tROUND %d\n", i+1);
        for(int j = 0; j < 3; j++){
            for(int l = 0; l < 3; l++){
                if(tabela[j][l]==0) printf("  | ");
                if(tabela[j][l]==1) printf("X | ");
                if(tabela[j][l]==2) printf("O | ");
            }
            printf("\n");
        }
        do{
            printf("Jogada %d: ", i+1);
            scanf("%d %d", &a, &b); 
        }while(tabela[a][b]!=0 || a < 0 || a > 2 || b < 0 || b > 2);
        (i % 2) ? tabela[a][b] = 2 : tabela[a][b]++;
        for(int j = 0; j < 3; j++){
            for(int l = 0; l < 3; l++){
                if(tabela[j][l]==1) ganhou_x++;
                if(tabela[j][l]==2) ganhou_o++;
            }
            if(ganhou_x==3){
                printf("O jogador %s GANHOU!!!\n", player1.nome);
                printf("FIM DE JOGO!!!");
                exit(0);
            }
            if(ganhou_o==3){
                printf("O jogador %s GANHOU!!!\n", player2.nome);
                printf("FIM DE JOGO!!!");
                exit(0);
            }
            ganhou_x = 0;
            ganhou_o = 0;
        }
        for(int j = 0; j < 3; j++){
            for(int l = 0; l < 3; l++){
                if(tabela[l][j]==1) ganhou_x++;
                if(tabela[l][j]==2) ganhou_o++;
            }
            if(ganhou_x==3){
                printf("O jogador %s GANHOU!!!\n", player1.nome);
                printf("FIM DE JOGO!!!");
                exit(0);
            }
            if(ganhou_o==3){
                printf("O jogador %s GANHOU!!!\n", player2.nome);
                printf("FIM DE JOGO!!!");
                exit(0);
            }
            ganhou_x = 0;
            ganhou_o = 0;
        }
        if((tabela[0][0]==1 && tabela[1][1]==1 && tabela[2][2]==1) || (tabela[0][2]==1 && tabela[1][1]==1 && tabela[2][0]==1)){
            printf("O jogador %s GANHOU!!!\n", player1.nome);
            printf("FIM DE JOGO!!!");
            exit(0);
        }
        if((tabela[0][0]==2 && tabela[1][1]==2 && tabela[2][2]==2) || (tabela[0][2]==2 && tabela[1][1]==2 && tabela[2][0]==2)){
            printf("O jogador %s GANHOU!!!\n", player2.nome);
            printf("FIM DE JOGO!!!");
            exit(0);
        }
    }
}