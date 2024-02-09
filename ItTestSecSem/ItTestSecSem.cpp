#include <iostream>
#include <string>

#include "Tests.h"
#include "FileManager.h"
#include "MenuOption.h"
#include "Menu.h"
#include "WelcomeMessage.h"

#include "inputs.h"

using namespace std;

int main()
{
	WelcomeMessage::printWelcomeMessage(
		Student("Fomin Mikhail Vital\'evich", 4307, 25),
		Task(1, 1, "Develop a class for the specified subject area.Implement data access using the Set, Get, Show. Provide for necessary checks of source data.")
	);

	// Initialize the file manager
	FileManager fileManager;
	fileManager.initializeFiles();

	// Initialize the menu options
	vector<MenuOption> items = {
		MenuOption(1, "Print files",  [&fileManager]() {
			fileManager.printFiles();
		}),
		MenuOption(2, "Get alphabetically sorted files",  [&fileManager]() {
			vector<File> sortedFiles = fileManager.getSortedFiles();

			FileManager::printVectorOfFiles(sortedFiles);
		}),
		MenuOption(3, "Get files above some size",  [&fileManager]() {
			vector<File> newFiles = fileManager.getFilesAboveSize(550);

			FileManager::printVectorOfFiles(newFiles);
		}),
		MenuOption(4, "Get files above some usage",  [&fileManager]() {
			vector<File> newFiles = fileManager.getFilesAboveUsage(10);

			FileManager::printVectorOfFiles(newFiles);
		}),
		MenuOption(5, "Run tests",  []() { testMenuOptionPrint(); }),
		MenuOption(6, "Exit",  []() { exit(EXIT_SUCCESS); })
	};

	// Initialize the menu
	Menu menu(items);

	int pickedItem = 0;

	do {
		// Display the menu
		menu.display();

		// Get the user's choice
		cout << "Choose an option: ";
		pickedItem = getIntUserInput();

		menu.choose(pickedItem);
	} while (pickedItem != 6);

	return EXIT_SUCCESS;
}
