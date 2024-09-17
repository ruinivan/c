#include <stdio.h>
#include <locale.h>

float troca(float *a, float *b){
    float temp;
    temp=*a;
    *a=*b;
    *b=temp;
    return 0;
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    int i, j;
    float n[11];
    for(i=0;i<10;i++){
        printf("%dº Número: ", i+1);
        scanf("%f", &n[i]);
    }
    for(i=0;i<10;i++){
        for(j=0;j<9;j++){
            if (n[j]>n[j+1]) troca(&n[j], &n[j+1]);
        }
    }
    for(i=0;i<10;i++){
        printf("%d --> %.1f\n", i+1, n[i]);
    }
    printf("Digite mais um valor: ");
    scanf("%f", &n[10]);
    for(i=0;i<11;i++){
        for(j=0;j<10;j++){
            if (n[j]>n[j+1]) troca(&n[j], &n[j+1]);
        }
    }
    for(i=0;i<11;i++){
        printf("%d --> %.1f\n", i+1, n[i]);
    }
    return 0;
}