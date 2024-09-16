#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int i, j, r, p;
    float q[20], temp;
    for(r=0;r<20;r++){
        do{
            printf("Informe o %dº número: ", r+1);
            scanf("%f", &q[r]);
        }while(q[r]<0);
    }
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            temp = (q[j]>temp) ? q[j] : temp;
            p = (q[j]==temp) ? j : p; 
        }
    }
    printf("O maior número é %.2f e está na posição %d", temp, p+1);
    return 0;
}