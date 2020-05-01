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
