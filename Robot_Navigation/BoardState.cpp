#include "pch.h"
#include "BoardState.h"





void BoardState::printBoard()
{


	for (int i = 0; i < boardHeight; i++) {
		for (int j = 0; j < boardWidth; j++) {
			std::cout << boardMatrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}

BoardState::~BoardState()
{
}
