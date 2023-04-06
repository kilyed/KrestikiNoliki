#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cstdio>
using namespace std;
char win = '-'; 
char PlayerName1[80], PlayerName2[80]; 
char cells[9] = { '-','-','-','-','-','-','-','-','-' };

void show_cells() {
    system("cls");

   
    cout << "Number cell: \n";
    cout << "-" << 1 << "-" << "|" << "-" << 2 << "-" << "|" << "-" << 3 << "-" << endl;
    cout << "-" << 4 << "-" << "|" << "-" << 5 << "-" << "|" << "-" << 6 << "-" << endl;
    cout << "-" << 7 << "-" << "|" << "-" << 8 << "-" << "|" << "-" << 9 << "-" << endl;

    cout << "Cell  now (--- = empty):\n" << endl;
    cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << endl;
    cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << endl;
    cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << "\n" << endl;

}
void make_move(int num) {
    if (num == 1) cout << PlayerName1;
    else cout << PlayerName2;
    int cell;
    cout << ",Enter number cell for step:";
    cin >> cell;
   

       
    while (cell > 9 || cell < 1 || cells[cell - 1] == 'O' || cells[cell - 1] == 'X')
        cout << "Enter number cell;";
    cin >> cell;
    cout << "\n";
   
    if (num == 1) cells[cell - 1] = 'X';
    else cells[cell - 1] = 'O';
}



char check()
{
    for (int i = 0; i < 3; i++) 
        if (cells[i * 3] == cells[i * 3 + 1] && cells[i * 3 + 1] == cells[i * 3 + 2]) 
            return cells[i]; 
   
        else if (cells[i] == cells[i + 3] && cells[i + 3] == cells[i + 6]) 
            return cells[i];
        else if ((cells[2] == cells[4] && cells[4] == cells[6]) || (cells[0] == cells[4] && cells[4] == cells[8]))
            return cells[i]; 
    return '-'; 
}

void result() {
    if (win == 'X')
        cout << PlayerName1 << "You Win! " << PlayerName2 << " or you lose..." << endl;
    else if (win == 'O') cout << PlayerName2 << "You Win!  " << PlayerName1 << " or you lose..." << endl;

}
int main(int argc, char** argv) {



    do {
        cout << "Input name first player : ";
        cin >> PlayerName1;

        cout << "Input name second player: ";
        cin >> PlayerName2;
        cout << "\n";
    } while (!strcmp(PlayerName1, PlayerName2));
   
    show_cells();

    for (int move = 1; move <= 9; move++) {
        if (move % 2) make_move(1); 
        else make_move(2);

        show_cells();
      
        if (move >= 5)
        {
            win = check();
            if (win != '-')
                break;
        }
       

    }

    result();
    system("pause");
    return 0;
}