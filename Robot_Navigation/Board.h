#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "BoardState.h"
#define TRIANGLE 3
#define CIRCLE 30
#define DIAMOND  4
class Board
{
private:
	int window_HSize = 500;
	int window_WSize = 500;
	int circleRadius = 15.f;
	int rows, cols;
	std::vector<std::vector<sf::CircleShape>> circles;
	std::vector<std::vector<int>> boardState;

	void createMap();

	public:
		Board(BoardState &boardState) :rows(boardState.getBoardHeight()), cols(boardState.getBoardWidth()), circles(rows, std::vector<sf::CircleShape>(cols))
		{
			this->boardState = boardState.getBoard();
			this->createMap();

		};


		~Board();
};

