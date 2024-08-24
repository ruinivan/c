#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int hrs_i, hrs_f;
    printf("Digite a hora de inicio do jogo de xadrez: ");
    scanf("%d", &hrs_i);
    printf("Digite a hora de termino do jogo de xadrez: ");
    scanf("%d", &hrs_f);
    if(hrs_f<hrs_i) printf ("O jogo de xadrez durou %dhrs", (hrs_f+24)-hrs_i);
    else printf("O jogo de xadrez durou %dhrs", hrs_f-hrs_i);
    return 0;
}