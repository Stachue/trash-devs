#include <iostream>
#include <windows.h>
#include <conio.h>

#include "mapa.h"

using namespace std;

void Mapa::generator()
{
    for(int x=0; x<30; x++)
   {
       for(int y=0; y<50; y++)
       {
           mapa[x][y] = 255;
       }
   }
}

void Mapa::wyswietlenie()
{
    system("cls");
    char border = 219;
    for(int x=0; x<30; x++)
    {
        cout << " " << border;
        for(int y=0; y<50; y++)
        {
            mapa[0][y]=border;
            mapa[29][y]=border;
            cout << mapa[x][y];
        }
        cout<< border << endl;

    }
}

void Mapa::rakieta(int x, int y)
{
        mapa[x][y] = 219;
        mapa[x-1][y] = 30;
        mapa[x+1][y+1] = 92;
        mapa[x+1][y-1] = 47;
        mapa[x+1][y] = 42;


}
