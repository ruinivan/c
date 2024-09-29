#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "remove.h"

int main(){
    char codigo[101], aux[3];
    int quantidade=0, b, value;
    system("chcp 850 > nul"); //A tabela ascii por padrao nao contem totalmente as nossas acentuacoes e nossas letras
    do{
        printf("Quantos codigos: ");
        scanf("%d", &quantidade);
        if(quantidade<=0 || quantidade>10000) printf("A quantia pode estar somente entre 0 e 10000\n");
    }while(quantidade<=0 || quantidade>10000);
    for(int m=0;m<quantidade;m++){
        do{
            printf("Informe o codigo da inteligencia: ");
            scanf("%d", &b);
            getchar(); //Limpar o buffer
            if(b< -100 || b>100) printf("O codigo de inteligencia so pode entre entre -100 e 100\n");
        }while(b< -100 || b>100);
        printf("Informe o codigo: ");
        fgets(codigo, 101, stdin);
        codigo[strcspn(codigo, "\n")] = "\0"; //Maneira melhor de tirar o enter da string e finalizar ela
        for(int i=0;i<(int)strlen(codigo);i+=2){
            aux[0]=codigo[i];
            aux[1]=codigo[i+1];
            aux[2] = '\0'; //Finalizar a string
            if(codigo[i]=='0' && codigo[i+1]=='0') break;
            value=strtol(aux, NULL, 16);
            if(func_val((i/2)+1, b)!=0 && ((value >= 32 && value <= 126) || (value >= 128 && value <= 255))) printf("%c", (char)value); //A função exclui caracteres indesejados e os outros dois parametros do if confirma que o caracter esta dentro dos desejados
        }
        printf("\n");
    }
    return 0;
}