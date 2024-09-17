#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float v1[15], v2[15];
    int i, q=0;
    for(i=0;i<15;i++){
        printf("%dº número de V1: ", i+1);
        scanf("%f", &v1[i]);
    }
    for(i=0;i<15;i++){
        printf("%dº número de V2: ", i+1);
        scanf("%f", &v2[i]);
    }
    for(i=0;i<15;i++) (v1[i]==v2[i]) ? q++ : q;
    printf("%d é a quantidade de repetição", q);
    return 0;
}