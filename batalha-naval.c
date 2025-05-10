#include <stdio.h>

// DEFININDO TAMANHO DO ARRAY DAS CORDENADAS(X, Y) E DO TAMANHO DAS LINHAS E COLUNAS DO TABULEIRO;
#define CORD 2
#define TABULEIRO 10

// prototipo das funcoes;
void exibirTabuleiro(char tabuleiro[][TABULEIRO]);
void coletarCordenadas(int cordenadas_navio1[]);
void exibirLegenda();

// funcao principal
int main(){

    // variavel que sera usada para verificar se o usuario deseja continuar a execucao do programa
    int cont;

    // Declarando os arrays que vai receber as corrdenadas do navio1(X, Y);
    int cordenadas_navio1[CORD];

    // // TABULEIRO QUE NAO VAI SER EXIBIDO AO USUARIO E SERVE APENAS PARA DECLARAR AS POSICOES DOS NAVIOS
    int tabuleiro[TABULEIRO][TABULEIRO] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 3, 3, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    // TABULEIRO QUE VAI SER EXIBIDO AO USUARIO SEM REVELAR AS POSICOES DOS NAVIOS
    // ESSE TABULEIRO VAI SER ATUALIZADO CASO ACERTE OU ERRE A POSICAO DOS NAVIOS
    char tabuleiro2[TABULEIRO][TABULEIRO] = {
        {'A','A','A','A','A','A','A','A','A','A'},
        {'A','A','A','A','A','A','A','A','A','A'},
        {'A','A','A','A','A','A','A','A','A','A'},
        {'A','A','A','A','A','A','A','A','A','A'},
        {'A','A','A','A','A','A','A','A','A','A'},
        {'A','A','A','A','A','A','A','A','A','A'},
        {'A','A','A','A','A','A','A','A','A','A'},
        {'A','A','A','A','A','A','A','A','A','A'},
        {'A','A','A','A','A','A','A','A','A','A'},
        {'A','A','A','A','A','A','A','A','A','A'}
    };

    // titulo do tabuleiro inicial
    printf("\n------------------------ TABULEIRO INICIAL BATALHA NAVAL ------------------------\n\n");

    // loop do while que executa o programa uma vez e executar novamente quando solicitado
    do
    {

        exibirTabuleiro(tabuleiro2); // exibe o tabuleiro de exibicao
        exibirLegenda(); // exibe legenda da tabela

        //  funcao de entrada de dados do usuario
        coletarCordenadas(cordenadas_navio1);

        // verifica se a posX(linha) e posY(coluna) estao entre 0 e 9(<10) e se as cordenadas ja foram digitadas
        if((cordenadas_navio1[0] >=0 && cordenadas_navio1[0]<TABULEIRO) && (cordenadas_navio1[1] >=0 && cordenadas_navio1[1]<TABULEIRO) && !((tabuleiro2[cordenadas_navio1[0]][cordenadas_navio1[1]] == 'X' || tabuleiro2[cordenadas_navio1[0]][cordenadas_navio1[1]] == 'N')))
        {
            // verificar se nas cordenadas digitadas se encontra um navio
            if(tabuleiro[cordenadas_navio1[0]][cordenadas_navio1[1]] == 3){

                // Atualizando o tabuleiro de exibição com 'N' de Navio Encontrado;
                tabuleiro2[cordenadas_navio1[0]][cordenadas_navio1[1]] = 'N';

                // exibe o titulo do tabuleiro
                printf("\n------------------------ TABULEIRO ATUALIZADO ------------------------\n\n");
                exibirTabuleiro(tabuleiro2);

                // imprimindo o acerto do palpite;
                printf("\n------------------------ RESULTADO DO PALPITE ------------------------\n\n");
                printf("\t\tAcertou! Navio encontrado!!!\n\n");
                printf("------------------------ RESULTADO DO PALPITE ------------------------\n");
            }
            else
            {
                // imprimindo o erro do palpite;
                printf("\n\n------------------------ RESULTADO DO PALPITE ------------------------\n\n");
                printf("\t\tTiro na agua!\n\n");
                printf("------------------------ RESULTADO DO PALPITE ------------------------\n");

                // Atualiza o tabuleiro de exibição com 'X' de Tiro na Agua;
                tabuleiro2[cordenadas_navio1[0]][cordenadas_navio1[1]] = 'X';
            }
        }
        else
        {
            // EXIBE UM ALERTA COM CODIGO DO ERRO ESPECIFICADO
            printf("\n------------------------ ERRO 1010F ------------------------\n\n");
            printf("\t\tCordenadas invalidas ou ja digitadas!!!\n\n"); // exibe que as cordenadas sao invalidas ou ja foram digitadas
            printf("------------------------ ERRO 1010F ------------------------\n");
        }


        // pergunta ao usuario se ele quer continuar o programa
        printf("\nDESEJA CONTINUAR?\n[SIM] -> digite 1\n[NAO] -> Digite outro numero\n");
        fflush(stdin); // limpa o buffer do teclado;
        scanf("%d", &cont);


        // exibe o titulo do tabuleiro caso o usuario deseje continuar o programa(o if verifica isso)
        if(cont == 1)
        {
            printf("\n------------------------ TABULEIRO ATUALIZADA ------------------------\n\n");
        }

    }while(cont == 1); // executa o loop(programa) novamente caso o usuario digite 1(sim)

    // mensagem de saida do programa
    printf("\n------------------------ ATE A PROXIMA ------------------------\n\n");
    printf("\t\t Saindo do programa...\n\n");
    printf("------------------------ FIM DO PROGRAMA ------------------------\n\n");

    // impede que a janeja feche quando o '.exe' e executado
    getchar();
    getchar();

    // retorna 0 caso o programa funcione sem dar erro
    return 0;
}

// funcao que exibe o tabuleiro de exibicao
void exibirTabuleiro(char tabuleiro2[][TABULEIRO]){

    //for que percorre as linha e colunas da matriz e exibe o elemento da posicao especificada
    for(int i=0; i<TABULEIRO; i++)
    {
        for(int j = 0; j<TABULEIRO; j++)
        {
            printf("  | %c | ", tabuleiro2[i][j]);
        }
        // pula uma linha depois de exibir o ultimo elemento da linha do tabuleiro
        printf("\n");
    }
}

// funcao que coleta os dados das cordenadas do usuario
void coletarCordenadas(int cordenadas_navio1[]){
    int posX, posY;

    // recebe a posicao da linha
    printf("\nDigite a posicao da linha:");
    fflush(stdin); // limpa o buffer do teclado;
    scanf("%d", &posX);

    // recebe a posicao da coluna
    printf("\nDigite a posicao da coluna:");
    fflush(stdin); // limpa o buffer do teclado;
    scanf("%d", &posY);

    // pula uma linha
    printf("\n");

    // atribue a posicao da linha ao primeiro elemento do array
    cordenadas_navio1[0] = posX;
    // atribue a posicao da coluna ao segundo elemento do array
    cordenadas_navio1[1] = posY;
}

// funcao que exibe a legenda do tabuleiro
void exibirLegenda(){

    printf("\n------------------------ LEGENDA DO TABULEIRO ------------------------\n\n");
    printf("A == AREA NEUTRA\n");
    printf("N == NAVIO ENCONTRADO\n");
    printf("X == TIRO NA AGUA\n");
    printf("\n-------------------------------------------------------------------\n");
}
