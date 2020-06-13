#include "Includes.h"

                         // Globais //
char Password[20];
int KeyPress, b, L, opcao;

                          // Setas //
void coordxy(int x,int y) {
    COORD Mouse;
    Mouse.X = x;
    Mouse.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Mouse);
}

void SetaUpDown (int La,int coordx,int BLimite,int LOper,char *SetaModel,char *SetaModelSpace) {   // Seta pra cima e pra baixo //
    opcao = 0;
    L=La, b=1;
    do{
        coordxy(coordx, L);
        printf(SetaModel);
        coordxy(0,20);
        if(kbhit){KeyPress=getch();}
        if(KeyPress == 80 && b < BLimite){coordxy(coordx, L);printf(SetaModelSpace);L+=LOper;b++;}
        if(KeyPress == 72 && b > 1){coordxy(coordx, L);printf(SetaModelSpace);L-=LOper;b--;}
        if (KeyPress == 27) {Quit();}
        if(KeyPress == 13){opcao=b;}
    }while(opcao == 0);
}

void SetaLeftRight (int La,int coordy,int BLimite,int LOper,char *SetaModel,char *SetaModelSpace) {   // Seta pra direita e pra esquerda //
    opcao = 0;
     L=La, b=1;
    do{
        coordxy(L, coordy);
        printf(SetaModel);
        coordxy(0,20);
        if(kbhit){KeyPress=getch();}
        if (KeyPress == 77 && b < BLimite) {coordxy(L, coordy);printf(SetaModelSpace);L+=LOper;b++;}
        if (KeyPress == 75 && b > 1) {coordxy(L, coordy);printf(SetaModelSpace);L-=LOper;b--;}
        if (KeyPress == 27) {Quit();}
        if(KeyPress == 13){opcao=b;}
    }while(opcao == 0);
}

void Menu() {
    int Vidas = 1;
    setlocale(LC_ALL,"Portuguese");
    SetConsoleTitle("Archeology Game");
    system("MODE con cols=200 lines=60");
    PlaySound(TEXT("menu.wav"), NULL, SND_ASYNC|SND_LOOP);
    system("cls");
    printf("     \"Menu de opções\"\n\n      Novo Jogo \n      Escolher Fase\n      GitHub\n      Sair \n");
    printf("\nPor Favor, deixei o jogo em tela cheia");
    SetaUpDown(2, 3, 4, 1, "->", "  ");

    switch (opcao){
        case 1:
            system("cls");
            Player(Vidas);
        case 2:
            system("cls");
            printf("  Este é o menu do desenvolvedor, por favor digite sua senha: ");
            gets(Password);
            if (strcmp (Password, "1234")== 0) {
                printf("  Verificando...\n");
                Sleep(1000);
                printf("  Você será direcionado para o menu de escolha de fase, por favor aguarde.");
                Sleep(2000);
                system("cls");
                SelectFase(Vidas);
            } else {
                printf("  Verificando...\n");
                Sleep(1000);
                printf("  Senha incorreta.");
                Sleep(700);
                system("cls");
                main();
            }
        case 3:
            system("cls");
            printf("  Você está sendo direcionado ao nosso projeto no GitHub...");
            Sleep(2000);
            system("start https://github.com/Gaspor/Archeology");
            Sleep(2000);
            main();
        case 4:
            Quit();
        default:
            printf("  Essa opção não existe, por favor tente uma nova.\n");
            Sleep(1500);
    }
    return 0;
}

