#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct{
    int codigo;
    char nome[30];
    float preco;
}Produto_t;

typedef struct{
    Produto_t produto;
    int quantidade;
}Carrinho_t;

int menu();

Produto_t casdastrarProduto();

void listarProdutos(Produto_t produto);

Carrinho_t comprarProduto(Produto_t produto);

void visualizarCarrinho(Carrinho_t carrinho);

float fecharPedido(Carrinho_t carrinho);

int temNoCarrinho(Carrinho_t carrinho);

int pegarProdutoPorCodigo(Produto_t produto);

#endif