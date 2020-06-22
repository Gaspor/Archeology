#include "Includes.h"

// Globais //

void Menu(int MusicOn)
{
    char Password[20];
    int opcao = 0, Vidas = 1, o = MusicOn;

    if (o == 0)
        PlaySound(TEXT("null.wav"), NULL, SND_ASYNC);
    else
        PlaySound(TEXT("menu.wav"), NULL, SND_ASYNC|SND_LOOP);

    system("cls");
    printf("     \"Menu de opções\"\n\n      Novo Jogo \n      Menu de Desenvolvedor\n      GitHub\n      Opções\n      Sair \n");
    printf("\nPor Favor, deixe o jogo em tela cheia");
    opcao = SetaUpDown(2, 3, 5, 1, "->", "  ");

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
        printf("  Você está sendo direcionado ao nosso projeto no GitHub...");
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

void Audio(int MusicOn)              // controle de audio
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
