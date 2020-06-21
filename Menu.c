#include "Includes.h"

// Globais //
char Password[20];
int KeyPress,b,L,opcao;

// Setas //
void coordxy(int x,int y)
{
    COORD Mouse;
    Mouse.X = x;
    Mouse.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Mouse);
}

void SetaUpDown (int La,int coordx,int BLimite,int LOper,char *SetaModel,char *SetaModelSpace)     // Seta pra cima e pra baixo //
{
    opcao = 0;
    L=La, b=1;
    do
    {
        coordxy(coordx, L);
        printf(SetaModel);
        coordxy(0,20);
        if(kbhit)
        {
            KeyPress=getch();
        }
        if(KeyPress == 80 && b < BLimite)
        {
            coordxy(coordx, L);
            printf(SetaModelSpace);
            L+=LOper;
            b++;
        }
        if(KeyPress == 72 && b > 1)
        {
            coordxy(coordx, L);
            printf(SetaModelSpace);
            L-=LOper;
            b--;
        }
        if (KeyPress == 27)
        {
            Quit();
        }
        if(KeyPress == 13)
        {
            opcao=b;
        }
    }
    while(opcao == 0);
}

void SetaLeftRight (int La,int coordy,int BLimite,int LOper,char *SetaModel,char *SetaModelSpace)     // Seta pra direita e pra esquerda //
{
    opcao = 0;
    L=La, b=1;
    do
    {
        coordxy(L, coordy);
        printf(SetaModel);
        coordxy(0,20);
        if(kbhit)
        {
            KeyPress=getch();
        }
        if (KeyPress == 77 && b < BLimite)
        {
            coordxy(L, coordy);
            printf(SetaModelSpace);
            L+=LOper;
            b++;
        }
        if (KeyPress == 75 && b > 1)
        {
            coordxy(L, coordy);
            printf(SetaModelSpace);
            L-=LOper;
            b--;
        }
        if (KeyPress == 27)
        {
            Quit();
        }
        if(KeyPress == 13)
        {
            opcao=b;
        }
    }
    while(opcao == 0);
}

// Efeito Texto em Slow //
char SlowText(char *Text)
{
    int i, TimeText = 1;
    for (i = 0; Text[i] != '\0'; i++)
    {
        printf("%c",Text[i]);
        Sleep(TimeText);
    }
}

void Menu(int MusicOn)
{
    int Vidas = 100, o = MusicOn;

    if (o == 0)
        PlaySound(TEXT("null.wav"), NULL, SND_ASYNC);
    else
        PlaySound(TEXT("menu.wav"), NULL, SND_ASYNC|SND_LOOP);

    system("cls");
    printf("     \"Menu de op��es\"\n\n      Novo Jogo \n      Menu de Desenvolvedor\n      GitHub\n      Op��es\n      Sair \n");
    printf("\nPor Favor, deixe o jogo em tela cheia");
    SetaUpDown(2, 3, 5, 1, "->", "  ");

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
            printf("  Voc� ser� direcionado para o menu de escolha de fase, por favor aguarde.");
            Sleep(2000);
            system("cls");
            MenuDeDesenvolvedor(Vidas);
        }
        else
        {
            printf("  Verificando...\n");
            Sleep(1000);
            printf("  Senha incorreta.");
            Sleep(700);
            system("cls");
            Menu(o);
        }
    case 3:
        system("cls");
        printf("  Voc� est� sendo direcionado ao nosso projeto no GitHub...");
        Sleep(2000);
        system("start https://github.com/Gaspor/Archeology");
        Sleep(2000);
        Menu(o);
    case 4:
        Audio(o);

    case 5:
        Quit();

    default:
        printf("  Essa op��o n�o existe, por favor tente uma nova.\n");
        Sleep(1500);
    }
}

void Audio(int MusicOn)              // controle de audio
{
    int o = MusicOn;
    system("cls");
    printf(" == Som == \n\n    Off \n    On");
    SetaUpDown(2, 1, 2, 1, "->", "  ");

    switch (opcao)
    {
    case 1:
        system("cls");
        printf("Som retirado com sucesso...");
        Sleep(3000);
        o--;
        Menu(o);

    case 2:
        system("cls");
        printf("Retornando ao menu...");
        Sleep(3000);
        o = 1;
        Menu(o);
    }
}

