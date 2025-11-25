# 🎲 Sistema de Cadastro de Territórios - Jogo War

## 📋 Descrição do Projeto

Este projeto implementa um sistema de cadastro de territórios para o jogo War, desenvolvido em linguagem C como parte do desafio de Estrutura de Dados - Nível Novato.

O sistema permite o cadastro de 5 territórios, armazenando informações como nome, cor do exército e quantidade de tropas, utilizando **structs** para organizar os dados de forma estruturada.

## 🎯 Objetivo

Aplicar os conhecimentos de estrutura de dados compostas (structs) em C, praticando:
- Criação e manipulação de structs
- Vetores de structs
- Entrada e saída de dados via terminal
- Organização lógica em programação estruturada

## 🛠️ Tecnologias Utilizadas

- **Linguagem:** C
- **Compilador:** GCC (recomendado)
- **Bibliotecas:** `stdio.h`, `string.h`

## 📂 Estrutura do Projeto

```
war_game/
├── cadastro_territorios.c    # Código principal do sistema
└── README.md                  # Documentação do projeto
```

## 📦 Requisitos Implementados

### Requisitos Funcionais ✅

1. **Criação da struct Territorio:** 
   - Campos: `char nome[30]`, `char cor[10]`, `int tropas`
   
2. **Cadastro de territórios:**
   - Sistema permite cadastrar 5 territórios
   - Entrada de nome, cor do exército e número de tropas
   
3. **Exibição dos dados:**
   - Mostra todos os territórios cadastrados com formatação clara

### Requisitos Não Funcionais ✅

1. **Usabilidade:** Interface simples com mensagens orientativas
2. **Desempenho:** Exibição imediata após cadastro
3. **Documentação:** Código extensivamente comentado
4. **Manutenibilidade:** Nomes claros e código legível

## 🚀 Como Compilar e Executar

### No Windows (usando GCC/MinGW):

```bash
# Compilar
gcc cadastro_territorios.c -o cadastro_territorios

# Executar
cadastro_territorios.exe
```

### No Linux/Mac:

```bash
# Compilar
gcc cadastro_territorios.c -o cadastro_territorios

# Executar
./cadastro_territorios
```

## 💡 Exemplo de Uso

```
========================================
   SISTEMA DE CADASTRO DE TERRITORIOS
           JOGO WAR - NIVEL NOVATO
========================================

Por favor, cadastre 5 territorios:

--- TERRITORIO 1 ---
Nome do territorio: Brasil
Cor do exercito: Azul
Quantidade de tropas: 10

--- TERRITORIO 2 ---
Nome do territorio: Argentina
Cor do exercito: Vermelho
Quantidade de tropas: 8

...

========================================
     TERRITORIOS CADASTRADOS
========================================

TERRITORIO 1:
  Nome........: Brasil
  Cor Exercito: Azul
  Tropas......: 10
----------------------------------------
```

## 📚 Conceitos Aplicados

- **Structs:** Estruturas de dados compostas para agrupar informações relacionadas
- **Vetores de structs:** Armazenamento de múltiplos territórios
- **Entrada de dados:** Uso de `scanf()` e `fgets()` para diferentes tipos de dados
- **Laços de repetição:** `for` para cadastro e exibição
- **Strings em C:** Manipulação com `strcspn()` e `fflush()`

## 👨‍💻 Autor

Desenvolvido como parte do desafio de Estrutura de Dados - Nível Novato

---

# 🎮 Sistema de Inventário - Nível Aventureiro

## 📋 Descrição do Projeto

Esta segunda fase implementa um **Sistema de Inventário Comparativo** para jogos de sobrevivência (estilo Battle Royale), comparando duas estruturas de dados:

- **Vetor (Lista Sequencial)** - Estrutura estática e contígua
- **Lista Encadeada** - Estrutura dinâmica com ponteiros

O sistema simula uma mochila de loot onde o jogador coleta itens essenciais (armas, munições, kits médicos e ferramentas).

## 🎯 Objetivo

Comparar o desempenho de diferentes estruturas de dados através de:
- Análise empírica de operações (inserção, remoção, busca)
- Contador de comparações em buscas
- Diferença entre busca sequencial e busca binária

## 🛠️ Tecnologias e Estruturas

### Estruturas de Dados
```c
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

typedef struct No {
    Item dados;
    struct No* proximo;
} No;
```

### Algoritmos Implementados
- **Busca Sequencial** - O(n)
- **Busca Binária** - O(log n) - apenas para vetor ordenado
- **Bubble Sort** - Ordenação do vetor
- **Inserção/Remoção** - Em vetor e lista encadeada

## 📂 Estrutura do Projeto Atualizada

```
war_game/
├── cadastro_territorios.c     # Nível Novato - Sistema de territórios
├── sistema_inventario.c       # Nível Aventureiro - Sistema de inventário
├── include/
│   ├── war.h                  # Headers do jogo War
│   └── inventario.h           # Headers do sistema de inventário
├── src/
│   ├── inicializacao.c        # Funções de inicialização War
│   ├── inventario_vetor.c     # Implementação com vetor
│   ├── inventario_lista.c     # Implementação com lista encadeada
│   └── inventario_utils.c     # Funções auxiliares
├── bin/                        # Executáveis compilados
└── README.md
```

