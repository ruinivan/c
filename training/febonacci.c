#include <stdio.h>

int main(){
    int i, n, n1=0, n2=0, n3=0;
    printf("Digite até qual camada irá aparecer: ");
    scanf("%d", &n);
    for(i=0;i<=n;i++){ 
        n3=n1;
        n1+=n2;
        n2=n3;
        printf("%d --> %d\n", i, n1);
        n2 = (!n1 && !n3) ? ++n2 : n2;
    }
    return 0;
}