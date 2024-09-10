#include <stdio.h>
#include <locale.h>

int potencia(int *bas, int exp){
    int i, temp;
    temp=*bas;
    for(i=1;i<exp;i++){
        *bas*=temp;
    }
    return 0;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int base, expoente, temp;
    printf("Digite a base da potência e o expoente: ");
    scanf("%d %d", &base, &expoente);
    temp = base;
    potencia(&base, expoente);
    printf("%d^%d: %d", temp, expoente, base);
    return 0;
}