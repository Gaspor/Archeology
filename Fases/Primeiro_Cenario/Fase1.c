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
    char Texto1[] = ANSI_COLOR_DARK_CYAN "  Você se depara com uma porta com “peças” faltando, olha para o lado e observa que há: 3 peças com símbolos de Anúbis, 3 peças \n\n" ANSI_COLOR_RESET;
    char Texto2[] = ANSI_COLOR_DARK_CYAN " com símbolos de Hórus, e 4 peças com símbolos de Seth.\n\n";
    char Texto3[] = ANSI_COLOR_DARK_CYAN "  Enquanto olha para as peças você ouve algo, quando olha para a porta se depara com a seguinte frase sendo construída: Me diga \n\n";
    char Texto4[] = ANSI_COLOR_DARK_CYAN " quantas combinações pode-se fazer com as peças e liberarei a sua passagem.\n\n";
    char Texto5[] = ANSI_COLOR_DARK_CYAN " Quantas combinações podem ser feitas? ";

    coordxy(11, 4);
    printf(ANSI_COLOR_CYAN "=== Caixa de Dialógo ==============================================================================================================\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           |                                                                                                                                 |\n           ===================================================================================================================================" ANSI_COLOR_RESET);
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
        char Texto6[] = "\n\n            Você acertou o número de combinações\n" ANSI_COLOR_RESET;
        Pause(SlowText(Texto6));
        system("cls");
        Fase2(Vidas, o);
    }
    else
    {
        Pause("\n\n            Você ativou uma armadilha, toda pirâmide começa a tremer.\n\n            Você provocou um deslizamento e foi esmagado por uma rocha.\n\n" ANSI_COLOR_RESET);
        system("cls");
        Anubis(FaseAtual, Vidas, o);
    }
}
