#include "../include/inventario.h"

/**
 * Cria um item preenchendo seus dados
 */
Item criarItem(const char* nome, const char* tipo, int quantidade) {
    Item item;
    
    strncpy(item.nome, nome, MAX_NOME - 1);
    item.nome[MAX_NOME - 1] = '\0';
    
    strncpy(item.tipo, tipo, MAX_TIPO - 1);
    item.tipo[MAX_TIPO - 1] = '\0';
    
    item.quantidade = quantidade;
    
    return item;
}

/**
 * Exibe informações de um item
 */
void exibirItem(Item item) {
    printf("\n========================================\n");
    printf("  Nome........: %s\n", item.nome);
    printf("  Tipo........: %s\n", item.tipo);
    printf("  Quantidade..: %d\n", item.quantidade);
    printf("========================================\n");
}

/**
 * Limpa o buffer de entrada
 */
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
