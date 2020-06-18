#include "Includes.h"

// Globais //
char Password[20];
int KeyPress,b,L,opcao;

// Setas //
void coordxy(int x,int y)
{
    COORD Mouse;
    Mouse.X = x;
    Mouse.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Mouse);
}

void SetaUpDown (int La,int coordx,int BLimite,int LOper,char *SetaModel,char *SetaModelSpace)     // Seta pra cima e pra baixo //
{
    opcao = 0;
    L=La, b=1;
    do
    {
        coordxy(coordx, L);
        printf(SetaModel);
        coordxy(0,20);
        if(kbhit)
        {
            KeyPress=getch();
        }
        if(KeyPress == 80 && b < BLimite)
        {
            coordxy(coordx, L);
            printf(SetaModelSpace);
            L+=LOper;
            b++;
        }
        if(KeyPress == 72 && b > 1)
        {
            coordxy(coordx, L);
            printf(SetaModelSpace);
            L-=LOper;
            b--;
        }
        if (KeyPress == 27)
        {
            Quit();
        }
        if(KeyPress == 13)
        {
            opcao=b;
        }
    }
    while(opcao == 0);
}

void SetaLeftRight (int La,int coordy,int BLimite,int LOper,char *SetaModel,char *SetaModelSpace)     // Seta pra direita e pra esquerda //
{
    opcao = 0;
    L=La, b=1;
    do
    {
        coordxy(L, coordy);
        printf(SetaModel);
        coordxy(0,20);
        if(kbhit)
        {
            KeyPress=getch();
        }
        if (KeyPress == 77 && b < BLimite)
        {
            coordxy(L, coordy);
            printf(SetaModelSpace);
            L+=LOper;
            b++;
        }
        if (KeyPress == 75 && b > 1)
        {
            coordxy(L, coordy);
            printf(SetaModelSpace);
            L-=LOper;
            b--;
        }
        if (KeyPress == 27)
        {
            Quit();
        }
        if(KeyPress == 13)
        {
            opcao=b;
        }
    }
    while(opcao == 0);
}

// Efeito Texto em Slow //
char SlowText(char *Text)
{
    int i, TimeText = 1;
    for (i = 0; Text[i] != '\0'; i++)
    {
        printf("%c",Text[i]);
        Sleep(TimeText);
    }
}

void Menu(int MusicOn)
{
    Fase2Cenario2(1, 0);
    Pause("Batata");
    BossSeth(0);
    int Vidas = 1, o = MusicOn;

    if (o == 0)
        PlaySound(TEXT("null.wav"), NULL, SND_ASYNC);
    else
        PlaySound(TEXT("menu.wav"), NULL, SND_ASYNC|SND_LOOP);

    system("cls");
    printf("     \"Menu de opções\"\n\n      Novo Jogo \n      Escolher Fase\n      GitHub\n      Opções\n      Sair \n");
    printf("\nPor Favor, deixe o jogo em tela cheia");
    SetaUpDown(2, 3, 5, 1, "->", "  ");

    switch (opcao)
    {
    case 1:
        system("cls");
        Player(Vidas, o);
    case 2:
        system("cls");
        printf("  Este é o menu do desenvolvedor, por favor digite sua senha: ");
        gets(Password);
        if (strcmp (Password, "1234")== 0)
        {
            printf("  Verificando...\n");
            Sleep(1000);
            printf("  Você será direcionado para o menu de escolha de fase, por favor aguarde.");
            Sleep(2000);
            system("cls");
            SelectFase(Vidas);
        }
        else
        {
            printf("  Verificando...\n");
            Sleep(1000);
            printf("  Senha incorreta.");
            Sleep(700);
            system("cls");
            Menu(o);
        }
    case 3:
        system("cls");
        printf("  Você está sendo direcionado ao nosso projeto no GitHub...");
        Sleep(2000);
        system("start https://github.com/Gaspor/Archeology");
        Sleep(2000);
        Menu(o);
    case 4:
        Audio(o);

    case 5:
        Quit();

    default:
        printf("  Essa opção não existe, por favor tente uma nova.\n");
        Sleep(1500);
    }
}

