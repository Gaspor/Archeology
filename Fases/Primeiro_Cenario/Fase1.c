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
    char Texto1[] = "  Voc� se depara com uma porta com �pe�as� faltando, olha para o lado e observa que h�: 3 pe�as com s�mbolos de An�bis, 3 pe�as \n\n com s�mbolos de H�rus, e 4 pe�as com s�mbolos de Seth.\n\n";
    char Texto2[] = "  Enquanto olha para as pe�as voc� ouve algo, quando olha para a porta se depara com a seguinte frase sendo constru�da: Me diga \n\n quantas combina��es pode-se fazer com as pe�as e liberarei a sua passagem\n\n";
    char Texto3[] = "  Quantas combina��es podem ser feitas? ";

    SlowText(Texto1);
    SlowText(Texto2);
    SlowText(Texto3);
    scanf("%d", &Resposta);
    if (Resposta == 36)
    {
        char Texto4[] = "\n\n  Voc� acertou o n�mero de combina��es\n";
        SlowText(Texto4);
        Sleep(3000);
        system("cls");
        Fase2(Vidas, o);
    }
    else
    {
        printf("\n\n  Voc� errou e ativou uma armadilha, toda pir�mide tremia, voc� provocou um deslizamento e foi esmagado por uma rocha.\n\n");
        system("pause");
        system("cls");
        Anubis(FaseAtual, Vidas, o);
    }


}
