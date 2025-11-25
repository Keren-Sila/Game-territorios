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

## 📝 Observações

Este é o primeiro passo do projeto War estruturado. As funcionalidades serão expandidas nos próximos níveis, incluindo:
- Sistema de ataques
- Ponteiros e alocação dinâmica
- Missões estratégicas
- Condições de vitória

## 📄 Licença

Este projeto é desenvolvido para fins educacionais.