void Audio(int MusicOn)              // controle de audio
{
    int o = MusicOn;
    system("cls");
    printf(" == Som == \n\n    Off \n    On");
    SetaUpDown(2, 1, 2, 1, "->", "  ");

    switch (opcao)
    {
    case 1:
        system("cls");
        printf("Som retirado com sucesso...");
        Sleep(3000);
        o--;
        Menu(o);

    case 2:
        system("cls");
        printf("Retornando ao menu...");
        Sleep(3000);
        o = 1;
        Menu(o);
    }
}


void SelectFase(int Vida, int MusicOn)    // Função para desenvolvedores para selecionar Fase //
{
    int Vidas = Vida, o = MusicOn;
    system("cls");
    printf("     \"Menu de Fases\"\n\n      Ir para a Fase 1\n      Ir para a Fase 2\n      Ir para a Fase 3\n      Ir para o Boss Esfinge\n      Ir para a Fase 1 (Segundo Cenário)\n      Ir para a Fase 2 (Segundo Cenário)\n      Ir para a Fase 3 (Segundo Cenário)\n      Ir para o Boss   (Segundo Cenário)\n\n      Voltar ao Menu principal\n");
    SetaUpDown(2, 3, 10, 1, "->", "  ");

    switch (opcao)
    {
    case 1:
        system("cls");
        printf("   Você escolheu ir para a Fase 1.\n");
        Sleep(1000);
        printf("   Iniciando a Fase 1...\n");
        Sleep(1500);
        system("cls");
        Fase1(Vidas, o);
    case 2:
        system("cls");
        printf("   Você escolheu ir para a Fase 2.\n");
        Sleep(1000);
        printf("   Iniciando a Fase 2...\n");
        Sleep(1500);
        system("cls");
        //PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
        Fase2(Vidas, o);
    case 3:
        system("cls");
        printf("   Você escolheu ir para a Fase 3.\n");
        Sleep(1000);
        printf("   Iniciando a Fase 3...\n");
        Sleep(1500);
        system("cls");
        //PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
        Fase3(Vidas, o);
    case 4:
        system("cls");
        printf("   Você escolheu ir para a Fase do Boss.\n");
        Sleep(1000);
        printf("   Iniciando o Boss...\n");
        Sleep(1500);
        system("cls");
        BossEsfinge(Vidas, o);
    case 5:
        system("cls");
        printf("   Você escolheu ir para a Fase 1 do Segundo cenário.\n");
        Sleep(1000);
        printf("   Iniciando a Fase 1 (Segundo cenário)...\n");
        Sleep(1500);
        system("cls");
        //PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
        Fase1Cenario2(Vidas, o);
    case 6:
        system("cls");
        printf("   Você escolheu ir para a Fase 2 do Segundo cenário.\n");
        Sleep(1000);
        printf("   Iniciando a Fase 2 (Segundo cenário)...\n");
        Sleep(1500);
        system("cls");
        //PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
        Fase2Cenario2(Vidas, o);
    case 7:
        system("cls");
        printf("   Você escolheu ir para a Fase 3 do Segundo cenário.\n");
        Sleep(1000);
        printf("   Iniciando a Fase 3 (Segundo cenário)...\n");
        system("pause");
        system("cls");
        Fase3Cenario2(Vidas, o);
    case 8:
        system("cls");
        printf("   Você escolheu ir para a Fase do Boss do Segundo cenário.\n");
        Sleep(1000);
        printf("   Iniciando a Fase Boss Seth...\n");
        system("pause");
        system("cls");
        BossSeth(Vidas, o);
    case 10:
        Menu(o);
    default:
        printf("  Opção inválida, tente outra");
        Sleep(1000);
        SelectFase(Vidas, o);
    }
}

