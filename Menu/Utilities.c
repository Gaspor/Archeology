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
    int i, TimeText = 0;
    for (i = 0; Text[i] != '\0'; i++)
    {
        printf("%c",Text[i]);
        Sleep(TimeText);
    }
}

void Player(int Vida, int MusicOn)      // Nome do Player //
{
    int Vidas = Vida, o = MusicOn;
    system("cls");
    printf("  Por favor, não aperte nada enquanto o texto é digitado em sua tela.\n");
    printf("  Por favor, não use caractere especial\n\n");
    printf("  Digite o nome do Arqueólogo: ");
    fflush(stdin);
    gets(NamePlayer);
KbLore:
    coordxy(0,5);
    printf("\n\n Você deseja pular a História? \n   Aperte S para Sim.\n   Aperte N para Não.\n");
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
    int Vidas = Vida, o = MusicOn;
    system("cls");
    char Texto1[20000] = "  No Egito antigo, há muitas eras, antes da humanidade nascer, acontecia uma imensa batalha, algo que nenhum mortal poderia presenciar. Os Deuses antigos travaram uma batalha\n\n mortal pelo poder de um amuleto, aquele que possuísse tal amuleto ampliaria seus poderes e reinaria sobre o mundo. Os Deuses lutaram por séculos para obter tal poder, mas no\n\n meio desta grande batalha, Osíris o Deus do julgamento interveio, e com seu imenso poder amaldiçoou o amuleto, permitindo apenas o uso para aqueles que não possuem o poder\n\n divino. Com o passar das eras o amuleto se perdeu e o grande Deus Rá criou a humanidade. Os Deuses se dispersaram e pareciam ter se esquecido do amuleto, até que no ano 51 A.C\n\n um soldado percebeu que algo brilhava em meio a terra, tomado pela curiosidade ele decide vasculhar o chão, e finalmente encontra um amuleto até então desconhecido, tudo o que\n\n ele via era seu formato peculiar. Com o amuleto desenterrado um enorme poder surgia dele, humanos não podiam perceber, mas os Deuses perceberam na hora que o amuleto havia sido\n\n encontrado, mas sem saber o que era, o soldado coloca o amuleto em volta do pescoço, e sem perceber o poder flui pelo seu corpo, os soldados aliados que estavam em volta\n\n perceberam o comportamento estranho de seu companheiro, mas quando se aproximam dele o portador do amuleto simplesmente se torna cinzas, assustados com a cena os soldados em\n\n volta reparam que vinha um brilho do artefato desconhecido e ligam a morte de seu amigo diretamente ao amuleto. Assustados com a presença de algo tão poderoso os soldados\n\n informam ao faraó sobre o ocorrido, e sem acreditar no que ouvia e totalmente aterrorizado o faraó ordena aos seus súditos que construam uma enorme pirâmide em volta do\n\n amuleto, e que o enterrem o mais fundo possível nas catacumbas da nova pirâmide. Os Deuses não tinham muita influência no mundo mortal, mas o que eles não sabiam era que Seth\n\n tentaria manipular um mortal para obter o \“Olho de Hórus\” e retirar sua maldição. Com a maldição desfeita, Seth reinará sobre todos os Deuses e seus respectivos reinos, Seth\n\n libertará toda a escuridão sobre o mundo e o assim governará por toda eternidade.\n\n\n";
    char Texto2[] = "  Vocé é um arqueólogo conhecido como ";
    char Texto3[] = ", ao estudar está lenda você decide ir em busca deste artefato antigo...\n\n  Essa será um jornada tortuosa, e para enfim alcançar o antigo artefato, você terá que passar pelos mais difíceis \n\n desafios... \n\n\n";

    SlowText(Texto1);
    fflush(stdin);
    system("pause");
    system("cls");
    SlowText(Texto2);
    SlowText(NamePlayer);
    Pause(SlowText(Texto3));
    Fase1(Vidas, o);
}

void Pause(char *Text)
{
    printf(Text);
    getch();
}


// Game Utilities //
void Anubis(int Fase, int Vida, int MusicOn)   // Anúbis (Controlador de Vidas do Player)
{
    int Vidas = Vida, o = MusicOn;

    system("cls");
    if (Vida >= 1 && Fase == 1)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        Pause("\n  Anúbis: Não acredito que você errou algo tão fácil, mas não se preocupe, te darei uma segunda chance");
        system("cls");
        Fase1(Vidas, o);
    }
    if (Vida >= 1 && Fase == 2)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        Pause("\n  Anúbis: Eu te darei mais uma chance de vida, mortal não a desperdice");
        system("cls");
        Fase2(Vidas, o);
    }
    if (Vida >= 1 && Fase == 4)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        Pause("\n  Anúbis: Você morreu, irei te reviver apenas dessa vez, não cometa mais erros");
        system("cls");
        BossEsfinge(Vidas, o);
    }
    if (Vida >= 1 && Fase == 5)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        Pause("\n  Anúbis: Só tenho poder suficiente pra te reviver desta vez, então não erre novamente!");
        system("cls");
        Fase1Cenario2(Vidas, o);
    }
    if (Vida >= 1 && Fase == 6)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        Pause("\n  Anúbis: Você morreu, não cometa mais erros, pois, não irei te ajudar da próxima vez!\n\n");
        system("cls");
        Fase2Cenario2(Vidas, o);
    }
    if (Vida >= 1 && Fase == 7)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        Pause("\n  Anúbis: Você morreu no labirinto, espero que tenha aprendido com o seu erro, pois só te darei uma chance!\n\n");
        system("cls");
        Fase3Cenario2(Vidas, o);
    }
    if (Vida >= 1 && Fase == 8)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        Pause("\n  Anúbis: Você não obteve sorte nessa batalha, mas serei benevolente e te darei outra chance!\n\n");
        system("cls");
        BossSeth(Vidas, o);
    }
    else
    {
        PrintVida(Vidas);
        Pause("\n  Você não tem vidas restantes\n\n");
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
    else if (Vidas >= 10 && Vidas < 100){
        printf("\033[1;31m=============\n| Vidas: %d |\n=============\033[1;0m\n", Vidas);
    }
    else if (Vidas >= 100 && Vidas < 1000){
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
    Pause("Pressione qualquer tecla para continuar...");
    system("cls");
    char Texto1[] = "A batalha foi longa mas enfim Seth foi derrotado, com sua morte o mundo viverá em paz novamente. Porém a paz nunca é duradoura...\n\n";
    char Texto2[] = "Sistema: Parabéns ";
    char Texto3[] = ", você venceu Seth e restaurou a ordem.\n\n";
    SlowText(Texto1);
    SlowText(Texto2);
    SlowText(NamePlayer);
    SlowText(Texto3);
    Pause("Obrigado por jogar, aperte qualquer tecla para retornar ao menu.");
    Menu(o);
}

void Perdedor(int Vida, int MusicOn, int VidaSeth)
{
    int o = MusicOn, RandomSeth = VidaSeth, FaseAtual = 8, Vidas = Vida;
    system("cls");
    printf("Vida Seth: %d\n\n", VidaSeth);
    Pause("\nVoce morreu\n");
    Anubis(FaseAtual, Vidas, o);

}

void GameOver(int MusicOn)    // Função de GameOver //
{
    int o = MusicOn;
    char GameOver[] = "  Game Over";
    SlowText(GameOver);
    Pause(" ");
    system("cls");
    Menu(o);
}
