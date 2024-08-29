#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int i;
    for (i=101;i<=110;i++){
    printf("%d ", i);
    }
    return 0;
}