#include "../../Menu/Includes.h"

void Fase1(int Vida, int MusicOn)
{
    int Resposta, FaseAtual = 1, o = MusicOn, Vidas = Vida;
    system("cls");

    if (o == 0)
        PlaySound(TEXT("null.wav"), NULL, SND_ASYNC);
    else
        PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);

    PrintVida(Vidas);
    char Texto1[] = ANSI_COLOR_DARK_CYAN "  Voc� se depara com uma porta com �pe�as� faltando, olha para o lado e observa que h�: 3 pe�as com s�mbolos de An�bis, 3 pe�as \n\n" ANSI_COLOR_RESET;
    char Texto2[] = ANSI_COLOR_DARK_CYAN " com s�mbolos de H�rus, e 4 pe�as com s�mbolos de Seth.\n\n";
    char Texto3[] = ANSI_COLOR_DARK_CYAN "  Enquanto olha para as pe�as voc� ouve algo, quando olha para a porta se depara com a seguinte frase sendo constru�da: Me diga \n\n";
    char Texto4[] = ANSI_COLOR_DARK_CYAN " quantas combina��es pode-se fazer com as pe�as e liberarei a sua passagem.\n\n";
    char Texto5[] = ANSI_COLOR_DARK_CYAN " Quantas combina��es podem ser feitas? ";

    coordxy(11, 4);
    printf(ANSI_COLOR_CYAN "=== Caixa de Dial�go ==============================================================================================================\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           ===================================================================================================================================" ANSI_COLOR_RESET);
    coordxy(13, 6);
    SlowText(Texto1);
    coordxy(13, 8);
    SlowText(Texto2);
    coordxy(13, 10);
    SlowText(Texto3);
    coordxy(13, 12);
    SlowText(Texto4);
    Pause(" ");
    coordxy(11, 20);
    printf(ANSI_COLOR_CYAN "=============================================================\n           |                                                           |\n           =============================================================" ANSI_COLOR_RESET);
    coordxy(13, 21);
    SlowText(Texto5);
    scanf("%d", &Resposta);
    if (Resposta == 36)
    {
        char Texto6[] = "\n\n            Voc� acertou o n�mero de combina��es\n" ANSI_COLOR_RESET;
        Pause(SlowText(Texto6));
        system("cls");
        Fase2(Vidas, o);
    }
    else
    {
        Pause("\n\n            Voc� ativou uma armadilha, toda pir�mide come�a a tremer.\n\n            Voc� provocou um deslizamento e foi esmagado por uma rocha.\n\n" ANSI_COLOR_RESET);
        system("cls");
        Anubis(FaseAtual, Vidas, o);
    }
}
