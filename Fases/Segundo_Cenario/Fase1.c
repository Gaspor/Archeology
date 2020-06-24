#include "../../Menu/Includes.h"

void Fase1Cenario2(int Vida, int MusicOn)
{
    int opcao = 0, FaseAtual = 5, Vidas = Vida, o = MusicOn;
    char RespostaChar[200];

    if (o == 0)
        PlaySound(TEXT("null.wav"), NULL, SND_ASYNC);
    else
        PlaySound(TEXT("Cenario2.wav"), NULL, SND_ASYNC|SND_LOOP);

    system("cls");
    PrintVida(Vidas);
    char Text1Fase1[] = ANSI_COLOR_DARK_CYAN "Primeiramente, você deve se perguntar onde nasce o sol." ANSI_COLOR_RESET;
    printf(ANSI_COLOR_CYAN "=== Caixa de dialogo =======================================\n|                                                          |\n|                                                          |\n|                                                          |\n============================================================" ANSI_COLOR_RESET);

    coordxy(3, 5);
    SlowText(Text1Fase1);
    coordxy(0, 9);
    printf(ANSI_COLOR_CYAN "===============\n|             |\n|             |\n|             |\n|             |\n===============" ANSI_COLOR_RESET);
    coordxy(4, 10);
    printf(ANSI_COLOR_DARK_CYAN "N (norte)");
    coordxy(4, 11);
    printf("S (sul)");
    coordxy(4, 12);
    printf("L (leste)");
    coordxy(4, 13);
    printf("O (oeste)" ANSI_COLOR_RESET);
    opcao = SetaUpDown(10, 1, 4, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

    switch (opcao)
    {
    case 3:
        system("cls");
        PrintVida(Vidas);
        char Texto4[] = ANSI_COLOR_DARK_CYAN "Correto, mas não é apenas isso, o Templo de Hórus não é tão fácil de encontrar, então me responda novamente.\n\n";
        char Texto5[] = "Se você olhar na direção em que o sol nasce, qual é a direção que fica à sua direita?\n\n" ANSI_COLOR_RESET;
        printf(ANSI_COLOR_CYAN "=== Caixa de dialogo ============================================================================================\n|                                                                                                               |\n|                                                                                                               |\n|                                                                                                               |\n=================================================================================================================" ANSI_COLOR_RESET);

        coordxy(3, 4);
        SlowText(Texto4);
        coordxy(2, 6);
        SlowText(Texto5);
        coordxy(0, 9);
        printf(ANSI_COLOR_CYAN "===============\n|             |\n|             |\n|             |\n|             |\n===============" ANSI_COLOR_RESET);
        coordxy(4, 10);
        printf(ANSI_COLOR_DARK_CYAN "N (norte)");
        coordxy(4, 11);
        printf("S (sul)");
        coordxy(4, 12);
        printf("L (leste)");
        coordxy(4, 13);
        printf("O (oeste)" ANSI_COLOR_RESET);
        opcao = SetaUpDown(10, 1, 4, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

        switch (opcao)
        {
        case 2:
            system("cls");
            char Texto7[] = ANSI_COLOR_DARK_CYAN "Muito bem, você encontrou o Templo de Hórus, agora você terá que encontrar um modo de subir a montanha.\n\n" ANSI_COLOR_RESET;
            PrintVida(Vidas);

            printf(ANSI_COLOR_CYAN "=== Caixa de dialogo ======================================================================================\n|                                                                                                         |\n|                                                                                                         |\n|                                                                                                         |\n===========================================================================================================" ANSI_COLOR_RESET);
            coordxy(2, 5);
            Pause(SlowText(Texto7));
            Fase2Cenario2(Vidas, o);
        default:
            system("cls");
            char Texto6[] = ANSI_COLOR_DARK_CYAN "Bom, parece que você não tem o necessário para derrotar Seth, mas não se preocupe, você terá um segunda chance." ANSI_COLOR_RESET;
            PrintVida(Vidas);

            printf(ANSI_COLOR_CYAN "=== Caixa de dialogo ==============================================================================================\n|                                                                                                                 |\n|                                                                                                                 |\n|                                                                                                                 |\n===================================================================================================================" ANSI_COLOR_RESET);
            coordxy(2, 5);
            Pause(SlowText(Texto6));
            Anubis(FaseAtual, Vidas, o);
        }
    default:
        system("cls");
        char Texto6[] = ANSI_COLOR_DARK_CYAN "Bom, parece que você não tem o necessário para derrotar Seth, mas não se preocupe, você terá um segunda chance." ANSI_COLOR_RESET;
        PrintVida(Vidas);

        printf(ANSI_COLOR_CYAN "=== Caixa de dialogo ==============================================================================================\n|                                                                                                                 |\n|                                                                                                                 |\n|                                                                                                                 |\n===================================================================================================================" ANSI_COLOR_RESET);
        coordxy(2, 5);
        Pause(SlowText(Texto6));
        Anubis(FaseAtual, Vidas, o);
    }
}
