#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
=======
char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};
>>>>>>> 8d5529c6aa0bb75fd179b69f413678872405cf17
char turn = 'X';
int row, column;
bool draw = true;

void display()
{
<<<<<<< HEAD
    cout << "      |     |     " << endl;
    cout << "   " << board[0][0] << "  |  " << board[0][1] << "  |   " << board[0][2] << endl;
    cout << "______|_____|_____" << endl;
    cout << "      |     |     " << endl;
    cout << "   " << board[1][0] << "  |  " << board[1][1] << "  |   " << board[1][2] << endl;
    cout << "______|_____|_____" << endl;
    cout << "      |     |     " << endl;
    cout << "   " << board[2][0] << "  |  " << board[2][1] << "  |   " << board[2][2] << endl;
    cout << "      |     |     " << endl;
=======
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
>>>>>>> 8d5529c6aa0bb75fd179b69f413678872405cf17
}

void player_turn()
{
    int choice;
<<<<<<< HEAD
    cout << "Choice a Number: ";
    cin >> choice;

=======
    cout << "choice a number: ";
    cin >> choice;
>>>>>>> 8d5529c6aa0bb75fd179b69f413678872405cf17
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
<<<<<<< HEAD

=======
>>>>>>> 8d5529c6aa0bb75fd179b69f413678872405cf17
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
<<<<<<< HEAD
        row = 2;
=======
        row = 1;
>>>>>>> 8d5529c6aa0bb75fd179b69f413678872405cf17
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
<<<<<<< HEAD
        cout << "Invalid choice" << endl;
        player_turn();
        break;
    }
=======
        cout << "Invalid choice! Please try again \n";
        player_turn();
        break;
    }

>>>>>>> 8d5529c6aa0bb75fd179b69f413678872405cf17
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
<<<<<<< HEAD
        cout << "Box already filled" << endl;
=======
        cout << "Box already filled! \n Please try again!!\n\n";
>>>>>>> 8d5529c6aa0bb75fd179b69f413678872405cf17
        player_turn();
    }
}

<<<<<<< HEAD
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
=======
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
>>>>>>> 8d5529c6aa0bb75fd179b69f413678872405cf17
        {
            return false;
        }
    }
<<<<<<< HEAD
=======

>>>>>>> 8d5529c6aa0bb75fd179b69f413678872405cf17
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
<<<<<<< HEAD
    while (gameover())
=======

    while (game_over())
>>>>>>> 8d5529c6aa0bb75fd179b69f413678872405cf17
    {
        display();
        player_turn();
    }
<<<<<<< HEAD

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
=======
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
>>>>>>> 8d5529c6aa0bb75fd179b69f413678872405cf17
    }

    return 0;
}