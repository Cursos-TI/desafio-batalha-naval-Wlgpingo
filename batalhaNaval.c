#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO 10
// Valor para representar partes do navio no tabuleiro
#define NAVIO 3
// Tamanho fixo dos navios
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se um navio pode ser posicionado
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int horizontal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (horizontal ? 0 : i);
        int c = coluna + (horizontal ? i : 0);
        // Verifica se está dentro dos limites e se a posição está livre
        if (l >= TAMANHO || c >= TAMANHO || tabuleiro[l][c] != 0) {
            return 0; // Não pode posicionar
        }
    }
    return 1; // Pode posicionar
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int horizontal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (horizontal ? 0 : i);
        int c = coluna + (horizontal ? i : 0);
        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais para os navios
    int linhaHorizontal = 2, colunaHorizontal = 3;
    int linhaVertical = 5, colunaVertical = 7;

    // Verifica e posiciona o navio horizontal
    if (podePosicionar(tabuleiro, linhaHorizontal, colunaHorizontal, 1)) {
        posicionarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 1);
    } else {
        printf("Não foi possível posicionar o navio horizontal.\n");
    }

    // Verifica e posiciona o navio vertical
    if (podePosicionar(tabuleiro, linhaVertical, colunaVertical, 0)) {
        posicionarNavio(tabuleiro, linhaVertical, colunaVertical, 0);
    } else {
        printf("Não foi possível posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro com os navios
    exibirTabuleiro(tabuleiro);

    return 0;
}

