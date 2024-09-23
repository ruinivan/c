#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int m[3][3];
    int i, j, e, d, det;
    srand(time(NULL));
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            m[i][j] = rand() % 10;
        }
    }
    printf("MATRIZ\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    d=(m[0][0]*m[1][1]*m[2][2])+(m[0][1]*m[1][2]*m[2][0])+(m[0][2]*m[1][0]*m[2][1]);
    e=(m[0][2]*m[1][1]*m[2][0])+(m[0][0]*m[1][2]*m[2][1])+(m[0][1]*m[1][0]*m[2][2]);
    det=d-e;
    printf("O valor da determinante é: %d", det);
    return 0;
}