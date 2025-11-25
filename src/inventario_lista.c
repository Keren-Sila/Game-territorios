#include "../include/inventario.h"

/**
 * Cria um novo nó com o item fornecido
 * Aloca memória dinamicamente para o nó
 */
No* criarNo(Item item) {
    // Aloca memória para o novo nó
    No* novo = (No*)malloc(sizeof(No));
    
    if (novo == NULL) {
        printf("\n[ERRO] Falha ao alocar memoria para novo item.\n");
        return NULL;
    }
    
    // Inicializa o nó com os dados do item
    novo->dados = item;
    novo->proximo = NULL;
    
    return novo;
}

/**
 * Insere um novo item no início da lista
 * Inserção no início é mais eficiente (O(1))
 */
void inserirItemLista(No** cabeca, Item novo_item) {
    // Cria um novo nó
    No* novo = criarNo(novo_item);
    
    if (novo == NULL) {
        return;
    }
    
    // Insere o novo nó no início da lista
    novo->proximo = *cabeca;
    *cabeca = novo;
    
    printf("\n[SUCESSO] Item '%s' adicionado a mochila!\n", novo_item.nome);
}

/**
 * Remove um item da lista por nome
 * Percorre a lista buscando o item e ajusta os ponteiros
 */
int removerItemLista(No** cabeca, const char* nome) {
    No* atual = *cabeca;
    No* anterior = NULL;
    
    // Percorre a lista buscando o item
    while (atual != NULL) {
        if (strcmp(atual->dados.nome, nome) == 0) {
            // Item encontrado - ajusta os ponteiros
            if (anterior == NULL) {
                // Remove o primeiro nó
                *cabeca = atual->proximo;
            } else {
                // Remove um nó do meio ou final
                anterior->proximo = atual->proximo;
            }
            
            // Libera a memória do nó removido
            free(atual);
            printf("\n[SUCESSO] Item '%s' removido da mochila!\n", nome);
            return 1;
        }
        
        anterior = atual;
        atual = atual->proximo;
    }
    
    // Item não encontrado
    printf("\n[ERRO] Item '%s' nao encontrado na mochila.\n", nome);
    return 0;
}

/**
 * Lista todos os itens da lista encadeada
 * Percorre a lista e exibe os dados de cada nó
 */
void listarItensLista(No* cabeca) {
    if (cabeca == NULL) {
        printf("\n[AVISO] Mochila vazia! Nenhum item cadastrado.\n");
        return;
    }
    
    printf("\n========================================\n");
    printf("    ITENS DA MOCHILA (LISTA ENCADEADA)\n");
    printf("========================================\n");
    
    No* atual = cabeca;
    int contador = 1;
    
    // Percorre a lista exibindo cada item
    while (atual != NULL) {
        printf("\nITEM %d:\n", contador);
        printf("  Nome........: %s\n", atual->dados.nome);
        printf("  Tipo........: %s\n", atual->dados.tipo);
        printf("  Quantidade..: %d\n", atual->dados.quantidade);
        printf("----------------------------------------\n");
        
        atual = atual->proximo;
        contador++;
    }
}

/**
 * Busca sequencial na lista encadeada
 * Percorre a lista comparando cada nó
 */
No* buscarItemLista(No* cabeca, const char* nome, int* comparacoes) {
    *comparacoes = 0;
    No* atual = cabeca;
    
    // Percorre a lista comparando cada item
    while (atual != NULL) {
        (*comparacoes)++;
        
        if (strcmp(atual->dados.nome, nome) == 0) {
            return atual;  // Item encontrado
        }
        
        atual = atual->proximo;
    }
    
    return NULL;  // Item não encontrado
}

/**
 * Libera toda a memória alocada pela lista
 * Percorre a lista liberando cada nó
 */
void liberarLista(No** cabeca) {
    No* atual = *cabeca;
    No* proximo;
    
    // Percorre a lista liberando cada nó
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    
    *cabeca = NULL;
}

/**
 * Retorna o tamanho da lista encadeada
 * Conta o número de nós na lista
 */
int tamanhoLista(No* cabeca) {
    int tamanho = 0;
    No* atual = cabeca;
    
    // Percorre a lista contando os nós
    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }
    
    return tamanho;
}
