#include "../../Includes.h"

void Fase2Cenario2(int Vida, int MusicOn)
{
    int FaseAtual = 6, Vidas = Vida, o = MusicOn;
    char RespostaChar[200];
    system("cls");
    printf("Vidas: %d \n", Vidas);
    char Text1Fase1[] = "  Você encontra a monatnha e ouve a mesma voz: O templo de Hórus reside no topo desta montanha, resolva este anagrama e te \n darei uma pista de como subi-lá\n\n  Resolva o anagrama: \n";
    SlowText(Text1Fase1);
    printf("   ======================= \n   |  A B R I N I L O T  |\n   |                     |\n   |    E D O R H S U    |\n   =======================\n\n Resposta do anagrama: ");
    fflush(stdin);
    gets(RespostaChar);
    if (strcasecmp (RespostaChar, "LABIRINTO DE HORUS")== 0)
    {
        char Text2Fase1[] = "\n   Você acertou, e agora a escada surgirá!\n\n";
        SlowText(Text2Fase1);
        fflush(stdin);
        system("pause");
        system("cls");
        Fase3Cenario2(Vidas, o);
    }
    else
    {
        char Text3Fase1[] = "  Você decifrou o anagrama de forma errada, você segue a pista do seu anagrama, \n porém ele estava incorreto, eventualmente a escada não aparece e você morre de fome e sede\n\n";
        SlowText(Text3Fase1);
        system("pause");
        Anubis(FaseAtual, Vidas, o);
    }
}
