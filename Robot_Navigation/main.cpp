// Robot_Navigation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "BoardState.h"
#include "Board.h"


int main()
{
	//create a 17 x 17 board
	BoardState boardState = BoardState(17, 17);
	char userInput = ' ';
	int x, y;

	std::cout << "Welcome to the Robot Navigation Program" << "\n";
	
	while (userInput != 'n') {

		//ask for starting position
		std::cout << "Enter starting Position (e.g. 1 3): ";
		std::cin >> x >> y;
		x = x;
		y = y;

		while (!boardState.setStartPos(x, y)) {
			std::cout << "Invalid Entry, try again. \n";
			std::cout << "Enter starting Position (e.g. 1 3): ";
			std::cin >> x >> y;
			x = x;
			y = y;
		}

		//ask for goal position
		std::cout << "Enter goal Position (e.g. 1 3): ";
		std::cin >> x >> y;
		x = x;
		y = y;

		while (!boardState.setGoalPos(x, y)) {
			std::cout << "Invalid Entry, try again. \n";
			std::cout << "Enter starting Position (e.g. 1 3): ";
			std::cin >> x >> y;
			x = x;
			y = y;
		}


		//print the matrix board
		boardState.printBoard();

		//create a GUI representation of the board
		Board myBoard = Board(boardState);


		std::cout << "Run again? (y/n):";
		std::cin >> userInput;
	}
	



	

	std::getchar();
}

