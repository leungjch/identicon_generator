#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "identicon.h"
#include "colorGenerator.hpp"
// Identicons
// 5x5 picture made from 3x5 grid reflected on the y axis

int main()
{
	Identicon myIdent;
	sf::RenderWindow window(sf::VideoMode(800, 800), "Identicons");
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	sf::Image img;
	img.create(5, 5, sf::Color(240, 240, 240));
	sf::Sprite mySprite;
	int numOfScreenshots = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		std::string input;
		//input  = "yes";
		std::cin >> input;
		std::vector<std::vector<int>> values;
		values.clear();
		myIdent.configureIdenticon(input);
		values = myIdent.completeGrid();
		sf::Color myColour = colorGenerator(myIdent.grid[0][0], sf::Color(myIdent.color.r, myIdent.color.g, myIdent.color.b));
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (values[i][j] == 1)
				{
					img.setPixel(j, i, myColour);
				}
				else
				{
					img.setPixel(j, i, sf::Color(241, 255, 255));
				}
			}
		}
		sf::Texture tex;
		tex.loadFromImage(img);
		mySprite.setTexture(tex);
		mySprite.setScale(800 / values.size(), 800 / values.size());


		window.clear();
		window.draw(mySprite);
		
		sf::Vector2u windowSize = window.getSize();
		sf::Texture texture;
		texture.create(windowSize.x, windowSize.y);
		texture.update(window);
		sf::Image screenshot = texture.copyToImage();
		std::string filename = "Screenshots/" + std::to_string(numOfScreenshots) + "_" + myIdent.name + ".png";
		screenshot.saveToFile(filename);
		numOfScreenshots++;
		
		window.display();
	}
	return 0;
}