void Fase2(int Vida, int MusicOn)
{
    system("cls");
    int FaseAtual = 2, Acertos = 0, Vidas = Vida, o = MusicOn;
    coordxy(0, 0);
    printf("Vidas: %d \n", Vidas);
    char Text1[] = "  Você se depara com uma entrada, anda até ela e quando está chegando, o chão começa a tremer. De repente\nvocê percebe que alguns pisos não tremem e eles serão o seu caminho até a entrada.\n";
    SlowText(Text1);
Acerto:
    fflush(stdin);
    coordxy(2,3);
    printf("Passos: ");
    if (Acertos == 0)
    {
        coordxy(2,4);
        printf("%d Vá ao maxímo para esquerda.              ", Acertos);
        coordxy(49,7);
        printf("== Primeiro Piso == \n");
    }
    if (Acertos == 1)
    {
        coordxy(2,4);
        printf("%d Quadruplique!!              ", Acertos);
        coordxy(49,7);
        printf("== Segundo Piso == \n");
    }
    if (Acertos == 2)
    {
        coordxy(2,4);
        printf("%d Divida por dois.              ", Acertos);
        coordxy(49,7);
        printf("== Terceiro Piso == \n");
    }
    if (Acertos == 3)
    {
        coordxy(2,4);
        printf("%d Adicione um.              ", Acertos);
        coordxy(49,7);
        printf("== Quarto Piso ==       \n");
    }
    coordxy(19,7);
    printf("\n\t\t\t\t\t====================================\n\t\t\t\t\t|  1         2         3         4 |\n\t\t\t\t\t|        Posição do jogador        |\n\t\t\t\t\t====================================\n");
    SetaLeftRight(41, 9, 4, 10, ">", " ");

    switch (opcao)
    {
    case 1:
        if (Acertos == 0)
        {
            char Acerto1[] ="   Você acertou e passou para o próximo piso           \n";
            Acertos++;
            SlowText(Acerto1);
            goto Acerto;
        }
        else
        {
            ErrorFase2(Vidas, o);
        }
    case 2:
        if (Acertos == 2)
        {
            char Acerto3[] = "   Você acertou, por pouco!                            \n";
            Acertos++;
            SlowText(Acerto3);
            goto Acerto;
        }
        else
        {
            ErrorFase2(Vidas, o);
        }
    case 3:
        if (Acertos == 3)
        {
            char Acerto4[] = "   Você finalmente passou sem cair em nenhuma armadilha\n";
            SlowText(Acerto4);
            Sleep(3000);
            system("cls");
            Fase3(Vidas, o);
        }
        else
        {
            ErrorFase2(Vidas, o);
        }
    case 4:
        if (Acertos == 1)
        {
            char Acerto2[] = "   Você acertou, tome cuidado com os pisos falsos      \n";
            Acertos++;
            SlowText(Acerto2);
            goto Acerto;
        }
        else
        {
            ErrorFase2(Vidas, o);
        }
    }
}

void ErrorFase2(int Vida, int MusicOn)     // Função que é chamada quando o usuário erra o piso da Fase 2  //
{
    int FaseAtual = 2, Vidas = Vida, o = MusicOn;
    char ErroPiso[] ="   Você pisou em um lugar que não era seguro, o chão desmoronou, e você morreu com a queda.\n";
    SlowText(ErroPiso);
    Sleep(2000);
    Anubis(FaseAtual, Vidas, o);
}

