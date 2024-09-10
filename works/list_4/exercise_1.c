#include <stdio.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL, "Portuguese");
    int a, b;
    printf("Escreva dois números: ");
    scanf("%d %d", &a, &b);
    if(a>b) a=b;
    printf("%d", a);
    return a;
}