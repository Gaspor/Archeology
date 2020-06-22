#include "Menu/Includes.h"

int main()
{
    setlocale(LC_ALL,"Portuguese");
    SetConsoleTitle("Archeology Game");
    system("MODE con cols=200 lines=60");

    int o = 1;
    Menu(o);
    return 0;
}
