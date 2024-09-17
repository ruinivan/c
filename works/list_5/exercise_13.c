#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    float vet[50];
    int i, j, rep=0, n=0, temp, temp1=0, nun[1275];
    srand(time(NULL));
    for(i=0;i<50;i++) vet[i] = rand() % 100;
    for(i=0;i<50;i++){
        temp = rep;
        for(j=temp1;j<50;j++){
            nun[n]=i;
            nun[n+1]=j;
            if(i!=j && vet[i]==vet[j]){
                n+=2;
                rep++;
            }
        }
        rep += (rep>temp) ? 1 : 0;
        temp1++;
    }
    printf("Repetiram %d números, suas posições são: \n", rep);
    for(i=0;i<n;i+=2){
        printf("%d(%.1f) <---> %d(%.1f)\n", nun[i], vet[nun[i]], nun[i+1], vet[nun[i+1]]);
    }
    return 0;
}