/*
CODED BY :
  █████╗    ██████╗     █████╗  
 ██╔══██╗  ██╔═══██╗   ██╔══██╗ 
 ╚█████╔╝  ██║   ██║   ╚█████╔╝ 
 ██╔══██╗  ██║   ██║   ██╔══██╗ 
 ╚█████╔╝  ╚██████╔╝   ╚█████╔╝ 
  ╚════╝    ╚═════╝    ╚════╝  
*/



#include <iostream>
#include <windows.h>
using namespace std;

char board_Plays[9];

char player1, player2, choose;

int position1, position2, rate;

int StopperCounter = 0;

void Board();
void Default_Board();
bool Full_Board();
bool results();
void new_game();


int main()
{



    cout << "=========================================================\n";
    cout << "                                                         \n";
    cout << "====== Welcome To Ur Friendly-Neighborhood X0 Game ======\n";
    cout << "                                                         \n";
    cout << "=========================================================\n";

    cout << "\n";
    cout << "Welcome, Player 1 !\n\n\n";
    cout << "\n============================== <x><o><x><o>\n";
    cout << "// Choose Your Play (X or O) :\n\n";

    cin >> player1;
    cout << "\n\n";
    

    cout << "Welcome, Player 2 !\n\n\n";
    cout << "\n============================== <x><o><x><o>\n";
    cout << "Player 1 Has Chosen : " << player1 << " !\n\n";
    cout << "// Choose Your Play (X or O) : \n\n";

    cin >> player2;
    cout << "\n\n";

    cout << "[x][o] Player 1 ====> " << player1 << endl << endl;
    cout << "[o][x] Player 2 ====> " << player2 << endl << endl;
    

    cout << "\n\n|=|=|=|=|   Get Ready !   |=|=|=|=|\n\n\n\n";
    

    Sleep(2000);

    
    new_game();
    Default_Board();


    for (int i = 0;; i++)
    {
        cout << "\n\n==> Player 1, Choose Position To Play In ( 1 - 9 ) : <==\n\n";
        cin >> position1;

        while (position1 < 1 || position1 > 9 || board_Plays[position1 - 1] != ' ')
        {
            cout << "\n\n==> Invalid position! Choose again (1 - 9) : <==\n\n";
            cin >> position1;
        }

        board_Plays[position1 - 1] = player1;
        cout << endl;
        Board();

        if (results() || Full_Board())
        {
            if (Full_Board() && !results())
            {
                cout << "\n\n==> DRAW ! <==\n\n" << endl;
            }
            else
            {
                cout << "\n\n==> Player 1 Wins ! <==\n\n" << endl;
            }

            cout << "\n\n==> Do You Want To Play Again [ y / n ] ? <==\n\n" << endl;
            cin >> choose;

            if (choose == 'y' || choose == 'Y')
            {
                cout << "\n\n==> Ok, Let's Goooo <3 <==\n\n" << endl;
                main();
            }
            else if (choose == 'n' || choose == 'N')
            {
                cout << "\n\n==> Rate The Work Please Out of 10 <3, Good-Bye ! <==\n\n" << endl;
                cin >> rate;
                cout << "\n\n THANK YOU SM FOR THE FEEDBACK <3 \n\n  " << "Rate : " << rate << "/10\n\n";
                Sleep(100000);
                return 0;
            }
        }

        cout << "\n\n==> Player 2, Choose Position To Play In ( 1 - 9 ) : <==\n\n" << endl;
        cin >> position2;

        while (position2 < 1 || position2 > 9 || board_Plays[position2 - 1] != ' ')
        {
            cout << "\n\n==> Invalid position! Choose again (1 - 9) : <==\n\n";
            cin >> position2;
        }

        board_Plays[position2 - 1] = player2;
        cout << endl;
        Board();

        if (results() || Full_Board())
        {
            if (Full_Board() && !results())
            {
                cout << "\n\n==> DRAW ! <==\n\n" << endl;
            }
            else
            {
                cout << "\n\n==> Player 2 Wins ! <==\n\n" << endl;
            }

            cout << "\n\n==> Do You Want To Play Again [ y / n ] ? <==\n\n" << endl;
            cin >> choose;

            if (choose == 'y' || choose == 'Y')
            {
                cout << "\n\n==> Ok, Let's Goooo <3 <==\n\n" << endl;
                main();
            }
            else if (choose == 'n' || choose == 'N')
            {
                cout << "\n\n==> Rate The Work Please Out of 10 <3, Good-Bye ! <==\n\n" << endl;
                Sleep(100000);
                return 0;
            }
        }
    }

    return 0;
}

