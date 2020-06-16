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
    int Vidas = Vida, o = MusicOn, FaseAtual = 7;
    char movimento;
    while (linha_atual != 14 && coluna_atual != 29){
        system("cls");
        desenharMapa(Vidas);
        movimento = getch();

        if((movimento == 'w') || (movimento == 'W')){
            linha_atual -= 1;
            if (mapa[linha_atual][coluna_atual] == Parede){
                linha_atual += 1;
            }
        }
        if((movimento == 's') || (movimento == 'S')){
            linha_atual += 1;
            if (mapa[linha_atual][coluna_atual] == Parede){
                linha_atual -= 1;
            }
        }
        if((movimento == 'd') || (movimento == 'D')){
            coluna_atual += 1;
            if (mapa[linha_atual][coluna_atual] == Parede){
                coluna_atual -= 1;
            }
        }
        if((movimento == 'a') || (movimento == 'A')){
            coluna_atual -= 1;
            if (mapa[linha_atual][coluna_atual] == Parede){
                coluna_atual += 1;
            }
        }
        if ((linha_atual == 3 && coluna_atual == 2) || (linha_atual ==12 && coluna_atual == 3) || (linha_atual == 11 && coluna_atual == 10) || (linha_atual == 12 && coluna_atual == 24) || (linha_atual == 4 && coluna_atual == 28)){
            system("cls");
            desenharMapa(Vidas);
            LimpaLab();
            printf("\n\n\n\nVocê caiu em um buraco e morreu!\n");
            system("pause");
            Anubis(FaseAtual, Vidas, o);
        }
        if ((linha_atual == 4 && coluna_atual == 12) || (linha_atual == 2 && coluna_atual == 26) || (linha_atual == 7 && coluna_atual == 13)){
            system("cls");
            desenharMapa(Vidas);
            LimpaLab();
            printf("\n\n\n\nVocê pisou em um lugar e percebeu que você ativou uma armadilha, várias flechas com veneno são atiradas contra você e uma acaba pegando!\n");
            system("pause");
            Anubis(FaseAtual, Vidas, o);
        }

    }
    system("cls");
    desenharMapa(Vidas);
    LimpaLab();
    BossSeth(o);
}

void desenharMapa(int Vida){
    int linha, coluna, Vidas = Vida;
    printf("Vidas: %d \n\n\n\n", Vidas);
    for (linha = 0; linha < 15; linha++){
        printf("\t\t\t\t\t\t");
        for (coluna = 0; coluna < 30; coluna++){
            if ((linha == linha_atual) && (coluna == coluna_atual)){
                printf(ANSI_COLOR_RED "P" ANSI_COLOR_RESET);
                continue;
            }
            if (mapa[linha][coluna] == Piso){
                printf(" ");
            }
            if (mapa[linha][coluna] == Parede){
                printf("#");
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

void PrintarLegenda(){
    coordxy(0, 0);
    printf("\n  Após subir o as escadas você se vê dentro de um labirinto, seu objetivo é chegar até a entrada do templo de Hórus.");
    coordxy(85, 5);
    printf("===== Legenda =====\n");
    coordxy(85, 6);
    printf("| P = Player      |\n");
    coordxy(85, 7);
    printf("| B = Buraco      |\n");
    coordxy(85, 8);
    printf("| A = Armadilha   |\n");
    coordxy(85, 9);
    printf("| T = Entrada do  |\n");
    coordxy(85, 10);
    printf("| templo de Hórus |\n");
    coordxy(85, 11);
    printf("===================\n");
    coordxy(82, 14);
    printf(" Teclas de movimentação:\n\n");
    coordxy(82, 16);
    printf("\t     [w]\n");
    coordxy(82, 17);
    printf("\t [a] [s] [d]\n\n");

}
