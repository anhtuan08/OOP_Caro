#include "game.h"
#include "map.h"
#include "Square.h"
#include "logicGame.h"

void Game::gameLoad()
{
	std::cout << "Welcome to Caro game" << std::endl;
	std::cout << "1. New game" << std::endl;
	std::cout << "2. Load game" << std::endl;
	std::cout << "3. Setting" << std::endl;
	std::cout << "4. Exit" << std::endl;
	

	char key = _getch();
	
}



void Game::gameStart(Matrix drawMatrix, Square oVuong)
{
	system("cls");

	int rows = drawMatrix.getRows();
	int cols = drawMatrix.getCols();

	drawMatrix.setValueBoard(rows, cols);

	int x = 0, y = 0;
	int posX = 0, posY = 0;

	int countChessX = 0,  countChessO = 0;


			while (countChessX + countChessO < (rows * cols)) {
				drawMatrix.moveCursor(x,y);
				char key = _getch();

				switch (key) {
						case 'w': 
							posY = drawMatrix.checkBoundaryRowsTop(key, posY, drawMatrix);
							y = 2 * posY;
				   			break;
				   		case 's':
							posY = drawMatrix.checkBoundaryRowsBottom(key, posY, drawMatrix);
							y = posY * 2;
				   			break;
				   		case 'a':
							posX = drawMatrix.checkBoundaryColsLeft(key, posX, drawMatrix);
							x = 2 * posX;
				   			break;
				   		case 'd':
							posX = drawMatrix.checkBoundaryColsRight(key, posX, drawMatrix);
							x = posX * 2;
				   			break;
				   		case 'x':
				   			std::cout << "X";
				   			countChessX++;
							drawMatrix.setValueSquare(posX, posY, "X");
				   			break;
				   		case 'o':
				   			std::cout<< "O";
				   			countChessO++;
							drawMatrix.setValueSquare(posX, posY, "O");
				   			break;
				   	}
			}
			std::cout << endl;

	}
void Game::gameCheckWinner(Matrix matrix) {
	int countCols = 0;

	int rows, cols;
	rows = matrix.getRows();
	cols = matrix.getCols();

	string array[numberWins];

	

}

