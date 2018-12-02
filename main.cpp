#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
int GRID,N;
bool a[200][200];
void afis()
{
    for(int i=1;i<=GRID;i++)
        {for(int j=1;j<=GRID;j++)
        if(a[i][j])
        cout<<"*";
    else
        cout<<".";
        cout<<"\n";}

}
/*void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}*/

void constrGrid()
{  for(int i=1;i<=GRID;i++)
        for(int j=1;j<=GRID;j++)
            a[i][j]=0;

}
int life(int x, int y)
{int life=0;
for(int i=x-1;i<=x+1;i++)
for(int j=y-1;j<=y+1;j++)
    {if(a[i][j])
    life++;
    if(life>3)
        return 0;}
    return life;
}
void liveOrDie()
{for(int i=1;i<=GRID;i++)
        for(int j=1;j<=GRID;j++)
            {if(life(i,j)<2)
                a[i][j]=0;
                else
            if(life(i,j)==3)
                a[i][j]=1;
                }

}
int main()
{int x,y;
system("color B");
cout << "                         THE GAME OF life - Implementation in C++" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Also known simply as life, " << endl;
    cout << "is a cellular automaton devised by the British mathematician John Horton Conway in 1970." << endl;
    cout << endl;
    cout << "Rules" << endl;
    cout << "The universe of the Game of life is an infinite two-dimensional orthogonal grid of square cells," << endl;
    cout << "each of which is in one of two possible states, life or dead. Every" << endl;
    cout << "cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent." << endl;
    cout << "At each step in time, the following transitions occur:" << endl;
    cout << "1. Any live cell with fewer than two live neighbours dies, as if caused by under-population." << endl;
    cout << "2. Any live cell with two or three live neighbours lives on to the next generation." << endl;
    cout << "3. Any live cell with more than three live neighbours dies, as if by over-population." << endl;
    cout << "4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction." << endl;
    cout << endl;
    cout << "* - living cell" << endl;
    cout << ". - dead cell" << endl;
    cout << endl;

    cout<<"Grid size??"<<"\n";
    cin>>GRID;
    constrGrid();
    cout<<"Select seeds number?"<<"\n";
    cin>>N;
    system("CLS");
system("color C");
for(int i=1;i<=N;i++)
{afis();
cout<<"Select seeds coord (x,y)"<<"\n";
    cin>>x>>y;
    a[x][y]=1;

    system("CLS");
}

   while(true){afis();
        liveOrDie();
    gotoxy(0,0);

}
return 0;}
