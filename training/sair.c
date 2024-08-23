#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    char compromisso, cidade, dinheiro, chovendo, perto;
    printf("Tenho compromisso? ");
    scanf(" %c", &compromisso);
    printf("Vou estar na cidade? ");
    scanf(" %c", &cidade);
    printf("Tenho dinheiro? ");
    scanf(" %c", &dinheiro);
    printf("Está chovendo? ");
    scanf(" %c", &chovendo);
    printf("É perto? ");
    scanf(" %c", &perto);
    if ((compromisso=='n') && (cidade=='s') && (((dinheiro=='s') && (chovendo=='n')) || ((dinheiro=='n') && (perto=='s')))) printf("Eu vou!");
    else printf("Não vou!");
    return 0;
}