#include <bits/stdc++.h>
using namespace std;
char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};
char turn = 'X';
int row, column;
bool draw = true;

void display()
{
    system("cls");
    cout << "\t\tWelcome to Tic Tac Toe" << endl;
    cout << "\nPlyer1 [X]\n player2 [O]\n\n"
         << endl;

    cout << "      |      |      " << endl;
    cout << "  " << board[0][0] << "   |  " << board[0][1] << "   |  " << board[0][2] << endl;
    cout << "______|______|______" << endl;
    cout << "      |      |      " << endl;
    cout << "  " << board[1][0] << "   |  " << board[1][1] << "   |  " << board[1][2] << endl;
    cout << "______|______|______" << endl;
    cout << "      |      |      " << endl;
    cout << "  " << board[2][0] << "   |  " << board[2][1] << "   |  " << board[2][2] << endl;
    cout << "      |      |      " << endl;
}

void player_turn()
{
    int choice;
    cout << "choice a number: ";
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
        row = 1;
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
        cout << "Invalid choice! Please try again \n";
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
        cout << "Box already filled! \n Please try again!!\n\n";
        player_turn();
    }
}

int game_over()
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]))
        {
            return false;
        }
        if ((board[0][i] == board[1][i] && board[0][i] == board[2][i]))
        {
            return false;
        }
        if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]))
        {
            return false;
        }
        if ((board[0][2] == board[1][1] && board[0][2] == board[2][0]))
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

    while (game_over())
    {
        display();
        player_turn();
    }
    display();
    if (turn == 'X' && draw)
    {
        cout << "Player2 [O] Win !! Congratulation";
    }
    else if (turn == 'O' && draw)
    {
        cout << "Player1 [X] Win !! Congratulation";
    }
    else
    {
        cout << "Game Draw!!";
    }

    return 0;
}