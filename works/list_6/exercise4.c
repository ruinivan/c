#include <stdio.h>
#include <string.h>
#include <locale.h>

void apagar(char *string, int tam){
    for(int i=0; i<tam; i++){
        *(string+i)=*(string+i+1);
    }
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    char string[100], palindromo[100];
    int i;
    printf("Escreva algo: ");
    fgets(string, 100, stdin);
    string[strlen(string)-1]='\0';
    int tam=strlen(string);
    for(i=0; i<(int)strlen(string);i++){
        if((int)string[i]>=65 && (int)string[i]<=90) string[i]=(int)string[i]+32, --i;
        if(string[i]==' ') apagar(&string[i], tam), --i;
        if(string[i]=='-') apagar(&string[i], tam), --i;
        if(string[i]==',') apagar(&string[i], tam), --i;
    }
    for(i=0;i<(int)strlen(string);i++){
        palindromo[i]=string[strlen(string)-i-1];
    }
    (strcmp(string, palindromo)==0) ? printf("É um palindromo: ") : printf("Não é um palindromo: ");
    printf("%s <--> %s", string, palindromo);
    return 0;
}