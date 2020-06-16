#include "../../Includes.h"

void Fase1(int Vida, int MusicOn)
{
    int Resposta, FaseAtual = 1, o = MusicOn, Vidas = Vida;
    system("cls");

    if (o == 0)
        PlaySound(TEXT("null.wav"), NULL, SND_ASYNC);
    else
        PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);

    printf("Vidas: %d \n", Vidas);
    char Texto1[] = "  Você se depara com uma porta com “peças” faltando, olha para o lado e observa que há: 3 peças com símbolos de Anúbis, 3 peças \n\n com símbolos de Hórus, e 4 peças com símbolos de Seth.\n\n";
    char Texto2[] = "  Enquanto olha para as peças você ouve algo, quando olha para a porta se depara com a seguinte frase sendo construída: Me diga \n\n quantas combinações pode-se fazer com as peças e liberarei a sua passagem\n\n";
    char Texto3[] = "  Quantas combinações podem ser feitas? ";

    SlowText(Texto1);
    SlowText(Texto2);
    SlowText(Texto3);
    scanf("%d", &Resposta);
    if (Resposta == 36)
    {
        char Texto4[] = "\n\n  Você acertou o número de combinações\n";
        SlowText(Texto4);
        Sleep(3000);
        system("cls");
        Fase2(Vidas, o);
    }
    else
    {
        printf("\n\n  Você errou e ativou uma armadilha, toda pirâmide tremia, você provocou um deslizamento e foi esmagado por uma rocha.\n\n");
        system("pause");
        system("cls");
        Anubis(FaseAtual, Vidas, o);
    }


}
