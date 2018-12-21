#include <iostream>
#include <windows.h>
#include <conio.h>

#include "mapa.h"
using namespace std;

char space=255;

void color(int nr);

int main()
{
    int r1=25, r2=25; //rakieta
    Mapa m1;
    m1.generator();
    m1.rakieta(r1, r2);
    m1.wyswietlenie();

    while(true)
    {
        char wybor;
        wybor = getch();

        switch(wybor)
        {
            case 'w':
            {
                r1--;
                m1.mapa[r1+2][r2] = space;
                m1.mapa[r1+2][r2+1] = space;
                m1.mapa[r1+2][r2-1] = space;
                m1.rakieta(r1, r2);
                m1.wyswietlenie();

            }break;
        }
    }
    return 0;
}

void color(int nr)
{
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, nr);
    // 1 - ciemny niebieski
    // 2 - ciemny zielony
    // 3 - jakis dziwny ciemny niebieski
    // 4 - ciemny czerwony
    // 5 - ciemny rozowy
    // 6 - ciemny zolty
    // 7 - ciemny bialy (defaultowy)
    // 8 - szary
    // 9 - jasny ciemny niebieski
    // 10 - jasny zielony
    // 11 - jakis dziwny jasny niebieski
    // 12 - jasny czerwony
    // 13 - jasny rozowy
    // 14 - jasny zolty
    // 15 - bialy
}
