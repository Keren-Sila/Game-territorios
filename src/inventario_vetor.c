#include "../include/inventario.h"

/**
 * Insere um novo item no vetor
 * Verifica se há espaço disponível antes de inserir
 */
int inserirItemVetor(Item inventario[], int* tamanho, Item novo_item) {
    // Verifica se o vetor está cheio
    if (*tamanho >= MAX_ITENS) {
        printf("\n[ERRO] Mochila cheia! Nao e possivel adicionar mais itens.\n");
        return 0;
    }
    
    // Adiciona o item na próxima posição disponível
    inventario[*tamanho] = novo_item;
    (*tamanho)++;
    
    printf("\n[SUCESSO] Item '%s' adicionado a mochila!\n", novo_item.nome);
    return 1;
}

/**
 * Remove um item do vetor por nome
 * Desloca os elementos após a remoção para manter o vetor contíguo
 */
int removerItemVetor(Item inventario[], int* tamanho, const char* nome) {
    int indice = -1;
    
    // Busca o item no vetor
    for (int i = 0; i < *tamanho; i++) {
        if (strcmp(inventario[i].nome, nome) == 0) {
            indice = i;
            break;
        }
    }
    
    // Item não encontrado
    if (indice == -1) {
        printf("\n[ERRO] Item '%s' nao encontrado na mochila.\n", nome);
        return 0;
    }
    
    // Desloca todos os elementos após o índice removido
    for (int i = indice; i < *tamanho - 1; i++) {
        inventario[i] = inventario[i + 1];
    }
    
    (*tamanho)--;
    printf("\n[SUCESSO] Item '%s' removido da mochila!\n", nome);
    return 1;
}

/**
 * Lista todos os itens do vetor
 * Exibe os dados formatados de cada item
 */
void listarItensVetor(Item inventario[], int tamanho) {
    if (tamanho == 0) {
        printf("\n[AVISO] Mochila vazia! Nenhum item cadastrado.\n");
        return;
    }
    
    printf("\n========================================\n");
    printf("       ITENS DA MOCHILA (VETOR)\n");
    printf("========================================\n");
    
    for (int i = 0; i < tamanho; i++) {
        printf("\nITEM %d:\n", i + 1);
        printf("  Nome........: %s\n", inventario[i].nome);
        printf("  Tipo........: %s\n", inventario[i].tipo);
        printf("  Quantidade..: %d\n", inventario[i].quantidade);
        printf("----------------------------------------\n");
    }
}

/**
 * Busca sequencial no vetor
 * Percorre o vetor linearmente comparando cada elemento
 */
int buscarSequencialVetor(Item inventario[], int tamanho, const char* nome, int* comparacoes) {
    *comparacoes = 0;
    
    // Percorre o vetor comparando cada item
    for (int i = 0; i < tamanho; i++) {
        (*comparacoes)++;
        if (strcmp(inventario[i].nome, nome) == 0) {
            return i;  // Retorna o índice onde o item foi encontrado
        }
    }
    
    return -1;  // Item não encontrado
}

/**
 * Ordena o vetor usando Bubble Sort
 * Compara elementos adjacentes e os troca se estiverem fora de ordem
 */
void ordenarVetor(Item inventario[], int tamanho) {
    // Bubble Sort: compara pares adjacentes e troca se necessário
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            // Compara os nomes dos itens lexicograficamente
            if (strcmp(inventario[j].nome, inventario[j + 1].nome) > 0) {
                // Troca os itens de posição
                Item temp = inventario[j];
                inventario[j] = inventario[j + 1];
                inventario[j + 1] = temp;
            }
        }
    }
    
    printf("\n[SUCESSO] Itens ordenados alfabeticamente!\n");
}

/**
 * Busca binária no vetor (requer vetor ordenado)
 * Divide o espaço de busca pela metade a cada iteração
 */
int buscarBinariaVetor(Item inventario[], int tamanho, const char* nome, int* comparacoes) {
    *comparacoes = 0;
    
    int esquerda = 0;
    int direita = tamanho - 1;
    
    // Continua enquanto houver elementos a serem verificados
    while (esquerda <= direita) {
        (*comparacoes)++;
        
        // Calcula o índice do meio
        int meio = esquerda + (direita - esquerda) / 2;
        
        // Compara o item do meio com o nome buscado
        int resultado = strcmp(inventario[meio].nome, nome);
        
        if (resultado == 0) {
            return meio;  // Item encontrado
        }
        else if (resultado < 0) {
            esquerda = meio + 1;  // Busca na metade direita
        }
        else {
            direita = meio - 1;  // Busca na metade esquerda
        }
    }
    
    return -1;  // Item não encontrado
}
