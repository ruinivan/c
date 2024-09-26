#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    char senha[100];
    int ma=0, mi=0, n=0;
    while(ma==0 || mi==0 || (int)strlen(senha)<8 || n==0){
        printf("Digite sua senha: ");
        fgets(senha, 100, stdin);
        senha[strlen(senha)-1]='\0';
        for(int i=0; i<(int)strlen(senha);i++){
            ma += ((int)senha[i]>=65 && (int)senha[i]<=90) ? 1 : 0;
            mi += ((int)senha[i]>=97 && (int)senha[i]<=122) ? 1 : 0;
            n += ((int)senha[i]>=48 && (int)senha[i]<=57) ? 1 : 0;
        }
        if(ma==0 || mi==0 || (int)strlen(senha)<8 || n==0){
            printf("Sua senha não cumpre os requisitos mínimos: (1 letra maiúscula, 1 letra minúscula, 1 número e no mínimo 8 carácter)!\n");
        } else{
            printf("Senha registrada com SUCESSO!!!");
        }
    }
    return 0;
}