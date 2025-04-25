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

#include <stdio.h>

// Definições de constantes
#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3

// Inicializa o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Exibe o tabuleiro na tela
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se é possível posicionar o navio nas direções: 0-horizontal, 1-vertical, 2-diagonal principal (\), 3-diagonal secundária (/)
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;
        if (direcao == 0) c += i;                   // Horizontal
        else if (direcao == 1) l += i;              // Vertical
        else if (direcao == 2) { l += i; c += i; }  // Diagonal principal
        else if (direcao == 3) { l += i; c -= i; }  // Diagonal secundária

        // Verifica se está dentro dos limites e não há sobreposição
        if (l < 0 || l >= TAMANHO || c < 0 || c >= TAMANHO || tabuleiro[l][c] != 0) {
            return 0; // Não pode posicionar
        }
    }
    return 1; // Pode posicionar
}

// Posiciona o navio no tabuleiro na direção informada
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;
        if (direcao == 0) c += i;                   // Horizontal
        else if (direcao == 1) l += i;              // Vertical
        else if (direcao == 2) { l += i; c += i; }  // Diagonal principal
        else if (direcao == 3) { l += i; c -= i; }  // Diagonal secundária

        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Dados dos quatro navios: {linha, coluna, direcao}
    // direcao: 0-horizontal, 1-vertical, 2-diagonal principal (\), 3-diagonal secundária (/)
    int navios[4][3] = {
        {0, 0, 0},  // Horizontal (linha 0, coluna 0)
        {3, 5, 1},  // Vertical (linha 3, coluna 5)
        {6, 6, 2},  // Diagonal principal (linha 6, coluna 6)
        {0, 9, 3}   // Diagonal secundária (linha 0, coluna 9)
    };

    // Tenta posicionar cada navio, validando as posições
    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0];
        int coluna = navios[i][1];
        int direcao = navios[i][2];

        if (podePosicionar(tabuleiro, linha, coluna, direcao)) {
            posicionarNavio(tabuleiro, linha, coluna, direcao);
        } else {
            printf("Erro: Não foi possível posicionar o navio %d nas coordenadas (%d,%d) na direção %d\n", i+1, linha, coluna, direcao);
        }
    }

    #include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define HABILIDADE 5
#define TAM_HABILIDADE 5

// Inicializa o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++)
        for (int j = 0; j < TAMANHO; j++)
            tabuleiro[i][j] = 0;
}

// Exibe o tabuleiro com marcações diferentes para água, navio e habilidade
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 0) printf("~ ");  // Água
            else if (tabuleiro[i][j] == NAVIO) printf("N ");  // Navio
            else if (tabuleiro[i][j] == HABILIDADE) printf("* ");  // Habilidade
            else printf("? ");
        }
        printf("\n");
    }
}

// Verifica se pode posicionar o navio sem ultrapassar bordas ou sobrepor
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;
        if (direcao == 0) c += i;
        else if (direcao == 1) l += i;
        else if (direcao == 2) { l += i; c += i; }
        else if (direcao == 3) { l += i; c -= i; }

        if (l < 0 || l >= TAMANHO || c < 0 || c >= TAMANHO || tabuleiro[l][c] != 0)
            return 0;
    }
    return 1;
}

// Posiciona o navio na direção indicada
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;
        if (direcao == 0) c += i;
        else if (direcao == 1) l += i;
        else if (direcao == 2) { l += i; c += i; }
        else if (direcao == 3) { l += i; c -= i; }

        tabuleiro[l][c] = NAVIO;
    }
}

// Gera matriz cone (formato triangular invertido)
void gerarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int meio = TAM_HABILIDADE / 2;
            matriz[i][j] = (j >= meio - i && j <= meio + i) ? 1 : 0;
        }
    }
}

// Gera matriz cruz
void gerarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            matriz[i][j] = (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) ? 1 : 0;
        }
    }
}

// Gera matriz octaedro (formato de losango)
void gerarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int meio = TAM_HABILIDADE / 2;
            matriz[i][j] = (abs(meio - i) + abs(meio - j) <= meio) ? 1 : 0;
        }
    }
}

// Aplica a matriz da habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int matriz[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    int offset = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (matriz[i][j] == 1) {
                int l = origemLinha + i - offset;
                int c = origemColuna + j - offset;

                if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO && tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = HABILIDADE;
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posiciona 4 navios
    int navios[4][3] = {
        {0, 0, 0}, // Horizontal
        {3, 4, 1}, // Vertical
        {5, 5, 2}, // Diagonal principal
        {1, 8, 3}  // Diagonal secundária
    };

    for (int i = 0; i < 4; i++) {
        if (podePosicionar(tabuleiro, navios[i][0], navios[i][1], navios[i][2])) {
            posicionarNavio(tabuleiro, navios[i][0], navios[i][1], navios[i][2]);
        } else {
            printf("Erro: Navio %d inválido.\n", i + 1);
        }
    }

    // Matrizes de habilidade
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Gerar áreas de efeito
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);      // Posição central do cone
    aplicarHabilidade(tabuleiro, cruz, 7, 2);      // Cruz
    aplicarHabilidade(tabuleiro, octaedro, 5, 7);  // Octaedro

    // Exibir resultado
    exibirTabuleiro(tabuleiro);

    return 0;
}


    // Exibe o tabuleiro final com os navios
    exibirTabuleiro(tabuleiro);

    return 0;
}
