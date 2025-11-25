#include "../include/war.h"

/**
 * Cria e inicializa um novo jogo com alocação dinâmica de memória
 */
Jogo* criar_jogo(int num_jogadores) {
    if (num_jogadores < 3 || num_jogadores > MAX_JOGADORES) {
        printf("Erro: Número de jogadores deve ser entre 3 e %d\n", MAX_JOGADORES);
        return NULL;
    }
    
    // Alocação dinâmica da estrutura principal
    Jogo* jogo = (Jogo*)malloc(sizeof(Jogo));
    if (jogo == NULL) {
        printf("Erro: Falha ao alocar memória para o jogo\n");
        return NULL;
    }
    
    // Inicializa contadores
    jogo->num_jogadores = num_jogadores;
    jogo->num_territorios = 42;
    jogo->num_continentes = 6;
    jogo->turno_atual = 0;
    
    // Alocação dinâmica para territórios usando calloc (inicializa com zeros)
    jogo->territorios = (Territorio*)calloc(jogo->num_territorios, sizeof(Territorio));
    if (jogo->territorios == NULL) {
        printf("Erro: Falha ao alocar memória para territórios\n");
        free(jogo);
        return NULL;
    }
    
    // Alocação dinâmica para jogadores
    jogo->jogadores = (Jogador*)malloc(num_jogadores * sizeof(Jogador));
    if (jogo->jogadores == NULL) {
        printf("Erro: Falha ao alocar memória para jogadores\n");
        free(jogo->territorios);
        free(jogo);
        return NULL;
    }
    
    // Inicializa jogadores
    for (int i = 0; i < num_jogadores; i++) {
        jogo->jogadores[i].id = i;
        snprintf(jogo->jogadores[i].nome, MAX_NOME, "Jogador %d", i + 1);
        jogo->jogadores[i].cor = (Cor)i;
        jogo->jogadores[i].num_territorios = 0;
        jogo->jogadores[i].num_tropas_disponiveis = 0;
        jogo->jogadores[i].ativo = 1;
    }
    
    return jogo;
}

/**
 * Libera toda a memória alocada dinamicamente
 */
void destruir_jogo(Jogo* jogo) {
    if (jogo == NULL) return;
    
    if (jogo->territorios != NULL) {
        free(jogo->territorios);
    }
    
    if (jogo->jogadores != NULL) {
        free(jogo->jogadores);
    }
    
    free(jogo);
}

/**
 * Inicializa os territórios do jogo War (versão simplificada)
 */
void inicializar_territorios(Jogo* jogo) {
    if (jogo == NULL || jogo->territorios == NULL) return;
    
    // Exemplos de territórios da América do Sul
    const char* nomes_territorios[] = {
        "Brasil", "Argentina", "Peru", "Venezuela",
        "Alaska", "Vancouver", "California", "Texas", "Nova York", "Groelandia",
        "Inglaterra", "Suecia", "Alemanha", "Franca", "Polonia", "Moscou",
        "Egito", "Argelia", "Congo", "Africa do Sul", "Madagascar", "Somalia",
        "Oriente Medio", "Aral", "Omsk", "Dudinka", "Siberia", "Tchita",
        "Mongolia", "Vladivostok", "China", "India", "Japao", "Vietna",
        "Borneo", "Australia", "Sumatra", "Nova Guine"
    };
    
    for (int i = 0; i < jogo->num_territorios && i < 38; i++) {
        jogo->territorios[i].id = i;
        strncpy(jogo->territorios[i].nome, nomes_territorios[i], MAX_NOME - 1);
        jogo->territorios[i].nome[MAX_NOME - 1] = '\0';
        jogo->territorios[i].num_tropas = 0;
        jogo->territorios[i].jogador_id = -1;
        jogo->territorios[i].num_vizinhos = 0;
        
        // Define continente (simplificado)
        if (i < 4) jogo->territorios[i].continente_id = 0;  // América do Sul
        else if (i < 10) jogo->territorios[i].continente_id = 1;  // América do Norte
        else if (i < 16) jogo->territorios[i].continente_id = 2;  // Europa
        else if (i < 22) jogo->territorios[i].continente_id = 3;  // África
        else if (i < 34) jogo->territorios[i].continente_id = 4;  // Ásia
        else jogo->territorios[i].continente_id = 5;  // Oceania
    }
    
    // Adiciona alguns vizinhos (exemplo simplificado)
    // Brasil (0)
    jogo->territorios[0].vizinhos[0] = 1;  // Argentina
    jogo->territorios[0].vizinhos[1] = 2;  // Peru
    jogo->territorios[0].vizinhos[2] = 3;  // Venezuela
    jogo->territorios[0].num_vizinhos = 3;
    
    // Argentina (1)
    jogo->territorios[1].vizinhos[0] = 0;  // Brasil
    jogo->territorios[1].vizinhos[1] = 2;  // Peru
    jogo->territorios[1].num_vizinhos = 2;
    
    // Peru (2)
    jogo->territorios[2].vizinhos[0] = 0;  // Brasil
    jogo->territorios[2].vizinhos[1] = 1;  // Argentina
    jogo->territorios[2].vizinhos[2] = 3;  // Venezuela
    jogo->territorios[2].num_vizinhos = 3;
}

