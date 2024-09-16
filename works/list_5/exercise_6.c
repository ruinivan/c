#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int n, i;
    float a[n], b[n], soma[n];
    printf("Qual o tamanho do vetor? ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("%dº número do vetor a: ", i+1);
        scanf("%f", &a[i]);
    }
    for(i=0;i<n;i++){
        printf("%dº número do vetor b: ", i+1);
        scanf("%f", &b[i]);
    }
    for(i=0;i<n;i++){
        soma[i] = a[i] + b[i];
        printf("%.1f + %.1f = %.1f\n", a[i], b[i], soma[i]);
    }
    return 0;
}