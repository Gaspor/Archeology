#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

char RespostaChar[20], NamePlayer[20], Password[20];
int KeyPress,b,L,opcao,i,TimeText = 1;

void coordxy(int x,int y) {
    COORD Mouse;
    Mouse.X = x;
    Mouse.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Mouse);
}

void SetaUpDown(La, coordx, BLimite, LOper, SetaModel, SetaModelSpace) {
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

void SetaLeftRight(La, coordy, BLimite, LOper, SetaModel, SetaModelSpace) {
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

char SlowText(char* Text) {
    for (i = 0; Text[i] != '\0'; i++) {
        printf("%c",Text[i]);
        Sleep(TimeText);
    }
}

void main() {
    setlocale(LC_ALL,"Portuguese");
    PlaySound(TEXT("menu.wav"), NULL, SND_ASYNC|SND_LOOP);
    system("cls");
    printf("     \"Menu de opções\"\n\n      Novo Jogo \n      Escolher Fase\n      GitHub\n      Sair \n");
    printf("\nPor Favor, coloque o jogo em tela cheia");
    SetaUpDown(2, 3, 4, 1, "->", "  ");

    switch (opcao){
        case 1:
            system("cls");
            Player();
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
}

void SelectFase() {
    system("cls");
    printf("     \"Menu de Fases\"\n\n      Ir para a Fase 1\n      Ir para a Fase 2\n      Ir para a Fase 3\n      Ir para o Boss\n\n      Voltar ao Menu principal\n");
    SetaUpDown(2, 3, 6, 1, "->", "  ");

    switch (opcao){
        case 1:
            system("cls");
            printf("   Você escolheu ir para a Fase 1.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 1...\n");
            Sleep(1500);
            system("cls");
            Fase1();
        case 2:
            system("cls");
            printf("   Você escolheu ir para a Fase 2.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 2...\n");
            Sleep(1500);
            system("cls");
            PlaySound(TEXT("Fases.wav"), NULL,SND_ASYNC|SND_LOOP);
            Fase2();
        case 3:
            system("cls");
            printf("   Você escolheu ir para a Fase 3.\n");
            Sleep(1000);
            printf("   Iniciando a Fase 3...\n");
            Sleep(1500);
            system("cls");
            PlaySound(TEXT("Fases.wav"), NULL,SND_ASYNC);
            Fase3();
        case 4:
            system("cls");
            printf("   Você escolheu ir para a Fase do Boss.\n");
            Sleep(1000);
            printf("   Iniciando o Boss...\n");
            Sleep(1500);
            system("cls");
            BossEsfinge();
        case 6:
            main();
        default:
            printf("  Opção inválida, tente outra");
            Sleep(1000);
            SelectFase();
    }
}

void Quit() {
    system("cls");
    printf("\aSaindo...\n");
    Sleep(800);
    exit(0);
}

void Anubis() { // Em breve!!!
    system("cls");
    printf("Anúbis em construção, você será direcionado para o menu!\n");
    system("pause");
    main();
}

void GameOver() {
    char GameOver[] = "   Game Over";
    SlowText(GameOver);
    Sleep(2000);
    system("cls");
    Anubis();
}

void Player() {
    system("cls");
    printf("  Por favor, não aperte nada enquanto o texto é digitado em sua tela.\n");
    printf("  Por favor, não use caractere especial\n\n");
    printf("  Digite o nome do Arqueólogo: ");
    fflush(stdin);
    gets(NamePlayer);
    KbLore:
        coordxy(0,5);
        printf("\n\n Você deseja pular a História? \n   Aperte S para Sim.\n   Aperte N para Não.\n");
        if (kbhit) {KeyPress=getch();}
        if (KeyPress == 110) {Lore();}
        if (KeyPress == 115) {Fase1();}
        else {goto KbLore;}
}

void Lore() {
    system("cls");
    char Texto1[2000] = "   Há muitas eras, no ano 51 A.C, em algum lugar do Egito antigo acontecia uma grande batalha, uma guerra \n\n civil que parecia não ter fim. Em meio a todo aquele caos algo brilhava nos céus, e seu brilho ficava cada vez \n\n mais intenso e mais próximo, até que esse misterioso brilho se depara com o chão, causando um grande alvoroço em \n\n meio aquelas terras. Todos se esquecem por um minuto daquela guerra e decidem ir ver o que era aquilo. \n\n Depois de um tempo alguns dos soldados descobrem que aquilo era um amuleto ainda intacto, mesmo depois daquela \n\n enorme queda, e sem saber dos seus efeitos acidentalmente um dos soldados aciona esse amuleto, fazendo com que ele \n\n revelasse um poder desconhecido que era capaz de mudar toda a natureza humana. O medo assolava a todos que ali \n\n estavam presentes, muitos fugiram e os que ficaram decidiram que aquele amuleto era perigoso demais para a posse de \n\n qualquer pessoa, e em um ato de desespero construíram uma enorme pirâmide em volta do amuleto com diversas armadilhas. \n\n   Depois de séculos, lendas foram criadas e todos chamavam aquele amuleto desconhecido de O olho de Osíris. \n\n   Ninguém se atrevia a entrar naquela pirâmide, pois além das armadilhas, muitos diziam que os antigos designaram \n\n um guardião para a proteção do amuleto, mas a ganancia humana é grande demais, e em algum dia alguém tentara \n\n tomar posse desse poderoso artefato. Essa é a lenda que é contada até os dias de hoje.\n\n";
    char Texto2[] = "  Vocé é um arqueólogo conhecido como";
    char Texto3[] = "ao estudar está lenda você decide ir em busca deste artefato antigo...\n\n  Essa será um jornada tortuosa, e para enfim alcançar o antigo artefato, você terá que passar pelos mais difíceis \n\n desafios... \n\n";
    char TextFase1[] = "  Você entra na piramide e logo se depara com o primeiro desafio, uma porta com um tipo de tabela com peças faltando, \n\n sem saber o que fazer você começa a andar pela sala.\n\n Andando pela sala você encontra uma sacola com 6 letras F's e duas letras V's, depois de encontrar está sacola você \n\n decide voltar para a porta, ao voltar você logo percebe o que terá que fazer, você terá que colocar essas letras da \n\n sacola na porta para passar \n\n";

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

void Fase1() {
    system("cls");
    PlaySound(TEXT("Fases.wav"), NULL,SND_ASYNC|SND_LOOP);
    int Acertos = 0, Vs = 2, Fs = 6;
    Tabelas:
    system("cls");
    printf(" Você então começa a completar a tabela...\n");
    coordxy(0,6);
    printf("\t\t\t\t  ========================================\n");
    printf("\t\t\t\t  |   A   B (A^B) B' (B'^A) (A^B)^(B'^A) |\n");
    printf("\t\t\t\t  |       F       V              F       |\n");
    printf("\t\t\t\t  |   F   V   F   F     F                |\n");
    printf("\t\t\t\t  |       F   F   V     V                |\n");
    printf("\t\t\t\t  |   V       V         F        F       |\n");
    printf("\t\t\t\t  ========================================\n\n O que você deseja colocar nesta parte da tabela?");
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
    printf("\n\n Inventário\n  Total de F: %d\n  Total de V: %d", Fs, Vs);
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
            printf("Você errou!");
            Sleep(2000);
            Anubis();
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
            char NextFase[] = " A porta se abre e você consegue ir pra próxima sala.";
            SlowText(NextFase);
            fflush(stdin);
            Sleep(1000);
            system("cls");
            Acertos++;
            Fase2();
        } else {
            coordxy(2,22);
            printf("Você errou!");
            Sleep(2000);
            Anubis();
        }
    }
}

void ErrorFase2() {
    char ErroPiso[] ="   Você pisou em um lugar que não era seguro, o chão desmoronou, e você morreu com a queda.\n";
    SlowText(ErroPiso);
    Sleep(2000);
    GameOver();
}

void Fase2() {
    int Acertos = 0;
    char Text1[] = "   Você se depara com uma entrada, anda até ela e quando está chegando, o chão começa a tremer. De repente\nvocê percebe que alguns pisos não tremem e eles serão o seu caminho até a entrada.\n";
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
        printf("\n\t\t\t\t\t\====================================\n\t\t\t\t\t|  1         2         3         4 |\n\t\t\t\t\t|        Posição do jogador        |\n\t\t\t\t\t====================================\n");
        SetaLeftRight(41, 9, 4, 10, ">", " ");

        switch (opcao){
            case 1:
                if (Acertos == 0) {
                    char Acerto1[] ="   Você acertou e passou para o próximo piso           \n";
                    Acertos++;
                    SlowText(Acerto1);
                    goto Acerto;
                } else {
                    ErrorFase2();
                }
            case 2:
                if (Acertos == 2) {
                    char Acerto3[] = "   Você acertou, por pouco!                            \n";
                    Acertos++;
                    SlowText(Acerto3);
                    goto Acerto;
                } else {
                    ErrorFase2();
                }
            case 3:
                if (Acertos == 3) {
                    char Acerto4[] = "   Você finalmente passou sem cair em nenhuma armadilha\n";
                    SlowText(Acerto4);
                    Sleep(3000);
                    system("cls");
                    Fase3();
                } else {
                    ErrorFase2();
                }
            case 4:
                if (Acertos == 1) {
                    char Acerto2[] = "   Você acertou, tome cuidado com os pisos falsos      \n";
                    Acertos++;
                    SlowText(Acerto2);
                    goto Acerto;
                } else {
                    ErrorFase2();
                }
        }
}

void cenario() {
    system("cls");
    char Texto1[] = "   Depois de passar pela esfinge você chega a última sala da pirâmide. Nota-se que a sala \n\n está vazia, você acha isso estranho, será que todo esse sacrifício foi feito em vão?,\n\n de repente você escuta uma voz sussurrante dizendo: “O que você procura não está aqui,\n\n mas posso te dizer como encontrar, siga meus conselhos, você não tem muito tempo”.\n\n Sem entender o que estava acontecendo você segue o caminho da voz.";
    SlowText(Texto1);
    Sleep(15000);
    cenario1();
}

void cenario1() {
    system("cls");
    printf("Em Construção\n\n");
    system("pause");
    main();
}

void Fase3() {
    char Text1Fase3[] = "   Você passa pela entrada da segunda fase e observa que há outra passagem, você anda até ela e de repente a entrada \n\n se fecha e você ouve um barulho intenso, uma enorme esfinge feita de areia se ergue diante de você.\n\n";
    char Text2Fase3[] = "   \"Esfinge: Eu sou a última porta para o seu destino, responda corretamente meu enigma e sua passagem será liberada.\"\n\n";
    char Text3Fase3[] = "   Esfinge: Eu nunca fui e sempre poderei ser, ninguém jamais me viu ou verá, mas sou a certeza de todos os que vivem e que respiram, quem sou eu?: ";
    SlowText(Text1Fase3);
    SlowText(Text2Fase3);
    SlowText(Text3Fase3);
    fflush(stdin);
    gets(RespostaChar);
    if ((strcasecmp (RespostaChar, "amanha")== 0)||(strcasecmp (RespostaChar, "futuro")== 0)) {
        char Text4Fase3[] = "\n   Você acertou o meu enigma, eu te concedo a passagem para a próxima sala!\n";
        SlowText(Text4Fase3);
        fflush(stdin);
        Sleep(4000);
        system("cls");
        cenario();

    } else {
       printf("\nVocê errou, agora meu enfrente!!!\n\n");
       system("pause");
       BossEsfinge();
    }
}

void EsfingeImage() {
    printf("\n\t\t......................................................................\n\t\t............................'',;;::::;,'..............................\n\t\t..................'',;::cllooooddodxxxdolllcc::;,''...................\n\t\t...............,coodxxxddxxddddxddxkkxxxxxxxxxxxxdlc:,'...............\n\t\t..........'',,:xOkddxxxxkkxxxxxxodkkkkxkkkOOkkxxxdllol:;,,'''.........\n\t\t.....'',,;;,;cxOkkkxdddxkkOOkkOkddxxkkOO00000Oxddoododdc;;;;;;,''.....\n\t\t..',,;;;;;;;lkOOkkkkxdddxO000OOOxolldkO0KKKK0kxdodddodddl::::;;::;,'..\n\t\t,;;;;;;;;;;lO0OOkkkkxddookOOOkkkkkOOOO000000kxdddxxdddddxl:::::::::::;\n\t\t::;;;;;;;:lk0OOOkOOOkxolldxkxdoodkOOkkxxkOOOkdddxkkxdoodxxoccccccccccc\n\t\t::;;;;:::lkOOOkkOOOOOkdocclol::;;okOko:;:ldxdxxxOkkkkxddxxxocllllccccc\n\t\t:;;;::::lxOOOkkkkkkddxdolcllllccclkOkxdlcloddxkkdodxxxxdxkOxolllllllll\n\t\t:;;:::clx00OkkkkkkdldxdodxxkkOOxlldxkO00Ok0000OxdlodxxddxxkOkoloooooll\n\t\t::::cccdO00Okkkxxxdx0OoclxkOOOOxlcccldk000KK0OkkOkooxxddxkkOOkoloooooo\n\t\t:::cccok00OOxxkxxxocoxo::coxxkkoloxxdodO000OOkxxl:coddxxkkOOOOxooooooo\n\t\t::ccclxOOOOkkxxxxxxdolc:;;cloddlloooddxkOkkkxxdoldxxdxxkkkOOOOkdlooooo\n\t\t:ccllokOOOOOkxxxxkkxkko:;;:coo:,,;;::cloxkxxddxxkxxxxxkkkkOOOOOxoooooo\n\t\tcccllok0000Okkkkkkkkkkxc;,,;cooccclooddkkxdoookOkkkkkkOOOOOOOOOxoloooo\n\t\tcccllldO00000OOkkkkkkkkd;,'';:ldxkOO00OOkoc:cdOOOOOOOO00000000kdlloooo\n\t\tccllooloxO000OOkkkkkkkkxl'...:odkkO00000x;.'ck0OOO0OO0000000Odlllloooo\n\t\tcllooodolox0OOOkkxkxxxxxdc,..:ddkO000K00d,;lxOOOOOOOO00O00Oocccllllooo\n\t\tlllooddddlldkOkkkxxxxxxxxo:;,cdxkO00KK00kodxOOOOOOO00OO00Odlcccclllllo\n\t\tlllooddddxxddkOkkxdddddddl:;;lxxkO000K00kdxkOOOOOOOOOO00OOOOdc:cclllll\n\t\tllloooooodkOkdkOOkxddooool:;:oxxkOO00K00OxkOkOOOOOOOOOOOO00Oxc:cccllll\n\t\tcllooooodxO00kxk0OOkxdollll::oddxkkOOOkO0kkkxkOOOOO0OOOO000Okl:::cccll\n\t\tcllooooodkO000kkO00Oxolllcll;''...''',;;lxkxdkOkkOOOOOO0000Okl:::cccll\n\t\tlloooooodkO000OkkO0Oxollc:coc.      ....ckOxxOkkkkOOOOO000OOko::::cccl\n\t\tllooollodkOO000kkOOOxoccc:cll:.       .ckOkdxOkkkkOOOO00OOOkxo::::cccl\n\t\tlllllllodkO0000OkkOOdlccc::lcc;.     .:kOkkdxOkkkOOOkO0OOkkxxdc::::ccc\n\t\tclllllloxkO00000kxkkdlccc::ccc:'.   .;dkOOxoxOkkkkkxxOOOOkxxxdc::::ccc\n\t\tclllllloxO0000000kddolccc:;:cc:,',codkkOOOxoxOkkxddxOOOOkkkkxdl:::cccc\n\t\tclllllloxO00000000Oxoollcc:llllldkOOOOOOO0kdoodddxkO00OOkkkkxdl::ccccc\n\t\tlllllcldkO00000K0000OOOkkkOOkkkkOOOOOOO0000OOOO000OO000Okkkxddl:::cccc");
}

void BossEsfinge() {
    system("cls");
    int VidaEsfinge = 500;
    printf("\t\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|/////////////////////////|%d", VidaEsfinge);
    EsfingeImage();
    printf("\n Que animal anda pela manhã sobre quatro patas, a tarde sobre duas e a noite sobre três? \n\n   O Gato \n   O Chachorro \n   O Homem");
    SetaUpDown(36, 0, 3, 1, "->", "  ");

    if (opcao == 3) {
        system("cls");
        VidaEsfinge -= 100;
        printf("\t\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|////////////////////-----|%d", VidaEsfinge);
        EsfingeImage();
        printf("\n Por que seria o homem? \n\n   Porque o homem é um bípede \n   Porque o homem não quer mais viver uma mentira \n   Porque na infância o homem engatinha \n   Porque na infância o homem pensa muito");
        SetaUpDown(36, 0, 4, 1, "->", "  ");

        if (opcao == 3) {
            system("cls");
            VidaEsfinge -= 100;
            printf("\t\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|///////////////----------|%d", VidaEsfinge);
            EsfingeImage();
            printf("\n E o que mais? \n\n   Na idade adulta ele anda ereto \n   Essa é toda a resposta \n   Não tenho tempo para essas questões filosóficas, me deixe passar \n   Não idade adulta ele pensa muito, e pensar nos faz andar");
            SetaUpDown(36, 0, 4, 1, "->", "  ");

            if (opcao == 1) {
                system("cls");
                VidaEsfinge -= 100;
                printf("\t\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|//////////---------------|%d", VidaEsfinge);
                EsfingeImage();
                printf("\n Mais alguma coisa? \n   Sim, na velhice o homem necessita de uma bengala para andar \n   Não, é apenas essa a resposta", VidaEsfinge);
                SetaUpDown(35, 0, 2, 1, "->", "  ");

                if (opcao == 1) {
                    system("cls");
                    VidaEsfinge = 0;
                    printf("\t\t\t\t\t\tVida da Esfinge\n\t\t\t\t\t|-------------------------|%d", VidaEsfinge);
                    EsfingeImage();
                    printf("\n\nVocê me venceu, como conseguiu?\n");
                    system("pause");
                    cenario();
                } else {
                    Anubis();
                }
            } else {
                Anubis();
            }
       } else {
            Anubis();
        }
    } else {
        Anubis();
    }
}

