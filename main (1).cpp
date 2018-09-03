#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
char matrix[3][3] = { '1', '2', '3',
                      '4', '5', '6',
                      '7', '8', '9' };
char player = 'X';
char player1[15],player2[15];

void enterName() {
    cout << "Enter your Name (PLAYER 1): ";
    gets(player1);
    cout << "Enter your Name (PLAYER 2): ";
    gets(player2);
}

void Draw()
{
	system("cls");

	cout << "\n\n\tTic Tac Toe\n\n";
	cout << player1 <<  " (X)  -  " << player2 <<" (O)" << endl << endl;
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << matrix[0][0] << "  |  " << matrix[0][1] << "  |  " << matrix[0][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << matrix[1][0] << "  |  " << matrix[1][1] << "  |  " << matrix[1][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << matrix[2][0] << "  |  " << matrix[2][1] << "  |  " << matrix[2][2] << endl;
	cout << "     |     |     " << endl << endl;
}

void Input()
{
	int a;
	if(player == 'X')
    {
        cout << player1 << "'s turn..." << endl;

    }
    else
      {
          cout << player2 << "'s turn..." << endl;

      }
	cout << "\nPress the number of the field: ";
	cin >> a;

	if (a == 1)
		matrix[0][0] = player;
	else if (a == 2)
		matrix[0][1] = player;
	else if (a == 3)
		matrix[0][2] = player;
	else if (a == 4)
		matrix[1][0] = player;
	else if (a == 5)
		matrix[1][1] = player;
	else if (a == 6)
		matrix[1][2] = player;
	else if (a == 7)
		matrix[2][0] = player;
	else if (a == 8)
		matrix[2][1] = player;
	else if (a == 9)
		matrix[2][2] = player;
}

void TogglePlayer()
{
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}

char Win()
{
	//first player
	if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
		return 'X';
	if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
		return 'X';
	if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
		return 'X';

	if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
		return 'X';
	if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
		return 'X';
	if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
		return 'X';

	if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
		return 'X';
	if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X')
		return 'X';

	//second player
	if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
		return 'O';
	if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
		return 'O';
	if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
		return 'O';

	if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
		return 'O';
	if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
		return 'O';
	if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
		return 'O';

	if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
		return 'O';
	if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')
		return 'O';

	return '/';
}

int checkDraw() {
    int flag=0;
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            if(matrix[i][j] != 'X' &&
                matrix[i][j] != 'O' )
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
    }
    return flag;
}

void reset(){
    char counter = '1';
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            matrix[i][j] = counter;
            counter++;
        }
    }
}

int main()
{
    enterName();
	top:
	Draw();
	while (1)
	{
		Input();
		Draw();
		if (Win() == 'X')
		{
		    system("COLOR 1F");
			cout << "\t\t\t" << player1 <<" wins!" << endl;
			break;
		}
		else if (Win() == 'O')
		{
		    system("color 2F");
			cout << "\t\t\t" << player2 <<" wins!" << endl;
			break;
		}
		else if(checkDraw() == 0)
        {
            system("color CF");
            cout << "\t\t\tDraw" << endl << endl;
            break;
        }
		TogglePlayer();
	}
	cout << endl << "Want to play again(Y/N) : ";
	char ch;
	cin >> ch;
	if(ch == 'y' || ch == 'Y')
    {
        reset();
        goto top;
    }
    else
    {
        system("color F0");
        system("cls");
    }
	return 0;
}
