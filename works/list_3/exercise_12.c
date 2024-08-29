#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int i;
    for (i=1;i<=10;i++){
        printf("8 x %d: %d\n", i, 8*i);
    }
    return 0;
}