/*
 * Sistema de Cadastro de Territórios - Jogo War
 * 
 * Este programa implementa um sistema básico de cadastro de territórios
 * utilizando structs para organizar os dados de cada território.
 * 
 * Funcionalidades:
 * - Cadastro de 5 territórios
 * - Armazenamento de nome, cor do exército e quantidade de tropas
 * - Exibição formatada dos dados cadastrados
 */

#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Armazena as informações básicas de cada território no jogo War
typedef struct {
    char nome[30];      // Nome do território (ex: Brasil, Argentina)
    char cor[10];       // Cor do exército ocupante (ex: Vermelho, Azul)
    int tropas;         // Quantidade de tropas posicionadas no território
} Territorio;

// Constante que define o número total de territórios a serem cadastrados
#define NUM_TERRITORIOS 5

/*
 * Função principal do programa
 * Responsável por cadastrar e exibir os dados dos territórios
 */
int main() {
    // Declaração do vetor de structs para armazenar os 5 territórios
    Territorio territorios[NUM_TERRITORIOS];
    int i;

    // Cabeçalho do sistema
    printf("========================================\n");
    printf("   SISTEMA DE CADASTRO DE TERRITORIOS\n");
    printf("           JOGO WAR - NIVEL NOVATO\n");
    printf("========================================\n\n");

    // Laço de entrada de dados - cadastro dos territórios
    printf("Por favor, cadastre %d territorios:\n\n", NUM_TERRITORIOS);
    
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("--- TERRITORIO %d ---\n", i + 1);
        
        // Entrada do nome do território
        printf("Nome do territorio: ");
        // Limpa o buffer de entrada
        fflush(stdin);
        // Lê o nome do território (permite espaços)
        fgets(territorios[i].nome, 30, stdin);
        // Remove o caractere de nova linha do final, se existir
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';
        
        // Entrada da cor do exército
        printf("Cor do exercito: ");
        fflush(stdin);
        fgets(territorios[i].cor, 10, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';
        
        // Entrada da quantidade de tropas
        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
        
        printf("\n");
    }

    // Exibição dos dados cadastrados
    printf("\n========================================\n");
    printf("     TERRITORIOS CADASTRADOS\n");
    printf("========================================\n\n");
    
    // Laço de exibição - percorre o vetor e mostra os dados
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("TERRITORIO %d:\n", i + 1);
        printf("  Nome........: %s\n", territorios[i].nome);
        printf("  Cor Exercito: %s\n", territorios[i].cor);
        printf("  Tropas......: %d\n", territorios[i].tropas);
        printf("----------------------------------------\n");
    }
    
    printf("\nCadastro concluido com sucesso!\n");
    printf("========================================\n");
    
    return 0;
}
