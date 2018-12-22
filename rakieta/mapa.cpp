#include <iostream>
#include <windows.h>
#include <conio.h>

#include "mapa.h"

using namespace std;

void Mapa::generator() //generowanie mapy
{
    for(int y=0; y<30; y++)
   {
       for(int x=0; x<50; x++)
       {
           mapa[y][x] = 255;
       }
   }
}

void Mapa::wyswietlenie(int r1, int r2) //wyswietlanie mapy
{
    system("cls");
    char border = 219;
    for(int y=0; y<30; y++)
    {
        cout << " " << border;
        for(int x=0; x<50; x++)
        {
            mapa[0][x]=border;
            mapa[29][x]=border;
            cout << mapa[y][x];
        }
        if(y==1){ cout<< border << "   X: " << r2 <<endl; }
        else if(y==2){ cout<< border << "   Y: " << r1 <<endl; }
        else cout<< border << endl;
    }
}

void Mapa::rakieta(int y, int x, int p) //sterowanie rakieta
{
    switch(p)
    {
    case 1: //gora
        {
            mapa[y][x] = 219; //kadlub
        //gora, dol statku
            mapa[y-1][x] = 30;
            mapa[y+1][x] = 42;
        //boki
            mapa[y+1][x+1] = 92;
            mapa[y+1][x-1] = 47;
        }break;
    case 2: //prawo
        {
            mapa[y][x] = 219; //kadlub
        //gora, dol statku
            mapa[y][x+1] = 16;
            mapa[y][x-1] = 42;
        //boki
            mapa[y-1][x-1] = 92;
            mapa[y+1][x-1] = 47;
        }break;
    case 3: //dol
        {
            mapa[y][x] = 219; //kadlub
        //gora, dol statku
            mapa[y+1][x] = 31;
            mapa[y-1][x] = 42;
        //boki
            mapa[y-1][x+1] = 47;
            mapa[y-1][x-1] = 92;
        }break;
    case 4: //lewo
        {
            mapa[y][x] = 219; //kadlub
        //gora, dol statku
            mapa[y][x-1] = 17;
            mapa[y][x+1] = 42;
        //boki
            mapa[y-1][x+1] = 47;
            mapa[y+1][x+1] = 92;
        }break;
    }
}
void Mapa::cleaner(int y, int x, int p) //usuwa pozostalosci po rakiecie
{
    switch(p)
    {
        case 1:
            {
                mapa[y+2][x] = space;
                mapa[y+2][x+1] = space;
                mapa[y+2][x-1] = space;
                mapa[y][x-1] = space;
                mapa[y][x+1] = space;
                mapa[y-1][x-1] = space;
                mapa[y-1][x+1] = space;
            }break;
        case 2:
            {
                mapa[y-1][x-2] = space;
                mapa[y][x-2] = space;
                mapa[y+1][x-2] = space;
                mapa[y+1][x] = space;
                mapa[y-1][x] = space;
                mapa[y+1][x+1] = space;
                mapa[y-1][x+1] = space;
            }break;
        case 3:
            {
                mapa[y-2][x] = space;
                mapa[y-2][x+1] = space;
                mapa[y-2][x-1] = space;
                mapa[y][x-1] = space;
                mapa[y][x+1] = space;
                mapa[y+1][x-1] = space;
                mapa[y+1][x+1] = space;
            }break;
        case 4:
            {
                mapa[y-1][x+2] = space;
                mapa[y][x+2] = space;
                mapa[y+1][x+2] = space;
                mapa[y+1][x] = space;
                mapa[y-1][x] = space;
                mapa[y+1][x-1] = space;
                mapa[y-1][x-1] = space;
            }break;
    }
}
