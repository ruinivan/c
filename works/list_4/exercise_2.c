#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float de, x[3], y[3];
    int i;
    for(i=1;i<3;i++){
        printf("Digite o valor de x%d e y%d: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }
    de = sqrt(((x[2]-x[1])*(x[2]-x[1]))+((y[2]-y[1])*(y[2]-y[1])));
    printf("A distância euclidiana é de %.2f", de);
    return 0;
}