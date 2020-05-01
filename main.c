#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

char RespostaChar[20];
char NamePlayer[20];
int KeyPress,b,L,L2,Password,opcao;

void coordxy(int x,int y)
{
    COORD Mouse;
    Mouse.X = x;
    Mouse.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Mouse);
}

void main()
{
    setlocale(LC_ALL,"Portuguese");
    do{
        opcao=0;
        L=2;L2=2;b=2;
        system("cls");
        printf("     \"Menu de op��es\"\n\n      Novo Jogo \n      Escolher Fase\n\n      Sair\n");
        do
        {
            coordxy(3,L);
            printf("->");
            coordxy(0,6);
            if(kbhit){KeyPress=getch();}
            if(KeyPress == 80 && b < 5){L2=L;L++;b++;}
            if(KeyPress == 72 && b > 2){L2=L;L--;b--;}
            if(L!=L2){coordxy(2,L2);printf("    \n     ");L2=L;}
            if (KeyPress == 27) {Quit();}
            if(KeyPress == 13){opcao=b-1;}
        }while(opcao == 0);
    switch (opcao){
        case 1:
            system("cls");
            Player();
        case 2:
            system("cls");
            printf("Este � o menu do desenvolvedor, por favor digite sua senha: ");
            scanf("%d", &Password);
            if (Password == 1234) {
                printf("Verificando...\n");
                Sleep(1000);
                printf("Voc� ser� direcionado para o menu de escolha de fase, por favor aguarde.");
                Sleep(2000);
                system("cls");
                SelectFase();
            } else {
                printf("Verificando...\n");
                Sleep(1000);
                printf("Senha incorreta.");
                Sleep(700);
                system("cls");
                main();
            }
        case 4:
            Quit();
        default:
            printf("Essa op��o n�o existe, por favor tente uma nova.\n");
            Sleep(1500);
        }
    }while(opcao!=2);
}


void SelectFase()
{
    int Fase;
    do{
        Fase=0;
        L=2;L2=2;b=2;
        system("cls");
        printf("     \"Menu de Fases\"\n\n     Ir para a Fase 1\n     Ir para a Fase 2\n     Ir para a Fase 3\n     Ir para o Boss\n\n     Voltar ao Menu principal\n");
        do
        {
            coordxy(3,L);
            printf("->");
            coordxy(0,8);
            if(kbhit){KeyPress=getch();}
            if(KeyPress == 80 && b < 7){L2=L;L++;b++;}
            if(KeyPress == 72 && b > 2){L2=L;L--;b--;}
            if(L!=L2){coordxy(1,L2);printf("    ");L2=L;}
            if (KeyPress == 27) {Quit();}
            if(KeyPress == 13){Fase=b-1;}
        }while(Fase == 0);
    switch (Fase){
        case 1:
            system("cls");
            printf("Voc� escolheu ir para a Fase 1.\n");
            Sleep(1000);
            printf("Iniciando a Fase 1...\n");
            Sleep(1500);
            system("cls");
            Fase1();
        case 2:
            system("cls");
            printf("Voc� escolheu ir para a Fase 2.\n");
            Sleep(1000);
            printf("Iniciando a Fase 2...\n");
            Sleep(1500);
            system("cls");
            Fase2();
        case 3:
            system("cls");
            printf("Voc� escolheu ir para a Fase 3.\n");
            Sleep(1000);
            printf("Iniciando a Fase 3...\n");
            Sleep(1500);
            system("cls");
            Fase3();
        case 4:
            system("cls");
            printf("Voc� escoleu ir para a Fase do Boss.\n");
            Sleep(1000);
            printf("Iniciando o Boss...\n");
            Sleep(1500);
            system("cls");
            Boss();
        case 6:
            main();
        default:
            printf("Op��o inv�lida, tente outra");
            Sleep(1000);
        }
    }while(Fase!=2);
}

void Quit()
{
    system("cls");
    printf("\aSaindo...\n");
    Sleep(800);
    exit(0);
}