void Board()
{
    cout << " " << board_Plays[0] << " || " << board_Plays[1] << " || " << board_Plays[2] << " " << endl;
    cout << "=============\n";
    cout << " " << board_Plays[3] << " || " << board_Plays[4] << " || " << board_Plays[5] << " " << endl;
    cout << "=============\n";
    cout << " " << board_Plays[6] << " || " << board_Plays[7] << " || " << board_Plays[8] << " " << endl;
}

void Default_Board()
{
    cout << " " << "1" << " || " << "2" << " || " << "3" << " " << endl;
    cout << "=============\n";
    cout << " " << "4" << " || " << "5" << " || " << "6" << " " << endl;
    cout << "=============\n";
    cout << " " << "7" << " || " << "8" << " || " << "9" << " " << endl;
}

void new_game()
{
    for (int i = 0; i < 9; i++)
    {
        board_Plays[i] = ' ';
    }
}

bool results()
{
    if (board_Plays[0] == board_Plays[1] && board_Plays[1] == board_Plays[2] && board_Plays[0] == player1)
    {
        StopperCounter++;
        return true;
    }
    else if (board_Plays[0] == board_Plays[1] && board_Plays[1] == board_Plays[2] && board_Plays[0] == player2)
    {
        StopperCounter++;
        return true;
    }
    else if (board_Plays[3] == board_Plays[4] && board_Plays[4] == board_Plays[5] && board_Plays[3] == player1)
    {
        StopperCounter++;
        return true;
    }
    else if (board_Plays[3] == board_Plays[4] && board_Plays[4] == board_Plays[5] && board_Plays[3] == player2)
    {
        StopperCounter++;
        return true;
    }
    else if (board_Plays[6] == board_Plays[7] && board_Plays[7] == board_Plays[8] && board_Plays[6] == player1)
    {
        StopperCounter++;
        return true;
    }
    else if (board_Plays[6] == board_Plays[7] && board_Plays[7] == board_Plays[8] && board_Plays[6] == player2)
    {
        StopperCounter++;
        return true;
    }
    else if (board_Plays[0] == board_Plays[3] && board_Plays[3] == board_Plays[6] && board_Plays[0] == player1)
    {
        StopperCounter++;
        return true;
    }
    else if (board_Plays[0] == board_Plays[3] && board_Plays[3] == board_Plays[6] && board_Plays[0] == player2)
    {
        StopperCounter++;
        return true;
    }
    else if (board_Plays[1] == board_Plays[4] && board_Plays[4] == board_Plays[7] && board_Plays[1] == player1)
    {
        StopperCounter++;
        return true;
    }
    else if (board_Plays[1] == board_Plays[4] && board_Plays[4] == board_Plays[7] && board_Plays[1] == player2)
    {
        StopperCounter++;
        return true;
    }
    else if (board_Plays[2] == board_Plays[5] && board_Plays[5] == board_Plays[8] && board_Plays[2] == player1)
    {
        StopperCounter++;
        return true;
    }
    else if (board_Plays[2] == board_Plays[5] && board_Plays[5] == board_Plays[8] && board_Plays[2] == player2)
    {
        StopperCounter++;
        return true;
    }
    else if (board_Plays[0] == board_Plays[4] && board_Plays[4] == board_Plays[8] && board_Plays[0] == player1)
    {
        StopperCounter++;
        return true;
    }
    else if (board_Plays[0] == board_Plays[4] && board_Plays[4] == board_Plays[8] && board_Plays[0] == player2)
    {
        StopperCounter++;
        return true;
    }
    else if (board_Plays[2] == board_Plays[4] && board_Plays[4] == board_Plays[6] && board_Plays[2] == player1)
    {
        StopperCounter++;
        return true;
    }
    else if (board_Plays[2] == board_Plays[4] && board_Plays[4] == board_Plays[6] && board_Plays[2] == player2)
    {
        StopperCounter++;
        return true;
    }

    return false;
}

bool Full_Board()
{
    for (int i = 0; i < 9; ++i)
    {
        if (board_Plays[i] == ' ')
        {
            return false;
        }
    }
    return true;
}
