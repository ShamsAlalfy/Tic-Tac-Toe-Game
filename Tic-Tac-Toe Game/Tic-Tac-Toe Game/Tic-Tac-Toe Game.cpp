#include <iostream>
#include <conio.h>
using namespace std;

bool rows(char, char*);
bool cols(char, char*);
bool diag(char, char*);
void drawBoard(char*);
bool isValidSpots(char, char*, int);
bool Win(char, char*,char&);
bool noWinner(int, bool, char*);
bool X_or_O(char, int, char*, int&, int&, bool&,char&);
void Game(int&,int&,int&,char&);
bool PlayAgain();

int main()
{
	int xo = 0;
	int WinnerX = 0, WinnerO = 0;
	char LastWinner = 'O';
	do
	{
		Game(xo,WinnerX,WinnerO,LastWinner);
	} while (PlayAgain());
	system("cls");
	cout << "Final Result : \n";
	cout << "X = " << WinnerX << " , O = " << WinnerO << endl;
	cout << "\nThanks for playing our game" << endl;
	return 0;
}

bool rows(char c, char* board)
{
	if ((board[0] == c && board[1] == c && board[2] == c) ||
		(board[3] == c && board[4] == c && board[5] == c) ||
		(board[6] == c && board[7] == c && board[8] == c))
		return true;
	else
		return false;
}
bool cols(char c, char* board)
{
	if ((board[0] == c && board[3] == c && board[6] == c) ||
		(board[1] == c && board[4] == c && board[7] == c) ||
		(board[2] == c && board[5] == c && board[8] == c))
		return true;
	else
		return false;
}
bool diag(char c, char* board)
{
	if ((board[0] == c && board[4] == c && board[8] == c) ||
		(board[2] == c && board[4] == c && board[6] == c))
		return true;
	else
		return false;
}
void drawBoard(char* board)
{
	cout << "Game Board : \n\n\n";
	for (int i = 0; i < 9; i++)
	{
		cout << " " << board[i] << " ";
		if (i == 2 || i == 5 || i == 8)
			cout << "\n";
		else
			cout << "|";
	}
}
bool isValidSpots(char c, char* board, int answer)
{
	if (!(board[answer - 1] == 'X' || board[answer - 1] == 'O' || answer < 1 || answer > 9))
	{
		board[answer - 1] = c;
		return true;
	}
	else
		return false;
}
bool Win(char c, char* board,char& LastWinner)
{
	bool win = false;
	if (rows(c, board) || cols(c, board) || diag(c, board))
	{
		win = true;
		drawBoard(board);
		cout << "Game Result : " << c << " WON!" << endl;
		LastWinner = c;
	}
	return win;
}
bool noWinner(int nospot, bool win, char* spots)
{
	if (nospot == 0 && win == false)
	{
		drawBoard(spots);
		cout << "Game Result : DRAW :(" << endl;
		return true;
	}
	return false;
}
bool X_or_O(char c, int answer, char* board, int& xo, int& nospot, bool& win,char& LastWinner)
{
	cout << c << "?";
	cin >> answer;
	if (isValidSpots(c, board, answer))
	{
		xo++;
		nospot--;
	}
	else
		cout << "This spot is already taken or invalid. Try again." << endl;
	win = Win(c, board, LastWinner);
	return win;
}
void Game(int& xo,int& WinnerX,int& WinnerO,char& LastWinner)
{
	char board[9] = { '1','2','3','4','5','6','7','8','9' };
	int answer = 0;
	bool win = false;
	int nospot = 9;
	while (!win)
	{
		drawBoard(board);
		cout << "Where Do You Want To Place Your ";
		if (xo % 2 == 0)
		{
			if (X_or_O('X', answer, board, xo, nospot, win, LastWinner))
			{
				if (LastWinner == 'X')
				{
					xo = 1;
					WinnerX++;
				}
				else
				{
					xo = 0;
					WinnerO++;
				}
			}
			if (noWinner(nospot, win, board))
				break;
		}
		else
		{
			if (X_or_O('O', answer, board, xo, nospot, win, LastWinner))
			{
				if (LastWinner == 'X')
				{
					xo = 1;
					WinnerX++;
				}
				else
				{
					xo = 0;
					WinnerO++;
				}
			}
			if (noWinner(nospot, win, board))
				break;
		}
	}
	cout << endl;
}
bool PlayAgain()
{
	cout << "Do you want to play again ?    press y for YES and n for NO  ";
	char input = _getch();
	if (input == 'y')
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t\t\tNEW GAME " << endl;
		cout << "\n------------------------------------------------------------------------------------------------------------------------";
		return true;
	}
	else
		return false;
}