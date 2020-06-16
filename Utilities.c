#include "Includes.h"

int KeyPress;
char NamePlayer[200];

void Player(int Vida, int MusicOn)      // Nome do Player //
{
    int Vidas = Vida, o = MusicOn;
    system("cls");
    printf("  Por favor, não aperte nada enquanto o texto é digitado em sua tela.\n");
    printf("  Por favor, não use caractere especial\n\n");
    printf("  Digite o nome do Arqueólogo: ");
    fflush(stdin);
    gets(NamePlayer);
KbLore:
    coordxy(0,5);
    printf("\n\n Você deseja pular a História? \n   Aperte S para Sim.\n   Aperte N para Não.\n");
    if (kbhit)
    {
        KeyPress=getch();
    }
    if (KeyPress == 110)
    {
        Lore(Vidas, o);
    }
    if (KeyPress == 115)
    {
        Fase1(Vidas, o);
    }
    else
    {
        goto KbLore;
    }
}

void Lore(int Vida, int MusicOn)    // História primeiro Cenário
{
    int Vidas = Vida, o = MusicOn;
    system("cls");
    char Texto1[20000] = "  No Egito antigo, há muitas eras, antes da humanidade nascer, acontecia uma imensa batalha, algo que nenhum mortal poderia presenciar. Os Deuses antigos travaram uma batalha mortal pelo poder de um amuleto, aquele que possuísse tal amuleto ampliaria seus poderes e reinaria sobre o mundo. Os Deuses lutaram por séculos para obter tal poder, mas no meio desta grande batalha, Osíris o Deus do julgamento interveio, e com seu imenso poder amaldiçoou o amuleto, permitindo apenas o uso para aqueles que não possuem o poder divino. Com o passar das eras o amuleto se perdeu e o grande Deus Rá criou a humanidade. Os Deuses se dispersaram e pareciam ter se esquecido do amuleto, até que no ano 51 A.C um soldado percebeu que algo brilhava em meio a terra, tomado pela curiosidade ele decide vasculhar o chão, e finalmente encontra um amuleto até então desconhecido, tudo o que ele via era seu formato peculiar. Com o amuleto desenterrado um enorme poder surgia dele, humanos não podiam perceber, mas os Deuses perceberam na hora que o amuleto havia sido encontrado, mas sem saber o que era, o soldado coloca o amuleto em volta do pescoço, e sem perceber o poder flui pelo seu corpo, os soldados aliados que estavam em volta perceberam o comportamento estranho de seu companheiro, mas quando se aproximam dele o portador do amuleto simplesmente se torna cinzas, assustados com a cena os soldados em volta reparam que vinha um brilho do artefato desconhecido e ligam a morte de seu amigo diretamente ao amuleto. Assustados com a presença de algo tão poderoso os soldados informam ao faraó sobre o ocorrido, e sem acreditar no que ouvia e totalmente aterrorizado o faraó ordena aos seus súditos que construam uma enorme pirâmide em volta do amuleto, e que o enterrem o mais fundo possível nas catacumbas da nova pirâmide. Os Deuses não tinham muita influência no mundo mortal, mas o que eles não sabiam era que Seth tentaria manipular um mortal para obter o \“Olho de Hórus\” e retirar sua maldição. Com a maldição desfeita, Seth reinará sobre todos os Deuses e seus respectivos reinos, Seth libertará toda a escuridão sobre o mundo e o assim governará por toda eternidade.\n\n";
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
    fflush(stdin);
    system("pause");
    Fase1(Vidas, o);
}

void Anubis(int Fase, int Vida, int MusicOn)   // Anúbis (Controlador de Vidas do Player)
{
    int Vidas = Vida, o = MusicOn;
    if (Vida == 1 && Fase == 1)
    {
        system("cls");
        printf("Vidas: %d \n\n  Anúbis: Não acredito que você errou algo tão fácil, mas não se preocupe, te darei uma segunda chance\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        Fase1(Vidas, o);
    }
    if (Vida == 1 && Fase == 2)
    {
        system("cls");
        printf("Vidas: %d \n\n  Anúbis: Eu te darei mais uma chance de vida, mortal não a desperdice\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        Fase2(Vidas, o);
    }
    if (Vida == 1 && Fase == 4)
    {
        system("cls");
        printf("Vidas: %d \n\n  Anúbis: Você morreu, irei te reviver apenas dessa vez, não cometa mais erros\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        BossEsfinge(Vidas, o);
    }
    if (Vida == 1 && Fase == 5)
    {
        system("cls");
        printf("Vidas: %d \n\n  Anúbis: Só tenho poder suficiente pra te reviver desta vez, então não erre novamente!\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        Fase1Cenario2(Vidas, o);
    }
    if (Vida == 1 && Fase == 6)
    {
        system("cls");
        printf("Vidas: %d \n\n  Anúbis: Você morreu, não cometa mais erros, pois, não irei te ajudar da próxima vez!\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        Fase2Cenario2(Vidas, o);
    }
    if (Vida == 1 && Fase == 7)
    {
        system("cls");
        printf("Vidas: %d \n\n  Anúbis: Você morreu no labirinto, espero que tenha aprendido com o seu erro, pois só te darei uma chance!\n\n", Vidas);
        Vida--;
        system("pause");
        system("cls");
        Vidas = Vida;
        Fase3Cenario2(Vidas, o);
    }
    else
    {
        system("cls");
        printf("Vidas: %d \n\n  Você não tem vidas restantes\n\n", Vidas);
        system("pause");
        GameOver(o);
    }
}

void GameOver(int MusicOn)    // Função de GameOver //
{
    int o = MusicOn;
    char GameOver[] = "  Game Over";
    SlowText(GameOver);
    Sleep(2000);
    system("cls");
    Menu(o);
}


