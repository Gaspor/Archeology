#include "../../Includes.h"

void cenario(int Vida) {
    int Vidas = Vida;
    system("cls");
    printf("Vidas : %d\n", Vidas);
    char Texto1[] = "   Depois de passar pela esfinge voc� chega a �ltima sala da pir�mide. Nota-se que a sala \n\n est� vazia, voc� acha isso estranho, ser� que todo esse sacrif�cio foi feito em v�o?,\n\n de repente voc� escuta uma voz sussurrante dizendo: �O que voc� procura n�o est� aqui,\n\n mas posso te dizer como encontrar, siga meus conselhos, voc� n�o tem muito tempo�.\n\n Sem entender o que estava acontecendo voc� segue o caminho da voz.\n";
    SlowText(Texto1);
    system("pause");
    Fase1Cenario2(Vidas);
}

void Fase1Cenario2(int Vida) {
    int FaseAtual = 5, Vidas = Vida;
    char RespostaChar[200];
    system("cls");
    printf("Vidas : %d\n", Vidas);
    char Text1Fase1[] = "  Voc� sai da pir�mide e ouve a mesma voz: O templo de H�rus emergiu no deserto, resolva este anagrama e te \n darei uma pista de como encontr�-lo\n\n  Resolva o anagrama: \n";
    SlowText(Text1Fase1);
    printf("   ======================= \n   |  N C E O T E R N A  |\n   |   N A N O M H T A   |\n   |      L S O O D      |\n   =======================\n\n Resposta do anagrama: ");
    fflush(stdin);
    gets(RespostaChar);
    if (strcasecmp (RespostaChar, "ENCONTRE A MONTANHA DO SOL")== 0) {
        char Text2Fase1[] = "\n   Voc� acertou, agora use essa frase para encontrar o Templo de H�rus!\n\n";
        SlowText(Text2Fase1);
        fflush(stdin);
        system("pause");
        system("cls");
        Fase2Cenario2(Vidas);
    } else {
        char Text3Fase1[] = "  Voc� decifrou o anagrama de forma errada, voc� segue a pista do seu anagrama, \n por�m ele estava incorreto, eventualmente voc� n�o encontra o templo e morre de fome e sede\n\n";
        SlowText(Text3Fase1);
        system("pause");
        system("cls");
        Anubis(FaseAtual, Vidas);
    }
}

