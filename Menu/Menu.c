#include "Includes.h"

void Menu(int MusicOn)
{
    char Password[20];
    int opcao = 0, Vidas = 1, o = MusicOn, i = 0;

    if (o == 0)
        PlaySound(TEXT("null.wav"), NULL, SND_ASYNC);
    else
        PlaySound(TEXT("menu.wav"), NULL, SND_ASYNC|SND_LOOP);

    system("cls");

    Archeology();
    coordxy(58, 20);
    printf(ANSI_COLOR_CYAN "=========================================");
    for (i = 0; i < 13; i++){
        coordxy(58, 21 + i);
        printf("|                                       |");
    }
    coordxy(58, 24);
    printf("|=======================================|");
    coordxy(58, 34);
    printf("=========================================" ANSI_COLOR_RESET);
    coordxy(70, 22);
    printf(ANSI_COLOR_DARK_CYAN "\"Menu de opções\"");
    coordxy(70, 26);
    printf("Novo Jogo");
    coordxy(70, 27);
    printf("Menu de Desenvolvedor");
    coordxy(70, 28);
    printf("GitHub");
    coordxy(70, 29);
    printf("Opções");
    coordxy(70, 30);
    printf(ANSI_COLOR_DARK_RED "Sair");
    coordxy(60, 32);
    printf(ANSI_COLOR_RED "Por Favor, deixe o jogo em tela cheia" ANSI_COLOR_RESET);
    opcao = SetaUpDown(26, 67, 6, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

    switch (opcao)
    {
    case 1:
        system("cls");
        Player(Vidas, o);
    case 2:
        system("cls");
        coordxy(45, 9);
        printf(ANSI_COLOR_CYAN "=========================================================================");
        for (i = 0; i < 6; i++){
            coordxy(45, 10+i);
            printf("|                                                                       |");
        }
        coordxy(45, 16);
        printf("=========================================================================" ANSI_COLOR_RESET);
        coordxy(47, 11);
        printf(ANSI_COLOR_CYAN "Para ter acesso ao menu do desenvolvedor, por favor digite sua senha:");
        coordxy(70, 13);
        printf(ANSI_COLOR_DARK_CYAN "______________________");
        coordxy(70, 13);
        gets(Password);
        if (strcasecmp (Password, "1234")== 0)
        {
            for (i = 0; i < 5; i++){
                coordxy(45, 15+i);
                printf(ANSI_COLOR_CYAN "|                                                                       |");
            }
            coordxy(45, 20);
            printf("=========================================================================" ANSI_COLOR_RESET);
            coordxy(47, 16);
            printf(ANSI_COLOR_CYAN "Verificando...");
            Sleep(1000);
            coordxy(47, 18);
            printf("Você será direcionado para o menu do desenvolvedor, por favor aguarde." ANSI_COLOR_RESET);
            Sleep(2000);
            system("cls");
            MenuDeDesenvolvedor(Vidas, o);
        }
        else
        {
            for (i = 0; i < 5; i++){
                coordxy(45, 15+i);
                printf(ANSI_COLOR_CYAN "|                                                                       |");
            }
            coordxy(45, 20);
            printf("=========================================================================" ANSI_COLOR_RESET);
            coordxy(47, 16);
            printf(ANSI_COLOR_CYAN "Verificando...");
            Sleep(1000);
            coordxy(47, 18);
            Pause(ANSI_COLOR_RED "Senha incorreta." ANSI_COLOR_RESET);
            system("cls");
            Menu(o);
        }
    case 3:
        system("cls");
        coordxy(48, 18);
        printf(ANSI_COLOR_CYAN "==============================================================");
        for (i = 0; i < 3; i++){
            coordxy(48, 19+i);
            printf("|                                                            |");
        }
        coordxy(48, 22);
        printf("==============================================================" ANSI_COLOR_RESET);
        coordxy(50, 20);
        printf(ANSI_COLOR_DARK_CYAN "Você está sendo direcionado ao nosso projeto no GitHub..." ANSI_COLOR_RESET);
        Sleep(2000);
        system("start https://github.com/Gaspor/Archeology");
        Menu(o);
    case 4:
        Audio(o);

    case 5:
        Quit();

    default:
        system("cls");
        coordxy(58, 18);
        printf(ANSI_COLOR_CYAN "=== Mensagem do sistema ============================");
        for (i = 0; i < 3; i++){
            coordxy(58, 19+i);
            printf("|                                                  |");
        }
        coordxy(58, 22);
        printf("====================================================" ANSI_COLOR_RESET);
        coordxy(60, 20);
        Pause(ANSI_COLOR_RED "Essa opção não existe, por favor tente uma nova." ANSI_COLOR_RESET);
        Menu(o);
    }
}

void Audio(int MusicOn)// Controle de audio
{
    int o = MusicOn, opcao = 0;
    system("cls");
    coordxy(70, 18);
    printf(ANSI_COLOR_CYAN "=== Som ===");
    coordxy(70, 19);
    printf("|         |");
    coordxy(70, 20);
    printf("|   \e[0;36mOff\e[1;36m   |");
    coordxy(70, 21);
    printf("|   \e[0;36mOn\e[1;36m    |");
    coordxy(70, 22);
    printf("===========" ANSI_COLOR_RESET);
    opcao = SetaUpDown(20, 71, 2, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

    switch (opcao)
    {
    case 1:
        system("cls");
        coordxy(65, 18);
        printf(ANSI_COLOR_CYAN "=== Mensagem do sitema ========");
        coordxy(65, 19);
        printf("|                             |");
        coordxy(65, 20);
        printf("|                             |");
        coordxy(65, 21);
        printf("|                             |");
        coordxy(65, 22);
        printf("===============================");
        coordxy(67, 20);
        Pause("Som retirado com sucesso..." ANSI_COLOR_RESET);
        o--;
        Menu(o);

    case 2:
        system("cls");
        coordxy(65, 18);
        printf(ANSI_COLOR_CYAN "=== Mensagem do sitema ========");
        coordxy(65, 19);
        printf("|                             |");
        coordxy(65, 20);
        printf("|                             |");
        coordxy(65, 21);
        printf("|                             |");
        coordxy(65, 22);
        printf("===============================");
        coordxy(67, 20);
        Pause("Som colocado com sucesso..." ANSI_COLOR_RESET);
        o = 1;
        Menu(o);
    }
}

void Quit()
{
    system("cls");
    coordxy(65, 18);
    printf(ANSI_COLOR_CYAN "=== Mensagem do sitema ========");
    coordxy(65, 19);
    printf("|                             |");
    coordxy(65, 20);
    printf("|                             |");
    coordxy(65, 21);
    printf("|                             |");
    coordxy(65, 22);
    printf("===============================");
    coordxy(70, 20);
    printf(ANSI_COLOR_RED "\aSaindo..." ANSI_COLOR_RESET);
    Sleep(800);
    system("cls");
    exit(0);
}
