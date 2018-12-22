#include <iostream>
#include <windows.h>
#include <conio.h>

#include "mapa.h"
using namespace std;

void color(int nr);

int main()
{
    int r1=25, r2=25; //kordy rakiety
    int p=1; //pozycja 1-gora 2-prawo 3-dol 4-lewo
    Mapa m1;
    m1.generator();
    m1.rakieta(r1, r2, p);
    m1.wyswietlenie(r1, r2);

    while(true)
    {
        char wybor;
        wybor = getch();

        switch(wybor)
        {
            case 'w':
                {
                    if(r1<=2){r1++;}
                    p=1;
                    r1--;
                    m1.cleaner(r1, r2, p);
                    m1.rakieta(r1, r2, p);
                    m1.wyswietlenie(r1, r2);

                }break;
            case 's':
                {
                    if(r1>=27){r1--;}
                    p=3;
                    r1++;
                    m1.cleaner(r1, r2, p);
                    m1.rakieta(r1, r2, p);
                    m1.wyswietlenie(r1, r2);

                }break;
            case 'a':
                {
                    if(r2<=1){r2++;}
                    p=4;
                    r2--;
                    m1.cleaner(r1, r2, p);
                    m1.rakieta(r1, r2, p);
                    m1.wyswietlenie(r1, r2);
                }break;
            case 'd':
                {
                    if(r2>=48){r2--;}
                    p=2;
                    r2++;
                    m1.cleaner(r1, r2, p);
                    m1.rakieta(r1, r2, p);
                    m1.wyswietlenie(r1, r2);
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
