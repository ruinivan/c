#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int i;
    float q[20];
    for(i=0;i<20;i++){
        printf("Informe o %dº número: ", i+1);
        scanf("%f", &q[i]);
    }
    for(i=19;i>=0;i--){
        printf("%.1f --> ", q[i]);
    }
    return 0;
}