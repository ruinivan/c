#include <stdio.h>

int main(){
    int a[9], pr;
    char jogador1[20], jogador2[20];
    for(int i=0; i<9; i++) a[i] = 0;
    printf("Nome do jogador1(X): ");
    scanf("%s", jogador1);
    printf("Nome do jogador2(O): ");
    scanf("%s", jogador2);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(a[j]==0) printf("  |  ");
            if(a[j]==1) printf("X |  ");
            if(a[j]==2) printf("O |  ");
            if(j==2 || j==5) printf("\n");
        }
        printf("\n");
        printf("Jogada %d: ", i+1);
        scanf("%d", &pr);
        if(!(i%2)) a[pr] = 1;
        if(i%2) a[pr] = 2;
        if((a[0]==1 && a[1]==1 && a[2]==1) || (a[3]==1 && a[4]==1 && a[5]==1) || (a[6]==1 && a[7]==1 && a[8]==1) || (a[0]==1 && a[4]==1 && a[8]==1) || (a[2]==1 && a[4]==1 && a[6]==1)){
            printf("%s GANHOU!!!", jogador1); 
            break;
        } 
        if((a[0]==2 && a[1]==2 && a[2]==2) || (a[3]==2 && a[4]==2 && a[5]==2) || (a[6]==2 && a[7]==2 && a[8]==2) || (a[0]==2 && a[4]==2 && a[8]==2) || (a[2]==2 && a[4]==2 && a[6]==2)){
            printf("%s GANHOU!!!", jogador2); 
            break;
        }
    }
    printf("FIM DE JOGO!!!");
    return 0;
}