void MenuDeDesenvolvedor(int Vida, int MusicOn)
{
    int Vidas = Vida, o = MusicOn;
    system("cls");
    printf("O que voc� deseja?\n\n      Ir para o Menu de escolha de Fase\n\n      Mudar a quantidade de vida do Player\n\n      Voltar ao Menu Inicial");
    SetaUpDown(2, 3, 3, 2, "->", "  ");

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
            printf("N�mero de vidas excede o limite, o sistema te deixar� com o total de vidas m�ximas permitidas que � 999.");
            Vidas = 999;
            MenuDeDesenvolvedor(Vidas, o);
        }
        if (Vidas < 1000){
            Sleep(1000);
            printf("Vida mudada com sucesso!");
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
    int Vidas = Vida, o = MusicOn;
    system("cls");
    printf("     \"Menu de Fases\"\n\n      Ir para a Fase 1\n      Ir para a Fase 2\n      Ir para a Fase 3\n      Ir para o Boss Esfinge\n      Ir para a Fase 1 (Segundo Cen�rio)\n      Ir para a Fase 2 (Segundo Cen�rio)\n      Ir para a Fase 3 (Segundo Cen�rio)\n      Ir para o Boss   (Segundo Cen�rio)\n\n      Voltar ao Menu principal\n");
    SetaUpDown(2, 3, 10, 1, "->", "  ");

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
        system("pause");
        system("cls");
        Fase3Cenario2(Vidas, o);
    case 8:
        system("cls");
        printf("   Voc� escolheu ir para a Fase do Boss do Segundo cen�rio.\n");
        Sleep(1000);
        printf("   Iniciando a Fase Boss Seth...\n");
        system("pause");
        system("cls");
        BossSeth(Vidas, o);
    case 10:
        Menu(o);
    default:
        printf("  Op��o inv�lida, tente outra");
        Sleep(1000);
        SelectFase(Vidas, o);
    }
}

