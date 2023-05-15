#include <stdio.h>
#include <stdlib.h>

void inicializarTabuleiro(char jogadas[][3]);
void printarTabuleiro(char jogadas[][3]);
void headerJogada();

int main()
{
    // Declaração de variaveis
    char jogadas[3][3];
    int jogadaUser[2];
    int pontuacoes[2] = {0}; // 0: X, 1: O
    char quemJoga;
    int i = 0, j = 0, continuar = 0;

    do
    {
        // Inicializando o jogo
        inicializarTabuleiro(jogadas);
        printarTabuleiro(jogadas);
        int erro = 0;
        char ganhou = ' ';
        do // Até o jogo chegar a 9 rodadas ou alguem ganhar
        {
            for (i = 0; i < 2; i++) // Jogadas do jogador X e do jogador Y
            {
                printf("Onde deseja jogar? (jogue com um espaco entre os numeros)\n");
                do
                {
                    scanf("%d", &jogadaUser[0]);
                    scanf("%d", &jogadaUser[1]);

                    // Se o jogador colocar algum valor menor ou igual a 0 e maior que 3
                    if (jogadaUser[0] <= 0 || jogadaUser[0] > 3)
                    {
                        printf("Insira um valor entre 1 e 3 para o eixo X\n");
                        erro = 1;
                    }
                    else if (jogadaUser[1] <= 0 || jogadaUser[1] > 3)
                    {
                        erro = 1;
                        printf("Insira um valor entre 1 e 3 para o eixo Y\n");
                    }
                    else
                    {
                        // Como foi feito usando matriz reais (desconsiderando o indice 0), preciso igualar a programacao
                        jogadaUser[0]--;
                        jogadaUser[1]--;

                        if (jogadas[jogadaUser[0]][jogadaUser[1]] == ' ') // se nao existir nada na posicao escolhida sera jogado
                        {
                            erro = 0;
                            quemJoga = i == 0 ? 'X' : 'O';
                            jogadas[jogadaUser[0]][jogadaUser[1]] = quemJoga;
                            printarTabuleiro(jogadas);
                        }
                        else
                        {
                            erro = 1;
                            printarTabuleiro(jogadas);
                            printf("Insira uma posicao nao utilizada\n");
                            continue;
                        }
                    }
                } while (erro != 0);
                if (jogadas[0][0] != ' ' && jogadas[0][0] == jogadas[1][1] && jogadas[0][0] == jogadas[2][2])
                {
                    // Valida a diagonal principal
                    ganhou = jogadas[0][0];
                }
                else if (jogadas[0][2] != ' ' && jogadas[0][2] == jogadas[1][1] && jogadas[0][2] == jogadas[2][0])
                {
                    // Valida a diagonal secundaria
                    ganhou = jogadas[0][2];
                }
                else
                {
                    for (j = 0; j < 3; j++)
                    {
                        // Valida as linhas
                        if (jogadas[j][0] != ' ' && jogadas[j][0] == jogadas[j][1] && jogadas[j][1] == jogadas[j][2])
                        {
                            ganhou = jogadas[j][0];
                            j = 3;
                            continue;
                        }
                        // Valida as colunas
                        else if (jogadas[0][j] != ' ' && jogadas[0][j] == jogadas[1][j] && jogadas[1][j] == jogadas[2][j])
                        {
                            ganhou = jogadas[j][0];
                            j = 3;
                            continue;
                        }
                    }
                }
                if (ganhou != ' ')
                {
                    printf("Jogador %c ganhou!\n", ganhou);
                    if (ganhou == 'X')
                    {
                        pontuacoes[0]++;
                    }
                    else
                    {
                        pontuacoes[1]++;
                    }
                    i = 2;
                    continue;
                }
            }
            j++;
            if (j == 9)
            {
                printf("Jogo falhou\n");
            }
        } while (j != 9 && ganhou == ' ');
        printf("Deseja continuar?\n");
        printf("[1]: Sim, continuar!\n");
        printf("[2]: Nao, sair!\n");
        scanf("%d", &continuar);
        if (continuar != 1)
        {
            printf("Obrigado por jogar!\n");
            printf("Pontuacoes finais:\n");
            printf("X: %d pontos\n", pontuacoes[0]);
            printf("O: %d pontos\n", pontuacoes[1]);
        }
    } while (continuar == 1);
    return 0;
}

void headerJogada()
{
    printf("----=(!)=----\n");
    printf("Jogo da velha\n");
    printf("----=(!)=----\n");
}

void inicializarTabuleiro(char jogadas[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            jogadas[i][j] = ' ';
        }
    }
}

void printarTabuleiro(char jogadas[][3])
{
    int i = 0, j = 0;
    // system("cls");
    headerJogada();
    printf("   | 1 | 2 | 3 |\n");
    for (i = 0; i < 3; i++)
    {
        printf(" %d |", i + 1);
        for (j = 0; j < 3; j++)
        {
            printf(" %c |", jogadas[i][j]);
        }
        printf("\n");
    }
}