/**
 * Inicializa os continentes com suas propriedades
 */
void inicializar_continentes(Jogo* jogo) {
    if (jogo == NULL) return;
    
    // América do Sul
    jogo->continentes[0].id = 0;
    strcpy(jogo->continentes[0].nome, "America do Sul");
    jogo->continentes[0].bonus_tropas = 2;
    jogo->continentes[0].num_territorios = 4;
    
    // América do Norte
    jogo->continentes[1].id = 1;
    strcpy(jogo->continentes[1].nome, "America do Norte");
    jogo->continentes[1].bonus_tropas = 5;
    jogo->continentes[1].num_territorios = 6;
    
    // Europa
    jogo->continentes[2].id = 2;
    strcpy(jogo->continentes[2].nome, "Europa");
    jogo->continentes[2].bonus_tropas = 5;
    jogo->continentes[2].num_territorios = 6;
    
    // África
    jogo->continentes[3].id = 3;
    strcpy(jogo->continentes[3].nome, "Africa");
    jogo->continentes[3].bonus_tropas = 3;
    jogo->continentes[3].num_territorios = 6;
    
    // Ásia
    jogo->continentes[4].id = 4;
    strcpy(jogo->continentes[4].nome, "Asia");
    jogo->continentes[4].bonus_tropas = 7;
    jogo->continentes[4].num_territorios = 12;
    
    // Oceania
    jogo->continentes[5].id = 5;
    strcpy(jogo->continentes[5].nome, "Oceania");
    jogo->continentes[5].bonus_tropas = 2;
    jogo->continentes[5].num_territorios = 4;
}

/**
 * Distribui territórios aleatoriamente entre os jogadores
 */
void distribuir_territorios(Jogo* jogo) {
    if (jogo == NULL) return;
    
    srand(time(NULL));
    
    int tropas_iniciais[] = {35, 30, 25, 20, 15};  // Baseado no número de jogadores
    int tropas_por_jogador = tropas_iniciais[jogo->num_jogadores - 3];
    
    // Distribui territórios em round-robin
    for (int i = 0; i < jogo->num_territorios; i++) {
        int jogador_id = i % jogo->num_jogadores;
        jogo->territorios[i].jogador_id = jogador_id;
        jogo->territorios[i].num_tropas = 1;
        jogo->jogadores[jogador_id].num_territorios++;
    }
    
    // Distribui tropas restantes
    for (int i = 0; i < jogo->num_jogadores; i++) {
        jogo->jogadores[i].num_tropas_disponiveis = 
            tropas_por_jogador - jogo->jogadores[i].num_territorios;
    }
}

/**
 * Atribui missões aleatórias aos jogadores
 */
void inicializar_missoes(Jogo* jogo) {
    if (jogo == NULL) return;
    
    srand(time(NULL));
    
    for (int i = 0; i < jogo->num_jogadores; i++) {
        atribuir_missao_aleatoria(&jogo->jogadores[i]);
    }
}