// Comandos da Esfinge //
void EsfingeImage()      // Aparecer a Imagem da Esfinge
{
    printf("\n\t\t......................................................................\n\t\t............................'',;;::::;,'..............................\n\t\t..................'',;::cllooooddodxxxdolllcc::;,''...................\n\t\t...............,coodxxxddxxddddxddxkkxxxxxxxxxxxxdlc:,'...............\n\t\t..........'',,:xOkddxxxxkkxxxxxxodkkkkxkkkOOkkxxxdllol:;,,'''.........\n\t\t.....'',,;;,;cxOkkkxdddxkkOOkkOkddxxkkOO00000Oxddoododdc;;;;;;,''.....\n\t\t..',,;;;;;;;lkOOkkkkxdddxO000OOOxolldkO0KKKK0kxdodddodddl::::;;::;,'..\n\t\t,;;;;;;;;;;lO0OOkkkkxddookOOOkkkkkOOOO000000kxdddxxdddddxl:::::::::::;\n\t\t::;;;;;;;:lk0OOOkOOOkxolldxkxdoodkOOkkxxkOOOkdddxkkxdoodxxoccccccccccc\n\t\t::;;;;:::lkOOOkkOOOOOkdocclol::;;okOko:;:ldxdxxxOkkkkxddxxxocllllccccc\n\t\t:;;;::::lxOOOkkkkkkddxdolcllllccclkOkxdlcloddxkkdodxxxxdxkOxolllllllll\n\t\t:;;:::clx00OkkkkkkdldxdodxxkkOOxlldxkO00Ok0000OxdlodxxddxxkOkoloooooll\n\t\t::::cccdO00Okkkxxxdx0OoclxkOOOOxlcccldk000KK0OkkOkooxxddxkkOOkoloooooo\n\t\t:::cccok00OOxxkxxxocoxo::coxxkkoloxxdodO000OOkxxl:coddxxkkOOOOxooooooo\n\t\t::ccclxOOOOkkxxxxxxdolc:;;cloddlloooddxkOkkkxxdoldxxdxxkkkOOOOkdlooooo\n\t\t:ccllokOOOOOkxxxxkkxkko:;;:coo:,,;;::cloxkxxddxxkxxxxxkkkkOOOOOxoooooo\n\t\tcccllok0000Okkkkkkkkkkxc;,,;cooccclooddkkxdoookOkkkkkkOOOOOOOOOxoloooo\n\t\tcccllldO00000OOkkkkkkkkd;,'';:ldxkOO00OOkoc:cdOOOOOOOO00000000kdlloooo\n\t\tccllooloxO000OOkkkkkkkkxl'...:odkkO00000x;.'ck0OOO0OO0000000Odlllloooo\n\t\tcllooodolox0OOOkkxkxxxxxdc,..:ddkO000K00d,;lxOOOOOOOO00O00Oocccllllooo\n\t\tlllooddddlldkOkkkxxxxxxxxo:;,cdxkO00KK00kodxOOOOOOO00OO00Odlcccclllllo\n\t\tlllooddddxxddkOkkxdddddddl:;;lxxkO000K00kdxkOOOOOOOOOO00OOOOdc:cclllll\n\t\tllloooooodkOkdkOOkxddooool:;:oxxkOO00K00OxkOkOOOOOOOOOOOO00Oxc:cccllll\n\t\tcllooooodxO00kxk0OOkxdollll::oddxkkOOOkO0kkkxkOOOOO0OOOO000Okl:::cccll\n\t\tcllooooodkO000kkO00Oxolllcll;''...''',;;lxkxdkOkkOOOOOO0000Okl:::cccll\n\t\tlloooooodkO000OkkO0Oxollc:coc.      ....ckOxxOkkkkOOOOO000OOko::::cccl\n\t\tllooollodkOO000kkOOOxoccc:cll:.       .ckOkdxOkkkkOOOO00OOOkxo::::cccl\n\t\tlllllllodkO0000OkkOOdlccc::lcc;.     .:kOkkdxOkkkOOOkO0OOkkxxdc::::ccc\n\t\tclllllloxkO00000kxkkdlccc::ccc:'.   .;dkOOxoxOkkkkkxxOOOOkxxxdc::::ccc\n\t\tclllllloxO0000000kddolccc:;:cc:,',codkkOOOxoxOkkxddxOOOOkkkkxdl:::cccc\n\t\tclllllloxO00000000Oxoollcc:llllldkOOOOOOO0kdoodddxkO00OOkkkkxdl::ccccc\n\t\tlllllcldkO00000K0000OOOkkkOOkkkkOOOOOOO0000OOOO000OO000Okkkxddl:::cccc");
}

