#include "../../Includes.h"

int coluna_atual = 1, linha_atual = 1;

int mapa[15][30] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                    1,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,1,1,2,2,2,1,1,1,1,1,1,1,1,1,
                    1,1,1,1,2,2,2,2,2,2,1,1,2,1,1,2,1,1,2,1,2,2,1,1,2,2,5,1,1,1,
                    1,2,3,1,2,1,1,2,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,1,
                    1,2,1,1,2,1,1,2,1,1,1,1,5,1,1,2,2,1,2,1,1,2,2,2,2,2,2,2,3,1,
                    1,2,2,2,2,1,1,2,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,
                    1,1,1,2,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,
                    1,1,1,2,1,1,1,1,1,1,1,2,1,5,1,1,1,1,1,1,2,1,1,1,1,1,1,1,2,1,
                    1,1,1,2,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,2,1,1,1,1,2,2,2,2,1,
                    1,2,2,2,1,1,1,1,1,2,1,1,2,2,2,2,2,1,1,1,2,1,1,1,1,2,1,1,1,1,
                    1,2,1,1,1,1,1,1,1,2,1,1,2,1,1,1,2,1,1,1,2,1,1,1,1,2,2,2,1,1,
                    1,2,1,1,1,1,1,1,2,2,3,1,2,1,2,2,2,1,1,1,2,1,1,1,1,1,1,2,1,1,
                    1,2,1,3,1,1,1,1,2,1,1,1,2,1,2,1,1,1,1,1,2,2,2,2,3,1,1,2,1,1,
                    1,2,2,2,1,1,1,1,2,2,2,2,2,1,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,4,
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};


void Fase3Cenario2(int Vida, int MusicOn) {
    int Vidas = Vida, o = MusicOn, FaseAtual = 7, DirecaoPersonagem = 0, ParedeOn = 0;
    char movimento;
    while (linha_atual != 14 && coluna_atual != 29){
        system("cls");
        desenharMapa(Vidas);
        MensagemMovimento(DirecaoPersonagem, ParedeOn, o);
        ParedeOn = 0;
        movimento = getch();

        if((movimento == 'w') || (movimento == 'W')){
            linha_atual -= 1;
            DirecaoPersonagem = 1;
            if (mapa[linha_atual][coluna_atual] == Parede){
                linha_atual += 1;
                ParedeOn = 1;
            }
        }
        if((movimento == 's') || (movimento == 'S')){
            linha_atual += 1;
            DirecaoPersonagem = 2;
            if (mapa[linha_atual][coluna_atual] == Parede){
                linha_atual -= 1;
                ParedeOn = 1;
            }
        }
        if((movimento == 'd') || (movimento == 'D')){
            coluna_atual += 1;
            DirecaoPersonagem = 3;
            if (mapa[linha_atual][coluna_atual] == Parede){
                coluna_atual -= 1;
                ParedeOn = 1;
            }
        }
        if((movimento == 'a') || (movimento == 'A')){
            coluna_atual -= 1;
            DirecaoPersonagem = 4;
            if (mapa[linha_atual][coluna_atual] == Parede){
                coluna_atual += 1;
                ParedeOn = 1;
            }
        }
        if ((linha_atual == 3 && coluna_atual == 2) || (linha_atual ==12 && coluna_atual == 3) || (linha_atual == 11 && coluna_atual == 10) || (linha_atual == 12 && coluna_atual == 24) || (linha_atual == 4 && coluna_atual == 28)){
            system("cls");
            desenharMapa(Vidas);
            LimpaLab();
            coordxy(38, 26);
            printf(ANSI_COLOR_CYAN "=============== Mensagem do Sistema ===============");
            coordxy(38, 27);
            printf("|                                                 |");
            coordxy(38, 28);
            printf("|                                                 |");
            coordxy(38, 29);
            printf("|                                                 |");
            coordxy(38, 30);
            printf("===================================================");
            coordxy(48, 28);
            Pause(ANSI_COLOR_RED "Você caiu em um buraco e morreu!\n" ANSI_COLOR_RESET);
            Anubis(FaseAtual, Vidas, o);
        }
        if ((linha_atual == 4 && coluna_atual == 12) || (linha_atual == 2 && coluna_atual == 26) || (linha_atual == 7 && coluna_atual == 13)){
            system("cls");
            desenharMapa(Vidas);
            LimpaLab();
            coordxy(28, 26);
            printf(ANSI_COLOR_CYAN "============================ Mensagem do Sistema ============================");
            coordxy(28, 27);
            printf("|                                                                           |");
            coordxy(28, 28);
            printf("|                                                                           |");
            coordxy(28, 29);
            printf("|                                                                           |");
            coordxy(28, 30);
            printf("|                                                                           |");
            coordxy(28, 31);
            printf("|                                                                           |");
            coordxy(28, 32);
            printf("=============================================================================");
            coordxy(34, 28);
            printf(ANSI_COLOR_RED "Você pisou em um lugar e percebeu que você ativou uma armadilha,");
            coordxy(31, 30);
            Pause("várias flechas com veneno são atiradas contra você e uma acaba pegando!\n" ANSI_COLOR_RESET);
            Anubis(FaseAtual, Vidas, o);
        }
    }
    system("cls");
    desenharMapa(Vidas);
    LimpaLab();
    BossSeth(Vidas ,o);
}

