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

void Testinho()
{
    int Fase,Acertos = 0;
    do{
        Tabelas:
        Fase=0;
        L=9;L2=2;b=2;
        system("cls");
        printf("\t\t  ========================================\n");
        printf("\t\t  |   A   B (A^B) B' (B'^A) (A^B)^(B'^A) |\n");
        printf("\t\t  |       F       V              F       |\n");
        printf("\t\t  |   F   V   F   F     F                |\n");
        printf("\t\t  |       F   F   V     V                |\n");
        printf("\t\t  |   V       V         F        F       |\n");
        printf("\t\t  ========================================\n\n");
        if (Acertos == 0) {
            coordxy(20,2);
            printf(">");
        }if (Acertos == 1) {
            coordxy(22,2);
            printf("F");
            coordxy(28,2);
            printf(">");
        } if (Acertos == 2) {
            coordxy(22,2);
            printf("F   F   F");
            coordxy(38,2);
            printf(">");
        }if (Acertos == 3) {
            coordxy(22,2);
            printf("F   F   F   V     F");
            coordxy(47,3);
            printf(">");
        } if (Acertos == 4) {
            coordxy(22,2);
            printf("F   F   F   V     F");
            coordxy(22,3);
            printf("F   V   F   F     F        F");
            coordxy(20,4);
            printf(">");
        }if (Acertos == 5) {
            coordxy(22,2);
            printf("F   F   F   V     F");
            coordxy(22,3);
            printf("F   V   F   F     F        F");
            coordxy(22,4);
            printf("V");
            coordxy(47,4);
            printf(">");
        }if (Acertos == 6) {
            coordxy(22,2);
            printf("F   F   F   V     F");
            coordxy(22,3);
            printf("F   V   F   F     F        F");
            coordxy(22,4);
            printf("V   F   F   V     V        F");
            coordxy(24,5);
            printf(">");
        }if (Acertos == 7) {
            coordxy(22,2);
            printf("F   F   F   V     F");
            coordxy(22,3);
            printf("F   V   F   F     F        F");
            coordxy(22,4);
            printf("V   F   F   V     V        F");
            coordxy(22,5);
            printf("V   V   V");
            coordxy(32,5);
            printf(">");
        }
        coordxy(6, 9);
        printf("V\n      F");
        do
        {
            coordxy(3,L);
            printf("->");
            coordxy(0,8);
            if(kbhit){KeyPress=getch();}
            if(KeyPress == 80 && b < 3){L2=L;L++;b++;}
            if(KeyPress == 72 && b > 2){L2=L;L--;b--;}
            if(L!=L2){coordxy(3,L2);printf("  ");L2=L;}
            if(KeyPress == 13){Fase=b-1;}
        }while(Fase == 0);
    switch (Fase){
        case 1:
            if (Acertos == 4) {
                system("cls");
                Acertos++;
                goto Tabelas;
            }if (Acertos == 6) {
                system("cls");
                Acertos++;
                goto Tabelas;
            } else {
                coordxy(2,12);
                printf("Você errou!");
                Sleep(2000);
                main();
            }
        case 2:
            if (Acertos == 0) {
                system("cls");
                Acertos++;
                goto Tabelas;
            }if (Acertos == 1) {
                system("cls");
                Acertos++;
                goto Tabelas;
            }if (Acertos == 2) {
                system("cls");
                Acertos++;
                goto Tabelas;
            }if (Acertos == 3) {
                system("cls");
                Acertos++;
                goto Tabelas;
            }if (Acertos == 5) {
                system("cls");
                Acertos++;
                goto Tabelas;
            }if (Acertos == 7) {
                coordxy(34,5);
                printf("F");
                coordxy(2,12);
                printf("Você passou de fase");
                Sleep(2000);
                system("cls");
                Acertos++;
                main();
            } else {
                coordxy(2,12);
                printf("Você errou!");
                Sleep(2000);
                main();
            }
        }
    }while(Fase!=2);
}
void Boss()
{
    do{
        opcao=0;
        L=18;b=2;
        coordxy(2,0);
        puts("Anúbis: Você chegou até aqui, mas daqui você não passa!\nAnúbis: Tente me vencer, você precisará de sorte, muita sorte!\n");
        printf("Anúbis é um inimigo extremamete poderoso, e para derrotá-lo você deve encontrar uma arma poderosa.");
        Sleep(10);
        system("cls");
        printf("Você vai em busca de sua arma para derrotar Anúbis, mas derrepente você escuta sua voz.\n\n");
        printf("Anúbis: Você nunca saberá o que é (A->B)<->(B'->A').");
        Sleep(80);
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
                    printf("Parabéns %s, você venceu!!\n\n");
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
