#include "../../Menu/Includes.h"

void BossSeth(int Vida, int MusicOn, int argc, char *argv[])    //Boss final
{
    int opcao = 0, CoolDown = 0, Vidas = Vida, o = MusicOn, VidaSeth = 10, VidaArqueologo = 7, Random, RandomSeth, CoolDownOlhosdeAguia;
    system("cls");
    char Texto1[] = "Após ter entrado no templo você se depara com o próprio Deus Hórus, porém ele se encontra com ferimentos de sua última batalha. \nHórus conta a verdade sobre quem lhe guia, logo você descobre que a voz misteriosa era de Seth (Deus do Caos). \nApós ouvir isso Seth se manifesta e contradiz Horús.\n";
    SlowText(Texto1);

    printf("\n    Acreditar em Horús.\n    Acreditar em Seth.");
    opcao = SetaUpDown(4, 1, 2, 1, "->", "  ");

    switch(opcao)
    {
    case 1:
        system("cls");
        char Texto2[] = "Hórus: Rapido mortal, pegue o amuleto e obtenha o poder de um Deus, eu lhe darei o resto do meu poder, derrote Seth e traga a paz.\n\n";
        char Texto3[] = "Você pega o amuleto com o poder de Horús e entra em uma batalha mortal contra Seth\n";
        char Texto4[] = "Você tem três opções de ataques, saiba que o dano dos ataques causados em Seth sera escolhido randomicamente.\n\n";
        SlowText(Texto2);
        Pause(SlowText(Texto3));
        while (VidaArqueologo > 1 || VidaSeth > 1 )
        {
            system("cls");
            if (VidaArqueologo != 7 || VidaSeth != 10){
                printf(Texto4);
            }
            else {
                Pause(SlowText(Texto4));
            }
            printf("\n\n    Lamina de Hórus. \n    Olhos de Águia    \n");
            if (CoolDown <= 0){
                printf(ANSI_COLOR_YELLOW "    Raio Solar" ANSI_COLOR_RESET);
            }
            else {
                printf(ANSI_COLOR_DARK_YELLOW "    Raio Solar" ANSI_COLOR_RESET);
            }
            opcao = SetaUpDown(4, 1, 3, 1, "->", "  ");

            switch(opcao)
            {
            case 1:
                system("cls");
                printf("Vida Seth: %d\n\n", VidaSeth);
                printf("Vida Arqueologo: %d\n\n", VidaArqueologo);
                char Texto5[] = "Você foi na direção de Seth e desferiu um ataque com sua lamina.";
                SlowText(Texto5);
                srand(time(NULL));
                Random = rand()%6;
                RandomSeth = rand()%7 + 1;
                printf("\n\nVocê causou %d de dano a Seth.\n", Random);
                VidaSeth -= Random;
                if (VidaSeth > 0 && VidaArqueologo > 0)
                {
                    printf("\nSeth revidou o ataque e lhe causou %d de dano.\n\n", RandomSeth);
                    VidaArqueologo -= RandomSeth;
                    Pause(" ");

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
                    printf("Vida Seth: %d\n\n", VidaSeth);
                    printf("Vida Arqueologo: %d\n\n", VidaArqueologo);
                    char Texto8[] = "Você usa uma visão ampliada e descobre uma vulnerabilidade em Seth.";
                    SlowText(Texto8);
                    srand(time(NULL));
                    Random = rand()%6 + 2; //Maior probabilidade de dar dano alto
                    RandomSeth = rand()%7 + 1;
                    printf("\n\nVocê causou %d de dano a Seth.\n", Random);
                    VidaSeth -= Random;
                    if (VidaSeth > 0 && VidaArqueologo > 0)
                    {
                        printf("Seth revidou o ataque e lhe causou %d de dano.\n\n", RandomSeth);
                        VidaArqueologo -= RandomSeth;
                        Pause(" ");
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
                    char Texto1[] = "Essa habilidade não pode ser usada novamente.\n\n";
                    Pause(SlowText(Texto1));
                    break;
                }
            case 3:
                system("cls");
                if (CoolDown > 0)
                {
                    Pause("Você não pode usar este poder agora.\n\n");
                }
                else
                {
                    printf("Vida Seth: %d\n\n", VidaSeth);
                    printf("Vida Arqueologo: %d\n\n", VidaArqueologo);
                    char Texto10[] = "Você utiliza o raio solar e deixa Seth cego por alguns segundos, você aproveita e desfere um ataque.";
                    SlowText(Texto10);
                    srand(time(NULL));
                    Random = rand()%6;
                    printf("\n\nVocê causou %d de dano a Seth.\n", Random);
                    VidaSeth -= Random;
                    if (VidaSeth > 0 && VidaArqueologo > 0)
                    {
                        char Texto11[] = "\nSeth ficou cego e nao conseguiu te atacar.\n";
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
                }
                break;
            }
        }
    case 2:
        system("cls");
        char Texto12[] = "Seth: Como pôde ser tão ingênuo mortal, agora com esse poder finalmente poderei conquistar todo o Egito e acabarei com os 7 reinos.\n\n";
        char Texto13[] = "Horús: Como pôde ser tão Idiota ao confiar nele mortal, agora o destino do mundo e o dos 7 reinos estao nas maos de Seth.\n\n";
        char Texto14[] = "Seth aniquilou você e lançou o caos sobre todos os reinos.\n\n";
        SlowText(Texto12);
        SlowText(Texto13);
        Pause(SlowText(Texto14));
        GameOver(o);
    }
}
