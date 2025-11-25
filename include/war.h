#ifndef WAR_H
#define WAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TERRITORIOS 42
#define MAX_JOGADORES 6
#define MAX_NOME 50
#define MAX_CONTINENTES 6
#define MAX_TERRITORIOS_CONTINENTE 12
#define MAX_VIZINHOS 10

/* Enumeração para tipos de missão */
typedef enum {
    MISSAO_CONQUISTAR_CONTINENTES,
    MISSAO_CONQUISTAR_TERRITORIOS,
    MISSAO_DESTRUIR_COR,
    MISSAO_CONQUISTA_TOTAL
} TipoMissao;

/* Enumeração para cores dos jogadores */
typedef enum {
    COR_VERMELHO,
    COR_AZUL,
    COR_VERDE,
    COR_AMARELO,
    COR_PRETO,
    COR_BRANCO
} Cor;

/* Estrutura para representar um território */
typedef struct Territorio {
    int id;
    char nome[MAX_NOME];
    int continente_id;
    int num_tropas;
    int jogador_id;  // -1 se não conquistado
    int vizinhos[MAX_VIZINHOS];
    int num_vizinhos;
} Territorio;

/* Estrutura para representar um continente */
typedef struct {
    int id;
    char nome[MAX_NOME];
    int bonus_tropas;
    int territorios[MAX_TERRITORIOS_CONTINENTE];
    int num_territorios;
} Continente;

/* Estrutura para representar uma missão */
typedef struct {
    TipoMissao tipo;
    char descricao[200];
    union {
        struct {
            int continentes[3];
            int num_continentes;
        } conquistar_continentes;
        struct {
            int num_territorios;
            int min_tropas_por_territorio;
        } conquistar_territorios;
        struct {
            Cor cor_alvo;
        } destruir_cor;
    } objetivo;
} Missao;

/* Estrutura para representar um jogador */
typedef struct {
    int id;
    char nome[MAX_NOME];
    Cor cor;
    int num_territorios;
    int num_tropas_disponiveis;
    Missao missao;
    int ativo;  // 1 se ainda está jogando, 0 se foi eliminado
} Jogador;

/* Estrutura principal do jogo */
typedef struct {
    Territorio* territorios;
    Continente continentes[MAX_CONTINENTES];
    Jogador* jogadores;
    int num_territorios;
    int num_continentes;
    int num_jogadores;
    int turno_atual;
} Jogo;

/* Ponteiro para função de ataque */
typedef int (*FuncaoAtaque)(Territorio* atacante, Territorio* defensor);

/* === FUNÇÕES DE INICIALIZAÇÃO === */
Jogo* criar_jogo(int num_jogadores);
void destruir_jogo(Jogo* jogo);
void inicializar_territorios(Jogo* jogo);
void inicializar_continentes(Jogo* jogo);
void inicializar_missoes(Jogo* jogo);
void distribuir_territorios(Jogo* jogo);

/* === FUNÇÕES DE ATAQUE === */
int rolar_dados(int num_dados);
int executar_ataque(Territorio* atacante, Territorio* defensor);
int ataque_padrao(Territorio* atacante, Territorio* defensor);
int ataque_blitz(Territorio* atacante, Territorio* defensor);
void processar_ataque(Jogo* jogo, int id_atacante, int id_defensor, FuncaoAtaque func_ataque);

/* === FUNÇÕES DE MISSÃO E VITÓRIA === */
void atribuir_missao_aleatoria(Jogador* jogador);
int verificar_missao_cumprida(Jogo* jogo, Jogador* jogador);
int verificar_vitoria_conquista_total(Jogo* jogo, Jogador* jogador);
int verificar_vitoria_continentes(Jogo* jogo, Jogador* jogador);
int verificar_vitoria_territorios(Jogo* jogo, Jogador* jogador);
int verificar_vitoria_destruir_cor(Jogo* jogo, Jogador* jogador);

/* === FUNÇÕES DE GERENCIAMENTO === */
int territorios_sao_vizinhos(Territorio* t1, Territorio* t2);
int jogador_domina_continente(Jogo* jogo, int jogador_id, int continente_id);
int calcular_bonus_tropas(Jogo* jogo, Jogador* jogador);
void adicionar_tropas(Jogo* jogo, int jogador_id, int territorio_id, int num_tropas);
void mover_tropas(Territorio* origem, Territorio* destino, int num_tropas);

/* === FUNÇÕES DE EXIBIÇÃO === */
void exibir_status_jogo(Jogo* jogo);
void exibir_territorios_jogador(Jogo* jogo, int jogador_id);
void exibir_missao_jogador(Jogador* jogador);
const char* obter_nome_cor(Cor cor);

/* === FUNÇÕES AUXILIARES === */
Territorio* buscar_territorio_por_id(Jogo* jogo, int id);
Jogador* buscar_jogador_por_id(Jogo* jogo, int id);
int contar_territorios_jogador(Jogo* jogo, int jogador_id);

#endif /* WAR_H */