void Fase2(int Vida, int MusicOn)
{
    system("cls");
    int FaseAtual = 2, Acertos = 0, Vidas = Vida, o = MusicOn;
    coordxy(0, 0);
    PrintVida(Vidas);
    char Text1[] = ANSI_COLOR_DARK_CYAN " Voc� se depara com uma entrada, anda at� ela e quando est� chegando, o ch�o come�a a tremer. De repente\n";
    char TextComp[] = "voc� percebe que alguns pisos n�o tremem e eles ser�o o seu caminho at� a entrada.\n\n" ANSI_COLOR_RESET;
    printf(ANSI_COLOR_CYAN "  =========== Caixa de Di�logo ===============================================================================\n  |                                                                                                          |\n  |                                                                                                          |\n  |                                                                                                          |\n  |                                                                                                          |\n  |                                                                                                          |\n  ============================================================================================================\n\n" ANSI_COLOR_RESET);
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
        printf(ANSI_COLOR_DARK_CYAN " V� ao max�mo para esquerda." ANSI_COLOR_RESET);
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
    printf(ANSI_COLOR_CYAN "\n\t\t\t\t\t====================================\n\t\t\t\t\t|  \e[0;36m1         2         3         4\e[1;36m |\n\t\t\t\t\t|        Posi��o do jogador        |\n\t\t\t\t\t====================================\n" ANSI_COLOR_RESET);
    SetaLeftRight(41, 16, 4, 10, ANSI_COLOR_DARK_RED ">" ANSI_COLOR_RESET, " ");

    switch (opcao)
    {
    case 1:
        if (Acertos == 0)
        {
            char Acerto1[] = ANSI_COLOR_DARK_CYAN "\n\n   Voc� acertou e passou para o pr�ximo piso           \n" ANSI_COLOR_RESET;
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
            char Acerto3[] = ANSI_COLOR_DARK_CYAN "\n\n   Voc� acertou, por pouco!                            \n" ANSI_COLOR_RESET;
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
            char Acerto4[] = ANSI_COLOR_DARK_CYAN "\n\n   Voc� finalmente passou sem cair em nenhuma armadilha\n" ANSI_COLOR_RESET;
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
            char Acerto2[] = ANSI_COLOR_DARK_CYAN "\n\n   Voc� acertou, tome cuidado com os pisos falsos      \n" ANSI_COLOR_RESET;
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

void ErrorFase2(int Vida, int MusicOn)     // Fun��o que � chamada quando o usu�rio erra o piso da Fase 2  //
{
    int FaseAtual = 2, Vidas = Vida, o = MusicOn;
    char ErroPiso[] = ANSI_COLOR_DARK_CYAN "   Voc� pisou em um lugar que n�o era seguro, o ch�o desmoronou, e voc� morreu com a queda.\n" ANSI_COLOR_RESET;
    Pause(SlowText(ErroPiso));
    Anubis(FaseAtual, Vidas, o);
}

// Comandos da Esfinge //
void EsfingeImage()      // Aparecer a Imagem da Esfinge
{
    printf("\n\t\t......................................................................");
    printf("\n\t\t............................\'\',;;::::;,\'..............................");
    printf("\n\t\t..................'',;::cllooooddodxxxdolllcc::;,''...................");
    printf("\n\t\t...............,coodxxxddxxddddxddxkkxxxxxxxxxxxxdlc:,'...............");
    printf("\n\t\t..........'',,:xOkddxxxxkkxxxxxxodkkkkxkkkOOkkxxxdllol:;,,'''.........");
    printf("\n\t\t.....'',,;;,;cxOkkkxdddxkkOOkkOkddxxkkOO00000Oxddoododdc;;;;;;,''.....");
    printf("\n\t\t..',,;;;;;;;lkOOkkkkxdddxO000OOOxolldkO0KKKK0kxdodddodddl::::;;::;,'..");
    printf("\n\t\t,;;;;;;;;;;lO0OOkkkkxddookOOOkkkkkOOOO000000kxdddxxdddddxl:::::::::::;");
    printf("\n\t\t::;;;;;;;:lk0OOOkOOOkxolldxkxdoodkOOkkxxkOOOkdddxkkxdoodxxoccccccccccc");
    printf("\n\t\t::;;;;:::lkOOOkkOOOOOkdocclol::;;okOko:;:ldxdxxxOkkkkxddxxxocllllccccc");
    printf("\n\t\t:;;;::::lxOOOkkkkkkddxdolcllllccclkOkxdlcloddxkkdodxxxxdxkOxolllllllll");
    printf("\n\t\t:;;:::clx00OkkkkkkdldxdodxxkkOOxlldxkO00Ok0000OxdlodxxddxxkOkoloooooll");
    printf("\n\t\t::::cccdO00Okkkxxxdx0OoclxkOOOOxlcccldk000KK0OkkOkooxxddxkkOOkoloooooo");
    printf("\n\t\t:::cccok00OOxxkxxxocoxo::coxxkkoloxxdodO000OOkxxl:coddxxkkOOOOxooooooo");
    printf("\n\t\t::ccclxOOOOkkxxxxxxdolc:;;cloddlloooddxkOkkkxxdoldxxdxxkkkOOOOkdlooooo");
    printf("\n\t\t:ccllokOOOOOkxxxxkkxkko:;;:coo:,,;;::cloxkxxddxxkxxxxxkkkkOOOOOxoooooo");
    printf("\n\t\tcccllok0000Okkkkkkkkkkxc;,,;cooccclooddkkxdoookOkkkkkkOOOOOOOOOxoloooo");
    printf("\n\t\tcccllldO00000OOkkkkkkkkd;,'';:ldxkOO00OOkoc:cdOOOOOOOO00000000kdlloooo");
    printf("\n\t\tccllooloxO000OOkkkkkkkkxl'...:odkkO00000x;.'ck0OOO0OO0000000Odlllloooo");
    printf("\n\t\tcllooodolox0OOOkkxkxxxxxdc,..:ddkO000K00d,;lxOOOOOOOO00O00Oocccllllooo");
    printf("\n\t\tlllooddddlldkOkkkxxxxxxxxo:;,cdxkO00KK00kodxOOOOOOO00OO00Odlcccclllllo");
    printf("\n\t\tlllooddddxxddkOkkxdddddddl:;;lxxkO000K00kdxkOOOOOOOOOO00OOOOdc:cclllll");
    printf("\n\t\tllloooooodkOkdkOOkxddooool:;:oxxkOO00K00OxkOkOOOOOOOOOOOO00Oxc:cccllll");
    printf("\n\t\tcllooooodxO00kxk0OOkxdollll::oddxkkOOOkO0kkkxkOOOOO0OOOO000Okl:::cccll");
    printf("\n\t\tcllooooodkO000kkO00Oxolllcll;''...''',;;lxkxdkOkkOOOOOO0000Okl:::cccll");
    printf("\n\t\tlloooooodkO000OkkO0Oxollc:coc.      ....ckOxxOkkkkOOOOO000OOko::::cccl");
    printf("\n\t\tllooollodkOO000kkOOOxoccc:cll:.       .ckOkdxOkkkkOOOO00OOOkxo::::cccl");
    printf("\n\t\tlllllllodkO0000OkkOOdlccc::lcc;.     .:kOkkdxOkkkOOOkO0OOkkxxdc::::ccc");
    printf("\n\t\tclllllloxkO00000kxkkdlccc::ccc:'.   .;dkOOxoxOkkkkkxxOOOOkxxxdc::::ccc");
    printf("\n\t\tclllllloxO0000000kddolccc:;:cc:,',codkkOOOxoxOkkxddxOOOOkkkkxdl:::cccc");
    printf("\n\t\tclllllloxO00000000Oxoollcc:llllldkOOOOOOO0kdoodddxkO00OOkkkkxdl::ccccc");
    printf("\n\t\tlllllcldkO00000K0000OOOkkkOOkkkkOOOOOOO0000OOOO000OO000Okkkxddl:::cccc");
}

void BossEsfinge(int Vida, int MusicOn)   // Inicio da luta com a Esfinge //
{
    int FaseAtual = 4, Vidas = Vida, VidaEsfinge = 500, o = MusicOn;
    system("cls");
    PrintVida(Vidas);
    coordxy(48, 0);
    printf(ANSI_COLOR_RED "Vida da Esfinge\n\t\t\t\t\t|/////////////////////////| %d " ANSI_COLOR_RESET, VidaEsfinge);
    coordxy(0, 2);
    EsfingeImage();
    coordxy(95, 5);
    printf(ANSI_COLOR_CYAN "=== Caixa de dialogo ===================================");
    coordxy(95, 6);
    printf("|                                                      |");
    coordxy(95, 7);
    printf("|                                                      |");
    coordxy(95, 8);
    printf("|                                                      |");
    coordxy(95, 9);
    printf("|                                                      |");
    coordxy(95, 10);
    printf("|                                                      |");
    coordxy(95, 11);
    printf("========================================================");

    coordxy(99, 7);
    printf("Que animal anda pela manh� sobre quatro patas, a");
    coordxy(103, 9);
    printf("tarde sobre duas e a noite sobre tr�s?\n\n");

    coordxy(95, 13);
    printf( "===================");
    coordxy(95, 14);
    printf("|                 |");
    coordxy(95, 15);
    printf("|                 |");
    coordxy(95, 16);
    printf("|                 |");
    coordxy(95, 17);
    printf("===================" ANSI_COLOR_RESET);

    coordxy(100, 14);
    printf(ANSI_COLOR_DARK_CYAN "O Gato");
    coordxy(100, 15);
    printf("O Chachorro");
    coordxy(100, 16);
    printf("O Homem" ANSI_COLOR_RESET);
    SetaUpDown(14, 97, 3, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

    if (opcao == 3)
    {
        system("cls");
        VidaEsfinge -= 100;
        PrintVida(Vidas);
        coordxy(48, 0);
        printf(ANSI_COLOR_RED "Vida da Esfinge\n\t\t\t\t\t|////////////////////" ANSI_COLOR_DARK_RED "-----" ANSI_COLOR_RED "| %d" ANSI_COLOR_RESET, VidaEsfinge);
        coordxy(0, 2);
        EsfingeImage();
        coordxy(95, 5);
        printf(ANSI_COLOR_CYAN "=== Caixa de dialogo =======");
        coordxy(95, 6);
        printf("|                          |");
        coordxy(95, 7);
        printf("|                          |");
        coordxy(95, 8);
        printf("|                          |");
        coordxy(95, 9);
        printf("============================");
        coordxy(97, 7);
        printf("Por que seria o homem?");

        coordxy(95, 11);
        printf(ANSI_COLOR_CYAN "=====================================================");
        coordxy(95, 12);
        printf("|                                                   |");
        coordxy(95, 13);
        printf("|                                                   |");
        coordxy(95, 14);
        printf("|                                                   |");
        coordxy(95, 15);
        printf("|                                                   |");
        coordxy(95, 16);
        printf("=====================================================" ANSI_COLOR_RESET);

        coordxy(100, 12);
        printf(ANSI_COLOR_DARK_CYAN "Porque o homem � um b�pede");
        coordxy(100, 13);
        printf("Porque o homem n�o quer mais viver uma mentira");
        coordxy(100, 14);
        printf("Porque na inf�ncia o homem engatinha");
        coordxy(100, 15);
        printf("Porque na inf�ncia o homem pensa muito" ANSI_COLOR_RESET);
        SetaUpDown(12, 97, 4, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

        if (opcao == 3)
        {
            system("cls");
            VidaEsfinge -= 100;
            PrintVida(Vidas);
            coordxy(48, 0);
            printf(ANSI_COLOR_RED "Vida da Esfinge\n\t\t\t\t\t|///////////////" ANSI_COLOR_DARK_RED "----------" ANSI_COLOR_RED "| %d" ANSI_COLOR_RESET, VidaEsfinge);
            coordxy(0, 2);
            EsfingeImage();

            coordxy(95, 5);
            printf(ANSI_COLOR_CYAN "=== Caixa de dialogo =======");
            coordxy(95, 6);
            printf("|                          |");
            coordxy(95, 7);
            printf("|                          |");
            coordxy(95, 8);
            printf("|                          |");
            coordxy(95, 9);
            printf("============================");
            coordxy(97, 7);
            printf("E o que mais? \n\n");

            coordxy(95, 11);
            printf(ANSI_COLOR_CYAN "=======================================================================");
            coordxy(95, 12);
            printf("|                                                                     |");
            coordxy(95, 13);
            printf("|                                                                     |");
            coordxy(95, 14);
            printf("|                                                                     |");
            coordxy(95, 15);
            printf("|                                                                     |");
            coordxy(95, 16);
            printf("=======================================================================" ANSI_COLOR_RESET);

            coordxy(100, 12);
            printf(ANSI_COLOR_DARK_CYAN "Na idade adulta ele anda ereto");
            coordxy(100, 13);
            printf("Essa � toda a resposta");
            coordxy(100, 14);
            printf("N�o tenho tempo para essas quest�es filos�ficas, me deixe passar");
            coordxy(100, 15);
            printf("N�o idade adulta ele pensa muito, e pensar nos faz andar" ANSI_COLOR_RESET);
            SetaUpDown(12, 97, 4, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

            if (opcao == 1)
            {
                system("cls");
                VidaEsfinge -= 100;
                PrintVida(Vidas);
                coordxy(48, 0);
                printf(ANSI_COLOR_RED "Vida da Esfinge\n\t\t\t\t\t|//////////" ANSI_COLOR_DARK_RED "---------------" ANSI_COLOR_RED "| %d" ANSI_COLOR_RESET, VidaEsfinge);
                coordxy(0, 2);
                EsfingeImage();

                coordxy(95, 5);
                printf(ANSI_COLOR_CYAN "=== Caixa de dialogo =======");
                coordxy(95, 6);
                printf("|                          |");
                coordxy(95, 7);
                printf("|                          |");
                coordxy(95, 8);
                printf("|                          |");
                coordxy(95, 9);
                printf("============================");
                coordxy(97, 7);
                printf("Mais alguma coisa?");


                coordxy(95, 11);
                printf(ANSI_COLOR_CYAN "=======================================================================");
                coordxy(95, 12);
                printf("|                                                                     |");
                coordxy(95, 13);
                printf("|                                                                     |");
                coordxy(95, 14);
                printf("=======================================================================" ANSI_COLOR_RESET);

                coordxy(100, 12);
                printf(ANSI_COLOR_DARK_CYAN  "Sim, na velhice o homem necessita de uma bengala para andar");
                coordxy(100, 13);
                printf("N�o, � apenas essa a resposta" ANSI_COLOR_RESET);
                SetaUpDown(12, 97, 4, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

                if (opcao == 1)
                {
                    system("cls");
                    VidaEsfinge = 0;
                    PrintVida(Vidas);
                    coordxy(48, 0);
                    printf(ANSI_COLOR_RED "Vida da Esfinge\n\t\t\t\t\t" ANSI_COLOR_DARK_RED "|-------------------------| %d" ANSI_COLOR_DARK_GRAY, VidaEsfinge);
                    coordxy(0, 2);
                    EsfingeImage();
                    coordxy(95, 5);
                    printf(ANSI_COLOR_CYAN "=== Caixa de dialogo ===================================");
                    coordxy(95, 6);
                    printf("|                                                      |");
                    coordxy(95, 7);
                    printf("|                                                      |");
                    coordxy(95, 8);
                    printf("|                                                      |");
                    coordxy(95, 9);
                    printf("========================================================");
                    coordxy(100, 7);
                    Pause("Voc� me venceu, como conseguiu?");
                    cenario(Vidas, o);
                }
                else
                {
                    Anubis(FaseAtual, Vidas, o);
                }
            }
            else
            {
                Anubis(FaseAtual, Vidas, o);
            }
        }
        else
        {
            Anubis(FaseAtual, Vidas, o);
        }
    }
    else
    {
        Anubis(FaseAtual, Vidas, o);
    }
}

void cenario(int Vida, int MusicOn)
{
    int Vidas = Vida, o = MusicOn;
    system("cls");
    PrintVida(Vidas);
    char Texto1[] = "Depois de passar pela esfinge voc� chega a �ltima sala da pir�mide. Nota-se que a sala";
    char Texto2[] = "est� vazia, voc� acha isso estranho, ser� que todo esse sacrif�cio foi feito em v�o?";
    char Texto3[] = "de repente voc� escuta uma voz sussurrante dizendo: �O que voc� procura n�o est� aqui,";
    char Texto4[] = "mas posso te dizer como encontrar, siga meus conselhos, voc� n�o tem muito tempo�.";
    char Texto5[] = "Sem entender o que estava acontecendo voc� segue o caminho da voz.";

    coordxy(28, 5);
    printf(ANSI_COLOR_CYAN "=== Caixa de dialogo ======================================================================");
    coordxy(28, 6);
    printf("|                                                                                         |");
    coordxy(28, 7);
    printf("|                                                                                         |");
    coordxy(28, 8);
    printf("|                                                                                         |");
    coordxy(28, 9);
    printf("|                                                                                         |");
    coordxy(28, 10);
    printf("|                                                                                         |");
    coordxy(28, 11);
    printf("|                                                                                         |");
    coordxy(28, 12);
    printf("|                                                                                         |");
    coordxy(28, 13);
    printf("|                                                                                         |");
    coordxy(28, 14);
    printf("|                                                                                         |");
    coordxy(28, 15);
    printf("|                                                                                         |");
    coordxy(28, 16);
    printf("|                                                                                         |");
    coordxy(28, 17);
    printf("===========================================================================================");

    coordxy(31, 7);
    SlowText(Texto1);
    coordxy(30, 9);
    SlowText(Texto2);
    coordxy(30, 11);
    SlowText(Texto3);
    coordxy(30, 13);
    SlowText(Texto4);
    coordxy(30, 15);
    Pause(SlowText(Texto5));
    Fase1Cenario2(Vidas, o);
}

void Fase1Cenario2(int Vida, int MusicOn)
{
    int FaseAtual = 5, Vidas = Vida, o = MusicOn;
    char RespostaChar[200];
    system("cls");
    PrintVida(Vidas);
    char Text1Fase1[] = ANSI_COLOR_DARK_CYAN "Primeiramente, voc� deve se perguntar onde nasce o sol." ANSI_COLOR_RESET;
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
    SetaUpDown(10, 1, 4, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

    switch (opcao)
    {
    case 3:
        system("cls");
        PrintVida(Vidas);
        char Texto4[] = ANSI_COLOR_DARK_CYAN "Correto, mas n�o � apenas isso, o Templo de H�rus n�o � t�o f�cil de encontrar, ent�o me responda novamente.\n\n";
        char Texto5[] = "Se voc� olhar na dire��o em que o sol nasce, qual � a dire��o que fica � sua direita?\n\n" ANSI_COLOR_RESET;
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
        SetaUpDown(10, 1, 4, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

        switch (opcao)
        {
        case 2:
            system("cls");
            char Texto7[] = ANSI_COLOR_DARK_CYAN "Muito bem, voc� encontrou o Templo de H�rus, agora voc� ter� que encontrar um modo de subir a montanha.\n\n" ANSI_COLOR_RESET;
            PrintVida(Vidas);

            printf(ANSI_COLOR_CYAN "=== Caixa de dialogo ======================================================================================\n|                                                                                                         |\n|                                                                                                         |\n|                                                                                                         |\n===========================================================================================================" ANSI_COLOR_RESET);
            coordxy(2, 5);
            Pause(SlowText(Texto7));
            Fase2Cenario2(Vidas, o);
        default:
            system("cls");
            char Texto6[] = ANSI_COLOR_DARK_CYAN "Bom, parece que voc� n�o tem o necess�rio para derrotar Seth, mas n�o se preocupe, voc� ter� um segunda chance." ANSI_COLOR_RESET;
            PrintVida(Vidas);

            printf(ANSI_COLOR_CYAN "=== Caixa de dialogo ==============================================================================================\n|                                                                                                                 |\n|                                                                                                                 |\n|                                                                                                                 |\n===================================================================================================================" ANSI_COLOR_RESET);
            coordxy(2, 5);
            Pause(SlowText(Texto6));
            Anubis(FaseAtual, Vidas, o);
        }
    default:
        system("cls");
        char Texto6[] = ANSI_COLOR_DARK_CYAN "Bom, parece que voc� n�o tem o necess�rio para derrotar Seth, mas n�o se preocupe, voc� ter� um segunda chance." ANSI_COLOR_RESET;
        PrintVida(Vidas);

        printf(ANSI_COLOR_CYAN "=== Caixa de dialogo ==============================================================================================\n|                                                                                                                 |\n|                                                                                                                 |\n|                                                                                                                 |\n===================================================================================================================" ANSI_COLOR_RESET);
        coordxy(2, 5);
        Pause(SlowText(Texto6));
        Anubis(FaseAtual, Vidas, o);
    }

}

void BossSeth(int Vida, int MusicOn, int argc, char *argv[])    //Boss final
{
    int CoolDown = 0, Vidas = Vida, o = MusicOn, VidaSeth = 100, VidaArqueologo = 7, Random, RandomSeth, CoolDownOlhosdeAguia;
    system("cls");
    char Texto1[] = "Ap�s ter entrado no templo voc� se depara com o pr�prio Deus H�rus, por�m ele se encontra com ferimentos de sua �ltima batalha. \nH�rus conta a verdade sobre quem lhe guia, logo voc� descobre que a voz misteriosa era de Seth (Deus do Caos). \nAp�s ouvir isso Seth se manifesta e contradiz Hor�s.\n";
    SlowText(Texto1);

    printf("\n    Acreditar em Hor�s.\n    Acreditar em Seth.");
    SetaUpDown(4, 1, 2, 1, "->", "  ");

    switch(opcao)
    {
    case 1:
        system("cls");
        char Texto2[] = "H�rus: Rapido mortal, pegue o amuleto e obtenha o poder de um Deus, eu lhe darei o resto do meu poder, derrote Seth e traga a paz.\n\n";
        char Texto3[] = "Voc� pega o amuleto com o poder de Hor�s e entra em uma batalha mortal contra Seth\n";
        char Texto4[] = "Voc� tem tr�s op��es de ataques, saiba que o dano dos ataques causados em Seth sera escolhido randomicamente.\n\n";
        SlowText(Texto2);
        SlowText(Texto3);
        Pause("\nPressione qualquer tecla para continuar...\n");
        while (VidaArqueologo > 1 || VidaSeth > 1 )
        {
            system("cls");
            SlowText(Texto4);
            Pause("Pressione qualquer tecla para continuar...\n");
            printf("\n    Lamina de H�rus. \n    Olhos de �guia    \n    Raio Solar");
            SetaUpDown(4, 1, 3, 1, "->", "  ");

            switch(opcao)
            {
            case 1:
                system("cls");
                printf("Vida Seth: %d\n\n", VidaSeth);
                printf("Vida Arqueologo: %d\n\n", VidaArqueologo);
                char Texto5[] = "Voc� foi na dire��o de Seth e desferiu um ataque com sua lamina.";
                SlowText(Texto5);
                srand(time(NULL));
                Random = rand()%6;
                RandomSeth = rand()%7 + 1;
                printf("\n\nVoc� causou %d de dano a Seth.\n", Random);
                VidaSeth -= Random;
                if (VidaSeth > 0 && VidaArqueologo > 0)
                {
                    printf("\nSeth revidou o ataque e lhe causou %d de dano.\n\n", RandomSeth);
                    VidaArqueologo -= RandomSeth;
                    Pause(" ");

                }
                if (VidaSeth <= 0 && VidaArqueologo > 0)
                {
                    Vencedor(o);
                }
                if (VidaArqueologo < 1)
                {
                    Perdedor(Vidas, o, VidaSeth);
                }
                CoolDown--;
                break;

            case 2:
                system("cls");
                if (CoolDownOlhosdeAguia != 1)
                {
                    printf("Vida Seth: %d\n\n", VidaSeth);
                    printf("Vida Arqueologo: %d\n\n", VidaArqueologo);
                    char Texto8[] = "Voc� usa uma vis�o ampliada e descobre uma vulnerabilidade em Seth.";
                    SlowText(Texto8);
                    srand(time(NULL));
                    Random = rand()%6 + 2; //Maior probabilidade de dar dano alto
                    RandomSeth = rand()%7 + 1;
                    printf("\n\nVoc� causou %d de dano a Seth.\n", Random);
                    VidaSeth -= Random;
                    if (VidaSeth > 0 && VidaArqueologo > 0)
                    {
                        printf("Seth revidou o ataque e lhe causou %d de dano.\n\n", RandomSeth);
                        VidaArqueologo -= RandomSeth;
                        Pause(" ");
                    }
                    if(VidaSeth <= 0 && VidaArqueologo > 0)
                    {
                        Vencedor(o);
                    }
                    if(VidaArqueologo < 1)
                    {
                        Perdedor(Vidas, o, VidaSeth);
                    }
                    CoolDownOlhosdeAguia = 1;
                    CoolDown--;
                    break;
                }
                else
                {
                    char Texto1[] = "Essa habilidade n�o pode ser usada novamente.\n\n";
                    Pause(SlowText(Texto1));
                    break;
                }
            case 3:
                system("cls");
                if (CoolDown > 0)
                {
                    Pause("Voc� n�o pode usar este poder agora.\n\n");
                }
                else
                {
                    printf("Vida Seth: %d\n\n", VidaSeth);
                    printf("Vida Arqueologo: %d\n\n", VidaArqueologo);
                    char Texto10[] = "Voc� utiliza o raio solar e deixa Seth cego por alguns segundos, voc� aproveita e desfere um ataque.";
                    SlowText(Texto10);
                    srand(time(NULL));
                    Random = rand()%6;
                    printf("\n\nVoc� causou %d de dano a Seth.\n", Random);
                    VidaSeth -= Random;
                    if (VidaSeth > 0 && VidaArqueologo > 0)
                    {
                        char Texto11[] = "\nSeth ficou cego e nao conseguiu te atacar.\n";
                        Pause(SlowText(Texto11));
                    }
                    if (VidaSeth <= 0 && VidaArqueologo > 0)
                    {
                        Vencedor(o);
                    }
                    if(VidaArqueologo < 1)
                    {
                        Perdedor(Vidas, o, VidaSeth);
                    }
                    CoolDown = 2;
                }
                break;
            }
        }

    case 2:
        system("cls");
        char Texto12[] = "Seth: Como p�de ser t�o ing�nuo mortal, agora com esse poder finalmente poderei conquistar todo o Egito e acabarei com os 7 reinos.\n\n";
        char Texto13[] = "Hor�s: Como p�de ser t�o Idiota ao confiar nele mortal, agora o destino do mundo e o dos 7 reinos estao nas maos de Seth.\n\n";
        char Texto14[] = "Seth aniquilou voc� e lan�ou o caos sobre todos os reinos.\n\n";
        SlowText(Texto12);
        SlowText(Texto13);
        Pause(SlowText(Texto14));
        GameOver(o);
    }
}