void SelectFase(int Vida) {  // Função para desenvolvedores para selecionar Fase //
    int Vidas = Vida;
    system("cls");
    printf("     \"Menu de Fases\"\n\n      Ir para a Fase 1\n      Ir para a Fase 2\n      Ir para a Fase 3\n      Ir para o Boss Esfinge\n      Ir para a Fase 1 (Segundo Cenário)\n      Ir para a Fase 2 (Segundo Cenário)\n      Ir para a Fase 3 (Segundo Cenário)\n      Ir para o Boss   (Segundo Cenário)\n\n      Voltar ao Menu principal\n");
    SetaUpDown(2, 3, 10, 1, "->", "  ");

    switch (opcao){
        case 1:
            system("cls");
            printf("   Você escolheu ir para a Fase 1.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 1...\n");
            Sleep(1500);
            system("cls");
            Fase1(Vidas);
        case 2:
            system("cls");
            printf("   Você escolheu ir para a Fase 2.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 2...\n");
            Sleep(1500);
            system("cls");
            PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
            Fase2(Vidas);
        case 3:
            system("cls");
            printf("   Você escolheu ir para a Fase 3.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 3...\n");
            Sleep(1500);
            system("cls");
            PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
            Fase3(Vidas);
        case 4:
            system("cls");
            printf("   Você escolheu ir para a Fase do Boss.\n");
            Sleep(1000);
            printf("   Iniciando o Boss...\n");
            Sleep(1500);
            system("cls");
            BossEsfinge(Vidas);
        case 5:
            system("cls");
            printf("   Você escolheu ir para a Fase 1 do Segundo cenário.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 1 (Segundo cenário)...\n");
            Sleep(1500);
            system("cls");
            PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
            Fase1Cenario2(Vidas);
        case 6:
            system("cls");
            printf("   Você escolheu ir para a Fase 2 do Segundo cenário.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 2 (Segundo cenário)...\n");
            Sleep(1500);
            system("cls");
            PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
            Fase2Cenario2(Vidas);
        case 7:
            system("cls");
            printf("   Você escolheu ir para a Fase 3 do Segundo cenário.\n");
            Sleep(1000);
            printf("   Fase em construção, selecione outra!\n");
            system("pause");
            system("cls");
            SelectFase(Vidas);
        case 8:
            system("cls");
            printf("   Você escolheu ir para a Fase do Boss do Segundo cenário.\n");
            Sleep(1000);
            printf("   Fase em construção, selecione outra!\n");
            system("pause");
            system("cls");
            SelectFase(Vidas);
        case 10:
            main();
        default:
            printf("  Opção inválida, tente outra");
            Sleep(1000);
            SelectFase(Vidas);
    }
}

void Fase2(int Vida) {
    system("cls");
    int FaseAtual = 2, Acertos = 0, Vidas = Vida;
    coordxy(0, 0);
    printf("Vidas: %d \n", Vidas);
    char Text1[] = "  Você se depara com uma entrada, anda até ela e quando está chegando, o chão começa a tremer. De repente\nvocê percebe que alguns pisos não tremem e eles serão o seu caminho até a entrada.\n";
    SlowText(Text1);
    Acerto:
        fflush(stdin);
        coordxy(2,3);
        printf("Passos: ");
        if (Acertos == 0){coordxy(2,4);printf("Vá ao maxímo para esquerda.              ");coordxy(49,7);printf("== Primeiro Piso == \n");}
        if (Acertos == 1){coordxy(2,4);printf("Quadruplique!!              ");coordxy(49,7);printf("== Segundo Piso == \n");}
        if (Acertos == 2){coordxy(2,4);printf("Divida por dois.              ");coordxy(49,7);printf("== Terceiro Piso == \n");}
        if (Acertos == 3){coordxy(2,4);printf("Adicione um.              ");coordxy(49,7);printf("== Quarto Piso ==       \n");}
        coordxy(19,7);
        printf("\n\t\t\t\t\t====================================\n\t\t\t\t\t|  1         2         3         4 |\n\t\t\t\t\t|        Posição do jogador        |\n\t\t\t\t\t====================================\n");
        SetaLeftRight(41, 9, 4, 10, ">", " ");

    switch (opcao){
        case 1:
            if (Acertos == 0) {
                char Acerto1[] ="   Você acertou e passou para o próximo piso           \n";
                Acertos++;
                SlowText(Acerto1);
                goto Acerto;
            } else {
                ErrorFase2(Vidas);
            }
        case 2:
            if (Acertos == 2) {
                char Acerto3[] = "   Você acertou, por pouco!                            \n";
                Acertos++;
                SlowText(Acerto3);
                goto Acerto;
            } else {
                ErrorFase2(Vidas);
            }
        case 3:
            if (Acertos == 3) {
                char Acerto4[] = "   Você finalmente passou sem cair em nenhuma armadilha\n";
                SlowText(Acerto4);
                Sleep(3000);
                system("cls");
                Fase3(Vidas);
            } else {
                ErrorFase2(Vidas);
            }
        case 4:
            if (Acertos == 1) {
                char Acerto2[] = "   Você acertou, tome cuidado com os pisos falsos      \n";
                Acertos++;
                SlowText(Acerto2);
                goto Acerto;
            } else {
                ErrorFase2(Vidas);
            }
    }
}

