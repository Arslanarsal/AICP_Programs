#include <bits/stdc++.h>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int row, column;
bool draw = true;

void display()
{
    cout << "      |     |     " << endl;
    cout << "   " << board[0][0] << "  |  " << board[0][1] << "  |   " << board[0][2] << endl;
    cout << "______|_____|_____" << endl;
    cout << "      |     |     " << endl;
    cout << "   " << board[1][0] << "  |  " << board[1][1] << "  |   " << board[1][2] << endl;
    cout << "______|_____|_____" << endl;
    cout << "      |     |     " << endl;
    cout << "   " << board[2][0] << "  |  " << board[2][1] << "  |   " << board[2][2] << endl;
    cout << "      |     |     " << endl;
}

void player_turn()
{
    int choice;
    cout << "Choice a Number: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;

    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 2;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;

    default:
        cout << "Invalid choice" << endl;
        player_turn();
        break;
    }
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "Box already filled" << endl;
        player_turn();
    }
}

int gameover()
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == board[i][1]) && board[i][0] == board[i][2])
        {

            return false;
        }
        if ((board[0][i] == board[1][i]) && board[0][i] == board[2][i])
        {
            return false;
        }
        if ((board[0][0] == board[1][1]) && board[0][0] == board[2][2])
        {
            return false;
        }
        if ((board[0][2] == board[1][1]) && board[0][1] == board[1][1])
        {
            return false;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return true;
            }
        }
    }
    draw = false;
    return true;
}

int main()
{
    while (gameover())
    {
        display();
        player_turn();
    }

    display();
    if (turn == 'X' && draw)
    {
        cout << "player [O] win\n";
    }
    else if (turn == 'O' && draw)
    {
        cout << "player [X] win\n";
    }
    else
    {
        cout << "Game draw" << endl;
    }

    return 0;
}