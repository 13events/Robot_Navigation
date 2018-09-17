#include "pch.h"
#include "BoardState.h"





bool BoardState::setStartPos(int x, int y)
{
	this->startPosX = x;
	this->startPosY = y;

	if (boardMatrix[startPosX][startPosY] == 0) {
		boardMatrix[startPosX][startPosY] = 2;
		return true;
	}
	else {
		return false;
	}
	

}

bool BoardState::setGoalPos(int x, int y)
{
	this->goalPosX = x;
	this->goalPosY = y;

	if (boardMatrix[goalPosX][goalPosY] == 0) {
		boardMatrix[goalPosX][goalPosY] = 3;
		return true;
	}
	else {
		return false;
	}
}

void BoardState::makeBoard()
{
	std::vector<std::vector<int>>::iterator row;
	std::vector<int>::iterator col;
	//randomly fill board with 1's and 0's
	for (row = boardMatrix.begin(); row != boardMatrix.end(); row++) {
		for (col = row->begin(); col != row->end(); col++) {
			int random = rand() % 100;
			if (random % 2 == 0) {
				*col = 0;
			}
			else {
				*col = 1;
			}
		}
	}
	
}

void BoardState::printBoard()
{

	for (int i = 0; i < boardHeight; i++) {
		for (int j = 0; j < boardWidth; j++) {
			std::cout << boardMatrix[i][j] << "  ";
		}
		std::cout << "\n";
	}

	std::cout << "\n\n\n";
}

int BoardState::getBoardHeight()
{
	return this->boardHeight;
}

int BoardState::getBoardWidth()
{
	return this->boardWidth;
}

std::vector<std::vector<int>> BoardState::getBoard()
{
	return this->boardMatrix;
}

BoardState::~BoardState()
{
}
