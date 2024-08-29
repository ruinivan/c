#include <stdio.h>
#include <locale.h>

int main(){
    int i, n=0;
    while(n<=0 || n>10){
        printf("Digite um numero: ");
        scanf("%d", &n);
    }
    for (i=1;i<=10;i++){
        printf("%d x %d: %d\n", n, i, n*i);
    }
    return 0;
}