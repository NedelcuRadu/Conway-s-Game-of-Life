#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

ifstream in("R-pentomino.in"); //Stream for seeds

int GRID, N;
bool **a, **b; //Dynamically Allocated Matrix

void afis(bool **a) { //Display function
    for(int i = 1; i <= GRID; i++) {
        for(int j = 1; j <= GRID; j++) {
            if(a[i][j])
                cout << "*"; //Alive cells
            else if(i == 1 || i == GRID)
                cout << "-"; //Wall
            else if(j == 1 || j == GRID)
                cout << "|"; //Wall
            else
                cout << (char) 254; //Alive cells
        }
        cout << "\n";
    }

}
void gotoxy(int x, int y) { //Less flicker than system("CLS)
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void constrGrid(bool **a) { //Initially grid is empty
    for(int i = 1; i <= GRID; i++)
        for(int j = 1; j <= GRID; j++)
            a[i][j] = 0;

}

int life(bool **a, int x, int y) { //Returns neighbours
    int life = 0;
    if(x > 1 && x < GRID && y < GRID && y > 1) //Check constraints
        for(int i = -1; i <= +1; i++)
            for(int j = -1; j <= +1; j++)
                if(a[x + i][y + j])
                    life++;
    if(a[x][y])
        return life - 1;
    return life;                           
}
                                         
void liveOrDie1() { //Applies rules to matrix A and keeps results in B      
    for(int i = 1; i <= GRID; i++)           
        for(int j = 1; j <= GRID; j++) {                                                         
            int k = life(a, i, j);
            if(k == 2) // 2 neighbours, cell keeps current state
                b[i][j] = a[i][j];
            else      
                if(k < 2)                                                                      
                    b[i][j] = 0; //Less than 2 neighbours, cell dies
                else if(k == 3)
                    b[i][j] = 1;//3 neighbours, cell spawns
                else if(k > 3)
                    b[i][j] = 0; // More than 3 neighbours, cell dies 
        }
}

void liveOrDie2() { //Applies rules to matrix B and keeps results in A   
    for(int i = 1; i <= GRID; i++)
        for(int j = 1; j <= GRID; j++) {
            int k = life(b, i, j);
            if(k < 2)
                a[i][j] = 0;
            else if(k == 3)
                a[i][j] = 1;
            else if(k > 3)
                a[i][j] = 0;
            else if(k == 2)
                a[i][j] = b[i][j];
        }

}

int main() {
    int x, y, nr = 0;
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
    cout << "Load preset? Y/N" << endl;
    char q;
    cin >> q; //Get decision
    if(q == 'Y' || q == 'y') { //If preset
        int x, y;
        in >> GRID >> N; //Read from stream
     //Construct matrix
        a = new bool*[GRID]; 
        b = new bool*[GRID];
        for(int i = 1; i <= GRID; i++) {
            a[i] = new bool[GRID];
            b[i] = new bool[GRID];
        }
        constrGrid(a);
        constrGrid(b);
        
        for(int i = 1; i <= N; i++) { //Get seeds
            in >> x;
            in >> y;
            a[x][y] = 1;
            cout << x << " " << y << endl;
        }
        
        system("CLS"); //Clear screen
    } else  {
        cout << "Grid size?" << "\n"; 
        cin >> GRID;
        
        a = new bool*[GRID];
        b = new bool*[GRID];
        for(int i = 1; i <= GRID; i++) {
            a[i] = new bool[GRID];
            b[i] = new bool[GRID];
        }
        constrGrid(a);
        constrGrid(b);
        
        cout << "How many seeds?" << "\n";
        cin >> N;
        
        system("CLS"); //Clear screen and chance color
        system("color c");
        
        for(int i = 1; i <= N; i++) { //Get seeds
            afis(a);
            cout << "Select coord (x,y) pt seed nr." << i << " (1 si " << GRID << " sunt pereti )" << "\n";
            cin >> x >> y;
            a[x][y] = 1;

            system("CLS");
        }
    }

    while(true) { //Main game loop
        system("color 17"); 
        
        cout << "Generatia nr." << ++nr << "\n";
        liveOrDie1();
        afis(b);
        Sleep(300);
        gotoxy(0, 0);
        
        cout << "Generatia nr." << ++nr << "\n";
        liveOrDie2();
        afis(a);
        Sleep(300);
        gotoxy(0, 0);
        
    }
    return 0;
}
