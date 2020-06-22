#include "../../Menu/Includes.h"

void Fase2(int Vida, int MusicOn)
{
    system("cls");
    int opcao = 0, FaseAtual = 2, Acertos = 0, Vidas = Vida, o = MusicOn;
    coordxy(0, 0);
    PrintVida(Vidas);
    char Text1[] = ANSI_COLOR_DARK_CYAN " Você se depara com uma entrada, anda até ela e quando está chegando, o chão começa a tremer. De repente\n";
    char TextComp[] = "você percebe que alguns pisos não tremem e eles serão o seu caminho até a entrada.\n\n" ANSI_COLOR_RESET;
    printf(ANSI_COLOR_CYAN "  =========== Caixa de Diálogo ===============================================================================\n  |                                                                                                          |\n  |                                                                                                          |\n  |                                                                                                          |\n  |                                                                                                          |\n  |                                                                                                          |\n  ============================================================================================================\n\n" ANSI_COLOR_RESET);
    coordxy(4, 5);
    SlowText(Text1);
    coordxy(4, 7);
    SlowText(TextComp);
Acerto:
    fflush(stdin);
    coordxy(0, 15);
    printf(ANSI_COLOR_CYAN "================================\n|  Passos:                     |\n|                              |\n================================" ANSI_COLOR_RESET);
    if (Acertos == 0)
    {
        coordxy(2,17);
        printf(ANSI_COLOR_DARK_CYAN " Vá ao maxímo para esquerda." ANSI_COLOR_RESET);
        coordxy(49,14);
        printf(ANSI_COLOR_CYAN "== Primeiro Piso == \n" ANSI_COLOR_RESET);
    }
    if (Acertos == 1)
    {
        coordxy(2,17);
        printf(ANSI_COLOR_DARK_CYAN " Quadruplique!!              " ANSI_COLOR_RESET);
        coordxy(49,14);
        printf(ANSI_COLOR_CYAN "== Segundo Piso == \n" ANSI_COLOR_RESET);
    }
    if (Acertos == 2)
    {
        coordxy(2,17);
        printf(ANSI_COLOR_DARK_CYAN " Divida por dois.            " ANSI_COLOR_RESET);
        coordxy(49,14);
        printf(ANSI_COLOR_CYAN "== Terceiro Piso == \n" ANSI_COLOR_RESET);
    }
    if (Acertos == 3)
    {
        coordxy(2, 17);
        printf(ANSI_COLOR_DARK_CYAN " Adicione um.              " ANSI_COLOR_RESET);
        coordxy(49, 14);
        printf(ANSI_COLOR_CYAN "== Quarto Piso ==       \n" ANSI_COLOR_RESET);
    }
    coordxy(19,14);
    printf(ANSI_COLOR_CYAN "\n\t\t\t\t\t====================================\n\t\t\t\t\t|  \e[0;36m1         2         3         4\e[1;36m |\n\t\t\t\t\t|        Posição do jogador        |\n\t\t\t\t\t====================================\n" ANSI_COLOR_RESET);
    opcao = SetaLeftRight(41, 16, 4, 10, ANSI_COLOR_DARK_RED ">" ANSI_COLOR_RESET, " ");

    switch (opcao)
    {
    case 1:
        if (Acertos == 0)
        {
            char Acerto1[] = ANSI_COLOR_DARK_CYAN "\n\n   Você acertou e passou para o próximo piso           \n" ANSI_COLOR_RESET;
            Acertos++;
            Pause(SlowText(Acerto1));
            goto Acerto;
        }
        else
        {
            ErrorFase2(Vidas, o);
        }
    case 2:
        if (Acertos == 2)
        {
            char Acerto3[] = ANSI_COLOR_DARK_CYAN "\n\n   Você acertou, por pouco!                            \n" ANSI_COLOR_RESET;
            Acertos++;
            Pause(SlowText(Acerto3));
            goto Acerto;
        }
        else
        {
            ErrorFase2(Vidas, o);
        }
    case 3:
        if (Acertos == 3)
        {
            char Acerto4[] = ANSI_COLOR_DARK_CYAN "\n\n   Você finalmente passou sem cair em nenhuma armadilha\n" ANSI_COLOR_RESET;
            Pause(SlowText(Acerto4));
            system("cls");
            Fase3(Vidas, o);
        }
        else
        {
            ErrorFase2(Vidas, o);
        }
    case 4:
        if (Acertos == 1)
        {
            char Acerto2[] = ANSI_COLOR_DARK_CYAN "\n\n   Você acertou, tome cuidado com os pisos falsos      \n" ANSI_COLOR_RESET;
            Acertos++;
            Pause(SlowText(Acerto2));
            goto Acerto;
        }
        else
        {
            ErrorFase2(Vidas, o);
        }
    }
}

void ErrorFase2(int Vida, int MusicOn)     // Função que é chamada quando o usuário erra o piso da Fase 2  //
{
    int FaseAtual = 2, Vidas = Vida, o = MusicOn;
    char ErroPiso[] = ANSI_COLOR_DARK_CYAN "\n\n   Você pisou em um lugar que não era seguro, o chão desmoronou, e você morreu com a queda.\n" ANSI_COLOR_RESET;
    Pause(SlowText(ErroPiso));
    Anubis(FaseAtual, Vidas, o);
}
