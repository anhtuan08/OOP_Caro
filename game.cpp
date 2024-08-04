#include "game.h"
#include "map.h"
#include "Square.h"
#include "logicGame.h"
#include "Graphics.h"

void Game::gameLoad()
{
	std::cout << "Welcome to Caro game" << std::endl;
	std::cout << "1. New game" << std::endl;
	std::cout << "2. Load game" << std::endl;
	std::cout << "3. Setting" << std::endl;
	std::cout << "4. Exit" << std::endl;
	

	char key = _getch();
	
}


bool Game::gameWon(Matrix board, LogicGame game) {
	int rows = board.getRows();
	int cols = board.getCols();
	

	if (
		game.checkDiagonalLeft(board, rows, cols)
		|| game.checkDiagonalLeftBottom(board, rows, cols)
		|| game.checkDiagonalRight(board, rows, cols)
		|| game.checkDiagonalRightBottom(board, rows, cols)
		||game.checkHorizontal(board, rows, cols)
		|| game.checkVertical(board, rows, cols)
		 ) 
	{
		return true;
	}
	return false;
}

void Game::gameStart(Matrix board)
{
	system("cls");

	int rows = board.getRows();
	int cols = board.getCols();
	board.setValueBoard(rows, cols);

	Graphics drawBoard;
	for (int i = 0; i < rows * 2; i++) {
		for (int j = 0; j < cols * 2; j++) {
			if (j % 2 == 0)
			{
				drawBoard.gotoXY((j + 1), i);
				cout << "-";
			}
			if (i % 2 == 1 && (j % 2 == 0)) 
			{
				drawBoard.gotoXY((j + 1), (i - 1));
				cout << "| ";
			}
		}
	}


	Square oVuong;
	int x = 0, y = 0;
	int posX = 0, posY = 0;
	int turn = 0;
	string playerCurrent = "x";

	Game game1;
	LogicGame logicGame1;
	while (game1.gameWon(board, logicGame1) != true) {
		if (turn < (rows * cols)) {
			logicGame1.logicControl(board, x, y, posX, posY, playerCurrent);
			logicGame1.logicTurn(board, posX, posY, playerCurrent);
			if (game1.gameWon(board, logicGame1) != true) {
				logicGame1.switchPlayer(playerCurrent);
			}
			else {
				cout << "\t\t\t\t\t" << playerCurrent + "wins";
			}
		}
	}


}


