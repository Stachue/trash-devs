#include <iostream>
#include <windows.h>
#include <conio.h>


class Mapa
{
    public:
    char space=255;
    char mapa[30][50];

    void generator(); //generuje mape
    void wyswietlenie(int, int); //wyswietla mape
    void rakieta(int, int, int); //sterowanie rakieta
    void cleaner(int, int, int); //usuwa pozostalosci po rakiecie
};
