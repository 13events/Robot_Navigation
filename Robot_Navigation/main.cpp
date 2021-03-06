// Robot_Navigation.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Project uses the SFML library to draw graphics to the screen.
// Go to sfml-dev.org for more information.

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "BoardState.h"
#include "Board.h"


int main()
{
	
	char userInput = ' ';
	int x, y;

	std::cout << "Welcome to the Robot Navigation Program" << "\n"
		<< "The table below is a 17x17 table representing the maze \n"
		<< "where a 1 represents a wall, and 0 represents a clear tile \n"
		<< "The table uses a (y,x) coordinate space where the top left \n"
		<< "corner has a coordinate of (0,0) and the bottom \n"
		<< "right corner is (16,16). Use this coordinate space to enter \n"
		<< "starting and end positions in the prompts below.\n\n\n";

	//create a 17 x 17 board and display it
	BoardState boardState = BoardState(17, 17);
	
	while (userInput != 'n') {

		//ask for starting position
		std::cout << "Enter a starting Position (e.g. 1 3): ";
		std::cin >> x >> y;
		x = x;
		y = y;

		while (!boardState.setStartPos(x, y)) {
			std::cout << "Invalid Entry, try again. \n";
			std::cout << "Enter a starting Position (e.g. 1 3): ";
			std::cin >> x >> y;
			x = x;
			y = y;
		}

		//ask for goal position
		std::cout << "Enter a goal Position (e.g. 1 3): ";
		std::cin >> x >> y;
		x = x;
		y = y;

		while (!boardState.setGoalPos(x, y)) {
			std::cout << "Invalid Entry, try again. \n";
			std::cout << "Enter a goal Position (e.g. 1 3): ";
			std::cin >> x >> y;
			x = x;
			y = y;
		}


		//print the matrix board
		//boardState.printBoard();

		std::cout << "Drawing Maze...";
		//create a GUI representation of the board
		Board myBoard = Board(boardState);


		std::cout << "Run again? (y/n):";
		std::cin >> userInput;
	}
	



	

	std::getchar();
}

