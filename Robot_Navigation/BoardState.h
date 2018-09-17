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
		int startPosX, startPosY, goalPosX, goalPosY;
public:
	BoardState(int matrixRows, int matrixColumns): boardMatrix(matrixRows, std::vector<int>(matrixColumns))
	{	
		srand(time(0));
		boardHeight = matrixRows;
		boardWidth = matrixColumns;

		//makeBoard
		this->makeBoard();

		this->printBoard();
	};

	bool setStartPos(int x, int y);
	bool setGoalPos(int x, int y);
	void makeBoard();
	void printBoard();
	int getBoardHeight();
	int getBoardWidth();
	std::vector<std::vector<int>> getBoard();
	~BoardState();
};

