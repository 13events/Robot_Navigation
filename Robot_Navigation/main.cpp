// Robot_Navigation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "BoardState.h"
#define TRIANGLE 3
#define CIRCLE 30

int main()
{
	BoardState boardState = BoardState(10, 10);
	//boardState.printBoard();
	int window_size_x = 1920;
	int window_size_y = 1080;
	int circleRadius = 15.f;
	int circlesToDrawHorizontal = window_size_x / (circleRadius * 2);
	int circlesToDrawVertical = window_size_y / (circleRadius *  2);
	
	std::vector<std::vector<sf::CircleShape>> circles(circlesToDrawVertical, std::vector<sf::CircleShape>(circlesToDrawHorizontal));
	//std::vector<std::vector<sf::CircleShape>> circles;	//array of shapes

	//loop through and make circles
	for (int i = 0; i < circlesToDrawVertical; i++) {
		for(int j = 0; j < circlesToDrawHorizontal; j++) {
			if (i % 2 == 0) {

				circles[i][j] = sf::CircleShape(circleRadius,CIRCLE);
				circles[i][j].setPosition((circleRadius * 2) * j, i * (circleRadius * 2));
				circles[i][j].setFillColor(sf::Color::Green);
			}
			else {
				circles[i][j] = sf::CircleShape(circleRadius, TRIANGLE);
				circles[i][j].setPosition((circleRadius * 2) * j, i * (circleRadius * 2));
				circles[i][j].setFillColor(sf::Color::Red);
			}
		}
	}
	//create window of 500 by 500 with title
	sf::RenderWindow window(sf::VideoMode(window_size_x, 500), "SFML Works!");

	//create a circle with radius 100
	sf::CircleShape shape(15.f);

	//set fill color
	shape.setFillColor(sf::Color::Green);

	//set position
	std::cout << "Circle Position: (" << shape.getPosition().x << ", " << shape.getPosition().y << ")";

	//while window is open check its state, close window if state is closed
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		for (int i = 0; i < circlesToDrawVertical; i++) {
			for (int j = 0; j < circlesToDrawHorizontal; j++) {
				window.draw(circles[i][j]);
			}
		}
		//window.draw(shape);
		//window.clear();
		//shape.setPosition(shape.getPosition().x + 0.25, shape.getPosition().y + 0.25);
		//window.draw(shape);
		window.display();
	}

	std::getchar();
}

