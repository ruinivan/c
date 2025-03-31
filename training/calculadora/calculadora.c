#include <stdio.h>
#include "funcoes.h"

int main(){
    float m, n;
    int dnv;
    char opr;
    printf("==========CALCULADORA==========");
    do{
        opr = menu();
        printf("Digite os dois numeros: ");
        scanf("%f %f", &m, &n);
        switch(opr){
            case '+':
                printf("%.2f %c %.2f: %.2f", m, opr, n, soma(m,n));
                break;
            case '-':
                printf("%.2f %c %.2f: %.2f", m, opr, n, sub(m,n));
                break;
            case '*':
                printf("%.2f %c %.2f: %.2f", m, opr, n, mult(m,n));
                break;
            case '/':
                if(n!=0){
                    printf("%.2f %c %.2f: %.f", m, opr, n, div(m,n));
                    break;
                } else{
                    printf("O denominador nao pode ser 0");
                    break;
                }
        }
        printf("\nDeseja efetuar outro calculo? (SIM: 1 / NAO: 0) ");
        scanf("%d", &dnv);
    }while(dnv==1);
    printf("FIM DE CALCULO );");
    return 0;
}