void Player()
{
    system("cls");
    printf("Por favor, n�o use espa�o nem caractere especial\n");
    printf("Digite o nome do Arque�logo: ");
    gets(NamePlayer);
    system("cls");
}

void Fase1()
{
    printf("   H� muitas eras no ano 51 A.C, em algum lugar do Egito antigo acontecia uma grande batalha, uma guerra \n\n civil que parecia n�o ter fim. Em meio a todo aquele caos algo brilhava nos c�us, e seu brilho ficava cada vez \n\n mais intenso e mais pr�ximo, at� que esse misterioso brilho se depara com o ch�o, causando um grande alvoro�o em \n\n meio aquelas terras. Todos se esquecem por um minuto daquela guerra e decidem ir ver o que era aquilo. \n\n Depois de um tempo alguns dos soldados descobrem que aquilo era um amuleto ainda intacto, mesmo depois daquela \n\n enorme queda, e sem saber dos seus efeitos acidentalmente um dos soldados aciona esse amuleto, fazendo com que ele \n\n revelasse um poder desconhecido que era capaz de mudar toda a natureza humana. O medo assolava a todos que ali \n\n estavam presentes, muitos fugiram e os que ficaram decidiram que aquele amuleto era perigoso demais para a posse de \n\n qualquer pessoa, e em um ato de desespero constru�ram uma enorme pir�mide em volta do amuleto com diversas armadilhas. \n\n Depois de s�culos, lendas foram criadas e todos chamavam aquele amuleto desconhecido de O olho de Os�ris e ningu�m se \n\n atrevia a entrar naquela pir�mide, pois al�m das armadilhas, muitos diziam que os antigos designaram um guardi�o para \n\n a prote��o do amuleto, mas a ganancia humana � grande demais, e em algum dia algu�m tentara tomar posse desse poderoso \n\n artefato. Essa lenda � contada at� os dias de hoje.\n");
    coordxy(81,28);
    printf("Aperte espa�o para pular a hist�ria ou\n");
    coordxy(81,29);
    printf("Aperte enter para continuar a hist�ria");
    if (kbhit) {KeyPress=getch();}
    if (KeyPress == 13) {
        system("cls");
        printf("  Voc� � um arque�logo conhecido como %s, voc� est� em busca de um artefato antigo, mais conhecido como \n'O olho de Os�ris'... \n", NamePlayer);
        printf("\n  Essa jornada ser� tortuosa, e para enfim alcan�ar o antigo artefato, voc� ter� que passar pelos mais dif�ceis \ndesafios... \n");
        coordxy(81,29);
        printf("Aperte enter para continuar a hist�ria");
        if (kbhit) {KeyPress=getch();}
        if (KeyPress == 13) {
            system("cls");
            do{
                Skipped:
                opcao=0;
                L=18;L2=12;b=2;
                printf("\n  Voc� entra na piramide e logo se depara com o primeiro desafio, uma sala com 3 portas, sem saber o que fazer voc� \ncome�a a andar pela sala.\n\n");
                printf(" Andando pela sala voc� v� que tinha uma escrita escondida em um dos pilares da piramide, voc� se aproxima para ver o \nque �, nesse pilar voc� v� o seguinte s�mbolo: (A^B) ^ (B'^A)\n\n Sem saber o que significa voc� volta para onde estavam as portas pra tentar entender, logo voc� percebe que\n nas portas tem alguns s�mbolos parecidos com qual voc� tinha encontrado, voc� ent�o percebe que o que voc� tinha\n lido vai te ajudar a descobrir por qual porta voc� deve seguir");
                coordxy(2,15);
                printf("====================================   ======================================   =====================================\n");
                printf("  |         Porta da esquerda        |   |            Porta da meio           |   |          Porta da direita         |\n");
                printf("  | A B (A^B) B' (B'^A) (A^B)^(B'^A) |   |   A B (AvB) B' (B'vA) (AvB)^(B'vA) |   |  A B (A^B) B' (B'^A) (A^B)^(B'^A) |\n");
                printf("  | F F   V   V    V         V       |   |  F F   F   V     V        F        |   |  F F   F   V     F        F       |\n");
                printf("  | F V   F   V    F         V       |   |  F V   V   F     F        F        |   |  F V   F   F     F        F       |\n");
                printf("  | V F   V   F    F         V       |   |  V F   V   V     V        V        |   |  V F   F   V     V        F       |\n");
                printf("  | V V   F   V    V         V       |   |  V V   V   F     V        V        |   |  V V   V   F     F        F       |\n");
                printf("  ====================================   ======================================   =====================================\n\n");
                printf("Apenas uma das portas � a correta, fa�a sua escolha sabiamente.\n");
                do{
                    coordxy(L,L2);
                    printf("|");
                    coordxy(L,L2+1);
                    printf("V");
                    coordxy(0,24);
                    if(kbhit){KeyPress=getch();}
                    if (KeyPress == 77 && b < 4) {coordxy(L,L2-1);printf(" ");coordxy(L,L2);printf(" ");coordxy(L,L2+1);printf(" ");L=L+41;b++;}
                    if (KeyPress == 75 && b > 2) {coordxy(L,L2-1);printf(" ");coordxy(L,L2);printf(" ");coordxy(L,L2+1);printf(" ");L=L-41;b--;}
                    if (KeyPress == 27) {Quit();}
                    if(KeyPress == 13){opcao=b-1;}
                }while(opcao == 0);
            switch (opcao){
                case 1:
                    printf("Voc� acaba de entrar em um labirinto, e percebe que n�o consegue encontrar a saida...\n");
                    Sleep(5000);
                    printf("Voc� ficou perdido para todo o sempre\n");
                    Sleep(2000);
                    printf("\aGame over\n");
                    Sleep(2000);
                    system("cls");
                    main();
                case 2:
                    printf("Voc� caiu em um po�o que n�o possui fundo!                     \n");
                    Sleep(2000);
                    printf("Voc� caiu por toda a eternidade...                             \n");
                    Sleep(2000);
                    printf("Game over\n");
                    Sleep(2000);
                    system("cls");
                    main();
                case 3:
                    printf("Voc� passou de fase!                                           \n");
                    Sleep(2000);
                    system("cls");
                    Fase2();
                }
            }while(opcao!=2);
        }if (KeyPress == 32) {system("cls");goto Skipped;}
        if (KeyPress == 27) {Quit();}
    }if (KeyPress == 32) {system("cls");goto Skipped;}
    if (KeyPress == 27) {Quit();}
}

