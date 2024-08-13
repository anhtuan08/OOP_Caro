#include "AIplayer.h"

void AIplayer::checkAvailable(int rows, int cols, Matrix board, Console g1)
{
	int flag = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//check available
			if (board.getValueSquare(i, j) == " " && flag == 0) {
				board.setValueSquare(i, j, aiPlayer);
				showAIMove(i, j, g1);
				flag = 1;
			}
		}
	}
	
}

void AIplayer::showAIMove(int posY, int posX, Console g1)
{
	int cursorX = posX * 2;
	int cursorY = posY * 2;

	g1.gotoXY(cursorX, cursorY);

	cout << aiPlayer;
}

void AIplayer::bestMove(Matrix board)

{
	int rows = board.getRows();
	int cols = board.getCols();

	int pointX = 0, pointY = 0;
	Console g1;

	int bestscore = 100000000;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//If available
			if (board.getValueSquare(i, j) == " ") {
				board.setValueSquare(i, j, aiPlayer);
				int score = miniMax(board, 0, true);
				if (score < bestscore) {
					bestscore = score;
					pointX = i;
					pointY = j;
				}
				board.setValueSquare(i, j, " ");
				}
			}
		}
	board.setValueSquare(pointX, pointY, aiPlayer);
	showAIMove(pointY, pointX, g1);
}

int AIplayer::miniMax(Matrix board, int dept, bool isMinimaxing)
{
	int rows = board.getRows();
	int cols = board.getCols();

	Game game1;
	LogicGame logic1;
	int turn = 0;
	int res = game1.gameWon(board, logic1, turn);
	if (res == 10) {
		return res - dept;
	}
	else if (res == -10) {
		return res + dept;
	}
	else {

		if (isMinimaxing) {
			int bestScore = -10000;
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					if (board.getValueSquare(i, j) == " ") {
						board.setValueSquare(i, j, humanPlayer);
						int score = miniMax(board, dept + 1, false);
						bestScore = max(score, bestScore);
						board.setValueSquare(i, j, " ");
					}
				}
			}
			return bestScore;
		}
		else {
			int bestScore = 10000;
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					if (board.getValueSquare(i, j) == " ") {
						board.setValueSquare(i, j, aiPlayer);
						int score = miniMax(board, dept + 1, true);
						bestScore = min(score, bestScore);
						board.setValueSquare(i, j, " ");
					}
				}
			}
			return bestScore;
		}
	}
}



