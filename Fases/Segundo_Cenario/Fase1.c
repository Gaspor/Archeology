#include "../../Includes.h"

void cenario(int Vida) {
    int Vidas = Vida;
    system("cls");
    printf("Vidas : %d\n", Vidas);
    char Texto1[] = "   Depois de passar pela esfinge você chega a última sala da pirâmide. Nota-se que a sala \n\n está vazia, você acha isso estranho, será que todo esse sacrifício foi feito em vão?,\n\n de repente você escuta uma voz sussurrante dizendo: “O que você procura não está aqui,\n\n mas posso te dizer como encontrar, siga meus conselhos, você não tem muito tempo”.\n\n Sem entender o que estava acontecendo você segue o caminho da voz.\n";
    SlowText(Texto1);
    system("pause");
    Fase1Cenario2(Vidas);
}

void Fase1Cenario2(int Vida) {
    int FaseAtual = 5, Vidas = Vida;
    char RespostaChar[200];
    system("cls");
    printf("Vidas : %d\n", Vidas);
    char Text1Fase1[] = "  Você sai da pirâmide e ouve a mesma voz: O templo de Hórus emergiu no deserto, resolva este anagrama e te \n darei uma pista de como encontrá-lo\n\n  Resolva o anagrama: \n";
    SlowText(Text1Fase1);
    printf("   ======================= \n   |  N C E O T E R N A  |\n   |   N A N O M H T A   |\n   |      L S O O D      |\n   =======================\n\n Resposta do anagrama: ");
    fflush(stdin);
    gets(RespostaChar);
    if (strcasecmp (RespostaChar, "ENCONTRE A MONTANHA DO SOL")== 0) {
        char Text2Fase1[] = "\n   Você acertou, agora use essa frase para encontrar o Templo de Hórus!\n\n";
        SlowText(Text2Fase1);
        fflush(stdin);
        system("pause");
        system("cls");
        Fase2Cenario2(Vidas);
    } else {
        char Text3Fase1[] = "  Você decifrou o anagrama de forma errada, você segue a pista do seu anagrama, \n porém ele estava incorreto, eventualmente você não encontra o templo e morre de fome e sede\n\n";
        SlowText(Text3Fase1);
        system("pause");
        system("cls");
        Anubis(FaseAtual, Vidas);
    }
}

