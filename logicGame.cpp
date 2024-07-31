#include "logicGame.h"

LogicGame::LogicGame() {
	
}

bool LogicGame::checkHorizontal(Matrix board, int rows, int cols, string array[numberWins]) {
	int countCols = 0;
	for (int j = 0; j < rows; j++) {
		for (int i = 0; i < cols - numberWins + 1; i++) {
			int start_cols = i;
			while (countCols < numberWins) {
				array[countCols] = board.getValueSquare(j, start_cols);
				start_cols++;
				countCols++;
			}
			countCols = 0;
		}
		//check_array(array);
	}
	return false;
}

bool LogicGame::checkVertical(Matrix board, int rows, int cols, string array[numberWins]) {
	int countRows = 0;
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < cols - numberWins + 1; i++) {
			int start_rows = i;
			while (countRows < numberWins) {
				array[countRows] = board.getValueSquare(start_rows, j);
				start_rows++;
				countRows++;
			}
			countRows = 0;
		}
		//check_array(array);
	}
	return false;
}

bool LogicGame::checkDiagonalLeft(Matrix board, int rows, int cols, string array[numberWins]) {
	int countDiagonals = 0;
	int leftToRight = 0;
	while(leftToRight < (cols - numberWins + 1)) {
		for (int i = 0; i < (rows - numberWins + 1); i++) {
			int start_diagonals = i;
			while (countDiagonals < numberWins) {
				array[countDiagonals] = board.getValueSquare(start_diagonals, start_diagonals + leftToRight);
				countDiagonals++;
				start_diagonals++;
			}
			countDiagonals = 0;
			//if (check_array(array)) {
			//	return true;
			//}
		}
		rows--;
		leftToRight++;
	}

	return false;
}

bool LogicGame::checkDiagonalLeftBottom(Matrix board, int rows, int cols, string array[numberWins]) {
	int countDiagonals = 0;
	int leftToRight = 0;
	while (leftToRight < (rows - numberWins + 1)) {
		for (int i = 0; i < (cols - numberWins); i++) {
			int start_diagonals = i;
			while (countDiagonals < numberWins) {
				array[countDiagonals] = board.getValueSquare(start_diagonals + leftToRight, start_diagonals );
				countDiagonals++;
				start_diagonals++;
			}
			countDiagonals = 0;
			//if (check_array(array)) {
			//	return true;
			//}
		}
		cols--;
		leftToRight++;
	}

	return false;
}


bool LogicGame::checkDiagonalRight(Matrix board, int rows, int cols, string array[numberWins]) {
	int countDiagonals = 0;
	int RightToLeft = 0;
	while (RightToLeft < (cols - numberWins + 1)) {
		for (int i = 0; i < (rows - numberWins + 1); i++) {
			int start_diagonals = i;
			while (countDiagonals < numberWins) {
				array[countDiagonals] = board.getValueSquare(start_diagonals, start_diagonals + RightToLeft);
				countDiagonals++;
				start_diagonals++;
			}
			countDiagonals = 0;
			//if (check_array(array)) {
			//	return true;
			//}
		}
		rows--;
		RightToLeft++;
	}

	return false;
}

bool LogicGame::checkDiagonalRightBottom(Matrix board, int rows, int cols, string array[numberWins]) {
	int countDiagonals = 0;
	int RightToLeft = 0;
	while (RightToLeft < (rows - numberWins + 1)) {
		for (int i = 0; i < (cols - numberWins); i++) {
			int start_diagonals = i;
			while (countDiagonals < numberWins) {
				array[countDiagonals] = board.getValueSquare(start_diagonals + RightToLeft, start_diagonals);
				countDiagonals++;
				start_diagonals++;
			}
			countDiagonals = 0;
			//if (check_array(array)) {
			//	return true;
			//}
		}
		cols--;
		RightToLeft++;
	}

	return false;
}

