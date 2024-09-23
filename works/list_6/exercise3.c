#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    char string[100], gnirts[100];
    int i;
    printf("Escreva algo: ");
    fgets(string,100,stdin);
    string[strlen(string)-1]='\0';
    for(i=0;i<(int)strlen(string);i++){
        gnirts[strlen(string)-i-1]=string[i];
    }
    printf("Ao contrario fica: %s", gnirts);
    return 0;
}