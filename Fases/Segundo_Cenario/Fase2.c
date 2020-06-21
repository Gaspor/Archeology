#include "../../Includes.h"

void Fase2Cenario2(int Vida, int MusicOn)
{
    int FaseAtual = 6, Vidas = Vida, o = MusicOn;
    char RespostaChar[200];
    system("cls");
    PrintVida(Vidas);
    printf(ANSI_COLOR_CYAN " ====== Caixa de Diálogo ===================================================================================================== \n |                                                                                                                           | \n |                                                                                                                           | \n |                                                                                                                           | \n |                                                                                                                           |\n |                                                                                                                           |\n =============================================================================================================================\n" ANSI_COLOR_RESET);
    char Text1Fase1[] = ANSI_COLOR_DARK_CYAN "Você encontra a montanha e ouve a mesma voz: O templo de Hórus reside no topo desta montanha, resolva este anagrama e te \n";
    char Text2Fase1[] = "darei uma pista de como subi-lá." ANSI_COLOR_RESET;
    coordxy(4, 5);
    SlowText(Text1Fase1);
    coordxy(3, 7);
    SlowText(Text2Fase1);
    coordxy(0, 12);
    printf(ANSI_COLOR_CYAN "  Resolva o anagrama: \n\n");
    printf("   ======================= \n   |                     |\n   |  \e[0;36mA B R I N I L O T\e[1;36m  |\n   |                     |\n   |   \e[0;36mE O R H S U D\e[1;36m     |\n   |                     |\n   =======================\n\n Resposta do anagrama: " ANSI_COLOR_RESET);
    fflush(stdin);
    gets(RespostaChar);
    if (strcasecmp (RespostaChar, "LABIRINTO DE HORUS")== 0)
    {
        char Text2Fase1[] = ANSI_COLOR_DARK_CYAN "Você acertou, e agora a escada surgirá!" ANSI_COLOR_RESET;
        coordxy(0, 24);
        printf(ANSI_COLOR_CYAN "===========================================\n|                                         |\n|                                         |\n|                                         |\n===========================================" ANSI_COLOR_RESET);
        coordxy(2, 26);
        Pause(SlowText(Text2Fase1));
        system("cls");
        Fase3Cenario2(Vidas, o);
    }
    else
    {
        char Text3Fase1[] = ANSI_COLOR_DARK_CYAN "Você decifrou o anagrama de forma errada, você segue a pista do seu anagrama,";
        char Text4Fase1[] = "porém ele estava incorreto, eventualmente a escada não aparece e você morre de fome e sede." ANSI_COLOR_RESET;
        coordxy(0, 24);
        printf(ANSI_COLOR_CYAN "===============================================================================================\n|                                                                                             |\n|                                                                                             |\n|                                                                                             |\n===============================================================================================" ANSI_COLOR_RESET);
        coordxy(2, 25);
        SlowText(Text3Fase1);
        coordxy(2, 27);
        Pause(SlowText(Text4Fase1));
        Anubis(FaseAtual, Vidas, o);
    }
}
