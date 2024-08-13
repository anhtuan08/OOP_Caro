#include "map.h"

int Matrix::checkBoundaryRowsBottom(char key, int value, Matrix matrix) {
	value++;
	if (value >= matrix.rows) {
		value--;
	}
	return value;
}

int Matrix::checkBoundaryColsRight(char key, int value, Matrix matrix) {
	value++;
	if (value >= matrix.cols) {
		value--;
	}
	return value;

}

int Matrix::checkBoundaryRowsTop(char key, int value, Matrix matrix) {
	value--;
	if (value < 0) {
		value++;
	}
	return value;
}

int Matrix::checkBoundaryColsLeft(char key, int value, Matrix matrix) {
	value--;
	if  (value < 0) {
		value++;
	}
	return value;
}


Matrix::Matrix() {
	rows = 0;
	cols = 0;
	squares = nullptr;
}

Matrix::Matrix(int rows, int cols) {
	this->rows = rows;
	this ->cols = cols;
	//squares.resize(rows);
	squares = new Square * [rows];
	for (int i = 0; i < rows; i++) {
		/*squares[i].resize(cols);*/
		squares[i] = new Square[cols];
	}
}

void Matrix::setValueBoard(int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			squares[i][j].setValue(i, j, " ");
		}
	}
}

	void Matrix::setValueSquare(int x, int y, string value) {
		squares[x][y].setValue(x, y, value);	
	}

	string Matrix::getValueSquare(int x, int y) {
		return squares[x][y].getValue();
	}

	void Matrix::setRows(int rows) {
		this->rows = rows;
	}

	void Matrix::setCols(int cols) {
		this->cols = cols;
	}
	
	int Matrix::getRows() {
		return this->rows;
	}

	int Matrix::getCols() {
		return this->cols;
	}