void BossEsfinge(int Vida, int MusicOn)   // Inicio da luta com a Esfinge //
{
    int FaseAtual = 4, Vidas = Vida, VidaEsfinge = 500, o = MusicOn;
    system("cls");
    printf("Vidas: %d ", Vidas);
    printf("\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|/////////////////////////| %d", VidaEsfinge);
    EsfingeImage();
    printf("\n Que animal anda pela manhã sobre quatro patas, a tarde sobre duas e a noite sobre três? \n\n   O Gato \n   O Chachorro \n   O Homem");
    SetaUpDown(36, 0, 3, 1, "->", "  ");

    if (opcao == 3)
    {
        system("cls");
        VidaEsfinge -= 100;
        printf("Vidas: %d ", Vidas);
        printf("\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|////////////////////-----| %d", VidaEsfinge);
        EsfingeImage();
        printf("\n Por que seria o homem? \n\n   Porque o homem é um bípede \n   Porque o homem não quer mais viver uma mentira \n   Porque na infância o homem engatinha \n   Porque na infância o homem pensa muito");
        SetaUpDown(36, 0, 4, 1, "->", "  ");

        if (opcao == 3)
        {
            system("cls");
            VidaEsfinge -= 100;
            printf("Vidas: %d ", Vidas);
            printf("\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|///////////////----------| %d", VidaEsfinge);
            EsfingeImage();
            printf("\n E o que mais? \n\n   Na idade adulta ele anda ereto \n   Essa é toda a resposta \n   Não tenho tempo para essas questões filosóficas, me deixe passar \n   Não idade adulta ele pensa muito, e pensar nos faz andar");
            SetaUpDown(36, 0, 4, 1, "->", "  ");

            if (opcao == 1)
            {
                system("cls");
                VidaEsfinge -= 100;
                printf("Vidas: %d ", Vidas);
                printf("\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|//////////---------------| %d", VidaEsfinge);
                EsfingeImage();
                printf("\n Mais alguma coisa? \n   Sim, na velhice o homem necessita de uma bengala para andar \n   Não, é apenas essa a resposta");
                SetaUpDown(35, 0, 2, 1, "->", "  ");

                if (opcao == 1)
                {
                    system("cls");
                    VidaEsfinge = 0;
                    printf("Vidas: %d ", Vidas);
                    printf("\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|-------------------------| %d", VidaEsfinge);
                    EsfingeImage();
                    printf("\n\nVocê me venceu, como conseguiu?\n");
                    system("pause");
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

void Fase1Cenario2(int Vida, int MusicOn)
{
    int FaseAtual = 5, Vidas = Vida, o = MusicOn;
    char RespostaChar[200];
    system("cls");
    printf("Vidas: %d \n", Vidas);
    char Text1Fase1[] = "  Primeiramente, você deve se perguntar onde nasce o sol.\n\n";
    SlowText(Text1Fase1);
    printf("    N (norte) \n    S (sul) \n    L (leste) \n    O (oeste) \n");
    SetaUpDown(3, 1, 4, 1, "->", "  ");

    switch (opcao)
    {
    case 1:
        system("cls");
        char Texto2[] = "Bom, parece que você não tem o necessário para derrotar Seth, mas não se preocupe, você terá um segunda chance.\n\n";
        SlowText(Texto2);
        system("pause");
        Anubis(FaseAtual, Vidas, o);
    case 2:
        system("cls");
        char Texto3[] = "Bom, parece que você não tem o necessário para derrotar Seth, mas não se preocupe, você terá um segunda chance.\n\n";
        SlowText(Texto3);
        system("pause");
        Anubis(FaseAtual, Vidas, o);
    case 3:
        system("cls");
        char Texto4[] = "Correto, mas não é apenas isso, o Templo de Hórus não é tão fácil de encontrar, então me responda novamente.\n\n";
        SlowText(Texto4);
        char Texto5[] = "Se você olhar na direção em que o sol nasce, qual é a direção que fica à sua direita?\n\n";
        SlowText(Texto5);
        printf ("    N (norte) \n    S (sul) \n    L (leste) \n    O (oeste) \n");
        SetaUpDown(4, 1, 4, 1, "->", "  ");

        switch (opcao)
        {
        case 2:
            system("cls");
            char Texto7[] = "Muito bem, você encontrou o Templo de Hórus, agora você terá que encontrar um modo de subir a montanha.\n\n";
            SlowText(Texto7);
            system("pause");
            Fase2Cenario2(Vidas, o);
        default:
            system("cls");
            char Texto8[] = "Bom, parece que você não tem o necessário para derrotar Seth, mas não se preocupe, você terá um segunda chance.\n\n";
            SlowText(Texto8);
            system("pause");
            Anubis(FaseAtual, Vidas, o);

        }
    case 4:
        system("cls");
        char Texto6[] = "Bom, parece que você não tem o necessário para derrotar Seth, mas não se preocupe, você terá um segunda chance.\n\n";
        SlowText(Texto6);
        system("pause");
        Anubis(FaseAtual, Vidas, o);

    }

}

void BossSeth(int Vida, int MusicOn, int argc, char *argv[])    //Boss final
{
    int CoolDown = 0, Vidas = Vida, FaseAtual = 8, o = MusicOn, VidaSeth = 10, VidaArqueologo = 4, Random;
    system("cls");
    char Texto1[] = "Após ter entrado no templo você se depara com o próprio Deus Hórus, porém ele se encontra com ferimentos de sua última batalha. Hórus conta a verdade sobre quem lhe guia, logo você descobre que a voz misteriosa\nera de Seth (Deus do Caos). Após ouvir isso Seth se manifesta e contradiz Horús.\n";
    SlowText(Texto1);

    printf("\n    Acreditar em Horús.\n    Acreditar em Seth.");
    SetaUpDown(4, 1, 2, 1, "->", "  ");

    switch(opcao)
    {
    case 1:
        system("cls");
        char Texto2[] = "Hórus: Rapido mortal, pegue o amuleto e obtenha o poder de um Deus, eu lhe darei o resto do meu poder, derrote Seth e traga a paz.\n\n";
        char Texto3[] = "Você pega o amuleto com o poder de Horús e entra em uma batalha mortal contra Seth\n";
        char Texto4[] = "Você tem três opções de ataques, saiba que o dano dos ataques causados em Seth sera escolhido randomicamente.\n\n";
        SlowText(Texto2);
        SlowText(Texto3);
        Sleep(8000);
        while (VidaArqueologo > 0 || VidaSeth > 0)
        {
            system("cls");
            SlowText(Texto4);
            system("pause");
            printf("\n    Lamina de Hórus. \n    Olhos de Águia    \n    Raio Solar");
            SetaUpDown(4, 1, 3, 1, "->", "  ");

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
                printf("Você causou %d de dano a Seth.\n", Random);
                VidaSeth -= Random;
                if (VidaSeth > 0 && VidaArqueologo > 0)
                {
                    char Texto6[] = "Seth revidou e te arrancou uma vida";
                    SlowText(Texto6);
                    VidaArqueologo--;
                    system("pause");
                }
                else if (VidaSeth <= 0 && VidaArqueologo > 0)
                {
                    Vencedor(o);
                }
                else
                {
                    printf("voce morreu");
                    system ("pause");
                    Anubis(FaseAtual, Vidas, o);
                }
                CoolDown--;
                break;

            case 2:
                system("cls");
                printf("Vida Seth: %d\n\n", VidaSeth);
                printf("Vida Arqueologo: %d\n\n", VidaArqueologo);
                char Texto7[] = "Você usa uma visão ampliada e descobre uma vulnerabilidade em Seth.";
                SlowText(Texto7);
                srand(time(NULL));
                Random = rand()%6 + 2; //Maior probabilidade de dar dano alto
                printf("Você causou %d de dano a Seth.\n", Random);
                VidaSeth -= Random;
                if (VidaSeth > 0 && VidaArqueologo > 0)
                {
                    char Texto6[] = "Seth revidou e te arrancou uma vida";
                    SlowText(Texto6);
                    VidaArqueologo--;
                    system("pause");
                }
                else if (VidaSeth <= 0 && VidaArqueologo > 0)
                {
                    Vencedor(o);
                }
                else
                {
                    printf("voce morreu");
                    system ("pause");
                    Anubis(FaseAtual, Vidas, o);
                }
                CoolDown--;
                break;
            case 3:
                system("cls");
                if (CoolDown > 0)
                {
                    printf("Você não pode usar este poder agora.");
                    system("pause");
                }
                else
                {
                    printf("Vida Seth: %d\n\n", VidaSeth);
                    printf("Vida Arqueologo: %d\n\n", VidaArqueologo);
                    char Texto9[] = "Você utiliza o raio solar e deixa Seth sego por alguns segundos, você aproveita e desfere um ataque.";
                    SlowText(Texto9);
                    srand(time(NULL));
                    Random = rand()%6;
                    printf("Você causou %d de dano a Seth.\n", Random);
                    VidaSeth -= Random;
                    if (VidaSeth > 0 && VidaArqueologo > 0)
                    {
                        char Texto10[] = "Seth estava sego e nao conseguiu te atacar.";
                        SlowText(Texto10);
                        system("pause");
                    }
                    else if (VidaSeth <= 0 && VidaArqueologo > 0)
                    {
                       Vencedor(o);
                    }
                    else
                    {
                        printf("voce morreu");
                        system ("pause");
                        Anubis(FaseAtual, Vidas, o);
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
        SlowText(Texto14);
        Sleep(8000);
        GameOver(o);
    }
}
