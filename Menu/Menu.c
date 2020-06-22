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
    opcao = SetaUpDown(26, 67, 5, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

    switch (opcao)
    {
    case 1:
        system("cls");
        Player(Vidas, o);
    case 2:
        system("cls");
        printf("  Para ter acesso ao menu do desenvolvedor, por favor digite sua senha: ");
        gets(Password);
        if (strcasecmp (Password, "1234")== 0)
        {
            printf("  Verificando...\n");
            Sleep(1000);
            printf("  Você será direcionado para o menu de escolha de fase, por favor aguarde.");
            Sleep(2000);
            system("cls");
            MenuDeDesenvolvedor(Vidas);
        }
        else
        {
            printf("  Verificando...\n");
            Sleep(1000);
            Pause("  Senha incorreta.");
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
        Sleep(2000);
        Menu(o);
    case 4:
        Audio(o);

    case 5:
        Quit();

    default:
        printf("  Essa opção não existe, por favor tente uma nova.\n");
        Sleep(1500);
    }
}

void Audio(int MusicOn)// Controle de audio
{
    int o = MusicOn, opcao = 0;
    system("cls");
    printf(" == Som == \n\n    Off \n    On");
    opcao = SetaUpDown(2, 1, 2, 1, "->", "  ");

    switch (opcao)
    {
    case 1:
        system("cls");
        Pause("Som retirado com sucesso...");
        o--;
        Menu(o);

    case 2:
        system("cls");
        Pause("Pressione qualquer tecla para retornar ao menu...");
        o = 1;
        Menu(o);
    }
}

void Quit()
{
    system("cls");
    printf("\aSaindo...\n");
    Sleep(800);
    exit(0);
}
