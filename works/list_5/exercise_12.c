#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float v[30], n;
    int i, r=0;
    srand(time(NULL));
    for(i=0;i<30;i++){
        printf("Digite o %dº número: ", i+1);
        scanf("%f", &v[i]);
    };
    printf("Digite um número: ");
    scanf("%f", &n);
    for(i=0;i<30;i++) (n==v[i]) ? r++ : r;
    printf("Esse número se repete %d vezes", r);
    return 0;
}