void ErrorFase2(int Vida) {   // Função que é chamada quando o usuário erra o piso da Fase 2  //
    int FaseAtual = 2, Vidas = Vida;
    char ErroPiso[] ="   Você pisou em um lugar que não era seguro, o chão desmoronou, e você morreu com a queda.\n";
    SlowText(ErroPiso);
    Sleep(2000);
    Anubis(FaseAtual, Vidas);
}

            // Comandos da Esfinge //
void EsfingeImage() {    // Aparecer a Imagem da Esfinge
    printf("\n\t\t......................................................................\n\t\t............................'',;;::::;,'..............................\n\t\t..................'',;::cllooooddodxxxdolllcc::;,''...................\n\t\t...............,coodxxxddxxddddxddxkkxxxxxxxxxxxxdlc:,'...............\n\t\t..........'',,:xOkddxxxxkkxxxxxxodkkkkxkkkOOkkxxxdllol:;,,'''.........\n\t\t.....'',,;;,;cxOkkkxdddxkkOOkkOkddxxkkOO00000Oxddoododdc;;;;;;,''.....\n\t\t..',,;;;;;;;lkOOkkkkxdddxO000OOOxolldkO0KKKK0kxdodddodddl::::;;::;,'..\n\t\t,;;;;;;;;;;lO0OOkkkkxddookOOOkkkkkOOOO000000kxdddxxdddddxl:::::::::::;\n\t\t::;;;;;;;:lk0OOOkOOOkxolldxkxdoodkOOkkxxkOOOkdddxkkxdoodxxoccccccccccc\n\t\t::;;;;:::lkOOOkkOOOOOkdocclol::;;okOko:;:ldxdxxxOkkkkxddxxxocllllccccc\n\t\t:;;;::::lxOOOkkkkkkddxdolcllllccclkOkxdlcloddxkkdodxxxxdxkOxolllllllll\n\t\t:;;:::clx00OkkkkkkdldxdodxxkkOOxlldxkO00Ok0000OxdlodxxddxxkOkoloooooll\n\t\t::::cccdO00Okkkxxxdx0OoclxkOOOOxlcccldk000KK0OkkOkooxxddxkkOOkoloooooo\n\t\t:::cccok00OOxxkxxxocoxo::coxxkkoloxxdodO000OOkxxl:coddxxkkOOOOxooooooo\n\t\t::ccclxOOOOkkxxxxxxdolc:;;cloddlloooddxkOkkkxxdoldxxdxxkkkOOOOkdlooooo\n\t\t:ccllokOOOOOkxxxxkkxkko:;;:coo:,,;;::cloxkxxddxxkxxxxxkkkkOOOOOxoooooo\n\t\tcccllok0000Okkkkkkkkkkxc;,,;cooccclooddkkxdoookOkkkkkkOOOOOOOOOxoloooo\n\t\tcccllldO00000OOkkkkkkkkd;,'';:ldxkOO00OOkoc:cdOOOOOOOO00000000kdlloooo\n\t\tccllooloxO000OOkkkkkkkkxl'...:odkkO00000x;.'ck0OOO0OO0000000Odlllloooo\n\t\tcllooodolox0OOOkkxkxxxxxdc,..:ddkO000K00d,;lxOOOOOOOO00O00Oocccllllooo\n\t\tlllooddddlldkOkkkxxxxxxxxo:;,cdxkO00KK00kodxOOOOOOO00OO00Odlcccclllllo\n\t\tlllooddddxxddkOkkxdddddddl:;;lxxkO000K00kdxkOOOOOOOOOO00OOOOdc:cclllll\n\t\tllloooooodkOkdkOOkxddooool:;:oxxkOO00K00OxkOkOOOOOOOOOOOO00Oxc:cccllll\n\t\tcllooooodxO00kxk0OOkxdollll::oddxkkOOOkO0kkkxkOOOOO0OOOO000Okl:::cccll\n\t\tcllooooodkO000kkO00Oxolllcll;''...''',;;lxkxdkOkkOOOOOO0000Okl:::cccll\n\t\tlloooooodkO000OkkO0Oxollc:coc.      ....ckOxxOkkkkOOOOO000OOko::::cccl\n\t\tllooollodkOO000kkOOOxoccc:cll:.       .ckOkdxOkkkkOOOO00OOOkxo::::cccl\n\t\tlllllllodkO0000OkkOOdlccc::lcc;.     .:kOkkdxOkkkOOOkO0OOkkxxdc::::ccc\n\t\tclllllloxkO00000kxkkdlccc::ccc:'.   .;dkOOxoxOkkkkkxxOOOOkxxxdc::::ccc\n\t\tclllllloxO0000000kddolccc:;:cc:,',codkkOOOxoxOkkxddxOOOOkkkkxdl:::cccc\n\t\tclllllloxO00000000Oxoollcc:llllldkOOOOOOO0kdoodddxkO00OOkkkkxdl::ccccc\n\t\tlllllcldkO00000K0000OOOkkkOOkkkkOOOOOOO0000OOOO000OO000Okkkxddl:::cccc");
}

