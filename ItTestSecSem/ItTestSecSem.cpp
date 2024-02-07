#include <iostream>
#include <string>

#include "Tests.h"
#include "FileManager.h"
#include "MenuOption.h"
#include "Menu.h"

using namespace std;

int main()
{
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
			vector<File> newFiles = fileManager.getFilesAboveUsage(3);

			FileManager::printVectorOfFiles(newFiles);
		}),
		MenuOption(5, "Run tests",  []() { testMenuOptionPrint(); }),
		MenuOption(6, "Exit",  []() { cout << "Exitting now...\n"; })
	};

	// Initialize the menu
	Menu menu(items);
	menu.display();

	// Get the user's choice
	cout << "\n\nEnter your choice: ";
	int choice;
	cin >> choice;

	menu.choose(choice);

	return EXIT_SUCCESS;
}
