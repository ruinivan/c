#include <stdio.h>
#include "funcoes.h"

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
    printf("Digite o Nome do Produto: ");
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

int pegarProdutoPorCodigo(Produto_t produto){
    printf("\nProduto: %s\n", produto.nome);
    printf("Preco: %.2f\n", produto.preco);
    printf("Codigo: %d\n", produto.codigo);
    return 1;
}