void BossEsfinge(int Vida) { // Inicio da luta com a Esfinge //
    int FaseAtual = 4, Vidas = Vida;
    system("cls");
    int VidaEsfinge = 500;
    printf("Vidas: %d ", Vidas);
    printf("\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|/////////////////////////| %d", VidaEsfinge);
    EsfingeImage();
    printf("\n Que animal anda pela manhã sobre quatro patas, a tarde sobre duas e a noite sobre três? \n\n   O Gato \n   O Chachorro \n   O Homem");
    SetaUpDown(36, 0, 3, 1, "->", "  ");

    if (opcao == 3) {
        system("cls");
        VidaEsfinge -= 100;
        printf("Vidas: %d ", Vidas);
        printf("\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|////////////////////-----| %d", VidaEsfinge);
        EsfingeImage();
        printf("\n Por que seria o homem? \n\n   Porque o homem é um bípede \n   Porque o homem não quer mais viver uma mentira \n   Porque na infância o homem engatinha \n   Porque na infância o homem pensa muito");
        SetaUpDown(36, 0, 4, 1, "->", "  ");

        if (opcao == 3) {
            system("cls");
            VidaEsfinge -= 100;
            printf("Vidas: %d ", Vidas);
            printf("\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|///////////////----------| %d", VidaEsfinge);
            EsfingeImage();
            printf("\n E o que mais? \n\n   Na idade adulta ele anda ereto \n   Essa é toda a resposta \n   Não tenho tempo para essas questões filosóficas, me deixe passar \n   Não idade adulta ele pensa muito, e pensar nos faz andar");
            SetaUpDown(36, 0, 4, 1, "->", "  ");

            if (opcao == 1) {
                system("cls");
                VidaEsfinge -= 100;
                printf("Vidas: %d ", Vidas);
                printf("\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|//////////---------------| %d", VidaEsfinge);
                EsfingeImage();
                printf("\n Mais alguma coisa? \n   Sim, na velhice o homem necessita de uma bengala para andar \n   Não, é apenas essa a resposta");
                SetaUpDown(35, 0, 2, 1, "->", "  ");

                if (opcao == 1) {
                    system("cls");
                    VidaEsfinge = 0;
                    printf("Vidas: %d ", Vidas);
                    printf("\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|-------------------------| %d", VidaEsfinge);
                    EsfingeImage();
                    printf("\n\nVocê me venceu, como conseguiu?\n");
                    system("pause");
                    cenario(Vidas);
                } else {
                    Anubis(FaseAtual, Vidas);
                }
            } else {
                Anubis(FaseAtual, Vidas);
            }
       } else {
           Anubis(FaseAtual, Vidas);
        }
    } else {
        Anubis(FaseAtual, Vidas);
    }
}

void Quit() {
    system("cls");
    printf("\aSaindo...\n");
    Sleep(800);
    exit(0);
}
