#include <iostream>

int getIntUserInput(std::string welcomeMessage) {
	int input = 0;

	std::cout << welcomeMessage << std::endl;

	do {
		std::cin >> input;

		if (std::cin.fail() || input <= 0) {
			std::cout << "Invalid input. Please enter a positive integer: ";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
	} while (std::cin.fail() || input <= 0);

	return input;
}
