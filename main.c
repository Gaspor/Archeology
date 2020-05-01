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
        printf("     \"Menu de opções\"\n\n      Novo Jogo \n      Escolher Fase\n\n      Sair\n");
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
            printf("Este é o menu do desenvolvedor, por favor digite sua senha: ");
            scanf("%d", &Password);
            if (Password == 1234) {
                printf("Verificando...\n");
                Sleep(1000);
                printf("Você será direcionado para o menu de escolha de fase, por favor aguarde.");
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
            printf("Essa opção não existe, por favor tente uma nova.\n");
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
            printf("Você escolheu ir para a Fase 1.\n");
            Sleep(1000);
            printf("Iniciando a Fase 1...\n");
            Sleep(1500);
            system("cls");
            Fase1();
        case 2:
            system("cls");
            printf("Você escolheu ir para a Fase 2.\n");
            Sleep(1000);
            printf("Iniciando a Fase 2...\n");
            Sleep(1500);
            system("cls");
            Fase2();
        case 3:
            system("cls");
            printf("Você escolheu ir para a Fase 3.\n");
            Sleep(1000);
            printf("Iniciando a Fase 3...\n");
            Sleep(1500);
            system("cls");
            Fase3();
        case 4:
            system("cls");
            printf("Você escoleu ir para a Fase do Boss.\n");
            Sleep(1000);
            printf("Iniciando o Boss...\n");
            Sleep(1500);
            system("cls");
            Boss();
        case 6:
            main();
        default:
            printf("Opção inválida, tente outra");
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
    printf("Por favor, não use espaço nem caractere especial\n");
    printf("Digite o nome do Arqueólogo: ");
    gets(NamePlayer);
    system("cls");
    Fase1();
}

