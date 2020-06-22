#include "../../Menu/Includes.h"

void EsfingeImage()      // Aparecer a Imagem da Esfinge
{
    printf("\n\t\t......................................................................");
    printf("\n\t\t............................\'\',;;::::;,\'..............................");
    printf("\n\t\t..................'',;::cllooooddodxxxdolllcc::;,''...................");
    printf("\n\t\t...............,coodxxxddxxddddxddxkkxxxxxxxxxxxxdlc:,'...............");
    printf("\n\t\t..........'',,:xOkddxxxxkkxxxxxxodkkkkxkkkOOkkxxxdllol:;,,'''.........");
    printf("\n\t\t.....'',,;;,;cxOkkkxdddxkkOOkkOkddxxkkOO00000Oxddoododdc;;;;;;,''.....");
    printf("\n\t\t..',,;;;;;;;lkOOkkkkxdddxO000OOOxolldkO0KKKK0kxdodddodddl::::;;::;,'..");
    printf("\n\t\t,;;;;;;;;;;lO0OOkkkkxddookOOOkkkkkOOOO000000kxdddxxdddddxl:::::::::::;");
    printf("\n\t\t::;;;;;;;:lk0OOOkOOOkxolldxkxdoodkOOkkxxkOOOkdddxkkxdoodxxoccccccccccc");
    printf("\n\t\t::;;;;:::lkOOOkkOOOOOkdocclol::;;okOko:;:ldxdxxxOkkkkxddxxxocllllccccc");
    printf("\n\t\t:;;;::::lxOOOkkkkkkddxdolcllllccclkOkxdlcloddxkkdodxxxxdxkOxolllllllll");
    printf("\n\t\t:;;:::clx00OkkkkkkdldxdodxxkkOOxlldxkO00Ok0000OxdlodxxddxxkOkoloooooll");
    printf("\n\t\t::::cccdO00Okkkxxxdx0OoclxkOOOOxlcccldk000KK0OkkOkooxxddxkkOOkoloooooo");
    printf("\n\t\t:::cccok00OOxxkxxxocoxo::coxxkkoloxxdodO000OOkxxl:coddxxkkOOOOxooooooo");
    printf("\n\t\t::ccclxOOOOkkxxxxxxdolc:;;cloddlloooddxkOkkkxxdoldxxdxxkkkOOOOkdlooooo");
    printf("\n\t\t:ccllokOOOOOkxxxxkkxkko:;;:coo:,,;;::cloxkxxddxxkxxxxxkkkkOOOOOxoooooo");
    printf("\n\t\tcccllok0000Okkkkkkkkkkxc;,,;cooccclooddkkxdoookOkkkkkkOOOOOOOOOxoloooo");
    printf("\n\t\tcccllldO00000OOkkkkkkkkd;,'';:ldxkOO00OOkoc:cdOOOOOOOO00000000kdlloooo");
    printf("\n\t\tccllooloxO000OOkkkkkkkkxl'...:odkkO00000x;.'ck0OOO0OO0000000Odlllloooo");
    printf("\n\t\tcllooodolox0OOOkkxkxxxxxdc,..:ddkO000K00d,;lxOOOOOOOO00O00Oocccllllooo");
    printf("\n\t\tlllooddddlldkOkkkxxxxxxxxo:;,cdxkO00KK00kodxOOOOOOO00OO00Odlcccclllllo");
    printf("\n\t\tlllooddddxxddkOkkxdddddddl:;;lxxkO000K00kdxkOOOOOOOOOO00OOOOdc:cclllll");
    printf("\n\t\tllloooooodkOkdkOOkxddooool:;:oxxkOO00K00OxkOkOOOOOOOOOOOO00Oxc:cccllll");
    printf("\n\t\tcllooooodxO00kxk0OOkxdollll::oddxkkOOOkO0kkkxkOOOOO0OOOO000Okl:::cccll");
    printf("\n\t\tcllooooodkO000kkO00Oxolllcll;''...''',;;lxkxdkOkkOOOOOO0000Okl:::cccll");
    printf("\n\t\tlloooooodkO000OkkO0Oxollc:coc.      ....ckOxxOkkkkOOOOO000OOko::::cccl");
    printf("\n\t\tllooollodkOO000kkOOOxoccc:cll:.       .ckOkdxOkkkkOOOO00OOOkxo::::cccl");
    printf("\n\t\tlllllllodkO0000OkkOOdlccc::lcc;.     .:kOkkdxOkkkOOOkO0OOkkxxdc::::ccc");
    printf("\n\t\tclllllloxkO00000kxkkdlccc::ccc:'.   .;dkOOxoxOkkkkkxxOOOOkxxxdc::::ccc");
    printf("\n\t\tclllllloxO0000000kddolccc:;:cc:,',codkkOOOxoxOkkxddxOOOOkkkkxdl:::cccc");
    printf("\n\t\tclllllloxO00000000Oxoollcc:llllldkOOOOOOO0kdoodddxkO00OOkkkkxdl::ccccc");
    printf("\n\t\tlllllcldkO00000K0000OOOkkkOOkkkkOOOOOOO0000OOOO000OO000Okkkxddl:::cccc");
}

