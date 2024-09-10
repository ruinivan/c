#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int absoluto(char *v){
    int i, vf;
    char vr[2];
    size_t t = strlen(v);
    for(i=0;i<(int)t;i++){
        vr[0]= v[i];
        vf=strtol(vr, NULL, 10);
        printf("o valor absoluto do algarismo %d no número %s é %d\n",vf,v,vf);
    }
    return 0;
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    char v[]="";
    printf("Digite 5 números: ");
    scanf("%s", v);
    absoluto(v);
    return 0;
}