void Fase2()
{
    int Acertos = 0;
    Acerto:
    do{
        opcao=0;
        L=41;b=2;
        coordxy(2,0);
        printf("Voc� se depara com uma entrada, anda at� ela e quando est� chegando, o ch�o come�a a tremer. De repente\nvoc� percebe que alguns pisos n�o tremem e eles ser�o o seu caminho at� a entrada.\n");
        printf("\n  Para chegar � entrada voc� deve no primeiro piso ir ao m�ximo para a esquerda, no pr�ximo piso voc� deve quadruplicar\na sua posi��o atual, no pr�ximo voc� deve dividir por dois a sua posi��o atual e no �ltimo piso voc� deve somar um a\nsua posi��o atual.\n");
        if (Acertos == 0){coordxy(49,7);printf("== Primeiro Piso == \n");}
        if (Acertos == 1){coordxy(49,7);printf("== Segundo Piso == \n");}
        if (Acertos == 2){coordxy(49,7);printf("== Terceiro Piso == \n");}
        if (Acertos == 3){coordxy(49,7);printf(" == Quarto Piso ==  \n");}
        coordxy(19,7);
        printf("\n\t\t\t\t\t\====================================\n\t\t\t\t\t|  1         2         3         4 |\n\t\t\t\t\t|        Posi��o do jogador        |\n\t\t\t\t\t====================================\n");
        do{
            coordxy(L,9);
            printf(">");
            coordxy(0,20);
            if(kbhit){KeyPress=getch();}
            if (KeyPress == 77 && b < 5) {coordxy(L,9);printf(" ");L=L+10;b++;}
            if (KeyPress == 75 && b > 2) {coordxy(L,9);printf(" ");L=L-10;b--;}
            if (KeyPress == 27) {Quit();}
            if(KeyPress == 13){opcao=b-1;}
        }while(opcao == 0);
    switch (opcao){
        case 1:
            if (Acertos == 0)
            {
                printf("Voc� acertou e passou para o pr�ximo piso           \n");
                Acertos++;
                goto Acerto;
            } else {
                printf("Voc� pisou em um lugar que n�o era seguro, o ch�o desmoronou, e voc� morreu com a queda.\n");
                Sleep(4000);
                printf("Game over\n");
                Sleep(1000);
                system("cls");
                main();
            }
        case 2:
            if (Acertos == 2)
            {
                printf("Voc� acertou, por pouco!                            \n");
                Acertos++;
                goto Acerto;
            } else {
                printf("Voc� pisou em um lugar que n�o era seguro, o ch�o desmoronou, e voc� morreu com a queda.\n");
                Sleep(4000);
                printf("Game over\n");
                Sleep(1000);
                system("cls");
                main();
            }

        case 3:
            if (Acertos == 3)
            {
                printf("Voc� finalmente passou sem cair em nenhuma armadilha\n");
                Sleep(3000);
                system("cls");
                Fase3();
            } else {
                printf("Voc� pisou em um lugar que n�o era seguro, o ch�o desmoronou, e voc� morreu com a queda.\n");
                Sleep(4000);
                printf("Game over\n");
                Sleep(1000);
                system("cls");
                main();
            }

        case 4:
            if (Acertos == 1)
            {
                printf("Voc� acertou, tome cuidado com os pisos falsos      \n");
                Acertos++;
                goto Acerto;
            } else {
                printf("Voc� pisou em um lugar que n�o era seguro, o ch�o desmoronou, e voc� morreu com a queda.\n");
                Sleep(4000);
                printf("Game over\n");
                Sleep(1000);
                system("cls");
                main();
            }
        }
    }while(opcao!=2);
}