void BossEsfinge(int Vida, int MusicOn)   // Inicio da luta com a Esfinge //
{
    int opcao = 0, FaseAtual = 4, Vidas = Vida, VidaEsfinge = 500, o = MusicOn;
    system("cls");
    PrintVida(Vidas);
    coordxy(48, 0);
    printf(ANSI_COLOR_RED "Vida da Esfinge\n\t\t\t\t\t|/////////////////////////| %d " ANSI_COLOR_RESET, VidaEsfinge);
    coordxy(0, 2);
    EsfingeImage();
    coordxy(95, 5);
    printf(ANSI_COLOR_CYAN "=== Caixa de dialogo ===================================");
    coordxy(95, 6);
    printf("|                                                      |");
    coordxy(95, 7);
    printf("|                                                      |");
    coordxy(95, 8);
    printf("|                                                      |");
    coordxy(95, 9);
    printf("|                                                      |");
    coordxy(95, 10);
    printf("|                                                      |");
    coordxy(95, 11);
    printf("========================================================");

    coordxy(99, 7);
    printf("Que animal anda pela manhã sobre quatro patas, a");
    coordxy(103, 9);
    printf("tarde sobre duas e a noite sobre três?\n\n");

    coordxy(95, 13);
    printf( "===================");
    coordxy(95, 14);
    printf("|                 |");
    coordxy(95, 15);
    printf("|                 |");
    coordxy(95, 16);
    printf("|                 |");
    coordxy(95, 17);
    printf("===================" ANSI_COLOR_RESET);

    coordxy(100, 14);
    printf(ANSI_COLOR_DARK_CYAN "O Gato");
    coordxy(100, 15);
    printf("O Chachorro");
    coordxy(100, 16);
    printf("O Homem" ANSI_COLOR_RESET);
    opcao = SetaUpDown(14, 97, 3, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

    if (opcao == 3)
    {
        system("cls");
        VidaEsfinge -= 100;
        PrintVida(Vidas);
        coordxy(48, 0);
        printf(ANSI_COLOR_RED "Vida da Esfinge\n\t\t\t\t\t|////////////////////" ANSI_COLOR_DARK_RED "-----" ANSI_COLOR_RED "| %d" ANSI_COLOR_RESET, VidaEsfinge);
        coordxy(0, 2);
        EsfingeImage();
        coordxy(95, 5);
        printf(ANSI_COLOR_CYAN "=== Caixa de dialogo =======");
        coordxy(95, 6);
        printf("|                          |");
        coordxy(95, 7);
        printf("|                          |");
        coordxy(95, 8);
        printf("|                          |");
        coordxy(95, 9);
        printf("============================");
        coordxy(97, 7);
        printf("Por que seria o homem?");

        coordxy(95, 11);
        printf(ANSI_COLOR_CYAN "=====================================================");
        coordxy(95, 12);
        printf("|                                                   |");
        coordxy(95, 13);
        printf("|                                                   |");
        coordxy(95, 14);
        printf("|                                                   |");
        coordxy(95, 15);
        printf("|                                                   |");
        coordxy(95, 16);
        printf("=====================================================" ANSI_COLOR_RESET);

        coordxy(100, 12);
        printf(ANSI_COLOR_DARK_CYAN "Porque o homem é um bípede");
        coordxy(100, 13);
        printf("Porque o homem não quer mais viver uma mentira");
        coordxy(100, 14);
        printf("Porque na infância o homem engatinha");
        coordxy(100, 15);
        printf("Porque na infância o homem pensa muito" ANSI_COLOR_RESET);
        opcao = SetaUpDown(12, 97, 4, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

        if (opcao == 3)
        {
            system("cls");
            VidaEsfinge -= 100;
            PrintVida(Vidas);
            coordxy(48, 0);
            printf(ANSI_COLOR_RED "Vida da Esfinge\n\t\t\t\t\t|///////////////" ANSI_COLOR_DARK_RED "----------" ANSI_COLOR_RED "| %d" ANSI_COLOR_RESET, VidaEsfinge);
            coordxy(0, 2);
            EsfingeImage();

            coordxy(95, 5);
            printf(ANSI_COLOR_CYAN "=== Caixa de dialogo =======");
            coordxy(95, 6);
            printf("|                          |");
            coordxy(95, 7);
            printf("|                          |");
            coordxy(95, 8);
            printf("|                          |");
            coordxy(95, 9);
            printf("============================");
            coordxy(97, 7);
            printf("E o que mais? \n\n");

            coordxy(95, 11);
            printf(ANSI_COLOR_CYAN "=======================================================================");
            coordxy(95, 12);
            printf("|                                                                     |");
            coordxy(95, 13);
            printf("|                                                                     |");
            coordxy(95, 14);
            printf("|                                                                     |");
            coordxy(95, 15);
            printf("|                                                                     |");
            coordxy(95, 16);
            printf("=======================================================================" ANSI_COLOR_RESET);

            coordxy(100, 12);
            printf(ANSI_COLOR_DARK_CYAN "Na idade adulta ele anda ereto");
            coordxy(100, 13);
            printf("Essa é toda a resposta");
            coordxy(100, 14);
            printf("Não tenho tempo para essas questões filosóficas, me deixe passar");
            coordxy(100, 15);
            printf("Não idade adulta ele pensa muito, e pensar nos faz andar" ANSI_COLOR_RESET);
            opcao = SetaUpDown(12, 97, 4, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

            if (opcao == 1)
            {
                system("cls");
                VidaEsfinge -= 100;
                PrintVida(Vidas);
                coordxy(48, 0);
                printf(ANSI_COLOR_RED "Vida da Esfinge\n\t\t\t\t\t|//////////" ANSI_COLOR_DARK_RED "---------------" ANSI_COLOR_RED "| %d" ANSI_COLOR_RESET, VidaEsfinge);
                coordxy(0, 2);
                EsfingeImage();

                coordxy(95, 5);
                printf(ANSI_COLOR_CYAN "=== Caixa de dialogo =======");
                coordxy(95, 6);
                printf("|                          |");
                coordxy(95, 7);
                printf("|                          |");
                coordxy(95, 8);
                printf("|                          |");
                coordxy(95, 9);
                printf("============================");
                coordxy(97, 7);
                printf("Mais alguma coisa?");


                coordxy(95, 11);
                printf(ANSI_COLOR_CYAN "=======================================================================");
                coordxy(95, 12);
                printf("|                                                                     |");
                coordxy(95, 13);
                printf("|                                                                     |");
                coordxy(95, 14);
                printf("=======================================================================" ANSI_COLOR_RESET);

                coordxy(100, 12);
                printf(ANSI_COLOR_DARK_CYAN  "Sim, na velhice o homem necessita de uma bengala para andar");
                coordxy(100, 13);
                printf("Não, é apenas essa a resposta" ANSI_COLOR_RESET);
                opcao = SetaUpDown(12, 97, 4, 1, ANSI_COLOR_DARK_RED "->" ANSI_COLOR_RESET, "  ");

                if (opcao == 1)
                {
                    system("cls");
                    VidaEsfinge = 0;
                    PrintVida(Vidas);
                    coordxy(48, 0);
                    printf(ANSI_COLOR_RED "Vida da Esfinge\n\t\t\t\t\t" ANSI_COLOR_DARK_RED "|-------------------------| %d" ANSI_COLOR_DARK_GRAY, VidaEsfinge);
                    coordxy(0, 2);
                    EsfingeImage();
                    coordxy(95, 5);
                    printf(ANSI_COLOR_CYAN "=== Caixa de dialogo ===================================");
                    coordxy(95, 6);
                    printf("|                                                      |");
                    coordxy(95, 7);
                    printf("|                                                      |");
                    coordxy(95, 8);
                    printf("|                                                      |");
                    coordxy(95, 9);
                    printf("========================================================");
                    coordxy(100, 7);
                    Pause("Você me venceu, como conseguiu?");
                    cenario(Vidas, o);
                }
                else
                {
                    Anubis(FaseAtual, Vidas, o);
                }
            }
            else
            {
                Anubis(FaseAtual, Vidas, o);
            }
        }
        else
        {
            Anubis(FaseAtual, Vidas, o);
        }
    }
    else
    {
        Anubis(FaseAtual, Vidas, o);
    }
}

void cenario(int Vida, int MusicOn)
{
    int Vidas = Vida, o = MusicOn;
    system("cls");
    PrintVida(Vidas);
    char Texto1[] = "Depois de passar pela esfinge você chega a última sala da pirâmide. Nota-se que a sala";
    char Texto2[] = "está vazia, você acha isso estranho, será que todo esse sacrifício foi feito em vão?";
    char Texto3[] = "de repente você escuta uma voz sussurrante dizendo: “O que você procura não está aqui,";
    char Texto4[] = "mas posso te dizer como encontrar, siga meus conselhos, você não tem muito tempo”.";
    char Texto5[] = "Sem entender o que estava acontecendo você segue o caminho da voz.";

    coordxy(28, 5);
    printf(ANSI_COLOR_CYAN "=== Caixa de dialogo ======================================================================");
    coordxy(28, 6);
    printf("|                                                                                         |");
    coordxy(28, 7);
    printf("|                                                                                         |");
    coordxy(28, 8);
    printf("|                                                                                         |");
    coordxy(28, 9);
    printf("|                                                                                         |");
    coordxy(28, 10);
    printf("|                                                                                         |");
    coordxy(28, 11);
    printf("|                                                                                         |");
    coordxy(28, 12);
    printf("|                                                                                         |");
    coordxy(28, 13);
    printf("|                                                                                         |");
    coordxy(28, 14);
    printf("|                                                                                         |");
    coordxy(28, 15);
    printf("|                                                                                         |");
    coordxy(28, 16);
    printf("|                                                                                         |");
    coordxy(28, 17);
    printf("===========================================================================================");

    coordxy(31, 7);
    SlowText(Texto1);
    coordxy(30, 9);
    SlowText(Texto2);
    coordxy(30, 11);
    SlowText(Texto3);
    coordxy(30, 13);
    SlowText(Texto4);
    coordxy(30, 15);
    Pause(SlowText(Texto5));
    Fase1Cenario2(Vidas, o);
}
