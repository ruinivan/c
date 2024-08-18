#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(0, "Portuguese");
    int total, branco, nulo, valido, porcent_branco, porcent_nulo, porcent_valido;
    printf("Quanto é o total de eleitor desse município? ");
    scanf("%d", &total);
    printf("Qual é a quantidade de votos branco? ");
    scanf("%d", &branco);
    printf("Qual é a quantidade de votos nulo? ");
    scanf("%d", &nulo);
    printf("Qual é a quantidade de votos valido? ");
    scanf("%d", &valido);
    porcent_branco = (branco/(float)total)*100;
    porcent_nulo = (nulo/(float)total)*100;
    porcent_valido = (valido/(float)total)*100;
    printf("A porcentagem de votos: \nbrancos: %d%%. \nnulos: %d%%. \nvalidos: %d%%.", porcent_branco, porcent_nulo, porcent_valido);
    return 0;
}