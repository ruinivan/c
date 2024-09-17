#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    float n[10], n1[10], nn;
    int i;
    for(i=0;i<10;i++){
        printf("%dº número: ", i+1);
        scanf("%f", &n[i]);
    }
    printf("Digite um número para excluir: ");
    scanf("%f", &nn);
    for(i=0;i<10;i++) n1[i] = (n[i]!=nn) ? n[i] : 0;
    for(i=0;i<10;i++){
        if (n1[i]!=0) printf("%d --> %.1f ", i, n1[i]);
    }
    return 0;
}