#include <stdio.h>

typedef struct{
    int codigo;
    char nome[30];
    float preco;
}Produto_t;

typedef struct{
    Produto_t produto;
    int quantidade;
}Carrinho_t;

int menu(){
    int opc;
    printf("\t\tBEM-VINDO AO MERCADO\n\n");
    printf("1 - Cadastrar Produto Novo\n");
    printf("2 - Listar Produtos Cadastrados\n");
    printf("3 - Comprar Produto Por Codigo\n");
    printf("4 - Visualizar Carrinho\n");
    printf("5 - Encerrar Pedido\n");
    printf("6 - Vericar Se Produto Estar No Carrinho Por Codigo\n");
    printf("7 - Visualizar Produto Por Codigo\n");
    printf("8 - Sair\n");
    scanf("%d", &opc);
    return opc;
}

Produto_t casdastrarProduto(){
    Produto_t produto;
    printf("Digite o Codigo: ");
    scanf("%d", &produto.codigo);
    printf("Digite o Nome: ");
    getchar();
    scanf("%s", produto.nome);
    printf("Digite o Preco: ");
    scanf("%f", &produto.preco);
    return produto;
}

void listarProdutos(Produto_t produto){
    printf("\nProduto: %s\n", produto.nome);
    printf("Preco: R$%.2f\n", produto.preco);
    printf("Codigo: %d\n", produto.codigo);
}

Carrinho_t comprarProduto(Produto_t produto){
    Carrinho_t carrinho;
    carrinho.produto = produto;
    printf("Quantos %s quer comprar? ", produto.nome);
    scanf("%d", &carrinho.quantidade);
    printf("O produto foi adicionado ao carrinho!\n");
    return carrinho;
}

void visualizarCarrinho(Carrinho_t carrinho){
    printf("\nProduto: %s\n", carrinho.produto.nome);
    printf("Preco p/ quant.: %.2f Preco total: %.2f\n", carrinho.produto.preco, carrinho.produto.preco*carrinho.quantidade);
    printf("Codigo: %d\t\t", carrinho.produto.codigo);
    printf("Quantidade: %d\n", carrinho.quantidade);
}

float fecharPedido(Carrinho_t carrinho){
    printf("\nProduto: %s\n", carrinho.produto.nome);
    printf("Preco p/ quant.: %.2f Preco total: %.2f\n", carrinho.produto.preco, carrinho.produto.preco*carrinho.quantidade);
    printf("Codigo: %d\t\t", carrinho.produto.codigo);
    printf("Quantidade: %d\n", carrinho.quantidade);
    return carrinho.produto.preco*carrinho.quantidade;
}

int temNoCarrinho(Carrinho_t carrinho){
    printf("O Produto %s com o Codigo %d ja esta no carrinho com %d quant.\n", carrinho.produto.nome, carrinho.produto.codigo, carrinho.quantidade);
    return 1;
}

void pegarProdutoPorCodigo(Produto_t produto){
    printf("\nProduto: %s\n", produto.nome);
    printf("Preco: %.2f\n", produto.preco);
    printf("Codigo: %d\n", produto.codigo);
}

int main(){
    Produto_t produto[50];
    Carrinho_t carrinho[50];
    int opc, cod, p=0, c=0, ver=0, sn=0;
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
                        for(int l=0; l<c; l++){
                            if(carrinho[l].produto.codigo==cod){
                                printf("O carrinho ja tem esse produto, deseja alterar a quantidade:(sim:1 / nao:0) ");
                                scanf("%d", &sn);
                                if(sn==1){
                                    printf("Qual a quantidade que quer desse item?(%s) ", carrinho[l].produto.nome);
                                    scanf("%d", &carrinho[l].quantidade);
                                }
                            } else{
                                carrinho[c] = comprarProduto(produto[i]);
                            }
                        }
                    } 
                }
                c++;
                break;
            case 4:
                for(int i=0; i<c; i++) visualizarCarrinho(carrinho[i]);
                break;
            case 5:
                for(int i=0; i<c; i++) valor_total+=fecharPedido(carrinho[i]);
                printf("Valor Total Final: %.2f\n", valor_total);
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
                    if(produto[i].codigo==cod) pegarProdutoPorCodigo(produto[i]);
                }
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }while(opc!=8);
    return 0;
}