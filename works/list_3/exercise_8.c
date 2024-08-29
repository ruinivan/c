#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int i;
    for (i=10;i>0;i--){
    printf("%d ", i);
    }
    return 0;
}