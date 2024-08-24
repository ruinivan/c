#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int nun1, nun2;
    printf("Digite um número: ");
    scanf("%d", &nun1);
    printf("Digite outro número: ");
    scanf("%d", &nun2);
    if (nun1>nun2) printf("%d, %d.", nun2, nun1);
    else printf("%d, %d.", nun1, nun2);
    return 0;
}