void Fase1()
{
    printf("   Há muitas eras no ano 51 A.C, em algum lugar do Egito antigo acontecia uma grande batalha, uma guerra \n\n civil que parecia não ter fim. Em meio a todo aquele caos algo brilhava nos céus, e seu brilho ficava cada vez \n\n mais intenso e mais próximo, até que esse misterioso brilho se depara com o chão, causando um grande alvoroço em \n\n meio aquelas terras. Todos se esquecem por um minuto daquela guerra e decidem ir ver o que era aquilo. \n\n Depois de um tempo alguns dos soldados descobrem que aquilo era um amuleto ainda intacto, mesmo depois daquela \n\n enorme queda, e sem saber dos seus efeitos acidentalmente um dos soldados aciona esse amuleto, fazendo com que ele \n\n revelasse um poder desconhecido que era capaz de mudar toda a natureza humana. O medo assolava a todos que ali \n\n estavam presentes, muitos fugiram e os que ficaram decidiram que aquele amuleto era perigoso demais para a posse de \n\n qualquer pessoa, e em um ato de desespero construíram uma enorme pirâmide em volta do amuleto com diversas armadilhas. \n\n Depois de séculos, lendas foram criadas e todos chamavam aquele amuleto desconhecido de O olho de Osíris e ninguém se \n\n atrevia a entrar naquela pirâmide, pois além das armadilhas, muitos diziam que os antigos designaram um guardião para \n\n a proteção do amuleto, mas a ganancia humana é grande demais, e em algum dia alguém tentara tomar posse desse poderoso \n\n artefato. Essa lenda é contada até os dias de hoje.\n");
    coordxy(81,28);
    printf("Aperte espaço para pular a história ou\n");
    coordxy(81,29);
    printf("Aperte enter para continuar a história");
    if (kbhit) {KeyPress=getch();}
    if (KeyPress == 13) {
        system("cls");
        printf("  Vocé é um arqueólogo conhecido como %s, você está em busca de um artefato antigo, mais conhecido como \n'O olho de Osíris'... \n", NamePlayer);
        printf("\n  Essa jornada será tortuosa, e para enfim alcançar o antigo artefato, você terá que passar pelos mais difíceis \ndesafios... \n");
        coordxy(81,29);
        printf("Aperte enter para continuar a história");
        if (kbhit) {KeyPress=getch();}
        if (KeyPress == 13) {
            system("cls");
            do{
                Skipped:
                opcao=0;
                L=18;L2=12;b=2;
                printf("\n  Você entra na piramide e logo se depara com o primeiro desafio, uma sala com 3 portas, sem saber o que fazer você \ncomeça a andar pela sala.\n\n");
                printf(" Andando pela sala você vê que tinha uma escrita escondida em um dos pilares da piramide, você se aproxima para ver o \nque é, nesse pilar você vê o seguinte símbolo: (A^B) ^ (B'^A)\n\n Sem saber o que significa você volta para onde estavam as portas pra tentar entender, logo você percebe que\n nas portas tem alguns símbolos parecidos com qual você tinha encontrado, você então percebe que o que você tinha\n lido vai te ajudar a descobrir por qual porta você deve seguir");
                coordxy(2,15);
                printf("====================================   ======================================   =====================================\n");
                printf("  |         Porta da esquerda        |   |            Porta da meio           |   |          Porta da direita         |\n");
                printf("  | A B (A^B) B' (B'^A) (A^B)^(B'^A) |   |   A B (AvB) B' (B'vA) (AvB)^(B'vA) |   |  A B (A^B) B' (B'^A) (A^B)^(B'^A) |\n");
                printf("  | F F   V   V    V         V       |   |  F F   F   V     V        F        |   |  F F   F   V     F        F       |\n");
                printf("  | F V   F   V    F         V       |   |  F V   V   F     F        F        |   |  F V   F   F     F        F       |\n");
                printf("  | V F   V   F    F         V       |   |  V F   V   V     V        V        |   |  V F   F   V     V        F       |\n");
                printf("  | V V   F   V    V         V       |   |  V V   V   F     V        V        |   |  V V   V   F     F        F       |\n");
                printf("  ====================================   ======================================   =====================================\n\n");
                printf("Apenas uma das portas é a correta, faça sua escolha sabiamente.\n");
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
                    printf("Você acaba de entrar em um labirinto, e percebe que não consegue encontrar a saida...\n");
                    Sleep(5000);
                    printf("Você ficou perdido para todo o sempre\n");
                    Sleep(2000);
                    printf("\aGame over\n");
                    Sleep(2000);
                    system("cls");
                    main();
                case 2:
                    printf("Você caiu em um poço que não possui fundo!                     \n");
                    Sleep(2000);
                    printf("Você caiu por toda a eternidade...                             \n");
                    Sleep(2000);
                    printf("Game over\n");
                    Sleep(2000);
                    system("cls");
                    main();
                case 3:
                    printf("Você passou de fase!                                           \n");
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
        printf("Você se depara com uma entrada, anda até ela e quando está chegando, o chão começa a tremer. De repente\nvocê percebe que alguns pisos não tremem e eles serão o seu caminho até a entrada.\n");
        printf("\n  Para chegar à entrada você deve no primeiro piso ir ao máximo para a esquerda, no próximo piso você deve quadruplicar\na sua posição atual, no próximo você deve dividir por dois a sua posição atual e no último piso você deve somar um a\nsua posição atual.\n");
        if (Acertos == 0){coordxy(49,7);printf("== Primeiro Piso == \n");}
        if (Acertos == 1){coordxy(49,7);printf("== Segundo Piso == \n");}
        if (Acertos == 2){coordxy(49,7);printf("== Terceiro Piso == \n");}
        if (Acertos == 3){coordxy(49,7);printf(" == Quarto Piso ==  \n");}
        coordxy(19,7);
        printf("\n\t\t\t\t\t\====================================\n\t\t\t\t\t|  1         2         3         4 |\n\t\t\t\t\t|        Posição do jogador        |\n\t\t\t\t\t====================================\n");
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
                printf("Você acertou e passou para o próximo piso           \n");
                Acertos++;
                goto Acerto;
            } else {
                printf("Você pisou em um lugar que não era seguro, o chão desmoronou, e você morreu com a queda.\n");
                Sleep(4000);
                printf("Game over\n");
                Sleep(1000);
                system("cls");
                main();
            }
        case 2:
            if (Acertos == 2)
            {
                printf("Você acertou, por pouco!                            \n");
                Acertos++;
                goto Acerto;
            } else {
                printf("Você pisou em um lugar que não era seguro, o chão desmoronou, e você morreu com a queda.\n");
                Sleep(4000);
                printf("Game over\n");
                Sleep(1000);
                system("cls");
                main();
            }

        case 3:
            if (Acertos == 3)
            {
                printf("Você finalmente passou sem cair em nenhuma armadilha\n");
                Sleep(3000);
                system("cls");
                Fase3();
            } else {
                printf("Você pisou em um lugar que não era seguro, o chão desmoronou, e você morreu com a queda.\n");
                Sleep(4000);
                printf("Game over\n");
                Sleep(1000);
                system("cls");
                main();
            }

        case 4:
            if (Acertos == 1)
            {
                printf("Você acertou, tome cuidado com os pisos falsos      \n");
                Acertos++;
                goto Acerto;
            } else {
                printf("Você pisou em um lugar que não era seguro, o chão desmoronou, e você morreu com a queda.\n");
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
    printf("Você passa pela entrada da segunda fase e observa que há outra entrada, você anda até ela e de repente a entrada se \nfecha e você ouve uma voz.\n");
    puts("Eu sou o Deus daquilo que traz a tristeza e o medo, mas sempre chego na hora certa, as vezes venho depois de uma doença,\ne outras, depois de um ato de violência e também sou guardião daquilo que você procura, me diga do que eu sou Deus e \nsua passagem será liberada.\n");
    printf("Me diga, eu sou Deus da: ");
    scanf("%s", &RespostaChar);
    if ((strcmp (RespostaChar, "MORTE")== 0)||(strcmp (RespostaChar, "morte")== 0)||(strcmp (RespostaChar, "Morte")== 0)) {
        printf("\n");
        printf("Você descobriu do que eu sou Deus, agora me enfrente e verá o meu poder!\n");
        Sleep(4000);
        system("cls\n");
        Boss();
    }else {
        printf("\n");
        printf("Se você não sabe que tipo de Deus eu sou você não é digno de me enfrentar, saia da minha pirâmide!\n");
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
        puts("Anúbis: Você chegou até aqui, mas daqui você não passa!\nAnúbis: Tente me vencer, você precisará de sorte, muita sorte!\n");
        printf("Anúbis é um inimigo extremamete poderoso, e para derrotá-lo você deve encontrar uma arma poderosa.");
        Sleep(3000);
        system("cls");
        printf("Você vai em busca de sua arma para derrotar Anúbis, mas derrepente você escuta sua voz.\n\n");
        printf("Anúbis: Você nunca saberá o que é (A->B)<->(B'->A').");
        Sleep(8000);
        system("cls");
        printf("Encontre pela sala o que é a expressão dita por Anúbis.\n\n");
        printf("Você vê duas peças, uma em sua direita e outra em sua esquerda.\nO que você deseja fazer ?\n\n");
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
            do {
                opcao=0;
                L=18;b=2;
                coordxy(2,0);
                system("cls");
                printf("Você encontrou uma peça escrita Contradição, o que você deseja fazer ?\n");
                printf("\n\t\t\=================================================================\n\t\t|   Pegar a peça e usar         Essa não é a peça para a arma   |\n\t\t=================================================================\n");
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
                    printf("Essa não é a peça correta para montar a arma\n\n");
                    Sleep(5000);
                    printf("Game over");
                    Sleep(2000);
                    system("cls");
                    main();
                case 2:
                    printf("Você descartou uma peça e voltou para o inicio fase.");
                    Sleep(5000);
                    system("cls");
                    Boss();
                }
            }while(opcao!=2);
        case 2:
            system("cls");
            printf("Voçê não conseguiu reunir as peças necessárias para derrotar Anúbis.\nEle arrancou a sua cabeça!!\n\n");
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
                printf("Você encontrou uma peça escrita Tautologia, o que você deseja fazer ?\n");
                printf("\n\t\t\=================================================================\n\t\t|   Pegar a peça e usar         Descartar   |\n\t\t=================================================================\n");
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
                    printf("Você conseguiu a peça correta para a arma.\nVocê termina de montar a arma definitiva para derrotar Anúbis.\n\n");
                    printf("Parabéns %s, você venceu!!\n\n", NamePlayer);
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
