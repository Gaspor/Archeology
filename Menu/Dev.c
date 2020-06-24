#include "Includes.h"

void MenuDeDesenvolvedor(int Vida, int MusicOn)
{
    int Vidas = Vida, o = MusicOn, opcao = 0, i = 0;
    system("cls");
    coordxy(60, 15);
    printf(ANSI_COLOR_CYAN "===========================================");
    for (i = 0; i < 11; i++)
    {
        coordxy(60, 16 + i);
        printf("|                                         |");
    }
    coordxy(60, 19);
    printf("|=========================================|");
    coordxy(60, 27);
    printf("===========================================" ANSI_COLOR_RESET);
    coordxy(71, 17);
    printf(ANSI_COLOR_DARK_CYAN "Menu de desenvolvedor");
    coordxy(65, 21);
    printf("Ir para o Menu de escolha de Fase");
    coordxy(65, 23);
    printf("Mudar a quantidade de vida do Player");
    coordxy(65, 25);
    printf(ANSI_COLOR_DARK_RED "Voltar ao Menu Inicial" ANSI_COLOR_RESET);
    opcao = SetaUpDown(21, 62, 3, 2, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

    switch (opcao)
    {
    case 1:
        SelectFase(Vidas, o);
    case 2:
        system("cls");
        PrintVida(Vidas);
        coordxy(50, 13);
        printf("==================================================================");
        coordxy(50, 14);
        printf("|                                                                |");
        coordxy(50, 15);
        printf("|                                                                |");
        coordxy(50, 16);
        printf("|                                                                |");
        coordxy(50, 17);
        printf("==================================================================");
        coordxy(52, 15);
        printf("Digite o novo valor da vida do Player: ", Vidas);
        fflush(stdin);
        scanf("%d", &Vidas);
        if (Vidas >= 1000)
        {
            coordxy(50, 17);
            Pause("Número de vidas excede o limite, o sistema te deixará com o total de vidas máximas permitidas que é 999.");
            Vidas = 999;
            MenuDeDesenvolvedor(Vidas, o);
        }
        if (Vidas < 1000)
        {
            Sleep(1000);
            coordxy(50, 17);
            Pause("Vida mudada com sucesso!");
            MenuDeDesenvolvedor(Vidas, o);
        }
    case 3:
        Menu(o);
    default:
        system("cls");
        coordxy(58, 22);
        printf("====================================================" ANSI_COLOR_RESET);
        coordxy(60, 20);
        Pause("Opção inválida");
        MenuDeDesenvolvedor(Vidas, o);
    }
}


void SelectFase(int Vida, int MusicOn)    // Função para desenvolvedores para selecionar Fase //
{
    int Vidas = Vida, o = MusicOn, opcao = 0, i = 0;
    system("cls");
    coordxy(60, 12);
    printf(ANSI_COLOR_CYAN "===========================================");
    for (i = 0; i < 17; i++)
    {
        coordxy(60, 13 + i);
        printf("|                                         |");
    }
    coordxy(60, 16);
    printf("|=========================================|");
    coordxy(60, 30);
    printf("===========================================" ANSI_COLOR_RESET);
    coordxy(73, 14);
    printf(ANSI_COLOR_DARK_CYAN "\"Menu de Fases\"");
    coordxy(65, 18);
    printf("Ir para a Fase 1");
    coordxy(65, 19);
    printf("Ir para a Fase 2");
    coordxy(65, 20);
    printf("Ir para a Fase 3");
    coordxy(65, 21);
    printf("Ir para o Boss Esfinge");
    coordxy(65, 22);
    printf("Ir para a Fase 1 (Segundo Cenário)");
    coordxy(65, 23);
    printf("Ir para a Fase 2 (Segundo Cenário)");
    coordxy(65, 24);
    printf("Ir para a Fase 3 (Segundo Cenário)");
    coordxy(65, 25);
    printf("Ir para o Boss   (Segundo Cenário)");

    coordxy(65, 27);
    printf(ANSI_COLOR_DARK_RED "Voltar ao Menu principal");
    coordxy(65, 28);
    printf("Voltar ao Menu de desenvolvedor" ANSI_COLOR_RESET);
    opcao = SetaUpDown(18, 62, 11, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

    switch (opcao)
    {
    case 1:
        system("cls");
        coordxy(60, 16);
        printf(ANSI_COLOR_CYAN "=== Mensagem do sistema ===================");
        for (i = 0; i < 5; i++)
        {
            coordxy(60, 17 + i);
            printf("|                                         |");
        }
        coordxy(60, 22);
        printf("===========================================");
        coordxy(62, 18);
        printf("Você escolheu ir para a Fase 1.");
        Sleep(1000);
        coordxy(62, 20);
        printf("Iniciando a Fase 1..." ANSI_COLOR_RESET);
        Sleep(1500);
        system("cls");
        Fase1(Vidas, o);
    case 2:
        system("cls");
        coordxy(60, 16);
        printf(ANSI_COLOR_CYAN "=== Mensagem do sistema ===================");
        for (i = 0; i < 5; i++)
        {
            coordxy(60, 17 + i);
            printf("|                                         |");
        }
        coordxy(60, 22);
        printf("===========================================");
        coordxy(62, 18);
        printf("Você escolheu ir para a Fase 2.");
        Sleep(1000);
        coordxy(62, 20);
        printf("Iniciando a Fase 2..." ANSI_COLOR_RESET);
        Sleep(1500);
        system("cls");
        //PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
        Fase2(Vidas, o);
    case 3:
        system("cls");
        coordxy(60, 16);
        printf(ANSI_COLOR_CYAN "=== Mensagem do sistema ===================");
        for (i = 0; i < 5; i++)
        {
            coordxy(60, 17 + i);
            printf("|                                         |");
        }
        coordxy(60, 22);
        printf("===========================================");
        coordxy(62, 18);
        printf("Você escolheu ir para a Fase 3.");
        Sleep(1000);
        coordxy(62, 20);
        printf("Iniciando a Fase 3..." ANSI_COLOR_RESET);
        Sleep(1500);
        system("cls");
        //PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
        Fase3(Vidas, o);
    case 4:
        system("cls");
        coordxy(60, 16);
        printf(ANSI_COLOR_CYAN "=== Mensagem do sistema ===================");
        for (i = 0; i < 5; i++)
        {
            coordxy(60, 17 + i);
            printf("|                                         |");
        }
        coordxy(60, 22);
        printf("===========================================");
        coordxy(62, 18);
        printf("Você escolheu ir para a Fase do Boss.");
        Sleep(1000);
        coordxy(62, 20);
        printf("Iniciando o Boss..." ANSI_COLOR_RESET);
        Sleep(1500);
        system("cls");
        BossEsfinge(Vidas, o);
    case 5:
        system("cls");
        coordxy(55, 16);
        printf(ANSI_COLOR_CYAN "=== Mensagem do sistema ======================================");
        for (i = 0; i < 5; i++)
        {
            coordxy(55, 17 + i);
            printf("|                                                            |");
        }
        coordxy(55, 22);
        printf("==============================================================");
        coordxy(57, 18);
        printf("Você escolheu ir para a Fase 1 do Segundo cenário.");
        Sleep(1000);
        coordxy(57, 20);
        printf("Iniciando a Fase 1 (Segundo cenário)..." ANSI_COLOR_RESET);
        Sleep(1500);
        system("cls");
        //PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
        Fase1Cenario2(Vidas, o);
    case 6:
        system("cls");
        coordxy(55, 16);
        printf(ANSI_COLOR_CYAN "=== Mensagem do sistema ======================================");
        for (i = 0; i < 5; i++)
        {
            coordxy(55, 17 + i);
            printf("|                                                            |");
        }
        coordxy(55, 22);
        printf("==============================================================");
        coordxy(57, 18);
        printf("Você escolheu ir para a Fase 2 do Segundo cenário.");
        Sleep(1000);
        coordxy(57, 20);
        printf("Iniciando a Fase 2 (Segundo cenário)..." ANSI_COLOR_RESET);
        Sleep(1500);
        system("cls");
        //PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
        Fase2Cenario2(Vidas, o);
    case 7:
        system("cls");
        coordxy(55, 16);
        printf(ANSI_COLOR_CYAN "=== Mensagem do sistema ======================================");
        for (i = 0; i < 5; i++)
        {
            coordxy(55, 17 + i);
            printf("|                                                            |");
        }
        coordxy(55, 22);
        printf("==============================================================");
        coordxy(57, 18);
        printf("Você escolheu ir para a Fase 3 do Segundo cenário.");
        Sleep(1000);
        coordxy(57, 20);
        printf("Iniciando a Fase 3 (Segundo cenário)..." ANSI_COLOR_RESET);
        Sleep(1500);
        system("cls");
        Fase3Cenario2(Vidas, o);
    case 8:
        system("cls");
        coordxy(55, 16);
        printf(ANSI_COLOR_CYAN "=== Mensagem do sistema ======================================");
        for (i = 0; i < 5; i++)
        {
            coordxy(55, 17 + i);
            printf("|                                                            |");
        }
        coordxy(55, 22);
        printf("==============================================================");
        coordxy(57, 18);
        printf("Você escolheu ir para a Fase do Boss do Segundo cenário.");
        Sleep(1000);
        coordxy(57, 20);
        printf("Iniciando a Fase Boss Seth..." ANSI_COLOR_RESET);
        Sleep(1500);
        system("cls");
        BossSeth(Vidas, o);
    case 10:
        Menu(o);
    case 11:
        MenuDeDesenvolvedor(Vidas, o);
    default:
        system("cls");
        coordxy(58, 18);
        printf(ANSI_COLOR_CYAN "=== Mensagem do sistema ======================");
        for (i = 0; i < 3; i++)
        {
            coordxy(58, 19 + i);
            printf("|                                            |");
        }
        coordxy(58, 22);
        printf("==============================================" ANSI_COLOR_RESET);
        coordxy(60, 20);
        Pause(ANSI_COLOR_RED "Opção inválida, tente outra!" ANSI_COLOR_RESET);
        SelectFase(Vidas, o);
    }
}
