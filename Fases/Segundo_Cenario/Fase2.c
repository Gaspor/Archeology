#include "../../Includes.h"

void Fase2Cenario2(int Vida, int MusicOn) {
    int FaseAtual = 6, Vidas = Vida, o = MusicOn;
    char RespostaChar[200];
    system("cls");
    printf("Vidas: %d \n", Vidas);
    char Text1Fase2[] = "  Voc� encontrou a montanha!\n\n  O Templo de H�rus reside no topo desta montanha, para subi-la voc� deve ouvir atentamente \n\n";
    SlowText(Text1Fase2);
    printf("  Me diga qual � a nega��o da seguinte frase: Eu sou R� Deus do Sol\n\n  Resposta(Sem acentua��o): ");
    fflush(stdin);
    gets(RespostaChar);
    if (strcasecmp (RespostaChar, "Eu nao sou ra deus do sol")== 0) {
        char Text2Fase1[] = "\n\n  Surge uma escada que te levar� ao topo da montanha\n\n";
        SlowText(Text2Fase1);
        fflush(stdin);
        system("pause");
        system("cls");
        Fase3Cenario2(Vidas, o);
    } else {
        char Text3Fase1[] = "\n\n  Uma escada surge por toda a montanha, voc� tenta subi-l�, mas quando voc� estava no \n\n  meio do caminha ela come�a a se desfazer, voc� morreu!\n\n";
        SlowText(Text3Fase1);
        system("pause");
        Anubis(FaseAtual, Vidas, o);
    }
}
