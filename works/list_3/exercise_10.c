#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int n, i;
    printf("Digite um número: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        printf("%d ", i);
    }
    return 0;
}