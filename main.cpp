#include <iostream>
#include <sstream>
#include <stdlib.h> 
#include <time.h>

using namespace std;

bool checking, playerWon;
string RA_input; //RA = random access
char player1, player2, validIn;
int currentPlayer;

char tile[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

bool randomBool()
{
    srand(time(NULL));
    return 0 + (rand() % (1 - 0 + 1)) == 1;
}


void printBoard() {
    cout << " " << tile[0] << " | " << tile[1] << " | " << tile[2] << endl;
    cout << "-----------\n";
    cout << " " << tile[3] << " | " << tile[4] << " | " << tile[5] << endl;
    cout << "-----------\n";
    cout << " " << tile[6] << " | " << tile[7] << " | " << tile[8] << endl;
}

void gameInit() {
    cout << "Do u want be X or O" << endl;
    cin >> RA_input ;

    if (RA_input == "X" || RA_input == "x") {
        player1 = 'X';
        player2 = 'O';
    } else {
        player1 = 'O';
        player2 = 'X';
    }

    if (randomBool()) {
        cout << "X is starting" << endl;
        if (player1 == 'X') {
            currentPlayer = 1;
        } else {
           currentPlayer = 2; 
        }
    } else {
        cout << "O is starting" << endl;
        if (player1 == 'O') {
            currentPlayer = 1;
        } else {
           currentPlayer = 2; 
        }
    }
}

void logicCheck(char a, char b, char c) {
    //cout << a << b << c << endl; //debug
    if((a == 'X' || b == 'O') && a == b && b == c) {
        playerWon = true;
        checking = false;
    }
}

/*
If:
0,1,2
3,4,5
6,7,8
0,3,6
1,4,7
2,5,8
0,4,8
2,4,6
is all same char win
*/
void winCheck() {
    checking = true;
    playerWon = 0;
    if(checking){logicCheck(tile[0], tile[1], tile[2]);}
    if(checking){logicCheck(tile[3], tile[4], tile[5]);}
    if(checking){logicCheck(tile[6], tile[7], tile[8]);}
    if(checking){logicCheck(tile[0], tile[3], tile[6]);}
    if(checking){logicCheck(tile[1], tile[4], tile[7]);}
    if(checking){logicCheck(tile[2], tile[5], tile[8]);}
    if(checking){logicCheck(tile[0], tile[4], tile[8]);}
    if(checking){logicCheck(tile[2], tile[4], tile[6]);}
}

void player_i() {
    int convertInt;

    while (true) {
        do {
            currentPlayer == 1 ? cout << "Where do you want to put the " << player1 << " (1-9)" << endl : cout << "Where do you want to put the " << player2 << " (1-9)" << endl;
            cin >> RA_input;
            stringstream geek(RA_input);
            geek >> convertInt;
            for (int i = 1; i < 9; i++) {
                if(convertInt == i) {
                    validIn = true;
                    break;
                } else {
                    validIn = false;
                }
            }
            if (!validIn) {
                cout << "Invalid input" << endl;
            }
        } while(!validIn);
        
        if (currentPlayer == 1) {
            tile[convertInt - 1] = player1;
            winCheck();
            printBoard();
            if (playerWon) {
                break;
            } else {
                currentPlayer = 2;
            }
        } else if (currentPlayer == 2) {
            tile[convertInt - 1] = player2;
            winCheck();
            printBoard();
            if (playerWon) {
                break;
            } else {
                currentPlayer = 1;
            }
        }
    }
}

int main()
{
    cout << "Welcome to the game of TicTacToe\n";
    while(true) {
        gameInit();
        while (true)
        {
            player_i();
            if(playerWon == true){
                break;
            }
        }
        cout << "Player " << currentPlayer << " has won\n" << "Play again y/n" << endl;
        cin >> RA_input;
        if(RA_input == "n"){
            break;
        }
        for (int i = 1; i < 9; i++) {
            tile[i] = ' ';
        }
    }
    
    return 0;
}