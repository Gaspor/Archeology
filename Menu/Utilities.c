#include "Includes.h"

int KeyPress;
char NamePlayer[200];

// Setas //
void coordxy(int x,int y)
{
    COORD Mouse;
    Mouse.X = x;
    Mouse.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Mouse);
}

int SetaUpDown (int La,int coordx,int BLimite,int LOper,char *SetaModel,char *SetaModelSpace)     // Seta pra cima e pra baixo //
{
    int opcao = 0, L = La, b = 1;
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
    return opcao;
}

void SetaLeftRight (int La,int coordy,int BLimite,int LOper,char *SetaModel,char *SetaModelSpace)     // Seta pra direita e pra esquerda //
{
    int opcao = 0, L = La, b = 1;
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
    return opcao;
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

// Game Utilities //
void Player(int Vida, int MusicOn)      // Nome do Player //
{
    int Vidas = Vida, o = MusicOn, x = 45, y = 10, i = y;
    system("cls");
    coordxy(x, y-4);
    printf(ANSI_COLOR_CYAN "=========================================================================");
    for (y = 0; y < 6; y++)
    {
        coordxy(x, y+7);
        printf("|                                                                       |");
    }
    coordxy(x, y+7);
    printf("=========================================================================" ANSI_COLOR_RESET);
    coordxy(x+3, y+6);
    printf(ANSI_COLOR_CYAN "Por favor, não aperte nada enquanto o texto é digitado em sua tela.");
    coordxy(x+18, y+5);
    printf("Por favor, não use caractere especial");
    coordxy(x+23, y+2);
    printf("Digite o nome do Arqueólogo:" ANSI_COLOR_DARK_CYAN);
    coordxy(x+25, y+4);
    printf("_______________________");
    fflush(stdin);
    coordxy(x+25,y+4);
    gets(NamePlayer);
KbLore:
    coordxy(x+20, y+9);
    printf(ANSI_COLOR_CYAN "=================================");
    for (y = 0; y < 6; y++)
    {
        coordxy(x+20,y+16);
        printf("|                               |");
    }
    coordxy(x+20, y+16);
    printf("=================================" ANSI_COLOR_RESET);
    coordxy(x+22, y+11);
    printf(ANSI_COLOR_CYAN "Você deseja pular a História? \n");
    coordxy(x+28, y+13);
    printf("Aperte S para Sim");
    coordxy(x+28, y+14);
    printf("Aperte N para Não" ANSI_COLOR_RESET);
    if (kbhit)
    {
        KeyPress=getch();
    }
    if (KeyPress == 110)
    {
        Lore(Vidas, o);
    }
    if (KeyPress == 115)
    {
        Fase1(Vidas, o);
    }
    else
    {
        goto KbLore;
    }
}

void Lore(int Vida, int MusicOn)    // História primeiro Cenário
{
    int Vidas = Vida, o = MusicOn, x = 4, y = 1;
    system("cls");
    char History1[] = ANSI_COLOR_DARK_CYAN "  Há muitas eras, antes da humanidade nascer, acontecia uma imensa disputa por poder, que nenhum ser mortal poderia presenciar.";
    char History2[] = "  Uma batalha entre Deuses antigos pela posse de um amuleto, aquele que possuísse tal artefato ampliaria seus poderes e reinaria sobre o mundo.";
    char History3[] = "  Os Deuses lutaram por séculos para obter tal poder, mas no meio desta grande batalha, Osíris, o Deus do julgamento interveio, e com sua imensa força";
    char History4[] = " amaldiçoou o amuleto, fazendo com que os Deuses não pudessem usufruir de seu poder infinito. Com o passar das eras o amuleto se perdeu e o grande";
    char History5[] = " Deus Rá criou a humanidade. Os Deuses pareciam ter se esquecido do artefato, até que no ano 51 A.C um soldado percebeu que algo brilhava em meio";
    char History6[] = " a terra, tomado pela curiosidade ele decide vasculhar o chão, e finalmente encontra algo até então desconhecido pelos mortais daquele tempo, tudo o que";
    char History7[] = " ele via era seu formato peculiar. Com este artefato desenterrado uma enorme aura emergiu dele, os humanos não podiam perceber tal coisa, mas os Deuses ";
    char History8[] = " perceberam na hora que o amuleto havia sido encontrado. Por curiosidade o soldado o coloca em volta de seu pescoço, e sem perceber um grande poder";
    char History9[] = " começou a fluir pelo seu corpo, os soldados aliados que estavam em volta perceberam o comportamento estranho de seu companheiro, mas quando se";
    char History10[] = " aproximaram do soldado ele se transformou em cinzas na frente de seus olhos, assustados com a cena, os soldados em volta repararam que vinha um brilho";
    char History11[] = " estranho daquele artefato, e ligaram a morte de seu amigo diretamente a ele. Assustados com a presença de algo tão poderoso, ";
    char History12[] = " eles informaram ao faraó sobre o ocorrido, sem acreditar no que ouvia e totalmente aterrorizado, o faraó ordena aos seus súditos que";
    char History13[] = " construam uma enorme pirâmide em volta daquele artefato peculiar, e que o enterrem o mais fundo possível nas catacumbas da nova pirâmide. ";
    char History14[] = " Os Deuses não tinham muita influência no mundo mortal, mas o que eles não sabiam era que Seth tentaria manipular um mortal para obter o \“Olho de Hórus\”";
    char History15[] = " e retirar sua maldição. Com a maldição desfeita, Seth poderá reinar sobre todos os Deuses, e seus reinos, Seth libertará toda a escuridão sobre o mundo ";
    char History16[] = " e assim o governará por toda eternidade." ANSI_COLOR_RESET;

    char Texto2[] = ANSI_COLOR_DARK_CYAN "  Vocé é um arqueólogo conhecido como " ANSI_COLOR_CYAN;
    char Texto3[] = ANSI_COLOR_DARK_CYAN ", ao estudar está lenda você decide ir em busca deste artefato antigo...";
    char Texto4[] = " Esta será um jornada tortuosa, e para enfim alcançar o antigo artefato, você terá que passar pelos mais difíceis desafios..." ANSI_COLOR_RESET;

    coordxy(x, y);
    printf(ANSI_COLOR_CYAN "=== História ===================================================================================================================================================\n");
    while (y <= 38)
    {
        coordxy(x, y+1);
        printf("|                                                                                                                                                              |");
        y++;
    }
    coordxy(x, y);
    printf("================================================================================================================================================================");

    coordxy(x+2, 3);
    SlowText(History1);
    coordxy(x+2, 5);
    SlowText(History2);
    coordxy(x+2, 7);
    SlowText(History3);
    coordxy(x+2, 9);
    SlowText(History4);
    coordxy(x+2, 11);
    SlowText(History5);
    coordxy(x+2, 13);
    SlowText(History6);
    coordxy(x+2, 15);
    SlowText(History7);
    coordxy(x+2, 17);
    SlowText(History8);
    coordxy(x+2, 19);
    SlowText(History9);
    coordxy(x+2, 21);
    SlowText(History10);
    coordxy(x+2, 23);
    SlowText(History11);
    coordxy(x+2, 25);
    SlowText(History12);
    coordxy(x+2, 27);
    SlowText(History13);
    coordxy(x+2, 29);
    SlowText(History14);
    coordxy(x+2, 31);
    SlowText(History15);
    coordxy(x+2, 33);
    SlowText(History16);

    coordxy(x+2, 35);
    SlowText(Texto2);
    SlowText(NamePlayer);
    SlowText(Texto3);
    coordxy(x+2, 37);
    Pause(SlowText(Texto4));
    Fase1(Vidas, o);
}

void Pause(char *Text)
{
    printf(Text);
    fflush(stdin);
    getch();
}

void Anubis(int Fase, int Vida, int MusicOn)   // Anúbis (Controlador de Vidas do Player)
{
    int Vidas = Vida, o = MusicOn;

    system("cls");
    coordxy(0, 4);
    printf(ANSI_COLOR_CYAN "=== Caixa de dialogo ========================================================================================\n|                                                                                                           |\n|                                                                                                           |\n|                                                                                                           |\n=============================================================================================================" ANSI_COLOR_DARK_RED);
    coordxy(0, 0);
    if (Vida >= 1 && Fase == 1)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        coordxy(3, 6);
        Pause(ANSI_COLOR_DARK_RED "Anúbis: Não acredito que você errou algo tão fácil, mas não se preocupe, te darei uma segunda chance." ANSI_COLOR_RESET);
        system("cls");
        Fase1(Vidas, o);
    }
    if (Vida >= 1 && Fase == 2)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        coordxy(3, 6);
        Pause(ANSI_COLOR_DARK_RED "Anúbis: Eu te darei mais uma chance de vida, mortal não a desperdice." ANSI_COLOR_RESET);
        system("cls");
        Fase2(Vidas, o);
    }
    if (Vida >= 1 && Fase == 4)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        coordxy(3, 6);
        Pause(ANSI_COLOR_DARK_RED "Anúbis: Você morreu, irei te reviver apenas dessa vez, não cometa mais erros." ANSI_COLOR_RESET);
        system("cls");
        BossEsfinge(Vidas, o);
    }
    if (Vida >= 1 && Fase == 5)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        coordxy(3, 6);
        Pause(ANSI_COLOR_DARK_RED "Anúbis: Só tenho poder suficiente pra te reviver desta vez, então não erre novamente!" ANSI_COLOR_RESET);
        system("cls");
        Fase1Cenario2(Vidas, o);
    }
    if (Vida >= 1 && Fase == 6)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        coordxy(3, 6);
        Pause(ANSI_COLOR_DARK_RED "Anúbis: Você morreu, não cometa mais erros, pois, não irei te ajudar da próxima vez!" ANSI_COLOR_RESET);
        system("cls");
        Fase2Cenario2(Vidas, o);
    }
    if (Vida >= 1 && Fase == 7)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        coordxy(3, 6);
        Pause(ANSI_COLOR_DARK_RED "Anúbis: Você morreu no labirinto, espero que tenha aprendido com o seu erro, pois só te darei uma chance!" ANSI_COLOR_RESET);
        system("cls");
        Fase3Cenario2(Vidas, o);
    }
    if (Vida >= 1 && Fase == 8)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        coordxy(3, 6);
        Pause(ANSI_COLOR_DARK_RED "Anúbis: Você não obteve sorte nessa batalha, mas serei benevolente e te darei outra chance!" ANSI_COLOR_RESET);
        system("cls");
        BossSeth(Vidas, o);
    }
    else
    {
        PrintVida(Vidas);
        coordxy(3, 6);
        Pause(ANSI_COLOR_RED "Você não tem vidas restantes!" ANSI_COLOR_RESET);
        GameOver(o);
    }
}

