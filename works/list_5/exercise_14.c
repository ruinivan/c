#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    float m[3][3];
    int i, j;
    for(i=0;i<3;i++){
        printf("%dª Coluna: \n", i+1);
        for(j=0;j<3;j++){
            printf("%dª linha: ", j+1);
            scanf("%f", &m[i][j]);
        }
    }
    printf("MATRIZ\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%.1f ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}