#include "logicGame.h"

LogicGame::LogicGame() {
	
}

int checkArray(string array[numberWins]) {
	int score = 0;
	if (array[0] == "x"){
		if (array[0] == array[1] && array[1] == array[2] && array[2] == array[3] && array[3] == array[4]) {
			//if(array[0] == array[1] && array[1] == array[2]){
			return score + 10;
		}
	}
	else if(array[0] == "o") {
		if (array[0] == array[1] && array[1] == array[2] && array[2] == array[3] && array[3] == array[4]) {
		//if (array[0] == array[1] && array[1] == array[2]) {
		return score - 10;
		}
	}
	return 0;
}

int LogicGame::checkHorizontal(Matrix board, int rows, int cols) {
	int countCols = 0;
	string array[numberWins];
	for (int j = 0; j < rows; j++) {
		for (int i = 0; i < cols - numberWins + 1; i++) {
			int start_cols = i;
			while (countCols < numberWins) {
				array[countCols] = board.getValueSquare(j, start_cols);
				start_cols++;
				countCols++;
			}
			countCols = 0;
			int wins = checkArray(array);
			if (wins == 10) {
				return 10;
			}
			else if (wins == -10){
				return -10;
			}
		}
	}
	return 1;
}

int LogicGame::checkVertical(Matrix board, int rows, int cols) {
	int countRows = 0;
	string array[numberWins];
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < cols - numberWins + 1; i++) {
			int start_rows = i;
			while (countRows < numberWins) {
				array[countRows] = board.getValueSquare(start_rows, j);
				start_rows++;
				countRows++;
			}
			countRows = 0;
			int wins = checkArray(array);
			if (wins == 10) {
				return 10;
			}
			else if (wins == -10) {
				return -10;
			}
		}
	}
	return 1;
}

int LogicGame::checkDiagonalLeft(Matrix board, int rows, int cols) {
	int countDiagonals = 0;
	int leftToRight = 0;
	string array[numberWins];
	while(leftToRight < (cols - numberWins + 1)) {
		for (int i = 0; i < (rows - numberWins + 1); i++) {
			int start_diagonals = i;
			while (countDiagonals < numberWins) {
				array[countDiagonals] = board.getValueSquare(start_diagonals, start_diagonals + leftToRight);
				countDiagonals++;
				start_diagonals++;
			}
			countDiagonals = 0;
			int wins = checkArray(array);
			if (wins == 10) {
				return 10;
			}
			else if (wins == -10) {
				return -10;
			}
		}
		rows--;
		leftToRight++;
	}

	return 1;
}

int LogicGame::checkDiagonalLeftBottom(Matrix board, int rows, int cols) {
	int countDiagonals = 0;
	int leftToRight = 0;
	string array[numberWins];
	while (leftToRight < (rows - numberWins + 1)) {
		for (int i = 0; i < (cols - numberWins); i++) {
			int start_diagonals = i ;
			while (countDiagonals < numberWins) {
				array[countDiagonals] = board.getValueSquare(start_diagonals + 1 + leftToRight, start_diagonals );
				countDiagonals++;
				start_diagonals++;
			}
			countDiagonals = 0;
			int wins = checkArray(array);
			if (wins == 10) {
				return 10;
			}
			else if (wins == -10) {
				return -10;
			}
		}
		cols--;
		leftToRight++;
	}

	return 1;
}


int LogicGame::checkDiagonalRight(Matrix board, int rows, int cols) {
	int countDiagonals = 0;
	int RightToLeft = 0;
	int x, y;
	string array[numberWins];
	while (RightToLeft < (cols - numberWins + 1)) {
		for (int i = 0; i < (rows - numberWins + 1); i++) {
			int start_diagonals = i;
			while (countDiagonals < numberWins) {
				x = start_diagonals;
				y = cols - 1 - start_diagonals - RightToLeft;
				array[countDiagonals] = board.getValueSquare(x, y);
				countDiagonals++;
				start_diagonals++;
			}
			countDiagonals = 0;
			int wins = checkArray(array);
			if (wins == 10) {
				return 10;
			}
			else if (wins == -10) {
				return -10;
			}
		}
		rows--;
		RightToLeft++;
	}

	return 1;
}

int LogicGame::checkDiagonalRightBottom(Matrix board, int rows, int cols) {
	int countDiagonals = 0;
	int RightToLeft = 0;
	string array[numberWins];
	while (RightToLeft < (cols - numberWins)) {
		for (int i = 0; i < (rows - numberWins); i++) {
			int start_diagonals = i;
			while (countDiagonals < numberWins) {
				array[countDiagonals] = board.getValueSquare(start_diagonals + 1 + RightToLeft, cols - 1 - start_diagonals);
				countDiagonals++;
				start_diagonals++;
			}
			countDiagonals = 0;
			int wins = checkArray(array);
			if (wins == 10) {
				return 10;
			}
			else if (wins == -10) {
				return -10;
			}
		}
		rows--;
		RightToLeft++;
	}

	return 1;
}

void LogicGame::logicControl(Matrix board, int& x, int& y, int& posX, int& posY, string playerCurrent) {
	char key = 1;
	Console g1;
	while (key != playerCurrent[0]) {
		key = _getch();
		switch (key) {
		case 'w':
			posY = board.checkBoundaryRowsTop(key, posY, board);
			y = 2 * posY;
			break;
		case 's':
			posY = board.checkBoundaryRowsBottom(key, posY, board);
			y = posY * 2;
			break;
		case 'a':
			posX = board.checkBoundaryColsLeft(key, posX, board);
			x = 2 * posX;
			break;
		case 'd':
			posX = board.checkBoundaryColsRight(key, posX, board);
			x = posX * 2;
			break;

		}
		g1.moveCursor(x, y);
	}
}

void LogicGame::logicTurn(Matrix board, int x, int y, string playerCurrent) {
	if (board.getValueSquare(x, y) == " ") {
		cout << playerCurrent;
		board.setValueSquare(x, y, playerCurrent);
	}
}

void LogicGame::switchPlayer(string &playerCurrent) {
	playerCurrent = (playerCurrent == "x") ? "o" : "x";
}

int LogicGame::moveLeft(Matrix board)
{
	int rows = board.getRows();
	int cols = board.getCols();
	int count = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (board.getValueSquare(i, j) == " ") {
				count++;
			}
		}
	}
	return count;
}

