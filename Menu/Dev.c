#include "Includes.h"

void MenuDeDesenvolvedor(int Vida, int MusicOn)
{
    int Vidas = Vida, o = MusicOn, opcao = 0;
    system("cls");
    printf("O que voc� deseja?\n\n      Ir para o Menu de escolha de Fase\n\n      Mudar a quantidade de vida do Player\n\n      Voltar ao Menu Inicial");
    opcao = SetaUpDown(2, 3, 3, 2, "->", "  ");

    switch (opcao)
    {
    case 1:
        system("cls");
        printf("Espere 1 segundo, voc� ser� direcionado ao menu de Escolha de Fase");
        Sleep(1000);
        SelectFase(Vidas, o);
    case 2:
        system("cls");
        printf("Vida atual: %d\n\n Digite o novo valor da vida do Player: ", Vidas);
        fflush(stdin);
        scanf("%d", &Vidas);
        if (Vidas >= 1000){
            Pause("N�mero de vidas excede o limite, o sistema te deixar� com o total de vidas m�ximas permitidas que � 999.");
            Vidas = 999;
            MenuDeDesenvolvedor(Vidas, o);
        }
        if (Vidas < 1000){
            Sleep(1000);
            Pause("Vida mudada com sucesso!");
            MenuDeDesenvolvedor(Vidas, o);
        }
    case 3:
        system("cls");
        printf("Voc� ser� direcionado ao menu inicial com a quantidade de vida padr�o em 1 segundo");
        Sleep(1000);
        Menu(o);
    default:
        Pause("Op��o inv�lida");
        MenuDeDesenvolvedor(Vidas, o);
    }
}


void SelectFase(int Vida, int MusicOn)    // Fun��o para desenvolvedores para selecionar Fase //
{
    int Vidas = Vida, o = MusicOn, opcao = 0;
    system("cls");
    printf("     \"Menu de Fases\"\n\n      Ir para a Fase 1\n      Ir para a Fase 2\n      Ir para a Fase 3\n      Ir para o Boss Esfinge\n      Ir para a Fase 1 (Segundo Cen�rio)\n      Ir para a Fase 2 (Segundo Cen�rio)\n      Ir para a Fase 3 (Segundo Cen�rio)\n      Ir para o Boss   (Segundo Cen�rio)\n\n      Voltar ao Menu principal\n      Voltar ao Menu de desenvolvedor");
    opcao = SetaUpDown(2, 3, 11, 1, "->", "  ");

    switch (opcao)
    {
    case 1:
        system("cls");
        printf("   Voc� escolheu ir para a Fase 1.\n");
        Sleep(1000);
        printf("   Iniciando a Fase 1...\n");
        Sleep(1500);
        system("cls");
        Fase1(Vidas, o);
    case 2:
        system("cls");
        printf("   Voc� escolheu ir para a Fase 2.\n");
        Sleep(1000);
        printf("   Iniciando a Fase 2...\n");
        Sleep(1500);
        system("cls");
        //PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
        Fase2(Vidas, o);
    case 3:
        system("cls");
        printf("   Voc� escolheu ir para a Fase 3.\n");
        Sleep(1000);
        printf("   Iniciando a Fase 3...\n");
        Sleep(1500);
        system("cls");
        //PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
        Fase3(Vidas, o);
    case 4:
        system("cls");
        printf("   Voc� escolheu ir para a Fase do Boss.\n");
        Sleep(1000);
        printf("   Iniciando o Boss...\n");
        Sleep(1500);
        system("cls");
        BossEsfinge(Vidas, o);
    case 5:
        system("cls");
        printf("   Voc� escolheu ir para a Fase 1 do Segundo cen�rio.\n");
        Sleep(1000);
        printf("   Iniciando a Fase 1 (Segundo cen�rio)...\n");
        Sleep(1500);
        system("cls");
        //PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
        Fase1Cenario2(Vidas, o);
    case 6:
        system("cls");
        printf("   Voc� escolheu ir para a Fase 2 do Segundo cen�rio.\n");
        Sleep(1000);
        printf("   Iniciando a Fase 2 (Segundo cen�rio)...\n");
        Sleep(1500);
        system("cls");
        //PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
        Fase2Cenario2(Vidas, o);
    case 7:
        system("cls");
        printf("   Voc� escolheu ir para a Fase 3 do Segundo cen�rio.\n");
        Sleep(1000);
        printf("   Iniciando a Fase 3 (Segundo cen�rio)...\n");
        Sleep(1500);
        system("cls");
        Fase3Cenario2(Vidas, o);
    case 8:
        system("cls");
        printf("   Voc� escolheu ir para a Fase do Boss do Segundo cen�rio.\n");
        Sleep(1000);
        printf("   Iniciando a Fase Boss Seth...\n");
        Sleep(1500);
        system("cls");
        BossSeth(Vidas, o);
    case 10:
        Menu(o);
    case 11:
        MenuDeDesenvolvedor(Vidas, o);
    default:
        Pause("  Op��o inv�lida, tente outra");
        SelectFase(Vidas, o);
    }
}
