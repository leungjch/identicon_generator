#ifndef IDENTICON_H
#define IDENTICON_H
#include <SFML/Graphics.hpp>
#include <iostream>
class Identicon
{
public:
	std::string name;
	unsigned long long int hash;
	sf::Color color;
	int grid[3][3];
	void configureIdenticon(std::string input);
	unsigned long long int stringToInt(std::string input);
	std::vector<int> Identicon::notRandomGenerator(unsigned long long int seed, int size);
	std::vector<std::vector<int>> Identicon::completeGrid();
};
#endif