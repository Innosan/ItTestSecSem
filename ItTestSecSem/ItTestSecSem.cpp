#include <iostream>
#include <string>

#include "FileManager.h"
#include "MenuOption.h"
#include "Menu.h"

using namespace std;

int main()
{
	FileManager fileManager;
	fileManager.initializeFiles();

	vector<MenuOption> items = {
		MenuOption(1, "Print files",  [&fileManager]() { fileManager.printFiles(); }),
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
		MenuOption(5, "Run tests",  []() { cout << "Running tests.\n"; }),
		MenuOption(6, "Exit",  []() { cout << "Exitting now...\n"; })
	};

	Menu menu(items);
	menu.display();

	cout << "\n\nEnter your choice: ";
	int choice;
	cin >> choice;

	menu.choose(choice);

	return EXIT_SUCCESS;
}
