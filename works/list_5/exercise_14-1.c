#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int m[3][3];
    int i, j;
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
    return 0;
}