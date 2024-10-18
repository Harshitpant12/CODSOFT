#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void sample_board()
{
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << '1' << "  |   " << '2' << "  |   " << '3' << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "--------------------" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << '4' << "  |   " << '5' << "  |   " << '6' << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "--------------------" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << '7' << "  |   " << '8' << "  |   " << '9' << endl;
    cout << "   " << "   |   " << "   |   " << endl;
}

void clear_board()
{
    board[0] = ' ';
    board[1] = ' ';
    board[2] = ' ';
    board[3] = ' ';
    board[4] = ' ';
    board[5] = ' ';
    board[6] = ' ';
    board[7] = ' ';
    board[8] = ' ';
}

void show_board()
{

    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[0] << "  |   " << board[1] << "  |   " << board[2] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "--------------------" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[3] << "  |   " << board[4] << "  |   " << board[5] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "--------------------" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[6] << "  |   " << board[7] << "  |   " << board[8] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
}

void getComputerChoice()
{
    srand((unsigned int)time(NULL));
    int choice;
    do
    {
        choice = rand() % 10;
    } while (board[choice] != ' ');
    board[choice] = 'O';
}

void xChoice()
{
    while (true)
    {
        cout << "Select Your Position(1-9) : ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8)
        {
            cout << "Invalid choice!!! Please Select Your choice from (1-9). " << endl;
        }
        else if (board[choice] != ' ')
        {
            cout << "Please select an empty Position." << endl;
        }
        else
        {
            board[choice] = 'X';
            break;
        }
    }
}
void oChoice()
{
    while (true)
    {
        cout << "Select Your Position(1-9) : ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8)
        {
            cout << "Invalid choice!!! Please Select Your choice from (1-9). " << endl;
        }
        else if (board[choice] != ' ')
        {
            cout << "Please select an empty Position." << endl;
        }
        else
        {
            board[choice] = 'O';
            break;
        }
    }
}
int boardCount(char symbol)
{
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == symbol)
        {
            total += 1;
        }
    }
    return total;
}

char checkWinner()
{
    // checking winner in row
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
    {
        return board[0];
    }
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
    {
        return board[3];
    }
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
    {
        return board[6];
    }

    // checking winner in column
    if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
    {
        return board[0];
    }
    if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
    {
        return board[1];
    }
    if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
    {
        return board[2];
    }

    // checking winner in diagonal
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
    {
        return board[0];
    }
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
    {
        return board[2];
    }

    if (boardCount('X') + boardCount('O') < 9)
    {
        // it has no such use but we have to return something to continue the game so we uses c for continue.
        return 'C';
    }
    else
    {
        // we have return d so that if board has already 9 character and we've not won the game than it must be draw.
        return 'D';
    }
}

void compVsPlayer()
{
    string player_name;
    cout << "Enter your name: " << endl;
    cin >> player_name;
    cout << player_name << " your positions will be marked as X." << endl;
    while (true)
    {
        system("cls");
        show_board();
        if (boardCount('X') == boardCount('O'))
        {
            cout << player_name << "'s Turn:" << endl;
            xChoice();
        }
        else
        {
            getComputerChoice();
        }
        char winner = checkWinner();
        if (winner == 'X')
        {
            system("cls");
            show_board();
            cout << "Hurray " << player_name << "! you won the game." << endl;
            break;
        }
        else if (winner == 'O')
        {
            system("cls");
            show_board();
            cout << "Computer won the game." << endl;
            break;
        }
        else if (winner == 'D')
        {
            system("cls");
            show_board();
            cout << "Oops! It's a Draw." << endl;
            break;
        }
    }
}

void playerVsPlayer()
{
    string x_player_name, o_player_name;
    cout << "Enter 1st player name: " << endl;
    cin >> x_player_name;
    cout << x_player_name << " your positions will be marked as X." << endl;
    cout << "Enter 2nd player name: " << endl;
    cin >> o_player_name;
    cout << o_player_name << " your positions will be marked as O." << endl;
    system("pause");
    while (true)
    {
        system("cls");
        show_board();
        if (boardCount('X') == boardCount('O'))
        {
            cout << x_player_name << "'s Turn: " << endl;
            xChoice();
        }
        else
        {
            cout << o_player_name << "'s Turn: " << endl;
            oChoice();
        }
        char winner = checkWinner();
        if (winner == 'X')
        {
            system("cls");
            show_board();
            cout << "Hurray " << x_player_name << "! you won the game." << endl;
            break;
        }
        else if (winner == 'O')
        {
            system("cls");
            show_board();
            cout << "Hurray " << o_player_name << "! you won the game." << endl;
            break;
        }
        else if (winner == 'D')
        {
            system("cls");
            show_board();
            cout << "Oops! It's a Draw." << endl;
            break;
        }
    }
}

int main()
{

    //Easy level

    char play = 'y';
    do
    {
        cout << "\nThis is the sample board and the given positions will be used to take input." << endl;
        sample_board();
        // cout << "Enter any number to continue" << endl;
        system("pause");
        system("cls");

        // A computer mode is also added just for one more option
        int mode;

        cout << "There are two choices : " << endl
             << "1. Computer vs Player." << endl
             << "2.Player vs Player." << endl;
        cout << "Select mode by entering your choice as 1 or 2 : " << endl;
        cin >> mode;

        switch (mode)
        {
        case 1:
            compVsPlayer();
            break;
        case 2:
            playerVsPlayer();
            break;
        default:
            cout << "Please select valid mode." << endl;
            break;
        }
        cout << "Would you like to play again? Enter 'y' for yes or 'n' for no: ";
        cin >> play;
        system("cls");
        clear_board();
    } while (play == 'y');

    return 0;
}
