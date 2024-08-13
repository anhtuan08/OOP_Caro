#include "game.h"


void Game::gameLoad(Matrix board)
{
	std::cout << "Welcome to Caro game" << std::endl;
	std::cout << "1. New Game (2 player)" << std::endl;
	std::cout << "2. Player with Computer" << std::endl;
	std::cout << "3. Exit" << std::endl;
	
	char key = _getch();
	switch (key)
	{
	case '1':
		gameStart(board);
		break;
	case '2':
		gamePlayerWithComputer(board);
		break;
	case '3':
		exit(0);
		break;
	}
}


int Game::gameWon(Matrix board, LogicGame game, int turn) {
	int rows = board.getRows();
	int cols = board.getCols();
	
	int flag[7];

	flag[0] = game.checkHorizontal(board, rows, cols);
	flag[1] = game.checkVertical(board, rows, cols);
	flag[2] = game.checkDiagonalLeft(board, rows, cols);
	flag[3] = game.checkDiagonalLeftBottom(board, rows, cols);
	flag[4] = game.checkDiagonalLeft(board, rows, cols);
	flag[5] = game.checkDiagonalRight(board, rows, cols);
	flag[6] = game.checkDiagonalRightBottom(board, rows, cols);
	

	if (turn != 0) {
		for (int i = 0; i < 7; i++) {
			if (flag[i] == 10 || flag[i] == -10) {
				return flag[i];
			}
		}
		return 1;
	}
	else if (turn == 0) {
			return 0;
		}

	}

void Game::gameStart(Matrix board)
{
	//system("cls");

	//int rows = board.getRows();
	//int cols = board.getCols();
	//board.setValueBoard(rows, cols);

	//Console g1;
	//g1.drawBoard(rows, cols);

	//Square oVuong;
	//int x = 0, y = 0;
	//int posX = 0, posY = 0;
	//string playerCurrent = "x";

	//Game game1;
	//LogicGame logicGame1;

	//bool flag = false;

	//while (flag != true) {
	//		logicGame1.logicControl(board, x,y, posX, posY, playerCurrent);
	//		logicGame1.logicTurn(board, posX, posY, playerCurrent);	
	//		flag = game1.gameWon(board, logicGame1);
	//		if (flag != true) {
	//			logicGame1.switchPlayer(playerCurrent);
	//			//minimax in here
	//			}
	//		else {
	//			cout << playerCurrent + "wins" << endl;
	//			}
	//		}
		}


void Game::gamePlayerWithComputer(Matrix board) {
	system("cls");

	int rows = board.getRows();
	int cols = board.getCols();
	board.setValueBoard(rows, cols);

	Game game1;
	LogicGame logicGame1;
	AIplayer computerPlayer;
	Console g1;

	int x = 0, y = 0;
	int posX = 0, posY = 0;

	int turn = logicGame1.moveLeft(board);

	g1.drawBoard(rows, cols);

	while (game1.gameWon(board, logicGame1, turn) == 1) {
		turn = logicGame1.moveLeft(board);
		if (turn != 0) {
			logicGame1.logicControl(board, x, y, posX, posY, humanPlayer);
			logicGame1.logicTurn(board, posY, posX, humanPlayer);
			if (game1.gameWon(board, logicGame1, turn) == 1) {
				/*computerPlayer.bestMove(board);*/
				computerPlayer.checkAvailable(rows, cols, board, g1);
				}
			}
		}

	if(game1.gameWon(board, logicGame1, turn) == 10)
	{
		cout << " \t\t\t\t\t\t\t\t X wins" << endl;
	}
	else if(game1.gameWon(board, logicGame1, turn) == -10) {
		cout << "\t\t\t\t\t\t\t\t O wins";
	}
	else {
		cout << "\t\t\t\t\t\t\t\t tie";
	}
}



