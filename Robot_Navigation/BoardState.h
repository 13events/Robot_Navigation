#pragma once

#include "pch.h"
#include <iostream>
#include <vector>
#include <time.h>

class BoardState
{
	private:
		std::vector<std::vector<int>> boardMatrix;
		int boardHeight, boardWidth;
public:
	BoardState(int matrixRows, int matrixColumns): boardMatrix(matrixRows, std::vector<int>(matrixColumns))
	{	
		boardHeight = matrixRows;
		boardWidth = matrixColumns;

		//randomly fill board with 1's and 0's
		this->printBoard();
	};

	void printBoard();
	~BoardState();
};

