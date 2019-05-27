//Tic Tac Toe - 1 Player
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

char boardItems[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int score[] = {0, 0};

void drawBoard();
void resetGame(int &player, char &win, int &plays);
char checkValid(int);
char checkWin();
int getMoves();
int getRandomMove();

int main() {
	char win = 'N';
	int player = 1;
	int choice = 0;
	char correct = ' ';
	char symbol = ' ';
	int plays = 0;

	srand(static_cast<int>(time(0)));
	while (choice != -1) {
		while (win != 'Y' && plays < 9) {
			drawBoard();

			if (player > 2)
				player = 1;

			if (player == 1) {
				cout << "Player #" << player << endl;
				cout << "Enter a box number: ";
				cin >> choice;
			}
			else {
				if (plays == 1)
					choice = getRandomMove();
				else
					choice = getMoves();

			}

			if (player == 1)
				symbol = 'X';
			else
				symbol = 'O';

			correct = checkValid(choice);
			if (correct == 'Y')
				boardItems[choice] = symbol;
			else {
				cout << "Invalid move" << endl;
				player--;
				plays--;
				cin.ignore();
				cin.get();
			}

			win = checkWin();
			player++;
			plays++;
		}

		drawBoard();
		player -= 1;
		if (win == 'Y') {
			cout << "Player #" << player << " won!" << endl;

			switch (player) {
			case 1:
				score[0] += 1;
				break;
			case 2:
				score[1] += 1;
				break;
			}
		}
		else if (plays > 8)
			cout << "Draw" << endl;

		resetGame(player, win, plays);
		cout << "Enter '-1' to Quit " << endl;
		cout << "Enter any number to continue: ";
		cin >> choice;
		system("cls");
	}
	//system("pause");
	return 0;
}

void drawBoard() {
	system("clear");

	cout << "\tTic-Tac-Toe" << endl << endl;
	cout << "  " << boardItems[1] << "  |  " << boardItems[2] << "  |  " << boardItems[3] << endl;
	cout << "----------------" << endl;
	cout << "  " << boardItems[4] << "  |  " << boardItems[5] << "  |  " << boardItems[6] << endl;
	cout << "----------------" << endl;
	cout << "  " << boardItems[7] << "  |  " << boardItems[8] << "  |  " << boardItems[9] << endl;
	cout << endl << endl;
	cout << "Player 1 (X)   :   Player 2 (O)" << endl;

}

char checkValid(int choice) {
	char digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char validation = digits[choice];
	char correct = ' ';

	if (choice > 0 && choice < 10) {
		if (boardItems[choice] == validation)
			correct = 'Y';
		else
			correct = 'N';
	}
	else
		correct = 'N';

	return correct;
}

char checkWin() {
	char win = 'N';
	char draw = 'N';

	if (boardItems[1] == boardItems[2] && boardItems[2] == boardItems[3])
		win = 'Y';
	else if (boardItems[4] == boardItems[5] && boardItems[5] == boardItems[6])
		win = 'Y';
	else if (boardItems[7] == boardItems[8] && boardItems[8] == boardItems[9])
		win = 'Y';
	else if (boardItems[1] == boardItems[4] && boardItems[4] == boardItems[7])
		win = 'Y';
	else if (boardItems[2] == boardItems[5] && boardItems[5] == boardItems[8])
		win = 'Y';
	else if (boardItems[3] == boardItems[6] && boardItems[6] == boardItems[9])
		win = 'Y';
	else if (boardItems[1] == boardItems[5] && boardItems[5] == boardItems[9])
		win = 'Y';
	else if (boardItems[3] == boardItems[5] && boardItems[5] == boardItems[7])
		win = 'Y';
	else
		win = 'N';

	return win;
}

int getMoves() {
	int move = 0;
	char correct = 'N';
	char possibleMoves[10] = {' '};

	possibleMoves[0] = 'N';
	for (int i = 1; i <= 9; i++) {
		possibleMoves[i] = checkValid(i);
	}

	if (possibleMoves[1] == 'Y' && ((boardItems[2] == boardItems[3]) || (boardItems[4] == boardItems[7]) || (boardItems[5] == boardItems[9]))) {
		move = 1;
	}
	if (possibleMoves[2] == 'Y' && ((boardItems[1] == boardItems[3]) || (boardItems[5] == boardItems[8]))) {
		move = 2;
	}
	if (possibleMoves[3] == 'Y' && ((boardItems[1] == boardItems[2]) || (boardItems[6] == boardItems[9]) || (boardItems[5] == boardItems[7]))) {
		move = 3;
	}
	if (possibleMoves[4] == 'Y' && ((boardItems[5] == boardItems[6]) || (boardItems[1] == boardItems[7]))) {
		move = 4;
	}
	if (possibleMoves[5] == 'Y' && ((boardItems[4] == boardItems[6]) || (boardItems[2] == boardItems[8]) || (boardItems[1] == boardItems[9]) || (boardItems[3] == boardItems[7]))) {
		move = 5;
	}
	if (possibleMoves[6] == 'Y' && ((boardItems[4] == boardItems[5]) || (boardItems[3] == boardItems[9]))) {
		move = 6;
	}
	if (possibleMoves[7] == 'Y' && ((boardItems[8] == boardItems[9]) || (boardItems[1] == boardItems[4]) || (boardItems[3] == boardItems[5]))) {
		move = 7;
	}
	if (possibleMoves[8] == 'Y' && ((boardItems[7] == boardItems[9]) || (boardItems[2] == boardItems[5]))) {
		move = 8;
	}
	if (possibleMoves[9] == 'Y' && ((boardItems[7] == boardItems[8]) || (boardItems[3] == boardItems[6]) || (boardItems[1] == boardItems[5]))) {
		move = 9;
	}

	correct = checkValid(move);
	while (correct == 'N') {
		move = getRandomMove();
		correct = checkValid(move);
	}

	return move;
}

int getRandomMove() {
	char correct = 'N';
	int move = 0;

	while (correct == 'N') {
		move = 1 + rand() % (9 + 1 - 1);
		correct = checkValid(move);
	}

	return move;
}

void resetGame(int &player, char &win, int &plays) {
	player = 1;
	win = 'N';
	plays = 0;
	double winPercentage[] = {0.0, 0.0};
	double total = score[0] + score[1];

	char digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	for (int i = 0; i < 10; i++) {
		boardItems[i] = digits[i];
	}

	if (total > 0) {
		winPercentage[0] = (score[0] / total) * 100;
		winPercentage[1] = (score[1] / total) * 100;
	}

	cout << endl;
	cout << "\tScore\n\t" << score[0] << " : " << score[1] << endl << endl;

	cout << fixed << setprecision(0);
	cout << "Player #1 Win Percentage: " << winPercentage[0] << "%" << endl;
	cout << "Player #2 Win Percentage: " << winPercentage[1] << "%" << endl;
	cout << endl;
}
