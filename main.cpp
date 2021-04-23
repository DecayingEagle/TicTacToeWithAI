#include <iostream>
#include <sstream>

using namespace std;

bool xStarts, endGame, checking;
string g_input;
char player1OX, player2OX, player1win, player2win, debugYN;
int playerWon = 0;

char tile[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

bool randomBool()
{
    return 0 + (rand() % (1 - 0 + 1)) == 1;
}


void printTTT() {
    cout << " " << tile[0] << " | " << tile[1] << " | " << tile[2] << endl;
    cout << "-----------\n";
    cout << " " << tile[3] << " | " << tile[4] << " | " << tile[5] << endl;
    cout << "-----------\n";
    cout << " " << tile[6] << " | " << tile[7] << " | " << tile[8] << endl;
}

void gameInit() {
    cout << "Do u want be X or O" << endl;
    cin >> g_input ;

    if (g_input == "X" || g_input == "x") {
        player1OX = 'X';
        player2OX = 'O';
    } else {
        player1OX = 'O';
        player2OX = 'X';
    }

    randomBool() ? xStarts = true : xStarts = false;
    xStarts ? cout << "X is starting" << endl : cout << "O is starting" << endl;
    /*cout << "End this? y/n" << endl;
    cin >> debugYN;
    debugYN == 'y' ? endGame = true : endGame = false;*/
}


//To do if invalid output is presented then output an error
void player1_i() {
    cout << "Where do you want to put the " << player1OX << endl;
    cin >> g_input;
    stringstream geek(g_input);
    int i;
    geek >> i;
    tile[i - 1] = player1OX;
    printTTT();
}

void player2_i() {
    cout << "Where do you want to put the " << player2OX << endl;
    cin >> g_input;
    stringstream geek(g_input);
    int i;
    geek >> i;
    tile[i - 1] = player2OX;
    printTTT();
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
void logicCheck(char a, char b, char c) {
    //cout << a << b << c << endl; //debug
    if((a == 'X' || b == 'O') && a == b && b == c) {
        a == 'X' ? playerWon = 1 : playerWon = 2;
        //cout << "someone won" << endl; //debug
        checking = false;
    }
}

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

int main()
{
    cout << "Welcome to the game of TicTacToe\n";
    while(true) {
        gameInit();
        while (true)
        {
            player1_i();
            winCheck();
            if(playerWon == 1){
                break;
            }
            player2_i();
            winCheck();
            if(playerWon == 2){
                break;
            }
        }
        cout << "Player " << playerWon << " has won\n" << "Play again y/n" << endl;
        cin >> g_input;
        if(g_input == "n"){
            break;
        }
    }
    
    return 0;
}