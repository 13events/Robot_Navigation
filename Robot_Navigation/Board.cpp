#include "pch.h"
#include "Board.h"

void Board::createMap()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//check to see if we have a 1 or 0 on the board
			if (boardState[i][j] == 1) {	//if we have a 1, place a circle in circles vector
				circles[i][j] = sf::CircleShape(circleRadius, CIRCLE);
				circles[i][j].setPosition((circleRadius * 2) * j, i * (circleRadius * 2));
				circles[i][j].setFillColor(sf::Color::Green);
			} else if(boardState[i][j] == 2){	//if 2 put a blue diamond
				circles[i][j] = sf::CircleShape(circleRadius, DIAMOND);
				circles[i][j].setPosition((circleRadius * 2) * j, i * (circleRadius * 2));
				circles[i][j].setFillColor(sf::Color::Blue);
			}
			else if (boardState[i][j] == 3) {	//if 3 put a red diamond
				circles[i][j] = sf::CircleShape(circleRadius, DIAMOND);
				circles[i][j].setPosition((circleRadius * 2) * j, i * (circleRadius * 2));
				circles[i][j].setFillColor(sf::Color::Red);
			}
			
		}
	}

	//create window
	sf::RenderWindow window(sf::VideoMode(window_WSize, window_HSize), "Robot Navigation");

	//handle state of window
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		//print out shapes in circles vector
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				window.draw(circles[i][j]);
			}
		}
		
		window.display();
	}
}

Board::~Board()
{
}
