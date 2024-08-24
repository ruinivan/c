#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    unsigned int atual, nasceu;
    printf("Qual é o ano atual? ");
    scanf("%u", &atual);
    printf("Em que ano você nasceu? ");
    scanf("%u", &nasceu);
    if(atual-nasceu>=16) printf("Você já pode votar nesse ano");
    else printf("Você ainda não pode votar");
    return 0;
}