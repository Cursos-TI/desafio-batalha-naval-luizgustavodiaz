#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (char j = 'A'; j < 'A' + TAMANHO_TABULEIRO; j++) {
        printf("%c ", j); // Imprime as letras das colunas
    }
    printf("\n");
    printf("--");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("--");
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d| ", i); // Imprime os números das linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para posicionar um navio horizontalmente no tabuleiro
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe horizontalmente
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        return 0; // Falha no posicionamento
    }

    // Verifica se há sobreposição com outros navios
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] == 3) {
            printf("Erro: Sobreposição detectada ao posicionar navio horizontal.\n");
            return 0; // Falha no posicionamento
        }
    }

    // Posiciona o navio horizontalmente
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3; // 3 representa parte do navio
    }
    return 1; // Sucesso no posicionamento
}

// Função para posicionar um navio verticalmente no tabuleiro
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe verticalmente
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        return 0; // Falha no posicionamento
    }

    // Verifica se há sobreposição com outros navios
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] == 3) {
            printf("Erro: Sobreposição detectada ao posicionar navio vertical.\n");
            return 0; // Falha no posicionamento
        }
    }

    // Posiciona o navio verticalmente
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3; // 3 representa parte do navio
    }
    return 1; // Sucesso no posicionamento
}

int main() {
    // Declaração do tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);
    printf("Tabuleiro inicial:\n");
    exibirTabuleiro(tabuleiro);

    // Define as coordenadas iniciais do navio horizontal
    int linhaHorizontal = 2;
    int colunaHorizontal = 1;
    printf("Tentando posicionar navio horizontal na linha %d, coluna %d...\n", linhaHorizontal, colunaHorizontal);
    if (posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal)) {
        printf("Navio horizontal posicionado com sucesso.\n");
    }

    // Define as coordenadas iniciais do navio vertical
    int linhaVertical = 5;
    int colunaVertical = 7;
    printf("Tentando posicionar navio vertical na linha %d, coluna %d...\n", linhaVertical, colunaVertical);
    if (posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical)) {
        printf("Navio vertical posicionado com sucesso.\n");
    }

    printf("\nTabuleiro com navios posicionados:\n");
    exibirTabuleiro(tabuleiro);

    // Exemplo de tentativa de posicionamento inválido (fora dos limites)
    printf("Tentando posicionar navio horizontal fora dos limites...\n");
    posicionarNavioHorizontal(tabuleiro, 0, 9);

    // Exemplo de tentativa de posicionamento inválido (sobreposição)
    printf("Tentando posicionar navio vertical sobre o navio horizontal...\n");
    posicionarNavioVertical(tabuleiro, 0, 1);

    printf("\nTabuleiro final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