void desenharMapa(int Vida){
    int linha, coluna, Vidas = Vida;
    PrintVida(Vidas);
    printf("\n\n\n\n\n\n\n");
    for (linha = 0; linha < 15; linha++){
        printf("\t\t\t\t\t\t");
        for (coluna = 0; coluna < 30; coluna++){
            if ((linha == linha_atual) && (coluna == coluna_atual)){
                printf(ANSI_COLOR_DARK_RED "P" ANSI_COLOR_RESET);
                continue;
            }
            if (mapa[linha][coluna] == Piso){
                printf(" ");
            }
            if (mapa[linha][coluna] == Parede){
                printf(ANSI_COLOR_CYAN "#" ANSI_COLOR_RESET);
            }
            if (mapa[linha][coluna] == Buraco){
                printf(ANSI_COLOR_DARK_GRAY "B" ANSI_COLOR_RESET);
            }
            if (mapa[linha][coluna] == Seth){
                printf("T");
            }
            if (mapa[linha][coluna] == Armadilha){
                printf(ANSI_COLOR_DARK_GRAY "A" ANSI_COLOR_RESET);
            }
        }
        printf("\n");
    }
    PrintarLegenda();
}

void LimpaLab(){
    linha_atual = 1;
    coluna_atual = 1;
}

