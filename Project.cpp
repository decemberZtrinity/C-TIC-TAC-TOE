//#include <iostream>
#include <iostream>

using namespace std;


//void manual()
//{
//	cout << "WELCOME TICTACTOE" << endl;
//	cout << "GUIDE" << endl << endl;
//	cout << "1 2 3" << endl;
//	cout << "4 5 6" << endl;
//	cout << "7 8 9" << endl;
//
//
//}

void initialize(char board[3][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}


void display(char board[3][3])
{
	cout << endl << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j];
			if (j < 2)
			{
				cout << " | ";
			}

		}
		cout << endl;
		if (i < 2)
		{
			cout << "--+---+--";

		}


	}


}




bool checkwin(char board[3][3])
{
	bool Suc = false;
	// HORIZONTAL WINS

	for (int i = 0; i < 3; i++)
	{

		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			Suc = true;

	}


	// VERTICAL WINS

	for (int i = 0; i < 3; i++)
	{

		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			Suc = true;

	}



	// DIAGNOL WINS

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		Suc = true;

	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		Suc = true;

	}



	return Suc;
}

void WorkingFunction(char board[3][3], char x , char y)
{
	


}





int main()
{
	char board[3][3];
	char choice1, choice2;
	char currentPlayer = 'X';


	// manual();
	initialize(board);
	display(board);


	while (true) {
		display(board);

		int choice;
		cout << "Player " << currentPlayer << ", enter position (1-9): ";
		cin >> choice;

		if (choice < 1 || choice > 9) {
			cout << "Invalid position!\n";
			continue;
		}

		int row = (choice - 1) / 3; // MOVES HORIZONTAL
		int col = (choice - 1) % 3; // MOVES VERTICAL

		if (board[row][col] != ' ') 
		{
			cout << "Cell already filled!\n";
			continue;
		}

		board[row][col] = currentPlayer;

		if (checkwin(board))
		{
			display(board);
		
			cout << "Player " << currentPlayer << " wins!\n";
			
			break;
		}

		currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
	}



}

