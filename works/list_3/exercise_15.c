#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float i, d, r;
    for(i=15;i<=100;i++){
        printf("%.0f+=%.0f // ", r+=i, i);
        printf("repetição: %.0f;\n",d++);
    }
    r/=d;
    printf("\nQuantidade total de repetição: %.0f\n", d);
    printf("Média aritmética: %.1f.\n\n", r);
    return 0;
}