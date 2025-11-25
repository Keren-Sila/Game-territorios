#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Constantes do sistema */
#define MAX_ITENS 10
#define MAX_NOME 30
#define MAX_TIPO 20

/* ===== ESTRUTURAS DE DADOS ===== */

/**
 * Struct Item - Representa um item do inventário
 * nome: Nome do item (ex: "AK-47", "Kit Médico")
 * tipo: Categoria do item (ex: "arma", "munição", "cura")
 * quantidade: Número de unidades do item
 */
typedef struct {
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    int quantidade;
} Item;

/**
 * Struct No - Nó para lista encadeada
 * dados: Item armazenado no nó
 * proximo: Ponteiro para o próximo nó da lista
 */
typedef struct No {
    Item dados;
    struct No* proximo;
} No;

/* ===== FUNÇÕES PARA VETOR ===== */

/**
 * Insere um novo item no vetor
 * Retorna 1 se sucesso, 0 se falha (vetor cheio)
 */
int inserirItemVetor(Item inventario[], int* tamanho, Item novo_item);

/**
 * Remove um item do vetor por nome
 * Retorna 1 se sucesso, 0 se item não encontrado
 */
int removerItemVetor(Item inventario[], int* tamanho, const char* nome);

/**
 * Lista todos os itens do vetor
 */
void listarItensVetor(Item inventario[], int tamanho);

/**
 * Busca sequencial no vetor
 * Retorna o índice do item ou -1 se não encontrado
 * comparacoes: contador de comparações realizadas
 */
int buscarSequencialVetor(Item inventario[], int tamanho, const char* nome, int* comparacoes);

/**
 * Ordena o vetor usando Bubble Sort
 */
void ordenarVetor(Item inventario[], int tamanho);

/**
 * Busca binária no vetor (requer vetor ordenado)
 * Retorna o índice do item ou -1 se não encontrado
 * comparacoes: contador de comparações realizadas
 */
int buscarBinariaVetor(Item inventario[], int tamanho, const char* nome, int* comparacoes);

/* ===== FUNÇÕES PARA LISTA ENCADEADA ===== */

/**
 * Cria um novo nó com o item fornecido
 */
No* criarNo(Item item);

/**
 * Insere um novo item no início da lista
 */
void inserirItemLista(No** cabeca, Item novo_item);

/**
 * Remove um item da lista por nome
 * Retorna 1 se sucesso, 0 se item não encontrado
 */
int removerItemLista(No** cabeca, const char* nome);

/**
 * Lista todos os itens da lista encadeada
 */
void listarItensLista(No* cabeca);

/**
 * Busca sequencial na lista encadeada
 * Retorna ponteiro para o nó ou NULL se não encontrado
 * comparacoes: contador de comparações realizadas
 */
No* buscarItemLista(No* cabeca, const char* nome, int* comparacoes);

/**
 * Libera toda a memória alocada pela lista
 */
void liberarLista(No** cabeca);

/**
 * Retorna o tamanho da lista encadeada
 */
int tamanhoLista(No* cabeca);

/* ===== FUNÇÕES AUXILIARES ===== */

/**
 * Cria um item preenchendo seus dados
 */
Item criarItem(const char* nome, const char* tipo, int quantidade);

/**
 * Exibe informações de um item
 */
void exibirItem(Item item);

/**
 * Limpa o buffer de entrada
 */
void limparBuffer();

#endif /* INVENTARIO_H */
