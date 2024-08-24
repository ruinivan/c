#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    signed int nun;
    printf("Digite um número: ");
    scanf("%d", &nun);
    if (nun>0) printf("Éste número é  positivo");
    else printf("Éste número é negativo");
    return 0;
}