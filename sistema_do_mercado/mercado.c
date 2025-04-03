#include <stdio.h>
#include "funcoes.h"

int main(){
    Produto_t produto[50];
    Carrinho_t carrinho[50];
    int opc, cod, p=0, c=0, ver=0, sn=0, jt=0, pic=0;
    float valor_total=0;
    do{
        opc = menu();
        switch(opc){
            case 1:
                produto[p] = casdastrarProduto();
                p++;
                break;
            case 2:
                for(int i=0; i<p; i++) listarProdutos(produto[i]);
                break;
            case 3:
                printf("Digite o codigo do produto: ");
                scanf("%d", &cod);
                for(int i=0; i<p; i++){
                    if(produto[i].codigo==cod){
                        pic=1;
                        for(int l=0; l<=c; l++){
                            if(carrinho[l].produto.codigo==cod){
                                pic=1;
                                jt=1;
                                printf("O carrinho ja tem esse produto, deseja alterar a quantidade:(sim:1 / nao:0) ");
                                scanf("%d", &sn);
                                if(sn==1){
                                    printf("Qual a quantidade que quer desse item?(%s) ", carrinho[l].produto.nome);
                                    scanf("%d", &carrinho[l].quantidade);
                                }
                            }
                        }
                        if(jt==0){
                            pic=1;
                            carrinho[c] = comprarProduto(produto[i]);
                            c++;
                        }else jt=0;
                    }   
                }
                if(pic==0) printf("Esse codigo nao existe no registro\n");
                pic=0;
                break;
            case 4:
                for(int i=0; i<c; i++) visualizarCarrinho(carrinho[i]);
                break;
            case 5:
                for(int i=0; i<c; i++) valor_total+=fecharPedido(carrinho[i]);
                printf("\n\tValor Total Final: %.2f\n\n", valor_total);
                c=0;
                break;
            case 6:
                printf("Digite o Codigo do Produto que queria conferir: ");
                scanf("%d", &cod);
                for(int i=0; i<c; i++){
                    if(carrinho[i].produto.codigo==cod) ver=temNoCarrinho(carrinho[i]);
                }
                if(ver==0) printf("O Produto nao esta no carrinho\n");
                ver=0;
                break;
            case 7:
                printf("Digite o codigo do produto: ");
                scanf("%d", &cod);
                for(int i=0; i<p; i++){
                    if(produto[i].codigo==cod) pic = pegarProdutoPorCodigo(produto[i]);
                }
                if(pic==0) printf("Esse codigo nao existe no registro\n");
                pic=0;
                break;
            case 8:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }while(opc!=8);
    return 0;
}