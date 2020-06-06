#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

                         // Globais //
char RespostaChar[20], NamePlayer[20], Password[20];
int KeyPress,b,L,opcao,i,TimeText = 1, Vidas = 1, FaseAtual;


                          // Setas //
void coordxy(int x,int y) {
    COORD Mouse;
    Mouse.X = x;
    Mouse.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Mouse);
}

void SetaUpDown(La, coordx, BLimite, LOper, SetaModel, SetaModelSpace) {   // Seta pra cima e pra baixo //
    opcao = 0;
    L=La; b=1;
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

void SetaLeftRight(La, coordy, BLimite, LOper, SetaModel, SetaModelSpace) {   // Seta pra direita e pra esquerda //
    opcao = 0;
    L=La; b=1;
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

      // Efeito Texto em Slow //
char SlowText(char* Text) {
    for (i = 0; Text[i] != '\0'; i++) {
        printf("%c",Text[i]);
        Sleep(TimeText);
    }
}

                      // Menu //
void main() {
    Vidas = 1;
    setlocale(LC_ALL,"Portuguese");
    SetConsoleTitle("Archeology Game");
    system("MODE con cols=200 lines=60");
    PlaySound(TEXT("menu.wav"), NULL, SND_ASYNC|SND_LOOP);
    system("cls");
    printf("     \"Menu de op��es\"\n\n      Novo Jogo \n      Escolher Fase\n      GitHub\n      Sair \n");
    printf("\nPor Favor, deixei o jogo em tela cheia");
    SetaUpDown(2, 3, 4, 1, "->", "  ");

    switch (opcao){
        case 1:
            system("cls");
            Player();
        case 2:
            system("cls");
            printf("  Este � o menu do desenvolvedor, por favor digite sua senha: ");
            gets(Password);
            if (strcmp (Password, "1234")== 0) {
                printf("  Verificando...\n");
                Sleep(1000);
                printf("  Voc� ser� direcionado para o menu de escolha de fase, por favor aguarde.");
                Sleep(2000);
                system("cls");
                SelectFase();
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
            printf("  Voc� est� sendo direcionado ao nosso projeto no GitHub...");
            Sleep(2000);
            system("start https://github.com/Gaspor/Archeology");
            Sleep(2000);
            main();
        case 4:
            Quit();
        default:
            printf("  Essa op��o n�o existe, por favor tente uma nova.\n");
            Sleep(1500);
    }
}

void SelectFase() {  // Fun��o para desenvolvedores para selecionar Fase //
    system("cls");
    printf("     \"Menu de Fases\"\n\n      Ir para a Fase 1\n      Ir para a Fase 2\n      Ir para a Fase 3\n      Ir para o Boss Esfinge\n      Ir para a Fase 1 (Segundo Cen�rio)\n      Ir para a Fase 2 (Segundo Cen�rio)\n      Ir para a Fase 3 (Segundo Cen�rio)\n      Ir para o Boss   (Segundo Cen�rio)\n\n      Voltar ao Menu principal\n");
    SetaUpDown(2, 3, 10, 1, "->", "  ");

    switch (opcao){
        case 1:
            system("cls");
            printf("   Voc� escolheu ir para a Fase 1.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 1...\n");
            Sleep(1500);
            system("cls");
            Fase1();
        case 2:
            system("cls");
            printf("   Voc� escolheu ir para a Fase 2.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 2...\n");
            Sleep(1500);
            system("cls");
            PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
            Fase2();
        case 3:
            system("cls");
            printf("   Voc� escolheu ir para a Fase 3.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 3...\n");
            Sleep(1500);
            system("cls");
            PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
            Fase3();
        case 4:
            system("cls");
            printf("   Voc� escolheu ir para a Fase do Boss.\n");
            Sleep(1000);
            printf("   Iniciando o Boss...\n");
            Sleep(1500);
            system("cls");
            BossEsfinge();
        case 5:
            system("cls");
            printf("   Voc� escolheu ir para a Fase 1 do Segundo cen�rio.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 1 (Segundo cen�rio)...\n");
            Sleep(1500);
            system("cls");
            PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
            Fase1Cenario2();
        case 6:
            system("cls");
            printf("   Voc� escolheu ir para a Fase 2 do Segundo cen�rio.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 2 (Segundo cen�rio)...\n");
            Sleep(1500);
            system("cls");
            PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
            Fase2Cenario2();
        case 7:
            system("cls");
            printf("   Voc� escolheu ir para a Fase 3 do Segundo cen�rio.\n");
            Sleep(1000);
            printf("   Fase em constru��o, selecione outra!\n");
            system("pause");
            system("cls");
            SelectFase();
        case 8:
            system("cls");
            printf("   Voc� escolheu ir para a Fase do Boss do Segundo cen�rio.\n");
            Sleep(1000);
            printf("   Fase em constru��o, selecione outra!\n");
            system("pause");
            system("cls");
            SelectFase();
        case 10:
            main();
        default:
            printf("  Op��o inv�lida, tente outra");
            Sleep(1000);
            SelectFase();
    }
}

void GameOver() {  // Fun��o de GameOver //
    char GameOver[] = "  Game Over";
    SlowText(GameOver);
    Sleep(2000);
    system("cls");
    main();
}

     // Sa�da do Jogo //
void Quit() {
    system("cls");
    printf("\aSaindo...\n");
    Sleep(800);
    exit(0);
}

                 // Utilit�rios do c�digo //
void Anubis(int Fase, int Vida) { // An�bis (Controlador de Vidas do Player)
    if (Vida == 1 && Fase == 1) {
        system("cls");
        printf("Vidas: %d \n\n  An�bis: N�o acredito que voc� errou algo t�o f�cil, mas n�o se preocupe, te darei uma segunda chance\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        Fase1();
    } if (Vida == 1 && Fase == 2) {
        system("cls");
        printf("Vidas: %d \n\n  An�bis: Eu te darei mais uma chance de vida, mortal n�o a desperdice\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        Fase2();
    } if (Vida == 1 && Fase == 4) {
        system("cls");
        printf("Vidas: %d \n\n  An�bis: Voc� morreu, irei te reviver apenas dessa vez, n�o cometa mais erros\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        BossEsfinge();
    } if (Vida == 1 && Fase == 5) {
        system("cls");
        printf("Vidas: %d \n\n  An�bis: S� tenho poder suficiente pra te reviver desta vez, ent�o n�o erre novamente!\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        Fase1Cenario2();
    } if (Vida == 1 && Fase == 6) {
        system("cls");
        printf("Vidas: %d \n\n  An�bis: Voc� morreu, n�o cometa mais erros, pois, n�o irei te ajudar da pr�xima vez!\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        Fase2Cenario2();
    } else {
        system("cls");
        printf("Vidas: %d \n\n  Voc� n�o tem vidas restantes\n\n", Vidas);
        system("pause");
        GameOver();
    }
}


void Player() {    // Nome do Player //
    system("cls");
    printf("  Por favor, n�o aperte nada enquanto o texto � digitado em sua tela.\n");
    printf("  Por favor, n�o use caractere especial\n\n");
    printf("  Digite o nome do Arque�logo: ");
    fflush(stdin);
    gets(NamePlayer);
    KbLore:
        coordxy(0,5);
        printf("\n\n Voc� deseja pular a Hist�ria? \n   Aperte S para Sim.\n   Aperte N para N�o.\n");
        if (kbhit) {KeyPress=getch();}
        if (KeyPress == 110) {Lore();}
        if (KeyPress == 115) {Fase1();}
        else {goto KbLore;}
}

                  // Hist�ria do Jogo //
void Lore() {  // Hist�ria primeiro Cen�rio
    system("cls");
    char Texto1[20000] = "  \n\tNo Egito antigo, h� muitas eras, antes da humanidade nascer, acontecia uma imensa batalha, algo que nenhum mortal poderia presenciar. Os Deuses antigos travaram uma bata-\n\nlha mortal pelo poder de um amuleto, aquele que possu�sse tal amuleto ampliaria seus poderes e reinaria sobre o mundo. Os Deuses lutaram por s�culos para obter tal poder, mas no\n\n meio desta grande batalha, Os�ris o Deus do julgamento interveio, e com seu imenso poder amaldi�oou o amuleto, permitindo apenas o uso para aqueles que n�o possuem o poder divi-\n\nno. Com o passar das eras o amuleto se perdeu e o grande Deus R� criou a humanidade. Os Deuses se dispersaram e pareciam ter se esquecido do amuleto, at� que no ano 51 A.C um\n\n soldado percebeu que algo brilhava em meio a terra, tomado pela curiosidade ele decide vasculhar o ch�o, e finalmente encontra um amuleto at� ent�o desconhecido, tudo o que ele\n\n via era seu formato peculiar. Com o amuleto desenterrado um enorme poder surgia dele, humanos n�o podiam perceber, mas os Deuses perceberam na hora que o amuleto havia sido en-\n\ncontrado, mas sem saber o que era, o soldado coloca o amuleto em volta do pesco�o, e sem perceber o poder flui pelo seu corpo, os soldados aliados que estavam em volta perceberam\n\n o comportamento estranho de seu companheiro, mas quando se aproximam dele o portador do amuleto simplesmente se torna cinzas, assustados com a cena os soldados em volta re-\n\nparam que vinha um brilho do artefato desconhecido e ligam a morte de seu amigo diretamente ao amuleto. Assustados com a presen�a de algo t�o poderoso os soldados informam ao\n\n fara� sobre o ocorrido, e sem acreditar no que ouvia e totalmente aterrorizado o fara� ordena aos seus s�ditos que construam uma enorme pir�mide em volta do amuleto, e que\n\n o enterrem o mais fundo poss�vel nas catacumbas da nova pir�mide. Os Deuses n�o tinham muita influ�ncia no mundo mortal, mas o que eles n�o sabiam era que Seth tentaria manipu-\n\nlar um mortal para obter o \�Olho de H�rus\� e retirar sua maldi��o. Com a maldi��o desfeita, Seth reinar� sobre todos os Deuses e seus respectivos reinos, Seth libertar�\n\n toda a escurid�o sobre o mundo e o assim governar� por toda eternidade.\n\n";
    char Texto2[] = "  Voc� � um arque�logo conhecido como";
    char Texto3[] = "ao estudar est� lenda voc� decide ir em busca deste artefato antigo...\n\n  Essa ser� um jornada tortuosa, e para enfim alcan�ar o antigo artefato, voc� ter� que passar pelos mais dif�ceis \n\n desafios... \n\n";
    char TextFase1[] = "  Voc� entra na piramide e logo se depara com o primeiro desafio, uma porta com um tipo de tabela com pe�as faltando, \n\n sem saber o que fazer voc� come�a a andar pela sala.\n\n Andando pela sala voc� encontra uma sacola com 6 letras F's e duas letras V's, depois de encontrar est� sacola voc� \n\n decide voltar para a porta, ao voltar voc� logo percebe o que ter� que fazer, voc� ter� que colocar essas letras da \n\n sacola na porta para passar \n\n";

    SlowText(Texto1);
    fflush(stdin);
    system("pause");
    system("cls");
    SlowText(Texto2);
    printf(" ");
    SlowText(NamePlayer);
    printf(", ");
    SlowText(Texto3);
    SlowText(TextFase1);
    LoreEnter2:
    fflush(stdin);
    system("pause");
    Fase1();
}

                      // Fase 1 //
void Fase1() {
    FaseAtual = 1;
    system("cls");
    PlaySound(TEXT("Fases.wav"), NULL, SND_ASYNC|SND_LOOP);
    int Acertos = 0, Vs = 2, Fs = 6;
    Tabelas:
    system("cls");
    coordxy(0, 0);
    printf("Vidas: %d \n", Vidas);
    printf(" Voc� ent�o come�a a completar a tabela...\n");
    coordxy(0,6);
    printf("\t\t\t\t  ========================================\n");
    printf("\t\t\t\t  |   A   B (A^B) B' (B'^A) (A^B)^(B'^A) |\n");
    printf("\t\t\t\t  |       F       V              F       |\n");
    printf("\t\t\t\t  |   F   V   F   F     F                |\n");
    printf("\t\t\t\t  |       F   F   V     V                |\n");
    printf("\t\t\t\t  |   V       V         F        F       |\n");
    printf("\t\t\t\t  ========================================\n\n O que voc� deseja colocar nesta parte da tabela?");
    if (Acertos == 0) {
        coordxy(36,8);
        printf(">");
    } if (Acertos == 1) {
        coordxy(38,8);
        printf("F");
        coordxy(44,8);
        printf(">");
    } if (Acertos == 2) {
        coordxy(38,8);
        printf("F   F   F");
        coordxy(54,8);
        printf(">");
    } if (Acertos == 3) {
        coordxy(38,8);
        printf("F   F   F   V     F");
        coordxy(63,9);
        printf(">");
    } if (Acertos == 4) {
        coordxy(38,8);
        printf("F   F   F   V     F");
        coordxy(38,9);
        printf("F   V   F   F     F        F");
        coordxy(36,10);
        printf(">");
    } if (Acertos == 5) {
        coordxy(38,8);
        printf("F   F   F   V     F");
        coordxy(38,9);
        printf("F   V   F   F     F        F");
        coordxy(38,10);
        printf("V");
        coordxy(63,10);
        printf(">");
    } if (Acertos == 6) {
        coordxy(38,8);
        printf("F   F   F   V     F");
        coordxy(38,9);
        printf("F   V   F   F     F        F");
        coordxy(38,10);
        printf("V   F   F   V     V        F");
        coordxy(40,11);
        printf(">");
    } if (Acertos == 7) {
        coordxy(38,8);
        printf("F   F   F   V     F");
        coordxy(38,9);
        printf("F   V   F   F     F        F");
        coordxy(38,10);
        printf("V   F   F   V     V        F");
        coordxy(38,11);
        printf("V   V   V");
        coordxy(48,11);
        printf(">");
    }
    coordxy(6,15);
    printf("V\n      F");
    printf("\n\n Invent�rio\n  Total de F: %d\n  Total de V: %d", Fs, Vs);

    SetaUpDown(15, 3, 2, 1, "->", "  ");

switch (opcao){
    case 1:
        if (Acertos == 4) {
            Vs--;
            system("cls");
            Acertos++;
            goto Tabelas;
        } if (Acertos == 6) {
            Vs--;
            system("cls");
            Acertos++;
            goto Tabelas;
        } else {
            coordxy(2,22);
            printf("Voc� errou!");
            Sleep(2000);
            Anubis(FaseAtual, Vidas);
            Fase1();
        }
    case 2:
        if (Acertos == 0) {
            Fs--;
            system("cls");
            Acertos++;
            goto Tabelas;
        } if (Acertos == 1) {
            Fs--;
            system("cls");
            Acertos++;
            goto Tabelas;
        } if (Acertos == 2) {
            Fs--;
            system("cls");
            Acertos++;
            goto Tabelas;
        } if (Acertos == 3) {
            Fs--;
            system("cls");
            Acertos++;
            goto Tabelas;
        } if (Acertos == 5) {
            Fs--;
            system("cls");
            Acertos++;
            goto Tabelas;
        } if (Acertos == 7) {
            Fs--;
            coordxy(50,11);
            printf("F");
            coordxy(1,22);
            char NextFase[] = " A porta se abre e voc� consegue ir pra pr�xima sala.";
            SlowText(NextFase);
            fflush(stdin);
            Sleep(1000);
            system("cls");
            Acertos++;
            Fase2();
        } else {
            coordxy(2,22);
            printf("Voc� errou!");
            Sleep(2000);
            Anubis(FaseAtual, Vidas);
            Fase1();
        }
    }
}

                   // Fase 2 //
void Fase2() {
    FaseAtual = 2;
    int Acertos = 0;
    coordxy(0, 0);
    printf("Vidas: %d \n", Vidas);
    char Text1[] = "   Voc� se depara com uma entrada, anda at� ela e quando est� chegando, o ch�o come�a a tremer. De repente\nvoc� percebe que alguns pisos n�o tremem e eles ser�o o seu caminho at� a entrada.\n";
    SlowText(Text1);
    Acerto:
        fflush(stdin);
        coordxy(2,3);
        printf("Passos: ");
        if (Acertos == 0){coordxy(2,4);printf("V� ao max�mo para esquerda.              ");coordxy(49,7);printf("== Primeiro Piso == \n");}
        if (Acertos == 1){coordxy(2,4);printf("Quadruplique!!              ");coordxy(49,7);printf("== Segundo Piso == \n");}
        if (Acertos == 2){coordxy(2,4);printf("Divida por dois.              ");coordxy(49,7);printf("== Terceiro Piso == \n");}
        if (Acertos == 3){coordxy(2,4);printf("Adicione um.              ");coordxy(49,7);printf("== Quarto Piso ==       \n");}
        coordxy(19,7);
        printf("\n\t\t\t\t\t====================================\n\t\t\t\t\t|  1         2         3         4 |\n\t\t\t\t\t|        Posi��o do jogador        |\n\t\t\t\t\t====================================\n");
        SetaLeftRight(41, 9, 4, 10, ">", " ");

    switch (opcao){
        case 1:
            if (Acertos == 0) {
                char Acerto1[] ="   Voc� acertou e passou para o pr�ximo piso           \n";
                Acertos++;
                SlowText(Acerto1);
                goto Acerto;
            } else {
                ErrorFase2();
            }
        case 2:
            if (Acertos == 2) {
                char Acerto3[] = "   Voc� acertou, por pouco!                            \n";
                Acertos++;
                SlowText(Acerto3);
                goto Acerto;
            } else {
                ErrorFase2();
            }
        case 3:
            if (Acertos == 3) {
                char Acerto4[] = "   Voc� finalmente passou sem cair em nenhuma armadilha\n";
                SlowText(Acerto4);
                Sleep(3000);
                system("cls");
                Fase3();
            } else {
                ErrorFase2();
            }
        case 4:
            if (Acertos == 1) {
                char Acerto2[] = "   Voc� acertou, tome cuidado com os pisos falsos      \n";
                Acertos++;
                SlowText(Acerto2);
                goto Acerto;
            } else {
                ErrorFase2();
            }
    }
}

void ErrorFase2() {   // Fun��o que � chamada quando o usu�rio erra o piso da Fase 2  //
    char ErroPiso[] ="   Voc� pisou em um lugar que n�o era seguro, o ch�o desmoronou, e voc� morreu com a queda.\n";
    SlowText(ErroPiso);
    Sleep(2000);
    Anubis(FaseAtual, Vidas);
    Fase2();
}

                // Fase 3 //
void Fase3() {
    FaseAtual = 3;
    coordxy(0, 0);
    printf("Vidas: %d \n", Vidas);
    char Text1Fase3[] = "   Voc� passa pela entrada da segunda fase e observa que h� outra passagem, voc� anda at� ela e de repente a entrada \n\n se fecha e voc� ouve um barulho intenso, uma enorme esfinge feita de areia se ergue diante de voc�.\n\n";
    char Text2Fase3[] = "   \"Esfinge: Eu sou a �ltima porta para o seu destino, responda corretamente meu enigma e sua passagem ser� liberada.\"\n\n";
    char Text3Fase3[] = "   Esfinge: Eu nunca fui e sempre poderei ser, ningu�m jamais me viu ou ver�, mas sou a certeza de todos os que vivem e que respiram, quem sou eu?: ";
    SlowText(Text1Fase3);
    SlowText(Text2Fase3);
    SlowText(Text3Fase3);
    fflush(stdin);
    gets(RespostaChar);
    if ((strcasecmp (RespostaChar, "amanha")== 0)||(strcasecmp (RespostaChar, "futuro")== 0)) {
        char Text4Fase3[] = "\n   Voc� acertou o meu enigma, eu te concedo a passagem para a pr�xima sala!\n";
        SlowText(Text4Fase3);
        fflush(stdin);
        Sleep(4000);
        system("cls");
        cenario();
    } else {
       printf("\nVoc� errou, agora meu enfrente!!!\n\n");
       system("pause");
       BossEsfinge();
    }
}

            // Comandos da Esfinge //
void EsfingeImage() {    // Aparecer a Imagem da Esfinge
    printf("\n\t\t......................................................................\n\t\t............................'',;;::::;,'..............................\n\t\t..................'',;::cllooooddodxxxdolllcc::;,''...................\n\t\t...............,coodxxxddxxddddxddxkkxxxxxxxxxxxxdlc:,'...............\n\t\t..........'',,:xOkddxxxxkkxxxxxxodkkkkxkkkOOkkxxxdllol:;,,'''.........\n\t\t.....'',,;;,;cxOkkkxdddxkkOOkkOkddxxkkOO00000Oxddoododdc;;;;;;,''.....\n\t\t..',,;;;;;;;lkOOkkkkxdddxO000OOOxolldkO0KKKK0kxdodddodddl::::;;::;,'..\n\t\t,;;;;;;;;;;lO0OOkkkkxddookOOOkkkkkOOOO000000kxdddxxdddddxl:::::::::::;\n\t\t::;;;;;;;:lk0OOOkOOOkxolldxkxdoodkOOkkxxkOOOkdddxkkxdoodxxoccccccccccc\n\t\t::;;;;:::lkOOOkkOOOOOkdocclol::;;okOko:;:ldxdxxxOkkkkxddxxxocllllccccc\n\t\t:;;;::::lxOOOkkkkkkddxdolcllllccclkOkxdlcloddxkkdodxxxxdxkOxolllllllll\n\t\t:;;:::clx00OkkkkkkdldxdodxxkkOOxlldxkO00Ok0000OxdlodxxddxxkOkoloooooll\n\t\t::::cccdO00Okkkxxxdx0OoclxkOOOOxlcccldk000KK0OkkOkooxxddxkkOOkoloooooo\n\t\t:::cccok00OOxxkxxxocoxo::coxxkkoloxxdodO000OOkxxl:coddxxkkOOOOxooooooo\n\t\t::ccclxOOOOkkxxxxxxdolc:;;cloddlloooddxkOkkkxxdoldxxdxxkkkOOOOkdlooooo\n\t\t:ccllokOOOOOkxxxxkkxkko:;;:coo:,,;;::cloxkxxddxxkxxxxxkkkkOOOOOxoooooo\n\t\tcccllok0000Okkkkkkkkkkxc;,,;cooccclooddkkxdoookOkkkkkkOOOOOOOOOxoloooo\n\t\tcccllldO00000OOkkkkkkkkd;,'';:ldxkOO00OOkoc:cdOOOOOOOO00000000kdlloooo\n\t\tccllooloxO000OOkkkkkkkkxl'...:odkkO00000x;.'ck0OOO0OO0000000Odlllloooo\n\t\tcllooodolox0OOOkkxkxxxxxdc,..:ddkO000K00d,;lxOOOOOOOO00O00Oocccllllooo\n\t\tlllooddddlldkOkkkxxxxxxxxo:;,cdxkO00KK00kodxOOOOOOO00OO00Odlcccclllllo\n\t\tlllooddddxxddkOkkxdddddddl:;;lxxkO000K00kdxkOOOOOOOOOO00OOOOdc:cclllll\n\t\tllloooooodkOkdkOOkxddooool:;:oxxkOO00K00OxkOkOOOOOOOOOOOO00Oxc:cccllll\n\t\tcllooooodxO00kxk0OOkxdollll::oddxkkOOOkO0kkkxkOOOOO0OOOO000Okl:::cccll\n\t\tcllooooodkO000kkO00Oxolllcll;''...''',;;lxkxdkOkkOOOOOO0000Okl:::cccll\n\t\tlloooooodkO000OkkO0Oxollc:coc.      ....ckOxxOkkkkOOOOO000OOko::::cccl\n\t\tllooollodkOO000kkOOOxoccc:cll:.       .ckOkdxOkkkkOOOO00OOOkxo::::cccl\n\t\tlllllllodkO0000OkkOOdlccc::lcc;.     .:kOkkdxOkkkOOOkO0OOkkxxdc::::ccc\n\t\tclllllloxkO00000kxkkdlccc::ccc:'.   .;dkOOxoxOkkkkkxxOOOOkxxxdc::::ccc\n\t\tclllllloxO0000000kddolccc:;:cc:,',codkkOOOxoxOkkxddxOOOOkkkkxdl:::cccc\n\t\tclllllloxO00000000Oxoollcc:llllldkOOOOOOO0kdoodddxkO00OOkkkkxdl::ccccc\n\t\tlllllcldkO00000K0000OOOkkkOOkkkkOOOOOOO0000OOOO000OO000Okkkxddl:::cccc");
}

void BossEsfinge() { // Inicio da luta com a Esfinge //
    FaseAtual = 4;
    system("cls");
    int VidaEsfinge = 500;
    coordxy(0, 0);
    printf("Vidas: %d ", Vidas);
    printf("\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|/////////////////////////| %d", VidaEsfinge);
    EsfingeImage();
    printf("\n Que animal anda pela manh� sobre quatro patas, a tarde sobre duas e a noite sobre tr�s? \n\n   O Gato \n   O Chachorro \n   O Homem");
    SetaUpDown(36, 0, 3, 1, "->", "  ");

    if (opcao == 3) {
        system("cls");
        VidaEsfinge -= 100;
        coordxy(0, 0);
        printf("Vidas: %d ", Vidas);
        printf("\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|////////////////////-----| %d", VidaEsfinge);
        EsfingeImage();
        printf("\n Por que seria o homem? \n\n   Porque o homem � um b�pede \n   Porque o homem n�o quer mais viver uma mentira \n   Porque na inf�ncia o homem engatinha \n   Porque na inf�ncia o homem pensa muito");
        SetaUpDown(36, 0, 4, 1, "->", "  ");

        if (opcao == 3) {
            system("cls");
            VidaEsfinge -= 100;
            coordxy(0, 0);
            printf("Vidas: %d ", Vidas);
            printf("\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|///////////////----------| %d", VidaEsfinge);
            EsfingeImage();
            printf("\n E o que mais? \n\n   Na idade adulta ele anda ereto \n   Essa � toda a resposta \n   N�o tenho tempo para essas quest�es filos�ficas, me deixe passar \n   N�o idade adulta ele pensa muito, e pensar nos faz andar");
            SetaUpDown(36, 0, 4, 1, "->", "  ");

            if (opcao == 1) {
                system("cls");
                VidaEsfinge -= 100;
                coordxy(0, 0);
                printf("Vidas: %d ", Vidas);
                printf("\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|//////////---------------| %d", VidaEsfinge);
                EsfingeImage();
                printf("\n Mais alguma coisa? \n   Sim, na velhice o homem necessita de uma bengala para andar \n   N�o, � apenas essa a resposta", VidaEsfinge);
                SetaUpDown(35, 0, 2, 1, "->", "  ");

                if (opcao == 1) {
                    system("cls");
                    VidaEsfinge = 0;
                    coordxy(0, 0);
                    printf("Vidas: %d ", Vidas);
                    printf("\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|-------------------------| %d", VidaEsfinge);
                    EsfingeImage();
                    printf("\n\nVoc� me venceu, como conseguiu?\n");
                    system("pause");
                    cenario();
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

                    // Mudan�a de Cen�rio  //
void cenario() {
    system("cls");
    char Texto1[] = "   Depois de passar pela esfinge voc� chega a �ltima sala da pir�mide. Nota-se que a sala \n\n est� vazia, voc� acha isso estranho, ser� que todo esse sacrif�cio foi feito em v�o?,\n\n de repente voc� escuta uma voz sussurrante dizendo: �O que voc� procura n�o est� aqui,\n\n mas posso te dizer como encontrar, siga meus conselhos, voc� n�o tem muito tempo�.\n\n Sem entender o que estava acontecendo voc� segue o caminho da voz.\n";
    SlowText(Texto1);
    system("pause");
    Fase1Cenario2();
}

                    // Fase 1 do Segundo cen�rio //
void Fase1Cenario2() {
    FaseAtual = 5;
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
        Fase2Cenario2();
    } else {
        char Text3Fase1[] = "  Voc� decifrou o anagrama de forma errada, voc� segue a pista do seu anagrama, \n por�m ele estava incorreto, eventualmente voc� n�o encontra o templo e morre de fome e sede\n\n";
        SlowText(Text3Fase1);
        system("pause");
        Anubis(FaseAtual, Vidas);
    }
}

                    // Fase 2 do Segundo cen�rio //
void Fase2Cenario2() {
    FaseAtual = 6;
    system("cls");
    printf("Vidas : %d \n", Vidas);
    char Text1Fase2[] = "  Voc� encontrou a montanha!\n\n  O Templo de H�rus reside no topo desta montanha, para subi-la voc� deve ouvir atentamente \n\n";
    SlowText(Text1Fase2);
    printf("  Me diga qual � a nega��o da seguinte frase: Eu sou R� Deus do Sol\n\n  Resposta(Sem acentua��o): ");
    fflush(stdin);
    gets(RespostaChar);
    if (strcasecmp (RespostaChar, "Eu nao sou ra deus do sol")== 0) {
        char Text2Fase1[] = "\n\n  Surge uma escada que te levar� ao topo da montanha\n\n";
        SlowText(Text2Fase1);
        fflush(stdin);
        system("pause");
        system("cls");
        Fase3Cenario2();
    } else {
        char Text3Fase1[] = "\n\n  Uma escada surge por toda a montanha, voc� tenta subi-l�, mas quando voc� estava no \n\n  meio do caminha ela come�a a se desfazer, voc� morreu!\n\n";
        SlowText(Text3Fase1);
        system("pause");
        Anubis(FaseAtual, Vidas);
    }
}

void Fase3Cenario2() {
    FaseAtual = 7;
    printf("Fase em constru��o, volte um outro dia!\n\n");
    system("pause");
    main();
}
