#include <stdio.h>

// --- Constantes para o tabuleiro ---

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define EFEITO 5


// --- Funções de inicialização e exibição ---


// Inicializa todas as posições do tabuleiro com AGUA

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {

        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {

            tabuleiro[i][j] = AGUA;

        }

    }

}

// Exibe o tabuleiro com representações visuais

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {

    // Imprime cabeçalhos de coluna (A a J)

    printf("\n   ");

    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {

        printf("%3c", 'A' + j); // AQUI FZ UM CALCULO DE A + 0 = A; A + 1 = B ASSIM POR DIANTE E DEFINE A COLUNA

    }

    printf("\n");


    // Imprime as linhas com cabeçalhos de linha e conteúdo

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {

        printf("%2d ", i);  // AQUI DEFINE A LINHA 0 A 9

        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {

            if (tabuleiro[i][j] == AGUA) {

                printf("  0"); // Água

            } else if (tabuleiro[i][j] == NAVIO) {

                printf("  3"); // Navio

            } else if (tabuleiro[i][j] == EFEITO) {

                printf("  5"); // Efeito da habilidade

            } else {

                printf("%3d", tabuleiro[i][j]); // Outros valores

            }

        }

        printf("\n");

    }

}

// --- Funções para criar as matrizes de habilidades ---


// Cria a matriz para a habilidade de CONE

void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {

    int centro = TAMANHO_HABILIDADE / 2;  // CENTRO = 5 / 2; RESUL EM CENTRO = 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {

            habilidade[i][j] = 0; // BOOLEANO FALSO PARA AREAS NAO AFETADAS

        }

    }

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (int j = centro - i; j <= centro + i; j++) {

            if (j >= 0 && j < TAMANHO_HABILIDADE) {

                habilidade[i][j] = 1; // BOOLEANO VERDADEIRO PARA AREAS AFETADAS

            }

        }

    }

}

// Cria a matriz para a habilidade de CRUZ

void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {

    int centro = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {

            habilidade[i][j] = 0;

        }

    }

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {

        habilidade[centro][i] = 1; // Linha horizontal

        habilidade[i][centro] = 1; // Linha vertical

    }

}

// Cria a matriz para a habilidade de OCTAEDRO

#include <stdio.h>

#define TAMANHO_HABILIDADE 5

void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {

    int centro = TAMANHO_HABILIDADE / 2;

    int diferente_centro_i, diferente_centro_j;

   

    // Inicializa a matriz com 0

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {

            habilidade[i][j] = 0;

        }

    }


    // Preenche o losango

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {

           

            // Calcula a diferença entre a posição atual e o centro

            diferente_centro_i = i - centro;

            diferente_centro_j = j - centro;

           

            // Converte a diferença para valor positivo

            if (diferente_centro_i < 0) {  // if (dif_centro_i < 0): Se a diferença for negativa, a variável dif_centro_i é multiplicada por -1 (-dif_centro_i) para torná-la positiva.

                diferente_centro_i = -diferente_centro_i;

            }

            if (diferente_centro_j < 0) {

                diferente_centro_j = -diferente_centro_j;

            }



            // Verifica a condição do losango

            if (diferente_centro_i + diferente_centro_j <= centro) {

                habilidade[i][j] = 1;

            }

        }

    }

}


// --- Funções de sobreposição ---

void sobreporHabilidade(

    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int matriz_habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],

    int linha_central,

    int coluna_central) {

    int tamanho_metade = TAMANHO_HABILIDADE / 2;

    int linha_inicio = linha_central - tamanho_metade; // linha_ini = linha_cen(0) - tamanho_me(2) = linha_ini = 2

    int coluna_inicio = coluna_central - tamanho_metade; // o memsmo vale para coluna

    for (int linha_habilidade = 0; linha_habilidade < TAMANHO_HABILIDADE; linha_habilidade++) {

        for (int coluna_habilidade = 0; coluna_habilidade < TAMANHO_HABILIDADE; coluna_habilidade++) {

            int linha_tabuleiro = linha_inicio + linha_habilidade; // linha_Tab =  linha_ini(2) + linha_hab que incrementa o valor 1 que começa no 0 ate se torna falso(6) entao vai de 0 a 5

            int coluna_tabuleiro = coluna_inicio + coluna_habilidade;

            if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&

                coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO) {

               

                if (matriz_habilidade[linha_habilidade][coluna_habilidade] == 1) {

                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = EFEITO;

                }

            }

        }

    }

}

int main() {

    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    int habilidade_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    int habilidade_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    int habilidade_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Cria as matrizes de habilidades uma única vez

    criarHabilidadeCone(habilidade_cone);

    criarHabilidadeCruz(habilidade_cruz);

    criarHabilidadeOctaedro(habilidade_octaedro);

    // --- Exemplo 1: Navios e Habilidade CONE ---

    inicializarTabuleiro(tabuleiro);

    // Adiciona navios

    for (int i = 0; i < 3; i++) { tabuleiro[2][7 + i] = NAVIO; } // horizontal

    for (int i = 0; i < 3; i++) { tabuleiro[6 + i][1] = NAVIO; } // vertical

    printf("\n--- Tabuleiro com navios e habilidade de CONE (origem 3, 4) ---\n");

    sobreporHabilidade(tabuleiro, habilidade_cone, 3, 4);

    exibirTabuleiro(tabuleiro);

    // --- Exemplo 2: Navios e Habilidade CRUZ ---

    inicializarTabuleiro(tabuleiro);

    // Adiciona navios

    for (int i = 0; i < 3; i++) { tabuleiro[4 - i][5 - i] = NAVIO; } // diagonal

    printf("\n--- Tabuleiro com navios e habilidade de CRUZ (origem 7, 7) ---\n");

    sobreporHabilidade(tabuleiro, habilidade_cruz, 7, 7);

    exibirTabuleiro(tabuleiro);

    // --- Exemplo 3: Navios e Habilidade OCTAEDRO ---

    inicializarTabuleiro(tabuleiro);

    // Adiciona navios

    for (int i = 0; i < 3; i++) { tabuleiro[7 + i][9 - i] = NAVIO; } // diagonal

    printf("\n--- Tabuleiro com navios e habilidade de OCTAEDRO (origem 5, 5) ---\n");

    sobreporHabilidade(tabuleiro, habilidade_octaedro, 5, 5);

    exibirTabuleiro(tabuleiro);

    return 0;

}