#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float b, x, a0, a1, a2, a3, a4, a5, a6, a7;
    char v[101], vaux[2];
    int i;
    long int vr[50];
    printf("Informe o código: ");
    fgets(v, 100, stdin);
    v[strlen(v)-1]='\0';
    for(i=0;i<(int)strlen(v);i++){
        vaux[0]=v[i];
        vaux[1]=v[i+1];
        if(v[i]=='0' && v[i+1]=='0'){
            vr[i/2]='\0';
            break;
        }
        vr[i/2]=strtol(vaux, NULL, 16);
    }
    for(i=0;i<50;i++){
        if(vr[i]=='\0') break;
        printf("%c", vr[i]);
    }
    return 0;
}