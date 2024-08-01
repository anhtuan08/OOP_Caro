#include "logicGame.h"

LogicGame::LogicGame() {
	
}

bool checkArray(string array[numberWins]) {
	if (array[0] == "x"){
		if (array[0] == array[1] && array[1] == array[2] && array[2] == array[3] && array[3] == array[4]) {
			return true;
		}
	}
	else if(array[0] == "o") {
		if (array[0] == array[1] && array[1] == array[2] && array[2] == array[3] && array[3] == array[4]) {
			return true;
		}
	}
	return false;
}

bool LogicGame::checkHorizontal(Matrix board, int rows, int cols) {
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
			if (checkArray(array))
				return true;
		}

	}
	return false;
}

bool LogicGame::checkVertical(Matrix board, int rows, int cols) {
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
				if (checkArray(array))
			return true;
		}

	}
	return false;
}

bool LogicGame::checkDiagonalLeft(Matrix board, int rows, int cols) {
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
			if (checkArray(array))
				return true;
		}
		rows--;
		leftToRight++;
	}

	return false;
}

bool LogicGame::checkDiagonalLeftBottom(Matrix board, int rows, int cols) {
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
			if (checkArray(array))
				return true;
		}
		cols--;
		leftToRight++;
	}

	return false;
}


bool LogicGame::checkDiagonalRight(Matrix board, int rows, int cols) {
	int countDiagonals = 0;
	int RightToLeft = 0;
	string array[numberWins];
	while (RightToLeft < (cols - numberWins + 1)) {
		for (int i = 0; i < (rows - numberWins + 1); i++) {
			int start_diagonals = i;
			while (countDiagonals < numberWins) {
				array[countDiagonals] = board.getValueSquare(start_diagonals, rows - 1 - start_diagonals - RightToLeft);
				countDiagonals++;
				start_diagonals++;
			}
			countDiagonals = 0;
			if (checkArray(array))
				return true;
		}
		rows--;
		RightToLeft++;
	}

	return false;
}

bool LogicGame::checkDiagonalRightBottom(Matrix board, int rows, int cols) {
	int countDiagonals = 0;
	int RightToLeft = 0;
	string array[numberWins];
	while (RightToLeft < (rows - numberWins + 1)) {
		for (int i = 0; i < (rows - numberWins); i++) {
			int start_diagonals = i;
			while (countDiagonals < numberWins) {
				array[countDiagonals] = board.getValueSquare(start_diagonals + 1 + RightToLeft, rows - 1 - start_diagonals);
				countDiagonals++;
				start_diagonals++;
			}
			countDiagonals = 0;
			if (checkArray(array))
				return true;
		}
		cols--;
		RightToLeft++;
	}

	return false;
}

void LogicGame::logicControl(Matrix board, int& x, int& y, int& posX, int& posY, string playerCurrent) {
	char key = '1';
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
		board.moveCursor(x, y);
	}
}

void LogicGame::logicTurn(Matrix board, int posX, int posY, string playerCurrent) {
	if (board.getValueSquare(posY, posX) == " ") {
		cout << playerCurrent;
		board.setValueSquare(posY, posX, playerCurrent);
	}
}

void LogicGame::switchPlayer(string &playerCurrent) {
	playerCurrent = (playerCurrent == "x") ? "o" : "x";
}

