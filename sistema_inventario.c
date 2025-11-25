/*
 * ============================================================================
 * SISTEMA DE INVENTÁRIO - JOGO DE SOBREVIVÊNCIA
 * Nível Aventureiro - Estrutura de Dados
 * ============================================================================
 * 
 * Este programa implementa um sistema de inventário comparando duas 
 * estruturas de dados diferentes:
 * - Vetor (lista sequencial)
 * - Lista encadeada (estrutura dinâmica)
 * 
 * Funcionalidades:
 * - Inserção de itens
 * - Remoção de itens
 * - Listagem de itens
 * - Busca sequencial
 * - Ordenação (apenas vetor)
 * - Busca binária (apenas vetor ordenado)
 * - Análise de desempenho (contador de comparações)
 * 
 * Autor: Desenvolvido para o desafio de Estrutura de Dados
 * ============================================================================
 */

#include "include/inventario.h"

/* ========== PROTÓTIPOS DAS FUNÇÕES DO MENU ========== */
void exibirMenuPrincipal();
void exibirMenuVetor();
void exibirMenuLista();
void menuVetor(Item inventario[], int* tamanho);
void menuLista(No** cabeca);
void adicionarItemVetor(Item inventario[], int* tamanho);
void adicionarItemLista(No** cabeca);
void buscarItemVetor(Item inventario[], int tamanho);
void buscarItemLista(No* cabeca);
void buscarItemBinaria(Item inventario[], int tamanho);

/* ========== FUNÇÃO PRINCIPAL ========== */
int main() {
    // Variáveis para o vetor
    Item inventario_vetor[MAX_ITENS];
    int tamanho_vetor = 0;
    
    // Variável para a lista encadeada
    No* inventario_lista = NULL;
    
    int opcao_principal;
    
    // Cabeçalho do sistema
    printf("========================================\n");
    printf("  SISTEMA DE INVENTARIO - MOCHILA LOOT\n");
    printf("      NIVEL AVENTUREIRO\n");
    printf("========================================\n\n");
    printf("Este sistema permite comparar o desempenho\n");
    printf("de duas estruturas de dados:\n");
    printf("  1. Vetor (Lista Sequencial)\n");
    printf("  2. Lista Encadeada (Dinamica)\n");
    printf("========================================\n\n");
    
    // Loop principal do menu
    do {
        exibirMenuPrincipal();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao_principal);
        limparBuffer();
        
        switch (opcao_principal) {
            case 1:
                menuVetor(inventario_vetor, &tamanho_vetor);
                break;
            case 2:
                menuLista(&inventario_lista);
                break;
            case 0:
                printf("\n========================================\n");
                printf("  Encerrando o sistema...\n");
                printf("  Liberando memoria...\n");
                liberarLista(&inventario_lista);
                printf("  Ate logo!\n");
                printf("========================================\n");
                break;
            default:
                printf("\n[ERRO] Opcao invalida! Tente novamente.\n");
        }
        
        if (opcao_principal != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }
        
    } while (opcao_principal != 0);
    
    return 0;
}

/* ========== FUNÇÕES DE EXIBIÇÃO DE MENUS ========== */

/**
 * Exibe o menu principal do sistema
 */
void exibirMenuPrincipal() {
    printf("\n========================================\n");
    printf("           MENU PRINCIPAL\n");
    printf("========================================\n");
    printf("  [1] Mochila com VETOR\n");
    printf("  [2] Mochila com LISTA ENCADEADA\n");
    printf("  [0] Sair do sistema\n");
    printf("========================================\n");
}

/**
 * Exibe o menu de operações para vetor
 */
void exibirMenuVetor() {
    printf("\n========================================\n");
    printf("      MENU - MOCHILA COM VETOR\n");
    printf("========================================\n");
    printf("  [1] Adicionar item\n");
    printf("  [2] Remover item\n");
    printf("  [3] Listar itens\n");
    printf("  [4] Buscar item (sequencial)\n");
    printf("  [5] Ordenar itens\n");
    printf("  [6] Buscar item (binaria - requer ordenacao)\n");
    printf("  [0] Voltar ao menu principal\n");
    printf("========================================\n");
}

/**
 * Exibe o menu de operações para lista encadeada
 */
void exibirMenuLista() {
    printf("\n========================================\n");
    printf("   MENU - MOCHILA COM LISTA ENCADEADA\n");
    printf("========================================\n");
    printf("  [1] Adicionar item\n");
    printf("  [2] Remover item\n");
    printf("  [3] Listar itens\n");
    printf("  [4] Buscar item\n");
    printf("  [0] Voltar ao menu principal\n");
    printf("========================================\n");
}

/* ========== MENUS DE OPERAÇÕES ========== */

/**
 * Menu de operações com vetor
 */
void menuVetor(Item inventario[], int* tamanho) {
    int opcao;
    
    do {
        exibirMenuVetor();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();
        
        switch (opcao) {
            case 1:
                adicionarItemVetor(inventario, tamanho);
                break;
            case 2: {
                char nome[MAX_NOME];
                printf("\nDigite o nome do item a remover: ");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                removerItemVetor(inventario, tamanho, nome);
                break;
            }
            case 3:
                listarItensVetor(inventario, *tamanho);
                break;
            case 4:
                buscarItemVetor(inventario, *tamanho);
                break;
            case 5:
                if (*tamanho == 0) {
                    printf("\n[AVISO] Mochila vazia! Adicione itens primeiro.\n");
                } else {
                    ordenarVetor(inventario, *tamanho);
                }
                break;
            case 6:
                buscarItemBinaria(inventario, *tamanho);
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\n[ERRO] Opcao invalida! Tente novamente.\n");
        }
        
        if (opcao != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }
        
    } while (opcao != 0);
}