void PrintVida(Vida)
{
    int Vidas = Vida;

    if (Vidas >= 1 && Vidas < 10)
    {
        printf("\033[1;31m============\n| Vidas: %d |\n============\033[1;0m\n", Vidas);
    }
    else if (Vidas >= 10 && Vidas < 100)
    {
        printf("\033[1;31m=============\n| Vidas: %d |\n=============\033[1;0m\n", Vidas);
    }
    else if (Vidas >= 100 && Vidas < 1000)
    {
        printf("\033[1;31m==============\n| Vidas: %d |\n==============\033[1;0m\n", Vidas);
    }
    else if (Vidas == 0)
    {
        printf("\033[1;31m============\n| Vidas: \033[0;31m%d\033[1;31m |\n============\033[1;0m\n", Vidas);
    }
    else
    {
        printf("\033[1;31m================\n| Vidas: Error |\n================\033[1;0m\n");
    }
}

void Vencedor(int MusicOn)  // Função caso o jogador vença o jogo
{
    int o = MusicOn;
    Pause(" ");
    system("cls");
    char Texto1[] = ANSI_COLOR_DARK_CYAN "A batalha foi longa, mas finalmente Seth foi derrotado, com sua morte o mundo viverá em paz novamente. Porém a paz nunca é duradoura...";
    char Texto2[] = "Sistema: Parabéns " ANSI_COLOR_CYAN;
    char Texto3[] = ANSI_COLOR_DARK_CYAN ", você venceu Seth e restaurou a ordem.";
    printf(ANSI_COLOR_CYAN "  === Caixa de Diálogo ======================================================================================================================\n  |                                                                                                                                         |\n  |                                                                                                                                         |\n  |                                                                                                                                         |\n  |                                                                                                                                         |\n  |                                                                                                                                         |\n  |                                                                                                                                         |\n  |                                                                                                                                         |\n  ===========================================================================================================================================" ANSI_COLOR_RESET);

    coordxy(4, 2);
    SlowText(Texto1);
    coordxy(4, 4);
    SlowText(Texto2);
    SlowText(NamePlayer);
    SlowText(Texto3);
    coordxy(4, 6);
    Pause(ANSI_COLOR_YELLOW "Obrigado por jogar, aperte qualquer tecla para retornar ao menu." ANSI_COLOR_RESET);
    Menu(o);
}

