#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    float vet[50];
    int i, j, rep=0, n=0, t, temp, nun[2500], cond=0;
    srand(time(NULL));
    for(i=0;i<50;i++) vet[i] = rand() % 10;
    for(i=0;i<50;i++){
        temp = rep;
        for(j=0;j<50;j++){
            nun[n]=i;
            nun[n+1]=j;
            for(t=0;t>2500;t+=2){
               cond = (nun[t]==nun[n+1] && nun[t+1]==nun[n]) ? 1 : 0;
            }
            if(i!=j && vet[i]==vet[j] && cond==0){
                n+=2;
                rep++;
            }
        }
        rep += (rep>temp) ? 1 : 0;
    }
    printf("%d repetiram\n", rep);
    for(i=0;i<100;i+=2){
        printf("%d(%.1f) <---> %d(%.1f)\n", nun[i], vet[nun[i]], nun[i+1], vet[nun[i+1]]);
    }
    return 0;
}