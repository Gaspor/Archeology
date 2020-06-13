#include "Includes.h"

int KeyPress;
char NamePlayer[200];

char SlowText(char *Text) {
    int i, TimeText = 1;
    for (i = 0; Text[i] != '\0'; i++) {
        printf("%c",Text[i]);
        Sleep(TimeText);
    }
}

void Player(int Vida) {    // Nome do Player //
    int Vidas = Vida;
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
        if (KeyPress == 110) {Lore(Vidas);}
        if (KeyPress == 115) {Fase1(Vidas);}
        else {goto KbLore;}
}

void Lore(int Vida) {  // Hist�ria primeiro Cen�rio
    int Vidas = Vida;
    system("cls");
    char Texto1[20000] = "  No Egito antigo, h� muitas eras, antes da humanidade nascer, acontecia uma imensa batalha, algo que nenhum mortal poderia presenciar. Os Deuses antigos travaram uma batalha mortal pelo poder de um amuleto, aquele que possu�sse tal amuleto ampliaria seus poderes e reinaria sobre o mundo. Os Deuses lutaram por s�culos para obter tal poder, mas no meio desta grande batalha, Os�ris o Deus do julgamento interveio, e com seu imenso poder amaldi�oou o amuleto, permitindo apenas o uso para aqueles que n�o possuem o poder divino. Com o passar das eras o amuleto se perdeu e o grande Deus R� criou a humanidade. Os Deuses se dispersaram e pareciam ter se esquecido do amuleto, at� que no ano 51 A.C um soldado percebeu que algo brilhava em meio a terra, tomado pela curiosidade ele decide vasculhar o ch�o, e finalmente encontra um amuleto at� ent�o desconhecido, tudo o que ele via era seu formato peculiar. Com o amuleto desenterrado um enorme poder surgia dele, humanos n�o podiam perceber, mas os Deuses perceberam na hora que o amuleto havia sido encontrado, mas sem saber o que era, o soldado coloca o amuleto em volta do pesco�o, e sem perceber o poder flui pelo seu corpo, os soldados aliados que estavam em volta perceberam o comportamento estranho de seu companheiro, mas quando se aproximam dele o portador do amuleto simplesmente se torna cinzas, assustados com a cena os soldados em volta reparam que vinha um brilho do artefato desconhecido e ligam a morte de seu amigo diretamente ao amuleto. Assustados com a presen�a de algo t�o poderoso os soldados informam ao fara� sobre o ocorrido, e sem acreditar no que ouvia e totalmente aterrorizado o fara� ordena aos seus s�ditos que construam uma enorme pir�mide em volta do amuleto, e que o enterrem o mais fundo poss�vel nas catacumbas da nova pir�mide. Os Deuses n�o tinham muita influ�ncia no mundo mortal, mas o que eles n�o sabiam era que Seth tentaria manipular um mortal para obter o \�Olho de H�rus\� e retirar sua maldi��o. Com a maldi��o desfeita, Seth reinar� sobre todos os Deuses e seus respectivos reinos, Seth libertar� toda a escurid�o sobre o mundo e o assim governar� por toda eternidade.\n\n";
    char Texto2[] = "  Voc� � um arque�logo conhecido como";
    char Texto3[] = "ao estudar est� lenda voc� decide ir em busca deste artefato antigo...\n\n  Essa ser� um jornada tortuosa, e para enfim alcan�ar o antigo artefato, voc� ter� que passar pelos mais dif�ceis \n\n desafios... \n\n";

    SlowText(Texto1);
    fflush(stdin);
    system("pause");
    system("cls");
    SlowText(Texto2);
    printf(" ");
    SlowText(NamePlayer);
    printf(", ");
    SlowText(Texto3);
    fflush(stdin);
    system("pause");
    Fase1(Vidas);
}

void Anubis(int Fase, int Vida) { // An�bis (Controlador de Vidas do Player)
    int Vidas = Vida;
    if (Vida == 1 && Fase == 1) {
        system("cls");
        printf("Vidas: %d \n\n  An�bis: N�o acredito que voc� errou algo t�o f�cil, mas n�o se preocupe, te darei uma segunda chance\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        Fase1(Vidas);
    } if (Vida == 1 && Fase == 2) {
        system("cls");
        printf("Vidas: %d \n\n  An�bis: Eu te darei mais uma chance de vida, mortal n�o a desperdice\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        Fase2(Vidas);
    } if (Vida == 1 && Fase == 4) {
        system("cls");
        printf("Vidas: %d \n\n  An�bis: Voc� morreu, irei te reviver apenas dessa vez, n�o cometa mais erros\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        BossEsfinge(Vidas);
    } if (Vida == 1 && Fase == 5) {
        system("cls");
        printf("Vidas: %d \n\n  An�bis: S� tenho poder suficiente pra te reviver desta vez, ent�o n�o erre novamente!\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        Fase1Cenario2(Vidas);
    } if (Vida == 1 && Fase == 6) {
        system("cls");
        printf("Vidas: %d \n\n  An�bis: Voc� morreu, n�o cometa mais erros, pois, n�o irei te ajudar da pr�xima vez!\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        Fase2Cenario2(Vidas);
    } else {
        system("cls");
        printf("Vidas: %d \n\n  Voc� n�o tem vidas restantes\n\n", Vidas);
        system("pause");
        GameOver();
    }
}

void GameOver() {  // Fun��o de GameOver //
    char GameOver[] = "  Game Over";
    SlowText(GameOver);
    Sleep(2000);
    system("cls");
    main();
}
