#include "SFML/Graphics.hpp"
sf::Color colorGenerator(int seed, sf::Color mixInput)
{
	srand(seed);
	sf::Color color = sf::Color((rand()*256+mixInput.r)/2, (rand()*256+mixInput.g)/2, (rand()*256+mixInput.b)/2);
	return color;
}