#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int i;
    float x, a[10], m[10];
    for(i=0;i<10;i++){
        printf("%dº Número de A: ", i+1);
        scanf("%f", &a[i]);
    }
    printf("Qual será o número que irá multiplica-los: ");
    scanf("%f", &x);
    for(i=0;i<10;i++){
        m[i]=a[i]*x;
        printf("%dº %.1f * %.1f = %.1f\n", i+1, x, a[i], m[i]);
    }
    return 0;
}