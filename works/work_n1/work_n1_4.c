#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float n1, n2, ppd, eu, n3, media;
    int if_eu, if_n3;
    do{
        printf("Qual a nota da N1: ");
        scanf("%f", &n1);
        if(n1<0 || n1>4.5) printf("A Nota da N1 tem que estar entre 0 e 4,5\n");
    }while(n1<0 || n1>4.5);
    do{
        printf("Qual a nota da N2: ");
        scanf("%f", &n2);
        if(n2<0 || n2>4.5) printf("A Nota da N2 tem que estar entre 0 e 4,5\n");
    }while(n2<0 || n2>4.5);
    do{
        printf("Qual a nota da PPD: ");
        scanf("%f", &ppd);
        if(ppd<0 || ppd>4.5) printf("A Nota da PPD tem que estar entre 0 e 1\n");
    }while(ppd<0 || ppd>1);
    printf("Você fez o Exame Unificado:(\'0\' pra \'N\' e \'1\' pra \'S\') ");
    scanf("%d", &if_eu);
    if(if_eu==1){
        do{
        printf("Qual a nota do Exame Unificado: ");
        scanf("%f", &eu);
        if(eu<0 || eu>4.5) printf("A Nota da Exame Unificado tem que estar entre 0 e 1\n");
        }while(eu<0 || eu>1);
    }
    printf("Você fez a N3:(\'0\' pra \'N\' e \'1\' pra \'S\') ");
    scanf("%d", &if_n3);
    if(if_n3==1){
        do{
        printf("Qual a nota da N3: ");
        scanf("%f", &n3);
        if(n3<0 || n3>4.5) printf("A Nota da N3 tem que estar entre 0 e 4,5\n");
        }while(n3<0 || n3>4.5);
        if (n1<n2) n1 = n3;
        else n2 = n3;
    }
    media = n1 + n2 + ppd + eu;
    media = (media>10) ? 10 : media;
    (media>=7) ? printf("Aprovado! \nCom a média de: %.2f", media) : printf("Reprovado! \nCom a média de: %.2f", media);  
    return 0;
}