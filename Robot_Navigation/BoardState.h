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

		//makeBoard

		this->printBoard();
	};

	void makeBoard();
	void printBoard();
	~BoardState();
};

