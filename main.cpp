#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;
ifstream in("Block.txt");
int GRID,N;
bool a[200][200];
bool b[200][200];

void afis(bool a[200][200])
{
    for(int i=1;i<=GRID;i++)
        {for(int j=1;j<=GRID;j++)
        if(a[i][j])
        cout<<"*";
    else
        cout<<"O";
        cout<<"\n";}

}
void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void constrGrid()
{  for(int i=1;i<=GRID;i++)
        for(int j=1;j<=GRID;j++)
            a[i][j]=0;

}
int life(bool a[200][200],int x, int y)
{int life=0;
if(x>1 && x<GRID && y<GRID && y>1)
for(int i=-1;i<=+1;i++)
for(int j=-1;j<=+1;j++)
    if(a[x+i][y+j])
    life++;
    if(a[x][y])
    return life-1;
    return life;                           //                A              B            A         TO DO: life in A
}                                          //              0 0 0          0 X 0        0 0 0              live2 in B
void liveOrDie1(bool b[200][200])          //              X X X    --->  0 X 0  --->  X X X             afis B
{for(int i=1;i<=GRID;i++)                  //              0 0 0          0 X 0        0 0 0              life in B
        for(int j=1;j<=GRID;j++)                                                           //            live1 in A
            {int k=life(a,i,j);                                                            //       system("CLS");
            if(k<2)                                                                        //       afis A
                b[i][j]=0;
            if(k==3)
                b[i][j]=1;
                if(k>3)
                    b[i][j]=0;
                }

}
void liveOrDie2(bool b[200][200])
{for(int i=1;i<=GRID;i++)
        for(int j=1;j<=GRID;j++)
            {int k=life(b,i,j);
            if(k<2)
                b[i][j]=0;
            if(k==3)
                b[i][j]=1;
                if(k>3)
                    b[i][j]=0;
                }

}
void nextgen1()
{
    for(int i=1;i<=GRID;i++)
        for(int j=1;j<=GRID;j++)
            b[i][j]=a[i][j];
}
void nextgen2()
{for(int i=1;i<=GRID;i++)
        for(int j=1;j<=GRID;j++)
            a[i][j]=b[i][j];

}


int main()
{int x,y,nr=0;
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
    cout << "O - dead cell" << endl;
    cout << endl;
    cout<<"Grid size??"<<"\n";
    cin>>GRID;
    constrGrid();
    cout<<"Select seeds number?"<<"\n";
    cin>>N;
    system("CLS");
system("color c");
for(int i=1;i<=N;i++)
{afis(a);
cout<<"Select seeds coord (x,y)"<<"\n";
    cin>>x>>y;
    a[x][y]=1;

    system("CLS");
}
/*while(in>>x>>y)
{Sleep(10000);
afis();
cout<<"Select seeds coord (x,y)"<<"\n";
    a[x][y]=1;
Sleep(1000);
    //system("CLS");

}*/

   while(true){cout<<"Generatia nr."<<++nr<<"\n";

        liveOrDie1(b);
         afis(b);
         Sleep(1000);
          gotoxy(0,0);
         cout<<"Generatia nr."<<++nr<<"\n";
          liveOrDie2(a);
         afis(a);
        Sleep(1000);
    gotoxy(0,0);

}
cout<<life(a,5,6);
return 0;}
