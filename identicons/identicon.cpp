#include "identicon.h"
// this function generates the values of the grid
void Identicon::configureIdenticon(std::string input)
{
	name = input;
	hash = stringToInt(input);
	std::vector<int> colors = notRandomGenerator(hash, 3); // generate colors
	color = sf::Color(colors[0], colors[1], colors[2]); // set color
	std::vector<int> values = notRandomGenerator(hash, 15); // generate values
	std::cout << "################ Colours: " << colors[0] << " " << colors[1] << " " << colors[2];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid[i][j] = values[3*i+j];
			//std::cout << grid[i][j] << std::endl;
		}
	}

}
// this function completes the grid, determining which values make a point valid and then reflecting the grid to make it look symmetrical
std::vector<std::vector<int>> Identicon::completeGrid()
{
	std::vector<std::vector<int>> ret(5, std::vector<int>(5));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//if (grid[i][j] % 2 != 0) // odd
			if (grid[i][j] % 2 == 0) // even
			{
				ret[i][j] = 1;
			}
			else
			{
				ret[i][j] = 0;

			}
			if (j != 2)
			{
				ret[i][4-j] = ret[i][j];
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << ret[i][j] << "	";
		}
		std::cout << std::endl;
	}
	return ret;

}

// this function returns a "hash" of the string.
// if any collisions occur, this function is probably responsible for it.
unsigned long long int Identicon::stringToInt(std::string input)
{
	unsigned long long int ret = 0;
	for (int i = 0; i < input.size(); i++)
	{
		std::cout << "######################BEFORE EXPT " << int(input[i]) << std::endl;
	//	std::cout << "######################AFTER EXPT " << input[i] * pow(31, input.size() - i) << std::endl;
		ret += unsigned long long int(int(input[i]) * pow(31, input.size() - i));
	}
	std::cout << "SUM:			" << ret << std::endl;
	return ret;
}
std::vector<int> Identicon::notRandomGenerator(unsigned long long int seed, int size)
{
	std::vector<int> ret(size);
	srand(seed);
	for (int i = 0; i < size; i++)
	{
		ret[i] = rand() * 32416188517;
	}
	return ret;
}