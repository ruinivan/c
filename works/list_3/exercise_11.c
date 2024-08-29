#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int n, i;
    do{
    printf("Digite um número: ");
    scanf("%d", &n);
    }while(n<=0);
    for(i=1;i<=n;i++){
        printf("%d ", i);
    }
    return 0;
}