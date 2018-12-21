#include <iostream>
#include <windows.h>
#include <conio.h>


class Mapa
{
    public:
    char mapa[30][50];

    void generator();

    void wyswietlenie();

    void rakieta(int, int);
};
