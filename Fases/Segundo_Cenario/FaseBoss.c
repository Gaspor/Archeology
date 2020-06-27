#include "../../Menu/Includes.h"

void BossSeth(int Vida, int MusicOn, int argc, char *argv[])    //Boss final
{
    int opcao = 0, CoolDown = 0, Vidas = Vida, o = MusicOn, VidaSeth = 10, VidaArqueologo = 700, Random = 0, RandomSeth = 0, CoolDownOlhosdeAguia = 0, i = 0;

    if (o == 0)
        PlaySound(TEXT("null.wav"), NULL, SND_ASYNC);
    else
        PlaySound(TEXT("Boss.wav"), NULL, SND_ASYNC|SND_LOOP);

    system("cls");
    char Texto1[] = ANSI_COLOR_DARK_CYAN "Ap�s ter entrado no templo voc� se depara com o pr�prio Deus H�rus, por�m ele se encontra com ferimentos de sua �ltima batalha.";
    char Texto2[] = "H�rus conta a verdade sobre quem lhe guia, logo voc� descobre que a voz misteriosa era de Seth (Deus do Caos).";
    char Texto3[] = "Ap�s ouvir isso Seth se manifesta e contradiz Hor�s." ANSI_COLOR_RESET;

    coordxy(2, 0);
    printf(ANSI_COLOR_CYAN "=== Caixa de Di�logo ===============================================================================================================\n  |                                                                                                                                  |\n  |                                                                                                                                  |\n  |                                                                                                                                  |\n  |                                                                                                                                  |\n  |                                                                                                                                  |\n  |                                                                                                                                  |\n  |                                                                                                                                  |\n  ====================================================================================================================================" ANSI_COLOR_RESET);
    coordxy(5, 2);
    SlowText(Texto1);
    coordxy(5, 4);
    SlowText(Texto2);
    coordxy(5, 6);
    SlowText(Texto3);

    coordxy(2, 11);
    printf(ANSI_COLOR_CYAN "========================");
    coordxy(2, 12);
    printf("|                      |");
    coordxy(2, 13);
    printf("|                      |");
    coordxy(2, 14);
    printf("|                      |");
    coordxy(2, 15);
    printf("========================" ANSI_COLOR_RESET);
    coordxy(6, 12);
    printf(ANSI_COLOR_DARK_CYAN "Acreditar em Hor�s");
    coordxy(6, 14);
    printf("Acreditar em Seth" ANSI_COLOR_RESET);
    opcao = SetaUpDown(12, 3, 2, 2, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

    switch(opcao)
    {
    case 1:
        system("cls");
        char Texto2[] = ANSI_COLOR_DARK_CYAN "H�rus: Rapido mortal, pegue o amuleto e obtenha o poder de um Deus, eu lhe darei o resto do meu poder, derrote Seth e traga a paz.";
        char Texto3[] = "Voc� pega o amuleto com o poder de Hor�s e entra em uma batalha mortal contra Seth.";
        char Texto4[] = ANSI_COLOR_DARK_CYAN "Voc� tem tr�s op��es de ataques, saiba que o dano dos ataques causados em Seth ser� escolhido randomicamente." ANSI_COLOR_RESET;
        coordxy(2, 0);
        printf(ANSI_COLOR_CYAN "=== Caixa de Di�logo ==================================================================================================================\n  |                                                                                                                                     |\n  |                                                                                                                                     |\n  |                                                                                                                                     |\n  |                                                                                                                                     |\n  |                                                                                                                                     |\n  =======================================================================================================================================" ANSI_COLOR_RESET);
        coordxy(4, 2);
        SlowText(Texto2);
        coordxy(4, 4);
        Pause(SlowText(Texto3));
        while (VidaArqueologo > 1 || VidaSeth > 1 )
        {
            system("cls");
            if (VidaArqueologo != 7 || VidaSeth != 10)
            {
                coordxy(2, 0);
                printf(ANSI_COLOR_CYAN "=== Caixa de Di�logo ============================================================================================\n  |                                                                                                               |\n  |                                                                                                               |\n  |                                                                                                               |\n  =================================================================================================================" ANSI_COLOR_RESET);
                coordxy(4, 2);
                printf(Texto4);
            }
            else
            {
                coordxy(2, 0);
                printf(ANSI_COLOR_CYAN "=== Caixa de Di�logo ============================================================================================\n  |                                                                                                               |\n  |                                                                                                               |\n  |                                                                                                               |\n  =================================================================================================================" ANSI_COLOR_RESET);
                coordxy(4, 2);
                Pause(SlowText(Texto4));
            }
            coordxy(2, 6);
            printf(ANSI_COLOR_CYAN "=====================");
            coordxy(2, 7);
            printf("|                   |");
            coordxy(2, 8);
            printf("|                   |");
            coordxy(2, 9);
            printf("|                   |");
            coordxy(2, 10);
            printf("|                   |");
            coordxy(2, 11);
            printf("|                   |");
            coordxy(2, 12);
            printf("=====================" ANSI_COLOR_RESET);
            coordxy(6, 7);
            printf("Lamina de H�rus");
            coordxy(6, 9);
            if (CoolDownOlhosdeAguia == 0)
            {
                printf(ANSI_COLOR_RED "Olhos de �guia" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_DARK_RED "Olhos de �guia" ANSI_COLOR_RESET);
            }
            coordxy(6, 11);
            if (CoolDown <= 0)
            {
                printf(ANSI_COLOR_YELLOW "Raio Solar" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_DARK_YELLOW "Raio Solar" ANSI_COLOR_RESET);
            }
            opcao = SetaUpDown(7, 3, 3, 2, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

            switch(opcao)
            {
            case 1:
                system("cls");
                coordxy(53, 10);
                printf(ANSI_COLOR_CYAN "=== Log de Batalha =================================================");
                for (i = 0; i < 11; i++)
                {
                    coordxy(53, 11 + i);
                    printf("|                                                                  |");
                }
                coordxy(53, 22);
                printf("====================================================================" ANSI_COLOR_RESET);
                coordxy(55, 12);
                printf(ANSI_COLOR_DARK_CYAN "Vida Seth: %d", VidaSeth);
                coordxy(55, 14);
                printf("Vida Arqueologo: %d", VidaArqueologo);
                char Texto5[] = "Voc� foi na dire��o de Seth e desferiu um ataque com sua l�mina.";
                coordxy(55, 16);
                SlowText(Texto5);
                Random = DanoPlayer(0);
                coordxy(55, 18);
                VidaSeth -= Random;
                printf("Voc� causou %d de dano a Seth." ANSI_COLOR_RESET, Random);

                if (VidaSeth > 0 && VidaArqueologo > 0)
                {
                    RandomSeth = DanoSeth();
                    coordxy(55, 20);
                    printf(ANSI_COLOR_DARK_CYAN "Seth revidou o ataque e lhe causou %d de dano." ANSI_COLOR_RESET, RandomSeth);
                    Pause(" ");
                    VidaArqueologo -= RandomSeth;
                }
                if (VidaSeth <= 0 && VidaArqueologo > 0)
                {
                    Vencedor(o);
                }
                if (VidaArqueologo < 1)
                {
                    Perdedor(Vidas, o, VidaSeth);
                }
                CoolDown--;
                break;
            case 2:
                system("cls");

                if (CoolDownOlhosdeAguia != 1)
                {
                    coordxy(53, 10);
                    printf(ANSI_COLOR_CYAN "=== Log de Batalha ====================================================");
                    for (i = 0; i < 11; i++)
                    {
                        coordxy(53, 11 + i);
                        printf("|                                                                     |");
                    }
                    coordxy(53, 22);
                    printf("=======================================================================" ANSI_COLOR_RESET );
                    coordxy(55, 12);
                    printf(ANSI_COLOR_DARK_CYAN "Vida Seth: %d", VidaSeth);
                    coordxy(55, 14);
                    printf("Vida Arqueologo: %d", VidaArqueologo);
                    char Texto8[] = "Voc� usa uma vis�o ampliada e descobre uma vulnerabilidade em Seth.";
                    coordxy(55, 16);
                    SlowText(Texto8);
                    Random = DanoPlayer(3);
                    VidaSeth -= Random;
                    coordxy(55, 18);
                    printf("Voc� causou %d de dano a Seth." ANSI_COLOR_RESET, Random);
                    if (VidaSeth > 0 && VidaArqueologo > 0)
                    {
                        RandomSeth = DanoSeth();
                        coordxy(55, 20);
                        printf(ANSI_COLOR_DARK_CYAN "Seth revidou o ataque e lhe causou %d de dano." ANSI_COLOR_RESET, RandomSeth);
                        Pause(" ");
                        VidaArqueologo -= RandomSeth;
                    }
                    if(VidaSeth <= 0 && VidaArqueologo > 0)
                    {
                        Vencedor(o);
                    }
                    if(VidaArqueologo < 1)
                    {
                        Perdedor(Vidas, o, VidaSeth);
                    }
                    CoolDownOlhosdeAguia = 1;
                    CoolDown--;
                    break;
                }
                else
                {
                    char Texto1[] = ANSI_COLOR_RED "Essa habilidade n�o pode ser usada novamente." ANSI_COLOR_RESET;
                    coordxy(2, 0);
                    printf(ANSI_COLOR_CYAN "=== Caixa de Di�logo ============================\n  |                                               |\n  |                                               |\n  |                                               |\n  =================================================" ANSI_COLOR_RESET);
                    coordxy(4, 2);
                    Pause(SlowText(Texto1));
                    break;
                }
            case 3:
                system("cls");
                if (CoolDown > 0)
                {
                    coordxy(2, 0);
                    printf(ANSI_COLOR_CYAN "=== Caixa de Di�logo ===================\n  |                                      |\n  |                                      |\n  |                                      |\n  ========================================" ANSI_COLOR_RESET);
                    coordxy(4, 2);
                    Pause(ANSI_COLOR_RED "Voc� n�o pode usar este poder agora." ANSI_COLOR_RESET);
                }
                else
                {
                    coordxy(53, 10);
                    printf(ANSI_COLOR_CYAN "=== Log de Batalha =================================================");
                    for (i = 0; i < 13; i++)
                    {
                        coordxy(53, 11 + i);
                        printf("|                                                                  |");
                    }
                    coordxy(53, 24);
                    printf("====================================================================" ANSI_COLOR_RESET);
                    coordxy(55, 12);
                    printf(ANSI_COLOR_DARK_CYAN "Vida Seth: %d", VidaSeth);
                    coordxy(55, 14);
                    printf("Vida Arqueologo: %d", VidaArqueologo);
                    char Texto10[] = "Voc� utiliza o raio solar e deixa Seth cego por alguns segundos,";
                    char TextoA[] = "voc� aproveita e desfere um ataque.";
                    coordxy(55, 16);
                    SlowText(Texto10);
                    coordxy(55, 18);
                    SlowText(TextoA);
                    Random = DanoPlayer(1);
                    VidaSeth -= Random;
                    coordxy(55, 20);
                    printf("Voc� causou %d de dano a Seth.", Random);
                    if (VidaSeth > 0 && VidaArqueologo > 0)
                    {
                        coordxy(55, 22);
                        char Texto11[] = ANSI_COLOR_CYAN "Seth ficou cego e nao conseguiu te atacar." ANSI_COLOR_RESET;
                        Pause(SlowText(Texto11));
                    }
                    if (VidaSeth <= 0 && VidaArqueologo > 0)
                    {
                        Vencedor(o);
                    }
                    if(VidaArqueologo < 1)
                    {
                        Perdedor(Vidas, o, VidaSeth);
                    }
                    CoolDown = 2;
                    break;
                }
                break;
            }
        }
    case 2:
        system("cls");
        char Texto12[] = ANSI_COLOR_DARK_CYAN "Seth: Como p�de ser t�o ing�nuo mortal, agora com esse poder finalmente poderei conquistar todo o Egito e acabarei com os 7 reinos.";
        char Texto13[] = "Hor�s: Como p�de ser t�o idiota ao confiar nele mortal, agora o destino do mundo e o dos 7 reinos est�o nas maos de Seth.";
        char Texto14[] = ANSI_COLOR_RED "Seth aniquilou voc� e lan�ou o caos sobre todos os reinos." ANSI_COLOR_RESET;

        coordxy(2, 0);
        printf(ANSI_COLOR_CYAN "=== Caixa de Di�logo ==================================================================================================================\n  |                                                                                                                                     |\n  |                                                                                                                                     |\n  |                                                                                                                                     |\n  |                                                                                                                                     |\n  |                                                                                                                                     |\n  |                                                                                                                                     |\n  |                                                                                                                                     |\n  =======================================================================================================================================" ANSI_COLOR_RESET);
        coordxy(4, 2);
        SlowText(Texto12);
        coordxy(4, 4);
        SlowText(Texto13);
        coordxy(4, 6);
        Pause(SlowText(Texto14));
        coordxy(4, 8);
        GameOver(o);
    }
}

int DanoPlayer(int Soma)
{
    int Dano = 0;

    srand(time(NULL));
    Dano = rand()%6 + Soma;

    return Dano;
}

int DanoSeth()
{
    int Dano = 0;

    srand(time(NULL));
    Dano = rand()%7+1;

    return Dano;
}
