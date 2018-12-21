#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>


using namespace std;

void generowanie(char tab[][10])
{
    int x=0, y=0;
    srand(time(NULL));
    int los=0;
    for(int y=0; y<10; y++)
    {
        for(x=0; x<10; x++)
        {
            los = rand()%5;
            if(los == 2)
            {
                tab[x][y] = 'O';
            }
            else
            {
            tab[x][y] = '-';
            }
        }

    }

}

void wyswietlenie(char tab[][10], int x1, int y1, int score, clock_t start)
{
    system("cls");
    int x=0, y=0;


    cout<< "____________" << endl;
    for(int y=0; y<10; y++)
    { cout << "|";
        for(x=0; x<10; x++)
        {
            tab[x1][y1] = 'X';
            cout << tab[x][y];

        }
        cout << "|";
        if(y==1) {cout<< " SCORE: " << score;}
        if(y==2) {cout<< " TIME: " << start/CLOCKS_PER_SEC << "s";}
        cout << endl;

    }
    cout<< "____________" << endl;
    cout<<endl;
    cout<< "PRESS: " << endl;
    cout<< " R - RETRY" << endl;
    cout<< " I - INFO" << endl;
    cout<< " Q - EXIT" << endl;


}

void f_tab_2d_dyn(char **arg)
{

}

int main()
{
    clock_t start=0;
    int score=0;
    int x=0, y=0, x1=4, y1=4;
    char mapa[10][10];
    generowanie(mapa);
    wyswietlenie(mapa, x1, y1, score, start);

    while(true)
    {

        char wybor;
        wybor=getch();
        start = clock();
        switch(wybor)
        {
        case 'w':
        {
            if(mapa[x1][y1-1] == 'O') score++;
            y1--;
            mapa[x1][y1+1]='-';
            if(y1<0) y1=9;


            wyswietlenie(mapa, x1, y1, score, start);

        }break;
        case 's':
        {
            if(mapa[x1][y1+1] == 'O') score++;
            y1++;
            mapa[x1][y1-1]='-';
            if(y1>9) y1=0;


            wyswietlenie(mapa, x1, y1, score, start);

        }break;
        case 'a':
        {
            if(mapa[x1-1][y1] == 'O') score++;
            x1--;
            mapa[x1+1][y1]='-';
            if(x1<0) x1=9;

            wyswietlenie(mapa, x1, y1, score, start);

        }break;
        case 'd':
            {
                if(mapa[x1+1][y1] == 'O') score++;
                x1++;
                mapa[x1-1][y1]='-';
                if(x1>9) x1=0;

                wyswietlenie(mapa, x1, y1, score, start);

            }break;
        case 'r':
            {
            generowanie(mapa);
            wyswietlenie(mapa, x1, y1, score, start);
            }break;
        case 'q':
            {
             exit(0);
            }break;
        case 'i':
            {
            system("cls");
            cout << "----- INFO -----" << endl;
            cout << "STEROWANIE: " << endl;
            cout << "   W   " << endl;
            cout << " S A D" << endl;
            cout << endl;
            cout << "Gra powstala w calosci na USELESS lekcjach w ciagu jednego dnia XD"<< endl;
            cout << endl;
            cout << "POWROT: PRESS R "<< endl;
            cout << "----------------";

            }break;
        }

    }

    return 0;
}

