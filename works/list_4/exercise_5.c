#include <stdio.h>
#include <locale.h>

int somadivisores(int a, int *soma){
    int i;
    for(i=1;i<a;i++){
        *soma += (a%i==0) ? i : 0;
    }
    return 0;
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    int a, result=0;
    printf("Digite um número: ");
    do{
        scanf("%d", &a);
        if(a<=0) printf("Valor inválido, digite um número positivo: ");
    }while(a<=0);
    somadivisores(a, &result);
    printf("A soma dos divisores de %d é %d", a, result);
    return 0;
}