## 📦 Requisitos Implementados - Nível Aventureiro

### Requisitos Funcionais ✅

1. **Criação de structs:**
   - `Item`: nome, tipo, quantidade
   - `No`: para lista encadeada com ponteiro para próximo
   
2. **Duas implementações paralelas:**
   - Sistema com vetor (até 10 itens)
   - Sistema com lista encadeada (dinâmico)
   
3. **Operações implementadas:**
   - Inserir item ✅
   - Remover item por nome ✅
   - Listar todos os itens ✅
   - Buscar item (sequencial) ✅
   - Ordenar vetor (Bubble Sort) ✅
   - Buscar item (binária no vetor) ✅
   
4. **Contador de operações:**
   - Exibe número de comparações em cada busca
   - Permite comparar eficiência dos algoritmos

### Requisitos Não Funcionais ✅

1. **Usabilidade:** Menu interativo com instruções claras
2. **Desempenho:** Operações executadas instantaneamente (<2s)
3. **Documentação:** Código extensivamente comentado
4. **Manutenibilidade:** Código modular em arquivos separados
5. **Gerenciamento de memória:** Alocação dinâmica correta com `malloc()` e `free()`

## 🚀 Como Compilar e Executar

### Opção 1: Compilação Manual (Windows com MinGW/GCC)

```bash
# Compilar o Sistema de Inventário (Nível Aventureiro)
gcc -o bin/inventario.exe sistema_inventario.c src/inventario_vetor.c src/inventario_lista.c src/inventario_utils.c -Iinclude

# Executar
bin\inventario.exe
```

### Opção 2: Compilação Manual (Linux/Mac)

```bash
# Compilar
gcc -o bin/inventario sistema_inventario.c src/inventario_vetor.c src/inventario_lista.c src/inventario_utils.c -Iinclude

# Executar
./bin/inventario
```

### Sistema de Territórios (Nível Novato)

```bash
# Compilar
gcc cadastro_territorios.c -o cadastro_territorios

# Executar
./cadastro_territorios
```

## 💡 Exemplo de Uso - Sistema de Inventário

```
========================================
  SISTEMA DE INVENTARIO - MOCHILA LOOT
      NIVEL AVENTUREIRO
========================================

           MENU PRINCIPAL
========================================
  [1] Mochila com VETOR
  [2] Mochila com LISTA ENCADEADA
  [0] Sair do sistema
========================================

--- ADICIONAR ITEM ---
Nome do item: AK-47
Tipo: arma
Quantidade: 1

[SUCESSO] Item 'AK-47' adicionado a mochila!

--- BUSCAR ITEM (SEQUENCIAL) ---
[SUCESSO] Item encontrado!
[ANALISE] Numero de comparacoes: 3

--- BUSCAR ITEM (BINARIA) ---
[SUCESSO] Item encontrado!
[ANALISE] Numero de comparacoes: 1
[INFO] A busca binaria e muito mais eficiente!
```

## 📚 Conceitos Aplicados - Nível Aventureiro

### Estruturas de Dados
- **Vetor/Array:** Acesso direto O(1), inserção/remoção O(n)
- **Lista Encadeada:** Inserção O(1), busca O(n), uso eficiente de memória

### Algoritmos de Busca
- **Busca Sequencial:** Percorre elemento por elemento - O(n)
- **Busca Binária:** Divide e conquista - O(log n)

### Algoritmos de Ordenação
- **Bubble Sort:** Algoritmo simples de ordenação - O(n²)

### Ponteiros e Alocação Dinâmica
- `malloc()` para alocação de nós
- `free()` para liberação de memória
- Manipulação de ponteiros em lista encadeada

### Análise de Complexidade
- Contador de operações para análise empírica
- Comparação prática entre estruturas

## 🔍 Diferenças entre as Estruturas

| Operação | Vetor | Lista Encadeada |
|----------|-------|----------------|
| Acesso direto | ✅ O(1) | ❌ O(n) |
| Inserção no início | ❌ O(n) | ✅ O(1) |
| Busca | O(n) ou O(log n)* | O(n) |
| Ordenação | ✅ Possível | ❌ Complexo |
| Uso de memória | Fixo | Dinâmico |

*O(log n) apenas se ordenado (busca binária)

## 👨‍💻 Autor

Desenvolvido como parte dos desafios de Estrutura de Dados:
- **Nível Novato:** Sistema de cadastro de territórios (War)
- **Nível Aventureiro:** Sistema de inventário comparativo

## 📝 Observações

Este projeto demonstra na prática a importância da escolha correta de estruturas de dados para diferentes cenários. O sistema permite:
- Experimentar com diferentes estruturas
- Visualizar o número de comparações em tempo real
- Compreender as vantagens e desvantagens de cada abordagem

Próximos níveis incluirão:
- Árvores binárias de busca
- Tabelas hash
- Grafos para representação de mapas

## 📄 Licença

Este projeto é desenvolvido para fins educacionais.