void Perdedor(int Vida, int MusicOn, int VidaSeth)
{
    int o = MusicOn, RandomSeth = VidaSeth, FaseAtual = 8, Vidas = Vida;
    system("cls");
    coordxy(0, 0);
    printf(ANSI_COLOR_CYAN "=== Log de batalha ===");
    coordxy(0, 1);
    printf("|                    |");
    coordxy(0, 2);
    printf("|                    |");
    coordxy(0, 3);
    printf("|                    |");
    coordxy(0, 4);
    printf("|                    |");
    coordxy(0, 5);
    printf("|                    |");
    coordxy(0, 6);
    printf("======================" ANSI_COLOR_RESET);
    coordxy(2, 2);
    printf(ANSI_COLOR_DARK_CYAN "Vida Seth: %d", VidaSeth);
    coordxy(2, 4);
    Pause(ANSI_COLOR_RED "Voce morreu!" ANSI_COLOR_RESET);
    Anubis(FaseAtual, Vidas, o);
}

void GameOver(int MusicOn)    // Função de GameOver //
{
    int o = MusicOn;
    system("cls");
    coordxy(75, 20);
    char GameOver[] = ANSI_COLOR_RED "Game Over" ANSI_COLOR_RESET;
    Pause(SlowText(GameOver));
    system("cls");
    Menu(o);
}

void Archeology()
{
    coordxy(70, 15);
    printf(ANSI_COLOR_RED "Archeology Game" ANSI_COLOR_RESET);
}
