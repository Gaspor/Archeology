#include "../../Includes.h"

void Fase3(int Vida, int MusicOn) {
    int FaseAtual = 3, Vidas = Vida, o = MusicOn;
    char RespostaChar[200];
    PrintVida(Vidas);
    char Text1Fase3[] = ANSI_COLOR_DARK_CYAN "   Voc� passa pela entrada da segunda fase e observa que h� outra passagem, voc� anda at� ela e de repente a entrada \n";
    char Text1[] = " se fecha e voc� ouve um barulho intenso, uma enorme esfinge feita de areia se ergue diante de voc�.\n\n";
    char Text2Fase3[] = " \"Esfinge: Eu sou a �ltima porta para o seu destino, responda corretamente meu enigma e sua passagem ser� liberada.\"\n\n";
    char Text3Fase3[] = " Esfinge: Eu nunca fui e sempre poderei ser, ningu�m jamais me viu ou ver�, mas sou a certeza de todos os que vivem e que respiram.";
    char TextEsfinge[] = ANSI_COLOR_DARK_CYAN " Quem sou eu? " ANSI_COLOR_RESET;
    coordxy(11, 4);
    printf(ANSI_COLOR_CYAN "=== Caixa de Dial�go ==================================================================================================================\n           |                                                                                                                                     |\n           |                                                                                                                                     |\n           |                                                                                                                                     |\n           |                                                                                                                                     |\n           |                                                                                                                                     |\n           |                                                                                                                                     |\n           |                                                                                                                                     |\n           |                                                                                                                                     |\n           |                                                                                                                                     |\n           =======================================================================================================================================" ANSI_COLOR_RESET);
    coordxy(13, 6);
    SlowText(Text1Fase3);
    coordxy(13, 8);
    SlowText(Text1);
    coordxy(13, 10);
    SlowText(Text2Fase3);
    coordxy(13, 12);
    SlowText(Text3Fase3);
    coordxy(11, 20);
    printf(ANSI_COLOR_CYAN "=============================================================\n           |                                                           |\n           =============================================================" ANSI_COLOR_RESET);
    coordxy(13, 21);
    SlowText(TextEsfinge);
    fflush(stdin);
    gets(RespostaChar);
    if ((strcasecmp (RespostaChar, "amanha")== 0)||(strcasecmp (RespostaChar, "futuro")== 0)) {
        char Text4Fase3[] = ANSI_COLOR_DARK_CYAN "\n\n            Esfinge: Voc� acertou o meu enigma, eu te concedo a passagem para a pr�xima sala!\n" ANSI_COLOR_RESET;
        system("cls");
        EsfingeImage();
        Pause(SlowText(Text4Fase3));
        system("cls");
        cenario(Vidas, o);
    } else {
        system("cls");
        EsfingeImage();
        Pause(ANSI_COLOR_DARK_RED "\n\n                Voc� errou, agora meu enfrente!!!\n\n" ANSI_COLOR_RESET);
        BossEsfinge(Vidas, o);
    }
}
