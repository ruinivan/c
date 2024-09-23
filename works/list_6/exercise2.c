#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    char string[100];
    int i, t1, t2=0;
    printf("Escreva algo: ");
    fgets(string, 100, stdin);
    t1=strlen(string)-1;
    string[strlen(string)-1]='\0';
    printf("O tamanho usando o strlen é de: %d\n", t1);
    for(i=0;i<100;i++){
        if(string[i]=='\0'){
            t2 = i;
            break;
        }
    }
    printf("E sem usar o strlen é: %d", t2);
    return 0;
}