void MensagemMovimento(int DirecaoPlayer, int ParedeOnOff, int MusicOn){
    int o = MusicOn;
    if (DirecaoPlayer == 0){
        coordxy(38, 26);
        printf(ANSI_COLOR_CYAN "=============== Mensagem do Sistema ===============");
        coordxy(38, 27);
        printf("|                                                 |");
        coordxy(38, 28);
        printf("|                                                 |");
        coordxy(38, 29);
        printf("|                                                 |");
        coordxy(38, 30);
        printf("===================================================");
        coordxy(41, 28);
        printf("Nenhuma tecla foi pressionada, até o momento!" ANSI_COLOR_RESET);
    }
    else if (DirecaoPlayer == 1){
        coordxy(38, 26);
        printf(ANSI_COLOR_CYAN "=============== Mensagem do Sistema ===============");
        coordxy(38, 27);
        printf("|                                                 |");
        coordxy(38, 28);
        printf("|                                                 |");
        coordxy(38, 29);
        printf("|                                                 |");
        coordxy(38, 30);
        printf("===================================================");
        coordxy(49, 28);
        printf("Você se movimentou para: \e[0;36mCima" ANSI_COLOR_RESET);
        if (ParedeOnOff == 1){
            coordxy(38, 30);
            printf(ANSI_COLOR_CYAN "|                                                 |");
            coordxy(38, 31);
            printf(ANSI_COLOR_CYAN "|                                                 |");
            coordxy(38, 32);
            printf("===================================================");
            coordxy(49, 30);
            printf("Mas acabou batendo na parede!" ANSI_COLOR_RESET);
        }
    }
    else if (DirecaoPlayer == 2){
        coordxy(38, 26);
        printf(ANSI_COLOR_CYAN "=============== Mensagem do Sistema ===============");
        coordxy(38, 27);
        printf("|                                                 |");
        coordxy(38, 28);
        printf("|                                                 |");
        coordxy(38, 29);
        printf("|                                                 |");
        coordxy(38, 30);
        printf("===================================================");
        coordxy(49, 28);
        printf("Você se movimentou para: \e[0;36mBaixo" ANSI_COLOR_RESET);
        if (ParedeOnOff == 1){
            coordxy(38, 30);
            printf(ANSI_COLOR_CYAN "|                                                 |");
            coordxy(38, 31);
            printf(ANSI_COLOR_CYAN "|                                                 |");
            coordxy(38, 32);
            printf("===================================================");
            coordxy(49, 30);
            printf("Mas acabou batendo na parede!" ANSI_COLOR_RESET);
        }
    }
    else if (DirecaoPlayer == 3){
        coordxy(38, 26);
        printf(ANSI_COLOR_CYAN "=============== Mensagem do Sistema ===============");
        coordxy(38, 27);
        printf("|                                                 |");
        coordxy(38, 28);
        printf("|                                                 |");
        coordxy(38, 29);
        printf("|                                                 |");
        coordxy(38, 30);
        printf("===================================================");
        coordxy(47, 28);
        printf("Você se movimentou para: \e[0;36mEsquerda" ANSI_COLOR_RESET);
        if (ParedeOnOff == 1){
            coordxy(38, 30);
            printf(ANSI_COLOR_CYAN "|                                                 |");
            coordxy(38, 31);
            printf(ANSI_COLOR_CYAN "|                                                 |");
            coordxy(38, 32);
            printf("===================================================");
            coordxy(49, 30);
            printf("Mas acabou batendo na parede!" ANSI_COLOR_RESET);
        }
    }
    else if (DirecaoPlayer == 4){
        coordxy(38, 26);
        printf(ANSI_COLOR_CYAN "=============== Mensagem do Sistema ===============");
        coordxy(38, 27);
        printf("|                                                 |");
        coordxy(38, 28);
        printf("|                                                 |");
        coordxy(38, 29);
        printf("|                                                 |");
        coordxy(38, 30);
        printf("===================================================");
        coordxy(47, 28);
        printf("Você se movimentou para: \e[0;36mDireita");
        if (ParedeOnOff == 1){
            coordxy(38, 30);
            printf(ANSI_COLOR_CYAN "|                                                 |");
            coordxy(38, 31);
            printf(ANSI_COLOR_CYAN "|                                                 |");
            coordxy(38, 32);
            printf("===================================================");
            coordxy(49, 30);
            printf("Mas acabou batendo na parede!" ANSI_COLOR_RESET);
        }
    }
    else {
        coordxy(38, 26);
        printf(ANSI_COLOR_RED "\a================ Mensagem de erro: ================");
        coordxy(38, 27);
        printf("|                                                 |");
        coordxy(38, 28);
        printf("|                                                 |");
        coordxy(38, 29);
        printf("|                                                 |");
        coordxy(38, 30);
        printf("|                                                 |");
        coordxy(38, 31);
        printf("===================================================");
        coordxy(44, 28);
        printf("Erro ao identificar a tecla pressionada\n");
        coordxy(40, 30);
        Pause("Por favor, entre em contado conosco pelo GitHub\n" ANSI_COLOR_RESET);
        Menu(o);
    }
}

void PrintarLegenda(){
    int x = 85, y = 10;
    coordxy(11, 4);
    printf(ANSI_COLOR_CYAN "=== Caixa de Dialógo ==============================================================================================================\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           ===================================================================================================================================" ANSI_COLOR_RESET);
    coordxy(12, 6);
    printf(ANSI_COLOR_DARK_CYAN "  Após subir as escadas você se vê dentro de um labirinto, seu objetivo é chegar até a entrada do templo de Hórus.");
    coordxy(x, y);
    printf(ANSI_COLOR_CYAN "===== Legenda =====\n");
    coordxy(x, y+1);
    printf("|                 |");
    coordxy(x, y+2);
    printf("|                 |");
    coordxy(x, y+3);
    printf("|                 |");
    coordxy(x, y+4);
    printf("|                 |");
    coordxy(x, y+5);
    printf("|                 |");
    coordxy(x, y+6);
    printf("===================\n" ANSI_COLOR_RESET);
    coordxy(x+1, y+1);
    printf(ANSI_COLOR_DARK_CYAN " P = Player      \n");
    coordxy(x+1, y+2);
    printf(" B = Buraco      \n");
    coordxy(x+1, y+3);
    printf(" A = Armadilha   \n");
    coordxy(x+1, y+4);
    printf(" T = Entrada do  \n");
    coordxy(x+1, y+5);
    printf(" templo de Hórus \n");
    coordxy(x-3, y+9);
    printf(ANSI_COLOR_CYAN " Teclas de movimentação:\n\n");
    coordxy(x-3, y+11);
    printf(ANSI_COLOR_DARK_CYAN "\t     [w]\n");
    coordxy(x-3, y+12);
    printf("\t [a] [s] [d]\n\n" ANSI_COLOR_RESET);
}