void Fase3()
{
    printf("Voc� passa pela entrada da segunda fase e observa que h� outra entrada, voc� anda at� ela e de repente a entrada se \nfecha e voc� ouve uma voz.\n");
    puts("Eu sou o Deus daquilo que traz a tristeza e o medo, mas sempre chego na hora certa, as vezes venho depois de uma doen�a,\ne outras, depois de um ato de viol�ncia e tamb�m sou guardi�o daquilo que voc� procura, me diga do que eu sou Deus e \nsua passagem ser� liberada.\n");
    printf("Me diga, eu sou Deus da: ");
    scanf("%s", &RespostaChar);
    if ((strcmp (RespostaChar, "MORTE")== 0)||(strcmp (RespostaChar, "morte")== 0)||(strcmp (RespostaChar, "Morte")== 0)) {
        printf("\n");
        printf("Voc� descobriu do que eu sou Deus, agora me enfrente e ver� o meu poder!\n");
        Sleep(4000);
        system("cls\n");
        Boss();
    }else {
        printf("\n");
        printf("Se voc� n�o sabe que tipo de Deus eu sou voc� n�o � digno de me enfrentar, saia da minha pir�mide!\n");
        Sleep(6000);
        system("cls\n");
        main();
    }
}

void Boss()
{
    do{
        opcao=0;
        L=18;b=2;
        coordxy(2,0);
        puts("An�bis: Voc� chegou at� aqui, mas daqui voc� n�o passa!\nAn�bis: Tente me vencer, voc� precisar� de sorte, muita sorte!\n");
        printf("An�bis � um inimigo extremamete poderoso, e para derrot�-lo voc� deve encontrar uma arma poderosa.");
        Sleep(10);
        system("cls");
        printf("Voc� vai em busca de sua arma para derrotar An�bis, mas derrepente voc� escuta sua voz.\n\n");
        printf("An�bis: Voc� nunca saber� o que � (A->B)<->(B'->A').");
        Sleep(80);
        system("cls");
        printf("Encontre pela sala o que � a express�o dita por An�bis.\n\n");
        printf("Voc� v� duas pe�as, uma em sua direita e outra em sua esquerda.\nO que voc� deseja fazer ?\n\n");
        printf("\n\t\t\===================================================================================\n\t\t|   Virar para a esquerda       Seguir em frente            Virar para a direita  |\n\t\t===================================================================================\n");
        do{
            coordxy(L,7);
            printf(">");
            coordxy(0,20);
            if(kbhit){KeyPress=getch();}
            if (KeyPress == 77 && b < 4) {coordxy(L,7);printf(" ");L=L+28;b++;}
            if (KeyPress == 75 && b > 2) {coordxy(L,7);printf(" ");L=L-28;b--;}
            if (KeyPress == 27) {Quit();}
            if(KeyPress == 13){opcao=b-1;}
            }while(opcao == 0);
        switch(opcao){
            case 1:
                opcao=0;
                L=18;b=2;
                coordxy(2,0);
                system("cls");
                printf("Voc� encontrou uma pe�a escrita Contradi��o, o que voc� deseja fazer ?\n");
                printf("\n\t\t\=================================================================\n\t\t|   Pegar a pe�a e usar         Essa n�o � a pe�a para a arma   |\n\t\t=================================================================\n");
                do{
                    coordxy(L,3);
                    printf(">");
                    coordxy(0,20);
                    if(kbhit){KeyPress=getch();}
                    if (KeyPress == 77 && b < 3) {coordxy(L,3);printf(" ");L=L+28;b++;}
                    if (KeyPress == 75 && b > 2) {coordxy(L,3);printf(" ");L=L-28;b--;}
                    if (KeyPress == 27) {Quit();}
                    if(KeyPress == 13){opcao=b-1;}
                }while(opcao == 0);
            switch(opcao){
                case 1:
                    system("cls");
                    printf("Essa n�o � a pe�a correta para montar a arma\n\n");
                    Sleep(5000);
                    printf("Game over");
                    Sleep(2000);
                    system("cls");
                    main();
                case 2:
                    printf("Voc� descartou uma pe�a e voltou para o inicio fase.");
                    Sleep(5000);
                    system("cls");
                    Boss();
                }
        case 2:
            system("cls");
            printf("Vo�� n�o conseguiu reunir as pe�as necess�rias para derrotar An�bis.\nEle arrancou a sua cabe�a!!\n\n");
            Sleep(6000);
            printf("Game over");
            Sleep(2000);
            main();

        case 3:
            do{
                system("cls");
                opcao=0;
                L=18;b=2;
                coordxy(2,0);
                system("cls");
                printf("Voc� encontrou uma pe�a escrita Tautologia, o que voc� deseja fazer ?\n");
                printf("\n\t\t\=================================================================\n\t\t|   Pegar a pe�a e usar         Descartar   |\n\t\t=================================================================\n");
                do{
                    coordxy(L,3);
                    printf(">");
                    coordxy(0,20);
                    if(kbhit){KeyPress=getch();}
                    if (KeyPress == 77 && b < 3) {coordxy(L,3);printf(" ");L=L+28;b++;}
                    if (KeyPress == 75 && b > 2) {coordxy(L,3);printf(" ");L=L-28;b--;}
                    if (KeyPress == 27) {Quit();}
                    if(KeyPress == 13){opcao=b-1;}
                }while(opcao == 0);
            switch(opcao){
                case 1:
                    system("cls");
                    printf("Voc� conseguiu a pe�a correta para a arma.\nVoc� termina de montar a arma definitiva para derrotar An�bis.\n\n");
                    printf("Parab�ns %s, voc� venceu!!\n\n");
                    printf("Obrigado por jogar o Beta.");
                    Sleep(8000);
                    system("cls");
                    main();
                case 2:
                    system("cls");
                }
            }while(opcao!=2);
        }
    }while(opcao!=2);
}
