#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "remove.h"

int main(){
    char v[101], vaux[3];
    int n=0, m, b, i, value;
    do{
        printf("Quantos codigos: ");
        scanf("%d", &n);
        getchar(); //Limpar o buffer
        if(n<=0 || n>10000) printf("A quantia pode estar somente entre 0 e 10000\n");
    }while(n<=0 || n>10000);
    for(m=0;m<n;m++){
        do{
            printf("Informe o codigo da inteligencia: ");
            scanf("%d", &b);
            getchar(); //Limpar o buffer
            if(b<-100 || b>100) printf("O codigo de inteligencia so pode entre entre -100 e 100\n");
        }while(b<-100 || b>100);
        printf("Informe o codigo: ");
        fgets(v, 101, stdin);
        v[strcspn(v, "\n")] = 0; //Maneira melhor de tirar o enter da string e finalizar ela
        for(i=0;i<(int)strlen(v);i+=2){
            vaux[0]=v[i];
            vaux[1]=v[i+1];
            vaux[2] = '\0'; //Finalizar a string
            if(v[i]=='0' && v[i+1]=='0'){
                break;
            }
            if(func_val((i/2)+1, b)!=0){
                value=strtol(vaux, NULL, 16);
                if ((value >= 32 && value <= 126) || (value >= 128 && value <= 255)) printf("%c", (char)value);
            }
        }
        printf("\n");
    }
    return 0;
}