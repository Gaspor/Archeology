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
    printf("  Por favor, n�o aperte nada enquanto o texto � digitado em sua tela.\n");
    printf("  Por favor, n�o use caractere especial\n\n");
    printf("  Digite o nome do Arque�logo: ");
    fflush(stdin);
    gets(NamePlayer);
KbLore:
    coordxy(0,5);
    printf("\n\n Voc� deseja pular a Hist�ria? \n   Aperte S para Sim.\n   Aperte N para N�o.\n");
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

void Lore(int Vida, int MusicOn)    // Hist�ria primeiro Cen�rio
{
    int Vidas = Vida, o = MusicOn;
    system("cls");
    char Texto1[20000] = "  No Egito antigo, h� muitas eras, antes da humanidade nascer, acontecia uma imensa batalha, algo que nenhum mortal poderia presenciar. Os Deuses antigos travaram uma batalha\n\n mortal pelo poder de um amuleto, aquele que possu�sse tal amuleto ampliaria seus poderes e reinaria sobre o mundo. Os Deuses lutaram por s�culos para obter tal poder, mas no\n\n meio desta grande batalha, Os�ris o Deus do julgamento interveio, e com seu imenso poder amaldi�oou o amuleto, permitindo apenas o uso para aqueles que n�o possuem o poder\n\n divino. Com o passar das eras o amuleto se perdeu e o grande Deus R� criou a humanidade. Os Deuses se dispersaram e pareciam ter se esquecido do amuleto, at� que no ano 51 A.C\n\n um soldado percebeu que algo brilhava em meio a terra, tomado pela curiosidade ele decide vasculhar o ch�o, e finalmente encontra um amuleto at� ent�o desconhecido, tudo o que\n\n ele via era seu formato peculiar. Com o amuleto desenterrado um enorme poder surgia dele, humanos n�o podiam perceber, mas os Deuses perceberam na hora que o amuleto havia sido\n\n encontrado, mas sem saber o que era, o soldado coloca o amuleto em volta do pesco�o, e sem perceber o poder flui pelo seu corpo, os soldados aliados que estavam em volta\n\n perceberam o comportamento estranho de seu companheiro, mas quando se aproximam dele o portador do amuleto simplesmente se torna cinzas, assustados com a cena os soldados em\n\n volta reparam que vinha um brilho do artefato desconhecido e ligam a morte de seu amigo diretamente ao amuleto. Assustados com a presen�a de algo t�o poderoso os soldados\n\n informam ao fara� sobre o ocorrido, e sem acreditar no que ouvia e totalmente aterrorizado o fara� ordena aos seus s�ditos que construam uma enorme pir�mide em volta do\n\n amuleto, e que o enterrem o mais fundo poss�vel nas catacumbas da nova pir�mide. Os Deuses n�o tinham muita influ�ncia no mundo mortal, mas o que eles n�o sabiam era que Seth\n\n tentaria manipular um mortal para obter o \�Olho de H�rus\� e retirar sua maldi��o. Com a maldi��o desfeita, Seth reinar� sobre todos os Deuses e seus respectivos reinos, Seth\n\n libertar� toda a escurid�o sobre o mundo e o assim governar� por toda eternidade.\n\n\n";
    char Texto2[] = "  Voc� � um arque�logo conhecido como ";
    char Texto3[] = ", ao estudar est� lenda voc� decide ir em busca deste artefato antigo...\n\n  Essa ser� um jornada tortuosa, e para enfim alcan�ar o antigo artefato, voc� ter� que passar pelos mais dif�ceis \n\n desafios... \n\n\n";

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
void Anubis(int Fase, int Vida, int MusicOn)   // An�bis (Controlador de Vidas do Player)
{
    int Vidas = Vida, o = MusicOn;

    system("cls");
    if (Vida >= 1 && Fase == 1)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        Pause("\n  An�bis: N�o acredito que voc� errou algo t�o f�cil, mas n�o se preocupe, te darei uma segunda chance");
        system("cls");
        Fase1(Vidas, o);
    }
    if (Vida >= 1 && Fase == 2)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        Pause("\n  An�bis: Eu te darei mais uma chance de vida, mortal n�o a desperdice");
        system("cls");
        Fase2(Vidas, o);
    }
    if (Vida >= 1 && Fase == 4)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        Pause("\n  An�bis: Voc� morreu, irei te reviver apenas dessa vez, n�o cometa mais erros");
        system("cls");
        BossEsfinge(Vidas, o);
    }
    if (Vida >= 1 && Fase == 5)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        Pause("\n  An�bis: S� tenho poder suficiente pra te reviver desta vez, ent�o n�o erre novamente!");
        system("cls");
        Fase1Cenario2(Vidas, o);
    }
    if (Vida >= 1 && Fase == 6)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        Pause("\n  An�bis: Voc� morreu, n�o cometa mais erros, pois, n�o irei te ajudar da pr�xima vez!\n\n");
        system("cls");
        Fase2Cenario2(Vidas, o);
    }
    if (Vida >= 1 && Fase == 7)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        Pause("\n  An�bis: Voc� morreu no labirinto, espero que tenha aprendido com o seu erro, pois s� te darei uma chance!\n\n");
        system("cls");
        Fase3Cenario2(Vidas, o);
    }
    if (Vida >= 1 && Fase == 8)
    {
        Vida--;
        Vidas = Vida;
        PrintVida(Vidas);
        Pause("\n  An�bis: Voc� n�o obteve sorte nessa batalha, mas serei benevolente e te darei outra chance!\n\n");
        system("cls");
        BossSeth(Vidas, o);
    }
    else
    {
        PrintVida(Vidas);
        Pause("\n  Voc� n�o tem vidas restantes\n\n");
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

void Vencedor(int MusicOn)  // Fun��o caso o jogador ven�a o jogo
{
    int o = MusicOn;
    Pause("Pressione qualquer tecla para continuar...");
    system("cls");
    char Texto1[] = "A batalha foi longa mas enfim Seth foi derrotado, com sua morte o mundo viver� em paz novamente. Por�m a paz nunca � duradoura...\n\n";
    char Texto2[] = "Sistema: Parab�ns ";
    char Texto3[] = ", voc� venceu Seth e restaurou a ordem.\n\n";
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

void GameOver(int MusicOn)    // Fun��o de GameOver //
{
    int o = MusicOn;
    char GameOver[] = "  Game Over";
    SlowText(GameOver);
    Pause(" ");
    system("cls");
    Menu(o);
}
