#include <iostream>
#include <string>

#include "FileManager.h"
#include "Menu.h"

#include "inputs.h"

using namespace std;

int main()
{
	// Initialize the file manager
	std::unique_ptr<FileManager> fileManager = std::make_unique<FileManager>();

	// Initialize the menu
	Menu::printWelcomeMessage();
	Menu menu;
	menu.initializeMenu(fileManager);

	int pickedItem = 0;

	do {
		menu.display();

		pickedItem = getIntUserInput("Choose an option: ", Menu::optionsIds::PRINT_FILES - 1, Menu::optionsIds::EXIT + 1);

		menu.choose(pickedItem);
	} while (pickedItem != Menu::optionsIds::EXIT);

	return EXIT_SUCCESS;
}