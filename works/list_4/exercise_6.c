#include <stdio.h>
#include <locale.h>

void aritmetica(float *n1, float *n2, float *n3, float *media){
    *media=(*n1+*n2+*n3)/3;
}
void ponderada(float *n1, float *n2, float *n3, float *media){
    *media=(*n1*0.5)+(*n2*0.3)+(*n3*0.2);
}
void harmonica(float *n1, float *n2, float *n3, float *media){
    *media= 3/((1 / *n1)+(1 / *n2)+(1 / *n3));
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    float n1, n2, n3, media;
    char m;
    printf("Digite suas três notas: \n");
    printf("N1: ");
    scanf("%f", &n1);
    printf("N2: ");
    scanf("%f", &n2);
    printf("N3: ");
    scanf("%f", &n3);
    printf("Qual média devo aplica-las Média Aritmética(a), Média Ponderada(p) ou Média Harmônica(h): ");
    scanf(" %c", &m);
    switch (m){
    case 'a': 
        aritmetica(&n1, &n2, &n3, &media);
        printf("Com a N1:%.2f, N2:%.2f e N3:%.2f a média foi de %.2f", n1, n2, n3, media);
        break;
    case 'p': 
        ponderada(&n1, &n2, &n3, &media);
        printf("Com a N1:%.2f, N2:%.2f e N3:%.2f a média foi de %.2f", n1, n2, n3, media);
        break;
    case 'h': 
        harmonica(&n1, &n2, &n3, &media);
        printf("Com a N1:%.2f, N2:%.2f e N3:%.2f a média foi de %.2f", n1, n2, n3, media);
        break;
    default:
        printf("Insira uma média válida");
        break;
    }
    return 0;
}