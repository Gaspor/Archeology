#include "../../Includes.h"

void Fase3(int Vida, int MusicOn) {
    int FaseAtual = 3, Vidas = Vida, o = MusicOn;
    char RespostaChar[200];
    printf("Vidas: %d \n", Vidas);
    char Text1Fase3[] = "   Você passa pela entrada da segunda fase e observa que há outra passagem, você anda até ela e de repente a entrada \n\n se fecha e você ouve um barulho intenso, uma enorme esfinge feita de areia se ergue diante de você.\n\n";
    char Text2Fase3[] = "   \"Esfinge: Eu sou a última porta para o seu destino, responda corretamente meu enigma e sua passagem será liberada.\"\n\n";
    char Text3Fase3[] = "   Esfinge: Eu nunca fui e sempre poderei ser, ninguém jamais me viu ou verá, mas sou a certeza de todos os que vivem e que respiram, quem sou eu?: ";
    SlowText(Text1Fase3);
    SlowText(Text2Fase3);
    SlowText(Text3Fase3);
    fflush(stdin);
    gets(RespostaChar);
    if ((strcasecmp (RespostaChar, "amanha")== 0)||(strcasecmp (RespostaChar, "futuro")== 0)) {
        char Text4Fase3[] = "\n   Você acertou o meu enigma, eu te concedo a passagem para a próxima sala!\n";
        SlowText(Text4Fase3);
        fflush(stdin);
        Sleep(4000);
        system("cls");
        cenario(Vidas, o);
    } else {
       printf("\nVocê errou, agora meu enfrente!!!\n\n");
       system("pause");
       BossEsfinge(Vidas, o);
    }
}
