#include <iostream>

using namespace std;

char tile[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

int main()
{
    cout << " " << tile[0] << " | " << tile[1] << " | " << tile[2] << " \n";
    cout << "-----------\n";
    cout << " " << tile[3] << " | " << tile[4] << " | " << tile[5] << " \n";
    cout << "-----------\n";
    cout << " " << tile[6] << " | " << tile[7] << " | " << tile[8] << " \n";
    return 0;
}