/**
 * Menu de operações com lista encadeada
 */
void menuLista(No** cabeca) {
    int opcao;
    
    do {
        exibirMenuLista();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();
        
        switch (opcao) {
            case 1:
                adicionarItemLista(cabeca);
                break;
            case 2: {
                char nome[MAX_NOME];
                printf("\nDigite o nome do item a remover: ");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                removerItemLista(cabeca, nome);
                break;
            }
            case 3:
                listarItensLista(*cabeca);
                break;
            case 4:
                buscarItemLista(*cabeca);
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\n[ERRO] Opcao invalida! Tente novamente.\n");
        }
        
        if (opcao != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }
        
    } while (opcao != 0);
}

/* ========== FUNÇÕES AUXILIARES DE INTERFACE ========== */

/**
 * Adiciona um item ao vetor
 */
void adicionarItemVetor(Item inventario[], int* tamanho) {
    char nome[MAX_NOME], tipo[MAX_TIPO];
    int quantidade;
    
    printf("\n--- ADICIONAR ITEM ---\n");
    printf("Nome do item: ");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    
    printf("Tipo (arma/municao/cura/ferramenta): ");
    fgets(tipo, MAX_TIPO, stdin);
    tipo[strcspn(tipo, "\n")] = '\0';
    
    printf("Quantidade: ");
    scanf("%d", &quantidade);
    limparBuffer();
    
    Item novo_item = criarItem(nome, tipo, quantidade);
    inserirItemVetor(inventario, tamanho, novo_item);
}

/**
 * Adiciona um item à lista encadeada
 */
void adicionarItemLista(No** cabeca) {
    char nome[MAX_NOME], tipo[MAX_TIPO];
    int quantidade;
    
    printf("\n--- ADICIONAR ITEM ---\n");
    printf("Nome do item: ");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    
    printf("Tipo (arma/municao/cura/ferramenta): ");
    fgets(tipo, MAX_TIPO, stdin);
    tipo[strcspn(tipo, "\n")] = '\0';
    
    printf("Quantidade: ");
    scanf("%d", &quantidade);
    limparBuffer();
    
    Item novo_item = criarItem(nome, tipo, quantidade);
    inserirItemLista(cabeca, novo_item);
}

/**
 * Busca um item no vetor (busca sequencial)
 */
void buscarItemVetor(Item inventario[], int tamanho) {
    char nome[MAX_NOME];
    int comparacoes = 0;
    
    if (tamanho == 0) {
        printf("\n[AVISO] Mochila vazia! Adicione itens primeiro.\n");
        return;
    }
    
    printf("\n--- BUSCAR ITEM (SEQUENCIAL) ---\n");
    printf("Digite o nome do item: ");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    
    int indice = buscarSequencialVetor(inventario, tamanho, nome, &comparacoes);
    
    if (indice != -1) {
        printf("\n[SUCESSO] Item encontrado!\n");
        exibirItem(inventario[indice]);
        printf("\n[ANALISE] Numero de comparacoes: %d\n", comparacoes);
    } else {
        printf("\n[ERRO] Item '%s' nao encontrado.\n", nome);
        printf("[ANALISE] Numero de comparacoes: %d\n", comparacoes);
    }
}

/**
 * Busca um item na lista encadeada
 */
void buscarItemLista(No* cabeca) {
    char nome[MAX_NOME];
    int comparacoes = 0;
    
    if (cabeca == NULL) {
        printf("\n[AVISO] Mochila vazia! Adicione itens primeiro.\n");
        return;
    }
    
    printf("\n--- BUSCAR ITEM ---\n");
    printf("Digite o nome do item: ");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    
    No* resultado = buscarItemLista(cabeca, nome, &comparacoes);
    
    if (resultado != NULL) {
        printf("\n[SUCESSO] Item encontrado!\n");
        exibirItem(resultado->dados);
        printf("\n[ANALISE] Numero de comparacoes: %d\n", comparacoes);
    } else {
        printf("\n[ERRO] Item '%s' nao encontrado.\n", nome);
        printf("[ANALISE] Numero de comparacoes: %d\n", comparacoes);
    }
}

/**
 * Busca um item no vetor usando busca binária
 */
void buscarItemBinaria(Item inventario[], int tamanho) {
    char nome[MAX_NOME];
    int comparacoes = 0;
    
    if (tamanho == 0) {
        printf("\n[AVISO] Mochila vazia! Adicione itens primeiro.\n");
        return;
    }
    
    printf("\n--- BUSCAR ITEM (BINARIA) ---\n");
    printf("ATENCAO: Certifique-se de ordenar os itens primeiro!\n");
    printf("Digite o nome do item: ");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    
    int indice = buscarBinariaVetor(inventario, tamanho, nome, &comparacoes);
    
    if (indice != -1) {
        printf("\n[SUCESSO] Item encontrado!\n");
        exibirItem(inventario[indice]);
        printf("\n[ANALISE] Numero de comparacoes: %d\n", comparacoes);
        printf("[INFO] A busca binaria e muito mais eficiente!\n");
    } else {
        printf("\n[ERRO] Item '%s' nao encontrado.\n", nome);
        printf("[ANALISE] Numero de comparacoes: %d\n", comparacoes);
        printf("[DICA] Verifique se os itens estao ordenados.\n");
    }
}
