#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    float m[3][3];
    int i, j, d, e, det;
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
    d=(m[0][0]*m[1][1]*m[2][2])+(m[0][1]*m[1][2]*m[2][0])+(m[0][2]*m[1][0]*m[2][1]);
    e=(m[0][2]*m[1][1]*m[2][0])+(m[0][0]*m[1][2]*m[2][1])+(m[0][1]*m[1][0]*m[2][2]);
    det=d-e;
    printf("A determinante da Matriz é: %d", det);
    return 0;
}