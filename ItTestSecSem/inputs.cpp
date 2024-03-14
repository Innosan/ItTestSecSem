#include <iostream>
#include "inputs.h"

int getIntUserInput(std::string welcomeMessage, int min, int max) {
	int input = 0;

	std::cout << welcomeMessage << std::endl;

	do {
		std::cin >> input;

		if (std::cin.fail() || input <= min || input >= max) {
			std::cout << "Invalid input. Please enter a number from " << min + 1 << " to " << max - 1 << std::endl;
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
	} while (std::cin.fail() || input <= min || input >= max);

	return input;
}

std::string getStringUserInput(std::string welcomeMessage) {
	std::string input = "";
	std::cout << welcomeMessage << std::endl;

	std::cin >> input;

	return input;
}
