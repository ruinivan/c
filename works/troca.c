#include <stdio.h>

int main(){
    int a=10, b=-8, c;
    c=a;
    a=b;
    b=c;
    printf("a:%d \nb:%d", a, b);
    return 0;    
}